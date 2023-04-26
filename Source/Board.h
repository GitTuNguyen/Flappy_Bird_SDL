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
	static Board* GetInstance();
	~Board();
private:
	Board();
	bool CheckScore();
	static std::mutex m_mutex;
	static Board* instance;
	Background* m_background;
	Column* m_column;
	Bird* m_bird;
	SFXManager* m_sound;
	GameResult m_gameResult;
	int m_scores;
};