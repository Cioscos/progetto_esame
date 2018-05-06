#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main(int argc, char *argv[]){

	//DEFINIZIONE VARIABILI --------------------------------------------------------------------------------------------------------------------------------------------------
	char input_utente[LUNGHEZZA_INPUT]={"1"};		//Variabile contenente l'input dell'utente
	char lista_generi[GENERI_TOT][LUNGHEZZA_MAX]={"Electro","Pop","Techno","Rock","Jazz","Rap","Blues","Country","Britpop","Dubstep"};
	int posizione_utente=-1;				//Variabile contenente la posizione nel vettore dell'utente loggato
	int artisti_effettivi=0;
	int utenti_effettivi=0;



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
									break;

							//---- Modifica un artista ----
							case 3:	system("cls");
									logo();
									modifica_artista(artisti_effettivi, lista_generi);
									break;

							//---- Elimina un artista ----
							case 4:	system("cls");
									logo();
									artisti_effettivi=elimina_artista(artisti_effettivi);
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
									break;

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
														logo();
														stampa_profilo(posizione_utente);		//TODO non serve più una funzione che stampi tutti gli utenti, aggiustarla per far stampare solo l'utente in questione
														system("PAUSE");
														break;

												//---- Aggiungi nuova preferenza ----
												case 2:	system("cls");
														logo();
														printf("Caso 2 selezionato\n");
														system("PAUSE");
														break;

												//---- Elimina preferenza ----
												case 3:	system("cls");
														logo();
														printf("Caso 3 selezionato\n");
														system("PAUSE");
														break;

												//---- Modifica utente ----
												case 4:	system("cls");
														logo();
														modifica_utente(utenti_effettivi, posizione_utente);
														system("PAUSE");
														break;

												//---- Elimina utente ----
												case 5:	system("cls");
														logo();
														utenti_effettivi=elimina_utente(utenti_effettivi, posizione_utente);
														system("PAUSE");
														break;

												//---- Cattura gli errori dell'utente ----
												default : 	system("cls");
															logo();
															printf("Comando errato, inserisci un valore corretto\a\n");
															system("PAUSE");
											}

										}while(atoi(input_utente)!=0 && atoi(input_utente)!=5);

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



