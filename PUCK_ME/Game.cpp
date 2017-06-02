#include "Game.h"

Game::Game()
{
	m_frameClock = std::make_unique<sf::Clock>();
	bool m_bPrintFPS = false;
}


Game::~Game()
{
}


void Game::update()
{
	// check for elapsed time and restart clock for next cycle
	float deltaTime = (*m_frameClock).restart().asMicroseconds() / 1000.0f;
		
	if(m_bPrintFPS)
		printf("\nFPS: %f", 1000.0f/deltaTime);

	//Manager.update(deltaTime);
}