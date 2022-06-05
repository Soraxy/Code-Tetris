#include "pieces.c"

	


int hasard(){ // fonction qui choisi un nombre aléatoire entre (0 et 7 exclus)
	int nombre;
	nombre = rand()%7;
	return nombre;
}



void affichepiece(piece tab){ //fonction qui permet d'afficher la pièce
		for(int i=0;i<TAILLE;i++){ 
			
			for(int j=0;j<TAILLE;j++){
				printf("\n");
				for(int k=0;k<TAILLE;k++){
					printf("%c",tab.forme_piece[i][j][k]);
					
				}
			}
			printf("\n");
		}

}		

void affiche_orientation_piece(piece tab,int choix){ //fonction qui permet d'afficher l'orientation de la pièce
		
			
			for(int j=0;j<TAILLE;j++){
				printf("\n");
				for(int k=0;k<TAILLE;k++){
					printf("%c",tab.forme_piece[choix][j][k]);
					
				}
			}
			
		
}	


int chosirpiece(piece tab){ //demande a l'utilisateur l'orientation de la pièce
	int orientation = 0;
	int choix;
	do{
		printf("veuillez choisir une orientation. entrez un numéro entre 0 et 3 (0 ET 3 inclus)\n");
			for(int i=0;i<TAILLE;i++){
				printf("orientation %d ?\n",i+1);
					affichepiece(tab);
			}
		scanf("%d",&choix);

	}while(choix<=1 && choix>=4);
	return choix;
}

int chosir_orientation(piece tab){ //demande a l'utilisateur l'orientation de la pièce
	int orientation = 0;
	int choix;
	do{
		printf("\nveuillez choisir une orientation. entrez un numéro entre 0 et 3 (0 ET 3 inclus)\n");
			for(int i=0;i<TAILLE;i++){
				printf("orientation %d ?",i);
					affiche_orientation_piece(tab,i);
					
			}
		printf("Quel est votre orientation ?\n");
		scanf("%d",&choix);

	}while((choix<0) || (choix>3));
	return choix;
}



piece constructionpiece(int a){ // fonction mère, elle permet d'allouer de la mémoire et pour créer une matrice de taille 4X4. Elle sera compléter par la suite grâce au fonction initialisationpiece et modifierpiece 
	piece Mapiece;
	char** tabp2p1;
	char* tabp1;
	Mapiece.symbole_piece = '@';
	Mapiece.forme_piece = malloc(4*sizeof(char**));
	if(Mapiece.forme_piece==NULL){
		printf("erreur 3, allocation échouée\n");
		exit(3);
	}
	
	for(int i=0;i<TAILLE;i++){
		tabp2p1 = malloc(4 * sizeof(char*));
		if(tabp2p1==NULL){
			printf("erreur 4, allocation échouée\n");
			exit(4);
		}
		for(int k=0;k<TAILLE;k++){
			tabp1 = malloc(4*sizeof(char));
			if(tabp1==NULL){
				printf("erreur 5, allocation échouée\n");
				exit(5);
			}
			tabp2p1[k] = tabp1;
		}	
	
		Mapiece.forme_piece[i] = tabp2p1;		
	}
	initialisationpiece(Mapiece,TAILLE); 
	modifierpiece(Mapiece,a);
	return Mapiece;
}


void initialisertableau(char tab[LENGTH2][LENGTH2],int taille){

	for(int i=0;i<taille;i++){
			for(int j=0;j<taille;j++){
				tab[i][j] = ' ';
			}
			
		}
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			tab[i][0] = ' ';	
		}
	}
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			tab[14][j] = '1';
			tab[15][j] = '1';	// ici nous avions eu l'idée de mettre des '1' pour que lorsque la pièce rentre en collision avec les '1' alors, on recule la pièece
			
		}
	}
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			tab[i][11] = ' ';	
		}
	}
}
int choisir_colonne(){
	int temp;
	char lettre;
	do {
		printf("veuillez choisir une lettre comprise entre (A-J)\n");
		scanf("%c",&lettre);
		temp = (int)lettre;
		
	} while((temp>74) || (temp<65));
	
	return temp;
}

void decaler_matrice(piece tab,int choix_colonne,int choix){
	int resultat = 0;
	int dx =2;
	int p = 3;
	int abs=1;
	int m =0;
	
	
	tab.x = choix_colonne;     
	tab.y = TAILLE-1;
	if(choix_colonne>=6){
		for(int i=0;i<=3;i++){
			if((tab.forme_piece[choix][i][3])!='@'){
				resultat = resultat + 1; 
			}
		}
		if(resultat==TAILLE){
			for(int y=0;y<TAILLE;y++){
				for(int x=0;x<TAILLE-1;x++){
					tab.forme_piece[choix][y][p] = tab.forme_piece[choix][y][dx];
					tab.forme_piece[choix][y][dx] = ' ';
					p = p - 1;
					dx = dx - 1;
				}
				p = 3;	
				dx = 2;
			}		
		}
	}
	else{
		for(int i=0;i<=3;i++){
			if(tab.forme_piece[choix][i][0]!='@'){
				resultat = resultat + 1; 
			}
		}
		if(resultat==TAILLE){
			for(int y=0;y<TAILLE;y++){
				for(int x=0;x<TAILLE-1;x++){
					tab.forme_piece[choix][y][m] = tab.forme_piece[choix][y][abs];
					tab.forme_piece[choix][y][abs] = ' ';
					m = m + 1;
					abs = abs + 1;
				}
				m = 0;	
				abs = 1;
			}		
		}	
	}			
}

void decaler_rang(piece tab,int choix_colonne,int choix,char grille[LENGTH2][LENGTH2]){
	int test;
	int px = choix_colonne;
	for(test=13;test<=test+1;test++){
			for(int px=tab.x;px<=tab.x+3;px++){
				if(grille[test][px]=='@'){
				
					grille[test-1][px] = grille[test][px];
					grille[test][px] = ' '; 
				}
			}
			test = test - 1;
		}
	
	affichetableau(grille,LENGTH2);
}

void descendre1(piece tab,int choix_colonne,int choix,char grille[LENGTH2][LENGTH2],int nb_descente){ // fonction qui permet  faire descendre une piece dans le cas où le joueur à choisi la colonne A,B,C,D,E,F
	tab.x = choix_colonne;     
	tab.y = TAILLE-1 + nb_descente;
	
	int o,i;
	int res,test;
	int indice=1;
	
	int vrai = 1;
	for(o=tab.y;o<=tab.y+3;o++){
		for(int p=tab.x;p<=tab.x +3;p++){
			if(grille[o-3][p]=='@'){
				grille[o+1][p]	= grille[o-3][p];
				grille[o-3][p] = ' ';
			}
		}
	}
	
		
	
	
			
	
}

void origine_principale(piece tab,int choix_colonne,int choix,char grille[LENGTH2][LENGTH2],int nb_descente){ //la position d'origine de la matrice de la piece est en haut à gauche
	
	int k = 0;
	int n = 0;	
	int i;
	int j;
	int loop;
	tab.x = choix_colonne;     
	tab.y = TAILLE-1;

	
	
	for(i=0;i<0+4;i++){
		for(j=choix_colonne;j<choix_colonne+4;j++){
			
			grille[i][j] =	tab.forme_piece[choix][n][k]; // on place la matrice de la pièce dans la gri
			k = k + 1;	
		}
		k = 0;
		n= n +1;
	}


	
	for(loop=0;loop<nb_descente;loop++){
		descendre1(tab,choix_colonne,choix,grille,loop*4);
	}
	affichetableau(grille,LENGTH2);
	
}



int collision_horizontale(piece tab,int choix_colonne,int choix,char grille[LENGTH2][LENGTH2]){ // la fonction renvoie le nombre de fois de fois que l'on peut déplacer la matrice avant collision
	int compteur = 0;
	int n = 0;
	int nb_descente = 0;
	int ord = TAILLE-1 + nb_descente;
	int o,p;
	int y = 3;
	int vrai=1;
	tab.x = choix_colonne;     
	tab.y = TAILLE-1 + nb_descente;
	while(vrai==1){
		ord = TAILLE-1 + nb_descente;
		for(o=ord;o<=ord+3;o++){
			for(p=tab.x;p<=tab.x +3;p++){
				if(grille[o-3][p]=='@'){
					grille[o+1][p]	= grille[o-3][p];
					grille[o-3][p] = ' ';
				}   
			}
		}
		affichetableau(grille,LENGTH2);
		compteur = compteur + 1;
		n = n+1;
		nb_descente = n*4;
		
		if(grille[y+4][p]=='1'){
			vrai = 0;
			
		}
		y = y+4;
		
	}
	for(int ordo=y-3;ordo<=y;ordo++){
		for(int px=choix_colonne;px<=choix_colonne +3;px++){
			
			if (grille[ordo][px] == '@'){
				grille[ordo][px] = ' ';
			}
		}
	}
	affichetableau(grille,LENGTH2);
	return compteur;
	
}

void descendre2(piece tab,int choix_colonne,int choix,char grille[LENGTH2][LENGTH2]){ // fonction qui permet  faire descendre une piece dans le cas où le joueur à choisi la colonne G,H,I,J
	tab.x = choix_colonne-1;     
	tab.y = TAILLE-1;
	for(int o=tab.y;o<tab.y+4;o++){
		for(int p=tab.x-3;p<=tab.x+1;p++){
			
			grille[o+1][p]	= grille[o-3][p];
			grille[o-3][p] = ' ';
		}
	}
	affichetableau(grille,LENGTH2);	
}
void changement_origine(piece tab,int choix_colonne,int choix,char grille[LENGTH2][LENGTH2]){ //  je me suis dit que si je conserve la position d'origine en haut à gauche, j'aurai un problème si le joueur demande la colonne G,H,I,J du coup j'ai changé la position d'origine. Cette fois-ci, elle se situe en haut à droite
	int k = 0;
	int n = 0;	
	int i,j;
	
	
	
	for(int i=0;i<0+4;i++){
		for(j=choix_colonne-3;j<=choix_colonne;j++){
			
			grille[i][j] =tab.forme_piece[choix][n][k]; // on place la matrice de la pièce dans la grille
			k = k + 1;	
		}
		k = 0;
		n= n +1;
	}

	affichetableau(grille,LENGTH2);
	
	descendre2(tab,choix_colonne,choix,grille);

	
}

void placerpiece(piece tab,int choix,char grille[LENGTH2][LENGTH2],int colonne){ //fonction qui va placer la piece
	int choix_colonne;
	int k = 0;
	int n = 0;	
	int i,res;
	int j;
	choix_colonne = (colonne % 65)+1;
	if(choix_colonne>=6){
		decaler_matrice(tab,choix_colonne,choix);
		changement_origine(tab,choix_colonne,choix, grille);	
	}
	else{
		decaler_matrice(tab,choix_colonne,choix);
		res = collision_horizontale(tab,choix_colonne,choix, grille);
		origine_principale(tab,choix_colonne,choix, grille,res);
		
	}

	
}

void affichetableau(char tab[LENGTH2][LENGTH2],int taille){ // cette fonction va afficher le tableau, il est tout d'abord vide puis le sera complété avec des caractères '@'
	printf("Voici la grille : \n");
	
	printf("\n");
	for(int i=4;i<taille-2;i++){
	
			if(i==4){

				for(int k=65;k<65+10;k++){	
					printf("  %c",k);
				}
				printf("\n");	
			}
			for(int j=1;j<taille-6;j++){ 
				printf("|%c ",tab[i][j]);
				
			}
		
			printf("\n");
		}

}
