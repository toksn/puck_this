#pragma once
#include <SFML\Graphics.hpp>
#include "Box2D\Box2D.h"

class Entity
{
public:
	Entity(b2World* world) {
		m_world = world;
		m_body = NULL;
	}
	virtual ~Entity() {}
	virtual void draw(sf::RenderWindow& mTarget) = 0;
	virtual void update(float deltaTime) = 0;

	bool destroyed = false;
	b2Body* m_body;
	b2World* m_world;
	sf::Transformable* m_transformable;
	sf::Drawable* m_drawable;
};

