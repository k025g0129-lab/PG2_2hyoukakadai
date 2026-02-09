#include "Player.h"
#include <Novice.h>

Player::Player() {
	Initialize();
}

void Player::Initialize() {
	pos_ = { 640.0f,360.0f };
	moveSpeed_ = 5.0f;
	radius_ = 50.0f;
}

void Player::Updata() {
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);


	//移動処理
	if (keys[DIK_W]) {
		pos_.y -= moveSpeed_;
	}

	if (keys[DIK_S]) {
		pos_.y += moveSpeed_;
	}

	if (keys[DIK_A]) {
		pos_.x -= moveSpeed_;
	}

	if (keys[DIK_D]) {
		pos_.x += moveSpeed_;
	}

}

void Player::Draw() {

	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f, 0xFFFFFFFF,
		kFillModeSolid
	);

}

Vector2 Player::GetPos() {
	return pos_;
}

float Player::GetRadius() {
	return radius_;
}
