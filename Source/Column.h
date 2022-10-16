#pragma once
#include "GameDefinition.h"
#include <vector>

class Column
{
public:
	Column();
	std::vector<std::pair <Coordinate, Coordinate> > getCoordinateColumn();
	void ColumnMove();
	void AddNewColumn();

private:
	std::pair <Coordinate, Coordinate> CreateColumn(int i_X);
	void InitColumn();
	std::vector< std::pair<Coordinate, Coordinate> > m_coordinateColumn;
};