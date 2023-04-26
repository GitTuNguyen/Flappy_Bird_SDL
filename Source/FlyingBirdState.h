#pragma once
#include "BirdState.h"
class FlyingBirdState : public BirdState
{
	void Move();
public:
	FlyingBirdState(Bird* i_bird);
private:
	Bird* m_bird;
};