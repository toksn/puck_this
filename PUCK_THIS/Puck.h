#pragma once
#include "CircleColEntity.h"

class Puck :
	public CircleColEntity
{
public:
	Puck(b2World* world, GameManager* manager);
	~Puck();

	void update(float deltaTime) override;
	void draw(sf::RenderWindow& target) override;
};

