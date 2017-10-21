#include "cBreakable.h"
#include "cBox.h"


cBreakable::cBreakable()
{
}

cBreakable::~cBreakable()
{
}

void cBreakable::Init()
{
	Reg(slRegister::UPDATE, -1);
	body = GetSiblingComponent<cBox>()->boxBody;
}

bool cBreakable::Input(sf::Event * e)
{
	return false;
}

void cBreakable::Update(float dt)
{
	b2ContactEdge* contact = body->GetContactList();
	while (contact) {
		contact = contact->next;
	}
}

void cBreakable::Draw()
{
}
