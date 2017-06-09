#include "Icefield.h"
#include "GameManager.h"



Icefield::Icefield(b2World* world, GameManager* manager) : Entity(world, manager)
{
	// create drawing shape //todo: radius
	m_shape.setFillColor(sf::Color::Transparent);
	m_shape.setOutlineColor(sf::Color::White);
	m_shape.setOutlineThickness(1.0f);
	//m_shape.setSize(sf::Vector2f(400.0f, 200.f));
	//m_shape.setOrigin(sf::Vector2f(200.0f, 100.f));
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
	
	
	float pixInMeter = 0.1f;
	
	
	b2ChainShape box;
	fd.shape = &box;
	m_shapeChain = &box;
	resize(40.0f, 20.0f);
	m_body->CreateFixture(&fd);

	

	printf("\nCreated an icefield.");
}


Icefield::~Icefield()
{
	//if (m_world && m_body)
	//	m_world->DestroyBody(m_body);
	
	printf("\nDestroyed an icefield.");
}

void Icefield::draw(sf::RenderWindow & target)
{
	target.draw(m_shape);
}

void Icefield::update(float deltaTime)
{
}

void Icefield::resize(float x_meter, float y_meter)
{
	// update drawing shape
	sf::Vector2f size_px = m_gameManager->convertToScreen(b2Vec2(x_meter, y_meter));
	m_shape.setSize(size_px);
	m_shape.setOrigin(size_px*0.5f);

	// update collision shape
	float x_half = x_meter *0.5f;
	float y_half = y_meter *0.5f;
	b2Vec2 boundaries[4];
	boundaries[0] = b2Vec2(-x_half, -y_half);
	boundaries[1] = b2Vec2(-x_half, y_half);
	boundaries[2] = b2Vec2(x_half, y_half);
	boundaries[3] = b2Vec2(x_half, -y_half);
	m_shapeChain->CreateLoop(boundaries, 4);
}
