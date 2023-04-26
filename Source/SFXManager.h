#pragma once
#include "SDL_mixer.h"
#include <string>
#include <mutex>
class SFXManager
{
public:
	
	void SoundSwosh();
	void SoundWing();
	void SoundPoint();
	void SoundHit();
	void SoundDie();
	void StopPlaySound();
	static SFXManager* GetInstance();
	~SFXManager();
private:
	SFXManager();
	static SFXManager* instance;
	static std::mutex m_mutex;
	Mix_Chunk* m_swosh = NULL;
	Mix_Chunk* m_wing = NULL;
	Mix_Chunk* m_point = NULL;
	Mix_Chunk* m_hit = NULL;
	Mix_Chunk* m_die = NULL;
};