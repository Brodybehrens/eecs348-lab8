CC = gcc
CFLAGS = -Wall -Wextra -O2

.PHONY: all clean

all: task1 task2

task1: task1.c
	$(CC) $(CFLAGS) -o task1 task1.c

task2: task2.c
	$(CC) $(CFLAGS) -o task2 task2.c

clean:
	del task1.exe task2.exe 2>nul || rm -f task1 task2
