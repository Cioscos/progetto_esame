/**
 * @file funzioni_artista.c
 * @brief File contenente tutte le funzioni che riguardano la gestione degli artisti.
 *
 * Questo file permette di gestire la lista degli utenti, andandola a modificare.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include "funzioni.h"

 /**
 * Inserimento nuovo artista
 *
 * Questa funzione permette di inserire un nuovo cantante nella lista degli artisti.
 * @param lista_generi Vettore bidimensionale di caratteri contenente i generi disponibili nel programma
 * @param artisti_effettivi Numero degli artisti effettivamente memorizzati nel programma
 * @return Il numero degli artisti effettivi aggiornato
 */
int inserimento_artista(char lista_generi[][LUNGHEZZA_MAX], int artisti_effettivi) {

	unsigned int posizione_genere = 0;							//pozione del genere nel vettore lista_generi
	char genere_provvisorio[LUNGHEZZA_MAX];				//Contiene l'input inserito dall'utente
	unsigned int genere_esistente = GENERI_TOT;					//0 genere non esistente | 1 genere esistente
	char risposta[LUNGHEZZA_MAX] = { "si" };			//Risposta alla domanda 'Vuoi inserire un'altra preferenza?'
	char anno_provvisorio[LUNGHEZZA_MAX] = { '\0' };	//Contiene l'anno in formato stringa per poter effettuare controlli
	int i = 0;
	char inserimento_provvisorio[LUNGHEZZA_MAX] = { '\0' };

//NOME ARTISTA-----------------------
	do
	{
		system("cls");
		logo();
		printf("L'ultimo codice inserito e': %s\n\n",ARTISTI[artisti_effettivi-1].codice);
		printf("Inserisci nome nuovo artista:");
		fgets(ARTISTI[artisti_effettivi].nome, LUNGHEZZA_MAX, stdin);
		strcpy(ARTISTI[artisti_effettivi].nome, eliminazione_acapo(ARTISTI[artisti_effettivi].nome));
		fflush(stdin);
		if((isControllo_Esistenza(artisti_effettivi, ARTISTI[artisti_effettivi].nome, "nome_artista")!= 0))
		{
			SetColor(4);
			printf("\aNome artista gi%c presente\n",133);
			SetColor(15);
			system("pause");
		}
	}while ((strlen(ARTISTI[artisti_effettivi].nome) < 1)
	        || (isControllo_Esistenza(artisti_effettivi, ARTISTI[artisti_effettivi].nome, "nome_artista")
	                != 0));

//CODICE ARTISTA---------------------
	do
	{
		system("cls");
		logo();
		printf("Inserisci codice artista di lunghezza 4:");
		fgets(ARTISTI[artisti_effettivi].codice, LUNGHEZZA_CODICE, stdin);
		strcpy(ARTISTI[artisti_effettivi].codice, eliminazione_acapo(ARTISTI[artisti_effettivi].codice));
		fflush(stdin);

		if (strcmp(ARTISTI[artisti_effettivi].codice, "0000") == 0)
		{
			system("cls");
			logo();
			SetColor(4);
			printf("\aNon puoi inserire un codice vuoto!\n");
			SetColor(15);
			system("pause");
		}

		if(isControllo_Esistenza(artisti_effettivi, ARTISTI[artisti_effettivi].codice, "codice_artista")!= 0)
		{
			SetColor(4);
			printf("\aCodice artista gi%c presente\n",133);
			SetColor(15);
			system("pause");
		}
	}while (strlen(ARTISTI[artisti_effettivi].codice) != LUNGHEZZA_CODICE - 1
	        || (isControllo_Esistenza(artisti_effettivi, ARTISTI[artisti_effettivi].codice, "codice_artista")
	                != 0)
	        || strcmp(ARTISTI[artisti_effettivi].codice, "0000") == 0);



//Inserimento generi fin quando non viene digitato no-----------------
	do
	{
		genere_esistente = GENERI_TOT;

		do
		{
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

			printf("\nInserisci genere artista:");
			fgets(genere_provvisorio, LUNGHEZZA_MAX, stdin);
			strcpy(genere_provvisorio, eliminazione_acapo(genere_provvisorio));
			fflush(stdin);

			for (i = 0; i < GENERI_TOT; i++) //Controlla se il genere Ã¨ presente nella lista_generi
			{
				if (strcmp(genere_provvisorio, lista_generi[i]) == 0)//Quando non Ã¨ presente (quindi 0) lo inserisce
				{
					genere_esistente = 1;
					posizione_genere = i;
					i = GENERI_TOT;

					if (ARTISTI[artisti_effettivi].genere[posizione_genere]
					        == 0)
					{
						ARTISTI[artisti_effettivi].genere[posizione_genere] = 1;//Genere inserito
						system("cls");
						logo();
						printf("Genere inserito correttamente\n");
						system("PAUSE");
					}else
					{
						system("cls");
						logo();
						printf("Genere gi%c inserito precedentemente\n", 133);
						system("PAUSE");
					}
				}else
				{
					if (i == GENERI_TOT - 1)
					{
						system("cls");
						logo();
						printf("Genere non inserito correttamente\n");
						system("PAUSE");
					}
				}
			}
		}while (genere_esistente != 1);

		do
		{
			system("cls");
			logo();
			printf("Vuoi inserire un altro genere?\nRispondere con si o no:");
			fgets(risposta, LUNGHEZZA_MAX, stdin);
			strcpy(risposta, eliminazione_acapo(risposta));
			fflush(stdin);		//Svuota flusso in input
		}while (strcmp(risposta, "si") != 0 && strcmp(risposta, "no") != 0);

	}while (strcmp(risposta, "si") == 0);


//INSERIMENTO PRODUTTORE------------------
	do
	{
		system("cls");
		logo();
		printf("Inserisci produttore:");
		fgets(ARTISTI[artisti_effettivi].produttore, LUNGHEZZA_MAX, stdin);
		strcpy(ARTISTI[artisti_effettivi].produttore, eliminazione_acapo(ARTISTI[artisti_effettivi].produttore));
		fflush(stdin);
	}while (strlen(ARTISTI[artisti_effettivi].produttore) < 1);
	system("cls");		//Controllo per evitare che non venga inserito nulla


//INSERIEMNTO NAZIONALITA'----------------
	do
	{	//Controllo fin quando non viene inserito almeno una lettera
		system("cls");
		logo();
		do
		{		//Controllo fin quando non vengono inserite tutte lettere
			printf("Inserisci nazionalit%c nuovo utente: ", 133);
			SetColor(6);
			fgets(inserimento_provvisorio, LUNGHEZZA_MAX, stdin);
			strcpy(inserimento_provvisorio, eliminazione_acapo(inserimento_provvisorio));
			fflush(stdin);
			SetColor(15);
			if(isControllo_Lettera(inserimento_provvisorio, LUNGHEZZA_MAX)!=1)
			{
				system("cls");
				logo();
				SetColor(4);
				printf("Hai inserito dei caratteri non validi.\nInserisci solamente lettere minuscole o maiuscole\n");
				SetColor(15);
				system("pause");
				system("cls");
				logo();				}
		}while(isControllo_Lettera(inserimento_provvisorio, LUNGHEZZA_MAX)!=1);
	}while ((strlen(inserimento_provvisorio) < 1));  //Controllo per evitare che non venga inserito nulla

	strcpy(ARTISTI[artisti_effettivi].nazionalita, inserimento_provvisorio);
	stringclear(inserimento_provvisorio, LUNGHEZZA_MAX);

//INSERIMENTO ANNO NASCITA GRUPPO---------
	do
	{
		system("cls");
		logo();
		printf("Inserisci anno di inizio:");
		fgets(anno_provvisorio, LUNGHEZZA_MAX, stdin);
		strcpy(anno_provvisorio, eliminazione_acapo(anno_provvisorio));
		fflush(stdin);
	}while (isControllo_Numero(anno_provvisorio, LUNGHEZZA_MAX) != 1 || atoi(anno_provvisorio)>DATA_CORRENTE.anno);

	ARTISTI[artisti_effettivi].anno_inizio = atoi(anno_provvisorio);

	artisti_effettivi++;        //Incrementa di 1 il numero degli artisti

	return (artisti_effettivi);
}

void visualizzazione_artisti(char lista_generi[][LUNGHEZZA_MAX], int artisti_effettivi) {
	int i, j;

	logo();

//MOSTRO INFORMAZIONE ARTISTA-----------------------------
	for (i = 0; i < artisti_effettivi; i++)
	{
		printf("\n\n%d ", i + 1);
		SetColor(2);
		printf("-------NOME:");
		SetColor(11);
		printf("%s", ARTISTI[i].nome);
		SetColor(2);
		printf("--------\nCODICE:");
		SetColor(15);
		printf("%s", ARTISTI[i].codice);
		SetColor(2);
		printf("\nGENERE: ");
		SetColor(15);
		for (j = 0; j < GENERI_TOT; j++) //Trovo il generere dell'artista (1 genere trovato)
		{
			if (ARTISTI[i].genere[j] == 1)
			{
				printf("%s ", lista_generi[j]);
			}
		}
		SetColor(2);
		printf("\nNAZIONALIT%c: ", 183);
		SetColor(15);
		printf("%s\n", ARTISTI[i].nazionalita);
		SetColor(2);
		printf("PRODUTTORE: ");
		SetColor(15);
		printf("%s\n", ARTISTI[i].produttore);
		SetColor(2);
		printf("ANNO: ");
		SetColor(15);
		printf("%d\n", ARTISTI[i].anno_inizio);
		SetColor(2);
		printf("ASCOLTI: ");
		SetColor(15);
		printf("%d\n", ARTISTI[i].ascolti);
		SetColor(2);
		printf("MI PIACE: ");
		SetColor(15);
		printf("%d\n", ARTISTI[i].preferenze);
	}
}

void modifica_artista(int artisti_effettivi, char lista_generi[][LUNGHEZZA_MAX]) {
	int i, j, x;
	char scelta[LUNGHEZZA_MAX] = { "\0" };	//Variabile d'appoggio per l'input della scelta per il men? chiesto in input
	unsigned int numero_generi = 0;						//Numero generi
	unsigned int genere_trovato = 0;						//0 genere non trovato - 1 genere trovato
	char genere[LUNGHEZZA_MAX] = { "\0" };		//Variabile d'appoggio per il genere chiesto in input
	unsigned int artista_trovato = 0;					//0 artista non trovato - 1 artista trovato
	char artista[LUNGHEZZA_MAX] = { "\0" };	 	//Variabile d'appoggio per l'artista chiesto in input
	char inserimento_provvisorio[LUNGHEZZA_MAX] = { '\0' };

	do
	{
		system("cls");
		logo();
		SetColor(3);
		printf("CODICE\t\tNOME\n");
		SetColor(15);
		for (i = 0; i < artisti_effettivi; i++)		//Stampa artisti
		{
			printf("%s\t\t%s\n", ARTISTI[i].codice, ARTISTI[i].nome);
		}
		printf("Inserisci il codice dell'artista da modificare:");
		fgets(artista,LUNGHEZZA_MAX,stdin);
		strcpy(artista, eliminazione_acapo(artista));
		fflush(stdin);

		for (i = 0; i < artisti_effettivi; i++)
		{
			if (strcmp(artista, ARTISTI[i].codice) == 0)//Controllo per individuare l'artista inserito in input
			{
				printf("Artista trovato!\n");
				artista_trovato = 1;
				system("pause");

				do
				{					//Controllo sull input fornito dall'utente
					system("cls");
					logo();
					SetColor(2);
					printf("[1]");
					SetColor(15);
					printf("Nome\n");
					SetColor(2);
					printf("[2]");
					SetColor(15);
					printf("Genere\n");
					SetColor(2);
					printf("[3]");
					SetColor(15);
					printf("Anno\n");
					SetColor(2);
					printf("[4]");
					SetColor(15);
					printf("Produttore\n");
					SetColor(2);
					printf("[5]");
					SetColor(15);
					printf("Nazionalit%c\nInserisci comando:", 133);
					fgets(scelta,LUNGHEZZA_MAX,stdin);
					strcpy(scelta, eliminazione_acapo(scelta));
					fflush(stdin);

					if ((strcmp(scelta, "1") < 0) || (strcmp(scelta, "5") > 0))
					{
						system("cls");
						logo();
						SetColor(4);
						printf("Inserire un campo valido!\a\n\n");
						SetColor(15);
						system("pause");
					}

				}while ((strcmp(scelta, "1") < 0) || (strcmp(scelta, "5") > 0));

				//SELEZIONE ATTRIBUTI DA CAMBIARE------------------------------------
				switch (atoi(scelta)) {

				case 1:
					do
					{
						system("cls");			//Cambio nome
						logo();
						printf("L'attuale nome %c: ", 138);
						SetColor(11);
						printf("%s\n\n", ARTISTI[i].nome);
						SetColor(15);
						printf("Con che nome vuoi sostituirlo?\n");
						fgets(artista, LUNGHEZZA_MAX, stdin);
						strcpy(artista, eliminazione_acapo(artista));
						fflush(stdin);
						if(isControllo_Lettera(artista, LUNGHEZZA_MAX)!=1)
						{
							system("cls");
							logo();
							SetColor(4);
							printf("Hai inserito dei caratteri non validi.\nInserisci solamente lettere minuscole o maiuscole\n");
							SetColor(15);
							system("pause");
							system("cls");
							logo();
						}
					}while ((strlen(artista) < 1 )
					        || (isControllo_Esistenza(artisti_effettivi, artista, "nome_artista")!= 0)
					        || (isControllo_Lettera(artista, LUNGHEZZA_MAX)!=1));

					stringclear(ARTISTI[i].nome, LUNGHEZZA_MAX);
					strcpy(ARTISTI[i].nome, artista);

					system("cls");
					logo();
					printf("Nome sostituito correttamente\n\n");

					break;

				case 2:
					do
					{						//Modifica generi
						system("cls");
						logo();
						printf("L'attuale genere %c: ", 138);
						SetColor(11);

						numero_generi = 0;

						for (j = 0; j < GENERI_TOT; j++)//Stampa lista generi dell'artista chiesto in input
						{
							if (ARTISTI[i].genere[j] == 1)
							{
								printf("%s  ", lista_generi[j]);
								numero_generi++;
							}
						}
						SetColor(15);
						printf("\nHai a disposizione le seguenti opzioni:\n");
						SetColor(3);
						printf("[1]");
						SetColor(15);
						printf("Elimina genere\n");
						SetColor(3);
						printf("[2]");
						SetColor(15);
						printf("Aggiungi genere\n");
						printf("Inserisci l'opzione: ");
						fgets(scelta, LUNGHEZZA_MAX, stdin);
						strcpy(scelta, eliminazione_acapo(scelta));
						fflush(stdin);

						if ((strcmp(scelta, "1") < 0)
						        || (strcmp(scelta, "2") > 0))//Controllo sull'input fornito dall'utente
						{
							system("cls");
							logo();
							SetColor(4);
							printf("Opzione non disponibile!\a\n\n");
							SetColor(15);
							system("pause");
						}
					}while ((strcmp(scelta, "1") < 0)
					        || (strcmp(scelta, "2") > 0));//Continua fin quando non viene inserito 1 o 2

					system("cls");

					if (strcmp(scelta, "1") == 0)		//Elimina genere
					{
						if (numero_generi == 1)	//Controllo per non far rimuovere il genere quando quando quest'ultimo ? l'unico
						{
							logo();
							printf("Non %c possibile eliminare l'unico genere\n", 138);
						}else		//Generi maggiori di 1
						{
							logo();
							printf("I generi inseriti sono:");
							SetColor(11);

							for (j = 0; j < GENERI_TOT; j++)
							{
								if (ARTISTI[i].genere[j] == 1)//Stampa i generi dell'artista chiesto in input
								{
									printf("%s  ", lista_generi[j]);
								}
							}

							SetColor(15);
							printf("\nInserire genere da eliminare: ");
							fgets(genere, LUNGHEZZA_MAX, stdin);
							strcpy(genere, eliminazione_acapo(genere));
							fflush(stdin);

							for (j = 0; j < GENERI_TOT; j++)
							{
								if (strcmp(lista_generi[j], genere) == 0)//Controllo se il genere inserito esiste
								{
									if (ARTISTI[i].genere[j] == 1)//Controllo se il genere appartiene all'artista
									{
										ARTISTI[i].genere[j] = 0;//Azzeramento genere
										genere_trovato = 1;
										j = GENERI_TOT;
									}
								}
							}

							if (genere_trovato == 0)//Controllo se il genere inserito in input dall'utente ? stato trovato
							{
								system("cls");
								logo();
								SetColor(4);
								printf("Genere inserito non appartenente all'artista\a\n\n");
								SetColor(15);
							}else
							{
								system("cls");
								logo();
								printf("\nGenere eliminato\n\n");
							}
						}

					}else		//Aggiungi genere
					{
						logo();
						printf("L'attuale genere %c: ", 138);
						SetColor(11);

						for (j = 0; j < GENERI_TOT; j++)//Stampa generi appartenenti all'artista
						{
							if (ARTISTI[i].genere[j] == 1)
							{
								printf("%s  ", lista_generi[j]);
							}
						}

						SetColor(15);
						printf("\nI generi disponibili sono:\n");
						x=1;
						SetColor(6);
						for (j = 0; j < GENERI_TOT; j++) //Stampa tutti i generi disponibili
						{
							if (ARTISTI[i].genere[j] == 0)
							{
								printf("%-31s", lista_generi[j]);
								if ((x % 2) == 0)
								{
									printf("\n");
								}
								x++;
							}
						}
						SetColor(15);

						printf("\nInserire genere da aggiungere: ");
						fgets(genere, LUNGHEZZA_MAX, stdin);
						strcpy(genere, eliminazione_acapo(genere));
						fflush(stdin);


						for (j = 0; j < GENERI_TOT; j++)
						{
							if (strcmp(lista_generi[j], genere) == 0)//Controllo se il genere inserito esiste
							{
								if (ARTISTI[i].genere[j] == 0)
								{
									ARTISTI[i].genere[j] = 1;
									genere_trovato = 1;
									j=GENERI_TOT;
								}else
								{
									system("cls");
									logo();
									SetColor(4);
									printf("Genere gi%c inserito\n\n", 133);
									SetColor(15);
								}
							}
						}

						if (genere_trovato == 0)//Controllo sul genere inserito
						{
							system("cls");
							logo();
							SetColor(4);
							printf("Genere inserito non esistente\n\n");
							SetColor(15);
							system("pause");
						}else
						{
							system("cls");
							logo();
							printf("\nGenere inserito\n\n");
						}
					}
					break;

				case 3:
					system("cls");	//Cambio anno di inzio attivit?
					char anno_provvisorio[LUNGHEZZA_MAX] = { '\0' };

					logo();
					printf("L'attuale anno %c: ", 138);
					SetColor(11);
					printf("%d\n\n", ARTISTI[i].anno_inizio);
					SetColor(15);

					do
					{
						system("cls");
						logo();
						printf("L'attuale anno %c: ", 138);
						SetColor(11);
						printf("%d\n\n", ARTISTI[i].anno_inizio);
						SetColor(15);
						printf("Inserisci nuovo anno: ");
						fgets(anno_provvisorio, LUNGHEZZA_MAX, stdin);
						strcpy(anno_provvisorio, eliminazione_acapo(anno_provvisorio));
						fflush(stdin);

					}while (isControllo_Numero(anno_provvisorio, LUNGHEZZA_MAX)
					        != 1 || atoi(anno_provvisorio)>DATA_CORRENTE.anno);

					ARTISTI[i].anno_inizio = atoi(anno_provvisorio);

					printf("Anno inserito!\n\n");

					break;

				case 4:
					system("cls");		//Cambio produttore
					logo();
					printf("L'attuale produttore %c: ", 138);
					SetColor(11);
					printf("%s\n\n", ARTISTI[i].produttore);
					SetColor(15);
					printf("Inserisci nuovo produttore: ");
					fgets(ARTISTI[i].produttore, LUNGHEZZA_MAX, stdin);
					strcpy(ARTISTI[i].produttore, eliminazione_acapo(ARTISTI[i].produttore));
					system("cls");
					logo();
					printf("Nuovo produttore inserito!\n\n");
					break;

				case 5:
					do
					{
						system("cls");		//Cambio nazionalità
						logo();
						do{		//Controllo fin quando non viene inserito almeno un carattere
							printf("L'attuale nazionalit%c %c: ", 133, 138);
							SetColor(11);
							printf("%s\n\n", ARTISTI[i].nazionalita);
							SetColor(15);
							printf("Inserisci nuova nazionalit%c: ", 133);
							fgets(inserimento_provvisorio, LUNGHEZZA_MAX, stdin);
							strcpy(inserimento_provvisorio, eliminazione_acapo(inserimento_provvisorio));
							fflush(stdin);
							if(isControllo_Lettera(inserimento_provvisorio, LUNGHEZZA_MAX)!=1)
							{
								system("cls");
								logo();
								SetColor(4);
								printf("Hai inserito dei caratteri non validi.\nInserisci solamente lettere minuscole o maiuscole\n");
								SetColor(15);
								system("pause");
								system("cls");
								logo();
							}
						}while(isControllo_Lettera(inserimento_provvisorio, LUNGHEZZA_MAX)!=1);
					}while((isControllo_Lettera(inserimento_provvisorio, LUNGHEZZA_MAX)!=1) || (strlen(inserimento_provvisorio) < 1));
					strcpy(ARTISTI[i].nazionalita, inserimento_provvisorio);
					printf("Nuova nazionalit%c inserita!\n\n", 133);
					break;
				}

				system("pause");
				i = artisti_effettivi;
			}
		}

		if (artista_trovato == 0)		//Artista non trovato
		{
			SetColor(4);
			printf("Artista non trovato!\a\n\n");
			SetColor(15);
			printf("Vuoi riprovare? Rispondi si o no\n");
			stringclear(scelta, 3);

			do
			{//Continua a chiedere l'input fin quando non viene inserito si o no
				gets(scelta);
				fflush(stdin);
				for (j = 0; j < LUNGHEZZA_MAX; j++)
				{
					scelta[j] = tolower(scelta[j]);	//Trasforma in minuscolo in primo carattere
				}
				if ((strcmp(scelta, "si") != 0) && (strcmp(scelta, "no") != 0))
				{
					SetColor(4);
					printf("Risposta non accettata! Riprova\n");
					SetColor(15);
				}
			}while ((strcmp(scelta, "si") != 0) && (strcmp(scelta, "no") != 0));

		}
		i = 0;

	}while (strcmp(scelta, "si") == 0);		//Termina quando viene digitato si
}

/**
 * La funzione stampa prima tutti gli artisti disponibili.
 * Successivamente chiede l'inserimento del codice artista da eliminare e controlla se effettivamente l'artista esiste.\n
 * Se l'artista esiste procederà con la sua eliminazione referenziando la funzione ::elimina_artista; in alternativa la funzione chiederà se vogliamo provare
 * ad inserire un nuovo artista da eliminare.
 */
int scegli_artista(int artisti_effettivi){

	int i,j;
	char artista[LUNGHEZZA_MAX] = { "\0" };		//Variabile d'appoggio per l'artista chiesto in input
	char scelta[LUNGHEZZA_MAX] = { "\0" };		//Variabile d'appoggio per l'input della scelta per il men? chiesto in input
	unsigned int artista_trovato = 0;					//0 artista non trovato - 1 artista trovato
	int posizione_artista = -1;					//Contiene la posizone dell'artista trovato nel vettore

	do{
		system("cls");
		logo();
		SetColor(3);
		printf("CODICE\t\tNOME\n");
		SetColor(15);

		for (i = 0; i < artisti_effettivi; i++)		//Stampa artisti
		{
			printf("%s\t\t%s\n", ARTISTI[i].codice, ARTISTI[i].nome);
		}
		printf("Inserisci il codice dell'artista da eliminare:");
		fgets(artista, LUNGHEZZA_CODICE, stdin);
		strcpy(artista, eliminazione_acapo(artista));
		fflush(stdin);

		for(i=0;i<artisti_effettivi;i++)
		{
			if(strcmp(artista, ARTISTI[i].codice)==0)		//Controllo per individuare l'artista inserito in input
			{
				artista_trovato=1;
				posizione_artista=i;
			}
		}

		if (artista_trovato == 0)		//Artista non trovato
		{
			system("cls");
			logo();
			SetColor(4);
			printf("Artista non trovato!\a\n\n");
			SetColor(15);
			printf("Vuoi riprovare? Rispondi si o no:");
			stringclear(scelta, 3);

			do
			{	//Continua a chiedere l'input fin quando non viene inserito si o no
				fgets(scelta, LUNGHEZZA_CODICE, stdin);
				strcpy(scelta, eliminazione_acapo(scelta));
				fflush(stdin);
				for (j = 0; j < LUNGHEZZA_MAX; j++)
				{
					scelta[j] = tolower(scelta[j]);	//Trasforma in minuscolo in primo carattere
				}

				if ((strcmp(scelta, "si") != 0) && (strcmp(scelta, "no") != 0))
				{
					system("cls");
					logo();
					SetColor(15);
					printf("Vuoi riprovare? Rispondi si o no: ");
				}
			}while ((strcmp(scelta, "si") != 0) && (strcmp(scelta, "no") != 0));
		}

	}while(strcmp(scelta, "si") == 0 && artista_trovato == 0);

	return posizione_artista;
}


int elimina_artista(int artisti_effettivi, int posizione_artista) {
	int i, j;

	for (i = posizione_artista + 1; i < artisti_effettivi; i++)	//Spostamento degli artisti nella posizione precendete fino all'indice del artista da eliminare
	{
		//COPIA DEL ARTISTA IN POSIZIONE SUPERIORE IN QUELLO IN POSIZIONE INFERIORE
		strcpy(ARTISTI[i - 1].codice, ARTISTI[i].codice);
		strcpy(ARTISTI[i - 1].nome, ARTISTI[i].nome);
		for (j = 0; j < GENERI_TOT; j++)
		{
			ARTISTI[i - 1].genere[j] = ARTISTI[i].genere[j];
		}
		strcpy(ARTISTI[i - 1].produttore, ARTISTI[i].produttore);
		strcpy(ARTISTI[i - 1].nazionalita, ARTISTI[i].nazionalita);
		ARTISTI[i - 1].anno_inizio = ARTISTI[i].anno_inizio;
		ARTISTI[i - 1].ascolti = ARTISTI[i].ascolti;
		ARTISTI[i - 1].preferenze = ARTISTI[i].preferenze;
	}

	//PULITURA ULTIMO POSZIONE ARTISTI
	stringclear(ARTISTI[artisti_effettivi - 1].codice, LUNGHEZZA_CODICE);
	stringclear(ARTISTI[artisti_effettivi - 1].nome, LUNGHEZZA_MAX);
	for (j = 0; j < GENERI_TOT; j++)
	{
		ARTISTI[artisti_effettivi - 1].genere[j] = 0;
	}
	stringclear(ARTISTI[artisti_effettivi - 1].produttore, LUNGHEZZA_MAX);
	stringclear(ARTISTI[artisti_effettivi - 1].nazionalita, LUNGHEZZA_MAX);
	ARTISTI[artisti_effettivi - 1].anno_inizio = 0;
	ARTISTI[artisti_effettivi - 1].ascolti = 0;
	ARTISTI[artisti_effettivi - 1].preferenze = 0;

	artisti_effettivi--;		//Eliminazione di un artista

	i = 0;

	return (artisti_effettivi);
}
