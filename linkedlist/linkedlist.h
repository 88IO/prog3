/**
 * @file linkedlist.h
 * @brief 線形リストのヘッダファイル
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/** リスト操作のメニュー */
typedef enum {
    Term, Insert, Append, Delete, InsertN, DeleteN, Print, Clear
} Menu;

/** リストを構成するノードの構造体 */
typedef struct __node {
    int no; /**< 会員番号 */
    char name[10]; /**< 名前 */
    struct __node *next; /**< 後続ノードへのポインタ */
} Node;

/**
 * ノードのプロパティを設定する
 *
 * @param[out] x ノードのポインタ
 * @param[in] no 会員番号
 * @param[in] name 名前
 * @param[in] next 後続ノードへのポインタ
 */
void SetNode(Node *x, int no, char *name, Node *next);

/**
 * ノードのメモリを確保する
 *
 * @return Node 確保したノードへのポインタ
 */
Node *AllocNode(void);

/**
 * 先頭にノードを挿入
 *
 * @param[out] top リストの先頭ノードへのポインタのポインタ
 * @param[in] no 会員番号
 * @param[in] name 名前
 */
void InsertNode(Node **top, int no, char *name);

/**
 * N番目にノードを挿入
 *
 * @param[out] top リストの先頭ノードへのポインタのポインタ
 * @param[in] n N番目
 * @param[in] no 会員番号
 * @param[in] name 名前
 */
void InserNodeNth(Node **top, int n, int no, char *name);

/**
 * 末尾にノードを追加
 *
 * @param[out] top リストの先頭ノードへのポインタのポインタ
 * @param[in] no 会員番号
 * @param[in] name 名前
 */
void AppendNode(Node **top, int no, char *name);

/**
 * 先頭のノードを削除
 *
 * @param[out] top リストの先頭ノードへのポインタのポインタ
 */
void DeleteNode(Node **top);

/**
 * N番目のノードを削除
 *
 * @param[out] top リストの先頭ノードへのポインタのポインタ
 * @param[in] n N番目
 */
void DeleteNodeNth(Node **top, int n);

/**
 * 全てのノードを削除
 *
 * @param[out] top リストの先頭ノードへのポインタのポインタ
 */
void ClearList(Node **top);

/**
 * 全てのノードを表示
 *
 * @param[in] top リストの先頭ノードへのポインタのポインタ
 */
void PrintList(Node **top);

/**
 * 線形リストを初期化
 *
 * @param[out] top リストの先頭ノードへのポインタのポインタ
 */
void InitList(Node **top);

/**
 * 線形リストの使用を終了
 *
 * @param[out] top リストの先頭ノードへのポインタのポインタ
 */
void TermList(Node **top);

/**
 * データの入力
 *
 * @param[in] message ノードの操作コメント
 * @return Node 作成したノード
 */
Node Read(char *message);

/**
 * リスト操作のメニュー選択
 *
 * @return Menu Term:終了 Insert:先頭追加 Append:末尾追加 Delete:先頭削除 InsertN:N番目追加 DeleteN:N番目削除 Print:表示 Clear:全削除
 */
Menu SelectMenu(void);

#endif
