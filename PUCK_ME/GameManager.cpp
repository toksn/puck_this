#include "GameManager.h"
#include <algorithm>



GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::update(float deltaTime)
{
	for (auto& e : m_entities) e->update(deltaTime);
}

void GameManager::draw(sf::RenderWindow& target)
{
	for (auto& e : m_entities) e->draw(target);
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