#ifndef FUNZIONI_H_INCLUDED
#define FUNZIONI_H_INCLUDED

/**
 * Trova il cittadino con il numero di bollettino postale minimo e massimo nella coda.
 *
 * @param[in] coda Puntatore alla coda.
 */
void minMAX(Coda* coda);

/**
 * Modifica cittadino nella coda.
 *
 * @param[in] coda Puntatore alla coda.
 * @param[in] codaModificati Puntatore alla coda dei cittadini modificati.
 */
void modifica_cittadino(Coda* coda, Coda* codaModificati);

/**
 * Modifica piu' cittadini nella coda.
 *
 * @param[in] coda Puntatore alla coda.
 */
void modifica_cittadini(Coda* coda);

/**
 * Gestore delle funzioni da richiamare in base alla scelta effettuata dall'utente
 *
 * @param[in] scelta scleta fatta dall'utente (gia' validata).
 * @param[in] coda Puntatore alla coda.
 */
void gestore_scelta(int scelta, Coda* codaCittadini);

#endif // FUNZIONI_H_INCLUDED
