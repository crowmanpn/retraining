#include "MyList.h"
#include "MyList_test.h"
#include "func.h"
#include <iostream>
//struct ListNode
//{
//	ListNode* pNext;
//	int val;
//
//	ListNode() :pNext(nullptr),val(0) {};
//	ListNode(const int v) {	  //переписаит списком ин
//		val = v;
//		pNext = nullptr;
//	}
//
//};
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




MyList_test* mergeTwoLists(MyList_test* list1, MyList_test* list2) {
	while (list1 && list2) {
		
	}
	
	return nullptr;
};

int main() {

	
	MyList mylist;	 //"Вариардик", функция с пермен числом параметром (вспомнить).
	
	mylist.InsNode("one");
	mylist.InsNode("two");
	mylist.InsNode("three",0);

	mylist.PrintList();
	
	std::cout<<std::endl;

	mylist.RemNode(0);
	mylist.RemNode("two");
	mylist.RemNode("three");

	mylist.PrintList();

	MyList_test mylist_test1;
	mylist_test1.InsNode(3);
	mylist_test1.InsNode(8);
	mylist_test1.InsNode(15);
	mylist_test1.InsNode(20);

	MyList_test mylist_test2;
	mylist_test1.InsNode(2);
	mylist_test1.InsNode(7);
	mylist_test1.InsNode(12);
	mylist_test1.InsNode(18);



	return 0;
}