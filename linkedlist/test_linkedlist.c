/**
 * @file test_linkedlist.c
 * @brief 線形リストの動作確認ファイル
 */
#include "linkedlist.h"

int main(void) {
    Menu menu;
    Node *list;

    InitList(&list);

    do {
        Node x;
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
            case Print:
                PrintList(&list);  break;
            case Clear:
                ClearList(&list);  break;
        }
    } while (menu != Term);

    TermList(&list);
    return 0;
}
