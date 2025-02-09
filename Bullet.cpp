#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet()
{
    pos_ = { 0.0f, 0.0f };
    speed_ = { 0.0f, -10.0f };
    radius_ = 10;

    // フラグ
    isAlive = false;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
    /* 移動処理 */

    if (isAlive) {
        pos_.y += speed_.y;

        // 画面外に出たらフラグをfalseに
        if (pos_.y <= 0) {
            isAlive = false;
        }
    }
}

void Bullet::Draw()
{
    Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), radius_, radius_, 0.0f, BLUE, kFillModeSolid);
}

void Bullet::SetBulletPos(Vector2 Pos, int Radius)
{
    pos_.x = Pos.x + (Radius / 2.0f);
    pos_.y = Pos.y + (Radius / 2.0f);
    isAlive = true;
}

int Bullet::SetBulletisAlive(int EnemyisAlive)
{
    isAlive = EnemyisAlive;
    return 0;
}
