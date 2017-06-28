#include "CircleColEntity.h"
#include "EntityManager.h"

CircleColEntity::CircleColEntity(b2World* world, EntityManager* manager) : Entity(world, manager)
{
	// create draw circle shape //todo: radius
	m_transformable = &m_circle;
	m_drawable = &m_circle;

	// create world space collision
	b2BodyDef bdef;
	bdef.position = b2Vec2(0.0f, 0.0f);
	bdef.type = b2_dynamicBody;
	m_body = world->CreateBody(&bdef);
	
	b2FixtureDef fd;
	b2CircleShape circle;
	fd.shape = &circle;
	m_circlefixture = m_body->CreateFixture(&fd);

	// set radius
	setRadius(1.0f);
}


CircleColEntity::~CircleColEntity()
{
}

void CircleColEntity::draw(sf::RenderWindow & target)
{
	Entity::draw(target);
}

void CircleColEntity::update(float deltaTime)
{
}

void CircleColEntity::setRadius(float radius_meter)
{
	float radius_px = m_manager->convertToScreen(radius_meter);
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

float CircleColEntity::getRadius()
{
	if (m_circlefixture)
	{
		b2CircleShape* shape = static_cast<b2CircleShape*>(m_circlefixture->GetShape());
		if (shape)
			return shape->m_radius;
	}
	return 0.0f;
}