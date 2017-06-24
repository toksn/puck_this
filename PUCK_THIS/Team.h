#pragma once
#include "Entity.h"
#include "Player.h"
#include "GameManager.h"
class Team : public Entity
{
public:
	//Team(b2World * world, GameManager * manager);
	Team(b2World* world, GameManager * manager, std::string name, bool isTeamA, int numberOfPlayers = 1);
	~Team();

	// Inherited via Entity
	virtual void draw(sf::RenderWindow & target) override;
	virtual void update(float deltaTime) override;

private:
	std::string m_teamName;
	uint16 m_score;
	std::vector<Player*> m_teamPlayers;
	bool bIsTeamA;	
};

