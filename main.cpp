#include "Enemy.h"
#include "EnemyA.h"
#include "Player.h"
#include "Vector2.h"
#include <Novice.h>
#include "EnemyBoss.h"

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
    Enemy* enemy[31];

    Scene sceneNumber = TITLE;

    Vector2 tragetPosA = { 0.0f, 0.0f };
    int tragetRadiusA = 0;
    int tragetisAliveA = 0;
    Vector2 tragetPosB[30] = { 0.0f, 0.0f };
    int tragetRadiusB[30] = { 0 };
    int tragetisAliveB[30] = { 0 };
    Vector2 tragetPosC[10] = { 0.0f, 0.0f };
    int tragetisAliveC[10] = { 0 };
    int tragetRadiusC[10] = { 0 };

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

                for (int i = 0; i < 30; i++) {
                    enemy[i] = new EnemyA;
                }
            }

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

            tragetPosA = player->GetPlayerPos();
            tragetRadiusA = player->GetPlayerRadius();

            for (int i = 0; i < 30; i++) {
                enemy[i]->Update();

                tragetPosB[i] = enemy[i]->GetEnemyPos();
                tragetRadiusB[i] = enemy[i]->GetRadiusyPos();
                tragetisAliveB[i] = enemy[i]->GetEnemyisAlive();

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

            for (int j = 0; j < 10; j++) {

                tragetisAliveC[j] = player->GetBulletisAlive(j);
                tragetRadiusC[j] = player->GetBulletRadius(j);

                if (tragetisAliveC[j]) {
                    tragetPosC[j] = player->GetBulletPos(j);

                    for (int z = 0; z < 30; z++) {

                        // 敵側の生存フラグ取得

                        if (tragetisAliveB[z]) {

                            if (tragetPosC[j].x + tragetRadiusC[j] > tragetPosB[z].x && tragetPosB[z].x + tragetRadiusB[z] > tragetPosC[j].x) {
                                if (tragetPosC[j].y + tragetRadiusC[j] > tragetPosB[z].y && tragetPosB[z].y + tragetRadiusB[z] > tragetPosC[j].y) {

                                    player->SetBulletisAlive(j, false);
                                    enemy[z]->SetEnemyisAlive(false);
                                }
                            }
                        }
                    }
                }
            }

            tragetisAliveA = player->GetPlayerisAlive();
            if (!tragetisAliveA) {

                delete player;
                for (int i = 0; i < 30; i++) {
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

            player->Draw();

            for (int i = 0; i < 30; i++) {
                enemy[i]->Draw();
            }

            ///
            /// ↑描画処理ここまで
            ///

            break;
        case RESULT:

            ///
            /// ↓更新処理ここから
            ///

            sceneNumber = TITLE;

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
