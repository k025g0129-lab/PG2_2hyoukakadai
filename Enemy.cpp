#include "Enemy.h"
#include <Novice.h>


Enemy::Enemy() {
	Initialize();
}

void Enemy::Initialize() {

	moveSpeed_ = 5.0f;
	radius_ = 30.0f;
	score_ = 1;
	isActive_ = true;

	pos_.x = float(rand() % 1220 ) + radius_;
	pos_.y = -float(rand() % 1000) - radius_;


}

void Enemy::Updata() {
	
	pos_.y += moveSpeed_;

	if (pos_.y >= 720.0f + radius_) {
		Initialize();
	}
	


}

void Enemy::Draw() {

	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f, 0xFF0000FF,
		kFillModeSolid
	);

}

void Enemy::SetIsActive(int active) {
	this->isActive_ = active;
}

int Enemy::GetIsActive() {
	return isActive_;
}

int Enemy::GetScore() {
	return score_;
}

Vector2 Enemy::GetPos() {
	return pos_;
}

float Enemy::GetRadius() {
	return radius_;
}

