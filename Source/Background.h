#pragma once
#include "GameDefinition.h"
#include <utility>

class Background
{
public:
	Background();
	std::pair <Coordinate, Coordinate> getCoordinateBackground();
	std::pair <Coordinate, Coordinate> getCoordinateGround();
	void BackgroundMove();
	void CreateBackground();
private:
	std::pair <Coordinate, Coordinate> m_coordinateBackground;
	std::pair <Coordinate, Coordinate> m_coordinateGround;
};