#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <ncurses.h>
#include <unistd.h>

#define ROWS 20
#define COLS 10
#define TRUE 1
#define FALSE 0

char Grid[ROWS][COLS] = {0}; //Game Grid
int score = 0;
int GameOn = 1; // defines whether the game is on or not
double timer = 1000000; //half second

//WINDOW* stop(6, 10, 14);

void init_colors(void){  //initalizes the colors for ncurses library
	start_color();
	init_color(100, 1000, 647, 0); // create a color 
	init_pair(1, COLOR_CYAN, COLOR_BLACK); // color for R in logo
	init_pair(2, COLOR_BLUE, COLOR_BLACK); // color for I in logo
	init_pair(3, COLOR_YELLOW, COLOR_BLACK); // useless
	init_pair(4, 100, COLOR_BLACK); // color for E in logo
	init_pair(5, COLOR_GREEN, COLOR_BLACK); // color for the 2nd T in logo
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK); //color for S in logo
	init_pair(7, COLOR_RED, COLOR_BLACK); // color for the T in the logo
	init_pair('O', 100, 100); // color for the O shape
	init_pair('L', COLOR_YELLOW, COLOR_YELLOW); //color for the L shape
	init_pair('S', COLOR_GREEN, COLOR_GREEN); // color fot the S shape
	init_pair('T', COLOR_MAGENTA, COLOR_MAGENTA); // the rest is self explanatory
	init_pair('I', COLOR_CYAN, COLOR_CYAN);
	init_pair('J', COLOR_BLUE, COLOR_BLUE);
	init_pair('Z', COLOR_RED, COLOR_RED);
}

typedef struct {  //defines the structure for a piece
    char **shape;
    int size, row, col; //defines the size of the piece then the position
} Tetromino;
Tetromino current;

const Tetromino Shapes[7]= {  // defines all shapes, all shapes have differents variables for the differents colors
    {(char *[]){(char []){0,'S','S'},
		(char []){'S','S',0}, 
		(char []){0,0,0}        }, 3},                           //S_shape     
    {(char *[]){(char []){'Z','Z',0},
		(char []){0,'Z','Z'},
		(char []){0,0,0}        }, 3},                           //Z_shape     
    {(char *[]){(char []){0,'T',0},
		(char []){'T','T','T'},
		(char []){0,0,0}        }, 3},                           //T_shape     
    {(char *[]){(char []){0,0,'L'},
		(char []){'L','L','L'},
		(char []){0,0,0}        }, 3},                           //L_shape     
    {(char *[]){(char []){'J',0,0},
		(char []){'J','J','J'},
		(char []){0,0,0}        }, 3},                           //J_shape    
    {(char *[]){(char []){'O','O'},
		(char []){'O','O'}      }, 2},                           //O_shape
    {(char *[]){(char []){0,0,0,0}, 
		(char []){'I','I','I','I'}, 
		(char []){0,0,0,0}, 
		(char []){0,0,0,0}      }, 4}                            //I_shape
};

#ifndef PROTO
#define PROTO

int CheckTetrominoPosition(Tetromino toCheck);  //prototypes all needed functions
void WriteToGrid(); 
void check_lines();

#endif
