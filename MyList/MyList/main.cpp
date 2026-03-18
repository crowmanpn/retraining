#include "MyList.h"
#include "MyList_test.h"
#include "func.h"
#include <iostream>
#include <cmath>

struct ListNode
{
	ListNode* pNext;
	int val;

	ListNode() :pNext(nullptr),val(0) {};
	ListNode(const int v) {	  //переписаит списком ин
		val = v;
		pNext = nullptr;
	}

};
//
//
//ListNode* MergeTwoList(ListNode* fst, ListNode* snd) {
//
//	//только ListNode (как с массивом)
//	for (ListNode* pCur=fst; pCur!=nullptr; pCur=pCur->pNext)
//	{
//
//
//	}
//}

//ListNode* swapPairs(ListNode* pHead) {
//	//пустой список
//	//с одн эл.
//
//	if (pHead==nullptr||pHead->pNext==nullptr)
//	{
//		return pHead;
//	}
//	ListNode* pCur = pHead;
//	ListNode* pPre = nullptr;
//	ListNode* pNewHead = pHead->pNext;
//
//	ListNode* swap1 = pCur;
//	ListNode* swap2 = pCur->pNext;
//	ListNode* tmp = swap1;
//	swap2 = swap1;
//	swap1 = tmp;
	
int  toDec(ListNode* oth){
	
	int res = 0;
	int cnt = 0;
	ListNode* pCur = oth;
	while (pCur!=nullptr)
	{
		cnt++;
		pCur = pCur->pNext;
	}
	
	pCur = oth;
  	while (pCur != nullptr)
	{
		res += pCur->val * pow(2,(cnt-1)); 
		cnt--;
		pCur = pCur->pNext;
				 
	}

	return res;
}


//MyList_test* mergeTwoLists(MyList_test* list1, MyList_test* list2) {
//	while (list1 && list2) {
//		
//	}
//	
//	return nullptr;
//};

int main() {

	
	//MyList mylist;	 //"Вариардик", функция с пермен числом параметром (вспомнить).
	//
	//mylist.InsNode("one");
	//mylist.InsNode("two");
	//mylist.InsNode("three",0);

	//mylist.PrintList();
	//
	//std::cout<<std::endl;

	//mylist.RemNode(0);
	//mylist.RemNode("two");
	//mylist.RemNode("three");

	//mylist.PrintList();

	//MyList_test mylist_test1;
	//mylist_test1.InsNode(3);
	//mylist_test1.InsNode(8);
	//mylist_test1.InsNode(15);
	//mylist_test1.InsNode(20);

	//MyList_test mylist_test2;
	//mylist_test1.InsNode(2);
	//mylist_test1.InsNode(7);
	//mylist_test1.InsNode(12);
	//mylist_test1.InsNode(18);

	ListNode* one=new ListNode(1);
	ListNode* two=new ListNode(0);
	ListNode* three = new ListNode(1);


	one->pNext = two;
	two->pNext = three;

	int test = toDec(one);


	return 0;
}