#pragma once
#include "BirdState.h"
class FallingBirdState : public BirdState
{
public:
	FallingBirdState(Bird* i_bird);
	void Move();
private:
	Bird* m_bird;
};