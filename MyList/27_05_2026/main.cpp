#include "tracer.h"

int removeDuplicates(std::vector<int>& nums) {
	
	size_t nextUi = 1;
	size_t i = 1;

	for (; i < nums.size(); i++)
	{
		if (nums[i]!=nums[i-1]) 
		{
			nums[nextUi] = nums[i];
		}
	}

}

int main()
{
	Tracer mytracer;
	bool isOpen = mytracer.readFromFile("myfile.txt");
	
	if (!isOpen)
	{
		std::cout << "Can't open file";
	}

	//mytracer.sortDataTime();

	Tracer::Trace myTrace = mytracer.GetTrace(6);
	size_t i=mytracer.binSearch(myTrace);
	mytracer.printAll();


	return 0;
}
