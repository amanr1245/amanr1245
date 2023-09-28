#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H
#include "AnimatedTexture.h"
#include "InputManager.h"

class StartScreen : public GameEntity {
	 
private:

	// Start screen entities
	Texture* mStartingScreen;


public:
	
	StartScreen(); // Start screen constructor
	~StartScreen(); // start screen deconstructor

	void Update();
	 
	void Render();

};

#endif