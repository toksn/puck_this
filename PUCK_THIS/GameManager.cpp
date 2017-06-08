#include "GameManager.h"
#include <algorithm>



GameManager::GameManager()
{
	b2Vec2 gravity;
	gravity.Set(0.0f, 0.0f);
	m_world = std::make_unique<b2World>(gravity);
}


GameManager::~GameManager()
{
}

void GameManager::update(float deltaTime)
{
	m_world->Step(deltaTime, 3, 4);

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
			target.draw(*e->m_drawable);
		}
		//e->draw(target);		
	}
}

constexpr float oneMeterInPixel = 10.0f;
constexpr float onePixelInMeter = 0.1f;
sf::Vector2f GameManager::convertToScreen(b2Vec2 worldPos)
{
	return sf::Vector2f(worldPos.x * oneMeterInPixel, worldPos.y * oneMeterInPixel);
}
b2Vec2 GameManager::convertToWorld(sf::Vector2f screenPos)
{
	return b2Vec2(screenPos.x * onePixelInMeter, screenPos.y * onePixelInMeter);
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