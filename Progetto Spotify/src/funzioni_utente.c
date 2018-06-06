/*!
 * @file funzioni_utente.c
 * @brief File contenente tutte le funzioni che riguardano la gestione degli utenti
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "funzioni.h"

/**
 * Questa funzione permette di inserire un nuovo utente nella lista utenti memorizzata.\n
 * Prima di tutto devono essere inseriti nome, cognome e nickname; sarà effettuato il controllo per far si che il nome e il cognome siano almeno di una lettera.\n
 * Successivaente l'utente dovrà inserire la sua password. La funzione prevede un doppio controllo per la password.\n
 * L'utente dovrà inserire la sua data di nascita nell'ordine AAAA/MM/GG a causa dei controlli di bisestilità\n
 * e di numeri giorni dei mesi.
 * La data di iscrizione sarà inserita automaticamente.
 *
 * @pre La variabile di tipo struct DATA, ::DATA_CORRENTE deve essere riempita in uno qualsiasi dei source file\n
 * possibilmente con la libreria time.h. Un esempio è quello presente nel file main.c riportato qui sotto:\n
 * \code{.c}
 * time_t t=time(NULL);
 * struct tm *tp=localtime(&t);
 *
 * char giorno_corrente[3];    //Variaible  momentanea contenente giorno corrente
 * int mese_corrente;			//Variaible  momentanea contenente mese corrente
 * char anno_corrente[5];		//Variaible  momentanea contenente anno corrente
 * strftime (anno_corrente,5,"%Y", tp);
 * mese_corrente=tp->tm_mon+1;
 * strftime (giorno_corrente,3,"%d", tp);
 * DATA_CORRENTE.anno=atoi(anno_corrente);
 * DATA_CORRENTE.mese=mese_corrente;
 * DATA_CORRENTE.giorno=atoi(giorno_corrente);
 * \endcode
 * @post All'inserimento di dati fuori dai canoni programmati, ci saranno dei messaggi di errore
 */
int inserimento_utente(int utenti_effettivi) {
	//DEFINZIONE VARIABILI
	unsigned int i = 0;	//Indice non negativo che conta il numero dei caratteri della password
	char carattere_bf;//Variabile contenenete un solo carattere per la creazione della password
	char controllo[LUNGHEZZA_PASS] = { '\0' };//Variabile utilizzata per effettuare un doppio controllo sulla password per verificare che corrisponda alla prima chiesta in input
	int uguali;	//Variaibile utilizzata come flag    0=Controllo non superato | 1=Controllo superato
	char data_provvisoria[LUNGHEZZA_MAX] = { '\0' };//Variabile contenente la data di tipo char per effettuare i controlli

//INSERIMENTO NOME UTENTE

	do
	{	//Controllo fin quando non viene inserito almeno una lettera
		system("cls");
		logo();
		printf("Inserisci nome utente: ");
		SetColor(6);
		fgets(UTENTI[utenti_effettivi].nome, LUNGHEZZA_MAX, stdin);
		strcpy(UTENTI[utenti_effettivi].nome, eliminazione_acapo(UTENTI[utenti_effettivi].nome));
		fflush(stdin);
		SetColor(15);
	}while ((strlen(UTENTI[utenti_effettivi].nome) < 1));

//INSERIMENTO COGNOME UTENTE

	do
	{			//Controllo fin quando non viene inserito almeno una lettera
		system("cls");
		logo();
		printf("Inserisci cognome nuovo utente: ");
		SetColor(6);
		fgets(UTENTI[utenti_effettivi].cognome, LUNGHEZZA_MAX, stdin);
		strcpy(UTENTI[utenti_effettivi].cognome, eliminazione_acapo(UTENTI[utenti_effettivi].cognome));
		fflush(stdin);
		SetColor(15);
	}while ((strlen(UTENTI[utenti_effettivi].cognome) < 1));

//INSERIMENTO NICKNAME UTENTE

	do
	{//Controllo fin quando non viene inserito almeno una lettera e il nickname non deve essere già  presente
		system("cls");
		logo();
		printf("Inserisci Nickname nuovo utente: ");
		SetColor(6);
		fgets(UTENTI[utenti_effettivi].nickname, LUNGHEZZA_MAX, stdin);
		strcpy(UTENTI[utenti_effettivi].nickname, eliminazione_acapo(UTENTI[utenti_effettivi].nickname));
		fflush(stdin);
		SetColor(15);
		if ((isControllo_Esistenza(utenti_effettivi, UTENTI[utenti_effettivi].nickname, "nickname_utente")
		        == 1))
		{
			SetColor(4);
			printf("\nNickname gi%c utilizzato\n\a", 133);
			SetColor(15);
			system("pause");
		}
	}while ((strlen(UTENTI[utenti_effettivi].nickname) < 1)
	        || (isControllo_Esistenza(utenti_effettivi, UTENTI[utenti_effettivi].nickname, "nickname_utente")
	                != 0));

//INSERIMENTO PASSWORD UTENTE

	system("cls");
	logo();
	stringclear(UTENTI[utenti_effettivi].password, LUNGHEZZA_PASS);
	stringclear(controllo, LUNGHEZZA_PASS);

	//PRIMO INSERIMENTO
	do
	{//Controllo fin quando la password e la conferma password non corrispondono
		i = 0;
		printf("Inserisci Password nuovo utente di 8 caratteri: ");
		SetColor(6);
		do
		{	//Controllo fin quando la password non raggiungerà gli 8 caratteri
			fflush(stdin);
			carattere_bf = '\0';

			if ((carattere_bf = getch()) != '\r')//Se premo "tasto invio" non devo fare nulla
			{
				if (carattere_bf == '\b')//Se premo "cancella" elimino un elemento delle stringa e tolgo un * da schermo
				{
					if (i != 0)
					{
						printf("\b \b");
						i--;
						controllo[i] = '\0';
					}

				}else//Se invece è un carattere allora lo inserisco nella variabile e incremento la i
				{
					controllo[i] = carattere_bf;
					printf("*");
					i++;
				}
			}
		}while (strlen(controllo) != LUNGHEZZA_PASS - 1);

		SetColor(15);
		printf("\nConferma password: ");
		SetColor(6);

		//SECONDO INSERIMENTO
		i = 0;
		do
		{//Controllo fin quando la password e la conferma password non corrispondono
			fflush(stdin);
			carattere_bf = '\0';
			if ((carattere_bf = getch()) != '\r')//Se premo "tasto invio" non devo fare nulla
			{
				if (carattere_bf == '\b')//Se premo "cancella" elimino un elemento delle stringa e tolgo un * da schermo
				{
					if (i != 0)
					{
						printf("\b \b");
						i--;
						UTENTI[utenti_effettivi].password[i] = '\0';
					}

				}else//Se invece è un carattere allora lo inserisco nella variabile e incremento la i
				{
					fflush(stdin);
					UTENTI[utenti_effettivi].password[i] = carattere_bf;
					printf("*");
					i++;
				}
			}

		}while (strlen(UTENTI[utenti_effettivi].password) != LUNGHEZZA_PASS - 1);

		if (strcmp(controllo, UTENTI[utenti_effettivi].password) == 0)//Controllo se le due password sono uguali
		{
			uguali = 1;
		}else
		{
			SetColor(4);
			printf("\nLe password non corrispondono\n\a");
			SetColor(15);
			system("pause");
			system("cls");
			logo();
			uguali = 0;
			//AZZERO I VETTORI DI CHAR PER PREPARARGLI AD UN NUOVO INSERIMENTO
			stringclear(controllo, LUNGHEZZA_PASS);
			stringclear(UTENTI[utenti_effettivi].password, LUNGHEZZA_PASS);
		}
	}while (uguali == 0);

	SetColor(15);
	printf("\n");
	system("pause");

//INSERIMENTO DATA DI NASCITA

	system("cls");
	logo();
	printf("Inserisci data di nascita\n");

	//INSERIMENTO ANNO DI NASCITA
	do
	{//Controllo fin quando l'anno non è compreso tra 1900 e 2001(anno per avere l'età minima di 16 anni)
		do
		{		//Controllo fin quando l'input inserito non è un numero
			printf("\nAnno: ");
			SetColor(6);
			fgets(data_provvisoria,LUNGHEZZA_MAX,stdin);
			strcpy(data_provvisoria, eliminazione_acapo(data_provvisoria));
			fflush(stdin);
			SetColor(15);
			if (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX) != 1)
			{
				system("cls");
				logo();
				SetColor(4);
				printf("Hai inserito un anno non corretto! Riprova\n\n\a");
				SetColor(15);
				system("pause");
				system("cls");
				logo();
				printf("Inserisci data di nascita in cifre\n");
			}
		}while (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX) != 1);

		UTENTI[utenti_effettivi].data_nascita.anno = atoi(data_provvisoria);

		if (UTENTI[utenti_effettivi].data_nascita.anno < 1900
		        || UTENTI[utenti_effettivi].data_nascita.anno
		                > (DATA_CORRENTE.anno - ETA_MINIMA - 1))
		{
			system("cls");
			logo();
			SetColor(4);
			printf("Hai inserito un anno non corretto! Riprova\n\n\a");
			SetColor(15);
			system("pause");
			system("cls");
			logo();
			printf("Inserisci data di nascita in cifre\n");
		}
	}while (UTENTI[utenti_effettivi].data_nascita.anno < 1900
	        || UTENTI[utenti_effettivi].data_nascita.anno
	                > (DATA_CORRENTE.anno - ETA_MINIMA - 1));

	//INSERIMENTO MESE DI NASCITA
	do
	{		//Controllo fin quando il mese non è compreso tra 1 e 12
		do
		{		//Controllo fin quando l'input inserito non è un numero
			printf("\nMese: ");
			SetColor(6);
			stringclear(data_provvisoria, LUNGHEZZA_MAX);
			fgets(data_provvisoria,LUNGHEZZA_MAX,stdin);
			strcpy(data_provvisoria, eliminazione_acapo(data_provvisoria));
			fflush(stdin);
			SetColor(15);
			if (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX) != 1)
			{
				system("cls");
				logo();
				SetColor(4);
				printf("Hai inserito un mese non corretto! Riprova\n\n\a");
				SetColor(15);
				system("pause");
				system("cls");
				logo();
				printf("Inserisci data di nascita in cifre\n");
			}
		}while (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX) != 1);

		UTENTI[utenti_effettivi].data_nascita.mese = atoi(data_provvisoria);

		if (UTENTI[utenti_effettivi].data_nascita.mese < PRIMO_MESE
		        || UTENTI[utenti_effettivi].data_nascita.mese > ULTIMO_MESE)
		{
			system("cls");
			logo();
			SetColor(4);
			printf("Hai inserito un mese non corretto! Riprova\n\n\a");
			SetColor(15);
			system("pause");
			system("cls");
			logo();
			printf("Inserisci data di nascita in cifre\n");
		}
	}while (UTENTI[utenti_effettivi].data_nascita.mese < PRIMO_MESE
	        || UTENTI[utenti_effettivi].data_nascita.mese > ULTIMO_MESE);

	//INSERIMENTO GIORNO DI NASCITA

	//CONTROLLO SUL GIORNO NELL'ANNO BISESTILE NEL MESE DI FEBBRAIO
	if (UTENTI[utenti_effettivi].data_nascita.mese == 2)
	{
		if (UTENTI[utenti_effettivi].data_nascita.anno % 4 == 0)//Caso in cui l'anno è bisestile
		{
			do
			{		//Controllo fin quando il giorno non è compreso tra 1 e 29
				do
				{		//Controllo fin quando l'input inserito non è un numero
					printf("\nGiorno: ");
					SetColor(6);
					stringclear(data_provvisoria, LUNGHEZZA_MAX);
					fgets(data_provvisoria,LUNGHEZZA_MAX,stdin);
					strcpy(data_provvisoria, eliminazione_acapo(data_provvisoria));
					fflush(stdin);
					SetColor(15);

					if (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX)
					        != 1)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci data di nascita in cifre\n");
					}
				}while (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX) != 1);

				UTENTI[utenti_effettivi].data_nascita.giorno =
				        atoi(data_provvisoria);

				if (UTENTI[utenti_effettivi].data_nascita.giorno < 1
				        || UTENTI[utenti_effettivi].data_nascita.giorno > 29)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci data di nascita in cifre\n");
				}
			}while (UTENTI[utenti_effettivi].data_nascita.giorno < 1
			        || UTENTI[utenti_effettivi].data_nascita.giorno > 29);
		}else
		{
			//CONTROLLO SUL GIORNO DEL'ANNO NON BISESTILE NEL MESE DI FEBBRAIO
			do
			{		//Controllo fin quando il giorno non è compreso tra 1 e 28
				do
				{		//Controllo fin quando l'input inserito non è un numero
					printf("\nGiorno: ");
					SetColor(6);
					stringclear(data_provvisoria, LUNGHEZZA_MAX);
					fgets(data_provvisoria,LUNGHEZZA_MAX,stdin);
					strcpy(data_provvisoria, eliminazione_acapo(data_provvisoria));
					fflush(stdin);
					SetColor(15);
					if (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX)
					        != 1)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci data di nascita in cifre\n");
					}
				}while (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX) != 1);

				UTENTI[utenti_effettivi].data_nascita.giorno =
				        atoi(data_provvisoria);

				if (UTENTI[utenti_effettivi].data_nascita.giorno < 1
				        || UTENTI[utenti_effettivi].data_nascita.giorno > 28)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci data di nascita in cifre\n");
				}
			}while (UTENTI[utenti_effettivi].data_nascita.giorno < 1
			        || UTENTI[utenti_effettivi].data_nascita.giorno > 28);
		}
	}else
	{
		//CONTROLLO MESI DA 30 GIORNI
		if (UTENTI[utenti_effettivi].data_nascita.mese == 4
		        || UTENTI[utenti_effettivi].data_nascita.mese == 6
		        || UTENTI[utenti_effettivi].data_nascita.mese == 9
		        || UTENTI[utenti_effettivi].data_nascita.mese == 11)
		{
			do
			{		//Controllo fin quando il giorno non è compreso tra 1 e 30
				do
				{	//Controllo fin quando l'input inserito non è un numero
					printf("\nGiorno: ");
					SetColor(6);
					stringclear(data_provvisoria, LUNGHEZZA_MAX);
					fgets(data_provvisoria,LUNGHEZZA_MAX,stdin);
					strcpy(data_provvisoria, eliminazione_acapo(data_provvisoria));
					fflush(stdin);
					SetColor(15);
					if (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX)
					        != 1)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci data di nascita in cifre\n");
					}
				}while (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX) != 1);

				UTENTI[utenti_effettivi].data_nascita.giorno =
				        atoi(data_provvisoria);

				if (UTENTI[utenti_effettivi].data_nascita.giorno <= 0
				        || UTENTI[utenti_effettivi].data_nascita.giorno > 30)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci data di nascita in cifre\n");
				}
			}while (UTENTI[utenti_effettivi].data_nascita.giorno <= 0
			        || UTENTI[utenti_effettivi].data_nascita.giorno > 30);
		}else
		{
			//CONTROLLO MESI DA 31 GIORNI
			do
			{		//Controllo fin quando il giorno non è compreso tra 1 e 31
				do
				{		//Controllo fin quando l'input inserito non è un numero
					printf("\nGiorno: ");
					SetColor(6);
					stringclear(data_provvisoria, LUNGHEZZA_MAX);
					fgets(data_provvisoria,LUNGHEZZA_MAX,stdin);
					strcpy(data_provvisoria, eliminazione_acapo(data_provvisoria));
					fflush(stdin);
					SetColor(15);
					if (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX)
					        != 1)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci data di nascita in cifre\n");
					}
				}while (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX) != 1);

				UTENTI[utenti_effettivi].data_nascita.giorno =
				        atoi(data_provvisoria);

				if (UTENTI[utenti_effettivi].data_nascita.giorno <= 0
				        || UTENTI[utenti_effettivi].data_nascita.giorno > 31)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci data di nascita in cifre\n");
				}
			}while (UTENTI[utenti_effettivi].data_nascita.giorno <= 0
			        || UTENTI[utenti_effettivi].data_nascita.giorno > 31);
		}
	}

	system("cls");
	logo();
	printf("Data di nascita inserita correttamente!\n\n");
	system("pause");
	fflush(stdin);

//INSERIMENTO DATA DI ISCRIZIONE

	//La data di iscrizione corrisponde alla data in cui viene registrato l'utente
	UTENTI[utenti_effettivi].data_iscrizione.anno = DATA_CORRENTE.anno;
	UTENTI[utenti_effettivi].data_iscrizione.mese = DATA_CORRENTE.mese;
	UTENTI[utenti_effettivi].data_iscrizione.giorno = DATA_CORRENTE.giorno;

//AZZZERAMENTO VETTORE PREFERENZE

	for (i = 0; i < ARTISTI_MAX; i++)
	{
		UTENTI[utenti_effettivi].preferenze[i] = 0;
	}

//INCREMENTO NUMERO UTENTI
	utenti_effettivi++;
	return (utenti_effettivi);
}

/**
 * La password dell'utente sarà oscurata permettendo di vedere solo la prima e l'ultima lettera.
 */
void stampa_profilo(int posizione_utente) {
	int i, j;
	SetColor(3);
	printf("NICKNAME:");
	SetColor(15);
	printf("%-31s", UTENTI[posizione_utente].nickname);
	SetColor(3);
	printf("PASSWORD:");
	SetColor(15);
	for(i=0;i<LUNGHEZZA_PASS;i++)    //Occultamento della password
	{
		if( (UTENTI[posizione_utente].password[i]!='\0') && (i==0 || i==(strlen(UTENTI[posizione_utente].password) - 1)) )
		{
			printf("%c", UTENTI[posizione_utente].password[i]);
			if(i==(strlen(UTENTI[posizione_utente].password) - 1))
			{
				i=LUNGHEZZA_PASS;
			}
		}
		else
		{
			printf("*");
		}
	}
	SetColor(3);
	printf("\nNOME:");
	SetColor(15);
	printf("%-31s\t", UTENTI[posizione_utente].nome);
	SetColor(3);
	printf("COGNOME:");
	SetColor(15);
	printf("%s\n", UTENTI[posizione_utente].cognome);
	SetColor(3);
	printf("DATA DI NASCITA:");
	SetColor(15);
	printf("%d/%d/%d\t\t", UTENTI[posizione_utente].data_nascita.giorno, UTENTI[posizione_utente].data_nascita.mese, UTENTI[posizione_utente].data_nascita.anno);
	SetColor(3);
	printf("DATA DI ISCRIZIONE:");
	SetColor(15);
	printf("%d/%d/%d", UTENTI[posizione_utente].data_iscrizione.giorno, UTENTI[posizione_utente].data_iscrizione.mese, UTENTI[posizione_utente].data_iscrizione.anno);
	SetColor(55);
	printf("\n\nASCOLTATI DI RECENTE\n\n");
	SetColor(15);

	for (i = 0; i < ARTISTI_MAX; i++)
	{
		if (UTENTI[posizione_utente].preferenze[i] != 0)
		{
			SetColor(3);
			for (j = 0; j < ARTISTI_MAX; j++)
			{
				if (strcmp(UTENTI[posizione_utente].codice_artista[i], ARTISTI[j].codice)
				        == 0)
				{
					printf("%s:", ARTISTI[j].nome);

					SetColor(15);
					if (UTENTI[posizione_utente].preferenze[i] == 1)
					{
						printf("Ascoltato\n");
					}

					if (UTENTI[posizione_utente].preferenze[i] == 2)
					{
						printf("Ascoltato e Mi piace\n");
					}

					if (UTENTI[posizione_utente].preferenze[i] == 3)
					{
						printf("Ascoltato e Non mi piace\n");
					}
				}
			}
		}
	}
	printf("\n");
}


/**
 * Questa funzione permette di autenticare l'accesso dell'utente.\n
 * Per fare ciò, controlla prima se l'utente inserito in input è presente. Se l'utente è presente, egli potrà continuare con l'inserimento della password che avverrà\n
 * facendo apparire a schermo un "*" per ogni tasto premuto. Eventualmente l'utente avrà la possibilità anche di cancellare la password per un eventuale errore di battitura.
 *
 * @post Il ritorno sarà un intero
 *
 */
int isAutenticazione(int utenti_effettivi, int* posizione_utente) {
	int i, j;
	int utente_trovato = 0;			//0 Utente trovato - 1 Utente non trovato
	int autenticazione = 0;	//0 autenticazione non riuscita - 1 autenticazione effettuata
	char utente[LUNGHEZZA_MAX];	//Variabile contenente il nome utente chiesto in input
	char password[LUNGHEZZA_PASS] = { '\0' };//Variabile contenente la password chiesta in input
	char carattere_bf;//Variabile contenenete un solo carattere per la creazione della password
	do
	{
		system("cls");
		logo();
		SetColor(15);
		printf("Inserisci nickname:");
		SetColor(6);
		fgets(utente, LUNGHEZZA_MAX, stdin);
		strcpy(utente, eliminazione_acapo(utente));
		fflush(stdin);

	}while (strlen(utente) < 1);

	for (i = 0; i < utenti_effettivi; i++)
	{
		if (strcmp(utente, UTENTI[i].nickname) == 0)//Controlla se l'utente inserito in input è presente
		{
			utente_trovato = 1;
			SetColor(15);
			j = 0;
			printf("Inserisci password di 8 caratteri: ");
			SetColor(6);

			do
			{//Controllo fin quando la password non raggiungerà gli 8 caratteri
				fflush(stdin);
				carattere_bf = '\0';

				if ((carattere_bf = getch()) != '\r')//Se premo "tasto invio" non devo fare nulla
				{
					if (carattere_bf == '\b')//Se premo "cancella" elimino un elemento delle stringa e tolgo un * da schermo
					{
						if (j != 0)
						{
							printf("\b \b");
							j--;
							password[j] = '\0';
						}

					}else//Se invece è un carattere allora lo inserisco nella variabile e incremento la i
					{
						password[j] = carattere_bf;
						printf("*");
						j++;
					}
				}
			}while (strlen(password) != LUNGHEZZA_PASS - 1);

			fflush(stdin);

			strcpy(password, eliminazione_acapo(password));

			if (strcmp(password, UTENTI[i].password) == 0)//Controlla se la password inserita in input è corretta
			{
				*posizione_utente = i;
				SetColor(15);
				printf("\n\nAutenticazione effettuata con successo, \n\n");
				system("pause");
				autenticazione = 1;
			}else
			{
				SetColor(4);
				printf("\nPassword errata\a\n");
				SetColor(15);
				system("pause");
			}
		}
	}

	if (utente_trovato == 0)//Stampa messaggio di errore quando l'utente non è stato trovato
	{
		SetColor(4);
		printf("\nNickname errato\a\n");
		SetColor(15);
		system("pause");
	}

	return (autenticazione);
}

/**
 * L'utente potrà scegliere fra 6 possibili scelte:
 * 	1. Modificare il nickname
 * 	2. Modificare la password
 * 	3. Modificare il nome
 * 	4. Modificare il cognome
 * 	5. Modificare la data di nascita
 * 	6. Tornare indietro
 *
 * Tutte le opzioni effettueranno dei controlli sui dati in input
 * 	-# Non può essere inseriti lo stesso nickname o il nickname di un altro utente
 * 	-# Doppio controllo sull'inserimento password
 */

void modifica_utente(int utenti_effettivi, int posizione_utente) {

	int i;
	char scelta[LUNGHEZZA_MAX] = { "\0" };			//Variabile d'appoggio per l'input della scelta per il men? chiesto in input
	char utente[LUNGHEZZA_MAX];							//Variabile d'appoggio per nickname, nome e cognome chiesti in input
	char controllo[LUNGHEZZA_PASS] = { '\0' };			//Variabile utilizzata per effettuare un doppio controllo sulla password per verificare che corrisponda alla prima chiesta in input
	char carattere_bf;									//Variabile contenenete un solo carattere per la creazione della password
	int uguali;											//Variaibile utilizzata come flag    0=Controllo non superato | 1=Controllo superato
	char data_provvisoria[LUNGHEZZA_MAX] = { '\0' };	//Variabile contenente la data di tipo char per effettuare i controlli

	do
	{//Controllo sull input fornito dall'utente fin quando non viene inserito un valore compreso tra 0 e 5 compresi
		system("cls");
		logo();
		SetColor(2);
		printf("[1]");
		SetColor(15);
		printf("Nickname\n");
		SetColor(2);
		printf("[2]");
		SetColor(15);
		printf("Password\n");
		SetColor(2);
		printf("[3]");
		SetColor(15);
		printf("Nome\n");
		SetColor(2);
		printf("[4]");
		SetColor(15);
		printf("Cognome\n");
		SetColor(2);
		printf("[5]");
		SetColor(15);
		printf("Data di nascita\n");
		SetColor(2);
		printf("[0]");
		SetColor(15);
		printf("Torna indietro\n\nInserisci comando: ");
		fgets(scelta, LUNGHEZZA_MAX, stdin);
		strcpy(scelta, eliminazione_acapo(scelta));
		fflush(stdin);

		if ((strcmp(scelta, "0") < 0) || (strcmp(scelta, "6") > 0))
		{
			system("cls");
			logo();
			SetColor(4);
			printf("Inserire un campo valido!\a\n\n");
			SetColor(15);
			system("pause");
		}
	}while ((strcmp(scelta, "0") < 0) || (strcmp(scelta, "6") > 0));

	switch (atoi(scelta)) {
	//TORNA AL MENU PRINCIPALE
	case 0:
		break;

		//MODIFICA NICKNAME
	case 1:
		do
		{//Controllo fin quando non viene inserito almeno una lettera e il nickname non deve essere già  presente
			system("cls");
			logo();
			printf("Inserisci nuovo Nickname: ");
			SetColor(6);
			fgets(utente, LUNGHEZZA_MAX, stdin);
			strcpy(utente, eliminazione_acapo(utente));
			fflush(stdin);
			SetColor(15);
			if ((isControllo_Esistenza(utenti_effettivi, utente, "nickname_utente")
			        == 1))
			{
				SetColor(4);
				printf("\nNickname gi%c utilizzato\n\a", 133);
				SetColor(15);
				system("pause");
			}
		}while ((strlen(utente) < 1)
		        || (isControllo_Esistenza(utenti_effettivi, utente, "nickname_utente")
		                != 0));

		printf("Nickname cambiato correttamente\n");
		strcpy(UTENTI[posizione_utente].nickname, utente);
		break;

		//MODIFICA PASSWORD
	case 2:
		system("cls");
		logo();
		stringclear(UTENTI[posizione_utente].password, LUNGHEZZA_PASS)
		;
		stringclear(controllo, LUNGHEZZA_PASS)
		;

		//PRIMO INSERIMENTO
		do
		{//Controllo fin quando la password e la conferma password non corrispondono
			i = 0;
			printf("Inserisci nuova password di 8 caratteri: ");
			SetColor(6);
			do
			{//Controllo fin quando la password non raggiungerà  gli 8 caratteri
				fflush(stdin);
				carattere_bf = '\0';

				if ((carattere_bf = getch()) != '\r')//Se premo "tasto invio" non devo fare nulla
				{
					if (carattere_bf == '\b')//Se premo "cancella" elimino un elemento delle stringa e tolgo un * da schermo
					{
						if (i != 0)
						{
							printf("\b \b");
							i--;
							controllo[i] = '\0';
						}

					}else//Se invece è un carattere allora lo inserisco nella variabile e incremento la i
					{
						controllo[i] = carattere_bf;
						printf("*");
						i++;
					}
				}
			}while (strlen(controllo) != LUNGHEZZA_PASS - 1);

			SetColor(15);
			printf("\nConferma password: ");
			SetColor(6);

			//SECONDO INSERIMENTO
			i = 0;
			do
			{//Controllo fin quando la password e la conferma password non corrispondono
				fflush(stdin);
				carattere_bf = '\0';
				if ((carattere_bf = getch()) != '\r')//Se premo "tasto invio" non devo fare nulla
				{
					if (carattere_bf == '\b')//Se premo "cancella" elimino un elemento delle stringa e tolgo un * da schermo
					{
						if (i != 0)
						{
							printf("\b \b");
							i--;
							UTENTI[posizione_utente].password[i] = '\0';
						}

					}else//Se invece Ã¨ un carattere allora lo inserisco nella variabile e incremento la i
					{
						fflush(stdin);
						UTENTI[posizione_utente].password[i] = carattere_bf;
						printf("*");
						i++;
					}
				}

			}while (strlen(UTENTI[posizione_utente].password)
			        != LUNGHEZZA_PASS - 1);

			if (strcmp(controllo, UTENTI[posizione_utente].password) == 0)//Controllo se le due password sono uguali
			{
				uguali = 1;
			}else
			{
				SetColor(4);
				printf("\nLe password non corrispondono\n\a");
				SetColor(15);
				system("pause");
				system("cls");
				logo();
				uguali = 0;
				//AZZERO I VETTORI DI CHAR PER PREPARARGLI AD UN NUOVO INSERIMENTO
				stringclear(controllo, LUNGHEZZA_PASS);
				stringclear(UTENTI[posizione_utente].password, LUNGHEZZA_PASS);
			}
		}while (uguali == 0);

		SetColor(15);
		printf("\nPassword cambiata correttamente\n");
		break;

		//MODIFICA NOME
	case 3:
		stringclear(UTENTI[posizione_utente].nome, LUNGHEZZA_MAX)
		;
		do
		{		//Controllo fin quando non viene inserito almeno una lettera
			system("cls");
			logo();
			printf("Inserisci nuovo nome: ");
			SetColor(6);
			fgets(UTENTI[posizione_utente].nome, LUNGHEZZA_MAX, stdin);
			strcpy(UTENTI[posizione_utente].nome, eliminazione_acapo(UTENTI[posizione_utente].nome));
			fflush(stdin);
			SetColor(15);
		}while ((strlen(UTENTI[posizione_utente].nome) < 1));
		break;

		//MODIFICA COGNOME
	case 4:
		stringclear(UTENTI[posizione_utente].cognome, LUNGHEZZA_MAX)
		;
		do
		{			//Controllo fin quando non viene inserito almeno una lettera
			system("cls");
			logo();
			printf("Inserisci cognome nuovo utente: ");
			SetColor(6);
			fgets(UTENTI[posizione_utente].cognome, LUNGHEZZA_MAX, stdin);
			strcpy(UTENTI[posizione_utente].cognome, eliminazione_acapo(UTENTI[posizione_utente].cognome));
			fflush(stdin);
			SetColor(15);
		}while ((strlen(UTENTI[posizione_utente].cognome) < 1));
		break;

		//MODIFICA DATA DI NASCITA
	case 5:
		system("cls");
		logo();
		printf("Inserisci nuova data di nascita\n");

		do
		{//Controllo fin quando l'anno non Ã¨ compreso tra 1900 e 2001(anno per avere l'etÃ  minima di 16 anni)
			do
			{		//Controllo fin quando l'input inserito non Ã¨ un numero
				printf("\nAnno: ");
				SetColor(6);
				fgets(data_provvisoria,LUNGHEZZA_MAX,stdin);
				strcpy(data_provvisoria, eliminazione_acapo(data_provvisoria));
				fflush(stdin);
				SetColor(15);
				if (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX) != 1)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un anno non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci nuova data di nascita:\n");
				}
			}while (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX) != 1);

			UTENTI[posizione_utente].data_nascita.anno = atoi(data_provvisoria);

			if (UTENTI[posizione_utente].data_nascita.anno < 1900
			        || UTENTI[posizione_utente].data_nascita.anno
			                > (DATA_CORRENTE.anno - ETA_MINIMA - 1))
			{
				system("cls");
				logo();
				SetColor(4);
				printf("Hai inserito un anno non corretto! Riprova\n\n\a");
				SetColor(15);
				system("pause");
				system("cls");
				logo();
				printf("Inserisci nuova data di nascita:\n");
			}
		}while (UTENTI[posizione_utente].data_nascita.anno < 1900
		        || UTENTI[posizione_utente].data_nascita.anno
		                > (DATA_CORRENTE.anno - ETA_MINIMA - 1));

		//INSERIMENTO MESE DI NASCITA
		do
		{		//Controllo fin quando il mese non Ã¨ compreso tra 1 e 12
			do
			{		//Controllo fin quando l'input inserito non Ã¨ un numero
				printf("\nMese: ");
				SetColor(6);
				stringclear(data_provvisoria, LUNGHEZZA_MAX);
				fgets(data_provvisoria,LUNGHEZZA_MAX,stdin);
				strcpy(data_provvisoria, eliminazione_acapo(data_provvisoria));
				fflush(stdin);
				SetColor(15);
				if (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX) != 1)
				{
					system("cls");
					logo();
					SetColor(4);
					printf("Hai inserito un mese non corretto! Riprova\n\n\a");
					SetColor(15);
					system("pause");
					system("cls");
					logo();
					printf("Inserisci nuova data di nascita:\n");
				}
			}while (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX) != 1);

			UTENTI[posizione_utente].data_nascita.mese = atoi(data_provvisoria);

			if (UTENTI[posizione_utente].data_nascita.mese < PRIMO_MESE
			        || UTENTI[posizione_utente].data_nascita.mese > ULTIMO_MESE)
			{
				system("cls");
				logo();
				SetColor(4);
				printf("Hai inserito un mese non corretto! Riprova\n\n\a");
				SetColor(15);
				system("pause");
				system("cls");
				logo();
				printf("Inserisci nuova data di nascita:\n");
			}
		}while (UTENTI[posizione_utente].data_nascita.mese < PRIMO_MESE
		        || UTENTI[posizione_utente].data_nascita.mese > ULTIMO_MESE);

		//INSERIMENTO GIORNO DI NASCITA

		//CONTROLLO SUL GIORNO NELL'ANNO BISESTILE NEL MESE DI FEBBRAIO
		if (UTENTI[posizione_utente].data_nascita.mese == 2)
		{
			if (UTENTI[posizione_utente].data_nascita.anno % 4 == 0)//Caso in cui l'anno Ã¨ bisestile
			{
				do
				{	//Controllo fin quando il giorno non Ã¨ compreso tra 1 e 29
					do
					{	//Controllo fin quando l'input inserito non Ã¨ un numero
						printf("\nGiorno: ");
						SetColor(6);
						stringclear(data_provvisoria, LUNGHEZZA_MAX);
						fgets(data_provvisoria,LUNGHEZZA_MAX,stdin);
						strcpy(data_provvisoria, eliminazione_acapo(data_provvisoria));
						fflush(stdin);
						SetColor(15);

						if (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX)
						        != 1)
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
					}while (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX)
					        != 1);

					UTENTI[posizione_utente].data_nascita.giorno =
					        atoi(data_provvisoria);

					if (UTENTI[posizione_utente].data_nascita.giorno < 1
					        || UTENTI[posizione_utente].data_nascita.giorno
					                > 29)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci nuova data di nascita:\n");
					}
				}while (UTENTI[posizione_utente].data_nascita.giorno < 1
				        || UTENTI[posizione_utente].data_nascita.giorno > 29);
			}else
			{
				//CONTROLLO SUL GIORNO DEL'ANNO NON BISESTILE NEL MESE DI FEBBRAIO
				do
				{	//Controllo fin quando il giorno non Ã¨ compreso tra 1 e 28
					do
					{	//Controllo fin quando l'input inserito non Ã¨ un numero
						printf("\nGiorno: ");
						SetColor(6);
						stringclear(data_provvisoria, LUNGHEZZA_MAX);
						fgets(data_provvisoria,LUNGHEZZA_MAX,stdin);
						strcpy(data_provvisoria, eliminazione_acapo(data_provvisoria));
						fflush(stdin);
						SetColor(15);
						if (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX)
						        != 1)
						{
							system("cls");
							logo();
							SetColor(4);
							printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
							SetColor(15);
							system("pause");
							system("cls");
							logo();
							printf("Inserisci nuova data di nascita:\n");
						}
					}while (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX)
					        != 1);

					UTENTI[posizione_utente].data_nascita.giorno =
					        atoi(data_provvisoria);

					if (UTENTI[posizione_utente].data_nascita.giorno < 1
					        || UTENTI[posizione_utente].data_nascita.giorno
					                > 28)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci nuova data di nascita:\n");
					}
				}while (UTENTI[posizione_utente].data_nascita.giorno < 1
				        || UTENTI[posizione_utente].data_nascita.giorno > 28);
			}
		}else
		{
			//CONTROLLO MESI DA 30 GIORNI
			if (UTENTI[posizione_utente].data_nascita.mese == 4
			        || UTENTI[posizione_utente].data_nascita.mese == 6
			        || UTENTI[posizione_utente].data_nascita.mese == 9
			        || UTENTI[posizione_utente].data_nascita.mese == 11)
			{
				do
				{	//Controllo fin quando il giorno non Ã¨ compreso tra 1 e 30
					do
					{	//Controllo fin quando l'input inserito non Ã¨ un numero
						printf("\nGiorno: ");
						SetColor(6);
						stringclear(data_provvisoria, LUNGHEZZA_MAX);
						fgets(data_provvisoria,LUNGHEZZA_MAX,stdin);
						strcpy(data_provvisoria, eliminazione_acapo(data_provvisoria));
						fflush(stdin);
						SetColor(15);
						if (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX)
						        != 1)
						{
							system("cls");
							logo();
							SetColor(4);
							printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
							SetColor(15);
							system("pause");
							system("cls");
							logo();
							printf("Inserisci nuova data di nascita:\n");
						}
					}while (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX)
					        != 1);

					UTENTI[posizione_utente].data_nascita.giorno =
					        atoi(data_provvisoria);

					if (UTENTI[posizione_utente].data_nascita.giorno <= 0
					        || UTENTI[posizione_utente].data_nascita.giorno
					                > 30)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci nuova data di nascita:\n");
					}
				}while (UTENTI[posizione_utente].data_nascita.giorno <= 0
				        || UTENTI[posizione_utente].data_nascita.giorno > 30);
			}else
			{
				//CONTROLLO MESI DA 31 GIORNI
				do
				{	//Controllo fin quando il giorno non è compreso tra 1 e 31
					do
					{	//Controllo fin quando l'input inserito non Ã¨ un numero
						printf("\nGiorno: ");
						SetColor(6);
						stringclear(data_provvisoria, LUNGHEZZA_MAX);
						fgets(data_provvisoria,LUNGHEZZA_MAX,stdin);
						strcpy(data_provvisoria, eliminazione_acapo(data_provvisoria));
						fflush(stdin);
						SetColor(15);
						if (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX)
						        != 1)
						{
							system("cls");
							logo();
							SetColor(4);
							printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
							SetColor(15);
							system("pause");
							system("cls");
							logo();
							printf("Inserisci nuova data di nascita:\n");
						}
					}while (isControllo_Numero(data_provvisoria, LUNGHEZZA_MAX)
					        != 1);

					UTENTI[posizione_utente].data_nascita.giorno =
					        atoi(data_provvisoria);

					if (UTENTI[posizione_utente].data_nascita.giorno <= 0
					        || UTENTI[posizione_utente].data_nascita.giorno
					                > 31)
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Hai inserito un giorno non corretto! Riprova\n\n\a");
						SetColor(15);
						system("pause");
						system("cls");
						logo();
						printf("Inserisci nuova data di nascita:\n");
					}
				}while (UTENTI[posizione_utente].data_nascita.giorno <= 0
				        || UTENTI[posizione_utente].data_nascita.giorno > 31);
			}
		}

		system("cls");
		logo();
		printf("Data di nascita inserita correttamente!\n\n");
		fflush(stdin);
		break;
	}
}

int conferma_eliminazione()
{
	char risposta[LUNGHEZZA_MAX] = { "si" };//Risposta alla domanda 'Sei sicuro di voler eliminare l'artista?'
	do
	{
		system("cls");
		logo();
		SetColor(30);
		printf("Sei sicuro di volerti eliminare da Spotify? :(");
		SetColor(15);
		printf("\nRispondere con si o no: ");
		fgets(risposta, LUNGHEZZA_MAX, stdin);
		strcpy(risposta, eliminazione_acapo(risposta));
		fflush(stdin);		//Svuota flusso in input
	}while (strcmp(risposta, "si") != 0 && strcmp(risposta, "no") != 0);

	if((strcmp(risposta, "si")==0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


/**
 * La funzione chiede la conferma di eliminazione all'utente prima di procedere.\n
 * Essa procede agendo sull'array di struct ::UTENTE, ::UTENTI scalando le informazioni degli utenti di una posizione in modo da eliminare le informazioni dell'utente desiderato.
 */
int elimina_utente(int utenti_effettivi, int posizione_utente) {
	int i, j;

	for (i = posizione_utente + 1; i < utenti_effettivi; i++)//Spostamento degli artisti nella posizione precendete fino all'indice del artista da eliminare
	{
		//COPIA DEL UTENTE IN POSIZIONE SUPERIORE IN QUELLO IN POSIZIONE INFERIORE
		strcpy(UTENTI[i - 1].nickname, UTENTI[i].nickname);
		strcpy(UTENTI[i - 1].password, UTENTI[i].password);
		strcpy(UTENTI[i - 1].nome, UTENTI[i].nome);
		strcpy(UTENTI[i - 1].cognome, UTENTI[i].cognome);
		UTENTI[i - 1].data_nascita.anno = UTENTI[i].data_nascita.anno;
		UTENTI[i - 1].data_nascita.mese = UTENTI[i].data_nascita.mese;
		UTENTI[i - 1].data_nascita.giorno = UTENTI[i].data_nascita.giorno;
		UTENTI[i - 1].data_iscrizione.anno = UTENTI[i].data_iscrizione.anno;
		UTENTI[i - 1].data_iscrizione.mese = UTENTI[i].data_iscrizione.mese;
		UTENTI[i - 1].data_iscrizione.giorno = UTENTI[i].data_iscrizione.giorno;
		for (j = 0; j < ARTISTI_MAX; j++)
		{
			strcpy(UTENTI[i - 1].codice_artista[j], UTENTI[i].codice_artista[j]);
			UTENTI[i - 1].preferenze[j] = UTENTI[i].preferenze[j];
		}

	}

	//PULITURA ULTIMO POSZIONE UTENTE
	stringclear(UTENTI[utenti_effettivi - 1].nickname, LUNGHEZZA_MAX);
	stringclear(UTENTI[utenti_effettivi - 1].password, LUNGHEZZA_PASS);
	stringclear(UTENTI[utenti_effettivi - 1].nome, LUNGHEZZA_MAX);
	stringclear(UTENTI[utenti_effettivi - 1].cognome, LUNGHEZZA_MAX);
	UTENTI[utenti_effettivi - 1].data_nascita.anno = 0;
	UTENTI[utenti_effettivi - 1].data_nascita.mese = 0;
	UTENTI[utenti_effettivi - 1].data_nascita.giorno = 0;
	UTENTI[utenti_effettivi - 1].data_iscrizione.anno = 0;
	UTENTI[utenti_effettivi - 1].data_iscrizione.mese = 0;
	UTENTI[utenti_effettivi - 1].data_iscrizione.giorno = 0;
	for (j = 0; j < ARTISTI_MAX; j++)
	{
		strcpy(UTENTI[utenti_effettivi - 1].codice_artista[j], "0000");
		UTENTI[utenti_effettivi - 1].preferenze[j] = 0;
	}

	utenti_effettivi--;		//Eliminazione di un utente

	return utenti_effettivi;

}

/**
 * L'utente potrà scegliere se:
 *  1. Scegliere l'artista sfogliando tutti i generi (referenziando ::categoria_artisti)
 *  2. Scegliere direttamente l'artista, dopo aver consultato la lista degli artisti (referenziando ::totale_artisti)
 *  3. Scegliere l'artista per nazionalità (referenziando ::campo_artisti)
 *  4. Scegliere l'artista anno (referenziando ::campo_artisti)
 *  5. Visualizzare la TOP 10 degli artisti con più "Mi piace" (referenziando ::top)
 *  6. Visualizzare la TOP 10 degli artisti con più "Ascolti" (referenziando ::top)
 *
 * Questa funzione referenzia le sopra elencate funzioni.
 */
void menu_preferenze(int posizione_utente, int artisti_effettivi) {
	int pos_artista;	//Contiene la posizione nel vettore dell'artista trovato
	char metodo[LUNGHEZZA_MAX] = { '\0' };

	do
	{		//Controllo fin quando non viene inserito il giusto comando
		system("cls");
		logo();
		printf("Scegli gli artisti che ti piacciono!\nPuoi scegliere se visualizzarli per:\n");
		SetColor(2);
		printf("[1]");
		SetColor(15);
		printf("Genere\n");
		SetColor(2);
		printf("[2]");
		SetColor(15);
		printf("Tutti gli artisti\n");
		SetColor(2);
		printf("[3]");
		SetColor(15);
		printf("Nazionalit%c\n",133);
		SetColor(2);
		printf("[4]");
		SetColor(15);
		printf("Anno\n");
		SetColor(2);
		printf("[5]");
		SetColor(15);
		printf("Top 10 %cMi piace%c\n", 34, 34);
		SetColor(2);
		printf("[6]");
		SetColor(15);
		printf("Top 10 %cAscolti%c\n\nInserisci comando:", 34, 34);
		fgets(metodo, LUNGHEZZA_MAX, stdin);
		strcpy(metodo, eliminazione_acapo(metodo));
		fflush(stdin);

	}while (isControllo_Numero(metodo,LUNGHEZZA_MAX)!=1);

	switch (atoi(metodo)) {
	//Categoria preferita
	case 1:
		pos_artista = categoria_artisti(artisti_effettivi);
		if (pos_artista != -1)
		{
			modifica_preferenze(posizione_utente, pos_artista);
		}

		break;

	//Tutti gli artisti
	case 2:
		pos_artista = totale_artisti(artisti_effettivi);
		if (pos_artista != -1)
		{
			modifica_preferenze(posizione_utente, pos_artista);
		}

		break;

	//Nazionalità
	case 3:
		pos_artista = campo_artisti(artisti_effettivi, atoi(metodo));
		if (pos_artista != -1)
		{
			modifica_preferenze(posizione_utente, pos_artista);
		}

		break;

	//Anno
	case 4:
		pos_artista = campo_artisti(artisti_effettivi, atoi(metodo));
		if (pos_artista != -1)
		{
			modifica_preferenze(posizione_utente, pos_artista);
		}

		break;


	//top 10 mi piace
	case 5:
		pos_artista = top(artisti_effettivi, "mi piace");
		if (pos_artista != -1)
		{
			modifica_preferenze(posizione_utente, pos_artista);
		}

		break;


	//Top 10 ascolti
	case 6:
		pos_artista = top(artisti_effettivi, "ascolti");
		if (pos_artista != -1)
		{
			modifica_preferenze(posizione_utente, pos_artista);
		}
		break;

	default:
		system("cls");
		logo();
		SetColor(4);
		printf("Comando errato, inserisci un valore corretto\a\n");
		SetColor(15);
		system("PAUSE");

	}
}

int campo_artisti(int artisti_effettivi,int campo){

	char input[LUNGHEZZA_MAX];	//Contiene l'input inserito dall'utente
	int trovato=0;			//0 elemento non trovato - 1 elemento trovato
	int pos_artista = -1;//Contiene la posizione nel vettore dell'artista trovato
	int vett[artisti_effettivi];	//vettore d'appoggio contenente gli anni di inizio attività degli artisti
	int i,k,j;



	if(campo==4)		//Anno
	{
		do{		//controllo fin quando non viene inserito un anno presente
			for(i=0;i<artisti_effettivi;i++)		//Inizializzazione vettore con 0
			{
				vett[i]=0;
			}
			system("cls");
			logo();
			printf("Lista anni:\n");
			SetColor(6);
			j=0;
			for(i=0;i<artisti_effettivi;i++)		//Stampa anni presenti
			{
				trovato=0;
				for(k=0;k<i;k++)	//Evita stampe di anni già presenti
				{
					if(ARTISTI[i].anno_inizio==ARTISTI[k].anno_inizio)
					{
						trovato=1;

					}
				}
				if(trovato==0)
				{
					vett[j]=ARTISTI[i].anno_inizio;	//Inserimento degli anni in un vettore
					j++;

				}

			}

			if(ordinamento_crescente(vett,artisti_effettivi)==1)	//controllo sull'ordinamento del vettore
			{
				for (i = 0; i < artisti_effettivi; i++)	//stampa anni ordinati
				{
					if (vett[i] != 0)
					{
						printf("%d\t", vett[i]);
					}

				}

				SetColor(15);
				printf("\nInserisci l'anno da controllare:");
				fgets(input, LUNGHEZZA_MAX, stdin);
				strcpy(input, eliminazione_acapo(input));
				fflush(stdin);

				trovato = 0;
				for (i = 0; i < artisti_effettivi; i++)	//Controllo se l'anno inserito è presente
				{
					if (atoi(input) == ARTISTI[i].anno_inizio)
					{
						trovato = 1;
						i = artisti_effettivi;
					}
				}
			}



		}while(trovato==0);


		for(i=0;i<artisti_effettivi;i++)		//Stampa artisti con l'anno inserito in input
		{
			if(atoi(input)==ARTISTI[i].anno_inizio)
			{
				SetColor(15);
				printf("%s\t\t", ARTISTI[i].codice);
				SetColor(3);
				printf("%s\n", ARTISTI[i].nome);
				SetColor(15);
			}
		}
	}

	if(campo==3)		//Nazionalità
	{
		do{		//controllo fin quando non viene inserita una nazionalità presente
			j=1;
			system("cls");
			logo();
			printf("Lista nazionalit%c:\n",133);
			SetColor(6);
			for(i=0;i<artisti_effettivi;i++)		//Stampa nazionalita presenti
			{
				trovato=0;
				for(k=0;k<i;k++)	//Evita stampe di nazionalita già presenti
				{
					if(strcmp(ARTISTI[i].nazionalita,ARTISTI[k].nazionalita)==0)
					{
						trovato=1;

					}
				}

				if(trovato==0)			//Stampa nazionalita
				{
					printf("%-31s",ARTISTI[i].nazionalita);

					if ((j % 2) == 0)
					{
						printf("\n");
					}
					j++;
				}

			}
			SetColor(15);
			printf("\nInserisci la nazionalit%c da controllare:",133);
			fgets(input, LUNGHEZZA_MAX, stdin);
			strcpy(input, eliminazione_acapo(input));
			fflush(stdin);

			trovato=0;
			for(i=0;i<artisti_effettivi;i++)	//Controllo se la nazionalità inserita è presente
			{
				if(strcmp(input,ARTISTI[i].nazionalita)==0)
				{
					trovato=1;
					i=artisti_effettivi;
				}
			}
		}while(trovato==0);

		for(i=0;i<artisti_effettivi;i++)		//Stampa lista artisti della nazionalita indicata
		{
			if(strcmp(input,ARTISTI[i].nazionalita)==0)
			{

				SetColor(15);
				printf("%s\t\t", ARTISTI[i].codice);
				SetColor(3);
				printf("%s\n", ARTISTI[i].nome);
				SetColor(15);
			}
		}
	}

	printf("Inserisci il codice dell'artista:");
	fgets(input, LUNGHEZZA_MAX, stdin);
	strcpy(input, eliminazione_acapo(input));
	fflush(stdin);


	for(i=0;i<artisti_effettivi;i++)		//Individuazione dell'utente
	{
		if(strcmp(input,ARTISTI[i].codice)==0)
		{
			pos_artista=i;
			i=ARTISTI_MAX;
		}
	}

	if(pos_artista==-1)		//Stampa messaggio artista non trovato
	{
		system("cls");
		logo();
		SetColor(4);
		printf("\nArtista non trovato\a\n");
		SetColor(15);
	}


	return (pos_artista);
}

/**
 * Quando l'utente inserisce il genere, viene effettuato un controllo per verificare che il genere effettivamente esista.\n
 * Se il genere sarà trovato, saranno visualizzati tutti i nomi degli artisti o gruppi. Se non esistono artisti o gruppi di quel genere, sarà notificato.
 * \pre Deve esistere la funzione ::menu_preferenze
 * \warning La funzione controlla l'esistenza del genere carattere per carattere, quindi vanno inserite anche le lettere maiuscole
 */
int categoria_artisti(int artisti_effettivi) {
	char lista_generi[GENERI_TOT][LUNGHEZZA_MAX] = { "N.A.", "Electro", "Pop",
	        "Techno", "Rock", "Jazz", "Rap", "Blues", "Country", "Britpop",
	        "Dubstep", "EDM", "Hip-Hop", "House", "Musica leggera", "Trap",
	        "Trance", "Disco", "Dance" };
	char genere_provvisorio[LUNGHEZZA_MAX];	//Contiene l'input inserito dall'utente
	int posizione_genere = 0;	//pozione del genere nel vettore lista_generi
	int genere_esistente = 0;	//0 genere non esistente | 1 genere esistente
	char artista[LUNGHEZZA_MAX] = { "\0" };	//Variabile d'appoggio per l'artista chiesto in input
	int artista_trovato = 0;		//0 artista non trovato | 1 artista trovato
	int pos_artista = -1;//Contiene la posizione nel vettore dell'artista trovato
	int i;

	do
	{			//Controlla fin quando il genere inserito esiste
		system("cls");
		logo();
		printf("Lista generi:\n");

		SetColor(6);
		for (i = 1; i <= GENERI_TOT; i++) //Stampa generi su schermo
		{
			printf("%-31s", lista_generi[i - 1]);

			if ((i % 2) == 0)
			{
				printf("\n");
			}

		}
		SetColor(15);

		printf("\nInserisci il tuo genere preferito:");
		fgets(genere_provvisorio, LUNGHEZZA_MAX, stdin);
		strcpy(genere_provvisorio, eliminazione_acapo(genere_provvisorio));
		fflush(stdin);

		for (i = 0; i < GENERI_TOT; i++) //Controlla se il genere è presente nella lista_generi
		{
			if (strcmp(genere_provvisorio, lista_generi[i]) == 0)
			{
				genere_esistente = 1;
				posizione_genere = i;
				i = GENERI_TOT;
			}
		}

		if (genere_esistente == 0)
		{
			system("cls");
			logo();
			SetColor(4);
			printf("Genere non esistente\n");
			SetColor(15);
			system("PAUSE");
		}
	}while (genere_esistente != 1);

	genere_esistente = 0;

	system("cls");
	logo();
	printf("\nI/Il cantante che corrisponde al tuo genere preferito %c:\n", 138);
	SetColor(3);
	printf("CODICE\t\tNOME\n");
	SetColor(15);

	for (i = 0; i < artisti_effettivi; i++)	//Stampa artisti appartenenti al genere inserito
	{
		if (ARTISTI[i].genere[posizione_genere] == 1)//Controlla se il genere appartiene a un determinato artista
		{
			printf("%s\t\t%s\n", ARTISTI[i].codice, ARTISTI[i].nome);
			genere_esistente = 1;
		}
	}

	if (genere_esistente == 0)
	{
		system("cls");
		logo();
		SetColor(4);
		printf("Nessun artista con questo genere trovato!\a\n");
		SetColor(15);
	}else
	{
		printf("\nInserisci il codice dell'artista:");
		fgets(artista, LUNGHEZZA_MAX, stdin);
		strcpy(artista, eliminazione_acapo(artista));
		fflush(stdin);

		for (i = 0; i < artisti_effettivi; i++)
		{
			if (strcmp(artista, ARTISTI[i].codice) == 0)//Controllo per individuare l'artista inserito in input
			{
				printf("Artista trovato!\n");
				artista_trovato = 1;
				pos_artista = i;  //VALORE DI RITORNO
				i = artisti_effettivi;
			}
		}

		if (artista_trovato == 0)
		{
			system("cls");
			logo();
			SetColor(4);
			printf("\nArtista non trovato\a\n");
			SetColor(15);
		}
	}

	return (pos_artista);

}

/**
 * L'utente inserirà il codice dell'artista e se il codice e disponibile l'artista sarà selezionato.
 * \pre Deve esistere la funzione ::menu_preferenze
 */
int totale_artisti(int artisti_effettivi) {
	char artista[LUNGHEZZA_MAX] = { "\0" };	//Variabile d'appoggio per l'artista chiesto in input
	int artista_trovato = 0;		//0 artista non trovato | 1 artista trovato
	int pos_artista = -1;//Contiene la posizione nel vettore dell'artista trovato
	int i;
	do
	{//Controllo fin quando non viene digitato il codice dell'artista correttamente
		system("cls");
		logo();
		SetColor(3);
		printf("CODICE\t\tNOME\n");
		SetColor(15);

		for (i = 0; i < artisti_effettivi; i++)		//Stampa artisti
		{
			printf("%s\t\t%s\n", ARTISTI[i].codice, ARTISTI[i].nome);
		}
		printf("Inserisci il codice dell'artista:");
		fgets(artista, LUNGHEZZA_MAX, stdin);
		strcpy(artista, eliminazione_acapo(artista));
		fflush(stdin);

		for (i = 0; i < artisti_effettivi; i++)
		{
			if (strcmp(artista, ARTISTI[i].codice) == 0)//Controllo per individuare l'artista inserito in input
			{
				printf("Artista trovato!\n");
				artista_trovato = 1;
				pos_artista = i;
			}
		}

		if (artista_trovato == 0)
		{
			system("cls");
			logo();
			SetColor(4);
			printf("\nArtista non trovato\a\n");
			SetColor(15);
			system("PAUSE");
		}
	}while (artista_trovato == 0);

	return (pos_artista);
}

/**
 * Questa funzione viene chiamata da ::menu_preferenze e permette di far scegliere all'utente cosa fare per ogni signolo artista.\n
 * Le opzioni sono:
 * 	1. Ascoltare cantante
 * 	2. Ascoltare e mettere mi piace
 * 	3. Ascoltare e mettere non mi piace.
 *
 * Nell'utilizzo della funzione si tenga presente che:
 * 	-# Ogni "Ascoltare cantante" aumenta di 1 gli ascolti
 * 	-# Ogni "Ascoltare e mettere mi piace" aumenterà di 1 gli ascolti ma il "Mi piace" sarà incrementato solo la prima volta.
 * 	-# Ogni "Ascoltare e mettere non mi piace" aumenterà di 1 gli ascolti e toglierà il "Mi piace" solamente se il "Mi piace" era già presente.
 *
 */

void modifica_preferenze(int posizione_utente, int pos_artista) {
	char artista[LUNGHEZZA_MAX] = { "\0" };	//Variabile d'appoggio per l'artista chiesto in input
	int artista_trovato = 0;//0 artista non trovato | 1 artista trovato					//Contiene la posizione nel vettore dell'artista trovato
	int i;

	do
	{		//Controllo fin quando non viene digitato 1 2 o 3
		system("cls");
		logo();
		SetColor(2);
		printf("[1]");
		SetColor(15);
		printf("Ascolta %s\n", ARTISTI[pos_artista].nome);
		SetColor(2);
		printf("[2]");
		SetColor(15);
		printf("Mi piace e ascolta%s\n", ARTISTI[pos_artista].nome);
		SetColor(2);
		printf("[3]");
		SetColor(15);
		printf("Non mi piace e ascolta%s\n", ARTISTI[pos_artista].nome);
		SetColor(15);
		printf("\nInserisci comando: ");
		fgets(artista, LUNGHEZZA_MAX, stdin);
		strcpy(artista, eliminazione_acapo(artista));
		fflush(stdin);

		if (strcmp(artista, "1") != 0 && strcmp(artista, "2") != 0
		        && strcmp(artista, "3") != 0)
		{
			system("cls");
			logo();
			SetColor(4);
			printf("\nComando errato\a\n");
			SetColor(15);
			system("PAUSE");
		}
	}while (strcmp(artista, "1") != 0 && strcmp(artista, "2") != 0
	        && strcmp(artista, "3") != 0);

	artista_trovato = 0;
	switch (atoi(artista)) {
	//Ascoltato
	case 1:
		for (i = 0; i < ARTISTI_MAX; i++)//Controllo se è già  presente il codice dell'artista
		{
			if (strcmp(UTENTI[posizione_utente].codice_artista[i], ARTISTI[pos_artista].codice)
			        == 0)
			{
				if (UTENTI[posizione_utente].preferenze[i] == 1)//Stava un ascoltato
				{
					artista_trovato = 1;
					i = ARTISTI_MAX;
				}

				if (UTENTI[posizione_utente].preferenze[i] == 2)//Stava un mi piace
				{
					UTENTI[posizione_utente].preferenze[i] = 2;
					artista_trovato = 1;
					i = ARTISTI_MAX;
				}

				if (UTENTI[posizione_utente].preferenze[i] == 3)//Stava un non mi piace
				{
					UTENTI[posizione_utente].preferenze[i] = 3;
					artista_trovato = 1;
					i = ARTISTI_MAX;
				}
				i = ARTISTI_MAX;
			}
		}

		if (artista_trovato == 0)//Se non è stato trovato lo inserisco nel primo spazio disponibile
		{
			for (i = 0; i < ARTISTI_MAX; i++)
			{
				if (UTENTI[posizione_utente].preferenze[i] == 0)
				{
					strcpy(UTENTI[posizione_utente].codice_artista[i], ARTISTI[pos_artista].codice);
					UTENTI[posizione_utente].preferenze[i] = 1;
					i = ARTISTI_MAX;
				}
			}
		}

		ARTISTI[pos_artista].ascolti++;
		break;

		//Mi piace
	case 2:
		for (i = 0; i < ARTISTI_MAX; i++)//Controllo se è già presente il codice dell'artista
		{
			if (strcmp(UTENTI[posizione_utente].codice_artista[i], ARTISTI[pos_artista].codice)
			        == 0)
			{
				//---
				if (UTENTI[posizione_utente].preferenze[i] == 1)//Stava un ascolto
				{
					UTENTI[posizione_utente].preferenze[i] = 2;
					ARTISTI[pos_artista].preferenze++;	//Aggiungo un mi piace
					artista_trovato = 1;
					i = ARTISTI_MAX;
				}

				if (UTENTI[posizione_utente].preferenze[i] == 2)//Stava un mi piace
				{
					artista_trovato = 1;
					i = ARTISTI_MAX;
				}

				if (UTENTI[posizione_utente].preferenze[i] == 3)//Stava un non mi piace
				{
					UTENTI[posizione_utente].preferenze[i] = 2;
					ARTISTI[pos_artista].preferenze++;	//Aggiungo un mi piace
					artista_trovato = 1;
					i = ARTISTI_MAX;
				}
			}
		}

		if (artista_trovato == 0)//Se non è stato trovato lo inserisco nel primo spazio disponibile
		{
			for (i = 0; i < ARTISTI_MAX; i++)
			{
				if (UTENTI[posizione_utente].preferenze[i] == 0)
				{
					strcpy(UTENTI[posizione_utente].codice_artista[i], ARTISTI[pos_artista].codice);
					UTENTI[posizione_utente].preferenze[i] = 2;
					i = ARTISTI_MAX;
					ARTISTI[pos_artista].preferenze++;
				}
			}
		}

		ARTISTI[pos_artista].ascolti++;
		break;

		//Non mi piace
	case 3:
		for (i = 0; i < ARTISTI_MAX; i++)//Controllo se Ã¨ giÃ  presente il codice dell'artista
		{
			if (strcmp(UTENTI[posizione_utente].codice_artista[i], ARTISTI[pos_artista].codice)
			        == 0)
			{
				if (UTENTI[posizione_utente].preferenze[i] == 1)//Stava un ascolto
				{
					UTENTI[posizione_utente].preferenze[i] = 3;
					artista_trovato = 1;
					i = ARTISTI_MAX;
				}

				if (UTENTI[posizione_utente].preferenze[i] == 2)//Stava un ascolto e mi piace
				{
					UTENTI[posizione_utente].preferenze[i] = 3;
					ARTISTI[pos_artista].preferenze--;		//Tolgo un mi piace
					artista_trovato = 1;
					i = ARTISTI_MAX;
				}

				if (UTENTI[posizione_utente].preferenze[i] == 3)//Stava un non mi piace
				{
					artista_trovato = 1;
					i = ARTISTI_MAX;
				}
			}
		}

		if (artista_trovato == 0)//Se non Ã¨ stato trovato lo inserisco nel primo spazio disponibile
		{
			for (i = 0; i < ARTISTI_MAX; i++)
			{
				if (UTENTI[posizione_utente].preferenze[i] == 0)
				{
					strcpy(UTENTI[posizione_utente].codice_artista[i], ARTISTI[pos_artista].codice);
					UTENTI[posizione_utente].preferenze[i] = 3;
					i = ARTISTI_MAX;
				}
			}
		}
		ARTISTI[pos_artista].ascolti++;
		break;
	}
}

/**
 * L'utente dovrà inserire il codice dell'artista desiderato. Sarà effettuato un controllo per verificare l'esistenza dell'artista
 *
 * @pre È possibile cambiare la dimensione della TOP cambiando il valore LUNGHEZZA_MAX
 */
int top(int artisti_effettivi, char* input) {
	char artista[LUNGHEZZA_MAX] = { "\0" };	//Variabile d'appoggio per l'artista chiesto in input
	int artista_trovato = 0;		//0 artista non trovato | 1 artista trovato
	int pos_artista = -1;//Contiene la posizione nel vettore dell'artista trovato
	int i;

	do{//Controllo fin quando non viene digitato il codice dell'artista correttamente

		ordinamento_stampa(input);

		printf("\nInserisci il codice dell'artista:");
		fgets(artista, LUNGHEZZA_MAX, stdin);
		strcpy(artista, eliminazione_acapo(artista));
		fflush(stdin);

		for (i = 0; i < artisti_effettivi; i++)
		{
			if (strcmp(artista, ARTISTI[i].codice) == 0)//Controllo per individuare l'artista inserito in input
			{
				printf("Artista trovato!\n");
				artista_trovato = 1;
				pos_artista = i;
			}
		}

		if (artista_trovato == 0)
		{
			system("cls");
			logo();
			SetColor(4);
			printf("\nArtista non trovato\a\n");
			SetColor(15);
			system("PAUSE");
		}
	}while (artista_trovato == 0);

	return (pos_artista);
}

/**
 * La funzione a seconda dell'input che riceverà andrà a ordinare gli artisti.\n
 * Per fare ciò saranno utilizzate delle variabili temporane rinominate con il nome del campo della struct preceduto da "tmp_".\n
 * Se il numero di "Mi piace" o "Ascolti" eccede il numero di massimo di TOP, saranno visualizzati comunque gli artisti con lo stesso numero di "Mi piace" o "Ascolti" in eccesso.
 * \pre Questa funzione deve essere chiamata da ::top
 */
void ordinamento_stampa(char* input) {
	unsigned int top = 0;
	unsigned int i;
	unsigned int min = 4294967295;		//valore massimo per l'int (2^32)-1
	unsigned int p = 0;
	unsigned int flag = 0;
	unsigned int appoggio_int;
	char appoggio_char[LUNGHEZZA_MAX];
	unsigned int tmp_mi_piace[ARTISTI_MAX];
	unsigned int tmp_ascolti[ARTISTI_MAX];
	char tmp_codice_artista[ARTISTI_MAX][LUNGHEZZA_CODICE];
	char tmp_nome_artista[ARTISTI_MAX][LUNGHEZZA_MAX];

	//Copia dei vettori  codice_artista e nome_artista
	for (i = 0; i < ARTISTI_MAX; i++)
	{
		strcpy(tmp_codice_artista[i], ARTISTI[i].codice);
		strcpy(tmp_nome_artista[i], ARTISTI[i].nome);
		tmp_mi_piace[i] = ARTISTI[i].preferenze;
		tmp_ascolti[i] = ARTISTI[i].ascolti;
	}

	if (strcmp(input, "mi piace") == 0)
	{
		while (p < ARTISTI_MAX - 1 && flag != 1)
		{
			p++;
			flag = 1;

			for (i = ARTISTI_MAX - 1; i >= p; i--)
			{
				if (tmp_mi_piace[i] > tmp_mi_piace[i - 1])
				{

					strcpy(appoggio_char, tmp_codice_artista[i]);
					strcpy(tmp_codice_artista[i], tmp_codice_artista[i - 1]);
					strcpy(tmp_codice_artista[i - 1], appoggio_char);

					strcpy(appoggio_char, tmp_nome_artista[i]);
					strcpy(tmp_nome_artista[i], tmp_nome_artista[i - 1]);
					strcpy(tmp_nome_artista[i - 1], appoggio_char);

					appoggio_int = tmp_mi_piace[i];
					tmp_mi_piace[i] = tmp_mi_piace[i - 1];
					tmp_mi_piace[i - 1] = appoggio_int;

					flag = 0;

				}
			}
		}

	}

	if (strcmp(input, "ascolti") == 0)
	{
		while (p < ARTISTI_MAX - 1 && flag != 1)
		{
			p++;
			flag = 1;

			for (i = ARTISTI_MAX - 1; i >= p; i--)
			{
				if (tmp_ascolti[i] > tmp_ascolti[i - 1])
				{
					strcpy(appoggio_char, tmp_codice_artista[i]);
					strcpy(tmp_codice_artista[i], tmp_codice_artista[i - 1]);
					strcpy(tmp_codice_artista[i - 1], appoggio_char);

					strcpy(appoggio_char, tmp_nome_artista[i]);
					strcpy(tmp_nome_artista[i], tmp_nome_artista[i - 1]);
					strcpy(tmp_nome_artista[i - 1], appoggio_char);

					appoggio_int = tmp_ascolti[i];
					tmp_ascolti[i] = tmp_ascolti[i - 1];
					tmp_ascolti[i - 1] = appoggio_int;

					flag = 0;
				}
			}
		}

	}

	if (strcmp(input, "mi piace") == 0)
	{
		for (i = 0; i < TOP; i++)		//Trovo il min
		{
			if (min > tmp_mi_piace[i])
			{
				min = tmp_mi_piace[i];
			}
		}

		system("cls");
		logo();
		SetColor(3);
		printf("POSIZIONE    CODICE\tNOME                          MI PIACE\n");
		SetColor(15);

		for (i = 0; i < ARTISTI_MAX; i++)
		{
			if(tmp_mi_piace[i]!=0)
			{
				printf("    %-8d %s\t%-32s%d\n", i + 1, tmp_codice_artista[i], tmp_nome_artista[i], tmp_mi_piace[i]);

				top++;

				if (top >= TOP)
				{
					if (min != tmp_mi_piace[i + 1])
					{
						i = ARTISTI_MAX;
					}
				}
			}
			else
			{
				i=ARTISTI_MAX;
			}


		}
	}

	if (strcmp(input, "ascolti") == 0)
	{
		for (i = 0; i < TOP; i++)		//Trovo il min
		{
			if (min > tmp_ascolti[i])
			{
				min = tmp_ascolti[i];
			}
		}

		system("cls");
		logo();
		SetColor(3);
		printf("POSIZIONE    CODICE\tNOME                          ASCOLTI\n");
		SetColor(15);

		for (i = 0; i < ARTISTI_MAX; i++)
		{
			if(tmp_ascolti[i]!=0)
			{
				printf("    %-8d %s\t%-32s%d\n", i + 1, tmp_codice_artista[i], tmp_nome_artista[i], tmp_ascolti[i]);

				top++;

				if (top >= TOP)
				{
					if (min != tmp_ascolti[i + 1])
					{
						i = ARTISTI_MAX;
					}
				}
			}
			else
			{
				i=ARTISTI_MAX;
			}
		}
	}

}
