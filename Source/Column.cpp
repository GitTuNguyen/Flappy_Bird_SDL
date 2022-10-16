#include "Column.h"

Column::Column()
{
	InitColumn();
}

std::vector<std::pair <Coordinate, Coordinate> > Column::getCoordinateColumn()
{
	return m_coordinateColumn;
}

std::pair <Coordinate, Coordinate> Column::CreateColumn(int i_X)
{
	int temp_y;
	int temp = MIN_COLUMN_HEIGHT_DISPLAY + rand() % ((WINDOW_HEIGHT - MIN_COLUMN_HEIGHT_DISPLAY * 2 - BLANK) + 1 - MIN_COLUMN_HEIGHT_DISPLAY);
	temp_y = temp - COLUMN_HEIGHT;
	std::pair <Coordinate, Coordinate> column;
	column.first.x = i_X;
	column.first.y = temp_y;
	temp_y += COLUMN_HEIGHT + BLANK;
	column.second.x = i_X;
	column.second.y = temp_y;
	return column;
}

void Column::InitColumn()
{
	for (int i = 0; i < NUMBER_COLUMN_IN_BOARD; i++)
	{
		m_coordinateColumn.push_back(CreateColumn(WINDOW_WIDTH + DISTANCE * i));
	}
}

void Column::ColumnMove()
{
	for (int i = 0; i < NUMBER_COLUMN_IN_BOARD; i++)
	{
		m_coordinateColumn[i].first.x -= COLUMN_SPEED;
		m_coordinateColumn[i].second.x -= COLUMN_SPEED;
	}
}

void Column::AddNewColumn()
{
	m_coordinateColumn.erase(m_coordinateColumn.begin());

	m_coordinateColumn.push_back(CreateColumn(m_coordinateColumn[NUMBER_COLUMN_IN_BOARD - 2].first.x + DISTANCE));
}