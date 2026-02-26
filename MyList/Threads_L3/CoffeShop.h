#pragma once
#include <queue>
#include <iostream>
#include <mutex>
#include <condition_variable>

//сделать самому с ENUM class
//кассир
//

enum class OrderStatus{
	  OPEN,		 // асса открыта
	  CLOSED	 // асса закрыта

};

class OrderSys {
private:
	std::mutex m_mtxOrdrsOpn; //m_isOpen,m_orders
	std::mutex m_mtxCout; //
	std::condition_variable m_cv;
	std::queue<std::string> m_orders; //ќбщий ресурс дл€ потоков - очередь заказов
	std::atomic<bool> m_isOpen{ true }; //јтомарный флаг - не требует мьютекс 

public:
	void PlaceOrder(const std::string& OrdName);
	bool HasOrders(); //наличие заказов
	std::string TakeOrder();//приготовить
	void Close();//механизм пробуждени€ потоков - ср
	bool IsOpen() const; //проверить открыта ли система
};