#include "Gamemanager.h"


// Its me Liam
// its me aman
// its me aneesh

//here is the main function;
int main(int argc, char* argv[]) {
	//here we create a new game manager instance
	GameManager* game = GameManager::Instance();

	// here we call all the functions we need for the game loop 
	game->Run();
	// here is the functions we call after we close the window and we set the value of the game back to null because we haev closed the game
	GameManager::Release();
	game = NULL;

	return 0;
}