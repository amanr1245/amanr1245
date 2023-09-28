#include "Gamemanager.h"
#include "GameEntity.h"
#include "AnimatedTexture.h"
#include "Bullet.h"

// here we intialized the game manager instance
GameManager* GameManager::sInstance = NULL;

// here is the instance function
GameManager* GameManager::Instance() {

	if (sInstance == NULL) 
		sInstance = new GameManager;

	return sInstance;
}

//our realese function when we are done with the instance
void GameManager::Release() {

	delete sInstance;
	sInstance = NULL;
}


// the constructor
GameManager::GameManager() {

	mQuit = false;

	mGraphics = Graphics::Instance();

	if(!Graphics::Initialized())
		mQuit = true;

	mAssetMgr = AssetManager::Instance();

	mInputMgr = InputManager::Instance();

	mTimer = Timer::Instance();

	for (int i = 0; i < MAX_BULLETS; i++) {
		mBullets[i] = new Bullet();
		mBullets[i]->Pos(Vector2(400, 400));
		mBullets[i]->Scale(Vector2(0.25f, 0.25f));
	}

	mStartScreen = new StartScreen();

	mTex = new Texture("blackSquare.png");
	mTex->Pos(Vector2(400, 400));
	m2Tex = new Texture("Room 2.png");
	m2Tex->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
	mTex->Scale(Vector2(0.25f, 0.25f));
	m2Tex->Scale(Vector2(4.0f, 4.0f));
	m3Tex = new Texture("greySquare.png");
	m3Tex->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
	m4Tex = new Texture("blueSquare.png");
	m4Tex->Pos(Vector2(750, 750));
	m5Tex = new Texture("blueSquare.png");
	m5Tex->Pos(Vector2(750, -750));
	m6Tex = new Texture("blueSquare.png");
	m6Tex->Pos(Vector2(-750, 750));
	m7Tex = new Texture("blueSquare.png");
	m7Tex->Pos(Vector2(-750, -750));
	m4Tex->Parent(m3Tex);
	m5Tex->Parent(m3Tex);
	m6Tex->Parent(m3Tex);
	m7Tex->Parent(m3Tex);
	m3Tex->Scale(Vector2(0.25f, 0.25f));
	m4Tex->Scale(Vector2(0.25f, 0.25f));
	m5Tex->Scale(Vector2(0.25f, 0.25f));
	m6Tex->Scale(Vector2(0.25f, 0.25f));
	m7Tex->Scale(Vector2(0.25f, 0.25f));


	for (int i = 0; i < MAX_BULLETS; i++) {

		mBullets[i] = new Bullet();
	}
	// Death Screen
	mDeathScreen = new Texture("Game Over.jpg", 0, 0, 1024, 600); //
	mDeathScreen->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f)); //
}

void GameManager::HandleFiring() {

	if (mInputMgr->KeyDown(SDL_SCANCODE_SPACE)) {

		for (int i = 0; i < MAX_BULLETS; i++) {

			if (!mBullets[i]->Active()) {

				mBullets[i]->Fire(mTex->Pos());
				printf("Boom\n");
				break;
			}
			/*if(mBullets[i]->Active()){
				mBullets[i]->Translate(Vector2(0.0f, -100.0f) * mTimer->DeltaTime(), GameEntity::local);
			}*/
		}
	}
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (mBullets[i]->Active()) {
			mBullets[i]->Translate(Vector2(projSpeed2, projSpeed1) * mTimer->DeltaTime(), GameEntity::local);
		}
	}
}


// the destructor
GameManager::~GameManager() {

	AssetManager::Release();
	mAssetMgr = NULL;
	
	Graphics::Release();
	mGraphics = NULL;

	InputManager::Release;
	mInputMgr = NULL;

	Timer::Release;
	mTimer = NULL;

	// Destroying start screen
	delete mStartScreen;
	mStartScreen = NULL;

	//delete mParent;
	//delete mChild;

	delete mTex;
	mTex = NULL;

	for (int i = 0; i < MAX_BULLETS; i++) {
		
		delete mBullets[i];
		mBullets[i] = NULL;
	}
}

void GameManager::EarlyUpdate() {

	mInputMgr->Update();
}

void GameManager::Update() {
	
	mStartScreen->Update();

	HandleFiring();

	for(int i = 0; i < MAX_BULLETS; i++){

		mBullets[i]->Update();
	}
	

	if (mInputMgr->KeyDown(SDL_SCANCODE_W)) {

		mTex->Translate(Vector2(0.0f, -100.0f) * mTimer->DeltaTime(), GameEntity::world);

	}
	else if (mInputMgr->KeyDown(SDL_SCANCODE_S)) {

		mTex->Translate(Vector2(0.0f, 100.0f) * mTimer->DeltaTime(), GameEntity::world);

	}
	else if (mInputMgr->KeyDown(SDL_SCANCODE_A)) {

		mTex->Translate(Vector2(-100.0f, 0.0f) * mTimer->DeltaTime(), GameEntity::world);

	}
	else if (mInputMgr->KeyDown(SDL_SCANCODE_D)) {

		mTex->Translate(Vector2(100.0f, 0.0f) * mTimer->DeltaTime(), GameEntity::world);

	}

	if (mInputMgr->Keypressed(SDL_SCANCODE_W)) {
		printf("Key pressed\n");
	}

	if (mInputMgr->KeyReleased(SDL_SCANCODE_W)) {
		printf("Key released\n");
	}

	if (mInputMgr->MouseButtonPressed(InputManager::left)) {
		printf("click pressed\n");
	}

	if (mInputMgr->MouseButtonReleased(InputManager::left)) {
		printf("click released\n");
	}

	if (mInputMgr->Keypressed(SDL_SCANCODE_E)) {
		if(counter == 1){
			counter = 2;
			projSpeed2 = 0.0f;
			projSpeed1 = -200.0f;
		} else if (counter == 2){
			counter = 3;
			projSpeed2 = 200.0f;
			projSpeed1 = 0.0f;
		} else if (counter == 3){
			counter = 4;
			projSpeed2 = 0.0f;
			projSpeed1 = 200.0f;
		} else if (counter == 4){
			counter = 1;
			projSpeed2 = -200.0f;
			projSpeed1 = 0.0f;
		}
	}
	
	m3Tex->Rotate(10 * mTimer->DeltaTime());

	for (int i = 0; i < MAX_BULLETS; i++)
		mBullets[i]->Update();

}

void GameManager::LateUpdate() {


	mInputMgr->UpdatePrevInput();

	mTimer->Reset();
}

void GameManager::Render() {
	
	// Clears the last frame's render from the back buffer
	mGraphics->ClearBackBuffer();

	// ALL other rendering is to happen here
	mStartScreen->Render(); // Start screen rendering

	// To start the game press 1
	if (mInputMgr->KeyDown(SDL_SCANCODE_1)) {
		startGame = 1; // making startGame equal to 1 (causes everything else to render)
	}
	else if (mInputMgr->KeyDown(SDL_SCANCODE_2)) {
		startGame = 0; // Stops everything from rendering and start screen will reappear
	}

	// When startGame integer is eqaul to 1, everything will render
	if (startGame == 1) {

		
		mTex->Update();
		mTex->Render();
		
		m2Tex->Update();

		m3Tex->Update();

		m4Tex->Update();

		m5Tex->Update();

		m6Tex->Update();

		m7Tex->Update();

		m2Tex->Render();

		mTex->Render();

		m3Tex->Render();

		m4Tex->Render();

		m5Tex->Render();

		m6Tex->Render();

		m7Tex->Render();

		for (int i = 0; i < MAX_BULLETS; i++) {
			mBullets[i]->Render();
		}
		


	}

	// Game Over / Death Screen
	if (startGame == 1 && mInputMgr->KeyDown(SDL_SCANCODE_3)) {
		mDeathScreen->Render();
	}
	
	mGraphics->Render();
}
// here is the main run function of the game the runs all the code
void GameManager::Run() {

	while (!mQuit) {

		mTimer->Update();

		while (SDL_PollEvent(&mEvents) != 0) {

			if (mEvents.type == SDL_QUIT) {

				mQuit = true;
			}
		}

		if (mTimer->DeltaTime() >= 1.0f / FRAME_RATE) {

			//printf("DeltaTIme: %f,\n", mTimer->DeltaTime()); this is the frame rate display

			/*mParent->Rotation(mParent->Rotation(GameEntity::local) + 0.1f);
			printf("Parent rOtation: %F\n", mParent->Rotation(GameEntity::local));
			printf("child local pos: (%F,%F)", mChild->Pos(GameEntity::world).x, mChild->Pos(GameEntity::world).y);*/

			// if startGame is equal to 1, this "if" statement stops player from playing the game during start screen
			// Game will only start after player presses the correct key during start screen
			if (startGame == 1) {

				EarlyUpdate();
				Update();
				LateUpdate();

			}

				Render();

		}
	}
}