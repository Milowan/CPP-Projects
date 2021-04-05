#ifndef TREEH
#define TREEH
#include "Node.h"

class Tree
{
private:

	Node *root;

	Node *current;

	Node *currentParent;

public:

	Tree();

	~Tree();

	void Reset();

	void Delete(Node *pNode);

	void iInOrder(fstream &fs, Node &node, int mN, int pos);

	void oInOrder(fstream &fs, Node &node, int mN, int pos);

	bool DisplayCurrentQuestion();

	void NextQuestion(char answer);

	void AddPerson();

	void LoadTree(fstream &fs, Node &node);

	void SaveTree(fstream &fs, Node &node, int height);

	Node &GetRoot();

	int TreeHeight(Node *node);

	char AskYesNo(const string &rQuestion = "");

	static const char YES = 'y';
	static const char NO = 'n';
};

#endif