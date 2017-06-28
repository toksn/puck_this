#pragma once
#include "EntityManager.h"
class GuiManager :
	public EntityManager
{
public:
	GuiManager(b2World* world);
	~GuiManager();

	// Inherited via EntityManager
	virtual void update(float deltaTime) override;
};

