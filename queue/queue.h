/**
 * @file queue.h
 * @brief キューのライブラリのヘッダファイル
 */
#ifndef QUEUE_H
#define QUEUE_H

/** キューを実現する構造体 */
typedef struct {
    int max;    /**< キューのサイズ */
    int num;    /**< 現在の要素数 */
    int front;  /**< 先頭要素カーソル */
    int rear;   /**< 末尾要素カーソル */
    int *que;   /**< キューの先頭要素へのポインタ */
} Queue;

/**
 * キューの初期化を行う
 *
 * @param[out] q キューのポインタ
 * @param[in] max キューのサイズ
 * @return int 0:初期化成功, -1:初期化失敗
 */
int QueueAlloc(Queue *q, int max);

/**
 * キューの解放を行う
 *
 * @param[out] q キューのポインタ
 */
void QueueFree(Queue *q);

/**
 * キューにデータを追加する
 *
 * @param[out] q キューのポインタ
 * @param[in] x 追加するデータ
 * @return int 0:追加成功, -1:追加失敗
 */
int QueueEnque(Queue *q, int x);

/**
 * キューからデータを削除する
 *
 * @param[out] q キューのポインタ
 * @param[out] x 削除したデータ
 * @return int 0:削除成功, -1:削除失敗
 */
int QueueDeque(Queue *q, int *x);

/**
 * キューの大きさを取得する
 *
 * @param[out] q キューのポインタ
 * @return int キューの大きさ
 */
int QueueSize(const Queue *q);

/**
 * キューに蓄えられているデータ数を取得する
 *
 * @param[out] q キューのポインタ
 * @return int キューに蓄えられているデータ数
 */
int QueueNo(const Queue *q);

/**
 * キューが空か判定
 *
 * @param[out] q キューのポインタ
 * @return int 1:空, 0:空でない
 */
int QueueIsEmpty(const Queue *q);

/**
 * キューが満杯か判定
 *
 * @param[out] q キューのポインタ
 * @return int 1:満杯, 0:満杯でない
 */
int QueueIsFull(const Queue *q);

#endif
