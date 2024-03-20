#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    double a, b;
    while (1) {
        printf("Entrez un opérateur (+, -, *, /), "
            "pour quitter, appuyez sur x : ");
        scanf(" %c", &ch);

        // pour quitter
        if (ch == 'x')
            exit(0);
        printf("Entrez le premier et le second nombre : ");
        scanf("%lf %lf", &a, &b);

        // opérations basées sur l'opérateur différent
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

        // Si l'opérateur ne correspond à aucun cas constant
        default:
            printf("Erreur ! Veuillez écrire un opérateur valide\n");
        }

        printf("\n");
    }
}

