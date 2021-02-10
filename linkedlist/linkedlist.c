/**
 * @file linkedlist.c
 * @brief 線形リストのソースファイル
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void SetNode(Node *x, int no, char *name, Node *next) {
    x->no = no;
    x->next = next;
    strcpy(x->name, name);
}

Node *AllocNode(void) {
    return (calloc(1, sizeof(Node)));
}

void InsertNode(Node **top, int no, char *name) {
    Node *ptr= *top;
    *top = AllocNode();
    SetNode(*top, no, name, ptr);
}

void InserNodeNth(Node **top, int n, int no, char *name) {
    Node *ptrh = *top;
    int i;
    for (i = 1; i < n - 1; i++)
        ptrh = ptrh->next;
    Node *ptrt = ptrh->next;
    ptrh->next = AllocNode();
    SetNode(ptrh->next, no, name, ptrt);
}

void AppendNode(Node **top, int no, char *name) {
    if (*top == NULL) {
        InsertNode(top, no, name);
    } else {
        Node *ptr = *top;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = AllocNode();
        SetNode(ptr->next, no, name, NULL);
    }
}

void DeleteNode(Node **top) {
    if (*top != NULL) {
        Node *ptr = (*top)->next;
        free(*top);
        *top = ptr;
    }
}

void DeleteNodeNth(Node **top, int n) {
    if (n == 1) {
        DeleteNode(top);
        return;
    }

    if (*top != NULL) {
        Node *ptr = *top;
        int i;
        for (i = 1; i < n - 1; i++)
            ptr = ptr->next;
        Node *ptrt = ptr->next->next;
        free(ptr->next);
        ptr->next = ptrt;
    }
}

void ClearList(Node **top) {
    while (*top != NULL)
        DeleteNode(top);
}

void PrintList(Node **top) {
    Node *ptr = *top;
    puts("【一覧表】");
    while (ptr != NULL) {
        printf("%5d %-10.10s\n", ptr->no, ptr->name);
        ptr = ptr->next;
    }
}

void InitList(Node **top) {
    *top = NULL;
}

void TermList(Node **top) {
    ClearList(top);
}

Node Read(char *message) {
    Node temp;

    printf("%sするデータを入力してください。\n", message);
    printf("番号：");  scanf("%d", &temp.no);
    printf("名前：");  scanf("%s", temp.name);

    return (temp);
}

Menu SelectMenu(void) {
    int ch;

    do {
        puts("(1) 先頭にノードを挿入    (2) 末尾にノードを追加");
        puts("(3) 先頭のノードを削除    (4) N番目にノードを追加");
        puts("(5) N番目のノードを削除   (6) 全てのノードを表示");
        puts("(7) 全てのノードを削除    (0) 処　理　完　了");
        printf("選択：");  scanf("%d", &ch);
    } while (ch < Term  ||  ch > Clear);

    return ((Menu)ch);
}
