#include "Board.h"

Board::Board()
{
	Reset();
}

void Board::Reset()
{
	srand(time(0));
	m_gameResult = GameResult::START;
	m_scores = 0;
	m_background = new Background();
	m_column = new Column();
	m_bird = new Bird();
	m_sound = new Sound();
}

Background* Board::getBackground()
{
	return m_background;
}

Column* Board::getColumn()
{
	return m_column;
}

Bird* Board::getBird()
{
	return m_bird;
}

GameResult Board::getGameResult()
{
	return m_gameResult;
}

int Board::getScores()
{
	return m_scores;
}

Sound* Board::getSound()
{
	return m_sound;
}

void Board::setGameResult(GameResult i_gameResult)
{
	m_gameResult = i_gameResult;
}

void Board::UpdateGameResult()
{
	for (int i = 0; i < NUMBER_COLUMN_IN_BOARD; i++)
	{
		if ((m_bird->getCoordinateBird().x >= m_column->getCoordinateColumn()[i].first.x - BIRD_WIDTH && m_bird->getCoordinateBird().x <= m_column->getCoordinateColumn()[i].first.x + COLUMN_WIDTH) && ((m_bird->getCoordinateBird().y >= 0 && m_bird->getCoordinateBird().y <= m_column->getCoordinateColumn()[i].first.y + COLUMN_HEIGHT) || (m_bird->getCoordinateBird().y + BIRD_HEIGHT >= m_column->getCoordinateColumn()[i].second.y)))
		{
			m_gameResult = GameResult::GAMEOVER;
			m_sound->SoundHit();
			m_sound->SoundDie();
			break;
		}
	}
	if (m_bird->getCoordinateBird().y + BIRD_HEIGHT >= WINDOW_HEIGHT - GROUND_HEIGHT)
	{
		m_gameResult = GameResult::GAMEOVER;
		m_sound->SoundHit();
		m_sound->SoundDie();
	}
}

bool Board::CheckScore()
{
	for (int i = 0; i < NUMBER_COLUMN_IN_BOARD; i++)
	{
		if (m_bird->getCoordinateBird().x + BIRD_WIDTH == m_column->getCoordinateColumn()[i].first.x + (COLUMN_WIDTH / 2) )
		{
			return true;
		}
	}
	return false;
}


void Board::UpdateMove()
{
	m_background->BackgroundMove();
	m_column->ColumnMove();
	if (CheckScore())
	{
		m_scores++;
		m_sound->SoundPoint();
	}
	if (m_background->getCoordinateBackground().second.x == 0)
	{
		m_background->CreateBackground();

	}
	if (m_column->getCoordinateColumn()[0].first.x == 0 - COLUMN_WIDTH)
	{
		m_column->AddNewColumn();
	}
}

Board::~Board()
{
	delete m_background;
	delete m_column;
	delete m_bird;
	delete m_sound;
}