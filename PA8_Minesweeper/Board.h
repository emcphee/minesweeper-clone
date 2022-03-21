#pragma once
#include "Square.h"
#include "header.hpp"
#include "DisplayBoard.h"
#include "Textures.h"
#include "TextDisplayBase.h"
#include "TimeRemainingText.h"
class Board
{
private:
	int flags;
	int time_remaining;
	sf::RectangleShape header;
	sf::Font arial;
	Textures textures;
	DisplaySquare dSquareArray[10][10];
	Square SquareArray[10][10];
public:
	TextDisplayBase* texts[2];
	Square& getSquare(int x, int y) { return SquareArray[x][y]; };
	void initializeBombs();
	void reset_board();

	// remove this
	void printBombArray();
	void printNumbersArray();
	void printBoardCMD();

	//getter
	int getFlags() {return flags; };
	void setFlags(int newFlags) { flags = newFlags; };
	int getTime_Remaining() { return time_remaining; };
	void setTime_Remaining(int newTime) { time_remaining = newTime; };
	sf::RectangleShape getHeader() { return header; };
	Textures& getTextures() { return textures; };
	sf::Font getArial() { return arial; };



	void initializeSquareNumber(int x, int y);
	void initializeNumbers();
	void recursiveReveal(int x, int y);
	int nonrecursiveReveal(int x, int y, bool mode);
	bool leftClick(int x, int y);


	void setSquareTexture(int x, int y, const sf::Texture texture);
	DisplaySquare& getDisplaySquare(int x, int y);

	Board();
};

