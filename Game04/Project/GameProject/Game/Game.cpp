#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "GameData.h"
#include "UI.h"
//#include "Goal.h"
//#include "../Title/Title.h"

Game::Game() :Base(eType_Scene)
{
	//Base::Add(new Field());
	Base::Add(new Map());
	Base::Add(new UI1());
	
	
	
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
	if (!Base::FindObject(eType_Goal)) {
		SetKill();
	}
	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) /* && PUSH(CInput::eButton1)*/) {
		SetKill();
	}
}

