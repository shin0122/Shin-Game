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
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�Q�[���V�[���ֈڍs
	Base::Add(new Game());
}
void Title::Update() {
	//�{�^���P�Ń^�C�g����j��
	if (PUSH(CInput::eButton1)) {
		SetKill();
		GameData::stage = 1;
	}
	//�{�^��2�Ń^�C�g����j��
	if (PUSH(CInput::eButton2)) {
		SetKill();
		GameData::stage = 2;
	}
	//�{�^��3�Ń^�C�g����j��
	if (PUSH(CInput::eButton3)) {
		SetKill();
		GameData::stage = 3;
	}
	//�{�^��4�Ń^�C�g����j��
	if (PUSH(CInput::eButton4)) {
		SetKill();
		GameData::stage = 4;
	}
	//�{�^��5�Ń^�C�g����j��
	if (PUSH(CInput::eButton5)) {
		SetKill();
		GameData::stage = 5;
	}
}
void Title::Draw()
{
	m_img.Draw();
	//�����\��
	//m_title_text.Draw(1000 / 2, 514, 1, 0, 0, "Push [Z]");
}