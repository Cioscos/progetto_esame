/*!
 * @file funzioni.h
 * @brief Header file contenente tutti i prototipi di funzione e le definizioni di strutture
 */
#ifndef FUNZIONI_H_
#define FUNZIONI_H_

//DEFINIZIONE DI COSTANTI ----------------------------------------------------------------------------------------------------------------------------------------------------
/**@def UTENTI_MAX
 * Numero massimo di utenti inseribili
 */
#define UTENTI_MAX 100

/**@def ARTISTI_MAX
 * Numero massimo di artisti inseribili
 *
 * Questo non è un limite in quanto il numero degli artisti massimo è basso perché si tratta di un caso di studio.
 */
#define ARTISTI_MAX 200

/**@def LUNGHEZZA_MAX
 * Numero massimo di caratteri(30) per nome, cognome, nickname, e qualsiasi inserimento da tastiera.
 */
#define LUNGHEZZA_MAX 32

/**@def LUNGHEZZA_PASS
 * Lunghezza della password fissa di 8 caratteri.
 */
#define LUNGHEZZA_PASS 9


/**@def LUNGHEZZA_BUFFER
 * Lunghezza buffer file
 *
 * La stringa presa in input dallo stream del file può essere lunga massimo LUNGHEZZA_BUFFER.
 */
#define LUNGHEZZA_BUFFER 200

/**@def LUNGHEZZA_PATH
 *Lunghezza massima del percorso file
 */
#define LUNGHEZZA_PATH 300

/**@def MENU_PRINCIPALE
 * Costante utilizzata per il menù principale
 */
#define MENU_PRINCIPALE 0

/**@def MENU_ARTISTA
 * Costante utilizzata per il menù artista
 */
#define MENU_ARTISTA 1

/**@def MENU_UTENTE
 * Costante utilizzata per il menù utente
 */
#define MENU_UTENTE 2

/**@def MENU_SECONDARIO

 * Costante utilizzata per il menù secondario
 */
#define MENU_SECONDARIO 3

/**@def GENERI_TOT
 * Numero generi esistenti
 */
#define GENERI_TOT 19

/**@def LUNGHEZZA_CODICE
 * Lunghezza massima del codice artista
 */
#define LUNGHEZZA_CODICE 5

/**@def ETA_MINIMA
 * Età  minima per iscriversi
 */
#define ETA_MINIMA 16

/**@def PRIMO_MESE
 * Numero mese di gennaio
 */
#define PRIMO_MESE 1

/**@def ULTIMO_MESE
 * Numero mese di dicembre
 */
#define ULTIMO_MESE 12

/**@def TOP
 * Grandezza della Top classifiche
 */
#define TOP 10

/**@def stringclear
 * Macro azzeramento stringa, ovvero riempie la stringa di caratteri terminatori
 *
 * Si chiama passandogli come primo argomento il nome della stirnga e come secondo la sua dimensione.
 */
#define stringclear(s, dim) memset(s, '\0', dim);

//DEFINIZIONE DI STRUTTURE -------------------------------------------------------------------------------------------------------------------------------------------------
/**
 * @struct DATA
 * @brief Struttura usata per creare variabili di tipo data.
 */
struct DATA {
	/**Contiene il giorno */
	unsigned int giorno;
	/**Contiene il mese */
	unsigned int mese;
	/**Contiene l'anno */
	unsigned int anno;
};
/**
 * Variabile usata per contenera la data.
 * @warning La variabile sarà riempita in run-time. Se chiuso il programma e cancellati i dati da file, il programma non troverà più nessun dato salvato.
 */
struct DATA DATA_CORRENTE;

/**
 * @struct ARTISTA
 * @brief Struttura usata per creare vettori di tipo artista
 *
 * Questa struttura è usata per definire il vettore ARTISTI il quale contiene la lista di tutti gli artisti memorizzati.
 */
struct ARTISTA {
	/**Contiene il codice artista. */
	char codice[LUNGHEZZA_CODICE];
	/**Contiene il nome dell'artista o del gruppo. */
	char nome[LUNGHEZZA_MAX];
	/**Contiene il genere dell'artista o del gruppo. */
	unsigned int genere[GENERI_TOT];
	/**Contiene il mome della casa discografica */
	char produttore[LUNGHEZZA_MAX];
	/**Contiene la nazionalità dell'artista o del gruppo. */
	char nazionalita[LUNGHEZZA_MAX];
	/**Contiene l'anno di inizio attività dell'artista. */
	unsigned int anno_inizio;
	/**Contiene il numero degli ascolti complessivi. */
	unsigned int ascolti;
	/**Contiene il numero di preferenze complessive. */
	unsigned int preferenze;
};
/**
 * Vettore usato per memorizzare tutti gli artisti.
 * @warning Il vettore sarà riempito in run-time. Se chiuso il programma e cancellati i dati da file, il programma non troverà più nessun dato salvato.
 */
struct ARTISTA ARTISTI[ARTISTI_MAX];

/**
 * @struct UTENTE
 * @brief Struttura usata per creare vettori di tipo utente
 *
 * Questa struttura è usata per definire il vettore UTENTI il quale contiene la lista di tutti gli utenti memorizzati.
 */
struct UTENTE {
	/**  Nome utilizzato dall'utente per accedere al programma. */
	char nickname[LUNGHEZZA_MAX];
	/** Utilizzata per accedere al programma dall'utente. */
	char password[LUNGHEZZA_PASS];
	/** Nome dell'utente. */
	char nome[LUNGHEZZA_MAX];
	/** Cognome dell'utente. */
	char cognome[LUNGHEZZA_MAX];
	/**
	 * @brief Data di nascita memorizzata nell'ordine GG/MM/AAAA
	 *
	 * Viene usata una variabile di tipo struttura DATA.
	 */
	struct DATA data_nascita;
	/**
	 * @brief Data di iscrizione memorizzata nell'ordine GG/MM/AAAA
	 *
	 * Viene usata una variabile di tipo struttura DATA.
	 */
	struct DATA data_iscrizione;
	/** Contiene numeri distintivi per indicare il gradimento di un artista da parte di un utente.\n
	 * -Nello specifico:
	 * 		-# 1 indica che l'artista è stato ascoltato.
	 * 		-# 2 indica che l'utente ha messo un mi piace per l'artista (incrementa anche gli ascolti)
	 * 		-# 3 indica che l'utente ha messo un non mi piace per l'artista (incrementa anche gli ascolti)
	 */
	char codice_artista[ARTISTI_MAX][LUNGHEZZA_CODICE];	//Matrice con codice artista e 1-Ascoltato 2-Mi piace 3-Non mi piace
	/** Contiene il numero di "Mi piace". */
	int preferenze[ARTISTI_MAX];
};
/**
 * Vettore usato per memorizzare tutti gli utenti.
 * @warning Il vettore sarà riempito in run-time. Se chiuso il programma e cancellati i dati da file, il programma non troverà più nessun dato salvato.
 */
struct UTENTE UTENTI[UTENTI_MAX];//Bisogna ancora inserire le preferenze sugli artisti e sui generi

unsigned int flag;//Controllo sull'entrata nel do while | 0 Entrato almeno una volta nel do while - 1 Mai entrato nel do while

//PROTOTIPI DI FUNZIONI ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
/**
 * @brief Cambio colore caratteri console
 *
 * Permette attraverso la gestione dei dispositivi di windows di cambiare il colore della shell.\n
 * -Nello specifico:
 * 		-# HANDLE=Puntatore "opaco";gli viene assegnato un valore da una funzione
 * 		-# GetStdHandle = restituisce a HANDLE un dispositivo
 * 		-# standard output (STD_OUTPUT_HANDLE)
 *
 * 	@warning Ovviamente la funzione può essere usata solo su sistemi operativi Windows.
 * @param[in] Color Un numero che indica il colore desiderato:\n
 * 1 = Blue 2 = Green 3 = Light Blue 4 = Red 5 = Purple
	 6 = Orange/Brown 7 = White 8 = Grey 9 = Blue
	 10 = Green 11 = Light Blue 12 = Pink/Red 13 = Purple
	 14 = Yellow 15 = White\n
	 @warning Numeri oltre quelli indicati cambieranno anche l'evidenziazione del testo
 */
void SetColor(short Color);

/**
 * @brief Stampa il logo di Spotify
 *
 * La funzione non ha ne parametri di input che di ritorno.\n È stata creata questa funzione per il grande numero di volte la quale viene richiamata.
 */
void logo();

/**
 * @brief Stampa il menù principale
 *
 * La funzione non ha ne parametri di input che di ritorno.
 */
void stampa_menu_principale();

/**
 * @brief Stampa il menù secondario
 *
 * La funzione non ha ne parametri di input che di ritorno.
 */
void stampa_menu_secondario();

/**
 * @brief Stampa il menù artista
 *
 * La funzione non ha ne parametri di input che di ritorno.
 */
void stampa_menu_artista();

/**
 * @brief Stampa menù utente
 *
 * La funzione non ha ne parametri di input che di ritorno.
 */
void stampa_menu_utente();

/**
 * @brief Controlla input utente
 *
 * Controlla l'input dell'utente nel menù principale
 * @param[in] input_utente Input inserito dall'utente
 * @param[in] menu Costante passata per specificare il tipo di menù da richiamare
 */
void controllo_menu(char* input_utente, unsigned int menu);

/**
 *@brief Controlla se l'input dell'utente rispetta le confizioni di funzionamento
 *
 * @param[in] appoggio Array di caratteri passato per valore
 * @param[in] lunghezza_massima Lunghezza massima input
 * @return 1 = L'input è corretto        0 = L'input è errato
 */
int isControllo_Numero(char appoggio[], int lunghezza_massima);

/**
 * @brief Controllo se dei dati sono già presenti nel Database.
 *
 * @param[in] numero_presenze Il numero presenze corrisponde al numero effettivo di utenti o di artisti memorizzati
 * @param[in] campo Stringa da controllorare
 * @param[in] controllo Stringa rappresentante il tipo di controllo che si vuole effettuare\n
 * 1. nome_artista
 * 2. codice_artista
 * 3. nickname_utente
 * 4. nome_utente
 * 5. cognome_utente
 * @return 1 = elemento non presente        0 = elemento già presente
 */
int isControllo_Esistenza(int numero_presenze, char* campo, char* controllo);

/**
 * @brief Funzione creata per eliminare un'eventuale \0 a fine frase
 * @param[in] input Riceve in input una stringa
 */
void eliminazione_acapo(char* input);

/**
 *
 * @param[in] utenti_effettivi Numeri utenti effettivamente registrati
 * @param[out] posizione_utente Fornisce per riferimento la variabile posizione utente che viene modificata con la posizione effettiva dell'utente all'interno del vettore degli utenti.
 * @return 0 = autenticazione non riuscita       1 = autenticazione effettuata
 */
int isAutenticazione(int utenti_effettivi, int* posizione_utente);

/**
 * @brief Funzione per la gestione dei file
 *
 * @param[in] modalita Carattere che permette di decidere la modalità di gestione del file
 * @param[in] tipo Intero passato per decidere che file bisogna gestire
 * 	1. 0 = Artista
 * 	2. 1 = Utente
 * 	3. 2 = Preferenze
 * @param[in,out] numero Intero passato per riferimento che indica il numero degli utenti effettivi ed eventualmente può anche essere modificato.
 * @param[in] relative_path Stringa contenente la relative_path dei file
 */
void gestione_file(char modalita, int tipo, int *numero, char relative_path[]);

/**
 *
 * @param[in] token_buffer Viene passata la relative path dell'eseguibile
 * @param[out] relative_path Viene ritornata per riferimento la path dell'eseguibile fino a File\\
 */
void creazione_path(char* token_buffer, char* relative_path);

/**
 *
 * @param[in] lista_generi Viene passata la lista dei generi disponibii
 * @param[in] artisti_effettivi Viene passato per valore il numero di utenti effetivamente memorizzati
 * @return Numero utenti effettivi
 */
int inserimento_artista(char lista_generi[][LUNGHEZZA_MAX], int artisti_effettivi);

/**
 * Questa funzione visualizza gli artisti memorizzati
 *
 * @param[in] lista_generi Viene passata la lista dei generi disponibii
 * @param[in] artisti_effettivi Viene passato per valore il numero di utenti effetivamente memorizzati
 */
void visualizzazione_artisti(char lista_generi[][LUNGHEZZA_MAX], int artisti_effettivi);

/**
 * Questa funzione modifica gli attributi dell'artista o del gruppo
 *
 * @param[in] artisti_effettivi Viene passato per valore il numero di utenti effetivamente memorizzati
 * @param[in] lista_generi Viene passata la lista dei generi disponibii
 */
void modifica_artista(int artisti_effettivi, char lista_generi[][LUNGHEZZA_MAX]);

/**
 * Questa funzione permette di scegliere l'artista da eliminare dalla lista degli artisti memorizzati
 *
 * @param[in] artisti_effettivi Viene passato per valore il numero di artisti effetivamente memorizzati
 * @return L'indice di posizione nella lista degli artisti, dell'artista scelto per l'eliminazione
 */
int scegli_artista(int artisti_effettivi);

/**
 * Questa funzione elimina un artista dalla lista degli artisti memorizzati
 *
 * @param[in] artisti_effettivi Viene passato per valore il numero di artisti effetivamente memorizzati
 * @param[in] posizione_artista Viene passato per valore l'indice dell'artista selezionato [vedi ::scegli_artista]
 * @return Il numero degli artisti memorizzati dopo l'eliminazione
 */
int elimina_artista(int artisti_effettivi, int posizione_artista);

/**
 *
 * @param[in] utenti_effettivi Viene passato per valore il numero di utenti effetivamente memorizzati
 * @return Il numero degli utenti memorizzati dopo l'eliminazione
 */
int inserimento_utente(int utenti_effettivi);

void visualizzazione_utenti(int utenti_effettivi); //FUNZIONE DEBUG

/**
 * Questa funzione permette di stampare il profilo dell'utente
 *
 * @param[in] posizione_utente Viene passato per valore l'indice dell'utente che ha fatto accesso al programma
 */
void stampa_profilo(int posizione_utente);

/**
 * Questa funzione permette di modificare gli attributi dell'utente
 *
 * @param[in] utenti_effettivi Viene passato per valore il numero di utenti effetivamente memorizzati
 * @param[in] posizione_utente Viene passato per valore l'indice dell'utente che ha fatto accesso al programma
 */
void modifica_utente(int utenti_effettivi, int posizione_utente);

/**
 * Questa funzion
 * @param[in] utenti_effettivi Viene passato per riferimento il numero di utenti effetivamente memorizzati
 * @return
 */
int conferma_eliminazione(int utenti_effettivi);

/**
 * Questa funzione permette di eliminare un utente registrato
 *
 * @param[in] utenti_effettivi Viene passato per riferimento il numero di utenti effetivamente memorizzati
 * @param[in] posizione_utente Viene passato per valore l'indice dell'utente che ha fatto accesso al programma
 * @return 1 = Utente eliminato     0 = Utente non eliminato
 */
int elimina_utente(int utenti_effettivi, int posizione_utente);

/**
 * Questa funzione mostra il menù dal quale l'utente può decidere di ascoltare un cantante e modficiare le preferenze
 *
 * @param[in] posizione_utente Viene passato per valore l'indice dell'utente che ha fatto accesso al programma
 * @param[in] artisti_effettivi Viene passato per valore il numero di utenti effetivamente memorizzati
 */
void menu_preferenze(int posizione_utente, int artisti_effettivi);

/**
 * Questa funzione serve per modificare gli ascolti e le preferenze dell'utente
 *
 * @param[in] posizione_utente Viene passato per valore l'indice dell'utente che ha fatto accesso al programma
 * @param[in] pos_artista Viene passato per valore l'indice dell'artista selezionato (Ritorno per le funzioni ::categoria_artisti, ::totale_artisti e ::top_10)
 */
void modifica_preferenze(int posizione_utente, int pos_artista);

/**
 * Questa funzione stampa tutti i generi disponibili
 *
 * @param[in] artisti_effettivi Viene passato per valore il numero di utenti effetivamente memorizzati
 * @return Ritorna pos_artista ovvero la posizione dell'artista all'interno dell'indice.
 */
int categoria_artisti(int artisti_effettivi);

/**
 * Questa funzione mostra la lista degli artisti
 *
 * @param[in] artisti_effettivi Viene passato per valore il numero di utenti effetivamente memorizzati
 * @return Ritorna pos_artista ovvero la posizione dell'artista all'interno dell'indice.
 */
int totale_artisti(int artisti_effettivi);

/**
 * Questa funzione ordina gli artisti per  "Mi piace" o "Ascolti"
 *
 * @param[in] input Viene passata una stringa (saranno accettate solo le stringhe "Mi piace" e "Ascolti"
 */
void ordinamento(char* input);

/**
 * Questa funzione farà visualizzare gli Artisti TOP 10
 *
 * @param[in] artisti_effettivi Viene passato per valore il numero di utenti effetivamente memorizzati
 * @param[in] input Viene passata una stringa (saranno accettate solo le stringhe "Mi piace" e "Ascolti"
 * @return Ritorna pos_artista ovvero la posizione dell'artista all'interno dell'indice.
 */
int top_10(int artisti_effettivi, char* input);

#endif /* FUNZIONI_H_ */
