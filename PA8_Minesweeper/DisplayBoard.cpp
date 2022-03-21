#include "DisplayBoard.h"


DisplaySquare& DisplayBoard::getDisplaySquare(int x, int y) {
	return GridArray[x][y];
}
void DisplayBoard::setSquareTexture(int x, int y, const sf::Texture texture) {
	GridArray[x][y].setTexture(&texture);
}

DisplayBoard::DisplayBoard() {
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			GridArray[x][y].setPosition(sf::Vector2f(x * 80, y * 80));
		}
	}
}