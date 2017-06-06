#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "PUCK_ME");
	
	//sf::CircleShape shape(10.f);
	//shape.setFillColor(sf::Color::Green);

	Game game;
	game.m_window = &window;

	game.restart();
		
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::Resized)
			{
				auto size = window.getSize();
				printf("\nwindow size changed: %i x %i", size.x, size.y);

				window.setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
			}
		}

		game.update();
	}

	return 0;
}