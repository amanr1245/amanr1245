#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <stdio.h>

class Graphics {

public:

	// here are the contraints for the window
	static const int SCREEN_WIDTH = 1024;
	static const int SCREEN_HEIGHT = 600;

private:
		
	//here we initialize all the variables we need to create our window and graphic functions
	static Graphics* sInstance;
	static bool sInitialized;

	SDL_Window* mWindow;
	SDL_Surface* mBackBuffer;

	SDL_Renderer* mRenderer;

public:
	// here are all our public functions
	static Graphics* Instance();
	static void Release();
	static bool Initialized();
	//here are the functions to draw textures and fonts onto the screen
	SDL_Texture* LoadTexture(std::string path);
	SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text, SDL_Color colour);

	void ClearBackBuffer();
	//here is the texture for a clipping tool
	void DrawTexture(SDL_Texture* tex, SDL_Rect* clip = NULL ,SDL_Rect* rend = NULL, float angle = 0.5, SDL_RendererFlip flip = SDL_FLIP_NONE);
	//render function
	void Render();

private:
	//constructor and destructor and intilization funtion to catch any errors
	Graphics();
	~Graphics();

	bool Init();
};

#endif // !_GRAPHICS_H

