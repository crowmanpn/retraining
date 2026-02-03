#include <chrono>
#include <cstddef>
#include <iostream>
#include <stack>
#include <thread>
#include <mutex>

std::mutex mtx;



void worker_func(int threadId) {
	std::lock_guard<std::mutex> myLockGrd(mtx);
	std::cout << "Thread Id: " << threadId << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void worker_func2(int threadId) {
	mtx.lock();
	std::cout << "Thread Id: " << threadId << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	mtx.unlock();
}

//Тема: многопоточность. Урок 1. Потоки работают не


int main() {
	//создаем поток

	std::thread worker1(worker_func, 0);
	std::thread worker2(worker_func2, 1);
	std::thread worker3(worker_func, 2);
	std::thread worker4(worker_func, 3);
	std::thread worker5(worker_func, 4);


	worker1.join();
	worker2.join();
	worker3.join();
	worker4.join();
	worker5.join();
	//происходит гонка с разным результатом.
	//Проблема решаются с потомощью потоковых методов синхронизации.
	//std::mutex, существует два состоянии mutex: открытый и закрытый.


	return 0;
}