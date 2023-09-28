#ifndef _ANIMATEDTEXTURE_H
#define _ANIMATEDTEXTURE_H
#include "Timer.h"
#include "Texture.h"

//here we create the animated texture class with the and inheritance from the texture class
class AnimatedTexture : public Texture {

public:

	//Initlizaing some public variables for animation types
	enum WRAP_MODE { once = 0, loop = 1 };
	enum ANIM_DIR { horizontal = 0, vertical = 1 };

private:

	//here we are intilizing all our private variables
	Timer* mTimer;
	//tellls the functions where to start the clipped rectangle
	int mStartX;
	int mStartY;
	//sets the speed of the animation
	float mAnimationTimer;
	float mAnimationSpeed;
	float mTimePerFrame;

	int mFrameCount;
	//sets the animation direction(portrait or landscape,) sets the wrap mode (once or looped)
	WRAP_MODE mWrapMode;
	ANIM_DIR mAnimationDirection;

	bool mAnimationDone;

public:
	//here we create all the public functions we wil be using
	AnimatedTexture(std::string filename, int x, int y, int w, int h, int framecount, float animationSpeed, ANIM_DIR animationDir);
	~AnimatedTexture();
	//wrape mosde function
	void WrapMode(WRAP_MODE mode);
	//upadate function
	void Update();
};
#endif // !_ANIMATEDTEXTURE_H
