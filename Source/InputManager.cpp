#include "InputManager.h"

InputManager* InputManager::instance = nullptr;
std::mutex InputManager::m_mutex;

InputManager::InputManager()
{
	m_mouseX = 0;
	m_mouseY = 0;
	m_isGoingToQuit = false;
	m_isMouseUp = false;
	m_isSpaceKeyDown = false;
	instance = nullptr;
}

void InputManager::UpdateInput()
{
	m_isSpaceKeyDown = false;
	m_isMouseUp = false;
	SDL_Event mainEvent;
	m_mouseX = 0;
	m_mouseY = 0;
	while (SDL_PollEvent(&mainEvent))
	{
		switch (mainEvent.type)
		{
		case SDL_QUIT:
		{
			m_isGoingToQuit = true;
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			m_isMouseUp = false;
			break;
		}
		case SDL_MOUSEBUTTONUP:
		{
			m_isMouseUp = true;
			m_mouseX = mainEvent.motion.x;
			m_mouseY = mainEvent.motion.y;
			break;
		}
		case SDL_KEYDOWN:
		{
			switch (mainEvent.key.keysym.sym)
			{
			case SDLK_SPACE:
			{
				m_isSpaceKeyDown = true;
				break;
			}
			default:
				break;
			}
		}
		default:
		{
			break;
		}
		}
	}
}

int InputManager::GetMouseX()
{
	return m_mouseX;
}

int InputManager::GetMouseY()
{
	return m_mouseY;
}

bool InputManager::IsGoingToQuit()
{
	return m_isGoingToQuit;
}

bool InputManager::IsMouseUp()
{
	return m_isMouseUp;
}
bool InputManager::IsSpaceKeyDown()
{
	return m_isSpaceKeyDown;
}

InputManager* InputManager::GetInstance()
{
	m_mutex.lock();
	if (instance == nullptr) {
		instance = new InputManager();
	}
	m_mutex.unlock();
	return instance;
}