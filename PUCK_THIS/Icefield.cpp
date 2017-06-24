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

	// create two goals
	m_goal_a = &manager->create<Goal>();
	m_goal_b = &manager->create<Goal>();
	


	// set initial size
	resize(20.0f, 10.0f);

	printf("\nCreated an icefield.");
}


Icefield::~Icefield()
{
	// tell the gamemanager that the goals should be destroyed as well
	m_goal_a->destroyed = true;
	m_goal_b->destroyed = true;
	
	printf("\nDestroyed an icefield.");
}

void Icefield::draw(sf::RenderWindow & target)
{
	target.draw(m_shape);
}

void Icefield::update(float deltaTime)
{
}

void Icefield::setPosition(b2Vec2 pos)
{
	Entity::setPosition(pos);

	arrangeGoals(true);
}

void Icefield::arrangeGoals(bool bRepositionOnly)
{
	float goal_dist_to_border = m_size.x * 0.1f;
	float x_half = m_size.x * 0.5f;

	// set size of the goals 
	if (!bRepositionOnly)
	{
		float goal_length = m_size.y * 0.15f;
		m_goal_a->resize(goal_length * 0.5f, goal_length, 180.0f);
		m_goal_b->resize(goal_length * 0.5f, goal_length, 0.0f);
	}
	//position relative to icefield
	if (m_body)
	{
		b2Vec2 icepos = m_body->GetPosition();
		m_goal_a->setPosition(b2Vec2(icepos.x - x_half + goal_dist_to_border, icepos.y));
		m_goal_b->setPosition(b2Vec2(icepos.x + x_half - goal_dist_to_border, icepos.y));
	}
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

			m_size.x = x_meter;
			m_size.y = y_meter;

			arrangeGoals();
		}		
	}	
}
