/**
 * @file main.c
 *
 * Programma principale per la gestione dei cittadini in un ufficio postale.
 * @authors Birardi Leonardo, De Martino Luca, Lippolis Alessandra
 * @version 1.0
 * @date 16-06-2023
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "CittadinoCoda.h"
#include "Funzioni.h"
#include "GestoreFile.h"
#include "InputOutput.h"

int main()
{
    /// Crea la coda per i cittadini
    Coda *codaCittadini = coda_crea();

    /// Log
    scrivi_log("Avvio del gestionale.");

    /// Grafica di Benvenuto in console
    visualizza_benvenuto();

    /// Visualizzazione in console e Gestione delle scelte dell'utente.
    int scelta;
    do
    {
        scelta = visualizza_menu();
        gestore_scelta(scelta, codaCittadini);
    } while (scelta != 4);

    /// Distrugge la coda
    coda_distruggi(codaCittadini);

    scrivi_log("Terminazione del gestionale.");

    return 0;
}
