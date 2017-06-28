#pragma once
#include "Entity.h"
#include "PolyLine.h"

class Goal :
	public Entity
{
public:
	Goal(b2World* world, EntityManager* manager);
	~Goal();

	// Inherited via Entity
	virtual void draw(sf::RenderWindow & target) override;
	virtual void update(float deltaTime) override;

	void resize(float x_meter, float y_meter, float angle);

private:
	
	PolyLine m_line;
	b2Fixture* m_fixture;
};

