#ifndef _TEXTURE_H
#define _TEXTURE_H
#include "GameEntity.h"
#include "AssetManager.h"
//creation of the texture class with public inheritance from our game entity class
class Texture : public GameEntity {

protected: 
	//here we make a texture variable
	SDL_Texture* mTex;
	//here we also make a graphics vriable
	Graphics* mGraphics;
	//variable to spcify height and width of the images we load
	int mWidth;
	int mHeight;
	//bool value to see if the image we made has been clipped
	bool mClipped;
	//we create our texture by generating rectangles and this what these two are for these to variables generate rectangle for out
	//textures to be loaded in
	SDL_Rect mRenderRect;
	SDL_Rect mClipRect;
public:
	//here are all the texture constructors to make all the textures we need
	Texture(std::string filename);
	Texture(std::string filename, int x, int y, int w, int h);
	//ignore this one function
	Texture(std::string text, std::string fontPath, int size, SDL_Color colour);
	//the destructor
	~Texture();
	//our render function
	virtual void Render();
};
#endif // !_TEXTURE_H
