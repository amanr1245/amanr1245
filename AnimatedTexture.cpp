#include "AnimatedTexture.h"
//here is our animated texture construcor that renders/clips and animates from a sprite sheet
AnimatedTexture::AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, ANIM_DIR animationDir)
	: Texture(filename, x, y, w, h)
{
	mTimer = Timer::Instance();

	mStartX = x;
	mStartY = y;

	mFrameCount = frameCount;
	mAnimationSpeed = animationSpeed;
	mTimePerFrame = mAnimationSpeed / mFrameCount;
	mAnimationTimer = 0.0f;

	mAnimationDirection = animationDir;

	mAnimationDone = false;
	
	mWrapMode = loop;

};
//destructor
AnimatedTexture::~AnimatedTexture() {

}
//setts wrap mode
void AnimatedTexture::WrapMode(WRAP_MODE mode){

	mWrapMode = mode;
}
//update fucntion for the game loop, sets the wrap mode and the animation type and animates 
void AnimatedTexture::Update() {

	if (!mAnimationDone) {

		mAnimationTimer += mTimer->DeltaTime();

		if (mAnimationTimer >= mAnimationSpeed) {

			if (mWrapMode == loop) {

				mAnimationTimer -= mAnimationSpeed;
			}
			else {

				mAnimationDone = true;

				mAnimationTimer = mAnimationSpeed - mTimePerFrame;
			}
		}

		if (mAnimationDirection == horizontal) {

			mClipRect.x = mStartX + (int)(mAnimationTimer / mTimePerFrame) * mWidth;
		} else {

			mClipRect.y = mStartY + (int)(mAnimationTimer / mTimePerFrame);
		}
	}
}
