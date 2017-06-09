#pragma once
#include "Entity.h"
class Icefield :
	public Entity
{
public:
	Icefield(b2World* world, GameManager* manager);
	~Icefield();

	// Inherited via Entity
	virtual void draw(sf::RenderWindow & target) override;
	virtual void update(float deltaTime) override;

	void resize(float x_meter, float y_meter);

private:
	sf::RectangleShape m_shape;
	b2Fixture* m_fixture;
};

