#include <stdio.h>
#include <signal.h>
#include "rotor.h"
#include "keyboard.h"

int running = 1;
void handler(int signo) { running = 0; }

int main(void) {
    // 初期値
    int swaps[3][2] = {{'a', 'a'}, {'b', 'b'}, {'c', 'c'}};
    int scrots[3] = {0, 0, 0};

    // 設定ファイルの読込
    FILE *sfp;
    // プラグの入換設定（最大3つ）
    if ((sfp = fopen("./plugs.txt", "r")) == NULL) {
        printf("プラグ設定ファイルplugs.txtを開けません\n");
        printf("初期値: {{a, a}, {b, b}, {c, c}} を使用します\n");
    } else {
        printf("プラグ設定ファイルplugs.txtを開きました\n");
        int i;
        char sw1, sw2;
        // 入換は3つまで
        for (i = 0; i < 3; i++) {
            if (fscanf(sfp, "%c,%c\n", &sw1, &sw2) == 2) {
                printf("{%c, %c} ", sw1, sw2);
                swaps[i][0] = sw1;  swaps[i][1] = sw2;
            }
        }
        putchar('\n');
        fclose(sfp);
    }
    // スクランブラーの初期回転状態
    if ((sfp = fopen("./rots.txt", "r")) == NULL) {
        printf("初期回転状態設定ファイルrots.txtを開けません\n");
        printf("初期値: {0, 0, 0} を使用します\n");
    } else {
        printf("初期回転状態設定ファイルrots.txtを開きました\n");
        int i;
        int rot;
        // スクランブラー数は3つ
        for (i = 0; i < 3; i++) {
            // [a-z]なので26で割った余り
            if (fscanf(sfp, "%d", &rot) == 1) {
                printf("%d ", rot % 26);
                scrots[i] = rot % 26;
            }
        }
        putchar('\n');
        fclose(sfp);
    }

    // プラグボード
    // 入れ替えるキーを指定
    Rotor pb = plugboard(swaps);
    // スクランブラー(3つ)
    // 適当なシードと初期回転状態を引数に生成
    Rotor sc[3] = {
        scrambler(0, scrots[0]),
        scrambler(1, scrots[1]),
        scrambler(2, scrots[2]),
    };
    int scsize = sizeof(sc) / sizeof(Rotor);
    // リフレクター
    Rotor rf = reflector(3);

    // 書込用ファイル
    FILE *dfp;
    // ファイルを開く(開けなかったら-1を返して終了)
    if ((dfp = fopen("./output.txt", "w")) == NULL) {
        printf("書込用ファイルを開けません\n");
        return -1;
    }

    // Ctrl + C を押したときにループを抜ける
    // エラー時の処理は必要になれば追記予定
    if (signal(SIGINT, handler) == SIG_ERR) {  }

    printf("初期化完了...\n");

    int i;
    char ch;
    // runnningが1の間はループ
    while (running) {
        // リアルタイムキー入力
        if (kbhit()) {
            // キー取得
            // Q(大文字)の入力で終了
            if ((ch = getchar()) == 'Q')  break;
            // キー入力を[a-z]で受付
            if (ch < 'a' || ch > 'z')  continue;

            // 入力文字の表示
            putchar(ch);

            // 暗号化/復号化
            ch = pb.table[ch - 'a'];
            for (i = 0; i < scsize; i++)  ch = sc[i].table[ch];
            ch = rf.table[ch];
            for (i = scsize - 1; i >= 0; i--)  ch = sc[i].rtable[ch];
            ch = 'a' + pb.table[ch];

            // スクランブラーの回転処理
            rotate(&sc[0]);
            // 前のスクランブラーが１回転したら隣を回転
            for (i = 0; i < scsize - 1; i++) {
                if (fullturn(&sc[i]))  rotate(&sc[i + 1]);
            }

            // 変換後の文字を表示
            printf(" -> %c\n", ch);
            // ファイル書込
            fputc(ch, dfp);
        }
    }
    // ファイルを閉じる
    fclose(dfp);

    return 0;
}
