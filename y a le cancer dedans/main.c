#include "gamerules.c"	

int main() {
	srand(time(0));
	score = 0;
	char username[30];
	int keybind;
	int pause = 1;
	initscr(); // initalizes the ncurses library
	noecho(); // disables writing when using getch
	curs_set(0);
	keypad(stdscr,TRUE); // allows to use the keypad for ncurses
	struct timeval before, after;
	gettimeofday(&before, NULL);
	nodelay(stdscr, TRUE);
	GetNewTetromino(); // first we get a random shape
	ShowGrid(GameOn); // then the grid is printed

		while(GameOn){
			if ((keybind = getch()) != ERR) { //ERR means that no key is detected
          			MoveCurrentTetromino(keybind);
        		}
        		gettimeofday(&after, NULL);
        		if (((double)after.tv_sec*1000000 + (double)after.tv_usec)-((double)before.tv_sec*1000000 + (double)before.tv_usec) > timer){ 
            			before = after;
            			MoveCurrentTetromino(KEY_DOWN); //automatically move down the piece after one sec
        		}
    		}
	
	DeleteTetromino(current);
	sleep(3);
	

	endwin(); //ends ncurses library
	printf("GAME OVER  Your score is : %d \n",score);
 
return 0;
}
