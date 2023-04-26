#include "Sound.h"

Sound::Sound()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
	{
		printf("%s", Mix_GetError());
	}

	m_swosh = Mix_LoadWAV("Data/swosh.wav");
	if (m_swosh == NULL)
	{
		printf("%s", Mix_GetError());
	}

	m_wing = Mix_LoadWAV("Data/wing.wav");
	if (m_wing == NULL)
	{
		printf("%s", Mix_GetError());
	}

	m_point = Mix_LoadWAV("Data/point.wav");
	if (m_point == NULL)
	{
		printf("%s", Mix_GetError());
	}

	m_hit = Mix_LoadWAV("Data/hit.wav");
	if (m_hit == NULL)
	{
		printf("%s", Mix_GetError());
	}

	m_die = Mix_LoadWAV("Data/die.wav");
	if (m_die == NULL)
	{
		printf("%s", Mix_GetError());
	}
}

void Sound::SoundSwosh()
{
	Mix_PlayChannel(-1, m_swosh, 0);
}

void Sound::SoundWing()
{
	Mix_PlayChannel(-1, m_wing, 0);
}

void Sound::SoundPoint()
{
	Mix_PlayChannel(-1, m_point, 0);
}

void Sound::SoundHit()
{
	Mix_PlayChannel(-1, m_hit, 0);
}

void Sound::SoundDie()
{
	Mix_PlayChannel(-1, m_die, 0);
}

void Sound::StopPlaySound()
{
	Mix_HaltChannel(-1);
}
