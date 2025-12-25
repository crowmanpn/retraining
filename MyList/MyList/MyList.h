#pragma once
#include <string>
struct Node
{
	Node* pNext;
	std::string val;

	Node() :pNext(nullptr) {};
	Node(const std::string& str) {	  //переписаит списком ин
		val = str;
		pNext = nullptr;
	}
};

class MyList {
private:
	Node* pHead;
	Node* pTail;
	size_t cnt;

public:

   	MyList() :pHead(nullptr), pTail(nullptr),cnt(0) {};
	void InsNode(const std::string& str);
	void InsNode(const std::string& str, size_t pos);
	bool RemNode(size_t pos);
	bool RemNode(const std::string& str); 
	void PrintList() const; //почитать про static
	

	~MyList();


};