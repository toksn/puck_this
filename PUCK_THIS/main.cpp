#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "puck this s***");
	
	Game game;
	game.m_window = &window;

	game.restart();
	game.run();

	return 0;
}