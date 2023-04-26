#pragma once
#include "SDL_mixer.h"
#include <string>
class SFXManager
{
public:
	SFXManager();
	void SoundSwosh();
	void SoundWing();
	void SoundPoint();
	void SoundHit();
	void SoundDie();
	void StopPlaySound();
private:
	Mix_Chunk* m_swosh = NULL;
	Mix_Chunk* m_wing = NULL;
	Mix_Chunk* m_point = NULL;
	Mix_Chunk* m_hit = NULL;
	Mix_Chunk* m_die = NULL;
};