#include "Bullet.h"

Bullet::Bullet() {

	mTimer = Timer::Instance();

	mSpeed = 500.0f;

	mBullet = new Texture("greySquare.png", 0, 0, 25, 25);
	mBullet->Parent(this);
	mBullet->Pos(VEC2_ZERO);

	Reload();

}

Bullet::~Bullet() {

	mTimer = NULL;

	delete mBullet;
	mBullet = NULL;

}

void Bullet::Fire(Vector2 pos) {

	Pos(pos);
	Active(true);
	printf("Bullet ");

}

void Bullet::Reload() {

	Active(false);

}

void Bullet::Update() {

	if (Active()) {

		Translate(VEC2_UP * mSpeed * mTimer->DeltaTime(), local); // up us negative

		Vector2 pos = Pos();

		if (pos.y < -OFFSCREEN_BUFFER || pos.y > Graphics::Instance()->SCREEN_HEIGHT + OFFSCREEN_BUFFER) {

			Reload();
		}
	}

}

void Bullet::Render() {

	if (Active()) {

		mBullet->Render();
	}

}