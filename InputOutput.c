/**
 * @file InputOutput.c
 * Source file per le funzioni di input e output dei dati dei cittadini
 */
#include <stdio.h>
#include <unistd.h>

#include "InputOutput.h"
#include "Validatore.h"


/**
 * Visualizza i dati di un cittadino in testa alla coda
 * @pre coda Puntatore alla coda dei cittadini
 */
void visualizza_cittadino(Coda* coda) {
    char CodiceArrivo[3];
    char CodiceFiscale[17];
    int NumeroBollettinoPostale;
    char MeseScadenzaBollettino[11];
    int ImportoBollettino;

    // Legge i dati del cittadino in testa alla coda
    coda_primo(coda, CodiceArrivo, CodiceFiscale, &NumeroBollettinoPostale, MeseScadenzaBollettino, &ImportoBollettino);

    // Visualizza i dati del cittadino
    printf(" Cittadino in testa alla coda:\n");
    visualizza_struttura(CodiceArrivo, CodiceFiscale, NumeroBollettinoPostale, MeseScadenzaBollettino, ImportoBollettino);
}

/**
 * Visualizza i dati di tutti i cittadini nella coda
 * @pre coda e' un puntatore alla coda e deve essere non NULL.
 */
void visualizza_cittadini(Coda* coda) {
    printf(" Cittadini nella coda:\n\n");

    // Crea una coda temporanea per mantenere l'ordine originale dei cittadini
    Coda* codaTemp = coda_crea();

    // Visualizza i dati dei cittadini uno alla volta e li inserisce nella coda temporanea
    while (!coda_vuota(coda)) {
        char CodiceArrivo[3];
        char CodiceFiscale[17];
        int NumeroBollettinoPostale;
        char MeseScadenzaBollettino[11];
        int ImportoBollettino;

        // Legge i dati del cittadino in testa alla coda
        coda_primo(coda, CodiceArrivo, CodiceFiscale, &NumeroBollettinoPostale, MeseScadenzaBollettino, &ImportoBollettino);

        // Visualizza i dati del cittadino
        visualizza_struttura(CodiceArrivo, CodiceFiscale, NumeroBollettinoPostale, MeseScadenzaBollettino, ImportoBollettino);

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
}

/**
 * Visualizza i dati del cittadino relativi al bollettino postale
 * @pre CodiceArrivo deve essere una stringa di 2 caratteri alfanumerici.
 * @pre CodiceFiscale deve essere una stringa di 16 caratteri alfanumerici.
 * @pre NumeroBollettinoPostale deve essere un numero intero.
 * @pre MeseScadenzaBollettino deve essere una stringa non nulla di massimo 10 caratteri alfabetici, scritto in lettere minuscole e deve essere un mese dell'anno.
 * @pre ImportoBollettino deve essere un numero intero.
 * @post stampa voliri di input
 */
void visualizza_struttura(char CodiceArrivo[3], char CodiceFiscale[17], int NumeroBollettinoPostale, char MeseScadenzaBollettino[11], int ImportoBollettino) {
    // Visualizza i dati del cittadino
    printf(" Codice di arrivo: %s\n", CodiceArrivo);
    printf(" Codice fiscale: %s\n", CodiceFiscale);
    printf(" Numero bollettino postale: %d\n", NumeroBollettinoPostale);
    printf(" Mese scadenza bollettino: %s\n", MeseScadenzaBollettino);
    printf(" Importo bollettino: %d\n\n", ImportoBollettino);
}

/**
 * Visualizza Messaggio di Benvenuto in Console
 * @post stampa il messaggio di benvenuto
 */
void visualizza_benvenuto() {
    puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts(" ||                                                                                                              ||");
    puts(" ||                             LE DIAMO IL BENVENUTO NEL GESTIONALE DELL'UFFICIO POSTALE                        ||");
    puts(" ||                                                                                                              ||");
    puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

/**
 * Visualizza Menu' con opzioni selezionabili dall'utente
 * @post stampa un menu
 * @post stampa risultato scelta
 */
int visualizza_menu() {
    int scelta = 0;

    puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts(" ||    Di Seguito le Funzionalita' di Dominio disponibili                                                        ||");
    puts(" ||       1) Acquisizione Cittadini da File con Visualizzazione.                                                 ||");
    puts(" ||       2) Ricerca Cittadino Minimo e Massimo in coda con Visualizzazione e Memorizzazione su File.            ||");
    puts(" ||       3) Modifica Cittadini in coda con Visualizzazione dei cittadini Modificati e Memorizzazione su File.   ||");
    puts(" ||       4) Chiudi Gestionale.                                                                                  ||");
    puts(" ||                                                                                                              ||");
    puts(" ||                           Inserire il numero dell'opzione desiderata [1/2/3].                                ||");
    puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n Scelta: ");
    scanf("%d", &scelta);

    while(scelta > 4 || scelta < 1) {
        puts(" Ops! L'opzione inserita non e' corretta. Riprova con un valore valido [1/2/3].");
        printf(" Scelta: ");
        scanf("%d", &scelta);
    }

    return scelta;
}
 /**
  * Chiusura gestione
  * @post messaggio di chiusura gestione
  */
void visualizza_chiusura_gestionale() {
    printf(" Chiusura del gestionale in corso");
    for(int i = 0; i < 3; i++) {
        sleep(1);
        printf(".");
    }
    printf("\n Arrivederla.");
}

/**
 * Acquisisce mese scadenza
 * @pre stringa del nomeFile che non deve essere NULL
 * @post stampa a schermo se il nomeFile non e' valido altrimenti ritorna nomeFile
 */
char* acquisisci_nome_file(char* nomeFile) {
    do {
        printf(" Inserisci il nome del file di input (estensione .txt): ");
        scanf("%99s", nomeFile);
    } while(!validatore_file(nomeFile));

    return nomeFile;
}

/**
 * Acquisisce mese scadenza
 * @pre stringa del codeice fiscale che non deve essere NULL
 * @post stampa a schermo se il codice fiscale e' valido
 */
void acquisisci_codice_fiscale(char* CF) {
    printf(" Inserire il Codice Fiscale del cittadino che si vuole modificare: ");
    scanf("%16s", CF);

    while(!valida_codice_fiscale(CF)) {
        printf(" Codice Fiscale non valido.\n Inserire il Codice Fiscale del cittadino che si vuole modificare: ");
        scanf("%16s", CF);
    }
}

/**
 * Acquisisce mese scadenza
 * @pre stringa di MeseScadenzaBollettino che non deve essere NULL
 * @post stampa a schermo se MeseScadenzaBollettino e' valido
 */
void acquisisci_mese_scadenza_bollettino(char* MeseScadenzaBollettino) {
    printf(" Inserire il nuovo Mese di scadenza del Bollettino in minuscolo: ");
    scanf("%10s", MeseScadenzaBollettino);

    while(!valida_mese_scadenza(MeseScadenzaBollettino)) {
        printf(" Mese non valido.\n Inserire il nuovo Mese di scadenza del Bollettino in minuscolo: ");
        scanf("%10s", MeseScadenzaBollettino);
    }
}

/**
 * Acquisisce importo bollettino
 * @pre putatore ad intero di ImportoBollettino che non deve essere NULL
 * @post stampa a schermo se importo e' valido
 */
void acquisisci_importo_bollettino(int* ImportoBollettino) {
    printf(" Inserire il nuovo Importo del Bollettino: ");
    scanf("%d", ImportoBollettino);

    while(!valida_importo_bollettino(ImportoBollettino)) {
        printf(" Importo non valido.\n Inserire il nuovo Importo del Bollettino: ");
        scanf("%d", ImportoBollettino);
    }
}



