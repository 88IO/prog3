/**
 * @file test_linkedlist.c
 * @brief 線形リストの動作確認ファイル
 */
#include <stdio.h>
#include "linkedlist.h"

int main(void) {
    Menu menu;
    Node *list;

    InitList(&list);

    do {
        Node x;
        int n;
        switch (menu = SelectMenu()) {
            case Insert:
                x = Read("挿入");
                InsertNode(&list, x.no, x.name);
                break;
            case Append:
                x = Read("追加");
                AppendNode(&list, x.no, x.name);
                break;
            case Delete:
                DeleteNode(&list);  break;
            case InsertN:
                x = Read("挿入");
                printf("何番目：");  scanf("%d", &n);
                InserNodeNth(&list, n, x.no, x.name);
                break;
            case DeleteN:
                printf("何番目：");  scanf("%d", &n);
                DeleteNodeNth(&list, n);  break;
            case Print:
                PrintList(&list);  break;
            case Clear:
                ClearList(&list);  break;
            default:
                break;
        }
    } while (menu != Term);

    TermList(&list);
    return 0;
}
