#pragma once
// File				: Space.h
// PROJECT			: Minesweeper
// PROGRAMMER		: Gavin McGuire

// Name		: Space
// Purpose	: holds the information for a tile in minesweeper
class Space
{
private:

	int mNum;
	bool isActivated;
	bool hasMine;
	bool isFlagged;

public:

	Space();

	// FUNCTION		: Space()
	// DESCRIPTION	: constructs the Space class
	// PARAMETERS	: bool mined
	// RETURNS		: none
	Space(bool mined);

	// FUNCTION		: ~Space()
	// DESCRIPTION	: deconstructs the Space class
	// PARAMETERS	: none
	// RETURNS		: none
	~Space();

	//Function		: setMNum()
	//Purpose		: sets the count for how many adjacent tiles have mines
	//Arguments		: int mCnt
	//Returns		: none
	void setMNum(int mCnt);

	//Function		: activateSpace()
	//Purpose		: activates the tile
	//Arguments		: none
	//Returns		: none
	void activateSpace();

	// FUNCTION		: toggleFlagState()
	// DESCRIPTION	: toggles whether the space is flagged
	// PARAMETERS	: none
	// RETURNS		: none
	void toggleFlagState();

	// FUNCTION		: getMNum()
	// DESCRIPTION	: gets the number of mines the space is touching
	// PARAMETERS	: none
	// RETURNS		: int mNum
	const int getMNum();

	// FUNCTION		: getActiveState()
	// DESCRIPTION	: gets the activation state of the space
	// PARAMETERS	: none
	// RETURNS		: bool isActivated
	const bool getActiveState();

	// FUNCTION		: getMineState()
	// DESCRIPTION	: gets the mine state for the space
	// PARAMETERS	: none
	// RETURNS		: bool hasMine
	const bool getMineState();

	// FUNCTION		: getFlagstate()
	// DESCRIPTION	: gets the flag state of the space
	// PARAMETERS	: none
	// RETURNS		: bool isFlagged
	const bool getFlagState();
};