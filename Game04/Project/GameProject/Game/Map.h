#pragma once

#include "../Base/Base.h"
#include "GameData.h"

#define MAP_WIDTH       40
#define MAP_HEIGHT      22
#define MAP_TIP_SIZE    32

class Map : public Base {
private:
	CImage m_img;
public:
	Map();
	void Draw();
	//�w����W�̃`�b�v�ԍ����擾
	int GetTip(const CVector2D& pos);
	//�w���A�w��s�̃}�b�v�`�b�v���擾
	int GetTip(int col, int raw);
	void SetTip(const CVector2D& pos, int t);
	//�}�b�v�Ƃ̓����蔻��
	int CollisionMap(const CVector2D& pos);
	int CollisionMap(const CVector2D& pos, const CRect& rect);
};