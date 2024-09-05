#include "stack.h"

Stack::Stack()
{
	this->head = nullptr;
}

Stack::~Stack()
{
	if (head != nullptr) {
		StackNode* auxNode = head;
		StackNode* auxHead = nullptr;
		while (auxHead != nullptr) {
			auxHead = auxNode->getNext();
			auxNode->~StackNode();
		}
	}
}

StackNode Stack::getHead()
{
	return StackNode();
}

void Stack::push(StackNode* node) {
	if (head == nullptr) {
		head = node;;
	}
	else {
		StackNode* auxNode = head;
		while (auxNode != nullptr) {
			if (auxNode->getNext() == nullptr)
			{
				auxNode->setNext(node);
				break;
			}
			auxNode = auxNode->getNext();
		}
	}
}

StackNode* Stack::popLastRoute() {
	if (head != nullptr) {
		StackNode* auxNode = head;
		while (auxNode != nullptr) {
			if (auxNode->getNext()->getRoute() == false){
				return auxNode;
			}
			auxNode = auxNode->getNext();
		}
	}
}

StackNode* Stack::peek()
{
	if (head != nullptr) {
		StackNode* auxNode = head;
		while (auxNode != nullptr) {
			if (auxNode->getNext() == nullptr)
			{
				return auxNode;
			}
			auxNode = auxNode->getNext();
		}
	}
}

StackNode* Stack::pop()
{
	if (head != nullptr) {
		StackNode* auxNode = head;
		StackNode* previous = nullptr;
		while (auxNode != nullptr) {
			if (auxNode->getNext() == nullptr)
			{
				previous->setNext(nullptr);
				return auxNode;
			}
			previous = auxNode;
			auxNode = auxNode->getNext();
		}
	}

}

void Stack::print()
{
	if (this->head != nullptr) {
		StackNode* aux = this->head;
		while (aux != nullptr) {
			aux->print();
			aux = aux->getNext();
		}
	}
}

StackNode* Stack::searchNode(int x, int y)
{
	if (this->head != nullptr) {
		StackNode* aux = this->head;
		while (aux != nullptr) {
			if (aux->getX() == x && aux->getY() == y) {
				return aux;
			}
			aux = aux->getNext();
		}
	}
	return nullptr;
}

bool Stack::isEmpty()
{
	if (this->head == nullptr) {
		return true;
	}
	return false;
}
