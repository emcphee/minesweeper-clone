#pragma once
#include "SFML/Graphics.hpp"
class TextDisplayBase
{
public:
	sf::Text text;
	// num represents bombs - flags or number of seconds remaining
	virtual void drawText(sf::RenderWindow &window, int& num) { return; };
};

