#include "Player.h"
#include "GameManager.h"

Player::Player(b2World* world, GameManager* manager) : CircleColEntity(world, manager)
{
	// virtual circle size
	m_virtualCircleSize = 2.0f;
	m_fitFactor = 1.0f;

	m_circle.setFillColor(sf::Color::Transparent);
	m_circle.setOutlineColor(sf::Color::Red);
	m_circle.setOutlineThickness(2.0f);
	m_circle.setScale(1.0f, 0.66f);

	// create player rectangle (todo: make it a sprite)
	m_playerRect.setFillColor(sf::Color(0, 20, -1, 160));

	// fixture settings
	m_circlefixture->SetDensity(80.0f);
	m_circlefixture->SetFriction(0.5f);
	//m_circlefixture->SetRestitution(1.0f);

	// body settings
	m_body->SetLinearDamping(0.0f);
	m_body->SetAngularDamping(0.0f);
	m_body->SetType(b2_staticBody);
	//m_body->SetType(b2_dynamicBody);

	// set position
	m_body->SetTransform(b2Vec2(16.0f, 7.5f), 0.0f);
	// set radius
	setPlayerHeight(2.0f);

	// 10 meter per second = 36km/h
	m_accel = 0.1f;
	// max speed 10 meter per second
	m_maxSpeed = 10.0f;
	m_damping = 0.01f;
	
	printf("\nCreated a Player");
}


Player::~Player()
{
	//if (m_world && m_body)
	//	m_world->DestroyBody(m_body);

	printf("\nDestroyed a Player");
}

void Player::update(float deltaTime)
{
	float curAccel = m_accel * deltaTime;
	float curDamp = m_damping * deltaTime;

	// accelerating
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_vel.y -= curAccel;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_vel.y += curAccel;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		m_vel.x -= curAccel;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		m_vel.x += curAccel;


	//damping
	if (abs(m_vel.x) < curDamp)
		m_vel.x = 0.0f;
	else if (m_vel.x > 0.0f)
		m_vel.x -= curDamp;
	else
		m_vel.x += curDamp;

	if (abs(m_vel.y) < curDamp)
		m_vel.y = 0.0f;
	else if (m_vel.y > 0.0f)
		m_vel.y -= curDamp;
	else
		m_vel.y += curDamp;


	// limit at max speed
	if (m_vel.Length() > m_maxSpeed)
	{
		m_vel.Normalize();
		m_vel *= m_maxSpeed;
	}

	// set new pos
	m_body->SetTransform(m_body->GetPosition() + m_vel, m_body->GetAngle());
}

void Player::setRadius(float radius_meter)
{
	float height = radius_meter * 4.0f * m_fitFactor;
	// use set height method because fitfactor is used in there
	setPlayerHeight(height);
}

//
void Player::setPlayerHeight(float height_meter)
{
	// player has m_fitFactor to determine the width from the height
	float height_px = m_gameManager->convertToScreen(height_meter);
	float width_px = height_px * 0.5f / m_fitFactor;
	float radius_px = width_px * 0.5f;
	
	// player rect size + position
	m_playerRect.setSize(sf::Vector2f(width_px, height_px));
	// move down rect by radius * 0.75 to aprox. visualize the hitting zone at the bottom of the rect
	float originAdjust = radius_px*0.75f;//todo: better word than adjust?
	m_playerRect.setOrigin(sf::Vector2f(radius_px, height_px-originAdjust)); 

	// circle size
	float collision_radius = height_px * 0.25f * m_virtualCircleSize;
	m_circle.setRadius(collision_radius);
	if (m_transformable)
		m_transformable->setOrigin(collision_radius, collision_radius-originAdjust);

	// collision circle has actual radius (without size multiplier)
	if (m_circlefixture)
	{
		b2CircleShape* shape = static_cast<b2CircleShape*>(m_circlefixture->GetShape());
		if (shape)
			shape->m_radius = height_meter * 0.25f / m_fitFactor;
	}
}

void Player::draw(sf::RenderWindow & target)
{
	target.draw(m_circle);

	// update rectangle position
	m_playerRect.setPosition(m_circle.getPosition());
	target.draw(m_playerRect);
}