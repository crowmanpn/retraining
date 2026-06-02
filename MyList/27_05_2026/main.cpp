#include "tracer.h"
int main()
{
	Tracer mytracer;
	bool isOpen = mytracer.readFromFile("myfile.txt");
	
	if (!isOpen)
	{
		std::cout << "Can't open file";
	}

	mytracer.sortDataTime();
	mytracer.printAll();


	return 0;
}