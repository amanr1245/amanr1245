#ifndef _TIMER_H
#define _TIMER_H
#include <SDL.h>

class Timer {

private:
	//here we intialize our isntance variable for the singleton
	static Timer* sInstance;
	//here we intialize all the variabels we need to set the frame rate
	unsigned int mStartTicks;
	unsigned int mElapsedTicks;
	float mDeltaTime;
	float mTimeScale;

public:
	//here we have our instance function to create a timer instance and a release function to cleare the memory when we are done
	static Timer* Instance();
	static void Release();

	//here we have our reset and delta time function to reset all our variables to zero after on frame has gone and to check the amoutn of 
	//time between each frame
	void Reset();
	float DeltaTime();
	//this is the functions we use to set the speed of frame rate/transformation
	void TimeScale(float t);
	float TimeScale();
	//update function for the game loop
	void Update();

private:
	//contructor and destructor
	Timer();
	~Timer();


};
#endif // !_TIMER_H

