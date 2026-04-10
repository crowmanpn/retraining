#pragma once
#include <atomic>
#include <iostream>

template <typename T> 
class MySharedPtr {

private:
	std::atomic<size_t>* m_counter;
	T* m_data;
public:
	MySharedPtr() :m_counter(nullptr), m_data(nullptr) {};
	~MySharedPtr(){
		if (m_counter == nullptr) {
			return;
		}
		(*m_counter)--;
		if (*m_counter == 0) {
			delete m_data;
			delete m_counter;
		}
	}
	//функции статичная
	static MySharedPtr MakeShared(const T& oth) {
		//инициализируем
		//my alloc(выделяем неинц область)
		//new - конструктор типа
		return MySharedPtr(new T(oth));
	}
	MySharedPtr(const MySharedPtr& oth) {
		m_data = oth.m_data;
		m_counter = oth.m_counter;
		if (m_counter!=nullptr)
		{
			(*m_counter)++;
			std::cout << "ref: " << *m_counter << std::endl;
		}	
	}
	T& operator*() const{

		return *m_data;
	}

	T* GetData() const{	//
		return m_data;
	}
private:
	MySharedPtr(T* oth) {
		m_counter = new std::atomic<size_t>(1);
		m_data = oth;
	}

};
