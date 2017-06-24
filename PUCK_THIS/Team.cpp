#include "Team.h"

Team::Team(b2World* world, GameManager * manager, std::string name, bool isTeamA, int numberOfPlayers) : Entity(world, manager)
{
	m_score = 0;
	m_teamName = name;
	bIsTeamA = isTeamA;

	if (numberOfPlayers && manager)
	{
		// create players
		for (int i = 0; i < numberOfPlayers; i++)
		{
			Player player = manager->create<Player>();
			m_teamPlayers.emplace_back(&player);
		}
	}

	printf("\nCreated team: %s", m_teamName.c_str());
}

Team::~Team()
{
	for(auto player : m_teamPlayers)
		// tell the gamemanager that the players should be destroyed as well
		player->destroyed = true;

	printf("\nDestroyed team: %s", m_teamName.c_str());
}

void Team::draw(sf::RenderWindow & target)
{
}

void Team::update(float deltaTime)
{
}
