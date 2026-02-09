#pragma once
#include "Vector.h"
#include "Bullet.h"

class Player {
public:
	Player();
	void Initialize();

	void Updata();
	void Draw();

	Vector2 GetPos();
	float GetRadius();

	int GetIsSpecial();

	Bullet bullet = Bullet({ -500.0f,-500.0f });


private:
	Vector2 pos_;
	float moveSpeed_;
	float radius_;
	int coolTime_;
	int specialTime_;
	int isSpecial_;


	char keys[256] = { 0 };
	char preKeys[256] = { 0 };


	enum RGBColor {
		Red,
		Yellow,
		Green,
		Cyan,
		Blue,
		Magenta,
	};

	RGBColor rGBColor = Red;
	int R = 255;
	int G = 0;
	int B = 0;

	int color_ = 0xFF0000FF;
};

