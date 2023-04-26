#include "DieBirdState.h"
#include "Bird.h"
DieBirdState::DieBirdState(Bird* i_bird)
{
	m_bird = i_bird;
}

void DieBirdState::Move()
{
	if (m_bird->GetBirdCoordinate().y + BIRD_WIDTH < WINDOW_HEIGHT)
	{
		m_bird->m_speed = SPEED_FALLING_WHEN_DIE + 0.5 * G;
	}
	else {
		m_bird->m_speed = 0;
	}
}