CC=gcc
CFLAGS=-lpthread
jews.iso: main.c
			$(CC) main.c -lpthread -o jews.iso
