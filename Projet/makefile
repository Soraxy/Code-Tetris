
tetris: tetris.o pieces.o main.o header.h
	gcc main.o -lncurses -o tetris

main.o: main.c tetris.o 
	gcc -lncurses -c main.c

tetris.o: header.h tetris.c
	gcc -lncurses -c tetris.c

pieces.o: pieces.c header.h
	gcc -lncurses -c pieces.c

clean:
	rm *.o tetris
