#include "Playbed.h"

#include "cBox.h"
#include "cBreakable.h"
#include "cCamera.h"
#include "cGround.h"
#include "cRobot.h"

Playbed::Playbed()
{
}

Playbed::~Playbed()
{
}

void Playbed::Init()
{
	slGame::inst.window->setTitle("Asimov's Passing");
	slGame::inst.gravity = { 0.0f, 10.0f };
	slGame::inst.world.SetGravity(slGame::inst.gravity);

	slEntity* robot = new slEntity;
	robot->AddComponent(new cRobot);

	slEntity* scene = new slEntity;
	scene->AddComponent(new cGround);
	scene->AddComponent(new cCamera);

	//slEntity* crate = new slEntity;
	//cBox* box = cBox::CreateBox(.5, .5, Material::RUBBER);
	//crate->AddComponent(box);
	////crate->AddComponent(new cBreakable);
	//box->boxBody->SetTransform({ 10, 5 }, 0);

	entities.insert({ {"robot", robot}, {"scene", scene} });
}

void Playbed::Restart()
{
	delete this;
	slGame::inst.Run(new Playbed);
}
