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
	std::mutex m_mtx;
	std::condition_variable m_cv;
	std::queue<std::string> m_orders; //Общий ресурс для потоков
	bool m_isOpen;
private:
	bool HasOrders(); //наличие заказов
public:
	void PlaceOrder(const std::string& OrdName); 
	std::string Cooking();//приготовить
	void Close();//механизм пробуждения потоков - ср



	



};