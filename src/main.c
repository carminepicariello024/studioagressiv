#include <stdio.h>
#include "../include/prenotazione.h"

int main() {
    int scelta, risultato;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Inserisci prenotazione\n");
        printf("2. Visualizza prenotazioni\n");
        printf("3. Elimina prenotazione\n");
        printf("0. Esci\n");
        printf("Scelta: ");

        risultato = scanf("%d", &scelta);

        if (risultato != 1) {
            printf("Input non valido!\n");
            while (getchar() != '\n');
            continue;
        }

        switch(scelta) {
            case 1:
                inserisciPrenotazione();
                break;
            case 2:
                visualizzaPrenotazioni();
                break;
            case 3:
                eliminaPrenotazione();
                break;
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida\n");
        }

    } while(scelta != 0);

    return 0;
}