#include "Board.h"
#include "header.hpp"

void Board::initializeBombs() {
	int i = 0;
	int x = 0;
	int y = 0;
	while (i < BombCount) {
		x = rand() % BoardSize;
		y = rand() % BoardSize;
		Square &s = getSquare(x, y);
		if (!s.mIsBomb) {
			s.mIsBomb = true;
			i++;
		}
	}
}

void Board::initializeSquareNumber(int x, int y) {
	if (getSquare(x, y).mIsBomb) {
		getSquare(x, y).mBombsAdjacent = 9;
		return;
	}
	int bombs = 0;
	// checks directly below
	if (y + 1 < BoardSize && getSquare(x, y + 1).mIsBomb) {
		bombs++;
	}
	// checks directly to the right
	if (x + 1 < BoardSize && getSquare(x + 1, y).mIsBomb) {
		bombs++;
	}
	// checks down right
	if ((x + 1 < BoardSize && y + 1 < BoardSize) && getSquare(x + 1, y + 1).mIsBomb) {
		bombs++;
	}
	// checks left down
	if ((x - 1 >= 0 && y + 1 < BoardSize) && getSquare(x - 1, y + 1).mIsBomb) {
		bombs++;
	}
	// checks right up
	if ((x + 1 < BoardSize && y - 1 >= 0) && getSquare(x + 1, y - 1).mIsBomb) {
		bombs++;
	}
	// checks left
	if (x - 1 >= 0 && getSquare(x - 1, y).mIsBomb) {
		bombs++;
	}
	// checks up
	if (y - 1 >= 0 && getSquare(x, y - 1).mIsBomb) {
		bombs++;
	}
	// checks left up
	if ((x - 1 >= 0 && y - 1 >= 0) && getSquare(x - 1, y - 1).mIsBomb) {
		bombs++;
	}
	getSquare(x, y).mBombsAdjacent = bombs;
}

void Board::initializeNumbers() {
	for (int y = 0; y < BoardSize; y++) {
		for (int x = 0; x < BoardSize; x++) initializeSquareNumber(x,y);
	}
}


void Board::printBoardCMD() {
	for (int x = 0; x < BoardSize; x++) {
		for (int y = 0; y < BoardSize; y++) {
				std::cout << SquareArray[x][y].mBombsAdjacent;
		}
		std::cout << std::endl;
	}
}

// returns true if game ends
bool Board::leftClick(int x, int y) {
	int ret = 0;
	ret = SquareArray[x][y].mLeftClicked();
	// game ends.. bomb
	if (ret == -1) {
		return true;
	}
	// blank, unhides keeps going
	if (ret == 1) {
		recursiveReveal(x,y);
		dSquareArray[x][y].setTexture(textures.retrieveTexture(0));
	}
	// unhides
	if (ret == 2) {
		dSquareArray[x][y].setTexture(textures.retrieveTexture(SquareArray[x][y].mBombsAdjacent));
	}
	return 0;
}
int Board::nonrecursiveReveal(int x, int y, bool mode)
{
	int flag_num = 0;
	if (y + 1 < BoardSize) {
		if (SquareArray[x][y + 1].mFlagged)
		{
			++flag_num;
		}
		if (!mode)
		{
			if (SquareArray[x][y + 1].mBombsAdjacent == 9 && !SquareArray[x][y + 1].mFlagged)
			{
				return -1;
			}
			if (SquareArray[x][y + 1].mBombsAdjacent < 9)
			{
				if (SquareArray[x][y + 1].mBombsAdjacent == 0)
				{
					recursiveReveal(x, y + 1);
				}
				else
				{
					dSquareArray[x][y + 1].setTexture(textures.retrieveTexture(SquareArray[x][y + 1].mBombsAdjacent));
				}
			}
		}
	}
	// checks directly to the right
	if (x + 1 < BoardSize) {
		if (SquareArray[x+1][y].mFlagged)
		{
			++flag_num;
		}
		if (!mode)
		{
			if (SquareArray[x + 1][y].mBombsAdjacent == 9 && !SquareArray[x + 1][y].mFlagged)
			{
				return -1;
			}
			if (SquareArray[x + 1][y].mBombsAdjacent < 9)
			{
				if (SquareArray[x + 1][y].mBombsAdjacent == 0)
				{
					recursiveReveal(x + 1, y);
				}
				else
				{
					dSquareArray[x + 1][y].setTexture(textures.retrieveTexture(SquareArray[x + 1][y].mBombsAdjacent));
				}
			}
		}
	}
	// checks down right
	if ((x + 1 < BoardSize && y + 1 < BoardSize)) {
		if (SquareArray[x+1][y + 1].mFlagged)
		{
			++flag_num;
		}
		if (!mode)
		{
			if (SquareArray[x + 1][y + 1].mBombsAdjacent == 9 && !SquareArray[x + 1][y + 1].mFlagged)
			{
				return -1;
			}
			if (SquareArray[x + 1][y + 1].mBombsAdjacent < 9)
			{
				if (SquareArray[x + 1][y + 1].mBombsAdjacent == 0)
				{
					recursiveReveal(x + 1, y + 1);
				}
				else
				{
					dSquareArray[x + 1][y + 1].setTexture(textures.retrieveTexture(SquareArray[x + 1][y + 1].mBombsAdjacent));
				}
			}
		}
	}
	// checks left down
	if ((x - 1 >= 0 && y + 1 < BoardSize)) {
		if (SquareArray[x-1][y + 1].mFlagged)
		{
			++flag_num;
		}
		if (!mode)
		{
			if (SquareArray[x - 1][y + 1].mBombsAdjacent == 9 && !SquareArray[x - 1][y + 1].mFlagged)
			{
				return -1;
			}
			if (SquareArray[x - 1][y + 1].mBombsAdjacent < 9)
			{
				if (SquareArray[x - 1][y + 1].mBombsAdjacent == 0)
				{
					recursiveReveal(x - 1, y + 1);
				}
				else
				{
					dSquareArray[x - 1][y + 1].setTexture(textures.retrieveTexture(SquareArray[x - 1][y + 1].mBombsAdjacent));
				}
			}
		}
	}
	// checks right up
	if ((x + 1 < BoardSize && y - 1 >= 0)) {
		if (SquareArray[x+1][y - 1].mFlagged)
		{
			++flag_num;
		}
		if (!mode)
		{
			if (SquareArray[x + 1][y - 1].mBombsAdjacent == 9 && !SquareArray[x + 1][y - 1].mFlagged)
			{
				return -1;
			}
			if (SquareArray[x + 1][y - 1].mBombsAdjacent < 9)
			{
				if (SquareArray[x + 1][y - 1].mBombsAdjacent == 0)
				{
					recursiveReveal(x + 1, y - 1);
				}
				else
				{
					dSquareArray[x + 1][y - 1].setTexture(textures.retrieveTexture(SquareArray[x + 1][y - 1].mBombsAdjacent));
				}
			}
		}
	}
	// checks left
	if (x - 1 >= 0) {
		if (SquareArray[x-1][y].mFlagged)
		{
			++flag_num;
		}
		if (!mode)
		{
			if (SquareArray[x - 1][y].mBombsAdjacent == 9 && !SquareArray[x - 1][y].mFlagged)
			{
				return -1;
			}
			if (SquareArray[x - 1][y].mBombsAdjacent < 9)
			{
				if (SquareArray[x - 1][y].mBombsAdjacent == 0)
				{
					recursiveReveal(x - 1, y);
				}
				else
				{
					dSquareArray[x - 1][y].setTexture(textures.retrieveTexture(SquareArray[x - 1][y].mBombsAdjacent));
				}
			}
		}
	}
	// checks up
	if (y - 1 >= 0) {
		if (SquareArray[x][y - 1].mFlagged)
		{
			++flag_num;
		}
		if (!mode)
		{
			if (SquareArray[x][y - 1].mBombsAdjacent == 9 && !SquareArray[x][y - 1].mFlagged)
			{
				return -1;
			}
			if (SquareArray[x][y - 1].mBombsAdjacent < 9)
			{
				if (SquareArray[x][y - 1].mBombsAdjacent == 0)
				{
					recursiveReveal(x, y - 1);
				}
				else
				{
					dSquareArray[x][y - 1].setTexture(textures.retrieveTexture(SquareArray[x][y - 1].mBombsAdjacent));
				}
			}
		}
	}
	// checks left up
	if ((x - 1 >= 0 && y - 1 >= 0)) {
		if (SquareArray[x-1][y - 1].mFlagged)
		{
			++flag_num;
		}
		if (!mode)
		{
			if (SquareArray[x - 1][y - 1].mBombsAdjacent == 9 && !SquareArray[x - 1][y - 1].mFlagged)
			{
				return -1;
			}
			if (SquareArray[x - 1][y - 1].mBombsAdjacent < 9)
			{
				if (SquareArray[x - 1][y - 1].mBombsAdjacent == 0)
				{
					recursiveReveal(x - 1, y - 1);
				}
				else
				{
					dSquareArray[x - 1][y - 1].setTexture(textures.retrieveTexture(SquareArray[x - 1][y - 1].mBombsAdjacent));
				}
			}
		}
	}
	if ((SquareArray[x][y].mBombsAdjacent == flag_num && mode))
	{
		if (nonrecursiveReveal(x, y, false) == -1)
		{
			return -1;
		}
	}
}
void Board::recursiveReveal(int x, int y) {
	// checks directly below
	if (y + 1 < BoardSize) {
		leftClick(x, y + 1);
	}
	// checks directly to the right
	if (x + 1 < BoardSize) {
		leftClick(x + 1, y);
	}
	// checks down right
	if ((x + 1 < BoardSize && y + 1 < BoardSize)) {
			leftClick(x + 1, y + 1);
	}
	// checks left down
	if ((x - 1 >= 0 && y + 1 < BoardSize)) {
			leftClick(x - 1, y + 1);
	}
	// checks right up
	if ((x + 1 < BoardSize && y - 1 >= 0)) {
			leftClick(x + 1, y - 1);
	}
	// checks left
	if (x - 1 >= 0) {
		leftClick(x - 1, y);
	}
	// checks up
	if (y - 1 >= 0) {
		leftClick(x, y - 1);
	}
	// checks left up
	if ((x - 1 >= 0 && y - 1 >= 0)) {
			leftClick(x - 1, y - 1);
	}
}

Board::Board() {
	// sets num flags to bomb count
	flags = BombCount;
	arial.loadFromFile("arial.ttf");

	// time remaining and flags text allocation
	texts[0] = new TimeRemainingText;
	texts[1] = new TextFlags;

	// initializes time remaining text
	texts[0]->text.setCharacterSize(25);
	texts[0]->text.setFont(arial);
	texts[0]->text.setPosition(sf::Vector2f(10,10));

	// initializes flags text
	texts[1]->text.setCharacterSize(25);
	texts[1]->text.setFont(arial);
	texts[1]->text.setPosition(sf::Vector2f(400, 10));


	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			dSquareArray[x][y].setPosition(sf::Vector2f(y * 80, x * 80 + 80));
		}
	}
}

void Board::setSquareTexture(int x, int y, const sf::Texture texture) {
	dSquareArray[x][y].setTexture(&texture);
}

DisplaySquare& Board::getDisplaySquare(int x, int y) {
	return dSquareArray[x][y];
}

void Board::reset_board() {

	header.setSize(sf::Vector2f(798,80));
	header.setFillColor(sf::Color(0,119,255));

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			SquareArray[x][y].mFlagged = false;
			SquareArray[x][y].mHidden = true;
			SquareArray[x][y].mIsBomb = false;
			SquareArray[x][y].mBombsAdjacent = 0;

			dSquareArray[x][y].setSize(sf::Vector2f(78, 78));
			dSquareArray[x][y].setFillColor(sf::Color::White);
			dSquareArray[x][y].setOutlineColor(sf::Color::Black);
			dSquareArray[x][y].setOutlineThickness(1);
			dSquareArray[x][y].setTexture(NULL);
		}
	}
	initializeBombs();
	initializeNumbers();
}