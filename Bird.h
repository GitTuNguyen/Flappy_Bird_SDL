#pragma once
#include "Parameter.h"
#include "Sound.h"

class Bird
{
public:
	Bird();
	Coordinate getCoordinateBird();
	void setPicture();
	int getPicture();
	void BirdMove(bool i_isClick);
	void BirdDie();
private:
	void CreatBird();
	float m_speed;
	int m_picture;
	Coordinate m_coordinateBird;
};