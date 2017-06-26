#pragma once
#include "CircleColEntity.h"

class Puck :
	public CircleColEntity
{
public:
	Puck(b2World* world, EntityManager* manager);
	~Puck();

	void update(float deltaTime) override;
	void draw(sf::RenderWindow& target) override;
};

