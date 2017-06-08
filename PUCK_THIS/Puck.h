#pragma once
#include "Entity.h"
#include <SFML\Graphics.hpp>
class Puck :
	public Entity
{
public:
	Puck(b2World* world);
	~Puck();

	void update(float deltaTime) override;
	void draw(sf::RenderWindow& target) override;

	sf::Vector2f m_dir;
	float m_vel;

private:
	void solveBoundCollisions();
	sf::CircleShape m_circle;
};

