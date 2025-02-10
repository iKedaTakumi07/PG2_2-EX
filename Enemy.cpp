#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy()
{
    pos_ = { 300.0f, 100.0f };
    velocity = { 5.0f, 5.0f };
    acacceleration = { 0.0f, 0.0f };
    move = { 0.0f, 0.0f };
    newMove = { 0.0f, 0.0f };
    length = 0.0f;
    radius = 20;
    isAlive = false;
    respawntimer = 0;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
}

void Enemy::Draw(const Imges& imges)
{

      Novice::DrawSprite(static_cast<int>(pos_.x), static_cast<int>(pos_.y), imges.enemy, 1, 1, 0.0f, 0xFFFFFFFF);
 /*   Novice::DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius), static_cast<int>(radius), 0.0f, 0xFF0000FF, kFillModeSolid);*/
}

int Enemy::SetEnemyisAlive(int isEnemyAlive)
{
    isAlive = isEnemyAlive;
    return 0;
}

