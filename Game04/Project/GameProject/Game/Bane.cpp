#include "Bane.h"


Bane::Bane(const CVector2D& pos)
	:Base(eType_Bane)
{
	//-(‰æ‘œ‚Ì•¡»)-
	m_img = COPY_RESOURCE("Goal", CImage);
	m_pos = pos;
	//-(m_rect‚Ìİ’è‚È‚Ç)-
	m_rect = CRect(-32, -128, 32, 0);
}

void Bane::Draw()
{
	//-(‰æ‘œ‚Ìİ’è)-
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}