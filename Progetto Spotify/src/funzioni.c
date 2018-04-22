#include "funzioni.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void stampa_menu_principale()
{
	printf("[1]Gestione artisti\n");
	printf("[2]Gestione utenti\n");
	printf("[3]Gestione file\n");
	printf("[0]Termina programma\n");
	printf("Inserisci comando:");
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



