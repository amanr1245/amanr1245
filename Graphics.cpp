#include "Graphics.h"

// here we create the intializations for the graphics instance
Graphics* Graphics::sInstance = NULL;
bool Graphics::sInitialized = false;


// here we create an instance
Graphics* Graphics::Instance() {
	if (sInstance == NULL) 
		sInstance = new Graphics();

	return sInstance;
}

// here we release that instance after we are done with the graphics instance
void Graphics::Release() {

	delete sInstance;
	sInstance = NULL;

	sInitialized = false;
}

// here we check it the graphics is initailized
bool Graphics::Initialized() {

	return sInitialized;

}

// here is the constructor
Graphics::Graphics() {

	mBackBuffer = NULL;

	sInitialized = Init();
}

// here is the destructor
Graphics::~Graphics() {

	SDL_DestroyWindow(mWindow);
	mWindow = NULL;

	SDL_DestroyRenderer(mRenderer);
	mRenderer = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

// here are all the intilizations we check for any error when loading textures or windows
bool Graphics::Init() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {

		printf("SDL INTIALIZATION ERROR: %s\n", SDL_GetError());
		return false;
	}

	mWindow = SDL_CreateWindow("Rescue of Order", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (mWindow == NULL) {

		printf("Window Creation Error %s\n", SDL_GetError());
		return false;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
	
	if (mRenderer == NULL) {

		printf("Renderer Creation Error: %s\n", SDL_GetError());
		return false;
	}

	SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	int flags = IMG_INIT_PNG;
	if (!(IMG_Init(flags) & flags)) {

		printf("IMG Initialization Error: %s\n", IMG_GetError());
		return false;
	}

	if (TTF_Init() == -1) {

		printf("TTF Initialization error: %s\n", TTF_GetError());
		return false;
	}
	mBackBuffer = SDL_GetWindowSurface(mWindow);

	return true;
 }

// here is the definition for load texture
SDL_Texture* Graphics::LoadTexture(std::string path) {

	SDL_Texture* tex = NULL;
	
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == NULL) {

		printf("Image Load Error: Path(%s) - Error(%s)\n", path.c_str(), IMG_GetError());
		return tex;
	}

	tex = SDL_CreateTextureFromSurface(mRenderer, surface);
	if (tex == NULL) {

		printf("Create Texture Error: %s\n", SDL_GetError());
		return tex;
	}

	SDL_FreeSurface(surface);

	return tex;
}

// here we create ttf font
SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, std::string text, SDL_Color colour) {

	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), colour);
	if (surface == NULL) {

		printf("Text render error: %s\n", TTF_GetError);
		return NULL;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(mRenderer, surface);
	if (tex == NULL) {

		printf("Text texture creation error: %s\n", SDL_GetError());
		return NULL;
	}

	SDL_FreeSurface(surface);

	return tex;
}

void Graphics::ClearBackBuffer() {

	SDL_RenderClear(mRenderer);
}

//here is overload for out draw tetxure that allows us to rotate it
void Graphics::DrawTexture(SDL_Texture* tex, SDL_Rect* clip, SDL_Rect* rend, float angle, SDL_RendererFlip flip) {

	SDL_RenderCopyEx(mRenderer, tex, clip, rend, angle, NULL, flip);
}

//here we render all out textures
void Graphics::Render() {

	SDL_RenderPresent(mRenderer);
}

