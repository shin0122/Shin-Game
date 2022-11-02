#include "Bane.h"


Bane::Bane(const CVector2D& pos)
	:Base(eType_Bane)
{
	//-(�摜�̕���)-
	m_img = COPY_RESOURCE("Goal", CImage);
	m_pos = pos;
	//-(m_rect�̐ݒ�Ȃ�)-
	m_rect = CRect(-32, -128, 32, 0);
}

void Bane::Draw()
{
	//-(�摜�̐ݒ�)-
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}