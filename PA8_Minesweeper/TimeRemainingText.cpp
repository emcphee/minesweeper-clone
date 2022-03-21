#include "TimeRemainingText.h"


void TimeRemainingText::drawText(sf::RenderWindow &window, int &num) {
	std::string s = "Time Remaining: ";
	s.append(std::to_string(num));
	text.setString(s);
	window.draw(text);
}