#include "Bird.h"

Bird::Bird()
{
	CreatBird();
	m_speed = 0;
	m_picture = 1;
}

void Bird::CreatBird()
{
	m_coordinateBird.x = BIRD_X;
	m_coordinateBird.y = BIRD_Y;
}

Coordinate Bird::getCoordinateBird()
{
	return m_coordinateBird;
}

int Bird::getPicture()
{
	return m_picture;
}

void Bird::setPicture()
{
	if (m_picture == NUMBER_OF_BIRD_PICTURE)
	{
		m_picture = 1;
	}
	else {
		m_picture++;
	}
}

void Bird::BirdMove(bool i_isClick)
{
	if (i_isClick)
	{
		m_speed = SPEED_FLY;
	}
	if (m_coordinateBird.y + m_speed + 0.5 * G <= 0)
	{
		m_coordinateBird.y = 0;
	}
	else {
		m_coordinateBird.y += m_speed + 0.5 * G;		
	}
	m_speed += G;
}

void Bird::BirdDie()
{
	if (m_coordinateBird.y + BIRD_WIDTH < WINDOW_HEIGHT)
	{
		m_coordinateBird.y += 10;
	}
}