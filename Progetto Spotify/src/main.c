#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"




int main(int argc, char *argv[]){

	char input_utente[LUNGHEZZA_INP]={'\0'};		//Variabile contenente l'input dell'utente
	strcpy(input_utente,"1");

	while(strcmp(input_utente,"0")!=0)		//Permette di eseguire più opreazioni fin quando non viene inserito uno 0, ovvero l'opzione termina programma
	{
		flag=1;
		do{
			controllo_menu(input_utente,MENU_PRINCIPALE);
		}while(isControllo_Numero(input_utente)!=1);		//Controllo sull'input dell'utente fin quando non viene digitato una cifra

			switch(atoi(input_utente))		//Funzione atoi converta da stringa a intero
			{

				case 0:	system("cls");		//0000=0
						logo();
						printf("Programma terminato\n");
						break;

				case 1:	system("cls");
						flag=1;
						do{
							controllo_menu(input_utente,MENU_ARTISTA);
						}while(isControllo_Numero(input_utente)!=1);		//Controllo sull'input dell'utente fin quando non viene digitato una cifra
						strcpy(input_utente,"1");
						system("PAUSE");
						break;

				case 2:	system("cls");
						flag=1;
						do{
							controllo_menu(input_utente,MENU_UTENTE);
						}while(isControllo_Numero(input_utente)!=1);		//Controllo sull'input dell'utente fin quando non viene digitato una cifra
						strcpy(input_utente,"1");
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

fflush(stdin);
strclr(input_utente);

system("PAUSE");
return 0;
}


