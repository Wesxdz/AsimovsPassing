#pragma once

#include "slComponent.h"

enum Material {
	WOOD,
	METAL,
	RUBBER
};

class cBox : public slComponent
{
public:
	static cBox* CreateBox(float width, float height, Material m);
public:
	Material mat;
	b2Body* boxBody;
public:
	cBox();
	~cBox();
	// Inherited via slComponent
	virtual void Init() override;
	virtual bool Input(sf::Event * e) override;
	virtual void Update(float dt) override;
	virtual void Draw() override;
};

