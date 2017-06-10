#pragma once
#include "CircleColEntity.h"

class Player :
	public CircleColEntity
{
public:
	Player(b2World* world, GameManager* manager);
	~Player();

	// Inherited via Entity
	virtual void draw(sf::RenderWindow & target) override;
	virtual void update(float deltaTime) override;

	// radius in meter
	virtual void setRadius(float radius_meter) override;

	void setPlayerHeight(float height_meter);

protected:
	sf::RectangleShape m_playerRect;
	float m_virtualCircleSize;
	float m_fitFactor;
};