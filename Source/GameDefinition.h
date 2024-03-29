#pragma once
#define SDL_MAIN_HANDLED

struct Coordinate {
	int x;
	int y;
};

enum GameResult {
	START,
	RUNNING,
	GAMEOVER
};

//Window
#define WINDOW_WIDTH 360
#define WINDOW_HEIGHT 720

//Start Window
#define START_WINDOW_WIDTH (WINDOW_WIDTH * 4 / 5)
#define START_WINDOW_HEIGHT (WINDOW_HEIGHT * 2 / 3)

//Bird
#define BIRD_WIDTH 60
#define BIRD_HEIGHT 45
#define BIRD_X ((WINDOW_WIDTH - BIRD_WIDTH) / 2)
#define BIRD_Y ((WINDOW_HEIGHT - BIRD_HEIGHT) / 2)
#define G 0.3
#define SPEED_FLY -6
#define SPEED_FALLING G
#define SPEED_FALLING_WHEN_DIE 7
#define NUMBER_OF_BIRD_MOTION 3

//Column

#define COLUMN_WIDTH 80
#define COLUMN_HEIGHT 600
#define BLANK 160
#define DISTANCE 300
#define COLUMN_SPEED 2
#define NUMBER_COLUMN_IN_BOARD 3
#define MIN_COLUMN_HEIGHT_DISPLAY 100

//Ground
#define GROUND_HEIGHT 30

//Scores
#define NUMBER_HEIGHT 36
#define NUMBER_WIDTH 24
#define NUMBER_OF_DIGITS 3
#define NUMBER_FRAME_X ((WINDOW_WIDTH - NUMBER_WIDTH * NUMBER_OF_DIGITS) / 2)
#define NUMBER_FRAME_Y 100

//GameOver
#define GAME_OVER_WIDTH 192
#define GAME_OVER_HEIGHT 42
#define GAME_OVER_X ((WINDOW_WIDTH - GAME_OVER_WIDTH) / 2)
#define GAME_OVER_Y ((WINDOW_WIDTH - GAME_OVER_HEIGHT) / 2)