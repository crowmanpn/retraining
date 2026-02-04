#include "CoffeShop.h"

bool OrderSys::HasOrders()
{
    std::lock_guard<std::mutex> guard(m_mtx);
    
    return !m_orders.empty();
}

std::string OrderSys::Cooking() //вспомог функция в потоке баристы
{
    std::unique_lock<std::mutex> unLock(m_mtx);
    m_cv.wait(unLock, [this] {
        return !m_isOpen || !m_orders.empty();
        });

    std::string orderName = m_orders.front();
    m_orders.pop();
    return orderName;
}

void OrderSys::Close()
{
    //cv.notify all закрыть 
}
