#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "GameManager.h"

class Game
{
public:
	Game();
	~Game();

	void update();
	void setMaxFPS(uint16 maxFPS);
	void run();
	void restart();

	bool m_bPrintFPS;
	sf::RenderWindow* m_window;

private:
	std::unique_ptr<sf::Clock> m_frameClock;
	GameManager m_gameManager;
	uint16		m_maxFPS;
	//sf::Time	m_renderStep;
	sf::Time	m_renderTimer;
	sf::Time	m_desiredFrameTime;
};

