#ifndef FUNZIONI_H_
#define FUNZIONI_H_

//DEFINIZIONE DI COSTANTI ----------------------------------------------------------------------------------------------------------------------------------------------------

/**
 *
 */
#define UTENTI_MAX 100
#define ARTISTI_MAX 200
#define LUNGHEZZA_MAX 32
#define LUNGHEZZA_PASS 9
#define LUNGHEZZA_BUFFER 200
#define LUNGHEZZA_PATH 300
#define MENU_PRINCIPALE 0
#define MENU_ARTISTA 1
#define MENU_UTENTE 2
#define MENU_SECONDARIO 3
#define GENERI_TOT 19
#define LUNGHEZZA_CODICE 5
#define ETA_MINIMA 16
#define PRIMO_MESE 1
#define ULTIMO_MESE 12
#define TOP 10
#define stringclear(s, dim) memset(s, '\0', dim);

//DEFINIZIONE DI STRUTTURE -------------------------------------------------------------------------------------------------------------------------------------------------

struct DATA {
	unsigned int giorno;
	unsigned int mese;
	unsigned int anno;
};
struct DATA DATA_CORRENTE;

struct ARTISTA {
	char codice[LUNGHEZZA_CODICE];
	char nome[LUNGHEZZA_MAX];
	unsigned int genere[GENERI_TOT];
	char produttore[LUNGHEZZA_MAX];
	char nazionalita[LUNGHEZZA_MAX];
	unsigned int anno_inizio;
	unsigned int ascolti;
	unsigned int preferenze;
};
struct ARTISTA ARTISTI[ARTISTI_MAX];

struct UTENTE {
	char nickname[LUNGHEZZA_MAX];
	char password[LUNGHEZZA_PASS];
	char nome[LUNGHEZZA_MAX];
	char cognome[LUNGHEZZA_MAX];
	struct DATA data_nascita;
	struct DATA data_iscrizione;
	char codice_artista[ARTISTI_MAX][LUNGHEZZA_CODICE];	//Matrice con codice artista e 1-Ascoltato 2-Mi piace 3-Non mi piace
	int preferenze[ARTISTI_MAX];
};
struct UTENTE UTENTI[UTENTI_MAX];//Bisogna ancora inserire le preferenze sugli artisti e sui generi

unsigned int flag;//Controllo sull'entrata nel do while | 0 Entrato almeno una volta nel do while - 1 Mai entrato nel do while

//PROTOTIPI DI FUNZIONI ---------------------------------------------------------------------------------------------------------------------------------------------------------------------

void SetColor(short Color);

void logo();

void stampa_menu_principale();

void stampa_menu_secondario();

void stampa_menu_artista();

void stampa_menu_utente();

void controllo_menu(char* input_utente, unsigned int menu);

int isControllo_Numero(char appoggio[], int lunghezza_massima);

int isControllo_Esistenza(int numero_presenze, char* campo, char* controllo);

char* eliminazione_acapo(char * input);

int isAutenticazione(int utenti_effettivi, int* posizione_utente);

int ordinamento_crescente(int vett[],int dim);

void gestione_file(char modalita, int tipo, int *numero, char relative_path[]);

void creazione_path(char* token_buffer, char* relative_path);

int isControllo_Lettera(char stringa[], int DIMENSIONE_MAX);

//-----------------------------------------------------------------------------------------------------------------

int inserimento_artista(char lista_generi[][LUNGHEZZA_MAX], int artisti_effettivi);

void visualizzazione_artisti(char lista_generi[][LUNGHEZZA_MAX], int artisti_effettivi);

void modifica_artista(int artisti_effettivi, char lista_generi[][LUNGHEZZA_MAX]);

int scegli_artista(int artisti_effettivi);

int elimina_artista(int artisti_effettivi, int posizione_artista);

//-----------------------------------------------------------------------------------------------------------------

int inserimento_utente(int utenti_effettivi);

void stampa_profilo(int posizione_utente);

void modifica_utente(int utenti_effettivi, int posizione_utente);


int conferma_eliminazione(int utenti_effettivi);

int elimina_utente(int utenti_effettivi, int posizione_utente);

void menu_preferenze(int posizione_utente, int artisti_effettivi);

void modifica_preferenze(int posizione_utente, int pos_artista);

int categoria_artisti(int artisti_effettivi);

int totale_artisti(int artisti_effettivi);

void ordinamento(char* input);

int top_10(int artisti_effettivi, char* input);

#endif /* FUNZIONI_H_ */
