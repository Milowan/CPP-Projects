#ifndef NODE_H
#define NODE_H

class Node
{
	friend class Stack;

private:
	int mData;
	Node *next;
	Node *prev;

public:
	Node(const int &data);

	int GetData();

	Node *GetNext();

	Node *GetPrev();

};

#endif // !NODE_H

