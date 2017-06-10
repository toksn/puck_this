#include "Entity.h"
//#include "GameManager.h"

Entity::Entity(b2World * world, GameManager * man)
{
	m_world = world;
	m_body = NULL;
	m_gameManager = man;
}

Entity::~Entity()
{
}

void Entity::setPosition(b2Vec2 pos)
{
	if(m_body)
		m_body->SetTransform(pos, m_body->GetAngle());
}
