/**
 * @file Funzioni.c
 * Le funzioni implementano le operazioni sulla coda dei cittadini e sul file MinMax.txt e Modifica.txt.
 */
#include <stdlib.h>
#include <string.h>

#include "CittadinoCoda.h"
#include "Funzioni.h"
#include "GestoreFile.h"
#include "InputOutput.h"
#include "Validatore.h"

/**
 * Trova il cittadino con il numero di bollettino postale minimo e il cittadino con il numero di bollettino postale massimo nella coda dei cittadini, li stampa a schermo e li inserisce nel file MinMax.txt.
 * @pre coda e' un puntatore alla coda e deve essere diverso da NULL.
 */
void minMAX(Coda *coda) {
    // Crea una coda temporanea per mantenere l'ordine originale dei cittadini
    Coda* codaTemp = coda_crea();
    // Crea una coda temporanea per min e MAX
    Coda* codaminMax = coda_crea();

    scrivi_log("Inizio ricerca min e Max");

    char minCodiceArrivo[3];
    char minCodiceFiscale[17];
    int minNumeroBollettinoPostale;
    char minMeseScadenzaBollettino[11];
    int minImportoBollettino;
    char MAXCodiceArrivo[3];
    char MAXCodiceFiscale[17];
    int MAXNumeroBollettinoPostale;
    char MAXMeseScadenzaBollettino[11];
    int MAXImportoBollettino;
    char CodiceArrivo[3];
    char CodiceFiscale[17];
    int NumeroBollettinoPostale;
    char MeseScadenzaBollettino[11];
    int ImportoBollettino;

    // Legge i dati del cittadino in testa alla coda
    coda_primo(coda, minCodiceArrivo, minCodiceFiscale, &minNumeroBollettinoPostale, minMeseScadenzaBollettino, &minImportoBollettino);
    coda_primo(coda, MAXCodiceArrivo, MAXCodiceFiscale, &MAXNumeroBollettinoPostale, MAXMeseScadenzaBollettino, &MAXImportoBollettino);

    // Visualizza i dati dei cittadini uno alla volta e li inserisce nella coda temporanea
    while (!coda_vuota(coda)) {

        // Legge i dati del cittadino in testa alla coda
        coda_primo(coda, CodiceArrivo, CodiceFiscale, &NumeroBollettinoPostale, MeseScadenzaBollettino, &ImportoBollettino);

        if((minNumeroBollettinoPostale > NumeroBollettinoPostale) || ((minNumeroBollettinoPostale == NumeroBollettinoPostale) && (strcmp(minCodiceFiscale, CodiceFiscale) > 0))) {
            minNumeroBollettinoPostale = NumeroBollettinoPostale;
            minImportoBollettino = ImportoBollettino;
            strcpy(minCodiceArrivo, CodiceArrivo);
            strcpy(minCodiceFiscale, CodiceFiscale);
            strcpy(minMeseScadenzaBollettino, MeseScadenzaBollettino);
        }

        if((MAXNumeroBollettinoPostale < NumeroBollettinoPostale) || ((minNumeroBollettinoPostale == NumeroBollettinoPostale) && (strcmp(minCodiceFiscale, CodiceFiscale) < 0))) {
            MAXNumeroBollettinoPostale = NumeroBollettinoPostale;
            MAXImportoBollettino = ImportoBollettino;
            strcpy(MAXCodiceArrivo, CodiceArrivo);
            strcpy(MAXCodiceFiscale, CodiceFiscale);
            strcpy(MAXMeseScadenzaBollettino, MeseScadenzaBollettino);
        }

        // Rimuove il cittadino dalla coda principale e lo inserisce nella coda temporanea
        coda_inserisci(codaTemp, CodiceArrivo, CodiceFiscale, NumeroBollettinoPostale, MeseScadenzaBollettino, ImportoBollettino);
        coda_rimuovi(coda);
    }

    // Ripristina i cittadini nella coda principale dalla coda temporanea
    while (!coda_vuota(codaTemp)) {
        char CodiceArrivo[3];
        char CodiceFiscale[17];
        int NumeroBollettinoPostale;
        char MeseScadenzaBollettino[11];
        int ImportoBollettino;

        // Legge i dati del cittadino in testa alla coda temporanea
        coda_primo(codaTemp, CodiceArrivo, CodiceFiscale, &NumeroBollettinoPostale, MeseScadenzaBollettino, &ImportoBollettino);

        // Inserisce il cittadino nella coda principale
        coda_inserisci(coda, CodiceArrivo, CodiceFiscale, NumeroBollettinoPostale, MeseScadenzaBollettino, ImportoBollettino);

        // Rimuove il cittadino dalla coda temporanea
        coda_rimuovi(codaTemp);
    }

    // Distrugge la coda temporanea
    coda_distruggi(codaTemp);

    // Popola Coda Min e Max
    coda_inserisci(codaminMax, minCodiceArrivo, minCodiceFiscale, minNumeroBollettinoPostale, minMeseScadenzaBollettino, minImportoBollettino);
    coda_inserisci(codaminMax, MAXCodiceArrivo, MAXCodiceFiscale, MAXNumeroBollettinoPostale, MAXMeseScadenzaBollettino, MAXImportoBollettino);

    // Visualizzo Cittadino Minimo e Massimo
    puts(" Cittadino Minimo e Massimo:");
    visualizza_cittadini(codaminMax);

    // Salvo su File Min e Max
    scrivi_file(codaminMax, "file/MinMax.txt");
    puts(" Esportazione min e Max avvenuta con successo! (file/MinMax.txt)\n");
    scrivi_log("Esportazione min e Max avvenuta con successo! (file/MinMax.txt)");

    // Distrugge la coda temporanea
    coda_distruggi(codaminMax);

    scrivi_log("Fine ricerca min e Max");
}

/**
 * Modifica gli elementi di un cittadino nella coda.
 * @pre coda e' un puntatore alla coda e deve essere diverso da NULL.
 * @pre codaModificati e' un puntatore alla coda e deve essere diverso da NULL.
 */
void modifica_cittadino(Coda* coda, Coda* codaModificati) {
    // Crea una coda temporanea per mantenere l'ordine originale dei cittadini
    Coda* codaTemp = coda_crea();

    /// Acquisizione con Validazione del CF in input da tastiera
    char CodiceFiscaleTmp[17];
    acquisisci_codice_fiscale(CodiceFiscaleTmp);

    sprintf(messaggio, "Inizio modifica cittadino: %s", CodiceFiscaleTmp);
    scrivi_log(messaggio);

    // Visualizza i dati dei cittadini uno alla volta e li inserisce nella coda temporanea
    while (!coda_vuota(coda)) {
        char CodiceArrivo[3];
        char CodiceFiscale[17];
        int NumeroBollettinoPostale;
        char MeseScadenzaBollettino[11];
        int ImportoBollettino;

        // Legge i dati del cittadino in testa alla coda
        coda_primo(coda, CodiceArrivo, CodiceFiscale, &NumeroBollettinoPostale, MeseScadenzaBollettino, &ImportoBollettino);

        // Rimuove il cittadino dalla coda principale e lo inserisce nella coda temporanea
        coda_inserisci(codaTemp, CodiceArrivo, CodiceFiscale, NumeroBollettinoPostale, MeseScadenzaBollettino, ImportoBollettino);

        if(strcmp(CodiceFiscale, CodiceFiscaleTmp) == 0) {
            /// Input MeseScadenzaBollettino e ImportoBollettino con Validazione
            acquisisci_mese_scadenza_bollettino(MeseScadenzaBollettino);
            acquisisci_importo_bollettino(&ImportoBollettino);

            coda_inserisci(codaModificati, CodiceArrivo, CodiceFiscale, NumeroBollettinoPostale, MeseScadenzaBollettino, ImportoBollettino);
        }
        coda_rimuovi(coda);
    }

    // Ripristina i cittadini nella coda principale dalla coda temporanea
    while (!coda_vuota(codaTemp)) {
        char CodiceArrivo[3];
        char CodiceFiscale[17];
        int NumeroBollettinoPostale;
        char MeseScadenzaBollettino[11];
        int ImportoBollettino;

        // Legge i dati del cittadino in testa alla coda temporanea
        coda_primo(codaTemp, CodiceArrivo, CodiceFiscale, &NumeroBollettinoPostale, MeseScadenzaBollettino, &ImportoBollettino);

        // Inserisce il cittadino nella coda principale
        coda_inserisci(coda, CodiceArrivo, CodiceFiscale, NumeroBollettinoPostale, MeseScadenzaBollettino, ImportoBollettino);

        // Rimuove il cittadino dalla coda temporanea
        coda_rimuovi(codaTemp);
    }

    // Distrugge la coda temporanea
    coda_distruggi(codaTemp);

    sprintf(messaggio, "Fine modifica cittadino: %s", CodiceFiscaleTmp);
    scrivi_log(messaggio);
}

/**
 * Modifica gli elementi dei cittadini nella coda con Visualizzazione e Memorizzazione su File.
 * @pre coda e' un puntatore alla coda e deve essere diverso da NULL.
 */
void modifica_cittadini(Coda* coda) {
    Coda* codaModificati = coda_crea();
    int flagContinua = 1;
    char scelta;

    while(flagContinua) {
        modifica_cittadino(coda, codaModificati);

        printf(" Vuoi modificare altri utenti? [S/N]\n ");
        scanf(" %c", &scelta);
        if(scelta == 'n' || scelta == 'N')
            flagContinua = 0;
    }

    printf("\n Coda degli utenti modificati:\n");
    visualizza_cittadini(codaModificati);

    // Salvo su File Min e Max
    scrivi_file(codaModificati, "file/Modifica.txt");
    puts(" Esportazione Modifiche avvenuta con successo! (file/Modifica.txt)\n");
    scrivi_log("Esportazione Modifiche avvenuta con successo! (file/Modifica.txt)");

    // Distrugge la coda temporanea
    coda_distruggi(codaModificati);
}

/**
 * Gestore scelta utente
 * @pre scelta definito come intero
 * @pre codaCittadini e' la coda.
 * @post stampa menu per la scelta utente
 * @post stampa il risultato della scelta
 */
void gestore_scelta(int scelta, Coda* codaCittadini) {
    sprintf(messaggio, "Opzione scelta: %d", scelta);
    scrivi_log(messaggio);

    switch(scelta) {
    case 1:
        if(!GetFlagAcquisizione()) {
            // Legge i cittadini dal file e li inserisce in coda
            char nomeFile[100];
            leggi_file(acquisisci_nome_file(nomeFile), codaCittadini);
            /// Imposto il flag di acquisizione del file in input con i cittadini a 1 in modo tale da evitare di riaggiungere gli stessi cittadini in coda
            SetFlagPositivo();

            // Visualizza tutti i cittadini in coda
            visualizza_cittadini(codaCittadini);
        } else
            printf(" Acquisizione gia' effettuata.\n\n");
        break;
    case 2:
        // Visualizza e Memorizza Min e MAX Cittadini
        if(GetFlagAcquisizione()) {
            minMAX(codaCittadini);
        } else
            puts(" Deve prima popolare il gestionale per poter effettuare la ricerca del min e del Max.\n");
        break;
    case 3:
        /// Modifica con Visualizzazione e Memorizzazione dei cittadini modificati
        if(GetFlagAcquisizione()) {
            modifica_cittadini(codaCittadini);
        } else
            puts(" Deve prima popolare il gestionale per poter apportare modifiche ai cittadini in coda.\n");
        break;
    case 4:
        visualizza_chiusura_gestionale();
        break;
    default:
        printf(" Opzione non valida. Uscita dal gestionale...");
        exit(0);
    }
}
