#include "tracer.h"
#include <fstream>
#include <iostream>
#include <string>
#include  <thread>
#include <algorithm>


bool Tracer::readFromFile(const std::string& address)
{
	std::string line;
	std::chrono::time_point<std::chrono::milliseconds> timeStamp;
	std::ifstream myFile(address);
	if (!myFile.is_open()) {
		return false;
	}
	int i = 0;
	while (std::getline(myFile,line))
	{
		
		std::cout << line << std::endl;
		m_data.push_back(Tracer::Trace(std::chrono::system_clock::now(), line,LevelLog(i++)));

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));//Сделать ранд... (1 до 3 сек)
		if (i > 2) i = 0;
	
	}


	return true;
}

void Tracer::sortDataTime()
{
	std::sort(m_data.begin(), m_data.end(), [](const Tracer::Trace& a, const Tracer::Trace& b) {return a.m_log > b.m_log; });
}

void Tracer::printAll()
{
	for (const auto& a : m_data) {
		std::time_t t = std::chrono::system_clock::to_time_t(a.m_time);
		std::cout << t << " [" << logLvlToStr(a.m_log) << "] " << a.m_message << std::endl;
	}
}

void Tracer::binSearch(const Trace& oth)
{
si
}



//Ф бинар поиска

//классические сортировки без сорт

std::string logLvlToStr(LevelLog mylog)
{
	switch (mylog)
	{
		case LevelLog::debug:
			return "debug";
		case LevelLog::error:
			return "error";
		case LevelLog::info:
			return "info";
	}
	return "";
}
