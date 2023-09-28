#include "Texture.h"
//texture contructor that loads the texture
Texture::Texture(std::string filename) {

	mGraphics = Graphics::Instance();

	mTex = AssetManager::Instance()->GetTexture(filename);
	
	SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);

	mClipped = false;

	mRenderRect.w = mWidth;
	mRenderRect.h = mHeight;
}
//texture constructor overload for a clipped texture to be rendered
Texture::Texture(std::string filename, int x, int y, int w, int h) {

	mGraphics = Graphics::Instance();

	mTex = AssetManager::Instance()->GetTexture(filename);

	mClipped = true;

	mWidth = w;
	mHeight = h;

	mRenderRect.w = mWidth;
	mRenderRect.h = mHeight;

	mClipRect.x = x;
	mClipRect.y = y;
	mClipRect.w = mWidth;
	mClipRect.h = mHeight;
}
//another texture overload for fonts to loaded
Texture::Texture(std::string text, std::string fontPath, int size, SDL_Color colour) {

	mGraphics = Graphics::Instance();
	mTex = AssetManager::Instance()->GetText(text, fontPath, size, colour);

	mClipped = false;

	SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);

	mRenderRect.w = mWidth;
	mRenderRect.h = mHeight;
}
//texture destructor
Texture::~Texture() {

	mTex = NULL;
	mGraphics = NULL;
}
//this is what allows our testure to rendered on to the screen
//specifies where the texture will be loaded and other criteria important to the rendering proccesss
void Texture::Render() {

	Vector2 pos = Pos(world);
	Vector2 scale = Scale(world);

	mRenderRect.x = (int)(pos.x - mWidth*scale.x* 0.5f);
	mRenderRect.y = (int)(pos.y - mHeight *scale.y*0.5f);
	mRenderRect.w = (int)(mWidth * scale.x);
	mRenderRect.h = (int)(mHeight * scale.y);
	mGraphics->DrawTexture(mTex,(mClipped)? &mClipRect : NULL, &mRenderRect, Rotation(world));
}