#pragma once
#include "Vector.h"

class Player {
public:
	Player();
	void Initialize();

	void Updata();
	void Draw();

	Vector2 GetPos();
	float GetRadius();

private:
	Vector2 pos_;
	float moveSpeed_;
	float radius_;


	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

};

