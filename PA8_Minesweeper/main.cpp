#include "header.hpp"
int main() {
	srand(time(NULL));
	Board b;

	// resets all squares and displaysquares then initializes bombs and numbers
	b.reset_board();
	b.printBoardCMD();
	//  time remaining is 120 - time elapsed
	// clock object that keeps track of time elapsed
	sf::Clock clock;

	bool game_over = false;

	// window object with 788 x 798 + 80 (80 is for header) dimensions.
	sf::RenderWindow window(sf::VideoMode(798, 798 + 80), "MineSweeper");

	// 
	while (window.isOpen()) {
		b.setTime_Remaining(ceil(120 - clock.getElapsedTime().asSeconds()));
		if (b.getTime_Remaining() <= 0) {
			MessageBoxA(NULL, "You Ran Out Of Time!", "GAME OVER", MB_OK | MB_ICONEXCLAMATION);
			clock.restart();
			game_over = true;
		}
		// gets checked every frame to see if the game needs to be reset
		if (game_over == true) {
			clock.restart();
			game_over = false;
			b.reset_board();
		}

		// sfml event variable is polled every frame to check for mouse button inputs
		// and to see if the tab needs to gracefully close due to a force exit
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			// checks for left click
			bool left, right, double_click;
			double_click = left = right = false;
			while ((sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)|| sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)  && sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
				{
					double_click = true;
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
				{
					left = true;
					right = false;
				}
				else if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
				{
					left = false;
					right = true;
				}
			}
			if (double_click)
			{

				game_over = DisplaySquareDoubleClicked(window, b);
			}
			else if (!double_click && (left && !right))
			{
				// left clicks and if bomb is hit sets game_over to 1
				game_over = DisplaySquareLeftClicked(window, b);
			}
			// checks for right click
			else if (!double_click && (!left && right))
			{
				// right clicks on a square to try to flag it
				DisplaySquareRightClicked(window, b);
			}
		}
		// all objects on screen are cleared, drawn and displayed every frame
		refresh_screen(window, b);
	}
}