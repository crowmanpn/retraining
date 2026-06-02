#include "my_tracer.h"
#include <iterator>

MyTracer::event::event(const std::string& msg, std::chrono::system_clock::time_point timestamp)
{
	m_message = msg;
	m_timestamp = timestamp;
}

void MyTracer::AddEvent(const std::string& eventMsg)
{
	event newEvent(eventMsg, std::chrono::system_clock::now());
	std::lock_guard<std::mutex> lock(m_data_mtx);
	m_data.push_back(newEvent);
	if (m_data.size() > m_MaxSz) {
		m_data.pop_front();
	}
}

std::vector<std::shared_ptr<MyTracer::event>> MyTracer::GetEventsInRange(std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end)
{
	std::lock_guard<std::mutex> lock(m_data_mtx);
	auto itStart=std::lower_bound(m_data.begin(), m_data.end(), start, [](const event& ev, const std::chrono::system_clock::time_point& tp) {return ev.m_timestamp < tp; });
	auto itEnd = std::lower_bound(m_data.begin(), m_data.end(), end, [](const event& ev, const std::chrono::system_clock::time_point& tp) {return ev.m_timestamp < tp; });

	std::vector<std::shared_ptr<event>> resultVec;
	resultVec.reserve(std::distance(itStart, itEnd));
	for (auto it=itStart; it!=itEnd; it++)
	{
		resultVec.emplace_back(std::make_shared<event>(*it));
	}
	


	return resultVec;
}

void MyTracer::PrintEvents(const std::vector<std::shared_ptr<MyTracer::event>>& events)
{

	for (size_t i = 0; i < events.size(); i++)
	{
		std::cout << events[i]->toString() << std::endl;
	}
}

void MyTracer::showAllMsg()
{
	for (auto it = m_data.begin(); it!=m_data.end(); it++)
	{
		std::cout << it->toString() << std::endl;
	}
}


