#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/prenotazione.h"

// converte stringa in minuscolo
void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// controlla anno bisestile
int isBisestile(int anno) {
    return (anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0);
}

// controlla validità data
int dataValida(int giorno, int mese, int anno) {
    if (anno < 1900 || anno > 2100) return 0;
    if (mese < 1 || mese > 12) return 0;
    if (giorno < 1) return 0;

    int giorniMese[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (mese == 2 && isBisestile(anno)) {
        giorniMese[1] = 29;
    }

    if (giorno > giorniMese[mese - 1]) return 0;

    return 1;
}

void inserisciPrenotazione() {
    Prenotazione p;
    int risultato;
    char c;
    int valida;

    // 🔹 MATRICOLA
    do {
        printf("Inserisci matricola (max 6 cifre): ");
        risultato = scanf("%d%c", &p.matricola, &c);

        if (risultato != 2 || c != '\n') {
            printf("Errore! Inserisci SOLO un numero.\n");
            while (getchar() != '\n');
            continue;
        }

        if (p.matricola <= 0 || p.matricola > 999999) {
            printf("Matricola non valida!\n");
        }

    } while (risultato != 2 || c != '\n' || p.matricola <= 0 || p.matricola > 999999);

    // 🔹 POSTO
    do {
        printf("Inserisci posto (1-100): ");
        risultato = scanf("%d%c", &p.posto, &c);

        if (risultato != 2 || c != '\n') {
            printf("Errore! Inserisci SOLO un numero.\n");
            while (getchar() != '\n');
            continue;
        }

        if (p.posto < 1 || p.posto > 100) {
            printf("Posto non valido!\n");
        }

    } while (risultato != 2 || c != '\n' || p.posto < 1 || p.posto > 100);

    // 🔹 DATA COMPLETA
    int giorno, mese, anno;

    do {
        valida = 1;

        printf("Inserisci data (gg/mm/aaaa): ");
        scanf("%s", p.data);

        if (strlen(p.data) != 10 || p.data[2] != '/' || p.data[5] != '/') {
            valida = 0;
        }

        // controllo numeri
        for (int i = 0; i < 10; i++) {
            if (i == 2 || i == 5) continue;

            if (!isdigit(p.data[i])) {
                valida = 0;
            }
        }

        if (valida) {
            sscanf(p.data, "%d/%d/%d", &giorno, &mese, &anno);

            if (!dataValida(giorno, mese, anno)) {
                valida = 0;
            }
        }

        if (!valida) {
            printf("Data non valida!\n");
        }

    } while (!valida);

    // 🔹 FASCIA ORARIA
    do {
        printf("Inserisci fascia (mattina/pomeriggio): ");
        scanf("%s", p.fascia_oraria);

        toLowerCase(p.fascia_oraria);

        if (strcmp(p.fascia_oraria, "mattina") != 0 &&
            strcmp(p.fascia_oraria, "pomeriggio") != 0) {

            printf("Fascia non valida!\n");
        }

    } while (strcmp(p.fascia_oraria, "mattina") != 0 &&
             strcmp(p.fascia_oraria, "pomeriggio") != 0);

    printf("Prenotazione inserita correttamente!\n");
}