#include <stdlib.h>
#include <stdio.h>
#include "rotor.h"

// プラグボード
Rotor plugboard(int swaps[][2]) {
    Rotor rt;

    // 無変換表
    int i;
    for (i = 0; i < 26; i++)  rt.table[i] = i;

    // 引数で受け付けたキーの組み合わせで入れ替え
    // 0 ~ 25, a ~ z の両方に対応
    int size = sizeof(*swaps) / sizeof(*swaps[0]);
    for (i = 0; i < size; i++) {
        rt.table[swaps[i][0] % 'a'] = swaps[i][1] % 'a';
        rt.table[swaps[i][1] % 'a'] = swaps[i][0] % 'a';
    }

    return rt;
}

// スクランブラー
Rotor scrambler(int seed, int rot) {
    Rotor rt;

    // 初期回転状態
    rt.rot = rot;
    rt.fullturn = 0;

    // 変換表を生成
    int i;
    for (i = 0; i < 26; i++)  rt.table[i] = i;
    shuffle(rt.table, 26, seed);

    // 逆変換表の生成
    for (i = 0; i < 26; i++)  rt.rtable[rt.table[i]] = i;

    return rt;
}

// リフレクター
Rotor reflector(int seed) {
    Rotor rt;

    // 無変換表の生成
    // 逆変換表は直接用いない
    int i;
    for (i = 0; i < 26; i++)  rt.rtable[i] = i;

    // シードを基にシャッフル
    shuffle(rt.rtable, 26, seed);

    // 配列から2要素ずつ取り出してペアにする
    // リフレクターの対応関係構築
    for (i = 0; i < 26; i += 2) {
        rt.table[rt.rtable[i]] = rt.rtable[i + 1];
        rt.table[rt.rtable[i + 1]] = rt.rtable[i];
    }

    return rt;
}

// スクランブラーを回転
void rotate(Rotor *rt) {
    // 回転状態を更新
    rt->rot = (rt->rot + 1) % 26;
    // 1回転したらフラグを立てる
    if (rt->rot == 0)  rt->fullturn = 1;
    else rt->fullturn = 0;

    // 変換表の更新
    int tmp = rt->table[0];
    int i;
    for (i = 0; i < 25; i++)  rt->table[i] = rt->table[i + 1];
    rt->table[25] = tmp;
    for (i = 0; i < 26; i++)  rt->rtable[rt->table[i]] = i;
}

// スクランブラーがちょうど１回転したか判別
int fullturn(Rotor *rt) {
    // 1回転のフラグが上がっていたら下げて1を返却
    if (rt->fullturn) {
        rt->fullturn = 0;
        return 1;
    }
    return 0;
}

// 配列のランダムシャッフル
// エニグマの変換表作成
void shuffle(int arr[], int size, int seed) {
    // シードで変換表を固定
    srand(seed);
    int i;
    for (i = 0; i < size; i++) {
        int j = rand() % size;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
