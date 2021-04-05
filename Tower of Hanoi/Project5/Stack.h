#ifndef STACKH
#define STACKH
#include "Node.h"
class Stack
{
private:

	static const int ERROR = -1;

	Node *head;
	Node *tail;

public:

	Stack();
	~Stack();

	bool operator==(const Stack &alternate);

	Stack &operator=(const Stack &source);

	Node *Begin();
	Node *End();

	bool IsEmpty() const;

	void Display() const;

	int Count() const;

	int Top() const;

	void Push(int data);

	void Pop();

	void Clear();
};

#endif