#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();

	void update();


	bool m_bPrintFPS;

private:
	std::unique_ptr<sf::Clock> m_frameClock;
};

