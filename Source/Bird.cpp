#include "Bird.h"


Bird::Bird()
{
	m_flyingState = new FlyingBirdState(this);
	m_fallingState = new FallingBirdState(this);
	m_dieState = new DieBirdState(this);
	Reset();
}

void Bird::Reset()
{
	InitializeCoordinate();
	m_birdCurrentState = m_fallingState;
	m_speed = 0;
	m_isDie = false;
}

void Bird::InitializeCoordinate()
{
	m_coordinateBird.x = BIRD_X;
	m_coordinateBird.y = BIRD_Y;
}

Coordinate Bird::GetBirdCoordinate()
{
	return m_coordinateBird;
}

void Bird::SetBirdCoordinate(int i_y)
{
	m_coordinateBird.y = i_y;
}

void Bird::SetState(BirdState* i_state)
{
	m_birdCurrentState = i_state;
}

void Bird::BirdMove(bool i_isFly)
{
	if (i_isFly && m_birdCurrentState != m_dieState)
	{
		SetState(m_flyingState);
		m_birdCurrentState->Move();
		
		SetState(m_fallingState);
	}
	else {
		m_birdCurrentState->Move();
	}
	if (m_coordinateBird.y + m_speed <= 0)
	{
		m_coordinateBird.y = 0;
	}
	else {
		m_coordinateBird.y += m_speed;
	}
	
}

void Bird::BirdDie()
{
	if (m_birdCurrentState != m_dieState)
	{
		SetState(m_dieState);
		m_isDie = true;
	}
}