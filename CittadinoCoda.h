#ifndef CITTADINOCODA_H_INCLUDED
#define CITTADINOCODA_H_INCLUDED

/**
 * @file CittadinoCoda.h
 * Dichiarazione dell'ADT Coda e delle relative operazioni.
 */

/**
 * Struttura del nodo della coda.
 */
typedef struct Nodo Nodo;

/**
 * Struttura dell'ADT Coda.
 */
typedef struct Coda Coda;

/**
 * Crea e restituisce una nuova coda vuota.
 * @return Puntatore alla nuova coda creata.
 */
Coda* coda_crea();

/**
 * Inserisce un cittadino nella coda.
 * @param coda Puntatore alla coda.
 * @param CodiceArrivo Codice di arrivo del cittadino.
 * @param CodiceFiscale Codice fiscale del cittadino.
 * @param NumeroBollettinoPostale Numero del bollettino postale del cittadino.
 * @param MeseScadenzaBollettino Mese di scadenza del bollettino postale del cittadino.
 * @param ImportoBollettino Importo del bollettino postale del cittadino.
 */
void coda_inserisci(Coda* coda, char CodiceArrivo[3], char CodiceFiscale[17], int NumeroBollettinoPostale, char MeseScadenzaBollettino[11], int ImportoBollettino);

/**
 * Rimuove il cittadino in testa alla coda.
 * @param coda Puntatore alla coda.
 */
void coda_rimuovi(Coda* coda);

/**
 * Legge il cittadino in testa alla coda senza rimuoverlo.
 * @param coda Puntatore alla coda.
 * @param CodiceArrivo Codice di arrivo del cittadino (output).
 * @param CodiceFiscale Codice fiscale del cittadino (output).
 * @param NumeroBollettinoPostale Numero del bollettino postale del cittadino (output).
 * @param MeseScadenzaBollettino Mese di scadenza del bollettino postale del cittadino (output).
 * @param ImportoBollettino Importo del bollettino postale del cittadino (output).
 */
void coda_primo(Coda* coda, char CodiceArrivo[3], char CodiceFiscale[17], int* NumeroBollettinoPostale, char MeseScadenzaBollettino[11], int* ImportoBollettino);

/**
 * Verifica se la coda e' vuota.
 * @param coda Puntatore alla coda.
 * @return 1 se la coda e' vuota, 0 altrimenti.
 */
int coda_vuota(Coda* coda);

/**
 * Distrugge la coda e dealloca la memoria.
 * @param coda Puntatore alla coda da distruggere.
 */
void coda_distruggi(Coda* coda);

/**
 * Imposta il flag di acquisizione a positivo.
 */
void SetFlagPositivo();

/**
 * Imposta il flag di acquisizione a negativo.
 */
void SetFlagNegativo();

/**
 * Restituisce il valore corrente del flag di acquisizione.
 * @return Valore del flag di acquisizione (0 o 1).
 */
int GetFlagAcquisizione();

#endif // CITTADINOCODA_H_INCLUDED
