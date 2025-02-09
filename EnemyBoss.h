#pragma once
#include "Enemy.h"

class EnemyBoss : public Enemy {
public:
    /// <summary>
    /// コンストラクタの定義(初期化)
    /// </summary>
    EnemyBoss();

    /// <summary>
    /// デストラクタの定義
    /// </summary>
    ~EnemyBoss() override;

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update() override;

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw() override;

    int SetBossIsArrival(int BossisArrival) override;

private:
    Vector2 pos_;
    Vector2 velocity; // 速度
    Vector2 acacceleration; // 加速度
    Vector2 move;
    Vector2 newMove;
    float length;
    int radius;
    int BossIsArrival;
    int isAlive;
    int respawntimer;
};
