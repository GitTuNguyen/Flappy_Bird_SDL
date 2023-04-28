#pragma once
#include <cstdlib>
#include <ctime>
#include <vector>
#include <mutex>

#include "Background.h"
#include "Column.h"
#include "Bird.h"
#include "SFXManager.h"

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
	SFXManager* GetSound();
	int GetScores();
	void UpdateScores();
	void ScreenMotion();
	void UpdateGameResult();
	bool IsCanStartNewGame();
	~Board();
private:
	bool CheckScore();
	Background* m_background;
	Column* m_column;
	Bird* m_bird;
	SFXManager* m_sound;
	GameResult m_gameResult;
	int m_scores;
};