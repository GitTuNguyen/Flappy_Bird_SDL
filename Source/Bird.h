#pragma once
#include "GameDefinition.h"
#include "Sound.h"

class Bird
{
public:
	Bird();
	Coordinate GetCoordinateBird();
	void SetBirdMotion();
	int GetBirdMotion();
	void BirdMove(bool i_isClick);
	void BirdDie();
private:
	void CreatBird();
	float m_speed;
	int m_birdMotion;
	Coordinate m_coordinateBird;
};