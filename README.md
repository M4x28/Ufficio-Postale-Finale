# Ufficio-Postale-Finale
Progetto in C simulazione coda Ufficio Postale

Usando la modularizzazione per dato astratto, scrivere un programma in C che fornisca, da menù uente, le seguenti funzionalità di dominio per gestione di cittadini in un ufficio postale:</br>
</br>1. Acquisizione, da un file precedentemente creato dallo studente, di dati di almeno tre cittadini.</br>
                  i. Una riga del file contiene i dati di un cittadino, più precisamente CodiceArrivo, CodicelFiscale, NumeroBollettinoPostale, MeseScadenzaBollettino, ImportoBollettino
                     separati da simbolo '#' come qui illustrato:</br>
                   &nbsp;&nbsp;&nbsp;&nbsp;• 131#XXXRRR111AAAAAAA#010101#giugno#40</br>
                   &nbsp;&nbsp;&nbsp;&nbsp;• A2#YYYRRR1222BBBBBB#12345#1uglio#400</br>
                   &nbsp;&nbsp;&nbsp;&nbsp;• Al#YYYRRR222CCCCCCC#565656#1uglio#700</br>
                 ii. Il nome del file deve essere fornito da tastiera dall'utente.</br>
                 iii. Visualizzazione dei dati a console.</br>
                 iv. Impiegare una struttura dati a coda.</br>
</br>
2. Ricercare i cittadini che in una relazione d'ordine basata sul criterio <NumeroBollettinoPostale, CodiceFiscale>
      rappresentano il valore minimo ed il valore massimo.</br>
                  i. A parità di valore di NumeroBollettinoPostale, si considera il valore di CodiceFiscale.</br>
                 ii. Visualizzazione a console e memorizzazione sul file di output MinMax.txt dei dati selezionati.</br>
</br>
3. Modificare gli elementi MeseScadenzaBollettino, ImportoBollettino di un cittadino come segue:</br>
                  i. Il CodiceFiscale del cittadino su cui lavorare deve essere fornito da tastiera dall'utente.</br>
                 ii. I nuovi valori di MeseScadenzaBollettino e Importol3ollettino devono essere forniti da tastiera dall'utente.</br>
                 iii. Il cittadino precedente è sostituito nell'elenco dal cittadino modificato.</br>
                 iv. Visualizzazione a console dell'elenco dei cittadini modificati e memorizzazione sul file di output Modifica.txt .</br>
