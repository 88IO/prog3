/**
 * @file queue.c
 * @brief キューのライブラリのソースファイル
 */
#include <stdlib.h>
#include "queue.h"
#include "linkedlist.h"

int QueueInit(Queue *q) {
    q->num = 0;
    q->front = NULL;
    q->rear = NULL;

    return 0;
}

void QueueFree(Queue *q) {
    TermList(&q->front);
}

int QueueEnque(Queue *q, Node *x) {
    if (q->num == 0)  q->front = x;
    else  q->rear->next = x;
    q->rear = x;
    q->num++;

    return 0;
}

Node *QueueDeque(Queue *q) {
    if (q->num == 0)  return NULL;

    Node *x = q->front;
    q->front = q->front->next;
    if (q->num == 1)  q->rear = NULL;
    q->num--;

    return x;
}

int QueueNo(const Queue *q) {
    return q->num;
}

int QueueIsEmpty(const Queue *q) {
    return q->num == 0;
}

void PrintQueue(Queue *q) {
    PrintList(&q->front);
}
