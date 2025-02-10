#include "Enemy.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "Player.h"
#include "Vector2.h"
#include "data.h"
#include <Novice.h>

const char kWindowTitle[] = "LC1B_02_イケダ_タクミ_PG2_評価課題";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    // ============================================
    // スクリーン画面の初期化
    // ============================================

    enum Scene {
        TITLE,
        MENU,
        COLLECTION,
        RESULT,
    };

    Player* player = new Player();
    Enemy* enemy[20];
    Imges imges;

    Scene sceneNumber = TITLE;

    Vector2 tragetPosA = { 0.0f, 0.0f };
    int tragetRadiusA = 0;
    int tragetisAliveA = 0;
    Vector2 tragetPosB[20] = { 0.0f, 0.0f };
    int tragetRadiusB[20] = { 0 };
    int tragetisAliveB[20] = { 0 };
    Vector2 tragetPosC[20] = { 0.0f, 0.0f };
    int tragetisAliveC[20] = { 0 };
    int tragetRadiusC[20] = { 0 };
    int score = 0;
    int targetScore = 0;
    int arrayScore[8] = { 0 };

    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        // キー入力を受け取る
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        switch (sceneNumber) {
        case TITLE:

            ///
            /// ↓更新処理ここから
            ///

            if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
                sceneNumber = COLLECTION;

                // 初期化
                player = new Player();
                score = 0;
                for (int i = 0; i < 8; i++) {
                    arrayScore[i] = { 0 };
                }

                for (int i = 0; i < 20; i++) {
                    if (i < 10) {
                        enemy[i] = new EnemyA;
                    } else {
                        enemy[i] = new EnemyB;
                    }
                }
            }

            ///
            /// ↑更新処理ここまで
            ///

            ///
            /// ↓描画処理ここから
            ///

            Novice::DrawSprite(0, 0, imges.bg, 1, 1, 0.0f, 0xbbbbbbFF);
            Novice::DrawSprite(0, 0, imges.title, 1, 1, 0.0f, 0xbbbbbbFF);

            ///
            /// ↑描画処理ここまで
            ///

            break;
        case MENU:

            ///
            /// ↓更新処理ここから
            ///

            ///
            /// ↑更新処理ここまで
            ///

            ///
            /// ↓描画処理ここから
            ///

            ///
            /// ↑描画処理ここまで
            ///

            break;
        case COLLECTION:

            ///
            /// ↓更新処理ここから
            ///

            // 更新処理
            player->Update(keys, preKeys);

            // 座標を取得する
            tragetPosA = player->GetPlayerPos();
            tragetRadiusA = player->GetPlayerRadius();

            for (int i = 0; i < 20; i++) {
                enemy[i]->Update();

                // 座標を取得する
                tragetPosB[i] = enemy[i]->GetEnemyPos();
                tragetRadiusB[i] = enemy[i]->GetRadiusyPos();
                tragetisAliveB[i] = enemy[i]->GetEnemyisAlive();

                // プレイヤーと敵
                if (tragetisAliveB[i]) {
                    // 当たり判定
                    if (tragetPosA.x + tragetRadiusA > tragetPosB[i].x && tragetPosB[i].x + tragetRadiusB[i] > tragetPosA.x) {
                        if (tragetPosA.y + tragetRadiusA > tragetPosB[i].y && tragetPosB[i].y + tragetRadiusB[i] > tragetPosA.y) {

                            enemy[i]->SetEnemyisAlive(false);
                            player->SetPlayerisHit(true);
                        }
                    }
                }
            }

            // 敵とプレイヤーの弾
            for (int j = 0; j < 20; j++) {

                // フラグ,半径を取得する
                tragetisAliveC[j] = player->GetBulletisAlive(j);
                tragetRadiusC[j] = player->GetBulletRadius(j);

                if (tragetisAliveC[j]) {
                    // 座標を取得する
                    tragetPosC[j] = player->GetBulletPos(j);

                    for (int z = 0; z < 20; z++) {

                        // 敵側の生存フラグ取得
                        if (tragetisAliveB[z]) {

                            // 当たっているなら生存をfalseに
                            if (tragetPosC[j].x + tragetRadiusC[j] > tragetPosB[z].x && tragetPosB[z].x + tragetRadiusB[z] > tragetPosC[j].x) {
                                if (tragetPosC[j].y + tragetRadiusC[j] > tragetPosB[z].y && tragetPosB[z].y + tragetRadiusB[z] > tragetPosC[j].y) {
                                    score += 50;
                                    player->SetBulletisAlive(j, false);
                                    enemy[z]->SetEnemyisAlive(false);
                                }
                            }
                        }
                    }
                }
            }

            // ===========================================
            // スコアの表示(可能ならクラス化)
            // ===========================================
            targetScore = score;

            arrayScore[0] = targetScore / 10000000;
            targetScore %= 10000000;

            arrayScore[1] = targetScore / 1000000;
            targetScore %= 1000000;

            arrayScore[2] = targetScore / 100000;
            targetScore %= 100000;

            arrayScore[3] = targetScore / 10000;
            targetScore %= 10000;

            arrayScore[4] = targetScore / 1000;
            targetScore %= 1000;

            arrayScore[5] = targetScore / 100;
            targetScore %= 100;

            arrayScore[6] = targetScore / 10;
            targetScore %= 10;

            arrayScore[7] = targetScore;

            // プレイヤーの残機が0ならリザルトに
            tragetisAliveA = player->GetPlayerisAlive();
            if (!tragetisAliveA) {

                delete player;
                for (int i = 0; i < 20; i++) {
                    delete enemy[i];
                }
                sceneNumber = RESULT;

                break;
            }

            ///
            /// ↑更新処理ここまで
            ///

            ///
            /// ↓描画処理ここから
            ///

            Novice::DrawSprite(0, 0, imges.bg, 1, 1, 0.0f, 0x666666FF);
            Novice::DrawSprite(1000, 0, imges.bg2, 1, 1, 0.0f, 0xffffffff);

            // スコア
            Novice::DrawSprite(1000, 265, imges.Score, 1, 1, 0.0f, 0xFFFFFFFF);

            for (int i = 0; i < 8; i++) {
                Novice::DrawSprite(1000 + (i * 32), 300, imges.ghnumber[arrayScore[i]], 2, 2, 0.0f, 0xFFFFFFFF);
            }

            player->Draw(imges);

            for (int i = 0; i < 20; i++) {
                enemy[i]->Draw(imges);
            }

            ///
            /// ↑描画処理ここまで
            ///

            break;
        case RESULT:

            ///
            /// ↓更新処理ここから
            ///

            if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
                sceneNumber = TITLE;
            }

            ///
            /// ↑更新処理ここまで
            ///

            ///
            /// ↓描画処理ここから
            ///

            Novice::DrawSprite(0, 0, imges.bg, 1, 1, 0.0f, 0x666666FF);
            Novice::DrawSprite(0, 0, imges.RESULT, 1, 1, 0.0f, 0xFFFFFFFF);

            // スコア
            Novice::DrawSprite(360, 300, imges.Score, 1, 1, 0.0f, 0xFFFFFFFF);

            for (int i = 0; i < 8; i++) {
                Novice::DrawSprite(510 + (i * 32), 300, imges.ghnumber[arrayScore[i]], 2, 2, 0.0f, 0xFFFFFFFF);
            }

            ///
            /// ↑描画処理ここまで
            ///

            break;
        }

        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}
