#ifndef NODEH
#define NODEH

#include <fstream>
#include <string>

using namespace std;

class Node
{
	friend class Tree;

private:

	string question;
	Node *yes;
	Node *no;

public:

	Node() : question(""), yes(NULL), no(NULL) {};

	Node(const string &rQuestion, Node *pYes, Node *pNo);

	string GetQuestion();

	bool IsFinalQuestion() const;
};

#endif // !NODEH