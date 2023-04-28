#pragma once
#include "GameDefinition.h"
#include "SFXManager.h"
#include "FlyingBirdState.h"
#include "FallingBirdState.h"
#include "DieBirdState.h"
#include <mutex>

class Bird
{
public:
	Bird();
	Coordinate GetBirdCoordinate();
	void Reset();
	void SetBirdCoordinate(int i_y);
	int GetBirdMotion();
	void BirdMove(bool i_isFlying);
	void BirdDie();
	float m_speed;
	bool m_isDie;
private:
	void InitializeCoordinate();
	void SetState(BirdState* i_state);
	BirdState* m_birdCurrentState;
	FlyingBirdState* m_flyingState;
	FallingBirdState* m_fallingState;
	DieBirdState* m_dieState;
	Coordinate m_coordinateBird;
};