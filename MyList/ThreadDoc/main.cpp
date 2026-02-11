#include <condition_variable>
#include <mutex>
#include <vector>
//#include <map>
#include <atomic>
#include <random>
#include <chrono>
#include <iostream>
#include <string>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> WorkerRandDuration(1000, 8000);
std::mutex mtxCout;

const size_t NUM_THREADS=5;
const size_t KEEP_ALIVE_TIMEOUT=5000;
const size_t REQ_TIME = 500;


std::vector<std::mutex> vecMtx;
std::vector <std::chrono::steady_clock::time_point> vecTimePt;

std::mutex mtxWatchDog;

std::condition_variable WatchDogCV;

std::atomic<bool> running{ false };

void Log(std::string myStr) {
	std::lock_guard<std::mutex> cOutLock(mtxCout);
	std::cout << myStr << std::endl;
}

void UpdateKeepAlive(size_t ThreadId) {
	std::lock_guard<std::mutex> upDateMtx(vecMtx[ThreadId]);
	vecTimePt[ThreadId]=std::chrono::steady_clock::now();
}

void Worker(size_t ThreadId) {
	std::string id = std::to_string(ThreadId);
	Log(std::string("Worker is running")+id);
	while (running.load())
	{
		UpdateKeepAlive(ThreadId);
		//генератор Рандомно Sleepfor
	}

}

//WatchDog() Без аргументов (через опр время проверять состояние потоков)




int main() {

	//запуск вотчдога, потоков...
	//




	return 0;
}