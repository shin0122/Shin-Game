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
	if (!Base::FindObject(eType_Goal)) {
		SetKill();
	}
	//�v���C���[���S�@�{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) /* && PUSH(CInput::eButton1)*/) {
		SetKill();
	}
}

