#include "CoffeShop.h"

bool OrderSys::HasOrders()
{
    std::lock_guard<std::mutex> guard(m_mtxOrdrsOpn);
    
    return !m_orders.empty();
}

void OrderSys::PlaceOrder(const std::string& OrdName)
{
    {
    std::lock_guard<std::mutex> lckGrdCout(m_mtxCout);
    std::cout << "Order is placed: " << OrdName << std::endl;
    } //забрали ресурс на время!! Перенести в мейн как домашка

    std::lock_guard<std::mutex> lckGrdOrdrs(m_mtxOrdrsOpn);
    m_orders.push(OrdName);

    m_cv.notify_one();

    
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
    m_cv.notify_all();
}
