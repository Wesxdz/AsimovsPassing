#include "cCamera.h"



cCamera::cCamera()
{
}

cCamera::~cCamera()
{
}

void cCamera::Init()
{
	Reg(slRegister::UPDATE);
	auto windowSize = slGame::inst.window->getSize();
	view.setSize(windowSize.x, windowSize.y);
	view.setCenter(windowSize.x/2, windowSize.y/2);
	slGame::inst.window->setView(view);
}

bool cCamera::Input(sf::Event * e)
{
	return false;
}

void cCamera::Update(float dt)
{
	// Reset view after making changes
	//slGame::inst.window->setView(view);
}

void cCamera::Draw()
{
}
