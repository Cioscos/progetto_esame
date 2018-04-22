#include "funzioni.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void logo()
{
	printf("   _____                   _     _    __         \n");
	printf("  / ____|                 | |   (_)  / _|        \n");
	printf(" | (___    _ __     ___   | |_   _  | |_   _   _ \n");
	printf("  \\___ \\  | '_ \\   / _ \\  | __| | | |  _| | | | |\n");
	printf("  ____) | | |_) | | (_) | | |_  | | | |   | |_| |\n");
	printf(" |_____/  | .__/   \\___/   \\__| |_| |_|    \\__, |\n");
	printf("          | |                               __/ |\n");
	printf("          |_|                              |___/ \n\n\n");
}

void stampa_menu_principale()
{
	printf("[1]Gestione artisti\n"
			"[2]Gestione utenti\n"
			"[3]Gestione file\n"
			"[0]Termina programma\n"
			"Inserisci comando:");
}

void stampa_menu_artista()
{
	printf("[1]Aggiungi nuovo artista\n");
	printf("[2]Modifica artista\n");
	printf("[3]Elimina artista\n");
	printf("[0]Torna al menu principale\n");
	printf("Inserisci comando:");
}

void stampa_menu_utente()
{
	printf("[1]Visualizza profilo utente\n");
	printf("[2]Aggiungi nuova preferenza\n");
	printf("[3]Modifica preferenza\n");
	printf("[4]Elimina preferenza\n");
	printf("[5]Aggiungi nuovo utente\n");
	printf("[6]Modifica utente\n");
	printf("[6]Elimina utente\n");
	printf("[0]Torna al menu principale\n");
	printf("Inserisci comando:");
}

int isControllo_Numero(char appoggio[LUNGHEZZA_MAX])
{
	int i=0;
	int input_valido=1;			//1 Input valido - 0 Input non valido
	int numero_caratteri=0;		//Contatore numero caratteri della stringa

	while(i<LUNGHEZZA_MAX)		//Conta numero effettivo di caratteri
	{
		if(appoggio[i]!='\0')
		{
			numero_caratteri++;
			i++;
		}
		else
		{
			i=LUNGHEZZA_MAX;
		}
	}

	i = 0;

	while(i<numero_caratteri)		//Controlla la correttezza della stringa in input
	{
		if(isdigit(appoggio[i]))
		{
			input_valido = 1;
		}
		else
		{
			input_valido = 0;
			i = numero_caratteri;
		}
		i++;
	}

	if(input_valido==1)		//Ritorna il valore 1 se la striga era corretta oppure ritorna il valore 0 se la stringa non era corretta
	{
		return 1;		//Input corretto
	}
	else
	{
		return 0;		//Input non corretto
	}
}

void controllo_menu(char* input_utente, int menu)
{
	static unsigned int flag=1;		//Controllo sull'entrata nel do while | 0 Entrato almeno una volta nel do while - 1 Mai entrato nel do while

	if(flag==1)
	{
		system("cls");
		logo();
		switch(menu)
		{	case MENU_PRINCIPALE: stampa_menu_principale();
								  break;

			case MENU_ARTISTA: 	  stampa_menu_artista();
							      break;

			case MENU_UTENTE:     stampa_menu_utente();
							      break;
		}
		scanf("%s",input_utente);
		flag=0;
	}
	else
	{
		system("cls");
		logo();
		printf("Comando errato, inserisci un valore corretto\a\n");
		system("PAUSE");

		system("cls");
		logo();
		switch(menu)
		{	case MENU_PRINCIPALE: stampa_menu_principale();
								  break;

			case MENU_ARTISTA: 	  stampa_menu_artista();
							      break;

			case MENU_UTENTE:     stampa_menu_utente();
							      break;
		}
		scanf("%s",input_utente);
	}
}
