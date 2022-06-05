#include "header.h"

void ShowGrid(int GameOn){ //print the grid
	init_colors();
	int test = 0;
	char Moving_Piece[ROWS][COLS] = {0}; //the function creates another grid with the moving piece
	int i, j;
	for(i = 0; i < current.size ;i++){
        	for(j = 0; j < current.size ; j++){
            		if(current.shape[i][j])
                		Moving_Piece[current.row+i][current.col+j] = current.shape[i][j];
        	}
    	}
	clear(); //clear terminal
	attron(A_BOLD); // print in bold
		attrset (COLOR_PAIR(7));printw("                   _______ ");attroff (COLOR_PAIR(7));
		attrset (COLOR_PAIR(4));printw(" _______");attroff (COLOR_PAIR(4));
		attrset (COLOR_PAIR(5));printw(" _______");attroff (COLOR_PAIR(5));
		attrset (COLOR_PAIR(1));printw("  _______ ");attroff (COLOR_PAIR(1));	
    		attrset (COLOR_PAIR(2));printw("__");attroff (COLOR_PAIR(2));
    		attrset (COLOR_PAIR(6));printw("  _______\n");attroff (COLOR_PAIR(6));
    		attrset (COLOR_PAIR(7));printw("                  |___ ___|");attroff (COLOR_PAIR(7));
    		attrset (COLOR_PAIR(4));printw("|  ____/");attroff (COLOR_PAIR(4));
    		attrset (COLOR_PAIR(5));printw("|___ ___|");attroff (COLOR_PAIR(5));
    		attrset (COLOR_PAIR(1));printw("|  ____/");attroff (COLOR_PAIR(1));
    		attrset (COLOR_PAIR(2));printw("|  |");attroff (COLOR_PAIR(2));
    		attrset (COLOR_PAIR(6));printw("|   ____|\n");attroff (COLOR_PAIR(6));
    		attrset (COLOR_PAIR(7));printw("                     | |  ");attroff (COLOR_PAIR(7));   // print TETRIS logo
    		attrset (COLOR_PAIR(4));printw(" | |___ ");attroff (COLOR_PAIR(4));
    		attrset (COLOR_PAIR(5));printw("    | |  ");attroff (COLOR_PAIR(5));
    		attrset (COLOR_PAIR(1));printw(" |  \\   ");attroff (COLOR_PAIR(1));
    		attrset (COLOR_PAIR(2));printw(" |  |");attroff (COLOR_PAIR(2));
    		attrset (COLOR_PAIR(6));printw(" \\  \\\n");attroff (COLOR_PAIR(6));
    		attrset (COLOR_PAIR(7));printw("                     | |  ");attroff (COLOR_PAIR(7));
    		attrset (COLOR_PAIR(4));printw(" |  __/  ");attroff (COLOR_PAIR(4));
    		attrset (COLOR_PAIR(5));printw("   | |  ");attroff (COLOR_PAIR(5));
    		attrset (COLOR_PAIR(1));printw(" | \\ \\  ");attroff (COLOR_PAIR(1));
    		attrset (COLOR_PAIR(2));printw(" |  | ");attroff (COLOR_PAIR(2));
    		attrset (COLOR_PAIR(6));printw(" \\  \\ \n");attroff (COLOR_PAIR(6));
    		attrset (COLOR_PAIR(7));printw("                     | | ");attroff (COLOR_PAIR(7));
    		attrset (COLOR_PAIR(4));printw("  | |____   ");attroff (COLOR_PAIR(4));
    		attrset (COLOR_PAIR(5));printw(" | | ");attroff (COLOR_PAIR(5));
    		attrset (COLOR_PAIR(1));printw("  | |\\ \\ ");attroff (COLOR_PAIR(1));
    		attrset (COLOR_PAIR(2));printw(" |  |");attroff (COLOR_PAIR(2));
    		attrset (COLOR_PAIR(6));printw(" __\\  \\\n");attroff (COLOR_PAIR(6));
    		attrset (COLOR_PAIR(7));printw("                     |_|  ");attroff (COLOR_PAIR(7));
    		attrset (COLOR_PAIR(4));printw(" |_____/  ");attroff (COLOR_PAIR(4));
    		attrset (COLOR_PAIR(5));printw("  |_| ");attroff (COLOR_PAIR(5));
    		attrset (COLOR_PAIR(1));printw("  |_| \\_\\");attroff (COLOR_PAIR(1));
    		attrset (COLOR_PAIR(2));printw(" |__|");attroff (COLOR_PAIR(2));
    		attrset (COLOR_PAIR(6));printw("|______\\\n\n");attroff (COLOR_PAIR(6));
	attroff(A_BOLD);
    for(i = 0; i < ROWS ;i++){
	printw("                          ");
        for(j = 0; j < COLS ; j++){
		switch(Grid[i][j] + Moving_Piece[i][j]) { // color switch for all the pieces
			default :  printw(" %c ", (Grid[i][j] +  Moving_Piece[i][j])? 'O':'.'); 
				   break;
			case 'S':  attrset (COLOR_PAIR('S'));
 				   printw(" %c ", (Grid[i][j] +  Moving_Piece[i][j])? 'O':'.');
				   attroff (COLOR_PAIR('S'));
				   break;
			case 'T' : attrset (COLOR_PAIR('T'));
 				   printw(" %c ", (Grid[i][j] +  Moving_Piece[i][j])? 'O':'.');
				   attroff (COLOR_PAIR('T'));
				   break;
			case 'I' : attrset (COLOR_PAIR('I'));
 				   printw(" %c ", (Grid[i][j] +  Moving_Piece[i][j])? 'O':'.');
				   attroff (COLOR_PAIR('I'));
				   break;
			case 'J' : attrset (COLOR_PAIR('J'));
 				   printw(" %c ", (Grid[i][j] +  Moving_Piece[i][j])? 'O':'.');
				   attroff (COLOR_PAIR('J'));
				   break;
			case 'L' : attrset (COLOR_PAIR('L'));
 				   printw(" %c ", (Grid[i][j] +  Moving_Piece[i][j])? 'O':'.');
				   attroff (COLOR_PAIR('L'));
				   break;
			case 'O' : attrset (COLOR_PAIR('O'));
 				   printw(" %c ", (Grid[i][j] +  Moving_Piece[i][j])? 'O':'.');
				   attroff (COLOR_PAIR('O'));
				   break;
			case 'Z' : attrset (COLOR_PAIR('Z'));
 				   printw(" %c ", (Grid[i][j] +  Moving_Piece[i][j])? 'O':'.');
				   attroff (COLOR_PAIR('Z'));
				   break;
		}
        }
        printw("\n");
    }
    printw("\n                                     SCORE: %d\n", score);

}

void display_text(WINDOW *w){
wclear(w);
box(w,0,0);
wprintw(w, "pause");
wnoutrefresh(w);
}
