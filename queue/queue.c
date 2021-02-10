/**
 * @file queue.c
 * @brief キューのライブラリのソースファイル
 */
#include <stdlib.h>
#include "queue.h"

int QueueAlloc(Queue *q, int max) {
    int *x;
    x = calloc(max, sizeof(int));

    if (x == NULL) {
        q->max = 0;
        return -1;
    }

    q->max = max;
    q->num = 0;
    q->front = 0;
    q->rear = 0;
    q->que = x;

    return 0;
}

void QueueFree(Queue *q) {
    q->max = 0;
    q->num = 0;
    q->front = 0;
    q->rear = 0;

    free(q->que);
}

int QueueEnque(Queue *q, int x) {
    if (q->max == q->num)  return -1;

    *(q->que + q->rear) = x;
    q->rear  = (q->rear + 1) % q->max;
    q->num++;

    return 0;
}

int QueueDeque(Queue *q, int *x) {
    if (q->num == 0)  return -1;

    *x = *(q->que + q->front);
    q->front = (q->front + 1) % q->max;
    q->num--;

    return 0;
}

int QueueSize(const Queue *q) {
    return q->max;
}

int QueueNo(const Queue *q) {
    return q->num;
}

int QueueIsEmpty(const Queue *q) {
    if (q->num == 0)  return 1;
    else  return 0;
}

int QueueIsFull(const Queue *q) {
    if (q->num == q->max)  return 1;
    else  return 0;
}

