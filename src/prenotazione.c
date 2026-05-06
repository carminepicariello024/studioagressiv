#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../include/prenotazione.h"

Nodo* testa = NULL;

// 🔹 controllo data (anno fisso 2026)
int dataValida(int g, int m, int a) {
    if (a != 2026) return 0;
    if (m < 1 || m > 12) return 0;
    if (g < 1) return 0;

    int giorni[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (g > giorni[m-1]) return 0;

    return 1;
}

// 🔥 controllo duplicati
int esistePrenotazione(Prenotazione p) {
    Nodo* temp = testa;

    while (temp != NULL) {
        // stessa matricola
        if (temp->p.matricola == p.matricola) {
            printf("Errore: matricola già esistente!\n");
            return 1;
        }

        // stesso posto + data + ora
        if (temp->p.posto == p.posto &&
            strcmp(temp->p.data, p.data) == 0 &&
            strcmp(temp->p.fascia_oraria, p.fascia_oraria) == 0) {

            printf("Errore: posto già occupato in quella data e ora!\n");
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

void inserisciPrenotazione() {
    Prenotazione p;
    int risultato;
    char c;
    int valida;

    // MATRICOLA
    do {
        printf("Inserisci matricola (max 6 cifre): ");
        risultato = scanf("%d%c", &p.matricola, &c);

        if (risultato != 2 || c != '\n') {
            printf("Errore! Inserisci SOLO numeri.\n");
            while (getchar() != '\n');
            continue;
        }

        if (p.matricola <= 0 || p.matricola > 999999) {
            printf("Matricola non valida!\n");
        }

    } while (risultato != 2 || c != '\n' || p.matricola <= 0 || p.matricola > 999999);

    // POSTO
    do {
        printf("Inserisci posto (1-100): ");
        risultato = scanf("%d%c", &p.posto, &c);

        if (risultato != 2 || c != '\n') {
            printf("Errore! Inserisci SOLO numeri.\n");
            while (getchar() != '\n');
            continue;
        }

        if (p.posto < 1 || p.posto > 100) {
            printf("Posto non valido!\n");
        }

    } while (risultato != 2 || c != '\n' || p.posto < 1 || p.posto > 100);

    // DATA (anno fisso 2026)
    int g, m, a;

    do {
        valida = 1;

        printf("Inserisci data (gg/mm/aaaa) [solo 2026]: ");
        scanf("%s", p.data);

        if (strlen(p.data) != 10 || p.data[2] != '/' || p.data[5] != '/') {
            valida = 0;
        }

        for (int i = 0; i < 10; i++) {
            if (i == 2 || i == 5) continue;
            if (!isdigit(p.data[i])) valida = 0;
        }

        if (valida) {
            sscanf(p.data, "%d/%d/%d", &g, &m, &a);

            if (!dataValida(g, m, a)) {
                valida = 0;
            }
        }

        if (!valida) printf("Data non valida (solo anno 2026)!\n");

    } while (!valida);

    // ORARIO
    int ora, minuti;

    do {
        valida = 1;

        printf("Inserisci orario (hh:mm): ");
        scanf("%s", p.fascia_oraria);

        if (strlen(p.fascia_oraria) != 5 || p.fascia_oraria[2] != ':') {
            valida = 0;
        }

        for (int i = 0; i < 5; i++) {
            if (i == 2) continue;
            if (!isdigit(p.fascia_oraria[i])) valida = 0;
        }

        if (valida) {
            sscanf(p.fascia_oraria, "%d:%d", &ora, &minuti);

            if (ora < 8 || ora > 20 || minuti < 0 || minuti > 59) {
                printf("Orario non valido! (08:00 - 20:00)\n");
                valida = 0;
            }
        }

        if (!valida) printf("Formato orario non valido!\n");

    } while (!valida);

    // 🔥 CONTROLLA DUPLICATI
    if (esistePrenotazione(p)) {
        printf("Prenotazione NON inserita.\n");
        return;
    }

    // LISTA
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));

    if (nuovo == NULL) {
        printf("Errore memoria!\n");
        return;
    }

    nuovo->p = p;
    nuovo->next = testa;
    testa = nuovo;

    printf("Prenotazione salvata!\n");
}

// VISUALIZZA
void visualizzaPrenotazioni() {
    Nodo* temp = testa;

    if (temp == NULL) {
        printf("Nessuna prenotazione.\n");
        return;
    }

    int i = 1;

    while (temp != NULL) {
        printf("\nPrenotazione %d\n", i);
        printf("Matricola: %d\n", temp->p.matricola);
        printf("Posto: %d\n", temp->p.posto);
        printf("Data: %s\n", temp->p.data);
        printf("Orario: %s\n", temp->p.fascia_oraria);

        temp = temp->next;
        i++;
    }
}

// ELIMINA
void eliminaPrenotazione() {
    if (testa == NULL) {
        printf("Nessuna prenotazione.\n");
        return;
    }

    int mat, risultato;
    char c;

    do {
        printf("Inserisci matricola da eliminare: ");
        risultato = scanf("%d%c", &mat, &c);

        if (risultato != 2 || c != '\n') {
            printf("Errore input.\n");
            while (getchar() != '\n');
        }

    } while (risultato != 2 || c != '\n');

    Nodo* temp = testa;
    Nodo* prev = NULL;

    if (temp != NULL && temp->p.matricola == mat) {
        testa = temp->next;
        free(temp);
        printf("Eliminata!\n");
        return;
    }

    while (temp != NULL && temp->p.matricola != mat) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Non trovata.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Eliminata!\n");
}