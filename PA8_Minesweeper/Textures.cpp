#include "Textures.h"


Textures::Textures() {

	textures[0].loadFromFile("dark_hidden.png");
	textures[1].loadFromFile("minesweeper_1.png");
	textures[2].loadFromFile("minesweeper_2.png");
	textures[3].loadFromFile("minesweeper_3.png");
	textures[4].loadFromFile("minesweeper_4.png");
	textures[5].loadFromFile("minesweeper_5.png");
	textures[6].loadFromFile("minesweeper_6.png");
	textures[7].loadFromFile("minesweeper_7.png");
	textures[8].loadFromFile("minesweeper_8.png");
	textures[9].loadFromFile("minesweeper_bomb.png");
	textures[10].loadFromFile("minesweeper_flag.png");
}

sf::Texture* Textures::retrieveTexture(int num) {
	return &textures[num];
}