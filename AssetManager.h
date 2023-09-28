#ifndef _ASSETMANAGER_H
//beginning of the singleton with
#define _ASSETMANAGER_H
#include "Graphics.h"
#include <map>

class AssetManager {

private:
	
	//Instance singleton
	static AssetManager* sInstance;

	//Initialization of maps 
	std::map<std::string, SDL_Texture*> mTextures;
	//Ignore these
	std::map<std::string, SDL_Texture*> mText;
	std::map<std::string, TTF_Font*> mFonts;

public:
	 //here we define all our public functions that we will use from now onward
	static AssetManager* Instance();
	static void Release();

	SDL_Texture* GetTexture(std::string filename);
	//ignore this
	SDL_Texture* GetText(std::string text, std::string filename, int size, SDL_Color colour);

private:

	//here is our constructor and destructor
	AssetManager();
	~AssetManager();

	//ignore this
	TTF_Font* GetFont(std::string filename, int size);
};

#endif // !_ASSETMANAGER_H
//end to singleton class
