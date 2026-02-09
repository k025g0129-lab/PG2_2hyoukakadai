#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet(Vector2 pos) {
	Initialize(pos);
}

void Bullet::Initialize(Vector2 pos) {
	pos_ = { pos.x,pos.y };
	moveSpeed_ = 10.0f;
	radius_ = 20.0f;
	isActive_ = false;

}

void Bullet::Updata() {
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
	if (isActive_) {
		pos_.y -= moveSpeed_;

		if (pos_.y <= 0.0f - radius_) {
			isActive_ = false;
		}
	}

	if (!isActive_) {
		pos_ = { -500.0f,-500.0f };
	}





}

void Bullet::Draw() {
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f, 0x0000FFFF,
		kFillModeSolid
	);

}

void Bullet::SetIsActive(int isActive) {
	this->isActive_ = isActive;
}

int Bullet::GetIsActive() {
	return isActive_;
}

Vector2 Bullet::GetPos() {
	return pos_;
}

float Bullet::GetRadius() {
	return radius_;
}
