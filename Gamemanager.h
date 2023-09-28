#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H
#include "InputManager.h"
#include "AnimatedTexture.h"
#include "Texture.h"
#include "Timer.h"
#include "StartScreen.h"
#include "Bullet.h"

class GameManager {

private:

	// here are all our variables we need to create the functions
	static GameManager* sInstance;
	//here out frame rate 
	const int FRAME_RATE = 30;
	//here is the variable to check if the player has quit out of the game
	bool mQuit;
	//here are the intilizations for all the manager variabels 
	Graphics* mGraphics;
	AssetManager* mAssetMgr;
	InputManager* mInputMgr;

	// used to limit the frame rate
	Timer* mTimer;

	// Used to catch the event when the user exits the game
	SDL_Event mEvents;

	StartScreen* mStartScreen; // Creating a start screen

	//GameEntity* mParent;
	//GameEntity* mChild;

	// Bullets
	static const int MAX_BULLETS = 25; // max bullets
	Bullet* mBullets[MAX_BULLETS];

	void HandleFiring();

	//Texture* mTex;
	//here we are creating all our texture variables
	Texture* mTex;
	Texture* m2Tex;
	Texture* m3Tex;
	Texture* m4Tex;
	Texture* m5Tex;
	Texture* m6Tex;	
	Texture* m7Tex;
	
	Texture* mDeathScreen;


public:
	int startGame = 0;
	float projSpeed1 = -100.0f;
	float projSpeed2 = 0.0f;
	int counter = 1;
	//here are all the public functions
	static GameManager* Instance();
	static void Release();
	//run function that allows use to run the game
	void Run();

private:
	//constructor and destructor
	GameManager();
	~GameManager();

	void EarlyUpdate();
	void Update();
	void LateUpdate();

	void Render();
};
#endif // !_GAMEMANAGER_H
