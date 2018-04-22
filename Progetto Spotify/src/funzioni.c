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



