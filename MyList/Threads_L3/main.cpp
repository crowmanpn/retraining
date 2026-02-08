#include <thread>
#include <string>
#include "CoffeShop.h"


void BaristaWorker(const size_t threadId, OrderSys& ordSys) {
	while (true)
	{
		std::string order = ordSys.TakeOrder();
		if (order.empty()) break;
		std::this_thread::sleep_for(std::chrono::microseconds(500)); //приготовление
	}
}

void CassirWorker(OrderSys& ordSys) {
   //placeOrd()	  - вызывать notify_one
	for (size_t i = 0; i < 20; i++)
	{
		ordSys.PlaceOrder(std::string("coffe ") + std::to_string(i));
		std::this_thread::sleep_for(std::chrono::microseconds(200));
	}
	while (ordSys.HasOrders())
	{
		std::this_thread::sleep_for(std::chrono::microseconds(200));
	}

	ordSys.Close();	 //рест закрыт

}




int main() {
	OrderSys myOrderSys;
	std::thread Barista1(BaristaWorker, 1, std::ref(myOrderSys));
	std::thread Barista2(BaristaWorker, 2, std::ref(myOrderSys));
	//std::thread Cassir(std::ref(myOrderSys));
	CassirWorker(myOrderSys);  //поток кассира в отдельный поток

	Barista1.join();
	Barista2.join();
	
	

	return 0;

}