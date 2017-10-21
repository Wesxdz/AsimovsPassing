#pragma once

#include "slComponent.h"

class cCamera : public slComponent
{
public:
	sf::View view;
public:
	cCamera();
	~cCamera();

	// Inherited via slComponent
	virtual void Init() override;
	virtual bool Input(sf::Event * e) override;
	virtual void Update(float dt) override;
	virtual void Draw() override;
};

