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
	Coordinate GetBirdCoordinate();
	void Reset();
	void SetBirdCoordinate(int i_y);
	void BirdAnimation();
	int GetBirdMotion();
	void BirdMove(bool i_isFlying);
	void BirdDie();
	static Bird* GetInstance();
	~Bird();
	float m_speed;

private:
	Bird();
	void InitializeCoordinate();
	void SetState(BirdState* i_state);
	static Bird* instance;
	static std::mutex m_mutex;
	BirdState* m_birdCurrentState;
	FlyingBirdState* m_flyingState;
	FallingBirdState* m_fallingState;
	DieBirdState* m_dieState;
	int m_indexImageOfBird;
	Coordinate m_coordinateBird;
};