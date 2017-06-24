#pragma once
#include <memory>
#include <map>
#include <vector>

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Puck.h"

// define fixed physics step
#define PHYSICS_STEP 0.01666666f


class GameManager
{
public:
	GameManager();
	~GameManager();

	template<typename T, typename... TArgs> inline T& create(TArgs&&... args)
	{
		//return T(std::forward<TArgs>(args));

		static_assert(std::is_base_of<Entity, T>::value, "'T' must be derived from 'Entity'");

		// create unique pointer by forwarding the given arguments + put it in the entities vector
		auto uPtr = std::make_unique<T>(m_world.get(), this, std::forward<TArgs>(args)...);
		auto ptr = uPtr.get();
		
		m_entities.emplace_back(std::move(uPtr));
		// create a hash entry for the typeid(T) and put the raw pointer in there
		m_groupedEntities[typeid(T).hash_code()].emplace_back(ptr);

		// return dereferenced raw pointer
		return *ptr;
	}

	template<typename T> inline T& create()
	{
		static_assert(std::is_base_of<Entity, T>::value, "'T' must be derived from 'Entity'");

		// create unique pointer by forwarding the given arguments + put it in the entities vector
		auto uPtr = std::make_unique<T>(m_world.get(), this);
		auto ptr = uPtr.get();
		
		m_entities.emplace_back(std::move(uPtr));
		//m_entities.emplace_back(std::make_unique<T>());		

		// create a hash entry for the typeid(T) and put the raw pointer in there
		m_groupedEntities[typeid(T).hash_code()].emplace_back(ptr);

		// return dereferenced raw pointer
		return *ptr;
	}

	template<typename T> auto& getAll()
	{
		return m_groupedEntities[typeid(T).hash_code()];
	}

	void update(float deltaTime);
	void draw(sf::RenderWindow & target);

	// converting methods
	sf::Vector2f convertToScreen(b2Vec2 worldPos);
	b2Vec2 convertToWorld(sf::Vector2f screenPos);
	float convertToScreen(float worldSize);
	float convertToWorld(float screenSize);

	void refresh();
	void clear();

private:
	std::vector<std::unique_ptr<Entity>> m_entities;
	std::map<std::size_t, std::vector<Entity*>> m_groupedEntities;
	std::unique_ptr<b2World> m_world;

	float m_physicsTimer;
};