#include "header.hpp"


void refresh_screen(sf::RenderWindow &window, Board &b) {
	window.clear();
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			window.draw(b.getDisplaySquare(x, y));
		}
	}
	window.draw(b.getHeader());
	int t = b.getTime_Remaining();
	int f = b.getFlags();
	b.texts[0]->drawText(window, t);
	b.texts[1]->drawText(window, f);
	window.display();
}

bool DisplaySquareLeftClicked(sf::RenderWindow& window, Board& b) {
	int squares_remaining = 0;
	sf::Vector2f coordinates = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			if (b.getDisplaySquare(x, y).getGlobalBounds().contains(coordinates)) {
				if (b.leftClick(x, y) == true)
				{
					revealBomb(b);
					refresh_screen(window, b);
					MessageBoxA(NULL, "You Clicked On A Bomb!", "GAME OVER", MB_OK | MB_ICONEXCLAMATION);
					// returns true to set gameover to true
					return true;
				}
			}
			if (b.getSquare(x, y).mIsBomb == false && b.getSquare(x, y).mHidden == true) {
				squares_remaining++;
			}
		}
	}
	if (squares_remaining == 0) {
		refresh_screen(window, b);
		MessageBoxA(NULL, "You Win!", "ALL BOMBS FOUND", MB_OK | MB_ICONASTERISK);
		return true;
	}
	return false;
}

void DisplaySquareRightClicked(sf::RenderWindow& window, Board& b) {
	int ret = 0;
	sf::Vector2f coordinates = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			if (b.getDisplaySquare(x, y).getGlobalBounds().contains(coordinates)) {
				ret = b.getSquare(x, y).mRightClicked();
				if (ret == 0) {
					break;
				}
				else if (ret == 1) {
					int temp = b.getFlags();
					b.setFlags(temp + 1);
					b.getDisplaySquare(x, y).setTexture(NULL);
				}
				else {
					int temp = b.getFlags();
					b.setFlags(temp - 1);
					b.getDisplaySquare(x, y).setTexture(b.getTextures().retrieveTexture(10));
				}
			}
		}
	}
}

bool DisplaySquareDoubleClicked(sf::RenderWindow& window, Board& b)
{
	sf::Vector2f coordinates = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	for (int x = 0; x < 10; x++) 
	{
		for (int y = 0; y < 10; y++) 
		{
			if (b.getDisplaySquare(x, y).getGlobalBounds().contains(coordinates))
			{
				if (b.nonrecursiveReveal(x, y, true) == -1)
				{
					revealBomb(b);
					refresh_screen(window, b);
					MessageBoxA(NULL, "You Clicked On A Bomb!", "GAME OVER", MB_OK | MB_ICONEXCLAMATION);
					// returns true to set gameover to true
					return true;
				}
			}
		}
	}
	return false;
}

void revealBomb(Board& b)
{
	for (int x = 0; x < 10; x++) 
	{
		for (int y = 0; y < 10; y++)
		{
			if (b.getSquare(x, y).mBombsAdjacent == 9) 
			{
				b.getDisplaySquare(x, y).setTexture(b.getTextures().retrieveTexture(9));
			}
		}
	}
}