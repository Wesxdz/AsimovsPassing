#include "cRobot.h"

cRobot::cRobot() :
	maxRodLen{ 2.5f }
{
}

cRobot::~cRobot()
{
	//slGame::inst.world.DestroyBody(frameBody);
	//slGame::inst.world.DestroyBody(sawBody);
	//slGame::inst.world.DestroyJoint(rodJoint);
}

void cRobot::Init()
{
	Reg(slRegister::DRAW | slRegister::UPDATE | slRegister::INPUT);

	// Create frame
	b2BodyDef frameDef;
	frameDef.fixedRotation = true;
	frameDef.type = b2_dynamicBody;
	frameDef.linearDamping = 0.5f;
	frameBody = slGame::inst.world.CreateBody(&frameDef);
	b2PolygonShape frameShape;
	frameShape.SetAsBox(frameWidth/2, frameHeight/2);
	b2FixtureDef frameFixDef;
	frameFixDef.shape = &frameShape;
	frameFixDef.density = 80.0f;
	frameFixDef.friction = 0.5f;
	frameBody->CreateFixture(&frameFixDef);

	// Create saw
	b2BodyDef sawDef;
	sawDef.type = b2_dynamicBody;
	sawDef.angularDamping = 0.2f;
	sawDef.linearDamping = 2.0f;
	sawBody = slGame::inst.world.CreateBody(&sawDef);
	b2CircleShape sawShape;
	sawShape.m_radius = sawRadius;
	b2FixtureDef sawFixDef;
	sawFixDef.shape = &sawShape;
	sawFixDef.density = 20.0f;
	sawFixDef.friction = 1.0f;
	sawFixDef.restitution = 0.2f;
	sawBody->CreateFixture(&sawFixDef);

	// Create hold joint
	b2DistanceJointDef holdDef;
	holdDef.Initialize(frameBody, sawBody, { 0, 0 }, { 0, 0 });
	holdDef.length = 2.0f;
	//holdJoint = (b2DistanceJoint*) slGame::inst.world.CreateJoint(&holdDef);

	// Create rod joint

	b2MotorJointDef rodDef;
	rodDef.Initialize(frameBody, sawBody);
	rodDef.linearOffset = b2Vec2{ cos(rodRotation) * rodLen, sin(rodRotation) * rodLen };
	rodDef.maxForce = 3000.0f;
	rodDef.maxTorque = 100.0f;
	rodJoint = (b2MotorJoint*) slGame::inst.world.CreateJoint(&rodDef);

	b2Vec2 spawnPoint = b2Vec2(slGame::inst.WindowSize().x / 2, slGame::inst.WindowSize().y / 2);
	frameBody->SetTransform(spawnPoint, 0);
	sawBody->SetTransform(spawnPoint, 0);

}

bool cRobot::Input(sf::Event* e)
{
	if (e->type == e->KeyPressed) {
		if (e->key.code == sf::Keyboard::Space) {
			if (magJoint) {
				slGame::inst.world.DestroyJoint(magJoint);
				magJoint = nullptr;
			}
			else {
				b2ContactEdge* contact = frameBody->GetContactList();
				if (contact && contact->contact->IsTouching()) {
					b2WeldJointDef magDef;
					magDef.Initialize(frameBody, contact->other, { 0, 0 });
					magJoint = (b2WeldJoint*)slGame::inst.world.CreateJoint(&magDef);
				}
			}
		}
	}
	return false;
}

void cRobot::Update(float dt)
{
	bool rodChange = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		sawBody->ApplyAngularImpulse(8.0f, true);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
		sawBody->ApplyAngularImpulse(-8.0f, true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		rodRotation += rodRotateSpeed * dt;
		rodChange = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		rodRotation -= rodRotateSpeed * dt;
		rodChange = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		float amountExtend = rodExtendSpeed * dt;
		rodLen = (rodLen + amountExtend > maxRodLen) ? maxRodLen : rodLen + amountExtend;
		rodChange = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		float amountRetract = rodExtendSpeed * dt;
		rodLen = (rodLen - amountRetract < minRodLen) ? minRodLen : rodLen - amountRetract;
		rodChange = true;

	}
	if (rodChange) {
		rodJoint->SetLinearOffset(b2Vec2{ cos(rodRotation) * rodLen, sin(rodRotation) * rodLen });
	}
}

void cRobot::Draw()
{
}
