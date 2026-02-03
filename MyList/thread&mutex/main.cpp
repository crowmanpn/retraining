//многопоточное программирование
#include <chrono>
//#include <cstddef>
#include <iostream>
//#include <stack>
#include <thread>
#include <mutex>
#include <ctime>
#include <random>

std::mutex mtxMoney;
std::mutex mtxCout;

unsigned int money = 1000000;



void transac(int idThread,int val, bool isGetMoney) {
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> amount_dist(1, 5);
	
	std::this_thread::sleep_for(std::chrono::seconds(amount_dist(gen)));
	//money += val * isGetMoney ? (-1) : (1);
	std::lock_guard<std::mutex> MoneyLck(mtxMoney);
	std::lock_guard<std::mutex> CoutLck(mtxCout);

	if (isGetMoney&&val>money)
	{
		std::cout <<"id "<< idThread << " " << "No enougth money" << std::endl;
		return;

	}
	money=isGetMoney ? money - val : money + val;
	std::cout << idThread << " " << (isGetMoney ? "Get " : "Put ") << val << std::endl;
}

int main(){
//std::mutex mtx;
//
//void worker_func(int thread_id) {
//	std::lock_guard<std::mutex> lock_guard(mtx);
//	std::cout << "thread id: " << thread_id << std::endl;
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//}
//
//void worker_func2(int thread_id) {
//	//...
//
//	mtx.lock();
//	std::cout << "thread id: " << thread_id << std::endl;
//	mtx.unlock();
//
//	//...
//
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//}
//
//int main() {
//	std::thread worker1(worker_func, 0);
//	std::thread worker2(worker_func2, 1);
//	std::thread worker3(worker_func, 2);
//	std::thread worker4(worker_func, 3);
//	std::thread worker5(worker_func, 4);
//
//	worker1.join();
//	worker2.join();
//	worker3.join();
//	worker4.join();
//	worker5.join();
	std::thread myThread1(transac,1,10000,true); //перед ук на ф-цию
	std::thread myThread2(transac, 2, 20000, false);
	std::thread myThread3(transac, 3, 30000, false);
	std::thread myThread4(transac, 4, 40000, false);
	std::thread myThread5(transac, 5, 50000, true);
	std::thread myThread6(transac, 6, 60000, false);
	std::thread myThread7(transac, 7, 70000, false);
	std::thread myThread8(transac, 8, 80000, false);
	std::thread myThread9(transac, 9, 90000, true);

	myThread1.join();
	myThread2.join();
	myThread3.join();
	myThread4.join();
	myThread5.join();
	myThread6.join();
	myThread7.join();
	myThread8.join();
	myThread9.join(); //пока потоконебезопасн.

	//поток вывода это один ресурс...
	
	
	

	return 0;
}