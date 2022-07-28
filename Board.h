#pragma once
#include "Parameter.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Background.h"
#include "Column.h"
#include "Bird.h"
#include "Sound.h"

class Board 
{
public:
	Board();
	void Reset();
	GameResult getGameResult();
	void setGameResult(GameResult i_gameResult);
	Background* getBackground();
	Column* getColumn();
	Bird* getBird();
	Sound* getSound();
	int getScores();
	void UpdateMove();
	void UpdateGameResult();
	~Board();
private:	
	bool CheckScore();
	Background* m_background;
	Column* m_column;
	Bird* m_bird;
	int m_scores;
	Sound* m_sound;
	GameResult m_gameResult;
};