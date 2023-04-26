#pragma once
#include "GameDefinition.h"
#include "SFXManager.h"
class Bird;
class BirdState
{
public:
	virtual void Move() = 0;
};