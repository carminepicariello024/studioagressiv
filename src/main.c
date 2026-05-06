#include <stdio.h>

int main() {
    int scelta;
    int risultato;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Inserisci elemento\n");
        printf("2. Visualizza elementi\n");
        printf("0. Esci\n");
        printf("Scelta: ");

        risultato = scanf("%d", &scelta);

        if (risultato != 1) {
            printf("Input non valido! Inserisci un numero.\n");

            while (getchar() != '\n'); 
            scelta = -1;
            continue;
        }

        switch(scelta) {
            case 1:
                printf("Hai scelto Inserisci\n");
                break;

            case 2:
                printf("Hai scelto Visualizza\n");
                break;

            case 0:
                printf("Uscita dal programma\n");
                break;

            default:
                printf("Scelta non valida\n");
        }

    } while(scelta != 0);

    return 0;
}