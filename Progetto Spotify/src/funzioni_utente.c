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
	//DEFINZIONE VARIABILI
	unsigned int i=0;		//Indice non negativo che conta il numero dei caratteri della password
	char carattere_bf;		//Variabile contenenete un solo carattere per la creazione della password
	char controllo[LUNGHEZZA_PASS]={'\0'};		//Variabile utilizzata per effettuare un doppio controllo sulla password per verificare che corrisponda alla prima chiesta in input
	int uguali;	//Variaibile utilizzata come flag    0=Controllo non superato | 1=Controllo superato
	char data_provvisoria[LUNGHEZZA_MAX]={'\0'};		//Variabile contenente la data di tipo char per effettuare i controlli
	char giorno_corrente[3];		//Variaible  momentanea contenente giorno corrente
	int mese_corrente;				//Variaible  momentanea contenente mese corrente
	char anno_corrente[5];			//Variaible  momentanea contenente anno corrente
	struct DATA DATA_CORRENTE;			//Creazione variabile di tipo struct data
	time_t t=time(NULL);		//Creazione di una veriabile di tipo "time_t" nella quale inserisco tutte le informazini del calendario di windows
	struct tm *tp=localtime(&t);		    //Creo una variabile di tipo struct "tm" nella quale inserisco le informazioni contenute in "t"

	//Inserisco nelle variabili momentanee elementi della variabile "tp"
	strftime (anno_corrente,5,"%Y", tp);
    mese_corrente=tp->tm_mon+1;
    strftime (giorno_corrente,3,"%d", tp);
    DATA_CORRENTE.anno=atoi(anno_corrente);
    DATA_CORRENTE.mese=mese_corrente;
    DATA_CORRENTE.giorno=atoi(giorno_corrente);


//INSERIMENTO NOME UTENTE

	do{		//Controllo fin quando non viene inserito almeno una lettera
		system("cls");
		logo();
		printf("Inserisci nome nuovo utente: ");
		SetColor(6);
		fgets(UTENTI[utenti_effettivi].nome,LUNGHEZZA_MAX,stdin);
		eliminazione_acapo(UTENTI[utenti_effettivi].nome);
		fflush(stdin);
		SetColor(15);
	}while((strlen(UTENTI[utenti_effettivi].nome)<1));



//INSERIMENTO COGNOME UTENTE

	do{			//Controllo fin quando non viene inserito almeno una lettera
		system("cls");
		logo();
		printf("Inserisci cognome nuovo utente: ");
		SetColor(6);
		fgets(UTENTI[utenti_effettivi].cognome,LUNGHEZZA_MAX,stdin);
		eliminazione_acapo(UTENTI[utenti_effettivi].cognome);
		fflush(stdin);
		SetColor(15);
	}while((strlen(UTENTI[utenti_effettivi].cognome)<1));



//INSERIMENTO NICKNAME UTENTE

	do{		//Controllo fin quando non viene inserito almeno una lettera e il nickname non deve essere già presente
		system("cls");
		logo();
		printf("Inserisci Nickname nuovo utente: ");
		SetColor(6);
		fgets(UTENTI[utenti_effettivi].nickname,LUNGHEZZA_MAX,stdin);
		eliminazione_acapo(UTENTI[utenti_effettivi].nickname);
		fflush(stdin);
		SetColor(15);
		if((isControllo_Esistenza(utenti_effettivi, UTENTI[utenti_effettivi].nickname, "nickname_utente")==1))
		{
			SetColor(4);
			printf("\nNickname gi%c utilizzato\n\a",133);
			SetColor(15);
			system("pause");
		}
	}while((strlen(UTENTI[utenti_effettivi].nickname)<1) || (isControllo_Esistenza(utenti_effettivi, UTENTI[utenti_effettivi].nickname, "nickname_utente")!=0));



//INSERIMENTO PASSWORD UTENTE

		system("cls");
		logo();
		stringclear(UTENTI[utenti_effettivi].password,LUNGHEZZA_PASS);
		stringclear(controllo,LUNGHEZZA_PASS);

		//PRIMO INSERIMENTO
		do{		//Controllo fin quando la password e la conferma password non corrispondono
			i=0;
			printf("Inserisci Password nuovo utente di 8 caratteri: ");
			SetColor(6);
			do{		//Controllo fin quando la password non raggiungerà gli 8 caratteri
				fflush(stdin);
				carattere_bf='\0';

				if( (carattere_bf=getch() )!='\r' )		//Se premo "tasto invio" non devo fare nulla
				{
					if(carattere_bf=='\b')		//Se premo "cancella" elimino un elemento delle stringa e tolgo un * da schermo
					{
						if(i!=0)
						{
							printf("\b \b");
							i--;
							controllo[i]='\0';
						}

					}
					else		//Se invece è un carattere allora lo inserisco nella variabile e incremento la i
					{
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
			do{		//Controllo fin quando la password e la conferma password non corrispondono
				fflush(stdin);
				carattere_bf='\0';
				if( (carattere_bf=getch() )!='\r' )		//Se premo "tasto invio" non devo fare nulla
				{
					if(carattere_bf=='\b')		//Se premo "cancella" elimino un elemento delle stringa e tolgo un * da schermo
					{
						if(i!=0)
						{
							printf("\b \b");
							i--;
							UTENTI[utenti_effettivi].password[i]='\0';
						}

					}
					else		//Se invece è un carattere allora lo inserisco nella variabile e incremento la i
					{
						fflush(stdin);
						UTENTI[utenti_effettivi].password[i]=carattere_bf;
						printf("*");
						i++;
					}
				}

			}while(strlen(UTENTI[utenti_effettivi].password)!=LUNGHEZZA_PASS-1);



			if(strcmp(controllo, UTENTI[utenti_effettivi].password)==0)		//Controllo se le due password sono uguali
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

	system("cls");
	logo();
	printf("Inserisci data di nascita\n");

	//INSERIMENTO ANNO DI NASCITA
	do{		//Controllo fin quando l'anno non è compreso tra 1900 e 2001(anno per avere l'età minima di 16 anni)
			do{		//Controllo fin quando l'input inserito non è un numero
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

			if(UTENTI[utenti_effettivi].data_nascita.anno<1900 || UTENTI[utenti_effettivi].data_nascita.anno>(DATA_CORRENTE.anno-ETA_MINIMA-1))
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
	}while(UTENTI[utenti_effettivi].data_nascita.anno<1900 || UTENTI[utenti_effettivi].data_nascita.anno>(DATA_CORRENTE.anno-ETA_MINIMA-1));




	//INSERIMENTO MESE DI NASCITA
	do{		//Controllo fin quando il mese non è compreso tra 1 e 12
		do{		//Controllo fin quando l'input inserito non è un numero
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

		if(UTENTI[utenti_effettivi].data_nascita.mese<PRIMO_MESE || UTENTI[utenti_effettivi].data_nascita.mese>ULTIMO_MESE)
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
	}while(UTENTI[utenti_effettivi].data_nascita.mese<PRIMO_MESE || UTENTI[utenti_effettivi].data_nascita.mese>ULTIMO_MESE);


	//INSERIMENTO GIORNO DI NASCITA

	//CONTROLLO SUL GIORNO NELL'ANNO BISESTILE NEL MESE DI FEBBRAIO
	if(UTENTI[utenti_effettivi].data_nascita.mese==2)
	{
		if(UTENTI[utenti_effettivi].data_nascita.anno % 4 == 0)		//Caso in cui l'anno è bisestile
		{
			do{		//Controllo fin quando il giorno non è compreso tra 1 e 29
				do{		//Controllo fin quando l'input inserito non è un numero
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

				if(UTENTI[utenti_effettivi].data_nascita.giorno<1 || UTENTI[utenti_effettivi].data_nascita.giorno>29)
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
			}while(UTENTI[utenti_effettivi].data_nascita.giorno<1 || UTENTI[utenti_effettivi].data_nascita.giorno>29);
		}
		else
		{
			//CONTROLLO SUL GIORNO DEL'ANNO NON BISESTILE NEL MESE DI FEBBRAIO
			do{		//Controllo fin quando il giorno non è compreso tra 1 e 28
				do{		//Controllo fin quando l'input inserito non è un numero
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

				if(UTENTI[utenti_effettivi].data_nascita.giorno<1 || UTENTI[utenti_effettivi].data_nascita.giorno>28)
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
			}while(UTENTI[utenti_effettivi].data_nascita.giorno<1 || UTENTI[utenti_effettivi].data_nascita.giorno>28);
		}
	}
	else
	{
		//CONTROLLO MESI DA 30 GIORNI
		if(UTENTI[utenti_effettivi].data_nascita.mese==4 || UTENTI[utenti_effettivi].data_nascita.mese==6 || UTENTI[utenti_effettivi].data_nascita.mese==9 || UTENTI[utenti_effettivi].data_nascita.mese==11)
		{
			do{		//Controllo fin quando il giorno non è compreso tra 1 e 30
				do{		//Controllo fin quando l'input inserito non è un numero
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
			do{		//Controllo fin quando il giorno non è compreso tra 1 e 31
				do{		//Controllo fin quando l'input inserito non è un numero
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

	//La data di iscrizione corrisponde alla data in cui viene registrato l'utente
	UTENTI[utenti_effettivi].data_iscrizione.anno=DATA_CORRENTE.anno;
	UTENTI[utenti_effettivi].data_iscrizione.mese=DATA_CORRENTE.mese;
	UTENTI[utenti_effettivi].data_iscrizione.giorno=DATA_CORRENTE.giorno;



//INCREMENTO NUMERO UTENTI
	utenti_effettivi++;
	return(utenti_effettivi);
}


void visualizzazione_utenti(int utenti_effettivi)
{
	int i;

	SetColor(11);
	printf("NOME                            COGNOME                         NICKNAME                        DATA NASCITA        DATA ISCRIZIONE\n");
	SetColor(15);

	for(i=0;i<utenti_effettivi;i++)
	{
		printf("%-31s %-31s %-31s %d/%d/%d            %d/%d/%d\n",UTENTI[i].nome,UTENTI[i].cognome,UTENTI[i].nickname,UTENTI[i].data_nascita.giorno,UTENTI[i].data_nascita.mese,UTENTI[i].data_nascita.anno,UTENTI[i].data_iscrizione.giorno,UTENTI[i].data_iscrizione.mese,UTENTI[i].data_iscrizione.anno);
	}
	printf("\n");
}

