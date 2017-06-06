#pragma once
#include <SFML\Graphics.hpp>

class Entity
{
public:
	//Entity();
	virtual ~Entity() {}
	virtual void draw(sf::RenderWindow& mTarget) {};
	virtual void update(float deltaTime) {};

	bool destroyed = false;
};

