#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main(int argc, char *argv[]){

	int I=0;
	FILE *pf;
	char buffer[101]={'\0'};
	char *token;
	char virgola[2]={","};
	char barra[2]={"/"};

	pf=fopen("C:\\Users\\Mattia\\git\\progetto_esame\\Progetto Spotify\\File\\Utenti.csv","r");

	if(pf!=NULL)
	{
		I=0;
		while(!feof(pf) && I<1)
	    {
			fgets(buffer, 101,pf);		//Mette tutta la riga
			fflush(stdin);

			token=strtok(buffer, virgola);
			strcpy(UTENTI[I].nickname, token);

			token=strtok(NULL, virgola);
			strcpy(UTENTI[I].password, token);

			token=strtok(NULL, virgola);
			strcpy(UTENTI[I].nome, token);

			token=strtok(NULL, virgola);
			strcpy(UTENTI[I].cognome, token);

			token=strtok(NULL, barra);
			UTENTI[I].data_nascita.giorno=atoi(token);

			token=strtok(NULL, barra);
			UTENTI[I].data_nascita.mese=atoi(token);

			token=strtok(NULL, virgola);
			UTENTI[I].data_nascita.anno=atoi(token);

			token=strtok(NULL, barra);
			UTENTI[I].data_iscrizione.giorno=atoi(token);

			token=strtok(NULL, barra);
			UTENTI[I].data_iscrizione.mese=atoi(token);

			token=strtok(NULL, barra);
			UTENTI[I].data_iscrizione.anno=atoi(token);


			I++;
		}
	}
	else
	{
		printf("\n Errore nel caricamento del file ");
	}
	fclose(pf);

	for(I=0;I<1;I++)
	{
		printf("%s	%s	%s	%s	",UTENTI[I].nickname,UTENTI[I].password,UTENTI[I].nome,UTENTI[I].cognome);
		printf("%d/%d/%d	",UTENTI[I].data_nascita.giorno,UTENTI[I].data_nascita.mese,UTENTI[I].data_nascita.anno);
		printf("%d/%d/%d",UTENTI[I].data_iscrizione.giorno,UTENTI[I].data_iscrizione.mese,UTENTI[I].data_iscrizione.anno);
	}



system("PAUSE");
return 0;
}
