#pragma once
#include "EntityManager.h"

// define fixed physics step
#define PHYSICS_STEP 0.01666666f

class GameManager : public EntityManager
{
public:
	GameManager(b2World* world);
	~GameManager();

	virtual void update(float deltaTime) override;
	//virtual void draw(sf::RenderWindow & target) override;

	//virtual void refresh() override;
	//virtual void clear() override;

private:
	float m_physicsTimer;
};