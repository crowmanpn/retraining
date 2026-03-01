#include <iostream>
#include "templates.h"
#include <string>



int main() {
	//Создаем обобщенный контейнер MyArray
	MyArray<int> myArray(10);
	MyArray<int> myArray2={1,2,3,4,5,6,7,8,9,10};

	MyArray<std::string> myArray3={ "hello","world" };
	myArray3.ShowMyArray();
	
	//MyArray<int> myArray4(myArray2);
	//Проверим мув семантику

	MyArray<int> myArray4(std::move(myArray2));

	

	return 0;
}