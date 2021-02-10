/**
 * @file test_queue.c
 * @brief キューのライブラリの動作確認コード
 */
#include <stdio.h>
#include "queue.h"

int main(void) {
    // 2つのキューを用意
    Queue q1, q2;

    // q1を初期化
    QueueAlloc(&q1, 3);

    // q1が空か満杯か判定（空のはず）
    if (QueueIsEmpty(&q1))  printf("q1は空です\n");
    if (QueueIsFull(&q1))  printf("q1は満杯です\n");

    // q1にデータを追加（q1の大きさが3なので出力は3回、1回は失敗するはず）
    if (QueueEnque(&q1, 1) == 0)  printf("正常に追加されました\n");
    if (QueueEnque(&q1, 2) == 0)  printf("正常に追加されました\n");
    if (QueueEnque(&q1, 3) == 0)  printf("正常に追加されました\n");
    if (QueueEnque(&q1, 4) == 0)  printf("正常に追加されました\n");

    // q2にデータを追加（初期化していないので失敗するはず）
    if (QueueEnque(&q2, 1) == 0)  printf("正常に追加されました\n");

    // q1が空か満杯か判定（満杯のはず）
    if (QueueIsEmpty(&q1))  printf("q1は空です\n");
    if (QueueIsFull(&q1))  printf("q1は満杯です\n");

    // 削除データを格納する変数x
    int x;
    // q1からデータを削除（q1のデータ数は3なので出力は3回(1,2,3)、1回は失敗するはず）
    if (QueueDeque(&q1, &x) == 0)  printf("%dを取り出しました\n", x);
    if (QueueDeque(&q1, &x) == 0)  printf("%dを取り出しました\n", x);
    if (QueueDeque(&q1, &x) == 0)  printf("%dを取り出しました\n", x);
    if (QueueDeque(&q1, &x) == 0)  printf("%dを取り出しました\n", x);

    // q1にデータを2つ追加
    if (QueueEnque(&q1, 5) == 0)  printf("正常に追加されました\n");
    if (QueueEnque(&q1, 6) == 0)  printf("正常に追加されました\n");

    // q1の大きさ,データ数を出力（大きさ3,データ数2のはず）
    printf("q1の大きさは%d, データ数は%dです\n",
            QueueSize(&q1), QueueNo(&q1));

    // q1からデータを1つ削除
    if (QueueDeque(&q1, &x) == 0)  printf("%dを取り出しました\n", x);

    // q1の大きさ,データ数を出力（大きさ3,データ数1のはず）
    printf("q1の大きさは%d, データ数は%dです\n",
            QueueSize(&q1), QueueNo(&q1));

    // q1の解放
    printf("q1の利用終了\n");
    QueueFree(&q1);

    // q1にデータを追加（q1は解放済なので失敗するはず）
    if (QueueEnque(&q1, 7) == 0)  printf("正常に追加されました\n");

    return 0;
}
