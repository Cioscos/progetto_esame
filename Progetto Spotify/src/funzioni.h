#ifndef FUNZIONI_H_
#define FUNZIONI_H_

//DEFINIZIONE DI COSTANTI ----------------------------------------------------------------------------------------------------------------------------------------------------
#define UTENTI_MAX 100			//Numero massimo di utenti inseribili
#define ARTISTI_MAX 22			//Numero massimo di artisti inseribili
#define LUNGHEZZA_MAX 32 		//Numero massimo di caratteri(30) per nome, cognome, nickname, generi..
#define LUNGHEZZA_PASS 9 		//Lunghezza della password fissa di 8 caratteri
#define LUNGHEZZA_INPUT 3		//Lunghezza dell'input del menu utente
#define LUNGHEZZA_BUFFER 200	//Lunghezza buffer file
#define LUNGHEZZA_PATH 100
#define MENU_PRINCIPALE 0		//Menu principale
#define MENU_ARTISTA 1			//Menu artista
#define MENU_UTENTE 2			//Menu utente
#define MENU_SECONDARIO 3		//Menu intermedio prima dell'utente
#define GENERI_TOT 19			//Numero generi esistenti
#define LUNGHEZZA_CODICE 5		//Lunghezza massima del codice artista
#define ETA_MINIMA 16 			//EtÃ  minima per iscriversi
#define PRIMO_MESE 1			//Numero mese di gennaio
#define ULTIMO_MESE 12			//Numero mese di dicembre
#define stringclear(s, dim) memset(s, '\0', dim);        // Macro azzeramento stringa, ovvero riempie la stringa di caratteri terminatori

//DEFINIZIONE DI STRUTTURE -------------------------------------------------------------------------------------------------------------------------------------------------
struct DATA{
	unsigned int giorno;
	unsigned int mese;
	unsigned int anno;
};
struct DATA DATA_CORRENTE;

struct ARTISTA{
	char codice[LUNGHEZZA_CODICE];
	char nome[LUNGHEZZA_MAX];
	int genere[GENERI_TOT];
	char produttore[LUNGHEZZA_MAX];
	char nazionalita[LUNGHEZZA_MAX];
	int anno_inizio;
	int ascolti;
	int preferenze;
};
struct ARTISTA ARTISTI[ARTISTI_MAX];

struct UTENTE {
	char nickname[LUNGHEZZA_MAX];
	char password[LUNGHEZZA_PASS];
	char nome[LUNGHEZZA_MAX];
	char cognome[LUNGHEZZA_MAX];
	struct DATA data_nascita;
	struct DATA data_iscrizione;
	char codice_artista[ARTISTI_MAX][LUNGHEZZA_CODICE];		//Matrice con codice artista e 1-Ascoltato 2-Mi piace 3-Non mi piace
	int preferenze[ARTISTI_MAX];
};

struct UTENTE UTENTI[UTENTI_MAX];	//Bisogna ancora inserire le preferenze sugli artisti e sui generi

unsigned int flag;		//Controllo sull'entrata nel do while | 0 Entrato almeno una volta nel do while - 1 Mai entrato nel do while


//PROTOTIPI DI FUNZIONI ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SetColor(short Color);
void logo();
void stampa_menu_principale();
void stampa_menu_secondario();
void stampa_menu_artista();
void stampa_menu_utente();
void controllo_menu(char* input_utente, unsigned int menu);
int isControllo_Numero(char appoggio[], int lunghezza_massima);		//Funzione booleana - Verifica se l'input in ingresso e' un numero
int isControllo_Esistenza(int numero_presenze, char* campo, char* controllo);
void eliminazione_acapo(char* input);
int isAutenticazione(int utenti_effettivi, int* posizione_utente);
void gestione_file(char modalita, int tipo, int *numero, char relative_path[]);


int inserimento_artista(char lista_generi[][LUNGHEZZA_MAX], int artisti_effettivi);
void visualizzazione_artisti(char lista_generi[][LUNGHEZZA_MAX], int artisti_effettivi);
void modifica_artista(int artisti_effettivi, char lista_generi[][LUNGHEZZA_MAX]);
int elimina_artista(int artisti_effetivi);


int inserimento_utente(int utenti_effettivi);
void visualizzazione_utenti(int utenti_effettivi);
void stampa_profilo(int posizione_utente);
void modifica_utente(int utenti_effettivi, int posizione_utente);
int elimina_utente(int* utenti_effettivi, int posizione_utente);
void modifica_preferenze(int posizione_utente,int artisti_effettivi);




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
