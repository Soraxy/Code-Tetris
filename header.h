#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH2 18
#define NB_PIECE 7
#define TAILLE 4
void affichetableau(char tab[LENGTH2][LENGTH2],int taille);
int choisir_colonne();
typedef struct{
	int x;
	int y;
	char*** forme_piece;
	char symbole_piece;
}piece;

