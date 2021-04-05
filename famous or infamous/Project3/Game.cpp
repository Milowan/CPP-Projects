#include "Game.h"
#include "Tree.h"
#include <iostream>


bool isEmpty(fstream &fs)
{
	return fs.peek() == fstream::traits_type::eof();
}

fstream &operator>>(fstream &fs, Tree *aTree)
{
	aTree->LoadTree(fs, aTree->GetRoot());
	return fs;
}

Tree &operator<<(fstream &fs, Tree *aTree)
{
	aTree->SaveTree(fs, aTree->GetRoot(), aTree->TreeHeight(&aTree->GetRoot()));
	return *aTree;
}

Game::Game()
{
	tree = new Tree;
}

void Game::DisplayInstructions()
{
	cout << "\tWelcome to Famous and Infamous\n\n";
	cout << "Think of a famous or infamous person ";
	cout << "and I'll try to guess his or her name.\n\n";
}

void Game::Play()
{
	fstream myTree("treeData.txt", ios_base::in);
	if (myTree.is_open())
	{
		bool empty = isEmpty(myTree);
		if (!empty)
			myTree >> tree;
	
		myTree.close();
	}
		tree->Reset();
		char response;
		while (tree->DisplayCurrentQuestion())
		{
			response = tree->AskYesNo();
			tree->NextQuestion(response);
		}

		response = tree->AskYesNo();

		if (response == tree->YES)
			cout << "I guessed it!\n";
		else
		{
			cout << "I give up.\n";
			tree->AddPerson();
			myTree.open("treeData.txt", ios_base::out | ios_base::trunc);
			if (myTree.is_open())
			{
				myTree << tree;
				myTree.close();
			}
		}
	

}