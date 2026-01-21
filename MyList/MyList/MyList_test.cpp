#include "MyList_test.h"
#include <iostream> 

void MyList_test::InsNode(const int& oth)
{
	if (pHead == nullptr)
	{
		pHead = new Node_test(oth);
		pTail = pHead;
		cnt++;

		return;
	}

	//меньше влож.
	pTail->pNext = new Node_test(oth);
	pTail = pTail->pNext;
	cnt++;


}

void MyList_test::InsNode(const int& oth, size_t pos)
{
	if (pos == 0)
	{
		Node_test* pNewHead = new Node_test(oth);
		pNewHead->pNext = this->pHead;
		pHead = pNewHead;
		cnt++;
		return;

	}
	else if (pos > cnt) //хвост
	{
		InsNode(oth);
		return;
	}

	Node_test* pCurrent = pHead;
	for (size_t i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->pNext;
	}

	Node_test* pNodeTmp = new Node_test(oth);
	pNodeTmp->pNext = pCurrent->pNext->pNext;
	pCurrent->pNext = pNodeTmp;
}

bool MyList_test::RemNode(size_t pos)
{
	if (pos > cnt)  return false;

	if (pos == 0) {
		Node_test* pNodeTodl = pHead;
		pHead = pHead->pNext;
		delete pNodeTodl;
		cnt--;
		if (cnt == 0) pTail = nullptr;
		return true;
	}

	Node_test* pCurrent = pHead;
	for (size_t i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->pNext;
	}
	Node_test* pNodeTodl = pCurrent->pNext;
	pCurrent->pNext = pCurrent->pNext->pNext;

	delete pNodeTodl;
	cnt--;
	return true;
}

bool MyList_test::RemNode(const int& oth)
{

	Node_test* pCurrent = pHead;


	while (pCurrent->pNext != nullptr && pCurrent->pNext->val != oth)
	{
		pCurrent = pCurrent->pNext;
	}

	if (pCurrent == pHead) {
		Node_test* pNodeTodl = pHead;
		pHead = pHead->pNext;
		delete pNodeTodl;
		cnt--;
		if (cnt == 0) pTail = nullptr;
		return true;
	}

	if (pCurrent->pNext == nullptr) return false;

	Node_test* pNodeTodl = pCurrent->pNext;
	pCurrent->pNext = pCurrent->pNext->pNext;

	delete pNodeTodl;
	cnt--;
	return true;
}

void MyList_test::PrintList() const
{
	std::cout << this->cnt << std::endl;
	for (Node_test* pCur = pHead; pCur != nullptr; pCur = pCur->pNext)
	{
		std::cout << pCur->val << std::endl;
	}
}

MyList_test::~MyList_test()
{
}

