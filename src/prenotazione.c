#include <string.h>
#include <stdio.h>
#include "../include/prenotazione.h"

void inserisciPrenotazione() {
    Prenotazione p;
    int risultato_1; 
    int risultato_2;
do {
    printf("Inserisci matricola (max 6 cifre): ");
    risultato_1 = scanf("%d", &p.matricola);

    if (risultato_1 != 1) {
        printf("Errore! Inserisci un numero.\n");
        while (getchar() != '\n');
        continue;
    }

    if (p.matricola <= 0 || p.matricola > 999999) {
        printf("Matricola non valida!\n");
    }

} while (risultato_1 != 1 || p.matricola <= 0 || p.matricola > 999999);
    

    do {
    printf("Inserisci posto (1-100): ");
    risultato_2 = scanf("%d", &p.posto);

    if (risultato_2 != 1) {
        printf("Errore! Inserisci un numero.\n");
        while (getchar() != '\n');
        continue;
    }

    if (p.posto < 1 || p.posto > 100) {
        printf("Posto non valido!\n");
    }

} while (risultato_2 != 1 || p.posto < 1 || p.posto > 100);

    do {
    printf("Inserisci data (gg/mm/aaaa): ");
    scanf("%s", p.data);

    if (strlen(p.data) != 10 || p.data[2] != '/' || p.data[5] != '/') {
        printf("Formato data non valido!\n");
    }

} while (strlen(p.data) != 10 || p.data[2] != '/' || p.data[5] != '/');

    do {
    printf("Inserisci fascia oraria (mattina/pomeriggio): ");
    scanf("%s", p.fascia_oraria);

    if (strcmp(p.fascia_oraria, "mattina") != 0 &&
        strcmp(p.fascia_oraria, "pomeriggio") != 0) {

        printf("Fascia non valida!\n");
    }

} while (strcmp(p.fascia_oraria, "mattina") != 0 &&
         strcmp(p.fascia_oraria, "pomeriggio") != 0);

    printf("Prenotazione inserita!\n");
}