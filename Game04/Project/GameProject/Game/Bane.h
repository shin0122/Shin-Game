#pragma once
#include"../Base/Base.h"
class Bane :public Base {
private:
	//�摜�I�u�W�F�N�g
	CImage m_img;
public:
	Bane(const CVector2D& pos);
	void Draw();
};