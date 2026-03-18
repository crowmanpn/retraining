#pragma once
struct Node_test
{
	Node_test* pNext;
	int val;

	Node_test() :pNext(nullptr) {};
	Node_test(const int& oth) {	  //переписаит списком ин
		val = oth;
		pNext = nullptr;
	}
};

class MyList_test {
private:
	Node_test* pHead;
	Node_test* pTail;
	size_t cnt;

public:

	MyList_test() :pHead(nullptr), pTail(nullptr), cnt(0) {};
	void InsNode(const int& oth);
	void InsNode(const int& oth, size_t pos);
	bool RemNode(size_t pos);
	bool RemNode(const int& oth);
	void PrintList() const; //почитать про static
	


	~MyList_test();


};