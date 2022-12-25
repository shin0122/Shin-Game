#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "GameData.h"
#include "UI.h"
#include "Goal.h"
#include"../Title/Gameclear.h"
#include"../Title/GameOver.h"

Game::Game() :Base(eType_Scene)
{
}
Game::~Game()
{
	//すべてのオブジェクトの破棄
	Base::KillAll();
	//タイトルシーンへ
	//Base::Add(new Title());
}
void Game::Update()
{
	//ゴールが無ければゲームシーン終了
	if (!Base::FindObject(eType_Goal))
	{
		if (GameClear_flag == false) {
			//一度だけ呼び出す
			Base::Add(new GameClear);
		}
		if (PUSH(CInput::eButton1))
			SetKill();
		GameClear_flag == true;
	}
	//リセットされる（タイトルに行くと）
	//プレイヤー死亡　Zでゲームシーン終了
	else if (!Base::FindObject(eType_Player)) {
		if (GameOver_flag == false) {
			Base::Add(new GameOver);
		}
		if (PUSH(CInput::eButton1))
			SetKill();
		GameOver_flag == true;
		//if (PUSH(CInput::eButton2))
	}
	//時間切れ　Zでゲームシーン終了
	else if (GameData::time == 1 ) {
		if (GameOver_flag == false) {
			//一度だけ呼び出す
			Base::Add(new GameOver);
		}
		if (PUSH(CInput::eButton1))
			SetKill();
		GameOver_flag == true;
		//if (PUSH(CInput::eButton2))
	}
	//0秒になったら
	else if (GameData::time == 0 && (PUSH(CInput::eButton1))) {
		SetKill();
	}
}