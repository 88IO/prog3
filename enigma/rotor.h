#ifndef ROTOR_H
#define ROTOR_H

// ローターの構造体
// プラグボード, スクランブラー, リフレクター に用いる
typedef struct {
    // 回転状態
    int rot;
    // 1回転時のフラグ
    int fullturn;
    // 変換表と逆変換表
    int table[26];
    int rtable[26];
} Rotor;

// 各パーツ用の初期化関数
Rotor plugboard(int swaps[][2]);
Rotor scrambler(int seed, int rot);
Rotor reflector(int seed);

// スクランブラーの回転用
void rotate(Rotor *sc);
// 1回転フラグの取得
int fullturn(Rotor *sc);

// 配列のシャッフル
// 変換表生成に用いる
void shuffle(int arr[], int size, int seed);

#endif
