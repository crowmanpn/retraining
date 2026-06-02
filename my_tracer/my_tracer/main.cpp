#include "my_tracer.h"
#include <thread>
#include <map>

MyTracer genTracer;

void doSmt(size_t threadId) {
	for (size_t i = 0; i < 50; i++)
	{
		genTracer.AddEvent("alarm" + std::to_string(i)+' '+std::to_string(threadId) + '\n');
		std::this_thread::sleep_for(std::chrono::nanoseconds(100));
	}
	
}

std::map<size_t, char> myMap = { {1,'A'},{2,'B'}, {3,'C'},{4,'D'},{5,'E'},{6,'F'},{7,'G'},{8,'H'},{9,'I'},{10,'J'},
{11,'K'},{12,'L'},{13,'M'},{14,'N'},{15,'O'}, { 16,'P' },{17,'Q'},{18,'R'},{19,'S'},{20,'T'},{21,'U'},{22,'V'},{23,'W'},{24,'X'},{25,'Y'},{26,'Z'} };

std::string convert(size_t i) {
	
	if (i == 0) return std::string("");
	size_t a = i / 26;
	size_t b = i % 26;
	do
	{

		if (b == 0)
		{

		}

	} 	while (a != 0)

	


}

int main() {

	
	//MyTracer myTraces;
	//myTraces.AddEvent("alarm1");
	//myTraces.AddEvent("alarm2");
	//myTraces.AddEvent("alarm3");
	//auto start = std::chrono::system_clock::now();
	//myTraces.AddEvent("alarm4");
	//myTraces.AddEvent("alarm5");
	//myTraces.AddEvent("alarm6");
	//auto end = std::chrono::system_clock::now();

	//std::vector<std::shared_ptr<MyTracer::event>> printVec=myTraces.GetEventsInRange(start, end);
	//MyTracer::PrintEvents(printVec);

	//многопоточность?
	//поток - работа...
	//несколько потоков в один лог
	//использ мутекс для синхронизации
	std::thread myThread1(doSmt,5);
	std::thread myThread2(doSmt, 10);
	std::thread myThread3(doSmt, 15);
									  
	myThread1.join();
	myThread2.join();
	myThread3.join();

	genTracer.showAllMsg();






	return 0;
}