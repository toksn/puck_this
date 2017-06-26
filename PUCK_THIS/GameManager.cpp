#include "GameManager.h"
#include <algorithm>



GameManager::GameManager(b2World* world) : EntityManager(world)
{
	m_physicsTimer = 0.0f;
}


GameManager::~GameManager()
{
}

void GameManager::update(float deltaTime)
{
	// add physics timer in seconds
	m_physicsTimer += deltaTime;
	// do fixed physics steps until theres less than 16.666ms left
	while (m_physicsTimer >= PHYSICS_STEP)
	{
		m_world->Step(PHYSICS_STEP, 3, 4);

		for (auto& e : m_entities) e->update(PHYSICS_STEP);

		m_physicsTimer -= PHYSICS_STEP;
	}

	
}
/*
void GameManager::draw(sf::RenderWindow& target)
{
	EntityManager::draw(target);
}*/