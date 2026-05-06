#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

typedef struct {
    int matricola;
    int posto;
    char data[20];
    char fascia_oraria[20];
} Prenotazione;

void inserisciPrenotazione();

#endif