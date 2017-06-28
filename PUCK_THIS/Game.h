#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "GuiManager.h"

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
	std::unique_ptr<b2World> m_world;
	std::unique_ptr<GameManager> m_gameManager;
	std::unique_ptr<GuiManager> m_guiManager;
	uint16		m_maxFPS;
	//sf::Time	m_renderStep;
	sf::Time	m_renderTimer;
	sf::Time	m_desiredFrameTime;
};

