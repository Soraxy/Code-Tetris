#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#define LENGTH 10
#define LENGTH2 15
#define NB_PIECE 7
#define TAILLE 4
#define LIG 9
#define COL 9
void affichetableau(char tab[LENGTH2][LENGTH2],int taille);
typedef struct{
	int x;
	int y;
	char*** forme_piece;
	char symbole_piece;
}piece;

piece current;
