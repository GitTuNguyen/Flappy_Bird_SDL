#pragma once
#include <SDL.h>
#include "SDL_image.h"
#include "Board.h"
#include <string>
#include <map>


class Renderer {
public:
	Renderer();
	void LoadTexture(std::string i_ImageName);
	void DrawStartScreen();
	void DrawBird(Coordinate i_coordinateBird, int i_birdMotion);
	void DrawColumn(std::vector< std::pair<Coordinate, Coordinate> > i_coordinateColumn);
	void DrawnBackground(std::pair <Coordinate, Coordinate> i_coordinateBackground);
	void DrawGround(std::pair <Coordinate, Coordinate> i_coordinateGround);
	void DrawScores(int i_scores);
	void DrawBirdDie(Coordinate i_coordinateBird, int i_birdMotion);
	void DrawGameOverScreen();
	void ClearFrame();
	void PostFrame();
	void PreRendering();
	void CleanUp();
private:
	SDL_Window* m_window = NULL;
	SDL_Renderer* m_sdlRenderer = NULL;
	std::map<std::string, SDL_Texture*> m_loadedTextures;
};