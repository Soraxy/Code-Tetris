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
		
			printf("  ");
			for(int j=0;j<TAILLE;j++){
				for(int k=0;k<TAILLE;k++){
				switch(tab.forme_piece[j][choix][k]) {
					case 'O': printf("\033[40;31m@\033[40;37m"); 
						break;
					case 'I': 
						 printf("\033[40;32m@\033[40;37m"); 
						break;
					case 'T': 
						 printf("\033[40;33m@\033[40;37m"); 
						break;
					case 'L': 
						 printf("\033[40;34m@\033[40;37m"); 
						break;
					case 'J': 
						 printf("\033[40;35m@\033[40;37m"); 
						break;
					case 'Z': 
						 printf("\033[40;36m@\033[40;37m"); 
						break;
					case 'S': 
						 printf("\033[40;37m@\033[40;37m"); 
						break;
					default: printf(" ");
					} 
				}
	printf("   ");		}
		
}	




int chosir_orientation(piece tab){ //demande a l'utilisateur l'orientation de la pièce
	int orientation = 0;
	int choix;
	do{
		printf("\nveuillez choisir une orientation. entrez un numéro entre 0 et 3 (0 ET 3 inclus)\n\n");
			for(int i=0;i<TAILLE;i++){
					affiche_orientation_piece(tab,i);
					printf("\n");
			}
			printf("\n   0?     1?     2?     3?");
		printf("\n\nQuel est votre orientation ?\n");
		if(scanf("%d",&choix)==0) break;
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
			tab[i][0] = '1';	
		}
	}
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			tab[14][j] = '2';	
		}
	}
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			tab[i][11] = '3';	
		}
	}
}
int choisir_colonne(){
	int temp;
	char lettre;

	do{
		printf("veuillez choisir une lettre comprise entre (A-J)\n");
		scanf("%c",&lettre);
		temp = (int)lettre;	
	}while(temp>74||temp<65);
	printf("lettre vaut %c",lettre);
	return temp;
}
void descendre1(piece tab,int choix_colonne,int choix,char grille[LENGTH2][LENGTH2]){ // fonction qui permet  faire descendre une piece dans le cas où le joueur à choisi la colonne A,B,C,D,E,F
	tab.x = choix_colonne;     
	tab.y = TAILLE-1;
	while(tab.forme_piece[choix][3][0]!=2||tab.forme_piece[choix][3][1]!=2||tab.forme_piece[choix][3][3]!=2||tab.forme_piece[choix][3][3]!=2){
	grille[tab.x-1][tab.y-1]=grille[tab.x][tab.y];
}
		

}

void origine_principale(piece tab,int choix_colonne,int choix,char grille[LENGTH2][LENGTH2]){ //la position d'origine de la matrice de la piece est en haut à gauche
	
	int k = 0;
	int n = 0;	
	int i;
	int j;
	tab.x = choix_colonne;     
	tab.y = TAILLE-1;
	printf("tab.x vaut %d\n",tab.x);
	
	for(i=0;i<0+4;i++){
		for(j=choix_colonne;j<choix_colonne+4;j++){
			
			grille[i][j] =	tab.forme_piece[choix][n][k]; // on place la matrice de la pièce dans la gri
			k = k + 1;	
		}
		k = 0;
		n= n +1;
	}
	//descendre1(tab,choix_colonne,choix,grille);
	affichetableau(grille,LENGTH2);
		
}

/*int collision_verticale(piece tab,char** grille){
	while (tab.forme_piece!=2){
		descendre1(tab,choix_colonne,choix,grille);	
	
}

int collision(piece tab,int choix_colonne,int choix,char **grille){
	//collision_horizontale(tab,choix_colonne,choix,grille)

	collision_verticale(tab,choix_colonne,choix,grille);
	
}*/
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
void changement_origine(piece tab,int choix_colonne,int choix,char grille[LENGTH2][LENGTH2]){ // en gros je me suis dit que si je conserve la position d'origine en haut à gauche, j'aurai un problème si le joueur demande la colonne G,H,I,J du coup j'ai changé la position d'origine. Cette fois-ci, elle se situe en haut à droite
	int k = 0;
	int n = 0;	
	int i,j;
	printf("tab.x vaut %d\n",tab.x);
	
	
	for(int i=0;i<0+4;i++){
		for(j=choix_colonne-3;j<=choix_colonne;j++){


			//istrue = collision(piece tab,int choix,int choix_colonne,char **grille);
			grille[i][j] =tab.forme_piece[choix][n][k]; // on place la matrice de la pièce dans la grille
			k = k + 1;	
		}
		k = 0;
		n= n +1;
	}

	
	descendre2(tab,choix_colonne,choix,grille);
	
}

//ecrireCase(char grille[LENGTH2][LENGTH2],int colonne){

void placerpiece(piece tab,int choix,char grille[LENGTH2][LENGTH2],int colonne){
	int choix_colonne;
	int k = 0;
	int n = 0;	
	int i;
	int j;
	choix_colonne = (colonne % 65)+1;
	if(choix_colonne>=6){
		changement_origine(tab,choix_colonne,choix, grille);	
	}
	else{
		
		origine_principale(tab,choix_colonne,choix, grille);
	}

	
}

void affichetableau(char tab[LENGTH2][LENGTH2],int taille){ // cette fonctionva afficher le tableau, il est tout d'abord vide puis le sera complété avec des caractères '@'
	printf("Voici la grille : \n");
	printf("   ");
	for(int k=65;k<65+10;k++){
		printf("  %c",k);
	}
	printf("\n");
	for(int i=0;i<taille;i++){
	
			if(i==4){
				printf("   ");
				for(int k=65;k<65+10;k++){	
					printf("  %c",k);
				}
				printf("\n");	
			}
			for(int j=0;j<taille;j++){
					switch(tab[i][j]){
						case 'O': printf("|\033[40;31m@\033[40;37m ");
							break;
						case 'I': printf("|\033[40;32m@\033[40;37m ");
							break;
						case 'T': printf("|\033[40;33m@\033[40;37m ");
							break;
						case 'L': printf("|\033[40;34m@\033[40;37m ");
							break;
						case 'J': printf("|\033[40;35m@\033[40;37m ");
							break;
						case 'Z': printf("|\033[40;36m@\033[40;37m ");
							break;
						case 'S': printf("|\033[40;37m@\033[40;37m ");
							break;
						default: printf("|%c ",tab[i][j]);
							break;
					}
			}
		
			printf("\n");
		}






}
