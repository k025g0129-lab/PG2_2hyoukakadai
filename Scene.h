#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class Scene {
public:
	Scene();
	~Scene();
	void Initialize();

	void Updata();
	void Draw();

private:

	enum GameScene {
		TITLE,
		MAIN_GAME,
		RESULT,
	};

	GameScene gameScene;
	Player player;
	Bullet bullet = Bullet({-500.0f,-500.0f});


	static const int maxEnemy = 30;
	Enemy* enemy[maxEnemy];

	int score_;
	int isClear = false;

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };



};

