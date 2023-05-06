$(CC)=gcc

memoo: memo.o libMemo.o
	$(CC) -o memo memo.o libMemo.o -I.

memo.o: memo.c mem.h
	$(CC) -c memo.c -I.

libmemo.o:libMemo.c mem.h
	$(CC) -c libMemo.c -I.

clean:
	rm -rf memo *.o
	  

# memo: memo.c libMemo.c
# 	$(CC) memo.c libMemo.c -o memo
