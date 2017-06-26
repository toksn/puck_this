#pragma once
#include "Entity.h"
#include "Goal.h"

class Icefield :
	public Entity
{
public:
	Icefield(b2World* world, EntityManager* manager);
	~Icefield();

	// Inherited via Entity
	virtual void draw(sf::RenderWindow & target) override;
	virtual void update(float deltaTime) override;

	virtual void setPosition(b2Vec2 pos) override;

	

	void resize(float x_meter, float y_meter);

private:
	sf::RectangleShape m_shape;
	b2Fixture* m_fixture;
	Goal* m_goal_a;
	Goal* m_goal_b;

	b2Vec2 m_size;

	void arrangeGoals(bool bRepositionOnly = false);
};

