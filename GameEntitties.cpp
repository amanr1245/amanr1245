#include "GameEntity.h"
//game entity constructor
GameEntity::GameEntity(float x, float y) {

	mPos.x = x;
	mPos.y = y;

	mRotation = 0.0f;

	mActive = true;

	mParent = NULL;

	mScale = VEC2_ONE;
}
//game entity destructor
GameEntity::~GameEntity() {

	mParent = NULL;
}
//here we set the position of the object
void GameEntity::Pos(Vector2 pos) {

	mPos = pos;
}
//here we overload te position function for rotation
Vector2 GameEntity::Pos(SPACE space) {
	
	if (space == local || mParent == NULL)
		return mPos;

	Vector2 parentScale = mParent->Scale(world);
	Vector2 rotPos = RotateVector(Vector2(mPos.x * parentScale.x, mPos.y * parentScale.y), mParent->Rotation(local));

	return mParent->Pos(world) + rotPos;
}
//here is the rotation function we use to rotate the object
void GameEntity::Rotation(float r) {

	mRotation = r;

	if (mRotation > 360.0f)
		mRotation -= 360.0f;

	if (mRotation < 0.0f)
		mRotation += 360.0f;
}
//here we overlaod teh rotation function
float GameEntity::Rotation(SPACE space) {

	if (space == local || mParent == NULL)
		return mRotation;

	return mParent->Rotation(world) + mRotation;
}
//here we have the scale function
void GameEntity::Scale(Vector2 scale) {

	mScale = scale;
}
//here we overload the scale function so that we can scale textures
Vector2 GameEntity::Scale(SPACE space) {

	if (space == local || mParent == NULL)
		return mScale;

	Vector2 parentScale = mParent->Scale(world);

	return  Vector2(parentScale.x * mScale.x, parentScale.y * mScale.y);
}

void GameEntity::Active(bool active) {

	mActive = active;
}

bool GameEntity::Active(){

	return mActive;
}
//setting the roation of the child to relative to the parent
void GameEntity::Parent(GameEntity* parent) {

	if (parent == NULL) {

		mPos = Pos(world);
		mRotation = Rotation(world);
		mScale = Scale(world);
	}
	else {

		if (mParent != NULL) 
			Parent(NULL);

			Vector2 parentScale = parent->Scale(world);

			//mPos = RotateVector(Pos(world) - parent->Pos(world), -parent->Rotation(world));
			Vector2 normalBack(Pos(world) - parent->Pos(world));
			mPos = RotateVector(normalBack, -parent->Rotation(world));
			mPos.x /= parentScale.x;
			mPos.y /= parentScale.y;

			mRotation -= parent->Rotation(world);

			mScale = Vector2(mScale.x / parentScale.x, mScale.y / parentScale.y);
	}

	mParent = parent;
}

GameEntity* GameEntity::Parent() {

	return mParent;
}

void GameEntity::Translate(Vector2 vec, SPACE space) {

	if (space == world) {
		
		mPos += vec;

	}
	else {

		mPos += RotateVector(vec, Rotation());
	}
}

void GameEntity::Rotate(float amount) {

	mRotation += amount;
}

void GameEntity::Update() {

}

void GameEntity::Render() {

}