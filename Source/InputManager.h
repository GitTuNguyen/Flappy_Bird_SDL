#pragma once
#include "SDL.h"
#include <mutex>
class InputManager
{
public:	
	void UpdateInput();
	int GetMouseX();
	int GetMouseY();
	bool IsGoingToQuit();
	bool IsMouseUp();
	bool IsSpaceKeyDown();
	static InputManager* GetInstance();
private:
	InputManager();
	static std::mutex m_mutex;
	static InputManager* instance;
	int m_mouseX;
	int m_mouseY;
	bool m_isGoingToQuit;
	bool m_isMouseUp;
	bool m_isSpaceKeyDown;
};