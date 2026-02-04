#include <thread>
#include "CoffeShop.h"


void BaristaWorker(const size_t threadId, OrderSys& ordSys) {
   //
}

void CassirWorker(OrderSys& ordSys) {
   //placeOrd()	  - вызывать notify_one
	В этом же потоке 
		lock

}




main() {
	OrderSys myOrderSys;
	std::thread Barista1(BaristaWorker, 1, std::ref(myOrderSys));
	std::thread Barista2(BaristaWorker, 2, std::ref(myOrderSys));
	//std::thread Cassir(std::ref(myOrderSys));
	CassirWorker(myOrderSys);

	Barista1.join();
	Barista2.join();
	

	return 0;

}