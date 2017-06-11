#pragma once
#include "CircleColEntity.h"

/*TODO:
- moving the player (by own velo to simulate ice)
- actual control sheme (keyboard only? mouse + keyboard?)
- find physics body properties
- shoot

- pass
*/

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

	b2Vec2 m_vel;
	float m_accel;
	float m_maxSpeed;
	float m_damping;
};