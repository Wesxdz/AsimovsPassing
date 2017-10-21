#include "cBox.h"

cBox* cBox::CreateBox(float width, float height, Material m)
{
	b2BodyDef boxDef;
	boxDef.type = b2_dynamicBody;
	b2Body* bBody = slGame::inst.world.CreateBody(&boxDef);
	b2PolygonShape boxShape;
	boxShape.SetAsBox(width / 2, height / 2);
	b2FixtureDef fixDef;
	switch (m) {
	case METAL:
		fixDef.density = 100.0f;
		fixDef.friction = 0.5f;
		break;
	case WOOD:
		fixDef.density = 5.0f;
		fixDef.friction = 0.8f;
		break;
	case RUBBER:
		fixDef.density = 20.0f;
		fixDef.friction = 0.5f;
		fixDef.restitution = 0.9f;
	}
	fixDef.shape = &boxShape;
	bBody->CreateFixture(&fixDef);
	cBox* boxComponent = new cBox;
	boxComponent->mat = m;
	boxComponent->boxBody = bBody;
	return boxComponent;
}

cBox::cBox()
{
}

cBox::~cBox()
{
}

void cBox::Init()
{
}

bool cBox::Input(sf::Event * e)
{
	return false;
}

void cBox::Update(float dt)
{
}

void cBox::Draw()
{
}
