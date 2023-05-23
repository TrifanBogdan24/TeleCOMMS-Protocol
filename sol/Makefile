# TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD
CC = gcc
CFLAGS = -Wall -Wextra

build: main

main: main.o structuri.o byte_string.o
	$(CC) $(CFLAGS) -o main main.o structuri.o byte_string.o

main.o: main.c structuri.h byte_string.h
	$(CC) $(CFLAGS) -c main.c

structuri.o: structuri.c structuri.h byte_string.h
	$(CC) $(CFLAGS) -c structuri.c

byte_string.o: byte_string.c byte_string.h
	$(CC) $(CFLAGS) -c byte_string.c

clean:
	rm -f main *.o

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./build

coding-style:
	cd ../'coding style' ; ./cs.sh ../sol ; cd ../sol
