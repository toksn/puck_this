#pragma once
#include "Entity.h"
#include <SFML\Graphics.hpp>
class Puck :
	public Entity
{
public:
	Puck(b2World* world, GameManager* manager);
	~Puck();

	void update(float deltaTime) override;
	void draw(sf::RenderWindow& target) override;

	// radius in meter
	void setRadius(float radius_meter);
	float getRadius();
private:
	b2Fixture* m_circlefixture;
	sf::CircleShape m_circle;
};

