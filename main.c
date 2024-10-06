#include <stdio.h>
#include "tic-tac-toe.h"

int main()
{
	char plateau[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	int tour = 0;
	int victoire = 0;

	while (!victoire){
		afficherPlateau(plateau);

		if (tour == 0)
		{
			joueur(plateau);
		} else {
			computer(plateau);
		}

		victoire = verifVictoire(plateau);

		if (victoire)
		{
			afficherPlateau(plateau);
			if (tour == 0)
			{
				printf("Vous avez gagné !\n");
			} else {
				printf("L'ordinateur a gagné\n");
			}
			break;
		}

 		int plein = 1;
 		for (int i = 0; i < 9; ++i)
 		{
 			if (plateau[i] == ' ')
 			{
 				plein = 0;
 				break;
 			}
 		}
 		if (plein)
 		{
 			afficherPlateau(plateau);
 			printf("Match nul.\n");
 			break;
 		}

 		tour = !tour;
 	}

	return 0;
}