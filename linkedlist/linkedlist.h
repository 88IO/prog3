#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef enum {
    Term, Insert, Append, Delete, Print, Clear
} Menu;

typedef struct _node {
    int no;
    char name[10];
    struct _node *next;
} Node;

void SetNode(Node *x, int no, char *name, Node *next);

Node *AllocNode(void);

void InsertNode(Node **top, int no, char *name);

void AppendNode(Node **top, int no, char *name);

void DeleteNode(Node **top);

void ClearList(Node **top);

void PrintList(Node **top);

void InitList(Node **top);

void TermList(Node **top);

Node Read(char *message);

Menu SelectMenu(void);

void InserNodeNth(Node **top, int n, int no, char *name);

void DeleteNodeNth(Node **top, int n);

#endif
