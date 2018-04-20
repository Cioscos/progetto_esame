#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main(int argc, char *argv[]){

	int I=0;
	FILE *pf;

	pf=fopen("C:\\Users\\Mattia\\git\\progetto_esame\\Progetto Spotify\\File\\Utenti.csv","r");

	if(pf!=NULL)
	{
		while(!feof(pf))
	    {
			fgets(UTENTI[I].nickname, LUNGHEZZA_MAX ,pf);
			fflush(stdin);
			fgets(UTENTI[I].password, LUNGHEZZA_MAX ,pf);
			fflush(stdin);
			fgets(UTENTI[I].nome, LUNGHEZZA_MAX ,pf);
			fflush(stdin);
			fgets(UTENTI[I].cognome, LUNGHEZZA_MAX ,pf);
			fflush(stdin);
			fscanf(pf, "%d", &UTENTI[I].data_nascita.giorno);
			fscanf(pf, "%d", &UTENTI[I].data_nascita.mese);
			fscanf(pf, "%d", &UTENTI[I].data_nascita.anno);
			fscanf(pf, "%d", &UTENTI[I].data_iscrizione.giorno);
			fscanf(pf, "%d", &UTENTI[I].data_iscrizione.mese);
			fscanf(pf, "%d", &UTENTI[I].data_iscrizione.anno);
			I++;
		}
	}
	else
	{
		printf("\n Errore nel caricamento del file ");
	}
	fclose(pf);

	for(I=0;I<10;I++)
	{
		printf("%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n",UTENTI[I].nickname,UTENTI[I].password,UTENTI[I].nome,UTENTI[I].cognome, UTENTI[I].data_nascita.giorno, UTENTI[I].data_nascita.mese, UTENTI[I].data_nascita.anno, UTENTI[I].data_iscrizione.giorno, UTENTI[I].data_iscrizione.mese, UTENTI[I].data_iscrizione.anno);
	}



system("PAUSE");
return 0;
}
