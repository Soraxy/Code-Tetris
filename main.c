#include "tetris.c"

int main(){
	srand(time(NULL));
	piece tableau_piece[NB_PIECE]; // tableau de structure qui va contenir les pièces et leurs orientations 
	
	int resultat; // variable qui va stocker le résultat de la fonction random() 
	int resultat_final; // variable qui va stocker le choix de la fonction choisir_orientation()
	char tabp2p[LENGTH2][LENGTH2]; 
	  
	int res_colonne;

	
	for(int i=0;i<NB_PIECE;i++){
		tableau_piece[i] = constructionpiece(i);
		
	}
	initialisertableau(tabp2p,LENGTH2);
	
	resultat = hasard(); 
	resultat_final = chosir_orientation(*(tableau_piece+resultat));
	res_colonne = choisir_colonne();	
	affiche_orientation_piece(*(tableau_piece+resultat),resultat_final);
	placerpiece(*(tableau_piece+resultat),resultat_final,tabp2p,res_colonne);
	

return 0;
}

