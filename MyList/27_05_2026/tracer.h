#pragma once
#include <chrono>
#include <string>
#include <vector>
#include <iostream>

enum class LevelLog
{
	error=0, info, debug

};

class Tracer {
public:
	struct Trace {
		std::chrono::time_point<std::chrono::system_clock> m_time;
		std::string m_message;
		LevelLog m_log;
		Trace(std::chrono::time_point<std::chrono::system_clock> timeStmp, const std::string& msg, const LevelLog log) : m_time(timeStmp), m_message(msg), m_log(log) {};
	};
private:
	std::vector<Trace> m_data;
public:
	bool readFromFile(const std::string& address);
	void sortDataTime();
	bool binFind(); //передаем таймпоинт, выв на экран сообщ у кот таймпоит (-1;1) сек
	//найти алгоритм, т.к. данные отсортированы по времени
	//разобраться
	void printAll();
	int binSearch(const Trace& oth);
	std::string logLvlToStr(LevelLog mylog);
	Trace GetTrace(size_t i);

	//класс Tracer 
	//фиксация времени.
	//чтение из файла
	//перед чтением будем....
	//время
};