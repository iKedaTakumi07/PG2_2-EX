#pragma once
#include "Vector2.h"

class Enemy {
public:
    /// <summary>
    /// コンストラクタの定義(初期化)
    /// </summary>
    Enemy();

    /// <summary>
    /// デストラクタの定義
    /// </summary>
    virtual ~Enemy();

    /// <summary>
    /// 更新処理
    /// </summary>
    virtual void Update();

    /// <summary>
    /// 描画処理
    /// </summary>
    virtual void Draw();

    virtual Vector2 GetEnemyPos() { return pos_; };

    virtual int GetRadiusyPos() { return radius; };

    /// <summary>
    /// 生存しているか設定する
    /// </summary>
    /// <param name="i"></param>
    /// <returns></returns>
    virtual int SetEnemyisAlive(int isEnemyAlive);

    virtual int GetEnemyisAlive() { return isAlive; };

protected:
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
