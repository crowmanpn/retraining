#include "MyList.h"

void MyList::InsNode(const std::string& str)
{
	if (pHead==nullptr)
	{
		pHead = new Node(str);
		pTail = pHead;
		cnt++;

		return;
	}
	
	//меньше влож.
	pTail->pNext = new Node(str);
	pTail = pTail->pNext;
	cnt++;
	

}

MyList::~MyList()
{
}
