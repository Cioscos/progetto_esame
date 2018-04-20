#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#define UTENTI_MAX 100		//Numero massimo di utenti inseribili
#define ARTISTI_MAX 100		//Numero massimo di artisti inseribili
#define LUNGHEZZA_MAX 31 	//Numero massimo di caratteri(30) per nome, cognome, nome_utente..
#define LUNGHEZZA_PASS 9 	//Lunghezza password fissa di 8 caratteri

struct DATA{		//Struttura utilizzata per la data
	unsigned int giorno;
	unsigned int mese;
	unsigned int anno;
};

struct UTENTE {		//Struttura utilizzata per la gestione degli utenti
	char nome_utente[LUNGHEZZA_MAX];
	char password[LUNGHEZZA_PASS];
	char nome[LUNGHEZZA_MAX];
	char cognome[LUNGHEZZA_MAX];
	struct DATA data_nascita;
	struct DATA data_iscrizione;
};	/*Bisogna ancora inserire le preferenze sugli artisti e sui generi*/

struct UTENTE UTENTI[1];







#endif /* FUNZIONI_H_ */
