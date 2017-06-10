#include "Game.h"
#include "Puck.h"
#include "Icefield.h"
#include "Player.h"

Game::Game()
{
	m_frameClock = std::make_unique<sf::Clock>();
	m_bPrintFPS = true;
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

void Game::run()
{
	while (m_window && m_window->isOpen())
	{
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window->close();

			if (event.type == sf::Event::Resized)
			{
				auto size = m_window->getSize();
				printf("\nwindow size changed: %i x %i", size.x, size.y);

				m_window->setView(sf::View(sf::FloatRect(0.0f, 0.0f, (float)size.x, (float)size.y)));
			}
		}

		// update the game
		update();
	}
}

void Game::restart()
{

	// create an icefield, puck and player
	m_gameManager.create<Icefield>();
	m_gameManager.create<Puck>();
	m_gameManager.create<Player>();
}
