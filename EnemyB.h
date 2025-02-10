#pragma once
#include "Enemy.h"
#include "data.h"
class EnemyB : public Enemy {
public:
    /// <summary>
    /// コンストラクタの定義(初期化)
    /// </summary>
    EnemyB();

    /// <summary>
    /// デストラクタの定義
    /// </summary>
    ~EnemyB() override;

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update() override;

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw(const Imges& imges) override;

    Vector2 GetEnemyPos() { return pos_; };

    int GetRadiusyPos() { return radius; };

    /// <summary>
    /// 生存しているか設定する
    /// </summary>
    /// <param name="i"></param>
    /// <returns></returns>
    int SetEnemyisAlive(int isEnemyAlive) override;

    int GetEnemyisAlive() { return isAlive; };

private:
    Vector2 pos_;
    Vector2 velocity; // 速度
    Vector2 acacceleration; // 加速度
    Vector2 move;
    Vector2 newMove;
    float length;
    int radius;
    int isAlive;
    int respawntimer;
};
