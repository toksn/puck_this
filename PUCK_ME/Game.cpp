#include "Game.h"
#include "Puck.h"

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

	m_gameManager.refresh();

	m_gameManager.update(deltaTime);

	if (m_window)
	{
		m_window->clear();
		m_gameManager.draw(*m_window);
		m_window->display();
	}
}

void Game::restart()
{

	// create a puck
	//m_gameManager.create<Puck>(m_window->getSize().x, m_window->getSize().y);
	m_gameManager.create<Puck>();

	// create
}
