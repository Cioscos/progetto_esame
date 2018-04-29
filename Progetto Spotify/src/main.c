#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main(int argc, char *argv[]){

	//DEFINIZIONE VARIABILI --------------------------------------------------------------------------------------------------------------------------------------------------
	char input_utente[LUNGHEZZA_INPUT]={"1"};		//Variabile contenente l'input dell'utente
	char lista_generi[GENERI_TOT][LUNGHEZZA_MAX]={"Electro","Pop","Techno","Rock","Jazz","Rap","Blues","Country","Britpop","Dubstep"};
	int artisti_effettivi=0;






	//CODICE -----------------------------------------------------------------------------------------------------------------------------------------------------------------
	while(strcmp(input_utente,"0")!=0)		//Permette di eseguire pi� opreazioni fin quando non viene inserito uno 0, ovvero l'opzione termina programma
	{
		flag=1;
		do{
			controllo_menu(input_utente,MENU_PRINCIPALE);
		}while(isControllo_Numero(input_utente,LUNGHEZZA_INPUT)!=1);		//Controllo sull'input dell'utente fin quando non viene digitato una cifra

		switch(atoi(input_utente))		//Funzione atoi converta da stringa a intero
		{

			case 0:	system("cls");
					logo();
					printf("Programma terminato\n");
					break;

			case 1:	system("cls");
					while(strcmp(input_utente,"0")!=0)
					{
						flag=1;
						do{
							controllo_menu(input_utente,MENU_ARTISTA);
						}while(isControllo_Numero(input_utente,LUNGHEZZA_INPUT)!=1);		//Controllo sull'input dell'utente fin quando non viene digitato una cifra

						switch(atoi(input_utente))
						{
							case 0: system("cls");
									logo();
									break;

							case 1:	system("cls");
									visualizzazione_artisti(lista_generi, artisti_effettivi);
									system("PAUSE");
									break;

							case 2:	system("cls");
									artisti_effettivi=inserimento_artista(lista_generi, artisti_effettivi);
									system("PAUSE");
									break;

							case 3:	system("cls");
									logo();
									modifica_artista(artisti_effettivi, lista_generi);
									break;

							case 4:	system("cls");
									logo();
									elimina_artista(&artisti_effettivi);
									system("PAUSE");
									break;

							default : 	system("cls");
										logo();
										printf("Comando errato, inserisci un valore corretto\a\n");
										system("PAUSE");
						}
					}
					strcpy(input_utente,"1");            //Permette di rientrare nel menu principale
					break;

			case 2:	system("cls");
					while(strcmp(input_utente,"0")!=0)
					{
						flag=1;
						do{
							controllo_menu(input_utente,MENU_UTENTE);
						}while(isControllo_Numero(input_utente,LUNGHEZZA_INPUT)!=1);		//Controllo sull'input dell'utente fin quando non viene digitato una cifra

						switch(atoi(input_utente))
						{
							case 0: system("cls");
									logo();
									break;

							case 1:	system("cls");
									logo();
									printf("Caso 1 selezionato\n");
									system("PAUSE");
									break;

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
									logo();
									printf("Caso 6 selezionato\n");
									system("PAUSE");
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

							default : 	system("cls");
										logo();
										printf("Comando errato, inserisci un valore corretto\a\n");
										system("PAUSE");
						}
					}
					strcpy(input_utente,"1");            //Permette di rientrare nel menu principale
					break;

			case 3:	system("cls");
					printf("Hai selezionato 3\n");
					system("PAUSE");
					break;

			default : 	system("cls");
						logo();
						printf("Comando errato, inserisci un valore corretto\a\n");
						system("PAUSE");
		}

	}

system("PAUSE");
return 0;
}


