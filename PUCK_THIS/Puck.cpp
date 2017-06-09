#include "Puck.h"
#include "GameManager.h"



Puck::Puck(b2World* world, GameManager* manager) : Entity(world, manager)
{
	// create draw circle shape //todo: radius
	m_circle.setFillColor(sf::Color::Green);
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
	fd.density = 2.0f;
	fd.friction = 0.0f;
	//fd.restitution = 0.5f;
	
	b2CircleShape circle;
	fd.shape = &circle;
	m_circlefixture = m_body->CreateFixture(&fd);
	m_body->SetLinearVelocity(b2Vec2(9.0f, 4.0f));
	
	// set radius
	setRadius(.5f);
	
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
	target.draw(m_circle);
}

void Puck::setRadius(float radius_meter)
{
	float radius_px = m_gameManager->convertToScreen(radius_meter);
	m_circle.setRadius(radius_px);
	if (m_transformable)
		m_transformable->setOrigin(radius_px, radius_px);
	
	if (m_circlefixture)
	{
		b2CircleShape* shape = static_cast<b2CircleShape*>(m_circlefixture->GetShape());
		if (shape)
			shape->m_radius = radius_meter;
	}	
}

float Puck::getRadius()
{
	if (m_circlefixture)
	{
		b2Shape* shape = m_circlefixture->GetShape();
		if (shape)
			return ((b2CircleShape*)shape)->m_radius;
	}
	return 0.0f;
}