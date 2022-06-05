CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)


all: tetris

%.o : %.c header.h
	$(CC) -c $< -lncurses -fsanitize=address -o $@

tetris: $(OBJ)
	$(CC) main.o -lncurses -fsanitize=address -o $@ 


clean: 
	rm *.o tetris
