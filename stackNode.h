#pragma once
#include <iostream>
class StackNode {
private:
	int x;
	int y;
	bool visited;
	bool route;
	StackNode* next;
public:
	StackNode();
	StackNode(int, int, bool, bool);
	~StackNode();
	StackNode* getNext();
	int getX();
	int getY();
	void setNext(StackNode*);
	void setX(int);
	void setY(int);
	void setRoute(bool);
	bool getRoute();
	void print();
	bool getVisited();
	void setVisited(bool);

};