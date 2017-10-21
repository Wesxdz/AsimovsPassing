#pragma once

#include "slGameState.h"

class Playbed : public slGameState
{
public:
	Playbed();
	~Playbed();

	// Inherited via slGameState
	virtual void Init() override;
	virtual void Restart() override;
};

