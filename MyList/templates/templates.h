#pragma once
#include <cstdarg>
#include <initializer_list>
#include <iostream>



template <typename T>
class MyArray {
private:
	T* m_data;
	size_t m_size;
	size_t m_cap;

public:
	MyArray() {
		m_data = nullptr;
		m_size = 0;
		m_cap = 0;
	}

	~MyArray() {
		delete[] m_data;
	}

	MyArray(size_t size) {
		m_data = new T[size];
		m_cap = size;
		m_size = size;
	}
	//template <typename... args> //а если мы сделаем constexpr метод, то его можно вычислить на этапе
	////компиляции?
	////можно ли делать new и delete?
	MyArray(std::initializer_list<T> init) :m_size(init.size()) {
		//вспомнил список инициализации std::initializer_list
		m_cap = m_size + 5;
		m_data = new T[m_cap];

		size_t i = 0;
		for (auto& x : init) {
			m_data[i] = x;	//почему выдает предупреждения?
			i++;
		}
		//вспомнил диапазонный фор
	}

	MyArray(const MyArray& oth) {
		m_size = oth.m_size;
		m_cap = oth.m_cap;
		m_data = new T[m_cap];

		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = oth.m_data[i];
		}

	}  //кк

	MyArray(MyArray&& oth) {
		//Если будем перемещать пустой динамический массив?
		m_size = oth.m_size;
		m_cap = oth.m_cap;
		m_data = oth.m_data;

		oth.m_size = 0;
		oth.m_cap = 0;
		oth.m_data = nullptr;
	 }

	MyArray& operator=(const MyArray& oth) { //Оптимизированный оператор присваивания?
		if (this != &oth) //Защита от присваивания на себя самого.
		{
			if (m_cap == oth.m_cap) //Просто перезаписываем
			{
				for (size_t i = 0; i < oth.m_size; i++)
				{
					m_data[i] = oth.m_data[i];
				}
			}
			else if (m_cap < oth.m_cap)
			{
				ClearMyArray();
				m_data = new T[oth.m_cap];
				m_cap = oth.m_cap;
				m_size = oth.m_size;
				for (size_t i = 0; i < oth.m_size; i++)
				{
					m_data[i] = oth.m_data[i];
				}
			}
			else
			{
				m_size = oth.m_size;
				for (size_t i = 0; i < m_size; i++)
				{
					m_data[i] = oth.m_data[i];
				}
			}

		}
		return *this;
	}

	MyArray& operator=(const MyArray&& oth) {
		if (this != &oth) {	//защита от перемещения самого себя
			ClearMyArray(); //удалили
			//отобрали
			m_size = oth.m_size;
			m_cap = oth.m_cap;
			m_data = oth.m_data;

			//обнулили
			oth.size = 0;
			oth.m_cap = 0;
			m_data = nullptr;
			

		}
		return *this;
	}

	void ShowMyArray() {
		for (size_t i = 0; i < m_size; i++)
		{
			std::cout << m_data[i] << " ";
		}
		std::cout << std::endl;
	}

	void ClearMyArray() {
		delete[] m_data;
		m_size = 0;
		m_data = 0;
	}				

	/*bool operator==(const MyArray& lhs, const MyArray& rhs) {
		return true;
	}*/

	/*T& operator[](size_t index);*/	 //Как отслеживать выход из массива - assert (макрос в режиме debug).

	/*const T& operator[](size_t index);*/

	


	
	//оператор присваивания
	//оператор сравнения==
	//оператор [] (const и не const версия)
	// push back, pop back
	// clear
	// Деструктор (delete)
	//




};