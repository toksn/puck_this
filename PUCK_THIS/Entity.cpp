#include "Entity.h"
#include "GameManager.h"

Entity::Entity(b2World * world, GameManager * man)
{
	m_world = world;
	m_body = NULL;
	m_gameManager = man;
}

Entity::~Entity()
{
}

void Entity::draw(sf::RenderWindow & target)
{
	if (m_gameManager && m_body && m_transformable)
	{
		b2Vec2 worldPos = m_body->GetPosition();
		sf::Vector2f screenPos = m_gameManager->convertToScreen(worldPos);

		m_transformable->setPosition(screenPos);
		//float angle = angle_rad * 180.0f / b2_pi;
		m_transformable->setRotation(m_body->GetAngle() * 180.0f / b2_pi);
	}
}

void Entity::setPosition(b2Vec2 pos)
{
	if(m_body)
		m_body->SetTransform(pos, m_body->GetAngle());
}

void Entity::setAngle(float angle)
{
	if (m_body)
		m_body->SetTransform(m_body->GetPosition(), angle);
}

void Entity::setTransform(b2Vec2 pos, float angle)
{
	if (m_body)
		m_body->SetTransform(pos, angle);
}
