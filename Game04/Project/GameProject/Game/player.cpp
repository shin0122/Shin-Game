#include "Player.h"
#include "Bullet.h"
#include "Map.h"
#include "UI.h"

Player::Player(const CVector2D& pos)
    :Base(eType_Player)
{
    m_img = COPY_RESOURCE("Player", CImage);
    m_pos = pos;
    //���S��ݒ�
    m_img.SetCenter(16, 16);
    //��`��ݒ�
    m_rect = CRect(-14,-14,14,14);
    //���a
    m_rad = 14;
    m_vec.x = 4;
    m_start = false;
}

void Player::Update()
{
    m_pos_old = m_pos;
    if (m_start == false)
    return;

    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;

    //�d�͂ɂ�闎��
    m_vec.y += GRAVITY;
    m_pos += m_vec;

    //�}�E�X�̃x�N�g��
   // CVector2D vec = CInput::GetMousePoint() - m_pos;
    //��]�l���t�Z
   // m_ang = atan2(vec.x, vec.y);
    
    if (PUSH(CInput::eMouseL)) {
        Base::Add(new Bullet(eType_Player_Bullet, m_pos, m_ang, 4));
    }
}

void Player::Collision(Base* b)
{
    switch (b->m_type) {
        //�S�[������
    case eType_Goal:
        if (Base::CollisionRect(this, b)) {
            b->SetKill();
        }
        break;

        //�}�b�v�`�b�v�̐ݒ�--------------------------
    case eType_Field:
        if (Map* m = dynamic_cast<Map*>(b)) {
            int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect);
            if (t != 0) {
                m_pos.x = m_pos_old.x;
                m_vec.x *= -1;
            }
            t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect);
            if (t == 3) {
                m_pos.y = m_pos_old.y;
                m_vec.y = -12;
            }
            else if (t == 4) {
                m_pos.y = m_pos_old.y;
                m_vec.y = -18;
            }
            else if (t != 0) {
                m_pos.y = m_pos_old.y;
                m_vec.y = 0;
            }
        }//--------------------------------
    }
}

void Player::Draw() {
    m_img.SetPos(m_pos);
    m_img.SetAng(m_ang);
    m_img.Draw();
}