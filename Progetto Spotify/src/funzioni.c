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

	for(i=0;i<LUNGHEZZA_INPUT-1;i++)		//Controllo se l'input � diverso da un numero
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

void inserimento_artista(char lista_generi[][LUNGHEZZA_MAX], int *artisti_effettivi)
{

//NOME ARTISTA-----------------------

	logo();
	printf("Inserisci nome artista:");
	gets(ARTISTI[*artisti_effettivi].nome);
	fflush(stdin);

//CODICE ARTISTA---------------------
	do{
		system("cls");
		logo();
		printf("Inserisci codice artista di lunghezza 4:");
		gets(ARTISTI[*artisti_effettivi].codice);
		fflush(stdin);
	}while(strlen(ARTISTI[*artisti_effettivi].codice)!=LUNGHEZZA_CODICE-1 /* && Fare una funzione che controlla se il codice � gi� stato utlizzato */);



	int posizione_genere=0;					//pozione del genere nel vettore lista_generi
	char genere_provvisorio[LUNGHEZZA_MAX];
	int genere_esistente=GENERI_TOT;		//0 genere non esistente | 1 genere esistente
	char risposta[LUNGHEZZA_INPUT]={"si"};	//Risposta alla domanda 'Vuoi inserire un'altra preferenza?'


//Inserimento generi fin quando non viene digitato no-----------------

	do{
		genere_esistente=GENERI_TOT;

		do{
			system("cls");
			logo();
			printf("Lista generi:");

			for(int i=0;i<GENERI_TOT;i++) //Stampa generi su schermo
			{
				printf("%s	",lista_generi[i]);
			}

			printf("\n");

			printf("Inserisci genere artista:");
			gets(genere_provvisorio);
			fflush(stdin);

			for(int i=0;i<GENERI_TOT;i++) //Controlla se il genere è presente nella lista_generi
			{
				if(strcmp(genere_provvisorio,lista_generi[i])==0)	//Quando non è presente (quindi 0) lo inserisce
				{
					genere_esistente=1;
					posizione_genere=i;
					i=GENERI_TOT;

					if(ARTISTI[*artisti_effettivi].genere[posizione_genere]==0)
					{
						ARTISTI[*artisti_effettivi].genere[posizione_genere]=1;		//Genere inserito
						system("cls");
						logo();
						printf("Genere inserito correttamente\n");
						system("PAUSE");
					}
					else
					{
						system("cls");
						logo();
						printf("Genere gia inserito precedentemente\n");
						system("PAUSE");
					}
				}
				else
				{
					if(i==GENERI_TOT-1)
					{
						system("cls");
						logo();
						printf("Genere non inserito correttamente\n");
						system("PAUSE");
					}

				}
			}
		}while(genere_esistente!=1);


		do{
			system("cls");
			logo();
			printf("Vuoi inserire un altro genere?\nRispondere con si o no:");
			scanf("%3s",risposta);
			fflush(stdin);		//Svuota flusso in input
		}while(strcmp(risposta,"si")!=0 && strcmp(risposta,"no")!=0);

	}while(strcmp(risposta,"si")==0);

//INSERIMENTO PRODUTTORE------------------
	system("cls");
	logo();
	printf("Inserisci produttore:");
	gets(ARTISTI[*artisti_effettivi].produttore);
	fflush(stdin);

//INSERIEMNTO NAZIONALITA'----------------
	system("cls");
	logo();
	printf("Inserisci nazionalita:");
	gets(ARTISTI[*artisti_effettivi].nazionalita);
	fflush(stdin);

//INSERIMENTO ANNO NASCITA GRUPPO---------
	char anno_provvisorio[LUNGHEZZA_MAX];

	do{
		system("cls");
		logo();
		printf("Inserisci anno di inizio:");
		gets(anno_provvisorio);
		fflush(stdin);
	}while(isControllo_Numero(anno_provvisorio)!=1);

	ARTISTI[*artisti_effettivi].anno_inizio=atoi(anno_provvisorio);

	*artisti_effettivi+=1;        //Incrementa di 1 il numero degli artisti
}

void visualizzazione_artisti(char lista_generi[][LUNGHEZZA_MAX], int artisti_effettivi)
{
	int i=0,j;
	logo();

//MOSTRO INFORMAZIONE ARTISTA-----------------------------
	for(i=0;i<artisti_effettivi;i++)
	{
		printf("%d -----------CODICE:%s----------------\n"
				"ARTISTA: %s\n",i+1, ARTISTI[i].codice, ARTISTI[i].nome);
		printf("\nGENERE: ");

		for(j=0;j<GENERI_TOT;j++)                    //Trovo il generere dell'artista (1 genere trovato)
		{
			if(ARTISTI[i].genere[j]==1)
			{
				printf("%s ", lista_generi[j]);
			}
		}

		printf("\nNAZIONALITA': %s\n"
				"PRODUTTORE: %s\n"
				"ANNO:%d\n"
				"ASCOLTI:%d\n"
				"MI PIACE:%d\n", ARTISTI[i].nazionalita, ARTISTI[i].produttore, ARTISTI[i].anno_inizio,
				ARTISTI[i].ascolti, ARTISTI[i].preferenze);
	}
}

void modifica_artista(int artisti_effettivi)
{
	int i;
	char risposta[LUNGHEZZA_MAX];
	int scelta;

	printf("\nQuale artista vuoi modificare?\n\n");

	for(i=0;i<artisti_effettivi;i++)
	{
		printf("%s  %s\n", ARTISTI[i].nome, ARTISTI[i].codice);
	}
	gets(risposta);
	fflush(stdin);

	for(i=0;i<artisti_effettivi;i++)
	{
		if(strcmp(risposta, ARTISTI[i].nome)==0)
		{
			printf("Artista trovato!\n");
			i=artisti_effettivi;

			printf("Cosa vuoi modificare?\n"
					"1)Nome\n"
					"2)Genere\n"
					"3)Anno\n"
					"4)Produttore\n"
					"5)Nazionalit%c\n"
					,133);
			scanf("%d", &scelta);
			printf("%d", scelta); //TODO

			system("pause");
		}
		else
		{

		}
	}
}
