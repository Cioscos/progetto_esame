#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include "funzioni.h"


int inserimento_utente(int utenti_effettivi)
{
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

	//INSERIMENTO PASSWORD UTENTE		//TODO fare controllo sulla password

	char carattere_bf;
	unsigned int i=0;
	char controllo[LUNGHEZZA_PASS];
	int uguali;

		system("cls");
		logo();

		do{
			i=0;
			stringclear(controllo);
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
				stringclear(controllo);
				stringclear(UTENTI[utenti_effettivi].password);
			}

		}while(uguali==0);

		SetColor(15);
		printf("\n");
		system("pause");

	//INSERIMENTO DATA DI NASCITA		//controllo sull'input

	char data_provvisoria[LUNGHEZZA_MAX];
	stringclear(data_provvisoria);

	system("cls");
	logo();
	printf("Inserisci data di nascita\n");


	do{
			do{
				printf("\nAnno: ");
				SetColor(6);
				gets(data_provvisoria);
				fflush(stdin);
				SetColor(15);
			}while(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1);

			UTENTI[utenti_effettivi].data_nascita.anno=atoi(data_provvisoria);

			if(UTENTI[utenti_effettivi].data_nascita.anno<1900 || UTENTI[utenti_effettivi].data_nascita.anno>2018)
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
	}while(UTENTI[utenti_effettivi].data_nascita.anno<1900 || UTENTI[utenti_effettivi].data_nascita.anno>2018);



	do{
		printf("\nMese: ");
		SetColor(6);
		scanf("%d", &UTENTI[utenti_effettivi].data_nascita.mese);
		SetColor(15);

		if(UTENTI[utenti_effettivi].data_nascita.mese<0 || UTENTI[utenti_effettivi].data_nascita.mese>12)
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
	}while(UTENTI[utenti_effettivi].data_nascita.mese<0 || UTENTI[utenti_effettivi].data_nascita.mese>12);



	if(UTENTI[utenti_effettivi].data_nascita.mese==2)
	{
		if(UTENTI[utenti_effettivi].data_nascita.anno % 4 == 0)		//Controllo anno bisestile
		{
			do{		//Anno bisestile
				printf("\nGiorno: ");
				SetColor(6);
				scanf("%d", &UTENTI[utenti_effettivi].data_nascita.giorno);
				SetColor(15);
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
			do{
				printf("\nGiorno: ");
				SetColor(6);
				scanf("%d", &UTENTI[utenti_effettivi].data_nascita.giorno);
				SetColor(15);
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
		if(UTENTI[utenti_effettivi].data_nascita.mese==4 || UTENTI[utenti_effettivi].data_nascita.mese==6 || UTENTI[utenti_effettivi].data_nascita.mese==9 || UTENTI[utenti_effettivi].data_nascita.mese==11)
		{
			do{
				printf("\nGiorno: ");
				SetColor(6);
				scanf("%d", &UTENTI[utenti_effettivi].data_nascita.giorno);
				SetColor(15);
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
			do{
				printf("\nGiorno: ");
				SetColor(6);
				scanf("%d", &UTENTI[utenti_effettivi].data_nascita.giorno);
				SetColor(15);
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

	//INSERIMENTO DATA DI ISCRIZIONE		//idem con patate (bsta copiare)

	system("cls");
	logo();
	printf("Inserisci data di iscrizione:\n");
	stringclear(data_provvisoria);

	do{
			do{
				printf("\nAnno: ");
				SetColor(6);
				gets(data_provvisoria);
				fflush(stdin);
				SetColor(15);
			}while(isControllo_Numero(data_provvisoria,LUNGHEZZA_MAX)!=1);

			UTENTI[utenti_effettivi].data_iscrizione.anno=atoi(data_provvisoria);

			if(UTENTI[utenti_effettivi].data_iscrizione.anno<1900 || UTENTI[utenti_effettivi].data_iscrizione.anno>2018)
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
	}while(UTENTI[utenti_effettivi].data_iscrizione.anno<1900 || UTENTI[utenti_effettivi].data_iscrizione.anno>2018);



	do{
		printf("\nMese: ");
		SetColor(6);
		scanf("%d", &UTENTI[utenti_effettivi].data_iscrizione.mese);
		SetColor(15);

		if(UTENTI[utenti_effettivi].data_iscrizione.mese<0 || UTENTI[utenti_effettivi].data_iscrizione.mese>12)
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
	}while(UTENTI[utenti_effettivi].data_iscrizione.mese<0 || UTENTI[utenti_effettivi].data_iscrizione.mese>12);



	if(UTENTI[utenti_effettivi].data_iscrizione.mese==2)
	{
		if(UTENTI[utenti_effettivi].data_iscrizione.anno % 4 == 0)		//Controllo anno bisestile
		{
			do{		//Anno bisestile
				printf("\nGiorno: ");
				SetColor(6);
				scanf("%d", &UTENTI[utenti_effettivi].data_iscrizione.giorno);
				SetColor(15);
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
			do{
				printf("\nGiorno: ");
				SetColor(6);
				scanf("%d", &UTENTI[utenti_effettivi].data_iscrizione.giorno);
				SetColor(15);
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
		if(UTENTI[utenti_effettivi].data_iscrizione.mese==4 || UTENTI[utenti_effettivi].data_iscrizione.mese==6 || UTENTI[utenti_effettivi].data_iscrizione.mese==9 || UTENTI[utenti_effettivi].data_iscrizione.mese==11)
		{
			do{
				printf("\nGiorno: ");
				SetColor(6);
				scanf("%d", &UTENTI[utenti_effettivi].data_iscrizione.giorno);
				SetColor(15);
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
			do{
				printf("\nGiorno: ");
				SetColor(6);
				scanf("%d", &UTENTI[utenti_effettivi].data_iscrizione.giorno);
				SetColor(15);
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
