#include "CoffeShop.h"

bool OrderSys::HasOrders()
{
    std::lock_guard<std::mutex> lock(m_mtxOrdrsOpn);
    return !m_orders.empty();
}

void OrderSys::PlaceOrder(const std::string& OrdName)
{
    ////Старый вариант
    //{
    //std::lock_guard<std::mutex> lckGrdCout(m_mtxCout);
    //std::cout << "Order is placed: " << OrdName << std::endl;
    //} //забрали ресурс на время!! Перенести в мейн как домашка

    //std::lock_guard<std::mutex> lckGrdOrdrs(m_mtxOrdrsOpn);
    //m_orders.push(OrdName);

    //m_cv.notify_one(); //уведомили ожидающий поток.

    if (!m_isOpen)
    {
        std::lock_guard<std::mutex> lock(m_mtxCout);
        std::cout << "Sys is closed. Can't place order: " << OrdName << std::endl;
        return;
    }

    //добавляем заказ в очередь
    {
        std::lock_guard<std::mutex> lock(m_mtxOrdrsOpn);
        m_orders.push(OrdName);
    }

    //Уведомляем один поток (бариста)
    m_cv.notify_one();

    //Выводим сообщение
    {
        std::lock_guard<std::mutex> lock(m_mtxCout);
        std::cout << "Order placed: " << OrdName << std::endl;
    }

}

std::string OrderSys::TakeOrder() //вспомог функция в потоке баристы
{
    std::unique_lock<std::mutex> unLock(m_mtxOrdrsOpn);
    m_cv.wait(unLock, [this] {
        return !m_isOpen || !m_orders.empty();
        });

    std::string orderName = m_orders.front();
    m_orders.pop();
    return orderName;
}

void OrderSys::Close()
{
    std::lock_guard<std::mutex> lckGuard(m_mtxOrdrsOpn);
    m_isOpen = false;
    m_cv.notify_all(); //Будим все ожидающие потоки

    std::lock_guard<std::mutex> lock(m_mtxCout);
    std::cout << "Order sys is closed. No more orders accepted! " << std::endl;

}

bool OrderSys::IsOpen() const
{
    return m_isOpen;
}
