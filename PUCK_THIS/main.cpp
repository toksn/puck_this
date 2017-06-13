#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	//b2Settings::
	
	sf::RenderWindow window(sf::VideoMode(600, 400), "puck this s***");
	//window.setFramerateLimit(100);
	Game game;
	game.m_window = &window;

	game.restart();
	game.run();

	return 0;
}