#include "tetris.c"
#include <ncurses.h>



int main(){
	  printf(" \033[40;31m _______ \033[40;33m _______\033[40;32m _______\033[40;34m  _______\033[40;36m __ \033[40;35m _______\n\033[40;31m |___ ___|\033[40;33m|  ____/\033[40;32m|___ ___|\033[40;34m|  ____/\033[40;36m|  |\033[40;35m|   ____|\n \033[40;31m   | |  \033[40;33m | |___  \033[40;32m   | |  \033[40;34m |  \\   \033[40;36m |  |\033[40;35m \\  \\\n\033[40;31m    | |  \033[40;33m |  __/  \033[40;32m   | |  \033[40;34m | \\ \\  \033[40;36m |  | \033[40;35m \\  \\ \n \033[40;31m   | | \033[40;33m  | |____   \033[40;32m | | \033[40;34m  | |\\ \\ \033[40;36m |  |\033[40;35m __\\  \\\n  \033[40;31m  |_|  \033[40;33m |_____/  \033[40;32m  |_| \033[40;34m  |_| \\_\\\033[40;36m |__|\033[40;35m|______\\\n\033[40;37m\n");// print TETRIS logo

	srand(time(NULL));
	piece tableau_piece[NB_PIECE]; // tableau de structure qui va contenir les pièces et leurs orientations 
	
	int resultat; // variable qui va stocker le résultat de la fonction random() 
	int resultat_final; // variable qui va stocker le choix de la fonction choisir_orientation()
	char tabp2p[LENGTH2][LENGTH2]; //grid for the game
	for(int i=0;i<NB_PIECE;i++){
		tableau_piece[i] = constructionpiece(i);
		//affichepiece(*(tableau_piece+i));
	}
		int res_colonne;
		
	initialisertableau(tabp2p,LENGTH2);
int a =0;
	
while (a<4){
		res_colonne = choisir_colonne();
	resultat = hasard();
	resultat_final = chosir_orientation(*(tableau_piece+resultat));
	
	affiche_orientation_piece(*(tableau_piece+resultat),resultat_final);
	placerpiece(*(tableau_piece+resultat),resultat_final,tabp2p,res_colonne);
	a++;
}
return 0;
}

