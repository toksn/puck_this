#include "Puck.h"



Puck::Puck(b2World* world) : Entity(world)
{
	// create draw circle shape //todo: radius
	m_circle.setRadius(5.0f);
	m_circle.setFillColor(sf::Color::Green);
	m_circle.setPosition(10.0f, 5.0f);
	m_transformable = &m_circle;
	m_drawable = &m_circle;

	// create world space collision
	b2BodyDef bdef;
	bdef.linearDamping = 0.1;
	bdef.angularDamping = 0.1;
	bdef.linearVelocity.x = 2.0;
	bdef.linearVelocity.y = 1.0;
	bdef.position = b2Vec2(0.5, 0.5);
	bdef.type = b2_dynamicBody;
	m_body = world->CreateBody(&bdef);

	b2FixtureDef fd;
	fd.density = 2.0f;
	fd.friction = 0.01f;
	fd.restitution = 0.5f;
	b2CircleShape circle;
	circle.m_radius = 5.0f * 0.1f/*onePixelInMeter*/;
	fd.shape = &circle;
	m_body->CreateFixture(&fd);
	
	// pixel per second
	//m_vel = 200.0f;
	// TODO: this has to be normalized every time it is set
	//m_dir = sf::Vector2f(1.0f, 0.5f);

	printf("\nCreated a Puck");
}


Puck::~Puck()
{
	printf("\nDestroyed a Puck");
}

void Puck::update(float deltaTime)
{
	solveBoundCollisions();
}

void Puck::draw(sf::RenderWindow & target)
{
	if (m_body)
	{
		//setRadius();
		//setPosition(convertToScreenPos(m_body->GetPosition()));
		//target.draw(m_transformable);
	}
}

void Puck::solveBoundCollisions()
{
	
}
