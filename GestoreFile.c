/**
* @file GestoreFile.c
* Implementazione delle funzioni per la gestione dei file di testo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "CittadinoCoda.h"
#include "GestoreFile.h"
#include "validatore.h"

#define MAX_DIM_RIGA 40


/**
 * Apre un file di testo in un determinato modo.
 * @pre nome_file una stringa non nulla.
 * @pre modo e' una stringa non nulla.
 * @pre file e' un puntatore al puntatore al file e deve essere non NULL.
 * @post 1 se il file e' stato aperto con successo, 0 altrimenti.
 */
int apri_file(const char* nome_file, const char* modo, FILE** file) {
    *file = fopen(nome_file, modo);
    if (*file == NULL) {
        printf(" Errore: impossibile aprire il file '%s'.\n", nome_file);
        return 0;
    }
    return 1;
}

/**
 * Legge i dati dei cittadini da un file di testo e li inserisce in una coda. Se il file contiene meno di 3 cittadini validi, il programma termina con un messaggio di errore.
 * @pre nome_file una stringa non nulla.
 * @pre modo e' una stringa non nulla.
 * @pre file e' un puntatore al puntatore al file e deve essere non NULL.
 * @post valori 1 o 0.
 */
void leggi_file(const char* nome_file, Coda* coda) {
    FILE* file;
    char riga[MAX_DIM_RIGA];

    if (apri_file(nome_file, "r", &file) == 0) {
        puts(" Impossibile Aprire il file specificato.");
        exit(0);
    }

    sprintf(messaggio, "Inizio lettura file: %s", nome_file);
    scrivi_log(messaggio);

    int numero_cittadini = 0;

    while (fgets(riga, MAX_DIM_RIGA, file) != NULL) {
        /// Eliminazione spazi,tab e a capo di fine file per evitare loop infinito
        if (riga[0] == '\t' || riga[0] == '\n' || riga[0] == '\r')
            break;

        char* codice_arrivo = strtok(riga, "#");
        char* codice_fiscale = strtok(NULL, "#");
        char* numero_bollettino = strtok(NULL, "#");
        char* mese_scadenza = strtok(NULL, "#");
        char* importo_bollettino = strtok(NULL, "#");


        if (!valida_codice_arrivo(codice_arrivo)) {
            printf(" Errore: codice arrivo non valido nella riga '%s'.\n", riga);
            continue;
        }

        if (!valida_codice_fiscale(codice_fiscale)) {
            printf(" Errore: codice fiscale non valido nella riga '%s'.\n", riga);
            continue;
        }

        if (!valida_numero_bollettino(numero_bollettino)) {
            printf(" Errore: numero bollettino postale non valido nella riga '%s'.\n", riga);
            continue;
        }
        int numero_bollettino_int = atoi(numero_bollettino);

        if (!valida_mese_scadenza(mese_scadenza)) {
            printf(" Errore: mese di scadenza non valido nella riga '%s'. Assicurati che sia minuscolo.\n", riga);
            continue;
        }

        int importo = atoi(importo_bollettino);
        if (!valida_importo_bollettino(importo)) {
            printf(" Errore: importo bollettino postale non valido nella riga '%s'.\n", riga);
            continue;
        }

        numero_cittadini++;

        coda_inserisci(coda, codice_arrivo, codice_fiscale, numero_bollettino_int, mese_scadenza, importo);
    }

    chiudi_file(file);

    if (numero_cittadini < 3) {
        puts(" Il file in input non contiene abbastanza Cittadini per procedere con l'elaborazione.");
        coda_distruggi(coda);
        exit(0);
    }

    sprintf(messaggio, "Fine lettura file: %s", nome_file);
    scrivi_log(messaggio);
}

/**
 * Scrive i dati contenuti in una coda su un file di testo.
 * @pre coda e' il parametro della coda e non deve essere NULL.
 * @pre nome_file deve essere una stringa non vuota.
 * @post ritorna 0 o 1.
 */
int scrivi_file(Coda* coda, const char* nome_file) {
    FILE* file;
    if (!apri_file(nome_file, "w", &file)) {
        printf("Errore nell'apertura del file '%s'.\n", nome_file);
        return 0;
    }

    sprintf(messaggio, "Inizio scrittura file: %s", nome_file);
    scrivi_log(messaggio);

    while (!coda_vuota(coda)) {
        char codiceArrivo[3];
        char codiceFiscale[17];
        int numeroBollettinoPostale;
        char meseScadenzaBollettino[11];
        int importoBollettino;

        coda_primo(coda, codiceArrivo, codiceFiscale, &numeroBollettinoPostale, meseScadenzaBollettino, &importoBollettino);

        fprintf(file, "%s#%s#%d#%s#%d\n", codiceArrivo, codiceFiscale, numeroBollettinoPostale, meseScadenzaBollettino, importoBollettino);

        coda_rimuovi(coda);
    }

    chiudi_file(file);

    sprintf(messaggio, "Fine lettura file: %s", nome_file);
    scrivi_log(messaggio);

    return 1;
}

/**
 * Chiude il file aperto.
 * @pre file e' il puntatore al file e deve essere diverso da NULL.
 * @post ritorna 0 o 1.
 */
int chiudi_file(FILE* file) {
    if(!fclose(file))
        return 0;
    else
        return 1;
}

/**
 * Log Operazioni Utente.
 * @pre messaggio del log non deve essere NULL.
 */
void scrivi_log(const char* messaggio) {
    FILE* file = fopen("file/log.txt", "a"); // Apre il file in modalità "append"

    if (file == NULL)
        file = fopen("log.txt", "a"); // Apre il file nella stessa cartella dell'eseguibile se non trova la cartella file.

    if (file != NULL) {
        time_t timestamp = time(NULL);
        struct tm* tempo = localtime(&timestamp);

        // Ottiene la data e l'ora corrente
        char data_ora[20];
        strftime(data_ora, sizeof(data_ora), "%Y-%m-%d %H:%M:%S", tempo);

        // Scrive il messaggio di log nel file
        fprintf(file, "[%s] %s\n", data_ora, messaggio);

        fclose(file);
    } else {
        printf(" Errore nell'apertura del file di log.\n");
    }
}
