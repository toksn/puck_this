//#include "Windows.h"
//#include <thread>
//#include <chrono>

#include "Game.h"
#include "Puck.h"
#include "Icefield.h"
#include "Player.h"

Game::Game()
{
	m_frameClock = std::make_unique<sf::Clock>();
	m_bPrintFPS = true;

	setMaxFPS(100);
}


Game::~Game()
{
}

void Game::update()
{
	// check for elapsed time and restart clock for next cycle
	float deltaTime = (*m_frameClock).restart().asSeconds();
	float curFPS = 1.0f / deltaTime;

	m_gameManager.refresh();
	m_gameManager.update(deltaTime);
	
	// add render timer in seconds
	m_renderTimer += deltaTime;
	// do fixed render steps until theres less than desired timeframe left
	if(m_renderTimer >= m_renderStep)
	{
		if (m_window)
		{
			if (m_bPrintFPS)
				printf("\nFPS: %f", 1.0f / m_renderTimer);

			m_window->clear();
			m_gameManager.draw(*m_window);
			m_window->display();
		}

		if (m_renderStep == 0.0f)
			m_renderTimer = 0.0f;
		else
		{
			while(m_renderTimer>m_renderStep)
				m_renderTimer -= m_renderStep;
		}
	}

	//SleepEx(1, TRUE);
	//constexpr std::chrono::milliseconds dur(1);
	//std::this_thread::sleep_for(dur);
	//std::this_thread::yield();
}

void Game::setMaxFPS(uint16 maxFPS)
{
	if (maxFPS == 0)
		m_renderStep = 0.0f;
	else
	{
		m_maxFPS = maxFPS;
		m_renderStep = 1.0f / m_maxFPS;
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
