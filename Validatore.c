/**
 * @file Validatore.c
 * Implementazione delle funzioni per la validazione dei campi e degli input.
 */
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "GestoreFile.h"
#include "Validatore.h"

/**
 * Verifica la validita' di un codice di arrivo. Un codice di arrivo e' valido se e' composto da due caratteri alfanumerici.
 * @pre codice_arrivo non deve essere NULL
 * @post il valore di ritorno e' 0 o 1
 */
bool valida_codice_arrivo(const char *codice_arrivo)
{
    // Verifica che il codice di arrivo sia composto da due caratteri alfanumerici
    if (strlen(codice_arrivo) != 2)
        return false;

    for (int i = 0; i < 2; i++)
    {
        if (!isalnum(codice_arrivo[i]))
            return false;
    }

    return true;
}

/**
 * Questa funzione controlla che il codice fiscale sia composto da 16 caratteri alfanumerici.
 * @pre codice_arrivo non deve essere NULL
 * @post 1 se il codice fiscale e' valido, 0 altrimenti
 */
bool valida_codice_fiscale(const char *codice_fiscale)
{
    // Verifica che il codice fiscale sia composto da 16 caratteri alfanumerici
    if (strlen(codice_fiscale) != 16)
        return false;

    for (int i = 0; i < 16; i++)
    {
        if (!isalnum(codice_fiscale[i]))
            return false;
    }

    return true;
}

/**
 * Valida un numero di bollettino postale. Un numero di bollettino postale e' valido se e' un intero positivo e ha una lunghezza almeno di 5 caratteri numerici.
 * @pre importo deve essere un numero intero
 * @post 1 se il numero e' valido, 0 altrimenti
 */
bool valida_numero_bollettino(const char *numero)
{
    // Verifica che il numero di bollettino postale sia un intero positivo
    // e abbia una lunghezza al meno di 5 caratteri numerici
    int length = strlen(numero);

    if (length < 5)
        return false;

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(numero[i]))
            return false;
    }

    int num = atoi(numero);
    return (num > 0);
}

/**
 * Verifica la validita' del mese di scadenza di una carta di credito.
 * @pre mese deve essere uno dei seguenti valori: "gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio", "agosto", "settembre", "ottobre", "novembre", "dicembre".
 * @post 1 se il mese e' valido, 0 altrimenti.
 */
bool valida_mese_scadenza(const char *mese)
{
    // Verifica che il mese di scadenza sia uno tra "gennaio", "febbraio", ..., "dicembre"
    char mesi[12][10] = {"gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio", "agosto",
                         "settembre", "ottobre", "novembre", "dicembre"};

    for (int i = 0; i < 12; i++)
    {
        if (strcmp(mese, mesi[i]) == 0)
            return true;
    }

    return false;
}

/**
 * Verifica la validita' dell'importo di un bollettino postale
 * @param importo L'importo del bollettino in euro
 * @return 1 se l'importo e' positivo, 0 altrimenti
 */
bool valida_importo_bollettino(int importo)
{
    // Verifica che l'importo del bollettino postale sia positivo
    return (importo > 0);
}

/**
 * Verifica se il nome del file e' valido
 * @pre nome_file deve essere una stringa non nulla
 * @post 1 se il nome del file non e' vuoto, 0 altrimenti
 */
bool valida_nome_file(const char *nomeFile)
{
    // Verifica la lunghezza del nome del file
    if (strlen(nomeFile) > 100)
    {
        return false;
    }

    // Verifica la presenza di caratteri non ammessi
    const char *caratteriNonAmmessi = ":*?\"<>|";
    for (int i = 0; i < strlen(caratteriNonAmmessi); i++)
    {
        if (strchr(nomeFile, caratteriNonAmmessi[i]) != NULL)
        {
            return false;
        }
    }

    return true;
}

/**
 * Verifica che l'estensione del file sia .txt
 * @pre nome_file deve essere una stringa non nulla
 * @post 1 se il file ha estensione .txt, 0 altrimenti
 */
bool valida_estensione_file(const char *nome_file)
{
    // Verifica che l'estensione del file sia .txt
    const char *estensione = ".txt";
    const char *punto = strrchr(nome_file, '.');

    if (punto == NULL)
        return 0;

    return (strcmp(punto, estensione) == 0);
}

/**
 * Validatore Percorso File inserito dall'utente
 * @pre nome_file deve essere una stringa non nulla
 * @post 1 se il file supera tutti i controlli, altrimenti 0
 */
bool validatore_file(const char *nomeFile)
{
    bool flagValiditaFile = true;

    /// Verifica nomeFile e che l'estensione del file sia .txt
    if (!valida_nome_file(nomeFile))
    {
        printf(" Nome del file non valido. Assicurati di inserire un file con un nome corretto.\n");
        flagValiditaFile = false;
    }
    /// Valida Estensione File
    if (!valida_estensione_file(nomeFile))
    {
        printf(" Estensione del file non valida. Assicurati di inserire un file .txt.\n");
        flagValiditaFile = false;
    }
    /// Se il percorso del file fornito e' corretto, allora verifico la sua esistenza effettiva
    if (flagValiditaFile)
    {
        FILE *file;
        if (apri_file(nomeFile, "r", &file) == 0)
        {
            printf(" Il file da lei specificato e' inesistente. Assicurati di inserire il percorso corretto.\n");
            flagValiditaFile = false;
        }
    }

    return flagValiditaFile;
}
