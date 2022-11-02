#include "Bane.h"


Bane::Bane(const CVector2D& pos)
	:Base(eType_Bane)
{
	//-(画像の複製)-
	m_img = COPY_RESOURCE("Goal", CImage);
	m_pos = pos;
	//-(m_rectの設定など)-
	m_rect = CRect(-32, -128, 32, 0);
}

void Bane::Draw()
{
	//-(画像の設定)-
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}