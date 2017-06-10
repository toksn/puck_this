#pragma once
#include "Entity.h"
class CircleColEntity :
	public Entity
{
public:
	CircleColEntity(b2World* world, GameManager* manager);
	~CircleColEntity();

	// Inherited via Entity
	virtual void draw(sf::RenderWindow & target) override;
	virtual void update(float deltaTime) override;

	// radius in meter
	virtual void setRadius(float radius_meter);
	virtual float getRadius();

protected:
	b2Fixture* m_circlefixture;
	sf::CircleShape m_circle;
};

