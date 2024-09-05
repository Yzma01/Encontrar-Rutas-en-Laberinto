#include "stackNode.h"

StackNode::StackNode()
{
    this->next = nullptr;
    this->x = 0;
    this->y = 0;
    this->visited = false;
    this->route = false;
}

StackNode::StackNode(int x, int y, bool visited, bool route)
{
    this->next = nullptr;
    this->x = x;
    this->y = y;
    this->visited = visited;
    this->route = route;
}

StackNode::~StackNode()
{
    this->next = nullptr;
}

StackNode* StackNode::getNext()
{
    return this->next;
}

int StackNode::getX()
{
    return this->x;
}

int StackNode::getY()
{
    return this->y;
}

void StackNode::setNext(StackNode* node)
{
    this->next = node;
}

void StackNode::setX(int x)
{
    this->x = x;
}

void StackNode::setY(int y)
{
    this->y = y;
}

void StackNode::setRoute(bool route)
{
    this->route = route;
}

bool StackNode::getRoute()
{
    return this->route;
}

void StackNode::print()
{
    std::cout <<'{' << this->x << ',' << this->y <<'}' << '\n';
}

bool StackNode::getVisited()
{
    return this->visited;
}

void StackNode::setVisited(bool visited)
{
    this->visited = visited;
}
