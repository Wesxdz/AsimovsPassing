#pragma once

#include "slComponent.h"

class cGround : public slComponent
{
public:
	b2Body* floorBody;
public:
	// Inherited via slComponent
	virtual void Init() override;
	virtual bool Input(sf::Event * e) override;
	virtual void Update(float dt) override;
	virtual void Draw() override;
};

