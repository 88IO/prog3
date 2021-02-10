/**
 * @file queue.h
 * @brief 線形リストを用いたキューのヘッダファイル
 */
#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"

/** キューを実現する構造体 */
typedef struct {
    int num;    /**< 現在の要素数 */
    Node *front;  /**< 先頭ノードへのポインタ */
    Node *rear;   /**< 末尾ノードへのポインタ */
} Queue;

/**
 * キューの初期化を行う
 *
 * @param[out] q キューのポインタ
 * @return int 0:初期化成功, -1:初期化失敗
 */
int QueueInit(Queue *q);

/**
 * キューの解放を行う
 *
 * @param[out] q キューのポインタ
 */
void QueueFree(Queue *q);

/**
 * ノードを追加する
 *
 * @param[out] q キューのポインタ
 * @param[in] x 追加ノードへのポインタ
 * @return int 0:追加成功, -1:追加失敗
 */
int QueueEnque(Queue *q, Node *x);

/**
 * ノードを削除する
 *
 * @param[out] q キューのポインタ
 * @return Node 削除したノードへのポインタ
 */
Node *QueueDeque(Queue *q);

/**
 * キューに蓄えられているデータ数を取得する
 *
 * @param[in] q キューのポインタ
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
 * キューの中身を表示
 *
 * @param[out] q キューのポインタ
 */
void PrintQueue(Queue *q);

#endif
