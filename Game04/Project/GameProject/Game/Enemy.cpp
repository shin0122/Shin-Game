#include "Enemy.h"
#include "Bullet.h"
Enemy::Enemy(const CVector2D& pos)
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_pos = pos;
	m_img.SetCenter(16, 16);
}
void Enemy::Update()
{

	m_cnt++;

	Base* b = Base::FindObject(eType_Player);

	if (b) {

		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 120) {
			Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 4));
			m_cnt = 0;

		}
	}

}
void Enemy::Collision(Base* b)
{
}
void Enemy::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}