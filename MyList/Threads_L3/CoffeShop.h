#pragma once
#include <queue>
#include <iostream>
#include <mutex>
#include <condition_variable>

//сделать самому с ENUM class
//кассир
//


class OrderSys {
private:
	std::mutex m_mtxOrdrsOpn; //m_isOpen,m_orders
	std::mutex m_mtxCout; //
	std::condition_variable m_cv;
	std::queue<std::string> m_orders; //Общий ресурс для потоков
	bool m_isOpen; //общий ресурс  сделать Atomic (не нужно будет синхронизировать)

public:
	void PlaceOrder(const std::string& OrdName);
	bool HasOrders(); //наличие заказов
	std::string TakeOrder();//приготовить
	void Close();//механизм пробуждения потоков - ср



	



};