#pragma once
#include"../Base/Base.h"
class Bane :public Base {
private:
	//画像オブジェクト
	CImage m_img;
public:
	Bane(const CVector2D& pos);
	void Draw();
};