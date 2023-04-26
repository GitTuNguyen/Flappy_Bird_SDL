#include "FlyingBirdState.h"
#include "Bird.h"

FlyingBirdState::FlyingBirdState(Bird* i_bird)
{
	m_bird = i_bird;
}

void FlyingBirdState::Move()
{
	m_bird->m_speed = SPEED_FLY + 0.5 * G;	
}
