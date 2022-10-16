#include "Game.h"

Game::Game()
{
	m_board = new Board();
	m_renderer = new Renderer();
	m_inputManager = new InputManager();
	m_isPlayerWantExit = false;
	m_isClick = false;
	LoadPicture();
}

void Game::LoadPicture()
{
	std::string file_name[AMOUNT_OF_FILE_PICTURE] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "b_1", "b_2", "b_3", "b_4", "back_ground", "column", "game_over", "start_game", "ground"};
	for (int i = 0; i < sizeof(file_name) / sizeof(std::string); i++)
	{
		m_renderer->LoadTexture(file_name[i]);
	}
}

void Game::DrawScreen()
{
	m_renderer->DrawnBackground(m_board->getBackground()->getCoordinateBackground());
	m_renderer->DrawColumn(m_board->getColumn()->getCoordinateColumn());
	m_renderer->DrawGround(m_board->getBackground()->getCoordinateGround());
	m_renderer->DrawScores(m_board->getScores());
}

void Game::CreateNewGame()
{
	m_board->Reset();
	DrawScreen();
}

void Game::Update()
{
	m_renderer->DrawStartScreen();
	Uint32 before_1, after_1, before_2, after_2;
	while (!m_isPlayerWantExit)
	{
		GameResult gameResult = m_board->getGameResult();
		m_inputManager->UpdateInput();
		m_isPlayerWantExit = m_inputManager->IsGoingToQuit();
		if (gameResult == GameResult::START)
		{
			if (m_inputManager->IsMouseUp())
			{
				m_board->setGameResult(GameResult::RUNNING);
				before_1 = SDL_GetTicks();
				before_2 = SDL_GetTicks();
				m_board->getSound()->SoundSwosh();
			}
		}
		else if (gameResult == GameResult::RUNNING)
		{
			m_renderer->ClearFrame();
			if (m_inputManager->IsMouseUp())
			{
				m_board->getSound()->SoundWing();
			}			
			after_1 = SDL_GetTicks();
			after_2 = SDL_GetTicks();
			if (after_1 - before_1 >= 10)
			{
				before_1 = after_1;
				m_board->UpdateMove();
			}
			after_2 = SDL_GetTicks();
			if (after_2 - before_2 >= 100)
			{
				before_2 = after_2;
				m_board->getBird()->setPicture();
			}
			m_board->UpdateGameResult();
			m_board->getBird()->BirdMove(m_inputManager->IsMouseUp());
			DrawScreen();
			m_renderer->DrawBird(m_board->getBird()->getCoordinateBird(), m_board->getBird()->getPicture());
		}
		else {
			m_renderer->ClearFrame();
			DrawScreen();
			m_renderer->DrawBirdDie(m_board->getBird()->getCoordinateBird());
			m_board->getBird()->BirdDie();
			m_renderer->DrawGameOverScreen();
			if (m_inputManager->IsMouseUp())
			{
				CreateNewGame();
			}			
		}
		m_renderer->PostFrame();
	}
	m_renderer->CleanUp();
}

Game::~Game()
{
	delete m_board;
	delete m_renderer;
	delete m_inputManager;
}