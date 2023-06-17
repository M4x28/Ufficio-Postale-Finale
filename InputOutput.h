#ifndef INPUTOUTPUT_H_INCLUDED
#define INPUTOUTPUT_H_INCLUDED

#include "CittadinoCoda.h"

/**
 * Visualizza i dati del cittadino in testa alla coda.
 * @param coda Puntatore alla coda.
 */
void visualizza_cittadino(Coda *coda);

/**
 * Visualizza i dati di tutti i cittadini nella coda.
 * @param coda Puntatore alla coda.
 */
void visualizza_cittadini(Coda *coda);

/**
 * Visualizza la struttura dei dati di un cittadino.
 * @param CodiceArrivo Codice di arrivo del cittadino.
 * @param CodiceFiscale Codice fiscale del cittadino.
 * @param NumeroBollettinoPostale Numero del bollettino postale del cittadino.
 * @param MeseScadenzaBollettino Mese di scadenza del bollettino postale del cittadino.
 * @param ImportoBollettino Importo del bollettino postale del cittadino.
 */
void visualizza_struttura(char CodiceArrivo[3], char CodiceFiscale[17], int NumeroBollettinoPostale, char MeseScadenzaBollettino[11], int ImportoBollettino);

/// Visualizza in console l'interfaccia di benvenutp
void visualizza_benvenuto();

/// Visualizza in console l'interfaccia di chiusura del gestionale
void visualizza_chiusura_gestionale();

/**
 * Visualizza Menu' con opzioni selezionabili dall'utente
 * @return Opzione scelta dall'utente valore di tipo int in range [1,4]
 */
int visualizza_menu();

/**
 * Acquisisce il nome del file da input.
 * @param nomeFile Puntatore alla variabile in cui viene memorizzato il nome del file.
 * @return Puntatore alla variabile contenente il nome del file.
*/
char *acquisisci_nome_file(char *nomeFile);

/**
 * Acquisisce il codice fiscale da input.
 * @param CF Puntatore alla variabile in cui viene memorizzato il codice fiscale.
*/
void acquisisci_codice_fiscale(char *CF);

/**
 * Acquisisce il mese di scadenza del bollettino postale da input.
 * @param MeseScadenzaBollettino Puntatore alla variabile in cui viene memorizzato il mese di scadenza.
*/
void acquisisci_mese_scadenza_bollettino(char *MeseScadenzaBollettino);

/**
 * Acquisisce l'importo del bollettino postale da input.
 * @param ImportoBollettino Puntatore alla variabile in cui viene memorizzato l'importo.
 */
void acquisisci_importo_bollettino(int *ImportoBollettino);

#endif // INPUTOUTPUT_H_INCLUDED
