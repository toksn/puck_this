#include "Icefield.h"
#include "GameManager.h"



Icefield::Icefield(b2World* world, GameManager* manager) : Entity(world, manager)
{
	m_fixture = NULL;

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
	bdef.position = b2Vec2(15.0f, 7.5f);
	bdef.type = b2_staticBody;
	m_body = world->CreateBody(&bdef);

	// set initial size
	resize(20.0f, 10.0f);

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
	// update collision shape
	//if (m_fixture)
	{
		//b2ChainShape* shape = static_cast<b2ChainShape*>(m_fixture->GetShape());
		//if (m_shapeChain)
		{
			float x_half = x_meter *0.5f;
			float y_half = y_meter *0.5f;
			b2Vec2 boundaries[4];
			boundaries[0] = b2Vec2(-x_half, -y_half);
			boundaries[1] = b2Vec2(-x_half, y_half);
			boundaries[2] = b2Vec2(x_half, y_half);
			boundaries[3] = b2Vec2(x_half, -y_half);
			
			b2ChainShape box;
			b2FixtureDef fd;
			fd.density = 0.0f;
			fd.friction = 0.0f;
			fd.restitution = 1.0f;
			fd.shape = &box;
			box.CreateLoop(boundaries, 4);

			// TODO: somehow circleshape doesnt update the whole thing when edited
			// destroy old fixture, create new one 
			if(m_fixture)
				m_body->DestroyFixture(m_fixture);
			m_fixture = m_body->CreateFixture(&fd);
			
			// update drawing shape
			sf::Vector2f size_px = m_gameManager->convertToScreen(b2Vec2(x_meter, y_meter));
			m_shape.setSize(size_px);
			m_shape.setOrigin(size_px*0.5f);
		}		
	}	
}
