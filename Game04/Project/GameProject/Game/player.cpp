#include "Player.h"
#include "Bullet.h"
#include "Map.h"
#include "UI.h"

Player::Player(const CVector2D& pos)
    :Base(eType_Player)
{
    m_img = COPY_RESOURCE("Player", CImage);
    m_pos = pos;
    //中心を設定
    m_img.SetCenter(16, 16);
    //矩形を設定
    m_rect = CRect(-14,-14,14,14);
    //半径
    m_rad = 14;
    m_vec.x = 6;
    m_start = false;
}
void Player::Update()
{
    m_pos_old = m_pos;

    if (m_start == false)
    return;

    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;

    //重力による落下
    m_vec.y += GRAVITY;
    m_pos += m_vec;

    //スクロール設定
  // m_scroll.x = m_pos.x - 1280 / 2;
   //m_scroll.y = m_pos.y - 600;

    //マウスのベクトル
   // CVector2D vec = CInput::GetMousePoint() - m_pos;
    //回転値を逆算
   // m_ang = atan2(vec.x, vec.y);

    if (PUSH(CInput::eMouseL)) {
        Base::Add(new Bullet(eType_Player_Bullet, m_pos, m_ang, 4));
    }
}
void Player::Collision(Base* b)
{
    switch (b->m_type) {
        //ゴール判定
    case eType_Goal:
        if (Base::CollisionRect(this, b)) {
            b->SetKill();
        }
        break;

    case eType_Field:
        if (Map* m = dynamic_cast<Map*>(b)) {
            int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect);
            if (t != 0) {
                m_pos.x = m_pos_old.x;
                m_vec.x *= -1;
            }
            t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect);
            if (t != 0) {
                m_pos.y = m_pos_old.y;
                m_vec.y = 0;
            }

        }
    }
}
void Player::Draw() {
    m_img.SetPos(m_pos);
    m_img.SetAng(m_ang);
    m_img.Draw();
}