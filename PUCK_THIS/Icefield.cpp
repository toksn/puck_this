#include "Icefield.h"



Icefield::Icefield(b2World* world) : Entity(world)
{
	// create drawing shape //todo: radius
	m_shape.setFillColor(sf::Color::Transparent);
	m_shape.setOutlineColor(sf::Color::White);
	m_shape.setOutlineThickness(1.0f);
	m_shape.setSize(sf::Vector2f(400.0f, 200.f));
	m_shape.setOrigin(sf::Vector2f(200.0f, 100.f));
	m_transformable = &m_shape;
	m_drawable = &m_shape;

	// create world space collision
	b2BodyDef bdef;
	bdef.position = b2Vec2(30.0f, 15.0f);
	bdef.type = b2_staticBody;
	m_body = world->CreateBody(&bdef);

	b2FixtureDef fd;
	fd.density = 0.0f;
	fd.friction = 0.0f;
	fd.restitution = 1.0f;
	
	b2Vec2 boundaries[4];
	float pixInMeter = 0.1f;
	boundaries[0] = b2Vec2(-200.0f, -100.0f);
	boundaries[1] = b2Vec2(-200.0f, 100.0f);
	boundaries[2] = b2Vec2(200.0f, 100.0f);
	boundaries[3] = b2Vec2(200.0f, -100.0f);
	boundaries[0] *= pixInMeter;
	boundaries[1] *= pixInMeter;
	boundaries[2] *= pixInMeter;
	boundaries[3] *= pixInMeter;
	
	b2ChainShape box;
	box.CreateLoop(boundaries, 4);
	fd.shape = &box;
	m_body->CreateFixture(&fd);

	printf("\nCreated an icefield.");
}


Icefield::~Icefield()
{
	//if (m_world && m_body)
	//	m_world->DestroyBody(m_body);
	
	printf("\nDestroyed an icefield.");
}

void Icefield::draw(sf::RenderWindow & mTarget)
{
	
}

void Icefield::update(float deltaTime)
{
}
