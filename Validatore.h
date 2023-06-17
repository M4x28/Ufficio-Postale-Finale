#ifndef VALIDATORE_H_INCLUDED
#define VALIDATORE_H_INCLUDED

#include <stdbool.h>

#include "CittadinoCoda.h"

/**
 * @file validatore.h
 * Modulo per la validazione dei campi e degli input.
 */

/**
 * Verifica se un codice di arrivo e' valido.
 * @param codice_arrivo Codice di arrivo da verificare.
 * @return 1 se il codice di arrivo e' valido, 0 altrimenti.
 */
bool valida_codice_arrivo(const char *codice_arrivo);

/**
 * Verifica se un codice fiscale e' valido.
 * @param codice_fiscale Codice fiscale da verificare.
 * @return 1 se il codice fiscale e' valido, 0 altrimenti.
 */
bool valida_codice_fiscale(const char *codice_fiscale);

/**
 * Verifica se un numero di bollettino postale e' valido.
 * @param numero Numero di bollettino postale da verificare.
 * @return 1 se il numero di bollettino postale e' valido, 0 altrimenti.
 */
bool valida_numero_bollettino(const char *numero);

/**
 * Verifica se un mese di scadenza del bollettino postale e' valido.
 * @param mese Mese di scadenza del bollettino postale da verificare.
 * @return 1 se il mese di scadenza del bollettino postale e' valido, 0 altrimenti.
 */
bool valida_mese_scadenza(const char *mese);

/**
 * Verifica se un importo di bollettino postale e' valido.
 * @param importo Importo del bollettino postale da verificare.
 * @return 1 se l'importo del bollettino postale e' valido, 0 altrimenti.
 */
bool valida_importo_bollettino(int importo);

/**
 * Verifica se il nome del file e' valido.
 * @param nome_file Nome del file da verificare.
 * @return 1 se il nome del file e' valido, 0 altrimenti.
 */
bool valida_nome_file(const char *nome_file);

/**
 * Verifica se l'estensione del file e' valida.
 * @param nome_file Nome del file da verificare.
 * @return 1 se l'estensione del file e' valida, 0 altrimenti.
 */
bool valida_estensione_file(const char *nome_file);

/**
 * Verifica se il file e' valido.
 * @param nome_file Nome del file da verificare.
 * @return 1 se il file e' valido, 0 altrimenti.
 */
bool validatore_file(const char *nomeFile);

#endif // VALIDATORE_H_INCLUDED
