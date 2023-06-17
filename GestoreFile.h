#ifndef GESTOREFILE_H_INCLUDED
#define GESTOREFILE_H_INCLUDED

#include <stdio.h>

#include "CittadinoCoda.h"

#define MAX_DIM_LOG 100

char messaggio[MAX_DIM_LOG];  // Dichiarazione di un array di caratteri per contenere il messaggio di log

/**
 * Apre il file specificato in modalita' specificata.
 *
 * @param nome_file Nome del file da aprire.
 * @param modo Modalita' di apertura del file (es. "r" per lettura, "w" per scrittura).
 * @param file Puntatore a un puntatore a FILE che conterra' il puntatore al file aperto.
 * @return 1 se l'apertura del file ha avuto successo, altrimenti 0.
 */
int apri_file(const char* nome_file, const char* modo, FILE** file);

/**
 * Legge il contenuto del file specificato riga per riga.
 *
 * @param nome_file Nome del file da leggere.
 */
void leggi_file(const char* nome_file, Coda* coda);

/**
 * Chiude il file specificato.
 *
 * @param file Puntatore al file da chiudere.
 * @return 0 se la chiusura e' avvenuta con successo, 1 in caso di errore.
 */
int chiudi_file(FILE* file);

/**
 * Apre un file per la scrittura e salva all'interno tutti gli elementi della coda.
 * @param coda Puntatore alla coda.
 * @param nome_file Nome del file da creare o sovrascrivere.
 * @return 1 se il file e' stato aperto e i dati sono stati scritti correttamente, 0 altrimenti.
 */
int scrivi_file(Coda* coda, const char* nome_file);

/**
 * Log Operazioni Utente.
 * @param Messaggio del log.
 */
void scrivi_log(const char* messaggio);

#endif // GESTOREFILE_H_INCLUDED
