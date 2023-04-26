#pragma once
#include "GameDefinition.h"
#include "SFXManager.h"
#include "FlyingBirdState.h"
#include "FallingBirdState.h"
#include "DieBirdState.h"
class Bird
{
public:
	Bird();
	Coordinate GetBirdCoordinate();
	void SetBirdCoordinate(int i_y);
	void BirdAnimation();
	int GetBirdMotion();
	void BirdMove(bool i_isFlying);
	void BirdDie();
	float m_speed;
private:
	void InitializeCoordinate();
	void SetState(BirdState* i_state);
	BirdState* m_birdCurrentState;
	FlyingBirdState* m_flyingState;
	FallingBirdState* m_fallingState;
	DieBirdState* m_dieState;
	int m_indexImageOfBird;
	Coordinate m_coordinateBird;
};