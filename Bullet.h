#pragma once
#include "Vector.h"

class Bullet {
public:

	Bullet(Vector2 pos);
	void Initialize(Vector2 pos);

	void Updata();
	void Draw();

	void SetIsActive(int isActive);
	int GetIsActive();

	Vector2 GetPos();
	float GetRadius();

private:
	Vector2 pos_;
	float moveSpeed_;
	float radius_;
	int isActive_ = false;


	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

};

