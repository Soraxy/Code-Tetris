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
		tab.forme_piece[0][1][1] ='O';
		tab.forme_piece[0][1][2] ='O';
		tab.forme_piece[0][2][1] ='O';
		tab.forme_piece[0][2][2] ='O';
		
		tab.forme_piece[1][1][1] ='O';
		tab.forme_piece[1][1][2] ='O';
		tab.forme_piece[1][2][1] ='O';
		tab.forme_piece[1][2][2] ='O';
		
		tab.forme_piece[2][1][1] ='O';
		tab.forme_piece[2][1][2] ='O';
		tab.forme_piece[2][2][1] ='O';
		tab.forme_piece[2][2][2] ='O';
		
		tab.forme_piece[3][1][1] ='O';
		tab.forme_piece[3][1][2] ='O';
		tab.forme_piece[3][2][1] ='O';
		tab.forme_piece[3][2][2] ='O';
		
		tab.symbole_piece = 'O';
	}
	else if(numero==1){  // Tétrimino I
		tab.forme_piece[0][1][0] ='I';
		tab.forme_piece[0][1][1] ='I';
		tab.forme_piece[0][1][2] ='I';
		tab.forme_piece[0][1][3] ='I';
		
		tab.forme_piece[1][0][1] ='I';
		tab.forme_piece[1][1][1] ='I';
		tab.forme_piece[1][2][1] ='I';
		tab.forme_piece[1][3][1] ='I';
		
		tab.forme_piece[2][1][0] ='I';
		tab.forme_piece[2][1][1] ='I';
		tab.forme_piece[2][1][2] ='I';
		tab.forme_piece[2][1][3] ='I';
		
		tab.forme_piece[3][0][1] ='I';
		tab.forme_piece[3][1][1] ='I';
		tab.forme_piece[3][2][1] ='I';
		tab.forme_piece[3][3][1] ='I';

		tab.symbole_piece = 'I';	
	}
	else if(numero==2){  // Tétrimino T
		tab.forme_piece[0][0][1] ='T';
		tab.forme_piece[0][1][1] ='T';
		tab.forme_piece[0][1][0] ='T';
		tab.forme_piece[0][1][2] ='T';
		
		tab.forme_piece[1][0][1] ='T';
		tab.forme_piece[1][1][1] ='T';
		tab.forme_piece[1][1][2] ='T';
		tab.forme_piece[1][2][1] ='T';
		
		tab.forme_piece[2][1][0] ='T';
		tab.forme_piece[2][1][1] ='T';
		tab.forme_piece[2][1][2] ='T';
		tab.forme_piece[2][2][1] ='T';
		
		tab.forme_piece[3][0][1] ='T';
		tab.forme_piece[3][1][1] ='T';
		tab.forme_piece[3][2][1] ='T';
		tab.forme_piece[3][1][0] ='T';
		
		tab.symbole_piece = 'T';

	}

	else if(numero==3){  // Tétrimino L
		tab.forme_piece[0][2][1] ='L';
		tab.forme_piece[0][1][1] ='L';
		tab.forme_piece[0][1][2] ='L';
		tab.forme_piece[0][1][3] ='L';
		
		tab.forme_piece[1][1][1] ='L';
		tab.forme_piece[1][1][2] ='L';
		tab.forme_piece[1][2][2] ='L';
		tab.forme_piece[1][3][2] ='L';
		
		tab.forme_piece[2][1][2] ='L';
		tab.forme_piece[2][2][2] ='L';
		tab.forme_piece[2][2][1] ='L';
		tab.forme_piece[2][2][0] ='L';
		
		tab.forme_piece[3][2][2] ='L';
		tab.forme_piece[3][2][1] ='L';
		tab.forme_piece[3][1][1] ='L';
		tab.forme_piece[3][0][1] ='L';

		tab.symbole_piece = 'L';

	
	}
	else if(numero==4){  // Tétrimino J
		tab.forme_piece[0][2][2] ='J';
		tab.forme_piece[0][1][2] ='J';
		tab.forme_piece[0][1][1] ='J';
		tab.forme_piece[0][1][0] ='J';
		
		tab.forme_piece[1][2][2] ='J';
		tab.forme_piece[1][2][3] ='J';
		tab.forme_piece[1][1][3] ='J';
		tab.forme_piece[1][0][3] ='J';
		
		tab.forme_piece[2][2][1] ='J';
		tab.forme_piece[2][3][1] ='J';
		tab.forme_piece[2][3][2] ='J';
		tab.forme_piece[2][3][3] ='J';
		
		tab.forme_piece[3][1][2] ='J';
		tab.forme_piece[3][1][1] ='J';
		tab.forme_piece[3][2][1] ='J';
		tab.forme_piece[3][3][1] ='J';
		
		tab.symbole_piece = 'J';

		
	}
	else if(numero==5){  // Tétrimino Z
		tab.forme_piece[0][1][1] ='Z';
		tab.forme_piece[0][1][2] ='Z';
		tab.forme_piece[0][2][2] ='Z';
		tab.forme_piece[0][2][3] ='Z';
		
		tab.forme_piece[1][1][1] ='Z';
		tab.forme_piece[1][2][1] ='Z';
		tab.forme_piece[1][1][2] ='Z';
		tab.forme_piece[1][0][2] ='Z';
		
		tab.forme_piece[2][1][1] ='Z';
		tab.forme_piece[2][1][2] ='Z';
		tab.forme_piece[2][2][2] ='Z';
		tab.forme_piece[2][2][3] ='Z';
		
		tab.forme_piece[3][1][1] ='Z';
		tab.forme_piece[3][2][1] ='Z';
		tab.forme_piece[3][1][2] ='Z';
		tab.forme_piece[3][0][2] ='Z';

		tab.symbole_piece = 'Z';
	
	}
	else if(numero==6){  // Tétrimino S
		tab.forme_piece[0][2][0] ='S';
		tab.forme_piece[0][2][1] ='S';
		tab.forme_piece[0][1][1] ='S';
		tab.forme_piece[0][1][2] ='S';
		
		tab.forme_piece[1][0][1] ='S';
		tab.forme_piece[1][1][1] ='S';
		tab.forme_piece[1][1][2] ='S';
		tab.forme_piece[1][2][2] ='S';
		
		tab.forme_piece[2][2][0] ='S';
		tab.forme_piece[2][2][1] ='S';
		tab.forme_piece[2][1][1] ='S';
		tab.forme_piece[2][1][2] ='S';
		
		tab.forme_piece[3][0][1] ='S';
		tab.forme_piece[3][1][1] ='S';
		tab.forme_piece[3][1][2] ='S';
		tab.forme_piece[3][2][2] ='S';

		tab.symbole_piece = 'S';
	
	}
	else{
		printf("erreur, piece non reconnue\n");
		exit(6);
	}

	
}
