#pragma once
#include "SFML/Graphics.hpp"

class Textures
{
public:
	Textures();
	sf::Texture* retrieveTexture(int num);
private:
	sf::Texture textures[11];
};

