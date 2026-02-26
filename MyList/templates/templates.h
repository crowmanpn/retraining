#pragma once


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

	MyArray(size_t size) {
		m_date = new T[size];
		m_cap = size;
		m_size = size;
	}

	MyArray(const MyArray& oth) {

	}  //кк

	MyArray& operator=(const MyArray& oth) {

	}

	bool operator==(const MyArray& lhs, const MyArray& rhs) {

	}

	T& operator[](size_t index);	 // ак отслеживать выход из массива - assert (макрос в режиме debug).

	const T& operator[](size_t index);

	


	
	//оператор присваивани€
	//оператор сравнени€==
	//оператор [] (const и не const верси€)
	// push back, pop back
	// clear
	// ƒеструктор (delete)
	//




};