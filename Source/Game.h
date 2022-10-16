#pragma once
#include "Board.h"
#include "Renderer.h"
#include "InputManager.h"
#include <iostream>

class Game 
{
public:
	Game();
	void Update();
	~Game();
private:
	Board* m_board;
	Renderer* m_renderer;
	InputManager* m_inputManager;
	bool m_isPlayerWantExit;
	bool m_isClick;
	SDL_Event mainEvent;
	void LoadPicture();
	void DrawScreen();
	void CreateNewGame();
	//void Rematch();
};