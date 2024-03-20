#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jeu(char toi, char ordinateur)
{
	if (toi == ordinateur)
		return -1;

	if (toi == 's' && ordinateur == 'p')
		return 0;

	else if (toi == 'p' && ordinateur == 's') return 1;

	if (toi == 's' && ordinateur == 'z')
		return 1;

	else if (toi == 'z' && ordinateur == 's')
		return 0;

	if (toi == 'p' && ordinateur == 'z')
		return 0;

	else if (toi == 'z' && ordinateur == 'p')
		return 1;
}

int main()
{
	int n;

	char toi, ordinateur, resultat;

	srand(time(NULL));

	n = rand() % 100;

	if (n < 33)
		ordinateur = 's';

	else if (n > 33 && n < 66)
		ordinateur = 'p';

	else
		ordinateur = 'z';

	printf("\n\n\n\n\t\t\t\tEntrez s pour PIERRE, p pour PAPIER et z pour CISEAUX\n\t\t\t\t\t\t\t");

	scanf("%c", &toi);

	resultat = jeu(toi, ordinateur);

	if (resultat == -1) {
		printf("\n\n\t\t\t\tMatch Nul!\n");
	}
	else if (resultat == 1) {
		printf("\n\n\t\t\t\tBravo! Vous avez gagne le jeu!\n");
	}
	else { 
		printf("\n\n\t\t\t\tOh! Vous avez perdu le jeu!\n");
	}
		printf("\t\t\t\tVous avez choisi : %c et l'ordinateur a choisi : %c\n", toi, ordinateur);

	return 0;
}

