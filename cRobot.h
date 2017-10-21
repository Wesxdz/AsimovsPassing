#include "slComponent.h"

#include <SFML/Audio.hpp>

class cRobot : public slComponent
{
public:
	float frameWidth = 1.0f;
	float frameHeight = 1.0f;
	b2Body* frameBody;

	float sawRadius = 0.5f;
	b2Body* sawBody;

	b2MotorJoint* rodJoint;
	float rodRotation = 270.0f;
	float rodRotateSpeed = 2.0f;
	float rodExtendSpeed = 6.0f;
	float minRodLen = 1.0f;
	float rodLen = 1.5f;
	float maxRodLen;

	b2WeldJoint* magJoint;


public:
	cRobot();
	~cRobot();
	// Inherited via slComponent
	virtual void Init() override;
	virtual bool Input(sf::Event * e) override;
	virtual void Update(float dt) override;
	virtual void Draw() override;
};