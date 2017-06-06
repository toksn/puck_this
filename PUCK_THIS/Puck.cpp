#include "Puck.h"



Puck::Puck()
{
	setRadius(5.0f);
	setFillColor(sf::Color::Green);
	setPosition(10.0f, 5.0f);
	m_vel = 25.0f;
	m_dir = sf::Vector2f(1.0f, 0.5f);

	printf("\nCreated a Puck");
}


Puck::~Puck()
{
	printf("\nDestroyed a Puck");
}

void Puck::update(float deltaTime)
{
	sf::Transformable::move(sf::Vector2f(m_dir.x * m_vel * deltaTime / 1000.0f, m_dir.y * m_vel * deltaTime / 1000.0f));

	solveBoundCollisions();
}

void Puck::draw(sf::RenderWindow & target)
{
	target.draw(*this);
}

void Puck::solveBoundCollisions()
{
	auto pos = getPosition();

	// reflect at them walls
	if (pos.x < 0 || pos.x > 100)
		m_dir.x *= -1.0;
	if (pos.y < 0 || pos.y > 100)
		m_dir.y *= -1.0;
}
