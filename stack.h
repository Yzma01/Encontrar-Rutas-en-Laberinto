#pragma once
#include "stackNode.h"
class Stack {
private:
	StackNode *head;
public:
	Stack();
	~Stack();
	StackNode getHead();
	void push(StackNode*);
	StackNode* pop();
	void print();
	StackNode* searchNode(int, int);
	bool isEmpty();
	StackNode* popLastRoute();
	StackNode* peek();
};