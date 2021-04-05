// File				: Space.cpp
// PROJECT			: Minesweeper
// PROGRAMMER		: Gavin McGuire

#include <iostream>
#include "Space.h"

Space::Space()
{
	hasMine = false;
	mNum = 0;
	isFlagged = false;
	isActivated = false;
}

Space::Space(bool mined)
{
	hasMine = mined;
	mNum = 0;
	isFlagged = false;
	isActivated = false;
}

Space::~Space()
{
	//does nothing
}

void Space::setMNum(int mCnt)
{
	mNum = mCnt;
}

void Space::activateSpace()
{
	if (!isActivated)
	{
		isActivated = !isActivated;
	}
}

void Space::toggleFlagState()
{
	isFlagged = !isFlagged;
}

const int Space::getMNum()// Steven - This function should be a const function
{
	return mNum;
}

const bool Space::getActiveState()// Steven - This function should be a const function
{
	return isActivated;
}

const bool Space::getMineState()// Steven - This function should be a const function
{
	return hasMine;
}

const bool Space::getFlagState()// Steven - This function should be a const function
{
	return isFlagged;
}