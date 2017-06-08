#pragma once
#include "Entity.h"
class Icefield :
	public Entity
{
public:
	Icefield(b2World* world);
	~Icefield();

	// Inherited via Entity
	virtual void draw(sf::RenderWindow & mTarget) override;
	virtual void update(float deltaTime) override;

private:
	sf::RectangleShape m_shape;
};

