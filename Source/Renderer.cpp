#include "Renderer.h"

Renderer::Renderer()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Unable to initialize SDL %s\n", SDL_GetError());
		return;
	}

	//Create window
	m_window = SDL_CreateWindow("Flappy Bird - SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (m_window == NULL)
	{
		printf("Could not create window %s", SDL_GetError());
		return;
	}


	//create a renderer
	m_sdlRenderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_sdlRenderer == NULL)
	{
		printf("Could not create render %s", SDL_GetError());
		return;
	}
}

void Renderer::PostFrame()
{
	SDL_RenderPresent(m_sdlRenderer);
	SDL_Delay(16);
}

void Renderer::LoadTexture(std::string i_ImageName)
{
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* tempSurface = NULL;
	SDL_Texture* texture = NULL;
	std::string str = "./Data/" + i_ImageName + ".png";
	tempSurface = IMG_Load(str.c_str());
	texture = SDL_CreateTextureFromSurface(m_sdlRenderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	m_loadedTextures.insert(std::pair<std::string, SDL_Texture*>(i_ImageName, texture));
}

void Renderer::DrawBird(Coordinate i_coordinateBird, int i_numberPicture)
{
	SDL_Rect newRect;
	newRect.w = BIRD_WIDTH;
	newRect.h = BIRD_HEIGHT;
	newRect.x = i_coordinateBird.x;
	newRect.y = i_coordinateBird.y;
	std::string temp = "b_" + std::to_string(i_numberPicture);
	SDL_RenderCopy(m_sdlRenderer, m_loadedTextures[temp], NULL, &newRect);
}

void Renderer::DrawBirdDie(Coordinate i_coordinateBird)
{
	SDL_Rect newRect;
	newRect.w = BIRD_WIDTH;
	newRect.h = BIRD_HEIGHT;
	newRect.x = i_coordinateBird.x;
	newRect.y = i_coordinateBird.y;
	std::string temp = "b_" + std::to_string(4);
	SDL_RenderCopyEx(m_sdlRenderer, m_loadedTextures[temp], NULL, &newRect, 90, NULL, SDL_FLIP_NONE);
}

void Renderer::DrawColumn(std::vector< std::pair<Coordinate, Coordinate> > i_coordinateColumn)
{
	SDL_Rect newRect;
	newRect.w = COLUMN_WIDTH;
	newRect.h = COLUMN_HEIGHT;
	for (int i = 0; i < i_coordinateColumn.size(); i++)
	{

	newRect.x = i_coordinateColumn[i].first.x;
	newRect.y = i_coordinateColumn[i].first.y;
	SDL_RenderCopy(m_sdlRenderer, m_loadedTextures["column"], NULL, &newRect);
	newRect.x = i_coordinateColumn[i].second.x;
	newRect.y = i_coordinateColumn[i].second.y;
	SDL_RenderCopy(m_sdlRenderer, m_loadedTextures["column"], NULL, &newRect);
	}
}

void Renderer::DrawnBackground(std::pair <Coordinate, Coordinate> i_coordinateBackground)
{
	SDL_Rect newRect;
	newRect.w = WINDOW_WIDTH;
	newRect.h = WINDOW_HEIGHT;
	newRect.x = i_coordinateBackground.first.x;
	newRect.y = i_coordinateBackground.first.y;
	SDL_RenderCopy(m_sdlRenderer, m_loadedTextures["back_ground"], NULL, &newRect);
	newRect.x = i_coordinateBackground.second.x;
	SDL_RenderCopy(m_sdlRenderer, m_loadedTextures["back_ground"], NULL, &newRect);
}

void Renderer::DrawGround(std::pair <Coordinate, Coordinate> i_coordinateGround)
{
	SDL_Rect newRect;
	newRect.w = WINDOW_WIDTH;
	newRect.h = GROUND_HEIGHT;
	newRect.x = i_coordinateGround.first.x;
	newRect.y = i_coordinateGround.first.y;
	SDL_RenderCopy(m_sdlRenderer, m_loadedTextures["ground"], NULL, &newRect);
	newRect.x = i_coordinateGround.second.x;
	SDL_RenderCopy(m_sdlRenderer, m_loadedTextures["ground"], NULL, &newRect);
}

void Renderer::DrawStartScreen()
{
	SDL_Rect newRect;
	newRect.w = WINDOW_WIDTH;
	newRect.h = WINDOW_HEIGHT;
	newRect.x = 0;
	newRect.y = 0;
	SDL_RenderCopy(m_sdlRenderer, m_loadedTextures["start_game"], NULL, &newRect);
}

void Renderer::DrawGameOverScreen()
{
	SDL_Rect newRect;
	newRect.w = GAME_OVER_WIDTH;
	newRect.h = GAME_OVER_HEIGHT;
	newRect.x = GAME_OVER_X;
	newRect.y = GAME_OVER_Y;
	SDL_RenderCopy(m_sdlRenderer, m_loadedTextures["game_over"], NULL, &newRect);
}

void Renderer::DrawScores(int i_scores)
{
	std::string str = std::to_string(i_scores);
	for (int i = 0; i <= NUMBER_OF_DIGITS - str.length(); i++)
	{
		str = "0" + str;
	}

	SDL_Rect newRect;
	newRect.w = NUMBER_WIDTH;
	newRect.h = NUMBER_HEIGHT;
	
	for (int i = 0; i < NUMBER_OF_DIGITS; i++)
	{
		std::string temp = str.substr(i, 1);
		newRect.x = NUMBER_FRAME_X + (i * NUMBER_WIDTH);
		newRect.y = NUMBER_FRAME_Y;
		SDL_RenderCopy(m_sdlRenderer, m_loadedTextures[temp], NULL, &newRect);
	}
}

void Renderer::ClearFrame()
{
	SDL_SetRenderDrawColor(m_sdlRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_sdlRenderer);
}

void Renderer::CleanUp()
{

	SDL_DestroyWindow(m_window);

	SDL_DestroyRenderer(m_sdlRenderer);

	SDL_Quit();
}

