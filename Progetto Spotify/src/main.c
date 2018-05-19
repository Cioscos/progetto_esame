#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"

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
//	char token_buffer[LUNGHEZZA_PATH]={'\0'};

	creazione_path(argv[0]);
	/*if(creazione_path(token_buffer)==0)
	{
		logo();
		SetColor(4);
		printf("Impossibile trovare i file\a\n");
		system("PAUSE");
	}*/


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







