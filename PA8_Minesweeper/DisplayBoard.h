#pragma once
#include "DisplaySquare.h"
#include "SFML/Graphics.hpp"
class DisplayBoard
{
public:
	DisplayBoard();
	DisplaySquare& getDisplaySquare(int x, int y);
	void setSquareTexture(int x, int y, const sf::Texture texture);
private:
	DisplaySquare GridArray[10][10];
};

