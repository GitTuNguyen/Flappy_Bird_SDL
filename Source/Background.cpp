#include "Background.h"

Background::Background()
{
	CreateBackground();
}

void Background::CreateBackground()
{
	m_coordinateBackground.first.x = 0;
	m_coordinateBackground.first.y = 0;
	m_coordinateBackground.second.x = m_coordinateBackground.first.x + WINDOW_WIDTH;
	m_coordinateBackground.second.y = 0;
	m_coordinateGround.first.x = 0;
	m_coordinateGround.first.y = WINDOW_HEIGHT - GROUND_HEIGHT;
	m_coordinateGround.second.x = m_coordinateGround.first.x + WINDOW_WIDTH;
	m_coordinateGround.second.y = WINDOW_HEIGHT - GROUND_HEIGHT;;
}

std::pair <Coordinate, Coordinate> Background::GetCoordinateBackground()
{
	return m_coordinateBackground;
}

std::pair <Coordinate, Coordinate> Background::GetCoordinateGround()
{
	return m_coordinateGround;
}

void Background::BackgroundMove()
{
	m_coordinateBackground.first.x -= COLUMN_SPEED;
	m_coordinateBackground.second.x -= COLUMN_SPEED;
	m_coordinateGround.first.x -= COLUMN_SPEED;
	m_coordinateGround.second.x -= COLUMN_SPEED;
}