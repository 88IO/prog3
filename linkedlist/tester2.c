#include <stdio.h>
#include "linkedlist.h"
#include "queue.h"

int main(void) {
    Queue q;

    QueueInit(&q);

    int ch;
    do {
        Node x;

        puts("(1) キューに追加    (2) キューから削除");
        puts("(3) キューを表示    (4) キューの要素数");
        puts("(0) 処　理　完　了");
        printf("選択：");  scanf("%d", &ch);

        switch (ch) {
            case 1:
                x = Read("追加");
                QueueEnque(&q, &x);
                break;
            case 2:
                QueueDeque(&q);  break;
            case 3:
                PrintQueue(&q);  break;
            case 4:
                printf("要素数：%d\n", QueueNo(&q));  break;
            default:
                break;
        }
    } while (ch > 0 || ch < 5);

    QueueFree(&q);
    return 0;
}
