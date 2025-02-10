#include "Player.h"
#include "Novice.h"
#include "math.h"

Player::Player()
{
    pos_ = { 620.0f, 600.0f };
    velocity_ = { 0.0f, 0.0f };
    acacceleration = { 0.0f, -2.1f };
    move = { 0.0f, 0.0f };
    newMove = { 0.0f, 0.0f };
    length = 0.0f;
    radius = 64;
    bulletShotCoolTime = 10;
    explosiontimer = 60;
    Life = 3;

    // フラグ
    isAlive = true;
    isHit = false;
    isBulletShot = false;

    for (int i = 0; i < 20; i++) {
        bullet_[i] = new Bullet();
    }
}

Player::~Player()
{
    for (int i = 0; i < 20; i++) {
        delete bullet_[i];
    }
}

void Player::Update(char* keys, char* prekeys)
{
    // 変数が(null)なら何もしない
    if (keys == nullptr || prekeys == nullptr) {
        return;
    }

    /* w, a, s, dを押したなら移動 */

    if (!isHit) {
        move = { 0.0f, 0.0f };

        if (keys[DIK_W]) {
            move.y = 1.0f;
            velocity_.y = -5.0f;
        }

        if (keys[DIK_S]) {
            move.y = 1.0f;
            velocity_.y = 5.0f;
        }

        if (keys[DIK_A]) {
            move.x = 1.0f;
            velocity_.x = -5.0f;
        }

        if (keys[DIK_D]) {
            move.x = 1.0f;
            velocity_.x = 5.0f;
        }

        // 横方向の正規化

        length = sqrtf(move.x * move.x + move.y * move.y);

        if (length != 0.0f) {
            newMove.x = move.x / length;
            newMove.y = move.y / length;

            pos_.x += newMove.x * velocity_.x;
            pos_.y += newMove.y * velocity_.y;
        }

        /* 弾の発射処理 */

        // 一部変更予定(setとgetのを作る)

        if (keys[DIK_SPACE]) {
            if (!isBulletShot) {
                int EnemyisAlive = false;

                for (int i = 0; i < 20; i++) {

                    EnemyisAlive = bullet_[i]->GetBulletisAlive();

                    if (!EnemyisAlive) {
                        // フラグをtrueに
                        isBulletShot = true;

                        // 座標をプレイヤーに合わせる
                        bullet_[i]->SetBulletPos(pos_, radius);

                        break;
                    }
                }
            }
        }

        // (連射可能の場合)発射のクールタイム
        if (isBulletShot) {
            bulletShotCoolTime--;
            if (bulletShotCoolTime <= 0) {

                // フラグをfalseに,クールタイムをリセット
                isBulletShot = false;
                bulletShotCoolTime = 5;
            }
        }
    }

    // 弾が発射されているなら更新処理をする
    for (int i = 0; i < 20; i++) {
        int EnemyisAlive = false;
        EnemyisAlive = bullet_[i]->GetBulletisAlive();

        if (EnemyisAlive) {
            bullet_[i]->Update();
        }
    }

    // その他

    if (isHit) {
        explosiontimer--;

        if (explosiontimer <= 0) {
            Life--;
            if (Life < 0) {
                isAlive = false;
            }
            isHit = false;
            explosiontimer = 60;
        }
    }
}

void Player::Draw(const Imges& imges)
{
    /* 描画処理 */
    for (int i = 0; i < 20; i++) {
        int EnemyisAlive = false;
        EnemyisAlive = bullet_[i]->GetBulletisAlive();

        if (EnemyisAlive) {
            bullet_[i]->Draw();
        }
    }

    // 残機
    if (Life >= 3) {
        Novice::DrawSprite(1000, 200, imges.playerGh, 1, 1, 0.0f, 0xFFFFFFFF);
    }
    if (Life >= 2) {
        Novice::DrawSprite(1064, 200, imges.playerGh, 1, 1, 0.0f, 0xFFFFFFFF);
    }
    if (Life >= 1) {
        Novice::DrawSprite(1128, 200, imges.playerGh, 1, 1, 0.0f, 0xFFFFFFFF);
    }


    // 　キャラ本人
    if (explosiontimer % 2 == 0) {

        Novice::DrawSprite(static_cast<int>(pos_.x), static_cast<int>(pos_.y), imges.playerGh, 1, 1, 0.0f, 0xFFFFFFFF);
    }
}

int Player::SetPlayerisHit(int isPlayerAlive)
{
    isHit = isPlayerAlive;
    return 0;
}

Vector2 Player::GetBulletPos(int i)
{
    Vector2 tragetC;

    tragetC = bullet_[i]->GetBulletPos();

    return tragetC;
}

int Player::SetBulletisAlive(int i, int isBulletAlive)
{
    bullet_[i]->SetBulletisAlive(isBulletAlive);
    return 0;
}

int Player::GetBulletRadius(int i)
{
    int tragetC;

    tragetC = bullet_[i]->GetBulletRadius();

    return tragetC;
}

int Player::GetBulletisAlive(int i)
{
    int tragetC;

    tragetC = bullet_[i]->GetBulletisAlive();

    return tragetC;
}
