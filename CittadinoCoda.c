/** @file CittadinoCoda.h
 *  Questo file contiene le definizioni delle strutture e delle funzioni per la creazione e la manipolazione di una coda di cittadini.
 */
#include <stdlib.h>
#include <string.h>

#include "CittadinoCoda.h"


// Definizione della struttura Cittadino
typedef struct Cittadino {
    char CodiceArrivo[3];                     /**< Codice di arrivo del cittadino */
    char CodiceFiscale[17];                   /**< Codice fiscale del cittadino */
    int NumeroBollettinoPostale;              /**< Numero del bollettino postale del cittadino */
    char MeseScadenzaBollettino[11];          /**< Mese di scadenza del bollettino postale del cittadino */
    int ImportoBollettino;                    /**< Importo del bollettino postale del cittadino */
} Cittadino;

// Struttura per il nodo della coda
typedef struct Nodo {
    Cittadino cittadino;                      /**< Cittadino contenuto nel nodo */
    struct Nodo* prossimo;                    /**< Puntatore al prossimo nodo */
} Nodo;

// Struttura per la coda
struct Coda {
    Nodo* testa;                              /**< Puntatore alla testa della coda */
    Nodo* coda;                               /**< Puntatore alla coda della coda */
};

/**
 * Crea e restituisce una nuova coda vuota.
 * @post Puntatore alla nuova coda creata.
 */
Coda* coda_crea() {
    Coda* coda = (Coda*)malloc(sizeof(Coda));            // Allocazione della memoria per la coda
    coda->testa = NULL;                                   // Inizializzazione della testa della coda
    coda->coda = NULL;                                    // Inizializzazione della coda della coda
    return coda;
}

/**
 * Inserisce un cittadino nella coda.
 * @pre coda e' un puntatore alla coda e deve essere non NULL.
 * @pre CodiceArrivo deve essere una stringa di 2 caratteri alfanumerici.
 * @pre CodiceFiscale deve essere una stringa di 16 caratteri alfanumerici.
 * @pre NumeroBollettinoPostale deve essere un numero intero.
 * @pre MeseScadenzaBollettino deve essere una stringa non nulla di massimo 10 caratteri alfabetici, scritto in lettere minuscole e deve essere un mese dell'anno.
 * @pre ImportoBollettino deve essere un numero intero.
 */
void coda_inserisci(Coda* coda, char CodiceArrivo[3], char CodiceFiscale[17], int NumeroBollettinoPostale, char MeseScadenzaBollettino[11], int ImportoBollettino) {
    // Creazione del nuovo nodo
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nuovoNodo->cittadino.CodiceArrivo, CodiceArrivo);
    strcpy(nuovoNodo->cittadino.CodiceFiscale, CodiceFiscale);
    nuovoNodo->cittadino.NumeroBollettinoPostale = NumeroBollettinoPostale;
    strcpy(nuovoNodo->cittadino.MeseScadenzaBollettino, MeseScadenzaBollettino);
    nuovoNodo->cittadino.ImportoBollettino = ImportoBollettino;
    nuovoNodo->prossimo = NULL;

    if (coda->coda == NULL) {
        // La coda è vuota, il nuovo nodo diventa sia la testa che la coda
        coda->testa = nuovoNodo;
        coda->coda = nuovoNodo;
    } else {
        // Il nuovo nodo viene aggiunto alla coda
        coda->coda->prossimo = nuovoNodo;
        coda->coda = nuovoNodo;
    }
}

/**
 * Rimuove il cittadino in testa alla coda.
 * @pre coda e' un puntatore alla coda e deve essere non NULL.
 */
void coda_rimuovi(Coda* coda) {
    if (coda->testa != NULL) {
        Nodo* nodoRimosso = coda->testa;
        coda->testa = coda->testa->prossimo;

        if (coda->testa == NULL) {
            // La coda è vuota, la coda diventa NULL
            coda->coda = NULL;
        }

        free(nodoRimosso);
    }
}

/**
 * Legge il cittadino in testa alla coda senza rimuoverlo.
 * @pre coda e' un puntatore alla coda e deve essere non NULL.
 * @pre CodiceArrivo deve essere una stringa di 2 caratteri alfanumerici.
 * @pre CodiceFiscale deve essere una stringa di 16 caratteri alfanumerici.
 * @pre NumeroBollettinoPostale deve essere un numero intero.
 * @pre MeseScadenzaBollettino deve essere una stringa non nulla di massimo 10 caratteri alfabetici, scritto in lettere minuscole e deve essere un mese dell'anno.
 * @pre ImportoBollettino deve essere un numero intero.
 */
void coda_primo(Coda* coda, char CodiceArrivo[3], char CodiceFiscale[17], int* NumeroBollettinoPostale, char MeseScadenzaBollettino[11], int* ImportoBollettino) {
    if (coda->testa != NULL) {
        Nodo* nodoPrimo = coda->testa;
        strcpy(CodiceArrivo, nodoPrimo->cittadino.CodiceArrivo);
        strcpy(CodiceFiscale, nodoPrimo->cittadino.CodiceFiscale);
        *NumeroBollettinoPostale = nodoPrimo->cittadino.NumeroBollettinoPostale;
        strcpy(MeseScadenzaBollettino, nodoPrimo->cittadino.MeseScadenzaBollettino);
        *ImportoBollettino = nodoPrimo->cittadino.ImportoBollettino;
    }
}

/**
 * Verifica se la coda e' vuota.
 * @pre coda e' un puntatore alla coda e deve essere non NULL.
 * @post ritorna 0 o 1.
 */
int coda_vuota(Coda* coda) {
    return (coda->testa == NULL);
}

/**
 * Distrugge la coda e dealloca la memoria.
 * @pre coda e' un puntatore alla coda e deve essere diverso da NULL.
 */
void coda_distruggi(Coda* coda) {
    while (coda->testa != NULL) {
        Nodo* nodoRimosso = coda->testa;
        coda->testa = coda->testa->prossimo;
        free(nodoRimosso);
    }
    coda->coda = NULL;
    free(coda);
}

// Variabile globale per la gestione del flag di acquisizione
int FlagAcquisizione = 0;

/**
 * Imposta il flag di acquisizione a positivo.
 */
void SetFlagPositivo()
{
    FlagAcquisizione = 1;
}

/**
 * Imposta il flag di acquisizione a negativo.
 */
void SetFlagNegativo()
{
    FlagAcquisizione = 0;
}

/**
 * Restituisce il valore corrente del flag di acquisizione.
 * @return Valore del flag di acquisizione (0 o 1).
 */
int GetFlagAcquisizione()
{
    return FlagAcquisizione;
}
