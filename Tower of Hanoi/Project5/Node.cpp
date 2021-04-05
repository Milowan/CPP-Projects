#include "Node.h"
#include <iostream>

Node::Node(const int &data):
	mData(data),
	next(NULL),
	prev(NULL)
{}

int Node::GetData()
{
	return mData;
}

Node *Node::GetNext()
{
	return next;
}

Node *Node::GetPrev()
{
	return prev;
}