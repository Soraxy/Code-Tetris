CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)


all: tetris

%.o : %.c header.h
	$(CC) -c $< -lncurses -o $@

tetris: $(OBJ)
	$(CC) main.o -lncurses -o $@ 


clean: 
	rm *.o tetris
