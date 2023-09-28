#ifndef _GAMEENTITY_H
#define _GAMEENTITY_H
#include "MathHelper.h"

class GameEntity {

public:
	//here this variable can be checke if the position is local or world
	enum SPACE{local = 0, world = 1};

private:
	//here are our position scale and rotation variables
	Vector2 mPos;
	Vector2 mScale;
	float mRotation;

	bool mActive;
	GameEntity* mParent;

public:
	//contructor and destructor
	GameEntity(float x = 0.0f, float y = 0.0f);
	~GameEntity();
	//here are postion functions
	void Pos(Vector2 pos);
	Vector2 Pos(SPACE space = world);
	//roattion functions
	void Rotation(float ratation);
	float Rotation(SPACE space = world);
	//scale function
	void Scale(Vector2 scale);
	Vector2 Scale(SPACE space = world);
	//active functions
	void Active(bool active);
	bool Active();
	//parent and child functions
	void Parent(GameEntity* parent);
	GameEntity* Parent();
	//movement functions
	void Translate(Vector2 vec, SPACE space = GameEntity::local);
	void Rotate(float amount);
	//update adn render functions
	virtual void Update();
	virtual void Render();
};
#endif // !_GAMEENTITY_H
