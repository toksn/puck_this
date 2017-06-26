#include "Puck.h"

Puck::Puck(b2World* world, GameManager* manager) : CircleColEntity(world, manager)
{
	m_circle.setFillColor(sf::Color::Green);

	// fixture settings
	m_circlefixture->SetDensity(0.6f);
	m_circlefixture->SetFriction(0.0f);

	// body settings
	m_body->SetLinearDamping(0.0f);
	m_body->SetAngularDamping(0.0f);
	m_body->SetSleepingAllowed(false);
	m_body->SetType(b2_dynamicBody);
	
	// set position
	m_body->SetTransform(b2Vec2(10.0f, 7.5f), 0.0f);
	// set radius
	setRadius(.3f);
	// initial velo
	m_body->SetLinearVelocity(b2Vec2(9.0f, 4.0f));
	
	printf("\nCreated a Puck");
}


Puck::~Puck()
{
	//if (m_world && m_body)
	//	m_world->DestroyBody(m_body);

	printf("\nDestroyed a Puck");
}

void Puck::update(float deltaTime)
{
}

void Puck::draw(sf::RenderWindow & target)
{
	Entity::draw(target);

	target.draw(m_circle);
}