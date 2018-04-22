#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main(int argc, char *argv[]){

	char input_utente[LUNGHEZZA_MAX]={"1"};


	while(strcmp(input_utente,"0")!=0)
	{
		do{
			system("cls");
			stampa_menu_principale();
			scanf("%s",input_utente);
		}while(isControllo_Numero(input_utente)!=1);

		switch(atoi(input_utente))
		{
			case 1:	system("cls");
					printf("Hai selezionato 1\n");
					system("PAUSE");
					break;

			case 2:	system("cls");
					printf("Hai selezionato 2\n");
					system("PAUSE");
					break;

			case 3:	system("cls");
					printf("Hai selezionato 3\n");
					system("PAUSE");
					break;
		}
	}



system("PAUSE");
return 0;
}


