#include "input.h"
#include <SDL.h>
bool Input::Initialize()
{
	int numKeys;
	const uint8_t* keyboardState = SDL_GetKeyboardState(&numKeys);
	m_keyboardState.resize(numKeys);
	std::copy(keyboardState, keyboardState + numKeys, m_keyboardState.begin());
	m_prevKeyboardState = m_keyboardState;
	return true;
}

void Input::Shutdown()
{
}

void Input::update()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	//if(SDL_PollEvent(&event) == SDL_QUIT)
	

	// keyboard input
	m_prevKeyboardState = m_keyboardState;
	const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
	std::copy(keyboardState, keyboardState + m_keyboardState.size(), m_keyboardState.begin());


	// mouse input
	int x, y;
	uint32_t buttonState = SDL_GetMouseState(&x, &y);
	m_mousePosition.x = (float)x;
	m_mousePosition.y = (float)y;
	m_prevMouseButtonState = m_mouseButtonState;
	m_mouseButtonState[0] = buttonState & SDL_BUTTON_LMASK;
	m_mouseButtonState[1] = buttonState & SDL_BUTTON_MMASK;
	m_mouseButtonState[2] = buttonState & SDL_BUTTON_RMASK;
}
