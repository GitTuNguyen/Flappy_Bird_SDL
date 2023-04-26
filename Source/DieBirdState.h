#pragma once
#include "BirdState.h"
class Bird;
class DieBirdState : public BirdState
{
public:
	DieBirdState(Bird* i_bird);
	void Move();
private:
	Bird* m_bird;
};