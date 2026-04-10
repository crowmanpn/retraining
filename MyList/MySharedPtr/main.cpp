#include "MySharepPtr.h"
#include <iostream>

MySharedPtr<int> testThread(MySharedPtr<int>::MakeShared(1));//как используется atomic?
															//


int main() {
	
	MySharedPtr<int> testShPtr(MySharedPtr<int>::MakeShared(777));
	std::cout << *testShPtr << std::endl;

	MySharedPtr<int> testShPtr2(testShPtr);

	


	return 0;
}

//Реализация с потоками.
