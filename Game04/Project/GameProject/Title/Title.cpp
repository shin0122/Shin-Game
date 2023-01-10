#include "Title.h"
#include "../Game/Game.h"
#include "../Game/Map.h"
#include"../Game/GameData.h"

Title::Title() :Base(eType_Scene), 
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) 
{
	m_img = COPY_RESOURCE("Title", CImage);
}
Title::~Title() {
	//全てのオブジェクトを破棄
	Base::KillAll();
	//ゲームシーンへ移行
	Base::Add(new Game());
}
void Title::Update() {
	//ボタン１でタイトルを破棄
	if (PUSH(CInput::eButton1)) {
		SetKill();
		GameData::stage = 1;
	}
	//ボタン2でタイトルを破棄
	if (PUSH(CInput::eButton2)) {
		SetKill();
		GameData::stage = 2;
	}
	//ボタン3でタイトルを破棄
	if (PUSH(CInput::eButton3)) {
		SetKill();
		GameData::stage = 3;
	}
	//ボタン4でタイトルを破棄
	if (PUSH(CInput::eButton4)) {
		SetKill();
		GameData::stage = 4;
	}
	//ボタン5でタイトルを破棄
	if (PUSH(CInput::eButton5)) {
		SetKill();
		GameData::stage = 5;
	}
}
void Title::Draw()
{
	m_img.Draw();
	//文字表示
	//m_title_text.Draw(1000 / 2, 514, 1, 0, 0, "Push [Z]");
}