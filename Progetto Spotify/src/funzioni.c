#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include "funzioni.h"

void SetColor(short Color)
{
	/*	1 = Blue 2 = Green 3 = Light Blue 4 = Red 5 = Purple
	  	6 = Orange/Brown 7 = White 8 = Grey 9 = Blue
		10 = Green 11 = Light Blue 12 = Pink/Red 13 = Purple
		14 = Yellow 15 = White	*/
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); /*HANDLE=Puntatore "opaco";gli viene assegnato
													*un valore da una funzione
													*GetStdHandle=restituisce a HANDLE un dispositivo
													*standard (STD_OUTPUT_HANDLE)*/
	SetConsoleTextAttribute(hCon,Color);
}

void logo()
{
	SetColor(2);
	printf("   _____                   _     _    __         \n"
		   "  / ____|                 | |   (_)  / _|        \n"
	       " | (___    _ __     ___   | |_   _  | |_   _   _ \n"
	       "  \\___ \\  | '_ \\   / _ \\  | __| | | |  _| | | | |\n"
	       "  ____) | | |_) | | (_) | | |_  | | | |   | |_| |\n"
	       " |_____/  | .__/   \\___/   \\__| |_| |_|    \\__, |\n"
	       "          | |                               __/ |\n"
		   "          |_|                              |___/   %c\n\n\n",169);
	SetColor(15);
}

void stampa_menu_principale()
{
	SetColor(2);
	printf("[1]");
	SetColor(15);
	printf("Gestione artisti\n");
	SetColor(2);
	printf("[2]");
	SetColor(15);
	printf("Gestione utenti\n");
	SetColor(2);
	printf("[0]");
	SetColor(15);
	printf("Termina programma\n\nInserisci comando: ");
}

void stampa_menu_artista()
{
	SetColor(2);
	printf("[1]");
	SetColor(15);
	printf("Viualizza artisti\n");
	SetColor(2);
	printf("[2]");
	SetColor(15);
	printf("Aggiungi nuovo artista\n");
	SetColor(2);
	printf("[3]");
	SetColor(15);
	printf("Modifica artista\n");
	SetColor(2);
	printf("[4]");
	SetColor(15);
	printf("Elimina artista\n");
	SetColor(2);
	printf("[0]");
	SetColor(15);
	printf("Torna al menu principale\n\nInserisci comando: ");
}

void stampa_menu_utente()
{
	SetColor(2);
	printf("[1]");
	SetColor(15);
	printf("Visualizza utenti\n");
	SetColor(2);
	printf("[2]");
	SetColor(15);
	printf("Visualizza profilo utente\n");
	SetColor(2);
	printf("[3]");
	SetColor(15);
	printf("Aggiungi nuova preferenza\n");
	SetColor(2);
	printf("[4]");
	SetColor(15);
	printf("Modifica preferenza\n");
	SetColor(2);
	printf("[5]");
	SetColor(15);
	printf("Elimina preferenza\n");
	SetColor(2);
	printf("[6]");
	SetColor(15);
	printf("Aggiungi nuovo utente\n");
	SetColor(2);
	printf("[7]");
	SetColor(15);
	printf("Modifica utente\n");
	SetColor(2);
	printf("[8]");
	SetColor(15);
	printf("Elimina utente\n");
	SetColor(2);
	printf("[0]");
	SetColor(15);
	printf("Torna al menu principale\n\nInserisci comndo: ");
}

int isControllo_Numero(char appoggio[], int lunghezza_massima)
{
	int i=0;
	int input_valido=1;			//1 Input valido - 0 Input non valido
	int lughezza_effettiva=0;	//Numero caratteri effettivi

	while(i<lunghezza_massima)		//Conta numero effettivo di caratteri
	{
		if(appoggio[i]!='\0')
		{
			lughezza_effettiva++;
			i++;
		}
		else
		{
			i=lunghezza_massima;
		}
	}
	i = 0;

	for(i=0;i<lughezza_effettiva;i++)		//Controllo se l'input � diverso da un numero
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

	if(lunghezza_massima==3)		//Ulteriore controllo su i casi limiti di 01-10-00-0'\0'
	{
		if( (appoggio[0]=='0' && appoggio[1]!='0') || (appoggio[0]!='0' && appoggio[1]=='0') || (appoggio[0]=='0' && appoggio[1]=='0'))
		{
			if((appoggio[0]=='0' && appoggio[1]!='\0'))
			input_valido = 0;
		}
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
		stringclear(input_utente, LUNGHEZZA_INPUT);
		scanf("%3s",input_utente);
		fflush(stdin);		//Svuota flusso in input
		flag=0;
	}
	else	//Comando input non accettato
	{
		system("cls");
		logo();
		SetColor(4);
		printf("Comando errato, inserisci un valore corretto\a\n\n");
		SetColor(15);
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
		stringclear(input_utente, LUNGHEZZA_INPUT);
		scanf("%3s",input_utente);
		fflush(stdin);		//Svuota flusso in input
	}
}
