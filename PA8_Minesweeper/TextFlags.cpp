#include "TextFlags.h"

void TextFlags::drawText(sf::RenderWindow& window, int& num) {
	std::string s = "Bombs - Flags: ";
	s.append(std::to_string(num));
	text.setString(s);
	window.draw(text);
}