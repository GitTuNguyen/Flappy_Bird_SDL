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
	std::vector<std::string> gameTextures = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "b_1", "b_2", "b_3", "b_4", "back_ground", "column", "game_over", "start_game", "ground"};
	for (int i = 0; i < gameTextures.size(); i++)
	{
		m_renderer->LoadTexture(gameTextures[i]);
	}
}

void Game::DrawScreen()
{
	m_renderer->DrawnBackground(m_board->GetBackground()->GetCoordinateBackground());
	m_renderer->DrawColumn(m_board->GetColumn()->getCoordinateColumn());
	m_renderer->DrawGround(m_board->GetBackground()->GetCoordinateGround());
	m_renderer->DrawScores(m_board->GetScores());
}

void Game::CreateNewGame()
{
	m_board->Reset();
}

void Game::Update()
{	
	Uint32 screenMotionBefore, screenMotionAfter, birdMotionBefore, birdMotionAfter;
	while (!m_isPlayerWantExit)
	{
		m_renderer->ClearFrame();
		GameResult gameResult = m_board->GetGameResult();
		m_inputManager->UpdateInput();
		m_isPlayerWantExit = m_inputManager->IsGoingToQuit();
		if (gameResult == GameResult::START)
		{
			DrawScreen();
			m_renderer->DrawStartScreen();
			if (m_inputManager->IsMouseUp() || m_inputManager->IsSpaceKeyDown())
			{
				m_board->StartGame();
				screenMotionBefore = SDL_GetTicks();
				birdMotionBefore = SDL_GetTicks();
				m_board->GetSound()->SoundSwosh();
			}
		}
		else if (gameResult == GameResult::RUNNING)
		{
			if (m_inputManager->IsMouseUp() || m_inputManager->IsSpaceKeyDown())
			{
				m_board->GetSound()->SoundWing();
			}			
			screenMotionAfter = SDL_GetTicks();
			birdMotionAfter = SDL_GetTicks();
			if (screenMotionAfter - screenMotionBefore >= 10)
			{
				screenMotionBefore = screenMotionAfter;
				m_board->ScreenMotion();
				m_board->UpdateScores();
			}
			birdMotionAfter = SDL_GetTicks();
			if (birdMotionAfter - birdMotionBefore >= 100)
			{
				birdMotionBefore = birdMotionAfter;
				m_board->GetBird()->SetBirdMotion();
			}
			m_board->UpdateGameResult();
			m_board->GetBird()->BirdMove(m_inputManager->IsMouseUp() || m_inputManager->IsSpaceKeyDown());
			DrawScreen();
			m_renderer->DrawBird(m_board->GetBird()->GetCoordinateBird(), m_board->GetBird()->GetBirdMotion());
		}
		else {
			DrawScreen();
			m_renderer->DrawBirdDie(m_board->GetBird()->GetCoordinateBird(), m_board->GetBird()->GetBirdMotion());
			m_board->GetBird()->BirdDie();
			m_renderer->DrawGameOverScreen();
			if (m_inputManager->IsMouseUp() || m_inputManager->IsSpaceKeyDown())
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