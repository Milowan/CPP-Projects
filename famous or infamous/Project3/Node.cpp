#include "Node.h"

Node::Node(const string &rQuestion, Node *pYes, Node *pNo):
	question(rQuestion),
	yes(pYes),
	no(pNo)
{}

bool Node::IsFinalQuestion() const
{
	return (yes == NULL && no == NULL);
}

string Node::GetQuestion()
{
	return question;
}