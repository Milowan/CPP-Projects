#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack():
	head(NULL),
	tail(NULL)
{}

Stack::~Stack()
{
	Clear();
}

bool Stack::operator==(const Stack &alternate)
{
	bool match;
	if (Count() == alternate.Count())
	{
		Node *node = head;
		Node *aNode = alternate.head;
		while (node != NULL && aNode != NULL)
		{
			if (node->mData == aNode->mData)
				match = true;
			else
			{
				match = false;
				break;
			}
			node = node->next;
			aNode = aNode->next;
		}
	}
	else
	{
		match = false;
	}

	return match;
}

Stack &Stack::operator=(const Stack &source)
{
	Clear();
	Node *node = source.head;
	while (node != NULL)
	{
		Push(node->mData);
		node = node->next;
	}

	return *this;
}

Node *Stack::Begin()
{
	return head;
}

Node *Stack::End()
{
	return tail;
}

bool Stack::IsEmpty() const
{
	bool isEmpty;
	if (Count() == 0)
	{
		isEmpty = true;
	}
	else
	{
		isEmpty = false;
	}
	return isEmpty;
}

void Stack::Display() const
{
	if (head == NULL)
	{
		cout << "<Empty>" << endl;
		system("pause");
		return;
	}

	Node *node = tail;

	while (node != NULL)
	{
		cout << node->mData << endl;
		node = node->prev;
	}
	system("pause");
}

int Stack::Count() const
{
	int lmnts = 0;
	Node *node = head;
	while (node != NULL)
	{
		++lmnts;
		node = node->next;
	}
	return lmnts;
}

int Stack::Top() const
{
	int retNum;
	if (head == NULL)
	{
		retNum = ERROR;
	}
	else
	{
		retNum = tail->mData;
	}
	return retNum;
}

void Stack::Push(int data)
{
	Node *node = new Node(data);

	if (head == NULL)
	{
		head = node;
		tail = node;
	}
	else
	{
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
}

void Stack::Pop()
{
	if (head == NULL)
	{
		cout << "The stack is empty, cannot call Pop()\n";
		system("pause");
	}
	else
	{
		if (head == tail)
		{
			Node *tmp = head;
			head = NULL;
			tail = NULL;
			delete tmp;
		}
		else
		{
			Node *tmp = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete tmp;
		}
	}
}

void Stack::Clear()
{
	while (head != NULL)
	{
		Node *tmp = head;
		head = head->next;
		delete tmp;
	}

	head = NULL;
	tail = NULL;
}