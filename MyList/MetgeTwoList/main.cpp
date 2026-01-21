#include <iostream>
#include "MTLists.h"

int main() {
	//list 1
	ListNode ln1(1);
	ListNode ln2(2);
	ListNode ln3(3);
	ListNode ln4(4);

	ln1.next = &ln2;
	ln2.next = &ln3;
	ln3.next = &ln4;
	//--------------
	//list 2
	ListNode ln21(10);
	ListNode ln22(20);
	ListNode ln23(30);
	ListNode ln24(40);

	ln21.next = &ln22;
	ln22.next = &ln23;
	ln23.next = &ln24;

	Solution mySol;
	mySol.mergeTwoLists(&ln1, &ln21);


	return 0;
}