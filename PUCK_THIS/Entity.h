#pragma once
#include <SFML\Graphics.hpp>
#include "Box2D\Box2D.h"

//#include "GameManager.h"
class GameManager;

class Entity
{
public:
	Entity(b2World* world, GameManager* man) {
		m_world = world;
		m_body = NULL;
		m_gameManager = man;
	}
	virtual ~Entity() {
	}
	virtual void draw(sf::RenderWindow& target) = 0;
	virtual void update(float deltaTime) = 0;

	bool destroyed = false;
	b2Body* m_body;
	b2World* m_world;
	GameManager* m_gameManager;
	sf::Transformable* m_transformable;
	sf::Drawable* m_drawable;
};

