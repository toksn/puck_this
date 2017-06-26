#include "Goal.h"
#include "EntityManager.h"

Goal::Goal(b2World* world, EntityManager* manager) : Entity(world, manager)
{
	m_fixture = NULL;

	// create drawing shape
	m_transformable = &m_line;
	m_drawable = &m_line;

	// create world space collision
	b2BodyDef bdef;
	bdef.position = b2Vec2(15.0f, 7.5f);
	bdef.type = b2_staticBody;
	m_body = world->CreateBody(&bdef);

	// set initial size
	resize(0.5f, 1.0f, 0.0f);

	printf("\nCreated an Goal.");
}


Goal::~Goal()
{
	//if (m_world && m_body)
	//	m_world->DestroyBody(m_body);

	printf("\nDestroyed an Goal.");
}

void Goal::draw(sf::RenderWindow & target)
{
	Entity::draw(target);

	target.draw(m_line);
}

void Goal::update(float deltaTime)
{
}

void Goal::resize(float x_meter, float y_meter, float angle)
{
	// update collision shape
	//if (m_fixture)
	{
		//b2ChainShape* shape = static_cast<b2ChainShape*>(m_fixture->GetShape());
		//if (m_shapeChain)
		{
			//float x_half = x_meter *0.5f;
			float y_half = y_meter *0.5f;
			b2Vec2 boundaries[4];
			boundaries[0] = b2Vec2(0.0f, -y_half);
			boundaries[1] = b2Vec2(x_meter, -y_half);
			boundaries[2] = b2Vec2(x_meter, y_half);
			boundaries[3] = b2Vec2(0.0f, y_half);

			b2ChainShape box;
			b2FixtureDef fd;
			fd.density = 0.0f;
			fd.friction = 0.0f;
			fd.restitution = 1.0f;
			fd.shape = &box;
			box.CreateChain(boundaries, 4);

			// TODO: somehow circleshape doesnt update the whole thing when edited
			// destroy old fixture, create new one 
			if (m_fixture)
				m_body->DestroyFixture(m_fixture);
			m_fixture = m_body->CreateFixture(&fd);

			float angle_rad = angle * b2_pi / 180.0f;
			m_body->SetTransform(m_body->GetPosition(), angle_rad);


			// update drawing shape
			sf::Vector2f size_px = m_manager->convertToScreen(b2Vec2(x_meter, y_meter));
			size_px.y *= 0.5f;

			m_line.m_vertices.clear();
			m_line.m_vertices.append(sf::Vertex(sf::Vector2f(0.0f, -size_px.y)));
			m_line.m_vertices.append(sf::Vertex(sf::Vector2f(size_px.x, -size_px.y)));
			m_line.m_vertices.append(sf::Vertex(sf::Vector2f(size_px.x, size_px.y)));
			m_line.m_vertices.append(sf::Vertex(sf::Vector2f(0.0f, size_px.y)));
			
			//m_line.setRotation(0.0f);
		}
	}
}
