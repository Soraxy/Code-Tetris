#include "header.h"

void initialisationpiece(piece tab,int taille){ //créer matrice 4x4 avec que des 0 à l'intérieur

		for(int i=0;i<taille;i++){ 
			for(int j=0;j<taille;j++){
				for(int k=0;k<taille;k++){
					tab.forme_piece[i][j][k] = ' ';
				}
			}
		}
}


void modifierpiece(piece tab,int numero){ // va permettre de modifier la matrice 4x4 afin d'ajouter des @ dans les cases souhaitées
	if(numero==0){ // Tétrimino O
		tab.forme_piece[0][1][1] ='@';
		tab.forme_piece[0][1][2] ='@';
		tab.forme_piece[0][2][1] ='@';
		tab.forme_piece[0][2][2] ='@';
		
		tab.forme_piece[1][1][1] ='@';
		tab.forme_piece[1][1][2] ='@';
		tab.forme_piece[1][2][1] ='@';
		tab.forme_piece[1][2][2] ='@';
		
		tab.forme_piece[2][1][1] ='@';
		tab.forme_piece[2][1][2] ='@';
		tab.forme_piece[2][2][1] ='@';
		tab.forme_piece[2][2][2] ='@';
		
		tab.forme_piece[3][1][1] ='@';
		tab.forme_piece[3][1][2] ='@';
		tab.forme_piece[3][2][1] ='@';
		tab.forme_piece[3][2][2] ='@';
		
		
	}
	else if(numero==1){  // Tétrimino I
		tab.forme_piece[0][1][0] ='@';
		tab.forme_piece[0][1][1] ='@';
		tab.forme_piece[0][1][2] ='@';
		tab.forme_piece[0][1][3] ='@';
		
		tab.forme_piece[1][0][1] ='@';
		tab.forme_piece[1][1][1] ='@';
		tab.forme_piece[1][2][1] ='@';
		tab.forme_piece[1][3][1] ='@';
		
		tab.forme_piece[2][1][0] ='@';
		tab.forme_piece[2][1][1] ='@';
		tab.forme_piece[2][1][2] ='@';
		tab.forme_piece[2][1][3] ='@';
		
		tab.forme_piece[3][0][1] ='@';
		tab.forme_piece[3][1][1] ='@';
		tab.forme_piece[3][2][1] ='@';
		tab.forme_piece[3][3][1] ='@';

	
	}
	else if(numero==2){  // Tétrimino T
		tab.forme_piece[0][0][1] ='@';
		tab.forme_piece[0][1][1] ='@';
		tab.forme_piece[0][1][0] ='@';
		tab.forme_piece[0][1][2] ='@';
		
		tab.forme_piece[1][0][1] ='@';
		tab.forme_piece[1][1][1] ='@';
		tab.forme_piece[1][1][2] ='@';
		tab.forme_piece[1][2][1] ='@';
		
		tab.forme_piece[2][1][0] ='@';
		tab.forme_piece[2][1][1] ='@';
		tab.forme_piece[2][1][2] ='@';
		tab.forme_piece[2][2][1] ='@';
		
		tab.forme_piece[3][0][1] ='@';
		tab.forme_piece[3][1][1] ='@';
		tab.forme_piece[3][2][1] ='@';
		tab.forme_piece[3][1][0] ='@';

	}

	else if(numero==3){  // Tétrimino L
		tab.forme_piece[0][2][1] ='@';
		tab.forme_piece[0][1][1] ='@';
		tab.forme_piece[0][1][2] ='@';
		tab.forme_piece[0][1][3] ='@';
		
		tab.forme_piece[1][1][1] ='@';
		tab.forme_piece[1][1][2] ='@';
		tab.forme_piece[1][2][2] ='@';
		tab.forme_piece[1][3][2] ='@';
		
		tab.forme_piece[2][1][2] ='@';
		tab.forme_piece[2][2][2] ='@';
		tab.forme_piece[2][2][1] ='@';
		tab.forme_piece[2][2][0] ='@';
		
		tab.forme_piece[3][2][2] ='@';
		tab.forme_piece[3][2][1] ='@';
		tab.forme_piece[3][1][1] ='@';
		tab.forme_piece[3][0][1] ='@';

	
	}
	else if(numero==4){  // Tétrimino J
		tab.forme_piece[0][2][2] ='@';
		tab.forme_piece[0][1][2] ='@';
		tab.forme_piece[0][1][1] ='@';
		tab.forme_piece[0][1][0] ='@';
		
		tab.forme_piece[1][2][2] ='@';
		tab.forme_piece[1][2][3] ='@';
		tab.forme_piece[1][1][3] ='@';
		tab.forme_piece[1][0][3] ='@';
		
		tab.forme_piece[2][2][1] ='@';
		tab.forme_piece[2][3][1] ='@';
		tab.forme_piece[2][3][2] ='@';
		tab.forme_piece[2][3][3] ='@';
		
		tab.forme_piece[3][1][2] ='@';
		tab.forme_piece[3][1][1] ='@';
		tab.forme_piece[3][2][1] ='@';
		tab.forme_piece[3][3][1] ='@';

		
	}
	else if(numero==5){  // Tétrimino Z
		tab.forme_piece[0][1][1] ='@';
		tab.forme_piece[0][1][2] ='@';
		tab.forme_piece[0][2][2] ='@';
		tab.forme_piece[0][2][3] ='@';
		
		tab.forme_piece[1][1][1] ='@';
		tab.forme_piece[1][2][1] ='@';
		tab.forme_piece[1][1][2] ='@';
		tab.forme_piece[1][0][2] ='@';
		
		tab.forme_piece[2][1][1] ='@';
		tab.forme_piece[2][1][2] ='@';
		tab.forme_piece[2][2][2] ='@';
		tab.forme_piece[2][2][3] ='@';
		
		tab.forme_piece[3][1][1] ='@';
		tab.forme_piece[3][2][1] ='@';
		tab.forme_piece[3][1][2] ='@';
		tab.forme_piece[3][0][2] ='@';

	
	}
	else if(numero==6){  // Tétrimino S
		tab.forme_piece[0][2][0] ='@';
		tab.forme_piece[0][2][1] ='@';
		tab.forme_piece[0][1][1] ='@';
		tab.forme_piece[0][1][2] ='@';
		
		tab.forme_piece[1][0][1] ='@';
		tab.forme_piece[1][1][1] ='@';
		tab.forme_piece[1][1][2] ='@';
		tab.forme_piece[1][2][2] ='@';
		
		tab.forme_piece[2][2][0] ='@';
		tab.forme_piece[2][2][1] ='@';
		tab.forme_piece[2][1][1] ='@';
		tab.forme_piece[2][1][2] ='@';
		
		tab.forme_piece[3][0][1] ='@';
		tab.forme_piece[3][1][1] ='@';
		tab.forme_piece[3][1][2] ='@';
		tab.forme_piece[3][2][2] ='@';

	
	}
	else{
		printf("erreur, piece non reconnue\n");
		exit(6);
	}

	
}
