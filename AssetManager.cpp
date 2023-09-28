#include "AssetManager.h"

// this is the initialization of the Instance variable
AssetManager* AssetManager::sInstance = NULL;

//creation of the assetmanager instance
AssetManager* AssetManager::Instance() {

	if (sInstance == NULL)
		sInstance = new AssetManager();

	return sInstance;
}

//definition of release 
void AssetManager::Release() {

	delete sInstance;
	sInstance = NULL;
}

//constructor, no need to add anything to it for now
AssetManager::AssetManager(){

}

//this is our destructor
AssetManager::~AssetManager() {

	for (auto tex : mTextures) {
		if (tex.second != NULL) {

			SDL_DestroyTexture(tex.second);
			//destroys second variable of the map, which is SDL_Texture
		}
	}

	mTextures.clear();
	//.clear() resets all elements to zero/NULL and sets the size of the map to zero

	//ignore the other two for loops 
	for (auto text : mText) {
		if (text.second != NULL) {

			SDL_DestroyTexture(text.second);
		}
	}

	mText.clear();

	for (auto font : mFonts) {
		if (font.second != NULL) {

			TTF_CloseFont(font.second);
		}
	}

	mFonts.clear();
}

//path is used get the file path of the .exe
// this pulls the path of the desired texture and outputs it
SDL_Texture* AssetManager::GetTexture(std::string filename) {

	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);
	//Assets/ is the folder that we put the desired textures in

	if (mTextures[fullPath] == nullptr)
		mTextures[fullPath] = Graphics::Instance()->LoadTexture(fullPath);

	return mTextures[fullPath];
}

//ignore this 
TTF_Font* AssetManager::GetFont(std::string filename, int size) {

	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);
	std::string key = fullPath + (char)size;

	if (mFonts[key] == nullptr) {

		mFonts[key] = TTF_OpenFont(fullPath.c_str(), size);
		if (mFonts[key] == nullptr)
			printf("Font Loading Error: Font-%s Error-%s", filename.c_str(), TTF_GetError());
	}

	return mFonts[key];
}

//ignore this 
SDL_Texture* AssetManager::GetText(std::string text, std::string filename, int size, SDL_Color colour) {

	TTF_Font* font = GetFont(filename, size);

	std::string key = text + filename + (char)size + (char)colour.r + (char)colour.b + (char)colour.g;

	if (mText[key] == nullptr)
		mText[key] = Graphics::Instance()->CreateTextTexture(font,text,colour);

	return mText[key];
}