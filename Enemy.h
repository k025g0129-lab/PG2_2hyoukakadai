#pragma once
#include "Vector.h"

class Enemy {
public:
	Enemy();
	void Initialize();

	void Updata();
	void Draw();

	void SetIsActive(int active);
	int GetIsActive();

	int GetScore();

	Vector2 GetPos();
	float GetRadius();

private:
	Vector2 pos_;
	float moveSpeed_;
	float radius_;
	int score_;
	int isActive_;



};

