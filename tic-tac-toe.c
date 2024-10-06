#include <stdio.h>
#include "tic-tac-toe.h"

void afficherPlateau(char *plateau){
	printf("\n");
	for (int i = 0; i < 9; ++i)
	{
		if (i % 3 == 0 && i !=0)
		{
			printf("\n-----------\n");
		}
		printf(" %c ", plateau[i]);
		if (i % 3 != 2)
		{
			printf("|");
		}
	}
	printf("\n");
}

int verifVictoire(char *plateau){
	int combinaisons [8][3] = {
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8},
		{0, 4, 8}, {2, 4, 6}
	};

	for (int i = 0; i < 8; ++i)
	{
		if (plateau[combinaisons[i][0]] == plateau[combinaisons[i][1]] &&
			plateau[combinaisons[i][1]] == plateau[combinaisons[i][2]] &&
			plateau[combinaisons[i][0]] != ' ')
		{
			return 1;		}
	}
	return 0;
}

void joueur(char *plateau){
	int choix;
	printf("Entrez le numéro de la case (0-8) ou vous voulez jouer : ");
	scanf("%d", &choix);
	while (choix < 0 || choix > 8 || plateau[choix] != ' '){
		printf("Case invalide, réessayez : ");
		scanf("%d", &choix);
	}
	plateau[choix] = 'X';

	printf("Le joueur a choisi la case %d\n", choix);
	printf("Le plateau du joueur après le choix du joueur : \n");
	afficherPlateau(plateau);
}

void computer(char *plateau){
	for (int i = 0; i < 9; ++i)
	{
		if (plateau[i] == ' ')
		{
			plateau[i] = 'O';

			printf("L'ordinateur a choisi la case %d\n", i);
			printf("Le plateau après le choix de l'ordianteur : \n");
			afficherPlateau(plateau);

			break;
		}
	}
}