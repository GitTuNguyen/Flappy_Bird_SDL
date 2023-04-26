#include "FallingBirdState.h"
#include "Bird.h"

FallingBirdState::FallingBirdState(Bird* i_bird)
{
	m_bird = i_bird;
}

void FallingBirdState::Move()
{
	m_bird->m_speed += SPEED_FALLING + 0.5 * G;
}