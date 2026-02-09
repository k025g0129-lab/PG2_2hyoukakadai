#include "Scene.h"
#include <Novice.h>
#include "Function.h"


Scene::Scene() {
	Initialize();

}

Scene::~Scene() {
	for (int i = 0; i < maxEnemy; i++) {
		delete enemy[i];
	}

}

void Scene::Initialize() {
	gameScene = TITLE;
	score_ = 0;
	isClear = false;


	for (int i = 0; i < maxEnemy; i++) {
		enemy[i] = new Enemy();
	}
}

void Scene::Updata() {
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);


	switch (gameScene) {
	case Scene::TITLE:
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			gameScene = MAIN_GAME;
		}

		break;
	case Scene::MAIN_GAME:

		player.Updata();
		for (int i = 0; i < maxEnemy; i++) {
			if (enemy[i]->GetIsActive()) {
				enemy[i]->Updata();
			}

			if (!enemy[i]->GetIsActive()) {
				enemy[i]->Initialize();
			}

		}	
		bullet.Updata();



		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			if (!bullet.GetIsActive()) {
				bullet.Initialize(player.GetPos());
				bullet.SetIsActive(true);
			}

		}


		//========================================================================================
		//当たり判定
		//========================================================================================
		
		
		for (int i = 0; i < maxEnemy; i++) {
			//敵と弾
			if (circleToCircleHitJudge(bullet.GetPos(),enemy[i]->GetPos(),bullet.GetRadius(),enemy[i]->GetRadius())) {
				score_ += enemy[i]->GetScore();
				bullet.Initialize({-500.0f,-500.0f});
				enemy[i]->Initialize();

			}

			//敵とプレイヤー
			if (circleToCircleHitJudge(player.GetPos(), enemy[i]->GetPos(), player.GetRadius(), enemy[i]->GetRadius())) {
				isClear = false;
				gameScene = RESULT;

			}


		}




		//クリア判定
		if (score_ >= 10) {
			isClear = true;
			gameScene = RESULT;
		}

		break;



	case Scene::RESULT:
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			gameScene = MAIN_GAME;
			player.Initialize();
			bullet.Initialize({ -500.0f, -500.0f });
			for (int i = 0; i < maxEnemy; i++) {
				enemy[i]->Initialize();
			}
			Initialize();
		}

		break;
	default:
		break;
	}



}

void Scene::Draw() {
	switch (gameScene) {
	case Scene::TITLE:
		Novice::ScreenPrintf(300, 320, "[ta i to ru na nn ka ne xe yo]");
		Novice::ScreenPrintf(300, 340, "PlayGame To Press Space Key");
		break;
	case Scene::MAIN_GAME:

		bullet.Draw();

		for (int i = 0; i < maxEnemy; i++) {
			enemy[i]->Draw();
		}

		player.Draw();


		Novice::ScreenPrintf(0, 0, "score = %d", score_);
		Novice::ScreenPrintf(0, 20, "bullet = %d", bullet.GetIsActive());
		break;

	case Scene::RESULT:
		if (isClear) {
			Novice::ScreenPrintf(300, 300, "Game Clear");
		} else {
			Novice::ScreenPrintf(300, 300, "Game Over");
		}
		Novice::ScreenPrintf(300, 320, "score = %d", score_);
		Novice::ScreenPrintf(300, 340, "BACK TITLE Press Space Key");

		break;


	default:
		break;
	}

}
