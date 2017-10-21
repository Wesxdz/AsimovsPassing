#include "cGround.h"

void cGround::Init()
{
	b2BodyDef floorDef;
	floorDef.type = b2_staticBody;
	floorBody = slGame::inst.world.CreateBody(&floorDef);
	b2EdgeShape floorEdge;
	floorEdge.Set({ 0.0f, slGame::inst.WindowSize().y }, { slGame::inst.WindowSize().x, slGame::inst.WindowSize().y });
	b2FixtureDef floorFixDef;
	floorFixDef.friction = 0.9f;
	floorFixDef.shape = &floorEdge;
	floorBody->CreateFixture(&floorFixDef);

	floorEdge.Set({ 0, 0 }, { 0, slGame::inst.WindowSize().y });
	floorBody->CreateFixture(&floorFixDef);

	floorEdge.Set({ slGame::inst.WindowSize().x, 0 }, { slGame::inst.WindowSize().x, slGame::inst.WindowSize().y });
	floorBody->CreateFixture(&floorFixDef);

	// Elevator tube?
	floorEdge.Set({ 23.0f, 0 }, { 23.0f, slGame::inst.WindowSize().y - 2.0f });
	floorBody->CreateFixture(&floorFixDef);

	b2Vec2 vs[4];
	vs[0].Set(0.0f, slGame::inst.WindowSize().y);
	vs[1].Set(10.0f, slGame::inst.WindowSize().y - 4.0f);
	vs[2].Set(12.0f, slGame::inst.WindowSize().y - 1.0f);
	vs[3].Set(15.0f, slGame::inst.WindowSize().y);

	b2ChainShape chain;
	chain.CreateChain(vs, 4);

	floorFixDef.shape = &chain;
	floorBody->CreateFixture(&floorFixDef);
}

bool cGround::Input(sf::Event * e)
{
	return false;
}

void cGround::Update(float dt)
{
}

void cGround::Draw()
{
}
