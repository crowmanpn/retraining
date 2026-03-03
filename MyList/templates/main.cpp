#include <iostream>
#include "templates.h"
#include <string>
#include <vector>



int main() {
	//Создаем обобщенный контейнер MyArray
	MyArray<int> myArray(10);
	MyArray<int> myArray2={1,2,3,4,5,6,7,8,9,10};

	MyArray<std::string> myArray3={ "hello","world" };
	//myArray3.ShowMyArray();
	
	//MyArray<int> myArray4(myArray2);
	//Проверим мув семантику

	MyArray<int> myArray4(std::move(myArray2));

	MyArray<int> myArray5{ 4,6,7,10,12,22,33 };
	
	myArray5 = myArray4;
	myArray5.ShowMyArray();

	MyArray<int> MyArray6={ 9,10,11 };
	myArray5 = MyArray6;
	myArray5.ShowMyArray();

	//std::vector<int> myVec;

	myArray5.PushBack(777);
	myArray5.ShowMyArray();

	MyArray<int> MyArray7{ 55,66,77};


	MyArray7.PushBack(88);
	MyArray7.PushBack(89);
	MyArray7.PushBack(100);
	MyArray7.PushBack(101);
	MyArray7.PushBack(102);
	MyArray7.PushBack(103);
	MyArray7.PushBack(777);
	
	MyArray7.ShowMyArray();


	return 0;
}