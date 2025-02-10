#include "EnemyB.h"
#include "Novice.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "stdio.h"

EnemyB::EnemyB()
{
    pos_ = { static_cast<float>(rand() % 700 + 300), static_cast<float>(rand() % 700 - 800) };
    velocity = { 7.5f, 3.0f };
    acacceleration = { 0.0f, 0.0f };
    move = { 0.0f, 0.0f };
    newMove = { 0.0f, 0.0f };
    length = 0.0f;
    radius = 32;
    isAlive = false;
    respawntimer = 10;
}

EnemyB::~EnemyB()
{
}

void EnemyB::Update()
{
    if (isAlive) {

        pos_.y += velocity.y;
        if (pos_.y >= 760) {
            isAlive = false;
        }
    }

    if (!isAlive) {
        respawntimer--;
        if (respawntimer <= 0) {
            isAlive = true;
            respawntimer = 70;
            pos_ = { static_cast<float>(rand() % 700 + 200), static_cast<float>(rand() % 600 - 700) };
        }
    }
}

void EnemyB::Draw(const Imges& imges)
{
    if (isAlive) {
        /*  Novice::DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius), static_cast<int>(radius), 0.0f, 0xFF0000FF, kFillModeSolid);*/

        Novice::DrawSprite(static_cast<int>(pos_.x), static_cast<int>(pos_.y), imges.enemy, 1, 1, 0.0f, 0xFFFFFFFF);
    }
}

int EnemyB::SetEnemyisAlive(int isEnemyAlive)
{
    isAlive = isEnemyAlive;
    return 0;
}
