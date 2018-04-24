#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#define UTENTI_MAX 100		//Numero massimo di utenti inseribili
#define ARTISTI_MAX 100		//Numero massimo di artisti inseribili
#define LUNGHEZZA_MAX 31 	//Numero massimo di caratteri(30) per nome, cognome, nickname, generi..
#define LUNGHEZZA_PASS 9 	//Lunghezza della password fissa di 8 caratteri
#define LUNGHEZZA_INPUT 3	//Lunghezza dell'input del menu utente
#define MENU_PRINCIPALE 0	//Menu principale
#define MENU_ARTISTA 1		//Menu artista
#define MENU_UTENTE 2		//Menu utente
#define GENERI_TOT 10		//Numero generi preesistenti
#define LUNGHEZZA_CODICE 4	//Lunghezza massima del codice artista

#define stringclear(s) memset(s, '\0', strlen(s));                   // Macro azzeramento stringa, ovvero riempie la stringa di caratteri terminatori


struct DATA{		//Struttura utilizzata per la data
	unsigned int giorno;
	unsigned int mese;
	unsigned int anno;
};

struct ARTISTA{
	char codice[LUNGHEZZA_CODICE];
	char nome[LUNGHEZZA_MAX];
	int genere[GENERI_TOT];		//Gestiamo i generi come se fosse un vettore di zero e uno
	char produttore[LUNGHEZZA_MAX];
	char nazionalita[LUNGHEZZA_MAX];
	int anno_inizio;
	int ascolti;
	int preferenze;
};

struct ARTISTA ARTISTI[ARTISTI_MAX];

struct UTENTE {		//Struttura utilizzata per la gestione degli utenti
	char nickname[LUNGHEZZA_MAX];
	char password[LUNGHEZZA_PASS];
	char nome[LUNGHEZZA_MAX];
	char cognome[LUNGHEZZA_MAX];
	struct DATA data_nascita;
	struct DATA data_iscrizione;
};	/*Bisogna ancora inserire le preferenze sugli artisti e sui generi*/

struct UTENTE UTENTI[UTENTI_MAX];


unsigned int flag;		//Controllo sull'entrata nel do while | 0 Entrato almeno una volta nel do while - 1 Mai entrato nel do while

void logo();
void stampa_menu_principale();
void stampa_menu_artista();
void stampa_menu_utente();
void controllo_menu(char* input_utente, unsigned int menu);
int isControllo_Numero(char appoggio[]);										//Funzione booleana - Verifica se l'input in ingresso è un numero







/*
int I=0;
FILE *pf;
char buffer[101]={'\0'};
char *token;
char virgola[2]={","};
char barra[2]={"/"};

pf=fopen("C:\\Users\\claud\\git\\progetto_esame\\Progetto Spotify\\File\\Utenti.csv","r");

if(pf!=NULL)
{
	I=0;
	while(!feof(pf) && I<2)
    {
		fgets(buffer, 101,pf);		//Mette tutta la riga
		fflush(stdin);

		token=strtok(buffer, virgola);
		strcpy(UTENTI[I].nickname, token);

		token=strtok(NULL, virgola);
		strcpy(UTENTI[I].password, token);

		token=strtok(NULL, virgola);
		strcpy(UTENTI[I].nome, token);

		token=strtok(NULL, virgola);
		strcpy(UTENTI[I].cognome, token);

		token=strtok(NULL, barra);
		UTENTI[I].data_nascita.giorno=atoi(token);

		token=strtok(NULL, barra);
		UTENTI[I].data_nascita.mese=atoi(token);

		token=strtok(NULL, virgola);
		UTENTI[I].data_nascita.anno=atoi(token);

		token=strtok(NULL, barra);
		UTENTI[I].data_iscrizione.giorno=atoi(token);

		token=strtok(NULL, barra);
		UTENTI[I].data_iscrizione.mese=atoi(token);

		token=strtok(NULL, barra);
		UTENTI[I].data_iscrizione.anno=atoi(token);


		I++;
	}
}
else
{
	printf("\n Errore nel caricamento del file ");
}
fclose(pf);

for(I=0;I<1;I++)
{
	printf("%s	%s	%s	%s  ",UTENTI[I].nickname,UTENTI[I].password,UTENTI[I].nome,UTENTI[I].cognome);
	printf("%d/%d/%d	",UTENTI[I].data_nascita.giorno,UTENTI[I].data_nascita.mese,UTENTI[I].data_nascita.anno);
	printf("%d/%d/%d\n",UTENTI[I].data_iscrizione.giorno,UTENTI[I].data_iscrizione.mese,UTENTI[I].data_iscrizione.anno);
}

*/





#endif /* FUNZIONI_H_ */
