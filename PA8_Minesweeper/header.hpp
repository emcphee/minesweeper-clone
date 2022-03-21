#pragma once

#include <SFML/Graphics.hpp>

#include <time.h>
#include <random>
#include <iostream>
#include <windows.h>

#include "Board.h"
#include "DisplaySquare.h"
#include "Textures.h"
#include "Square.h"
#include "Textures.h"
#include "DisplayBoard.h"
#include "TextDisplayBase.h"
#include "TextFlags.h"
#include "TimeRemainingText.h"

#define BombCount 10
#define BoardSize 10


void refresh_screen(sf::RenderWindow &window, Board &b);
bool DisplaySquareLeftClicked(sf::RenderWindow& window, Board& b);
void DisplaySquareRightClicked(sf::RenderWindow& window, Board& b);
bool DisplaySquareDoubleClicked(sf::RenderWindow& window, Board& b);
void revealBomb(Board& b);