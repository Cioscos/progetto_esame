#include "funzioni.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void logo()
{
	printf("   _____                   _     _    __         \n"
		   "  / ____|                 | |   (_)  / _|        \n"
	       " | (___    _ __     ___   | |_   _  | |_   _   _ \n"
	       "  \\___ \\  | '_ \\   / _ \\  | __| | | |  _| | | | |\n"
	       "  ____) | | |_) | | (_) | | |_  | | | |   | |_| |\n"
	       " |_____/  | .__/   \\___/   \\__| |_| |_|    \\__, |\n"
	       "          | |                               __/ |\n"
		   "          |_|                              |___/   %c\n\n\n",169);
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
	printf("[1]Visualizza artisti\n"
			"[2]Aggiungi nuovo artista\n"
			"[3]Modifica artista\n"
			"[4]Elimina artista\n"
			"[0]Torna al menu principale\n"
			"Inserisci comando:");
}

void stampa_menu_utente()
{
	printf("[1]Visualizza utenti\n"
			"[2]Visualizza profilo utente\n"
			"[3]Aggiungi nuova preferenza\n"
			"[4]Modifica preferenza\n"
			"[5]Elimina preferenza\n"
			"[6]Aggiungi nuovo utente\n"
			"[7]Modifica utente\n"
			"[8]Elimina utente\n"
			"[0]Torna al menu principale\n"
			"Inserisci comando:");
}

int isControllo_Numero(char appoggio[])
{
	int i=0;
	int input_valido=1;			//1 Input valido - 0 Input non valido

	for(i=0;i<LUNGHEZZA_INPUT-1;i++)		//Controllo se l'input è diverso da un numero
	{
		if((isdigit(appoggio[i])!=0) || (appoggio[i]=='\0' ) )
		{
			input_valido = 1;
		}
		else
		{
			input_valido = 0;
		}
	}

	if( (appoggio[0]=='0' && appoggio[1]!='0') || (appoggio[0]!='0' && appoggio[1]=='0') || (appoggio[0]=='0' && appoggio[1]=='0'))   //Controlla i casi limiti di 01-10-00-0'\0'
	{
		if((appoggio[0]=='0' && appoggio[1]!='\0'))
		input_valido = 0;
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

void controllo_menu(char* input_utente, unsigned int menu)
{
	if(flag==1)		//Comando input accettato
	{
		system("cls");
		logo();
		switch(menu)		//Scelta del menu da stampare
		{	case MENU_PRINCIPALE: stampa_menu_principale();
								  break;

			case MENU_ARTISTA: 	  stampa_menu_artista();
							      break;

			case MENU_UTENTE:     stampa_menu_utente();
							      break;
		}
		stringclear(input_utente);
		scanf("%3s",input_utente);
		fflush(stdin);		//Svuota flusso in input
		flag=0;
	}
	else	//Comando input non accettato
	{
		system("cls");
		logo();
		printf("Comando errato, inserisci un valore corretto\a\n");
		system("PAUSE");
		system("cls");

		logo();
		switch(menu)		//Scelta del menu da stampare
		{	case MENU_PRINCIPALE: stampa_menu_principale();
								  break;

			case MENU_ARTISTA: 	  stampa_menu_artista();
							      break;

			case MENU_UTENTE:     stampa_menu_utente();
							      break;
		}
		stringclear(input_utente);
		scanf("%3s",input_utente);
		fflush(stdin);		//Svuota flusso in input
	}
}

