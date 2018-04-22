#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"





int main(int argc, char *argv[]){

	char input_utente[LUNGHEZZA_MAX]={"1"};		//Variabile contenente l'input dell'utente


	while(strcmp(input_utente,"0")!=0)		//Permette di eseguire pi� opreazioni fin quando non viene inserito uno 0, ovverol'opzione termina programma
	{
		do{
			controllo_menu(input_utente,MENU_PRINCIPALE);

		}while(isControllo_Numero(input_utente)!=1);		//Controllo sull'input dell'utente fin quando non viene digitato una cifra


		switch(atoi(input_utente))		//Funzione atoi converta da stringa a intero
		{

			case 0:	system("cls");
					logo();
					printf("Programma terminato\n");
					break;

			case 1:	system("cls");
					logo();
					controllo_menu(input_utente,MENU_ARTISTA);

					system("PAUSE");
					break;

			case 2:	system("cls");
					logo();
					controllo_menu(input_utente,MENU_UTENTE);

					system("PAUSE");
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


