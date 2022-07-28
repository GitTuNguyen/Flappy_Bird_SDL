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
#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 600

//Bird
#define BIRD_WIDTH 60
#define BIRD_HEIGHT 45
#define BIRD_X ((WINDOW_WIDTH - BIRD_WIDTH) / 2)
#define BIRD_Y ((WINDOW_HEIGHT - BIRD_HEIGHT) / 2)
#define G 0.3
#define SPEED_FLY -6
#define NUMBER_OF_BIRD_PICTURE 4

//Column

#define COLUMN_WIDTH 60
#define COLUMN_HEIGHT 500
#define BLANK 160
#define DISTANCE 200
#define COLUMN_SPEED 2
#define NUMBER_COLUMN_IN_BOARD 3
#define MIN_COLUMN_HEIGHT_DISPLAY 50

//Ground
#define GROUND_HEIGHT 30

//Scores
#define NUMBER_HEIGHT 36
#define NUMBER_WIDTH 24
#define NUMBER_OF_DIGITS 3
#define NUMBER_FRAME_X ((WINDOW_WIDTH - NUMBER_WIDTH * NUMBER_OF_DIGITS) / 2)
#define NUMBER_FRAME_Y 100

//Picture
#define AMOUNT_OF_FILE_PICTURE 19

//GameOver
#define GAME_OVER_WIDTH 192
#define GAME_OVER_HEIGHT 42
#define GAME_OVER_X ((WINDOW_WIDTH - GAME_OVER_WIDTH) / 2)
#define GAME_OVER_Y ((WINDOW_WIDTH - GAME_OVER_HEIGHT) / 2)