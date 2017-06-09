#include "GameManager.h"
#include <algorithm>



GameManager::GameManager()
{
	b2Vec2 gravity;
	gravity.Set(0.0f, 0.0f);
	m_world = std::make_unique<b2World>(gravity);
	m_physicsTimer = 0.0f;
}


GameManager::~GameManager()
{
}

void GameManager::update(float deltaTime)
{
	// add physics timer in seconds
	m_physicsTimer += deltaTime/1000.0f;
	// do fixed physics steps until theres less than 16.666ms left
	while (m_physicsTimer >= PHYSICS_STEP)
	{
		m_world->Step(PHYSICS_STEP, 3, 4);
		m_physicsTimer -= PHYSICS_STEP;
	}

	for (auto& e : m_entities) e->update(deltaTime);
}

void GameManager::draw(sf::RenderWindow& target)
{
	for (auto& e : m_entities)
	{
		if (e->m_body && e->m_transformable)
		{
			b2Vec2 worldPos = e->m_body->GetPosition();
			sf::Vector2f screenPos = convertToScreen(worldPos);

			e->m_transformable->setPosition(screenPos);
			//target.draw(*e->m_drawable);
		}

		e->draw(target);
	}
}

// todo: make depending on window
constexpr float oneMeterInPixel = 10.0f;
constexpr float onePixelInMeter = 1.0f/ oneMeterInPixel;
sf::Vector2f GameManager::convertToScreen(b2Vec2 worldPos)
{
	return sf::Vector2f(worldPos.x * oneMeterInPixel, worldPos.y * oneMeterInPixel);
}
b2Vec2 GameManager::convertToWorld(sf::Vector2f screenPos)
{
	return b2Vec2(screenPos.x * onePixelInMeter, screenPos.y * onePixelInMeter);
}

float GameManager::convertToScreen(float worldSize)
{
	return worldSize*oneMeterInPixel;
}
float GameManager::convertToWorld(float screenSize)
{
	return screenSize*onePixelInMeter;
}

void GameManager::refresh()
{
	// delete raw pointers when marked as destroyed
	for (auto& pair : m_groupedEntities)
	{
		auto& vec(pair.second);
		vec.erase(std::remove_if(std::begin(vec), std::end(vec), [](auto ptr) {return ptr->destroyed; }), std::end(vec));
	}

	// delete unique pointer + element when marked as destroyed
	m_entities.erase(std::remove_if(std::begin(m_entities), std::end(m_entities), [](const auto& uptr) {return uptr->destroyed; }), std::end(m_entities));
}

void GameManager::clear()
{
	m_entities.clear();
	m_groupedEntities.clear();
}