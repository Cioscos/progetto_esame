/*!
 * @file main.c
 *
 * @brief File contenente il menù principale e tutte le chiamate delle funzioni presenti in funzioni.c, funzioni_artista.c e funzioni_utente.c
 * \mainpage Progetto Universitario Spotify
 * \authors Claudio Ciccarone, Mattia De Donatis (in ordine alfabetico)
 * \version 1.0.4
 * \date 19/05/2018
 * \copyright GNU Pubblic license
 *
 * \section intro_sec Introduzione
 * Questo codice è stato scritto per un progetto scolastico in C.\n
 * Il programma imita la gestione utenti e artisti della famosa piattaforma di streaming audio Spotify.\n
 * -Il programma è stato implementato inserendo un menù principale dal quale si possono accedere a due sottomenù:
 * 		1. Gestione artisti: Permette di gestire gli artisti. Più nello specifico permette di:
 * 			-# Visualizzare tutte le informazioni sugli artisti
 * 			-# Aggiungere un nuovo artista
 * 			-# Modificare il profilo dell'artista
 * 			-# Eliminare il profilo dell'artista
 * 		2. Gestire gli utenti: Permette di interfacciare l'utente al programma; da qui l'utente può:
 * 			-# Registrarsi e quindi creare un nuovo profilo utente
 * 			-# Accedere al programma inserendo Nickname e password; effettuato l'accesso, l'utente potrà:
 * 				-# Visualizzare il suo profilo
 * 				-# Modificare le sue preferenze ascoltando gli artisti o inserendo "Mi piace" o "Non mi piace"
 * 				-# Modificare il suo profilo
 * 				-# Disiscriversi
 * 				-# Effettuare il Log-Out
 * 		3. Chiudere Spotify\n
 *
 * Per ulteriori informazioni riguardo le funzioni del programma leggere la documentazione.
 *
 * \section comp_sec Compilazione
 * Il codice per essere compilato a bisogno di un qualsiasi compilatore C e necessita di includere la libreria funzioni.h in questo modo: include "funzioni.h"
 * \warning Eseguire il programma solo su Windows e inserire l'eseguibile in una cartella chiamata "Progetto Spotify".\n
 * I file si devono trovare in una sottocartella di "Progetto Spotify" chiamata "File".
 * \section file_sec File
 * I file usati nel progetto sono:
 * \subsection file1 Source principale
 * Formato da main.c
 * \subsection file2 Source funzioni
 * Formato da funzioni.c - funzioni_artista.c - funzioni_utente.c
 * \subsection file3 File Header
 * Formato da funzioni.h
 * \subsection file4-5-6 File dati
 * \subsubsection artisti Artisti
 * Il file artisti.txt contiene tutti gli artisti memorizzati nel Database.\n
 * -I dati sono memorizzati nel seguente ordine (separati da una virgola):
 * 			1. Codice artista: Es.0001 Codice formato da 4 cifre che identifica univocamente un artista. Non può esistere un codice 0000.
 * 			2. Nome artista: Es. Depeche Mode Indica il nome dell'artista o del gruppo.
 * 			3. Nome casa discografica: Es. Virgin Radio Indica il nome della casa discografica dell'artista.
 * 			4. Nazionalità: Es. Inglese Indica la nazionalità dell'artista o del gruppo.
 * 			5. Anno: Es.1980 Indica l'anno di inizio attività dell'artista o del gruppo.
 * 			6. Numero Ascolti: Indica il numero degli ascolti complessivi dell'artista.
 * 			7. Numero "Mi piace": Indica il numero di "Mi piace" complessivi ricevuti dagli utenti, dell'artista.
 * 			8. Genereri: Es. Rock Indica i/il genere/i dell'artista. Questi possono essere anche più di uno e saranno separati da una virgola.
 *\subsubsection utenti Utenti
 * Il file utenti.txt contiene tutti gli utenti memorizzati nel database.\n
 * -I dati sono memorizzati nel seguente ordine (separati da una virgola):
 * 		1. Nickname: Es. Cioscos Nome utilizzato dall'utente per accedere al programma.
 * 		2. Password: Utilizzata per accedere al programma dall'utente. \warning La password non potrà mai essere visualizzata dal programma ma potrà esserlo, invece, dal file utenti.txt
 * 		3. Nome: Nome dell'utente
 * 		4. Cognome: Cognome dell'utente
 * 		5. Data di nascita: Data di nascita memorizzata nell'ordine GG/MM/AAAA
 * 		6. Data di iscrizione: Data di iscrizione memorizzata nell'ordine GG/MM/AAAA.
 * 	\subsubsection preferenze Preferenze
 * 	Il file preferenze.txt contiene tutte le preferenze degli utenti.\n
 * 	-I dati sono memorizzati nel seguente ordine (separati da uno slash):
 * 		1. Nickname: Nickname utente che ha inserito la preferenza
 * 		2. Codice Artista: Codice dell'artista al quale è stata inserita la preferenza.\n
 * 		Dopo questo codice è presente una virgola seguita da un numero che può indicare:\n
 * 			-# 1: Indica che l'artista è stato solamente ascoltato dall'utente.
 * 			-# 2: Indica che l'artista è stato ascoltato dall'utente e che quest'ultimo ha gradito l'ascolto (incremento del numero di "Mi piace")
 * 			-# 3: Indica che l'artista è stato ascoltato dall'utente e che quest'ultimo non ha gradito l'ascolto.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"

 /**
 * @param argc Parametro standard passato dal sistema operativo all'eseguibile
 * @param argv Parametro standard passato dal sistema operativo all'eseguibile
 * @return 0 se la funzione viene terminata correttamente
 */
int main(int argc, char *argv[]){

	//CREAZIONE DATA ATTUALE---------------------------------------------------------------------------------------------------------------------------------------------
	time_t t=time(NULL);		//Creazione di una veriabile di tipo "time_t" nella quale inserisco tutte le informazini del calendario di windows
	struct tm *tp=localtime(&t);		    //Creo una variabile di tipo struct "tm" nella quale inserisco le informazioni contenute in "t"

	//Inserisco nelle variabili momentanee elementi della variabile "tp"
	char giorno_corrente[3];		//Variaible  momentanea contenente giorno corrente
	int mese_corrente;				//Variaible  momentanea contenente mese corrente
	char anno_corrente[5];			//Variaible  momentanea contenente anno corrente
	strftime (anno_corrente,5,"%Y", tp);
    mese_corrente=tp->tm_mon+1;
    strftime (giorno_corrente,3,"%d", tp);
    DATA_CORRENTE.anno=atoi(anno_corrente);
    DATA_CORRENTE.mese=mese_corrente;
    DATA_CORRENTE.giorno=atoi(giorno_corrente);

	//DEFINIZIONE VARIABILI --------------------------------------------------------------------------------------------------------------------------------------------------
	char lista_generi[GENERI_TOT][LUNGHEZZA_MAX]={"N.A.","Electro","Pop","Techno","Rock","Jazz","Rap","Blues","Country","Britpop","Dubstep","EDM","Hip-Hop","House","Musica leggera","Trap","Trance","Disco","Dance"};
	char input_utente[LUNGHEZZA_INPUT]={"1"};		//Variabile contenente l'input dell'utente
	int posizione_utente=-1;						//Variabile contenente la posizione nel vettore dell'utente loggato
	int flag_utente_eliminato=0;					//Flag utilizzata per controllare se un utente è stato eliminato   0 - Utente non eliminato | 1 - Utente eliminato
	int artisti_effettivi=0;
	int utenti_effettivi=0;
	char relative_path[LUNGHEZZA_PATH]={'\0'};

	creazione_path(argv[0],relative_path);


	//CARICO ARTISTI E UTENTI DA FILE
	gestione_file('r', 0, &artisti_effettivi, relative_path);
	gestione_file('r', 1, &utenti_effettivi, relative_path);
	gestione_file('r', 2, &utenti_effettivi, relative_path);

	//CODICE -----------------------------------------------------------------------------------------------------------------------------------------------------------------
	while(strcmp(input_utente,"0")!=0)		//Permette di eseguire piu opreazioni fin quando non viene inserito 0, ovvero l'opzione termina programma
	{
		flag=1;


		do{//Controllo sull'input dell'utente fin quando non viene digitato una cifra
			controllo_menu(input_utente,MENU_PRINCIPALE);
		}while(isControllo_Numero(input_utente,LUNGHEZZA_INPUT)!=1);

		switch(atoi(input_utente))		//Funzione atoi converta da stringa a intero
		{

			//---- Termina programma ----
			case 0:	system("cls");
					logo();
					printf("Programma terminato\n");
					break;

			//-----------------------  GESTIONE ARTISTA -------------------------------------------
			case 1:	system("cls");
					while(strcmp(input_utente,"0")!=0)
					{
						flag=1;

						do{	//Controllo sull'input dell'utente fin quando non viene digitato una cifra
							controllo_menu(input_utente,MENU_ARTISTA);
						}while(isControllo_Numero(input_utente,LUNGHEZZA_INPUT)!=1);

						switch(atoi(input_utente))
						{
							//---- Torna al menu principale ----
							case 0: system("cls");
									logo();
									break;

							//---- Stampa tutti gli artisti ----
							case 1:	system("cls");
									visualizzazione_artisti(lista_generi, artisti_effettivi);
									system("PAUSE");
									break;

							//---- Inserimento nuovo artista ----
							case 2:	system("cls");
									artisti_effettivi=inserimento_artista(lista_generi, artisti_effettivi);
									system("PAUSE");
									gestione_file('a', 0, &artisti_effettivi, relative_path);
									break;

							//---- Modifica un artista ----
							case 3:	system("cls");
									logo();
									modifica_artista(artisti_effettivi, lista_generi);
									gestione_file('w', 0, &artisti_effettivi, relative_path);
									break;

							//---- Elimina un artista ----
							case 4:	system("cls");
									logo();
									artisti_effettivi=elimina_artista(artisti_effettivi);
									gestione_file('w', 0, &artisti_effettivi, relative_path);
									gestione_file('w', 2, &utenti_effettivi, relative_path);
									system("PAUSE");
									break;

							//---- Cattura gli errori dell'utente ----
							default : 	system("cls");
										logo();
										printf("Comando errato, inserisci un valore corretto\a\n");
										system("PAUSE");
						}
					}
					strcpy(input_utente,"1");//Permette di rientrare nel menu principale
					break;




			//-----------------------  GESTIONE UTENTE -------------------------------------------
			case 2:	system("cls");
					while(strcmp(input_utente,"0")!=0)	//Permette di eseguire piu opreazioni fin quando non viene inserito 0, ovvero l'opzione torna al menu principale
					{
						flag=1;
						do{		//Controllo sull'input dell'utente fin quando non viene digitato una cifra
							controllo_menu(input_utente,MENU_SECONDARIO);
						}while(isControllo_Numero(input_utente,LUNGHEZZA_INPUT)!=1);

						switch(atoi(input_utente))
						{
							//---- Torna al menu principale ----
							case 0: system("cls");
									logo();
									break;

							//---- Inserisci nuovo utente ----
							case 1:	system("cls");
									utenti_effettivi=inserimento_utente(utenti_effettivi);
									gestione_file('a', 1, &utenti_effettivi, relative_path);
									break;

							//---- Accedi al programma ----
							case 2:	system("cls");
									posizione_utente=-1;		//Ripristino posizione dell'utente autenticato
									if(isAutenticazione(utenti_effettivi,&posizione_utente)==1)		//Autenticazione effettuata correttamente
									{
										do{		//Permette di rimanere nel menu utente fin quando non si decide di disconnettersi o fin quando non viene eliminato l'utente

											flag=1;
											do{		//Controllo sull'input dell'utente fin quando non viene digitato una cifra
												controllo_menu(input_utente,MENU_UTENTE);
											}while(isControllo_Numero(input_utente,LUNGHEZZA_INPUT)!=1);

											switch(atoi(input_utente))
											{
												//---- Disconnessione ----
												case 0:	system("cls");
														logo();
														printf("Sei stato disconnesso\n");
														system("PAUSE");
														break;

												//---- Stampa profilo utente ----
												case 1:	system("cls");
														gestione_file('r', 2, &utenti_effettivi, relative_path);
														logo();
														stampa_profilo(posizione_utente);
														system("PAUSE");
														break;

												//---- Modifica preferenze ----
												case 2:	system("cls");
														menu_preferenze(posizione_utente,artisti_effettivi);
														gestione_file('w', 2, &utenti_effettivi, relative_path);
														gestione_file('w', 0, &artisti_effettivi, relative_path);
														system("PAUSE");
														break;

												//---- Modifica utente ----
												case 3:	system("cls");
														logo();
														modifica_utente(utenti_effettivi, posizione_utente);
														gestione_file('w', 1, &utenti_effettivi, relative_path);
														system("PAUSE");
														break;

												//---- Elimina utente ----
												case 4:	system("cls");
														logo();
														flag_utente_eliminato=elimina_utente(&utenti_effettivi, posizione_utente);
														gestione_file('w', 1, &utenti_effettivi, relative_path);
														gestione_file('w', 2, &utenti_effettivi, relative_path);
														system("PAUSE");
														break;

												//---- Cattura gli errori dell'utente ----
												default : 	system("cls");
															logo();
															printf("Comando errato, inserisci un valore corretto\a\n");
															system("PAUSE");
											}

										}while(atoi(input_utente)!=0 && flag_utente_eliminato==0);

										flag_utente_eliminato=0;//Riazzeramento del flag per controllare una nuova eliminazione
										strcpy(input_utente,"1");//Permette di rientrare nel menu secondario
									}
									break;

							//---- Cattura gli errori dell'utente ----
							default : 	system("cls");
										logo();
										printf("Comando errato, inserisci un valore corretto\a\n");
										system("PAUSE");
						}
					}
					strcpy(input_utente,"1");//Permette di rientrare nel menu principale
					break;

			//---- Cattura gli errori dell'utente ----
			default : 	system("cls");
						logo();
						printf("Comando errato, inserisci un valore corretto\a\n");
						system("PAUSE");
		}

	}

system("PAUSE");
return 0;
}







