#include "Timer.h"

//here we set the value of the new isntance to null because nothing has been intilized with timer variable
Timer* Timer::sInstance = NULL;
//here we create the instance function for our timer class, the function creates a new timer for use to use
Timer* Timer::Instance() {
	if (sInstance == NULL) {
		sInstance = new Timer();
	}

	return sInstance;
}
//here is our release function that will delete the instance to free up the momory it is using and setting back the instance to null
void Timer::Release() {
	
	delete sInstance;
	sInstance = NULL;
}
//here we hvae the timer constructor 
Timer::Timer() {

	Reset();
	mTimeScale = 1.0f;
}

//here we have the timer destructor
Timer::~Timer() {

}

//when this is called everyithing gets reset back to zero, we use this after every frame to set a framerate
void Timer::Reset() {

	mStartTicks = SDL_GetTicks();
	mElapsedTicks = 0;
	mDeltaTime = 0.0f;
}

float Timer::DeltaTime() {

	return mDeltaTime;
}

void Timer::TimeScale(float t) {

	mTimeScale = t;
}

float Timer::TimeScale() {
	
	return mTimeScale;
}

// this is what sets the frame rate
void Timer::Update() {

	mElapsedTicks = SDL_GetTicks() - mStartTicks;
	mDeltaTime = mElapsedTicks * 0.001f;
}