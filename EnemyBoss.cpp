#include "EnemyBoss.h"
#include "Novice.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "stdio.h"

EnemyBoss::EnemyBoss()
{
    pos_ = { 200, -200 };
    velocity = { 5.0f, 3.0f };
    acacceleration = { 0.0f, 5.0f };
    move = { 0.0f, 0.0f };
    newMove = { 0.0f, 0.0f };
    length = 0.0f;
    radius = 400;
    isAlive = false;
    respawntimer = 10;
    BossIsArrival = false;
}

EnemyBoss::~EnemyBoss()
{
}

void EnemyBoss::Update()
{
    if (BossIsArrival) {
    }
}

void EnemyBoss::Draw()
{
    if (BossIsArrival) {


    }
}

int EnemyBoss::SetBossIsArrival(int BossisArrival)
{

    BossIsArrival = BossisArrival;

    return 0;
}
