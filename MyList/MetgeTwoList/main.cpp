#include <iostream>
#include "MTLists.h"

int main() {
	//list 1
	ListNode* head1 = new ListNode(1);
	ListNode* curr = head1;
	for (size_t i = 2; i < 5; i++)
	{
		curr->next = new ListNode(i);
		curr = curr->next;

	}
	
	//list 2
	ListNode* head2 = new ListNode(3);
	curr = head2;

	for (size_t i = 4; i < 8; i++)
	{
		curr->next = new ListNode(i);
		curr = curr->next;
	}

	ListNode* test=mergeTwoLists(head1,head2);
	
	while (head1)
	{
		ListNode* tmp = head1;
		head1 = head1->next;
		delete tmp;
	}

	while (head2)
	{
		ListNode* tmp = head2;
		head2 = head2->next;
		delete tmp;
	}
	//просмотреть два списка в одном цикле 


	return 0;
}