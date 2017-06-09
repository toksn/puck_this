#include "Puck.h"



Puck::Puck(b2World* world) : Entity(world)
{
	// create draw circle shape //todo: radius
	m_circle.setRadius(5.0f);
	m_circle.setFillColor(sf::Color::Green);
	//m_circle.setPosition(10.0f, 5.0f);
	m_circle.setOrigin(sf::Vector2f(2.5f, 2.5f));
	m_transformable = &m_circle;
	m_drawable = &m_circle;

	// create world space collision
	b2BodyDef bdef;
	bdef.linearDamping = 0.0f;
	bdef.angularDamping = 0.0f;
	//bdef.linearVelocity.x = 50.0f;
	//bdef.linearVelocity.y = 3.5f;
	// pos half of the window
	bdef.position = b2Vec2(30.0f, 15.0f);
	bdef.type = b2_dynamicBody;
	bdef.allowSleep = false;
	m_body = world->CreateBody(&bdef);

	b2FixtureDef fd;
	fd.density = 20.0f;
	fd.friction = 0.0f;

	//fd.friction = 0.0f;
	//fd.restitution = 5.0f;
	
	b2CircleShape circle;
	circle.m_radius = 5.0f * 0.1f/*onePixelInMeter*/;
	//circle.m_p = b2Vec2(10.0f, 0.0f);
	fd.shape = &circle;
	m_body->CreateFixture(&fd);
	m_body->SetLinearVelocity(b2Vec2(90.0f, 40.0f));
	
	//m_body->ApplyForce(b2Vec2(0.04f, 0.09f), m_body->GetPosition(),true);
	//m_body->ApplyForce(b2Vec2(400.0f, 90.0f), m_body->GetPosition(), true);
	
	// pixel per second
	//m_vel = 200.0f;
	// TODO: this has to be normalized every time it is set
	//m_dir = sf::Vector2f(1.0f, 0.5f);

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
