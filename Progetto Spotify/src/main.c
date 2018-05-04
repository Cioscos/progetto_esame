#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main(int argc, char *argv[]){

	//DEFINIZIONE VARIABILI --------------------------------------------------------------------------------------------------------------------------------------------------
	char input_utente[LUNGHEZZA_INPUT]={"1"};		//Variabile contenente l'input dell'utente
	char lista_generi[GENERI_TOT][LUNGHEZZA_MAX]={"Electro","Pop","Techno","Rock","Jazz","Rap","Blues","Country","Britpop","Dubstep"};
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
							controllo_menu(input_utente,MENU_UTENTE);
						}while(isControllo_Numero(input_utente,LUNGHEZZA_INPUT)!=1);

						switch(atoi(input_utente))
						{
							//---- Torna al menu principale ----
							case 0: system("cls");
									logo();
									break;

							//---- Stampa tutti gli utenti ----
							case 1:	system("cls");
									logo();
									visualizzazione_utenti(utenti_effettivi);
									system("PAUSE");
									break;

							//---- Stampa tutti gli artisti ----
							case 2:	system("cls");
									logo();
									printf("Caso 2 selezionato\n");
									system("PAUSE");
									break;

							case 3:	system("cls");
									logo();
									printf("Caso 3 selezionato\n");
									system("PAUSE");
									break;

							case 4:	system("cls");
									logo();
									printf("Caso 4 selezionato\n");
									system("PAUSE");
									break;

							case 5:	system("cls");
									logo();
									printf("Caso 5 selezionato\n");
									system("PAUSE");
									break;

							case 6:	system("cls");
									utenti_effettivi=inserimento_utente(utenti_effettivi);
									break;

							case 7:	system("cls");
									logo();
									printf("Caso 7 selezionato\n");
									system("PAUSE");
									break;

							case 8:	system("cls");
									logo();
									printf("Caso 8 selezionato\n");
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


