#pragma once
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
	void StartGame();
	void Reset();
	GameResult GetGameResult();
	Background* GetBackground();
	Column* GetColumn();
	Bird* GetBird();
	Sound* GetSound();
	int GetScores();
	void UpdateScores();
	void ScreenMotion();
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