#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    double a, b;
    while (1) {
        printf("Entrez un op�rateur (+, -, *, /), "
            "pour quitter, appuyez sur x : ");
        scanf(" %c", &ch);

        // pour quitter
        if (ch == 'x')
            exit(0);
        printf("Entrez le premier et le second nombre : ");
        scanf("%lf %lf", &a, &b);

        // op�rations bas�es sur l'op�rateur diff�rent
        switch (ch) {

        // Pour l'Addition
        case '+':
            printf("%.1lf + %.1lf = %.1lf\n", a, b, a + b);
            break;

        // Pour la Soustraction
        case '-':
            printf("%.1lf - %.1lf = %.1lf\n", a, b, a - b);
            break;

        // Pour la Multiplication
        case '*':
            printf("%.1lf * %.1lf = %.1lf\n", a, b, a * b);
            break;

        // Pour la Division
        case '/':
            if (b == 0) {
                printf("Erreur : Division par zero !\n");
            } else {
                printf("%.1lf / %.1lf = %.1lf\n", a, b, a / b);
            }
            break;

        // Si l'op�rateur ne correspond � aucun cas constant
        default:
            printf("Erreur ! Veuillez �crire un op�rateur valide\n");
        }

        printf("\n");
    }
}

