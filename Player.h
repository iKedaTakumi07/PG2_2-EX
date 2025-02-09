#pragma once
#include "Bullet.h"
#include "Vector2.h"
#include "data.h"

class Player {
private:
    Vector2 pos_; // 座標
    Vector2 velocity_; // 速度
    Vector2 acacceleration; // 加速度
    Vector2 move;
    Vector2 newMove;
    float length;
    int radius;
    int bulletShotCoolTime;
    int explosiontimer;
    int Life;

    // フラグ
    int isBulletShot;
    int isAlive;
    int isHit;

    // 包含
    Bullet* bullet_[10];
   

public:
    /// <summary>
    /// コンストラクタの定義(初期化)
    /// </summary>
    Player();

    /// <summary>
    /// デストラクタの定義
    /// </summary>
    ~Player();

    /// <summary>
    /// プレイヤーの更新処理
    /// </summary>
    /// <param name="keys">入力しているキー</param>
    /// <param name="prekeys">1フレーム前に入力したキー</param>
    void Update(char* keys, char* prekeys);

    /// <summary>
    /// プレイヤーの描画処理
    /// </summary>
    void Draw(const Imges& imges);

    /// <summary>
    /// 座標を取得する
    /// </summary>
    /// <returns></returns>
    Vector2 GetPlayerPos() { return pos_; };

    int GetPlayerRadius() { return radius; };

    int GetPlayerisAlive() { return isAlive; };

    int SetPlayerisHit(int isPlayerAlive);

    /// <summary>
    /// 弾の座標を取得する
    /// </summary>
    /// <returns></returns>
    Vector2 GetBulletPos(int i);

    /// <summary>
    /// 生存しているか設定する
    /// </summary>
    /// <param name="i">対象のアドレス</param>
    /// <param name="isAlive">生存させるか</param>
    /// <returns></returns>
    int SetBulletisAlive(int i, int isBulletAlive);

    /// <summary>
    /// 大きさを入手する
    /// </summary>
    /// <param name="i">対象のアドレス</param>
    /// <returns></returns>
    int GetBulletRadius(int i);

    /// <summary>
    /// 生存しているかを取得する
    /// </summary>
    /// <param name="i">対象のアドレス</param>
    /// <returns></returns>
    int GetBulletisAlive(int i);
};