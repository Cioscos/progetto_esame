#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "funzioni.h"

//INSERIMENTO NUOVO UTENTE----------------------------------------------------------------------------------------------------------------------------

int inserimento_utente(int utenti_effettivi)
{
	//VARIABILI MOMENTANEE CONTENENTI LA DATA ATTUALE
	char giorno_corrente[3];
	int mese_corrente;
	char anno_corrente[5];

	//CREAZIONE VARIABILE DI TIPO STRUCT DATA
	struct DATA DATA_CORRENTE;

	//CREAZIONE DI UNA VERIABILE DI TIPO "time_t" NELLA QUALE INSERISCO TUTTE LE INFORMAZINI DEL CALENDARIO DI WINDOWS
	time_t t=time(NULL);
    //CREO UNA VARIABILE DI TIPO STRUCT "tm" NELLA QUALE INSERISCO LE INFORMAZIONI CONTENUTE IN "t"
	struct tm *tp=localtime(&t);
	//INSERISCO NELLE VARIABILI MOMENTANEE ELEMENTI DELLA VARIABILE "tp"
	strftime (anno_corrente,5,"%Y", tp);
    mese_corrente=tp->tm_mon+1;
    strftime (giorno_corrente,3,"%d", tp);
    DATA_CORRENTE.anno=atoi(anno_corrente);
    DATA_CORRENTE.mese=mese_corrente;
    DATA_CORRENTE.giorno=atoi(giorno_corrente);

//INSERIMENTO NOME NUOVO UTENTE
	do{
		system("cls");
		logo();
		printf("Inserisci nome nuovo utente: ");
		SetColor(6);
		gets(UTENTI[utenti_effettivi].nome);
		fflush(stdin);
		SetColor(15);
		fflush(stdin);
	}while((strlen(UTENTI[utenti_effettivi].nome)<1));

//INSERIMENTO NUOVA COGNOME UTENTE
	do{
		system("cls");
		logo();
		printf("Inserisci cognome nuovo utente: ");
		SetColor(6);
		gets(UTENTI[utenti_effettivi].cognome);
		fflush(stdin);
		SetColor(15);
		fflush(stdin);
	}while((strlen(UTENTI[utenti_effettivi].cognome)<1));

//INSERIMENTO NICKNAME UTENTE
	do{
		system("cls");
		logo();
		printf("Inserisci Nickname nuovo utente: ");
		SetColor(6);
		gets(UTENTI[utenti_effettivi].nickname);
		fflush(stdin);
		SetColor(15);
		fflush(stdin);
	}while((strlen(UTENTI[utenti_effettivi].nickname)<1) || (isControllo_Esistenza(utenti_effettivi, UTENTI[utenti_effettivi].nickname, "nickname_utente")!=0));

//INSERIMENTO PASSWORD UTENTE

	//CREO UNA VARIABILE CONTENENTE UN SOLO CARATTERE
	char carattere_bf;
	//CREO UN INDICE CHE NON PUO' ANDARE IN NEGATIVO
	unsigned int i=0;
	//VARIABILE NELLA QUALE I CARATTERI SARANNO INSERITI; SERVIRA' PER ATTUARE IL CONTROLLO DI SICUREZZA
	char controllo[LUNGHEZZA_PASS]={'\0'};
	//VARIABILE FLAG       0=Controllo non superato | 1=Controllo superato
	int uguali;

		system("cls");
		logo();

		//PRIMO INSERIMENTO
		do{
			i=0;
			printf("Inserisci Password nuovo utente di 8 caratteri: ");
			SetColor(6);
			do{
				carattere_bf='\0';
				if( (carattere_bf=getch() )=='\r' )
				{
					controllo[i]='\n';

				}
				else
				{
					if(carattere_bf=='\b')
					{
						if(i!=0)
						{
							printf("\b \b");
							i--;
							controllo[i]='\0';
						}

					}
					else
					{
						fflush(stdin);
						controllo[i]=carattere_bf;
						printf("*");
						i++;
					}
				}

			}while(strlen(controllo)!=LUNGHEZZA_PASS-1);

			SetColor(15);
			printf("\nConferma password: ");
			SetColor(6);

			//SECONDO INSERIMENTO
			i=0;
			do{
				carattere_bf='\0';
				if( (carattere_bf=getch() )=='\r' )
				{
					UTENTI[utenti_effettivi].password[i]='\n';

				}
				else
				{
					if(carattere_bf=='\b')
					{
						if(i!=0)
						{
							printf("\b \b");
							i--;
							UTENTI[utenti_effettivi].password[i]='\0';
						}

					}
					else
					{
						fflush(stdin);
						UTENTI[utenti_effettivi].password[i]=carattere_bf;
						printf("*");
						i++;
					}
				}

			}while(strlen(UTENTI[utenti_effettivi].password)!=LUNGHEZZA_PASS-1);

			if(strcmp(controllo, UTENTI[utenti_effettivi].password)==0)
			{
				uguali=1;
			}
			else
			{
				SetColor(4);
				printf("\nLe password non corrispondono\n\a");
				SetColor(15);
				system("pause");
				system("cls");
				logo();
				uguali=0;
				//AZZERO I VETTORI DI CHAR PER PREPARARGLI AD UN NUOVO INSERIMENTO
				stringclear(controllo, LUNGHEZZA_PASS);
				stringclear(UTENTI[utenti_effettivi].password, LUNGHEZZA_PASS);
			}

		}while(uguali==0);

		SetColor(15);
		printf("\n");
		system("pause");

//INSERIMENTO DATA DI NASCITA

	char data_provvisoria[LUNGHEZZA_MAX]={'\0'};

	system("cls");
	logo();
	printf("Inserisci data di nascita\n");

	//INSERIMENTO ANNO
	do{
			do{
				printf("\nAnno: ");
				SetColor(6);
				gets(data_provvisoria);
				fflush(stdin);
				SetColor(15);
				if(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un anno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci data di nascita:\n");
				}
			}while(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1);

			UTENTI[utenti_effettivi].data_nascita.anno=atoi(data_provvisoria);

			if(UTENTI[utenti_effettivi].data_nascita.anno<1900 || UTENTI[utenti_effettivi].data_nascita.anno>2018)
			{
				system("cls");
				logo();
				SetColor(4);
				printf("Hai inserito un anno non corretto! Riprova\n\n\a");
				SetColor(15);
				system("pause");
				system("cls");
				logo();
				printf("Inserisci data di nascita:\n");
			}
	}while(UTENTI[utenti_effettivi].data_nascita.anno<1900 || UTENTI[utenti_effettivi].data_nascita.anno>2018);

	//INSERIMENTO MESE
	do{

		do{
			printf("\nMese: ");
			SetColor(6);
			stringclear(data_provvisoria,LUNGHEZZA_MAX);
			gets(data_provvisoria);
			SetColor(15);
			if(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1)
			{
				system("cls");
				logo();
				SetColor(4);
				printf("Hai inserito un mese non corretto! Riprova\n\n\a");
				SetColor(15);
				system("pause");
				system("cls");
				logo();
				printf("Inserisci data di nascita:\n");
			}
		}while(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1);

		UTENTI[utenti_effettivi].data_nascita.mese=atoi(data_provvisoria);

		if(UTENTI[utenti_effettivi].data_nascita.mese<0 || UTENTI[utenti_effettivi].data_nascita.mese>12)
		{
			system("cls");
			logo();
			SetColor(4);
			printf("Hai inserito un mese non corretto! Riprova\n\n\a");
			SetColor(15);
			system("pause");
			system("cls");
			logo();
			printf("Inserisci data di nascita:\n");
		}
	}while(UTENTI[utenti_effettivi].data_nascita.mese<0 || UTENTI[utenti_effettivi].data_nascita.mese>12);

	//CONTROLLO ANNO BISESTILE
	if(UTENTI[utenti_effettivi].data_nascita.mese==2)
	{
		if(UTENTI[utenti_effettivi].data_nascita.anno % 4 == 0)
		{
			//ANNO BISESTILE
			do{
				do{

				printf("\nGiorno: ");
				SetColor(6);
				stringclear(data_provvisoria,LUNGHEZZA_MAX);
				gets(data_provvisoria);
				SetColor(15);

					if(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci data di nascita:\n");
					}
				}while(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1);

				UTENTI[utenti_effettivi].data_nascita.giorno=atoi(data_provvisoria);

				if(UTENTI[utenti_effettivi].data_nascita.giorno<=0 || UTENTI[utenti_effettivi].data_nascita.giorno>29)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci data di nascita:\n");
				}
			}while(UTENTI[utenti_effettivi].data_nascita.giorno<=0 || UTENTI[utenti_effettivi].data_nascita.giorno>29);
		}
		else
		{
			//ANNO NON BISESTILE
			do{
				do{
				printf("\nGiorno: ");
				SetColor(6);
				stringclear(data_provvisoria,LUNGHEZZA_MAX);
				gets(data_provvisoria);
				SetColor(15);
					if(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci data di nascita:\n");
					}
				}while(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1);

				UTENTI[utenti_effettivi].data_nascita.giorno=atoi(data_provvisoria);

				if(UTENTI[utenti_effettivi].data_nascita.giorno<=0 || UTENTI[utenti_effettivi].data_nascita.giorno>28)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci data di nascita:\n");
				}
			}while(UTENTI[utenti_effettivi].data_nascita.giorno<=0 || UTENTI[utenti_effettivi].data_nascita.giorno>28);
		}
	}
	else
	{
		//CONTROLLO MESI DA 30 GIORNI
		if(UTENTI[utenti_effettivi].data_nascita.mese==4 || UTENTI[utenti_effettivi].data_nascita.mese==6 || UTENTI[utenti_effettivi].data_nascita.mese==9 || UTENTI[utenti_effettivi].data_nascita.mese==11)
		{
			do{
				do{
				printf("\nGiorno: ");
				SetColor(6);
				stringclear(data_provvisoria,LUNGHEZZA_MAX);
				gets(data_provvisoria);
				SetColor(15);
					if(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci data di nascita:\n");
					}
				}while(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1);

				UTENTI[utenti_effettivi].data_nascita.giorno=atoi(data_provvisoria);

				if(UTENTI[utenti_effettivi].data_nascita.giorno<=0 || UTENTI[utenti_effettivi].data_nascita.giorno>30)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci data di nascita:\n");
				}
			}while(UTENTI[utenti_effettivi].data_nascita.giorno<=0 || UTENTI[utenti_effettivi].data_nascita.giorno>30);
		}
		else
		{
			//CONTROLLO MESI DA 31 GIORNI
			do{
				do{
				printf("\nGiorno: ");
				SetColor(6);
				stringclear(data_provvisoria,LUNGHEZZA_MAX);
				gets(data_provvisoria);
				SetColor(15);
					if(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci data di nascita:\n");
					}
				}while(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1);

				UTENTI[utenti_effettivi].data_nascita.giorno=atoi(data_provvisoria);

				if(UTENTI[utenti_effettivi].data_nascita.giorno<=0 || UTENTI[utenti_effettivi].data_nascita.giorno>31)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci data di nascita:\n");
				}
			}while(UTENTI[utenti_effettivi].data_nascita.giorno<=0 || UTENTI[utenti_effettivi].data_nascita.giorno>31);
		}
	}



	system("cls");
	logo();
	printf("Data di nascita inserita correttamente!\n\n");
	system("pause");
	fflush(stdin);

//INSERIMENTO DATA DI ISCRIZIONE

	system("cls");
	logo();
	printf("Inserisci data di iscrizione:\n");
	stringclear(data_provvisoria, LUNGHEZZA_MAX);

	//INSERIMENTO ANNO
	do{
			do{
				printf("\nAnno: ");
				SetColor(6);
				gets(data_provvisoria);
				fflush(stdin);
				SetColor(15);
				if(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un anno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci data di iscrizione:\n");
				}
			}while(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1);

			UTENTI[utenti_effettivi].data_iscrizione.anno=atoi(data_provvisoria);

			if(UTENTI[utenti_effettivi].data_iscrizione.anno<1900 || UTENTI[utenti_effettivi].data_iscrizione.anno>DATA_CORRENTE.anno)
			{
				system("cls");
				logo();
				SetColor(4);
				printf("Hai inserito un anno non corretto! Riprova\n\n\a");
				SetColor(15);
				system("pause");
				system("cls");
				logo();
				printf("Inserisci data di iscrizione:\n");
			}
	}while(UTENTI[utenti_effettivi].data_iscrizione.anno<1900 || UTENTI[utenti_effettivi].data_iscrizione.anno>DATA_CORRENTE.anno);

	//INSERIMENTO MESE
	do{

		do{
			printf("\nMese: ");
			SetColor(6);
			stringclear(data_provvisoria,LUNGHEZZA_MAX);
			gets(data_provvisoria);
			SetColor(15);
			if(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1)
			{
				system("cls");
				logo();
				SetColor(4);
				printf("Hai inserito un mese non corretto! Riprova\n\n\a");
				SetColor(15);
				system("pause");
				system("cls");
				logo();
				printf("Inserisci data di iscrizione:\n");
			}
		}while(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1);

		UTENTI[utenti_effettivi].data_nascita.mese=atoi(data_provvisoria);

		if(UTENTI[utenti_effettivi].data_iscrizione.mese<0 || UTENTI[utenti_effettivi].data_iscrizione.mese>12)
		{
			system("cls");
			logo();
			SetColor(4);
			printf("Hai inserito un mese non corretto! Riprova\n\n\a");
			SetColor(15);
			system("pause");
			system("cls");
			logo();
			printf("Inserisci data di iscrizione:\n");
		}
	}while(UTENTI[utenti_effettivi].data_iscrizione.mese<0 || UTENTI[utenti_effettivi].data_iscrizione.mese>12);

	//CONTROLLO ANNO BISESTIVO
	if(UTENTI[utenti_effettivi].data_iscrizione.mese==2)
	{
		if(UTENTI[utenti_effettivi].data_iscrizione.anno % 4 == 0)		//Controllo anno bisestile
		{
			//ANNO BISESTILE
			do{
				do{

				printf("\nGiorno: ");
				SetColor(6);
				stringclear(data_provvisoria,LUNGHEZZA_MAX);
				gets(data_provvisoria);
				SetColor(15);

					if(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci data di iscrizione:\n");
					}
				}while(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1);

				UTENTI[utenti_effettivi].data_iscrizione.giorno=atoi(data_provvisoria);

				if(UTENTI[utenti_effettivi].data_iscrizione.giorno<=0 || UTENTI[utenti_effettivi].data_iscrizione.giorno>29)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci data di iscrizione:\n");
				}
			}while(UTENTI[utenti_effettivi].data_iscrizione.giorno<=0 || UTENTI[utenti_effettivi].data_iscrizione.giorno>29);
		}
		else
		{
			//ANNO NON BISESTILE
			do{
				do{
				printf("\nGiorno: ");
				SetColor(6);
				stringclear(data_provvisoria,LUNGHEZZA_MAX);
				gets(data_provvisoria);
				SetColor(15);
					if(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci data di iscrizione:\n");
					}
				}while(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1);

				UTENTI[utenti_effettivi].data_iscrizione.giorno=atoi(data_provvisoria);

				if(UTENTI[utenti_effettivi].data_iscrizione.giorno<=0 || UTENTI[utenti_effettivi].data_iscrizione.giorno>28)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci data di iscrizione:\n");
				}
			}while(UTENTI[utenti_effettivi].data_iscrizione.giorno<=0 || UTENTI[utenti_effettivi].data_iscrizione.giorno>28);
		}
	}
	else
	{
		if(UTENTI[utenti_effettivi].data_iscrizione.mese==4 || UTENTI[utenti_effettivi].data_iscrizione.mese==6 || UTENTI[utenti_effettivi].data_nascita.mese==9 || UTENTI[utenti_effettivi].data_nascita.mese==11)
		{
			//MESE DA 30 GIORNI
			do{
				do{
				printf("\nGiorno: ");
				SetColor(6);
				stringclear(data_provvisoria,LUNGHEZZA_MAX);
				gets(data_provvisoria);
				SetColor(15);
					if(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci data di iscrizione:\n");
					}
				}while(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1);

				UTENTI[utenti_effettivi].data_iscrizione.giorno=atoi(data_provvisoria);

				if(UTENTI[utenti_effettivi].data_iscrizione.giorno<=0 || UTENTI[utenti_effettivi].data_iscrizione.giorno>30)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci data di iscrizione:\n");
				}
			}while(UTENTI[utenti_effettivi].data_iscrizione.giorno<=0 || UTENTI[utenti_effettivi].data_iscrizione.giorno>30);
		}
		else
		{
			//MESE DA 31 GIORNI
			do{
				do{
				printf("\nGiorno: ");
				SetColor(6);
				stringclear(data_provvisoria,LUNGHEZZA_MAX);
				gets(data_provvisoria);
				SetColor(15);
					if(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci data di iscrizione:\n");
					}
				}while(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1);

				UTENTI[utenti_effettivi].data_iscrizione.giorno=atoi(data_provvisoria);

				if(UTENTI[utenti_effettivi].data_iscrizione.giorno<=0 || UTENTI[utenti_effettivi].data_iscrizione.giorno>31)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci data di iscrizione:\n");
				}
			}while(UTENTI[utenti_effettivi].data_iscrizione.giorno<=0 || UTENTI[utenti_effettivi].data_iscrizione.giorno>31);
		}
	}

	system("cls");
	logo();
	printf("Data di iscrizione inserita correttamente!\n\n");
	system("pause");

	utenti_effettivi++;
	return(utenti_effettivi);
}
