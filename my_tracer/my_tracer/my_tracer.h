#pragma once
#include <deque>
#include <chrono>
#include <string>
#include <vector>
#include <iostream>
#include <format>
#include <mutex>
//std::chrono::system_clock::time_point timestamp;

class MyTracer {
public:
	struct event
	{
		std::string m_message;
		std::chrono::system_clock::time_point m_timestamp;
		event(const std::string& msg, std::chrono::system_clock::time_point timestamp);
		bool operator<(const event& oth) {
			return m_timestamp < oth.m_timestamp;
		}
		bool operator<(const std::chrono::system_clock::time_point& oth) {
			return m_timestamp < oth;
		}
		friend bool operator<(const std::chrono::system_clock::time_point& tp, const event& e) {
			return tp < e.m_timestamp;
		}
		std::string toString() const {
			return std::format("{:%Y-%m-%d %H:%M:%S}", m_timestamp)+" "+m_message;
		}
	};
	std::deque<event> m_data;
	std::mutex m_data_mtx; //mtx защита очереди
	//std::condition_variable m_cv; //ожидание (
	//std::thread m_consumer_thread; //должны создаваться из вне в main

	size_t m_MaxSz;
public:
	//MyTracer() :m_MaxSz(0) {};
	MyTracer(size_t MaxSz = 100) :m_MaxSz(MaxSz) {};
	void AddEvent(const std::string& eventMsg);
	std::vector<std::shared_ptr<event>> GetEventsInRange(std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end);

	static void PrintEvents(const std::vector <std::shared_ptr<MyTracer::event>>& events);
	void showAllMsg();
	//ЗPrint

};					  