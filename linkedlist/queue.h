/**
 * @file queue.h
 * @brief キューのライブラリのヘッダファイル
 */
#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"

/** キューを実現する構造体 */
typedef struct {
    int num;    /**< 現在の要素数 */
    Node *front;  /**< 先頭要素カーソル */
    Node *rear;   /**< 末尾要素カーソル */
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
 * キューにデータを追加する
 *
 * @param[out] q キューのポインタ
 * @param[in] x 追加するデータ
 * @return int 0:追加成功, -1:追加失敗
 */
int QueueEnque(Queue *q, Node *x);

/**
 * キューからデータを削除する
 *
 * @param[out] q キューのポインタ
 * @return Node* 削除したデータ
 */
Node *QueueDeque(Queue *q);

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

void PrintQueue(Queue *q);

#endif
