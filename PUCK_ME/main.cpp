#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

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

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}