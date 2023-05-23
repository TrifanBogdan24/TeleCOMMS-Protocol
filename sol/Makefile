# TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD
CC = gcc
CFLAGS = -Wall -Wextra

build: main

main: main.o structuri.o
	$(CC) $(CFLAGS) -o main main.o structuri.o

main.o: main.c structuri.h
	$(CC) $(CFLAGS) -c main.c

structuri.o: structuri.c structuri.h
	$(CC) $(CFLAGS) -c structuri.c

clean:
	rm -f main main.o structuri.o

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./build

coding-style:
	cd ../'coding style' ; ./cs.sh ../sol ; cd ../sol
