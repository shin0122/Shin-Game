#pragma once
#include "../Base/Base.h"

class Player : public Base {
	CImage m_img;
	bool m_is_ground;
public:
	Player(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};