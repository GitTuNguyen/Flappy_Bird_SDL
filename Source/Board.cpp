#include "Board.h"

Board* Board::instance = nullptr;
std::mutex Board::m_mutex;

Board::Board()
{
	Reset();
	m_gameResult = GameResult::START;
}

void Board::StartGame()
{
	m_gameResult = GameResult::RUNNING;
}

void Board::Reset()
{
	srand(time(NULL));
	m_gameResult = GameResult::RUNNING;
	m_scores = 0;
	m_background = new Background();
	m_column = new Column();
	m_bird = Bird::GetInstance();
	m_bird->Reset();
	m_sound = SFXManager::GetInstance();
}

Background* Board::GetBackground()
{
	return m_background;
}

Column* Board::GetColumn()
{
	return m_column;
}

Bird* Board::GetBird()
{
	return m_bird;
}

GameResult Board::GetGameResult()
{
	return m_gameResult;
}

int Board::GetScores()
{
	return m_scores;
}

SFXManager* Board::GetSound()
{
	return m_sound;
}

void Board::UpdateGameResult()
{
	for (int i = 0; i < NUMBER_COLUMN_IN_BOARD; i++)
	{
		if ((m_bird->GetBirdCoordinate().x >= m_column->getCoordinateColumn()[i].first.x - BIRD_WIDTH && m_bird->GetBirdCoordinate().x <= m_column->getCoordinateColumn()[i].first.x + COLUMN_WIDTH) && ((m_bird->GetBirdCoordinate().y >= 0 && m_bird->GetBirdCoordinate().y <= m_column->getCoordinateColumn()[i].first.y + COLUMN_HEIGHT) || (m_bird->GetBirdCoordinate().y + BIRD_HEIGHT >= m_column->getCoordinateColumn()[i].second.y)))
		{
			m_gameResult = GameResult::GAMEOVER;
			m_sound->SoundHit();
			m_sound->SoundDie();
			break;
		}
	}
	if (m_bird->GetBirdCoordinate().y + BIRD_HEIGHT >= WINDOW_HEIGHT - GROUND_HEIGHT)
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
		if (m_bird->GetBirdCoordinate().x + BIRD_WIDTH == m_column->getCoordinateColumn()[i].first.x + (COLUMN_WIDTH / 2) )
		{
			return true;
		}
	}
	return false;
}

void Board::UpdateScores()
{
	if (CheckScore())
	{
		m_scores++;
		m_sound->SoundPoint();
	}
}

void Board::ScreenMotion()
{
	m_background->BackgroundMove();
	m_column->ColumnMove();
	
	if (m_background->GetCoordinateBackground().second.x == 0)
	{
		m_background->CreateBackground();

	}
	if (m_column->getCoordinateColumn()[0].first.x == 0 - COLUMN_WIDTH)
	{
		m_column->AddNewColumn();
	}
}

Board* Board::GetInstance()
{
	m_mutex.lock();
	if (instance == nullptr) {
		instance = new Board();
	}
	m_mutex.unlock();
	return instance;
}

Board::~Board()
{
	delete m_background;
	delete m_column;
	delete instance;
}