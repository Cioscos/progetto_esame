#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main(int argc, char *argv[]){

	int I=0;
	FILE *pf;
	char buffer[101]={'\0'};
	char *token;
	char c[2]={","};

	pf=fopen("C:\\Users\\claud\\git\\progetto_esame\\Progetto Spotify\\File\\Utenti.csv","r");

	if(pf!=NULL)
	{
		I=0;
		while(!feof(pf) && I<1)
	    {
			fgets(buffer, 101,pf);
			fflush(stdin);

			token=strtok(buffer, c);
			strcpy(UTENTI[I].nickname, token);

			token=strtok(NULL, c);
			strcpy(UTENTI[I].password, token);

			token=strtok(NULL, c);
			strcpy(UTENTI[I].nome, token);

			token=strtok(NULL, c);
			strcpy(UTENTI[I].cognome, token);

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
		printf("%s	%s	%s	%s	\n",UTENTI[I].nickname,UTENTI[I].password,UTENTI[I].nome,UTENTI[I].cognome);
	}



system("PAUSE");
return 0;
}
