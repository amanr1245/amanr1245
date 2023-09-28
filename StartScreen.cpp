#include "StartScreen.h"


// Start screen constructor
StartScreen::StartScreen() {

	// Starting Screen entities
	
	mStartingScreen = new Texture("Start Screen.jpeg", 0, 0, 1024, 600); // Getting the start screen png file at making it a certain size
	//mStartingScreen = new Texture("Start.png");

	mStartingScreen->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f)); // positioning start sreen to the middle of the window

	mStartingScreen->Parent(this); // Start screen parent
	
}

// Start screen destructor
StartScreen::~StartScreen() {
	
	// Freeing start screen entities
	delete mStartingScreen;
	mStartingScreen = NULL;
	
}

void StartScreen::Update() {


}

void StartScreen::Render() {

	mStartingScreen->Render();

}