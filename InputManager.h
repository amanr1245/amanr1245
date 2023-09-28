#ifndef _INPUTMANAGER_H
//singleton inputmanager
#define _INPUTMANAGER_H
#include "SDL.h"
#include "string.h"
#include "MathHelper.h"
class InputManager {

public:

	enum MOUSE_BUTTON { left = 0, right, middle, back, forward};

private:
	//here we creat our instance
	static InputManager* sInstance;

	Uint8* mPrevKeyboardState;
	const Uint8* mKeyboardStates;
	int mKeyLength;

	Uint32 mPrevMouseState;
	Uint32 mMouseState;

	int mMouseXpos;
	int mMouseYpos;
	//uint8 is an 8 bit integer value that is useful with pointers

public:
	//public functions the we will use later
	static InputManager* Instance();
	static void Release();

	bool KeyDown(SDL_Scancode scanCode);
	bool Keypressed(SDL_Scancode scanCode);
	bool KeyReleased(SDL_Scancode scanCode);
	
	bool MouseButtonDown(MOUSE_BUTTON button);
	bool MouseButtonPressed(MOUSE_BUTTON button);
	bool MouseButtonReleased(MOUSE_BUTTON button);
	//SDL_Scancode is a SDL class that tells you what input was pressed, in our case, its the controls

	Vector2 MousePos();

	void Update();
	void UpdatePrevInput();

private:
	//constructor and destructor 
	InputManager();
	~InputManager();
};
#endif // !1_INPUTMANAGER_H

