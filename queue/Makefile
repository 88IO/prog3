# マクロ定義部
CC = gcc
OBJS = test_queue.o queue.o

# 生成規則部
test_queue: $(OBJS)
	$(CC) -o $@ $(OBJS)

# サフィックスルール
.c.o:
	$(CC) -c $<

# タスク
.PHONY: clean
.PHONY: run
clean:
	rm -f $(OBJS) test_queue
run: test_queue
	./test_queue

# ヘッダファイル
test_queue.o: queue.h
queue.o: queue.h
