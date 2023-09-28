#include "InputManager.h"

//initialization of instance variable 
InputManager* InputManager::sInstance = NULL;

//creation of input manager instance
InputManager* InputManager::Instance() {

	if (sInstance == NULL)
		sInstance = new InputManager();

	return sInstance;
}
//definition of release
void InputManager::Release() {

	delete sInstance;
	sInstance = NULL;
}
//this is our constructor
InputManager::InputManager() {

	mKeyboardStates = SDL_GetKeyboardState(&mKeyLength);
	mPrevKeyboardState = new Uint8[mKeyLength];
	memcpy(mPrevKeyboardState, mKeyboardStates, mKeyLength);
}

//this is our destructor
InputManager::~InputManager() {

	delete[] mPrevKeyboardState;
	mPrevKeyboardState = NULL;
}

bool InputManager::KeyDown(SDL_Scancode scanCode) {

	//SDL_Scancode is a SDL class that tells you what input was pressed, in our case, its the controls


	return mKeyboardStates[scanCode];


}

bool InputManager::Keypressed(SDL_Scancode scanCode) {
	
	return !mPrevKeyboardState[scanCode] && mKeyboardStates[scanCode];
}

bool InputManager::KeyReleased(SDL_Scancode scanCode) {

	return mPrevKeyboardState[scanCode] && !mKeyboardStates[scanCode];
}

Vector2 InputManager::MousePos() {

	return Vector2((float)mMouseXpos, (float)mMouseYpos);
}

bool InputManager::MouseButtonDown(MOUSE_BUTTON button) {

	Uint32 mask = 0;

	switch (button) {
	case left:
		mask = SDL_BUTTON_LMASK;
		break;

	case right:
		mask = SDL_BUTTON_RMASK;
		break;
	case middle:
		mask = SDL_BUTTON_MMASK;
		break;
	case back:
		mask = SDL_BUTTON_X1MASK;
		break;
	case forward:
		mask = SDL_BUTTON_X2MASK;
		break;
	}

	return (mMouseState & mask);
}

bool InputManager::MouseButtonPressed(MOUSE_BUTTON button) {

	Uint32 mask = 0;

	switch (button) {
	case left:
		mask = SDL_BUTTON_LMASK;
		break;

	case right:
		mask = SDL_BUTTON_RMASK;
		break;
	case middle:
		mask = SDL_BUTTON_MMASK;
		break;
	case back:
		mask = SDL_BUTTON_X1MASK;
		break;
	case forward:
		mask = SDL_BUTTON_X2MASK;
		break;
	}

	return !(mPrevMouseState & mask) && (mMouseState & mask);
}

bool InputManager::MouseButtonReleased(MOUSE_BUTTON button) {

	Uint32 mask = 0;

	switch (button) {
	case left:
		mask = SDL_BUTTON_LMASK;
		break;

	case right:
		mask = SDL_BUTTON_RMASK;
		break;
	case middle:
		mask = SDL_BUTTON_MMASK;
		break;
	case back:
		mask = SDL_BUTTON_X1MASK;
		break;
	case forward:
		mask = SDL_BUTTON_X2MASK;
		break;
	}

	return (mPrevMouseState & mask) && !(mMouseState & mask);
}
void InputManager::Update() {

	mMouseState = SDL_GetMouseState(&mMouseXpos, &mMouseYpos);
	//mKeyboardStates = SDL_GetKeyboardState(NULL);
	//sdl_getkeyboardstate retrieves all keyboard inputs so that the program can check against each input
}

void InputManager::UpdatePrevInput() {

	memcpy(mPrevKeyboardState, mKeyboardStates, mKeyLength);
	mPrevMouseState = mMouseState;
}


