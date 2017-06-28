#pragma once
#include <SFML\Graphics.hpp>
#include "Box2D\Box2D.h"

class EntityManager;

class Entity
{
public:
	Entity(b2World* world, EntityManager* man);
	virtual ~Entity();
	virtual void draw(sf::RenderWindow& target);
	virtual void update(float deltaTime) = 0;

	virtual void setTransform(b2Vec2 pos, float angle);
	virtual void setPosition(b2Vec2 pos);
	virtual void setAngle(float angle);	

	bool destroyed = false;
	b2Body* m_body;
	b2World* m_world;
	EntityManager* m_manager;
	sf::Transformable* m_transformable;
	sf::Drawable* m_drawable;
};

