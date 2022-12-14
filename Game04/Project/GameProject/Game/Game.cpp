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
	//���ׂẴI�u�W�F�N�g�̔j��
	Base::KillAll();
	//�^�C�g���V�[����
	//Base::Add(new Title());
}
void Game::Update()
{
	//�S�[����������΃Q�[���V�[���I��
	if (!Base::FindObject(eType_Goal))
	{
		if (GameClear_flag == false) {
			//��x�����Ăяo��
			Base::Add(new GameClear);
		}
		if (PUSH(CInput::eButton1))
			SetKill();
		GameClear_flag == true;
	}
	//���Z�b�g�����i�^�C�g���ɍs���Ɓj
	//�v���C���[���S�@Z�ŃQ�[���V�[���I��
	else if (GameData::time == 1 ) {
		if (GameOver_flag == false) {
			//��x�����Ăяo��
			Base::Add(new GameOver);
		}
		if (PUSH(CInput::eButton1))
			SetKill();
		GameOver_flag == true;
		//if (PUSH(CInput::eButton2))
	}
	//0�b�ɂȂ�����
	else if (GameData::time == 0 && (PUSH(CInput::eButton1))) {
		SetKill();
	}
}