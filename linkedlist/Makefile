# マクロ定義部
CC = gcc
LOBJS = test_linkedlist.o linkedlist.o
QOBJS = test_queue.o queue.o linkedlist.o

# 生成規則部
test_linkedlist: $(LOBJS)
	$(CC) -o $@ $(LOBJS)
test_queue: $(QOBJS)
	$(CC) -o $@ $(QOBJS)

# サフィックスルール
.c.o:
	$(CC) -c $<

# タスク
.PHONY: clean
clean:
	rm -f $(LOBJS) $(QOBJS) test_linkedlist test_queue

# ヘッダファイル
test_linkedlist.o: linkedlist.h
linkedlist.o: linkedlist.h
test_queue.o: queue.h
queue.o: queue.h
