#include "Player.h"
#include <Novice.h>

Player::Player() {
	Initialize();
}

void Player::Initialize() {
	pos_ = { 640.0f,360.0f };
	moveSpeed_ = 5.0f;
	radius_ = 50.0f;
	coolTime_ = 0;
	specialTime_ = 120;
	isSpecial_ = false;
	color_ = 0xFFFFFFFF;

	rGBColor = Yellow;
	R = 255;
	G = 75;
	B = 0;
}

void Player::Updata() {
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
	coolTime_--;

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

	//特殊行動
	if (keys[DIK_E]) {
		if (coolTime_ <= 0) {
			isSpecial_ = true;
			specialTime_ = 120;
			moveSpeed_ = 8.0f;
			coolTime_ = 240;
		}
	}

	if (isSpecial_) {
		specialTime_--;


		if (specialTime_ <= 0) {
			isSpecial_ = false;
		}

		//ゲーミングカラー
		switch (rGBColor) {
		case Red:
			B -= 40;
			if (B <= 0) {
				B = 0;
				rGBColor = Yellow;
			}
			break;
		case Yellow:
			G += 40;
			if (G >= 255) {
				G = 255;
				rGBColor = Green;
			}
			break;
		case Green:
			R -= 40;
			if (R <= 0) {
				R = 0;
				rGBColor = Cyan;
			}
			break;
		case Cyan:
			B += 40;
			if (B >= 255) {
				B = 255;
				rGBColor = Blue;
			}
			break;
		case Blue:
			G -= 40;
			if (G <= 0) {
				G = 0;
				rGBColor = Magenta;
			}
			break;
		case Magenta:
			R += 40;
			if (R >= 255) {
				R = 255;
				rGBColor = Red;
			}
			break;
		}

		int toumei = 255;
		color_ = (R << 24) | (G << 16) | (B << 8) | toumei;

	} else {
		moveSpeed_ = 5.0f;
		color_ = 0xFFFFFFFF;
	}

}

void Player::Draw() {


	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f, color_,
		kFillModeSolid
	);

}

Vector2 Player::GetPos() {
	return pos_;
}

float Player::GetRadius() {
	return radius_;
}

int Player::GetIsSpecial() {
	return isSpecial_;
}
