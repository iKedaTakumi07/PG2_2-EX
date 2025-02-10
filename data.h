#pragma once
#include "Novice.h"

// 画像データ
struct Imges {
    int title = Novice::LoadTexture("./Resources/images/title.png");
    int playerGh = Novice::LoadTexture("./Resources/images/player.png");
    int bg = Novice::LoadTexture("./Resources/images/gb.png");
    int bg2 = Novice::LoadTexture("./Resources/images/bg2.png");
    int RESULT = Novice::LoadTexture("./Resources/images/RESULT.png");
    int ghnumber[10] = {
        Novice::LoadTexture("./Resources/images/number/number0.png"),
        Novice::LoadTexture("./Resources/images/number/number1.png"),
        Novice::LoadTexture("./Resources/images/number/number2.png"),
        Novice::LoadTexture("./Resources/images/number/number3.png"),
        Novice::LoadTexture("./Resources/images/number/number4.png"),
        Novice::LoadTexture("./Resources/images/number/number5.png"),
        Novice::LoadTexture("./Resources/images/number/number6.png"),
        Novice::LoadTexture("./Resources/images/number/number7.png"),
        Novice::LoadTexture("./Resources/images/number/number8.png"),
        Novice::LoadTexture("./Resources/images/number/number9.png")
    };

    int Score = Novice::LoadTexture("./Resources/images/number/score.png");
};

struct sound {
    int title = Novice::LoadAudio("./Resources/images/number/score.png");
};
