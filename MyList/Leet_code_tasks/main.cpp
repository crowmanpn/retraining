#include <iostream>

//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
	//пустой список?
		ListNode* cur = head;
		ListNode* prev = nullptr;
		//≈сли мы идем в начале списка флаг равен 0,
		// ак только нашли несопадающее значение - флаг подн€ли!
		bool fl = 0;


		while (cur != nullptr) {
					   
			if (cur->val == val)
			{
				ListNode* elToDel = cur;
				if (prev!=nullptr)		  //в середине
				{
					cur = prev;
					cur->next = elToDel->next;
		
				}
				else
				{
					head = head->next;//смещение головы
					cur = head;
				}
				delete elToDel;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		
		}
		return  head;
	}
};


int main() {
	//задача 1: 1,2,6,3,4,5,6
	ListNode* one = new ListNode(1);
	ListNode* two = new ListNode(2);
	ListNode* three = new ListNode(3);
	ListNode* four = new ListNode(4);
	ListNode* five = new ListNode(5);
	ListNode* six = new ListNode(6);
	ListNode* seven = new ListNode(7);

	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	five->next = six;
	six->next = seven;

	Solution mySol;
	ListNode* res=mySol.removeElements(one, 3);

	ListNode* s1 = new ListNode(7);
	ListNode* s2 = new ListNode(7);
	ListNode* s3 = new ListNode(7);

	s1->next = s2;
	s2->next = s3;
	
	res = mySol.removeElements(s1, 7);

	/*ListNode* emptyTest = new ListNode;

	res = mySol.removeElements(emptyTest, 1);*/




	return 0;
}