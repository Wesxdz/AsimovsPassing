#pragma once

#include "slComponent.h"

class cBreakable : public slComponent
{

public:
	b2Body* body;

public:
	cBreakable();
	~cBreakable();

	// Inherited via slComponent
	virtual void Init() override;
	virtual bool Input(sf::Event * e) override;
	virtual void Update(float dt) override;
	virtual void Draw() override;

};

