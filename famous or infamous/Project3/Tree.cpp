#include "Tree.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include "Node.h"

Tree::Tree()
{
	Node *pGhandi = new Node("Are you thinking of Ghandi?", NULL, NULL);
	Node *pSanta = new Node("Are you thinking of Santa?", NULL, NULL);
	Node *pQuestion = new Node("Is/was the person real?", pGhandi, pSanta);
	root = pQuestion;
	current = root;
	currentParent = NULL;
}

Tree::~Tree()
{
	Delete(root);
}

void Tree::Reset()
{
	current = root;
	currentParent = NULL;
}

void Tree::Delete(Node *node)
{
	if (node != NULL)
	{
		Delete(node->yes);
		Delete(node->no);
		delete node;
		node = NULL;
	}
}

void Tree::iInOrder(fstream &fs, Node &node, int mN, int pos)
{
	if (&node != NULL && mN != 0)
	{
		int newPos = (2 * pos) + 1;
		if (newPos < mN)
		{
			node.yes = new Node;
			iInOrder(fs, *node.yes, mN, newPos);
			if (node.yes->question == "")
			{
				Delete(node.yes);
				node.yes = NULL;
			}

		}
		string data;
		getline(fs, data);
		node.question = data;
		newPos = (2 * pos) + 2;
		if (newPos < mN)
		{
			node.no = new Node;
			iInOrder(fs, *node.no, mN, newPos);
			if (node.no->question == "")
			{
				Delete(node.no);
				node.no = NULL;
			}
		}
	}
}

void Tree::oInOrder(fstream &fs, Node &node, int mN, int pos)
{
	if (&node != NULL)
	{
		int newPos = (2 * pos) + 1;
		if (newPos < mN)
		{
			if (node.yes == NULL)
				node.yes = new Node;
			oInOrder(fs, *node.yes, mN, newPos);
		}

		fs << node.GetQuestion() << endl;

		newPos = (2 * pos) + 2;
		if (newPos < mN)
		{
			if (node.no == NULL)
				node.no = new Node;
			oInOrder(fs, *node.no, mN, newPos);
		}
	}
}

bool Tree::DisplayCurrentQuestion()
{
	if (current == NULL)
		return false;
	cout << current->question << endl;

	return (!current->IsFinalQuestion());
}

void Tree::NextQuestion(char answer)
{
	if (!((current == NULL) && !(current->IsFinalQuestion())))
	{
		currentParent = current;

		if (answer == YES)
			current = current->yes;
		else
			current = current->no;
	}
}

void Tree::AddPerson()
{
	cout << "Who are you thinking of?: ";
	string name;
	cin.ignore();
	getline(cin, name);

	cout << "What question would distinguish these two people?:" << endl;
	string aQuestion;
	getline(cin, aQuestion);

	Node *person = new Node("Are you thinking of " + name + "?", NULL, NULL);
	Node *pQuestion = new Node(aQuestion, NULL, NULL);

	char answer = AskYesNo("What would the answer be for " + name + "?");

	if (answer == YES)
	{
		pQuestion->yes = person;
		pQuestion->no = current;
	}
	else
	{
		pQuestion->yes = current;
		pQuestion->no = person;
	}

	if (currentParent->yes == current)
		currentParent->yes = pQuestion;
	else
		currentParent->no = pQuestion;
}

void Tree::LoadTree(fstream &fs, Node &node)
{
	Delete(node.yes);
	Delete(node.no);
	string tmp;
	getline(fs, tmp);
	int n;
	stringstream(tmp) >> n;
	iInOrder(fs, node, n, 0);
}

void Tree::SaveTree(fstream &fs, Node &node, int height)
{
	int n = 0;
	n = (int)pow(2, height) - 1;
	stringstream ss;
	ss << n;
	string out = ss.str();
	fs << out << endl;
	oInOrder(fs, node, n, 0);
}

Node &Tree::GetRoot()
{
	return *root;
}

int Tree::TreeHeight(Node *node)
{
	int retVal = 0;
	if (node != NULL)
		retVal = max(TreeHeight(node->yes), TreeHeight(node->no)) + 1;
	return retVal;
}

char Tree::AskYesNo(const string &rQuestion)
{
	char response;
	do
	{
		cout << rQuestion;
		cout << " (" << YES << "/" << NO << "): ";
		cin >> response;
	} while (response != YES && response != NO);

	return response;
}

