#pragma once
#include "Vector2.h"

class Bullet {
private:
    Vector2 pos_;
    Vector2 speed_;
    int radius_;

    // フラグ
    int isAlive;

public:
    /// <summary>
    /// コンストラクタの定義(初期化)
    /// </summary>
    Bullet();

    /// <summary>
    /// デストラクタの定義
    /// </summary>
    ~Bullet();

    /// <summary>
    /// 弾の更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 弾の描画処理
    /// </summary>
    void Draw();

    /// <summary>
    /// 弾の座標を設定する
    /// </summary>
    /// <param name="pos_">プレイヤーの座標</param>
    /// <param name="radius">プレイヤーの半径</param>
    void SetBulletPos(Vector2 pos_, int radius);

    int GetBulletisAlive() { return isAlive; };

    int GetBulletRadius() { return radius_; };

    /// <summary>
    /// 弾の座標を取得する
    /// </summary>
    /// <returns></returns>
    Vector2 GetBulletPos() { return pos_; };

    /// <summary>
    /// 生存しているか設定する
    /// </summary>
    /// <returns></returns>
    int SetBulletisAlive(int isAlive);

};