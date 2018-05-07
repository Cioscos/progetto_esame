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

void stampa_menu_secondario()
{
	SetColor(2);
	printf("[1]");
	SetColor(15);
	printf("Registra utente\n");
	SetColor(2);
	printf("[2]");
	SetColor(15);
	printf("Accedi al programma\n");
	SetColor(2);
	printf("[0]");
	SetColor(15);
	printf("Torna al menu principale\n\nInserisci comndo: ");
}

void stampa_menu_utente()
{
	SetColor(2);
	printf("[1]");
	SetColor(15);
	printf("Visualizza profilo utente\n");
	SetColor(2);
	printf("[2]");
	SetColor(15);
	printf("Aggiungi nuova preferenza\n");
	SetColor(2);
	printf("[3]");
	SetColor(15);
	printf("Elimina preferenza\n");
	SetColor(2);
	printf("[4]");
	SetColor(15);
	printf("Modifica utente\n");
	SetColor(2);
	printf("[5]");
	SetColor(15);
	printf("Elimina utente\n");
	SetColor(2);
	printf("[0]");
	SetColor(15);
	printf("Disconnetti\n\nInserisci comando: ");
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

	for(i=0;i<lughezza_effettiva;i++)		//Controllo se l'input ? diverso da un numero
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

			case MENU_SECONDARIO: stampa_menu_secondario();
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

			case MENU_SECONDARIO: stampa_menu_secondario();
								  break;
		}
		stringclear(input_utente, LUNGHEZZA_INPUT);
		scanf("%3s",input_utente);
		fflush(stdin);		//Svuota flusso in input
	}
}

void eliminazione_acapo(char *input)
{
	int i;
	for(i=0;i<LUNGHEZZA_MAX;i++)
	{
		if(input[i]=='\n')
			input[i]='\0';
	}
}

int isControllo_Esistenza(int numero_presenze, char* campo, char* controllo)
{
	int i;
	int presenza=0;		//0 elemento gi? presente - 1 elemento non presente

	if(strcmp(controllo,"nome_artista")==0)
	{
		for(i=0;i<numero_presenze;i++)
		{
			if(strcmp(campo,ARTISTI[i].nome)==0)
			{
				presenza=1;
			}
		}
	}


	if(strcmp(controllo,"codice_artista")==0)
	{
		for(i=0;i<numero_presenze;i++)
		{
			if(strcmp(campo,ARTISTI[i].codice)==0)
			{
				presenza=1;
			}
		}
	}


	if(strcmp(controllo,"nickname_utente")==0)
	{
		for(i=0;i<numero_presenze;i++)
		{
			if(strcmp(campo,UTENTI[i].nickname)==0)
			{
				presenza=1;
			}
		}
	}

	if(strcmp(controllo,"nome_utente")==0)
	{
		for(i=0;i<numero_presenze;i++)
		{
			if(strcmp(campo,UTENTI[i].nome)==0)
			{
				presenza=1;
			}
		}
	}

	if(strcmp(controllo,"cognome_utente")==0)
	{
		for(i=0;i<numero_presenze;i++)
		{
			if(strcmp(campo,UTENTI[i].cognome)==0)
			{
				presenza=1;
			}
		}
	}



	if(presenza==1)
	{
		return presenza;		//Ritorna 1 - elemento non presente
	}
	else
	{
		return presenza;		//Ritorna 0 - elemento gi? presente
	}

}

void gestione_file(char modalita, int tipo, int *nartisti, int *nutenti)                 //LETTURA FILE "r" | SCRITTURA FILE "w"  | AGGIUNTA ELEMENTO "a"   --   ARTISTA "0"  --  UTENTE "1"
{
	int i=0, j, k;
	char buffer[200]={'\0'};
	char *token;
	char virgola[2]={","};
	char barra[2]={"/"};
	char itoa_bf[5]={'\0'};
	char lista_generi[GENERI_TOT][LUNGHEZZA_MAX]={"N.A.","Electro","Pop","Techno","Rock","Jazz","Rap","Blues","Country","Britpop","Dubstep","EDM","Hip-Hop","House","Musica leggera","Trap","Trance","Disco","Dance"};
	if(modalita=='r' && tipo==0)
	{
		FILE *pf;

		pf = fopen("C:\\Users\\Mattia\\git\\progetto_esame\\Progetto Spotify\\File\\artisti.txt", "r");

		if(pf!=NULL)
		{
			i=0;

			while( !feof(pf) )
			{
				fgets(buffer, 200, pf);

				token=strtok(buffer, virgola);
				strcpy(ARTISTI[i].codice, token);

				token=strtok(NULL, virgola);
				strcpy(ARTISTI[i].nome, token);

				token=strtok(NULL, virgola);
				strcpy(ARTISTI[i].produttore, token);

				token=strtok(NULL, virgola);
				strcpy(ARTISTI[i].nazionalita, token);

				token=strtok(NULL, virgola);
				ARTISTI[i].anno_inizio = atoi(token);

				token=strtok(NULL, virgola);
				ARTISTI[i].ascolti = atoi(token);

				token=strtok(NULL, virgola);
				ARTISTI[i].preferenze = atoi(token);

				token=strtok(NULL, virgola);
				eliminazione_acapo(token);

				for(k=0;k<GENERI_TOT;k++)   //TODO vito
				{
					for(j=0;j<GENERI_TOT;j++)
					{
						if(strcmp(lista_generi[j], token)==0)
						{
							ARTISTI[i].genere[j]=1;
							j=GENERI_TOT;
							if( (token=strtok(NULL, virgola)) == NULL)
							{
								k=GENERI_TOT;
							}
							else
							{
								eliminazione_acapo(token);
							}
						}
					}
				}

				i++;
				*nartisti+=1;
			}
			fclose(pf);
		}
		else
		{
			SetColor(4);
			printf("\n\aErrore nel caricamento del file\n");
			SetColor(15);
			system("pause");
			fclose(pf);
		}
	}
	else
	{
		if(modalita=='a' && tipo==0)
		{
			FILE *pf;

			pf = fopen("C:\\Users\\Mattia\\git\\progetto_esame\\Progetto Spotify\\File\\artisti.txt", "a");

			if(pf!=NULL)
			{
				*nartisti-=1;

				strcpy(buffer,"\n");
				strcat(buffer, ARTISTI[*nartisti].codice);
				strcat(buffer,",");

				strcat(buffer, ARTISTI[*nartisti].nome);
				strcat(buffer,",");

				for(j=0;j<GENERI_TOT;j++)
				{
					if(ARTISTI[*nartisti].genere[j]==1)
					{
						strcat(buffer, lista_generi[j]);
						strcat(buffer,",");
					}
				}

				strcat(buffer, ARTISTI[*nartisti].produttore);
				strcat(buffer,",");

				strcat(buffer, ARTISTI[*nartisti].nazionalita);
				strcat(buffer,",");

				itoa(ARTISTI[*nartisti].anno_inizio, itoa_bf, 10);
				strcat(buffer, itoa_bf);
				strcat(buffer,",");

				itoa(ARTISTI[*nartisti].ascolti, itoa_bf, 10);
				strcat(buffer, itoa_bf);
				strcat(buffer,",");

				itoa(ARTISTI[*nartisti].ascolti, itoa_bf, 10);
				strcat(buffer, itoa_bf);

				fprintf(pf, "%s", buffer);
				*nartisti+=1;
			}
			else
			{
				SetColor(4);
				printf("\n\aErrore nel caricamento del file\n");
				SetColor(15);
				system("pause");
				fclose(pf);
			}
		}
		else
		{
			if(modalita=='w' && tipo==0)
			{
				FILE *pf;

				pf = fopen("C:\\Users\\Mattia\\git\\progetto_esame\\Progetto Spotify\\File\\artisti.txt", "w");

				if(pf!=NULL)
				{
					for(j=0;j<*nartisti;j++)
					{
						strcpy(buffer, ARTISTI[j].codice);
						strcat(buffer,",");

						strcat(buffer, ARTISTI[j].nome);
						strcat(buffer,",");

						for(i=0;i<GENERI_TOT;i++)
						{
							if(ARTISTI[j].genere[i]==1)
							{
								strcat(buffer, lista_generi[i]);
								strcat(buffer,",");
							}
						}

						strcat(buffer, ARTISTI[j].produttore);
						strcat(buffer,",");

						strcat(buffer, ARTISTI[j].nazionalita);
						strcat(buffer,",");

						itoa(ARTISTI[j].anno_inizio, itoa_bf, 10);
						strcat(buffer, itoa_bf);
						strcat(buffer,",");

						itoa(ARTISTI[j].ascolti, itoa_bf, 10);
						strcat(buffer, itoa_bf);
						strcat(buffer,",");

						itoa(ARTISTI[j].ascolti, itoa_bf, 10);
						strcat(buffer, itoa_bf);

						strcat(buffer, "\n");

						fprintf(pf, "%s", buffer);
					}
				}
				else
				{
					SetColor(4);
					printf("\n\aErrore nel caricamento del file\n");
					SetColor(15);
					system("pause");
					fclose(pf);
				}
			}
			else
			{
				if(modalita=='r' && tipo==1)
				{
					FILE *pf;

					pf = fopen("C:\\Users\\Mattia\\git\\progetto_esame\\Progetto Spotify\\File\\utenti.txt", "r");

					if(pf!=NULL)
					{
						i=0;

						while(!feof(pf))
						{
							fgets(buffer, 101, pf);

							token=strtok(buffer, virgola);
							strcpy(UTENTI[i].nickname, token);

							token=strtok(NULL, virgola);
							strcpy(UTENTI[i].password, token);

							token=strtok(NULL, virgola);
							strcpy(UTENTI[i].nome, token);

							token=strtok(NULL, virgola);
							strcpy(UTENTI[i].cognome, token);

							token=strtok(NULL, barra);
							UTENTI[i].data_nascita.giorno=atoi(token);

							token=strtok(NULL, barra);
							UTENTI[i].data_nascita.mese=atoi(token);

							token=strtok(NULL, virgola);
							UTENTI[i].data_nascita.anno=atoi(token);

							token=strtok(NULL, barra);
							UTENTI[i].data_iscrizione.giorno=atoi(token);

							token=strtok(NULL, barra);
							UTENTI[i].data_iscrizione.mese=atoi(token);

							token=strtok(NULL, barra);
							UTENTI[i].data_iscrizione.anno=atoi(token);

							i++;
							*nutenti+=1;
						}
					}
					else
					{
						SetColor(4);
						printf("\n\aErrore nel caricamento del file\n");
						SetColor(15);
						system("pause");
						fclose(pf);
					}
				}
				else
				{
					if(modalita=='a' && tipo==1)
					{
						FILE *pf;

						pf = fopen("C:\\Users\\Mattia\\git\\progetto_esame\\Progetto Spotify\\File\\utenti.txt", "a");

						if(pf!=NULL)
						{
							*nutenti-=1;

							strcpy(buffer,"\n");
							strcat(buffer, UTENTI[*nutenti].nickname);
							strcat(buffer,",");

							strcat(buffer, UTENTI[*nutenti].password);
							strcat(buffer, ",");

							strcat(buffer, UTENTI[*nutenti].nome);
							strcat(buffer, ",");

							strcat(buffer, UTENTI[*nutenti].cognome);
							strcat(buffer, ",");

							itoa(UTENTI[*nutenti].data_nascita.giorno, itoa_bf,10);
							strcat(buffer, itoa_bf);
							strcat(buffer, "/");

							itoa(UTENTI[*nutenti].data_nascita.mese, itoa_bf,10);
							strcat(buffer, itoa_bf);
							strcat(buffer, "/");

							itoa(UTENTI[*nutenti].data_nascita.anno, itoa_bf,10);
							strcat(buffer, itoa_bf);
							strcat(buffer, "/,");

							itoa(UTENTI[*nutenti].data_iscrizione.giorno, itoa_bf,10);
							strcat(buffer, itoa_bf);
							strcat(buffer, "/");

							itoa(UTENTI[*nutenti].data_iscrizione.mese, itoa_bf,10);
							strcat(buffer, itoa_bf);
							strcat(buffer, "/");

							itoa(UTENTI[*nutenti].data_iscrizione.anno, itoa_bf,10);
							strcat(buffer, itoa_bf);

							fprintf(pf,"%s", buffer);

							*nutenti+=1;
						}
						else
						{
							SetColor(4);
							printf("\n\aErrore nel caricamento del file\n");
							SetColor(15);
							system("pause");
							fclose(pf);
						}
					}
					else
					{
						if(modalita=='w' && tipo==1)
						{
							FILE *pf;

							pf = fopen("C:\\Users\\Mattia\\git\\progetto_esame\\Progetto Spotify\\File\\utenti.txt", "w");

							i=0;

							if(pf!=NULL)
							{
								strcpy(buffer, UTENTI[i].nickname);
								strcat(buffer,",");

								strcat(buffer, UTENTI[i].password);
								strcat(buffer, ",");

								strcat(buffer, UTENTI[i].nome);
								strcat(buffer, ",");

								strcat(buffer, UTENTI[i].cognome);
								strcat(buffer, ",");

								itoa(UTENTI[i].data_nascita.giorno, itoa_bf,10);
								strcat(buffer, itoa_bf);
								strcat(buffer, "/");

								itoa(UTENTI[i].data_nascita.mese, itoa_bf,10);
								strcat(buffer, itoa_bf);
								strcat(buffer, "/");

								itoa(UTENTI[i].data_nascita.anno, itoa_bf,10);
								strcat(buffer, itoa_bf);
								strcat(buffer, "/,");

								itoa(UTENTI[i].data_iscrizione.giorno, itoa_bf,10);
								strcat(buffer, itoa_bf);
								strcat(buffer, "/");

								itoa(UTENTI[i].data_iscrizione.mese, itoa_bf,10);
								strcat(buffer, itoa_bf);
								strcat(buffer, "/");

								itoa(UTENTI[i].data_iscrizione.anno, itoa_bf,10);
								strcat(buffer, itoa_bf);
								strcat(buffer, "\n");

								fprintf(pf, "%s", buffer);

								i++;
							}
							else
							{
								SetColor(4);
								printf("\n\aErrore nel caricamento del file\n");
								SetColor(15);
								system("pause");
								fclose(pf);
							}
						}
					}
				}
			}
		}
	}
}

