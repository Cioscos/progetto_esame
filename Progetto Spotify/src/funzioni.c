#include "funzioni.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

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
	printf("[3]");
	SetColor(15);
	printf("Gestione file\n");
	SetColor(2);
	printf("[0]");
	SetColor(15);
	printf("Termina programma\n\nInserisci comando:");
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

void stampa_menu_utente()
{
	SetColor(2);
	printf("[1]");
	SetColor(15);
	printf("Visualizza utenti\n");
	SetColor(2);
	printf("[2]");
	SetColor(15);
	printf("Visualizza profilo utente\n");
	SetColor(2);
	printf("[3]");
	SetColor(15);
	printf("Aggiungi nuova preferenza\n");
	SetColor(2);
	printf("[4]");
	SetColor(15);
	printf("Modifica preferenza\n");
	SetColor(2);
	printf("[5]");
	SetColor(15);
	printf("Elimina preferenza\n");
	SetColor(2);
	printf("[6]");
	SetColor(15);
	printf("Aggiungi nuovo utente\n");
	SetColor(2);
	printf("[7]");
	SetColor(15);
	printf("Modifica utente\n");
	SetColor(2);
	printf("[8]");
	SetColor(15);
	printf("Elimina utente\n");
	SetColor(2);
	printf("[0]");
	SetColor(15);
	printf("Torna al menu principale\n\nInserisci comndo: ");
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
		}
		stringclear(input_utente);
		scanf("%3s",input_utente);
		fflush(stdin);		//Svuota flusso in input
	}
}

int inserimento_artista(char lista_generi[][LUNGHEZZA_MAX], int artisti_effettivi)
{

//NOME ARTISTA-----------------------

	logo();
	printf("Inserisci nome artista:");
	gets(ARTISTI[artisti_effettivi].nome);
	fflush(stdin);

//CODICE ARTISTA---------------------
	do{
		system("cls");
		logo();
		printf("Inserisci codice artista di lunghezza 4:");
		gets(ARTISTI[artisti_effettivi].codice);
		fflush(stdin);
	}while(strlen(ARTISTI[artisti_effettivi].codice)!=LUNGHEZZA_CODICE-1 /* && Fare una funzione che controlla se il codice � gi� stato utlizzato */);



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

					if(ARTISTI[artisti_effettivi].genere[posizione_genere]==0)
					{
						ARTISTI[artisti_effettivi].genere[posizione_genere]=1;		//Genere inserito
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
	gets(ARTISTI[artisti_effettivi].produttore);
	fflush(stdin);

//INSERIEMNTO NAZIONALITA'----------------
	system("cls");
	logo();
	printf("Inserisci nazionalita:");
	gets(ARTISTI[artisti_effettivi].nazionalita);
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

	ARTISTI[artisti_effettivi].anno_inizio=atoi(anno_provvisorio);

	artisti_effettivi++;        //Incrementa di 1 il numero degli artisti

	return(artisti_effettivi);
}

void visualizzazione_artisti(char lista_generi[][LUNGHEZZA_MAX], int artisti_effettivi)
{
	int i=0,j;
	logo();

//MOSTRO INFORMAZIONE ARTISTA-----------------------------
	for(i=0;i<artisti_effettivi;i++)
	{
		printf("%d ",i+1);
		SetColor(2);
		printf("-----------CODICE:");
		SetColor(15);
		printf("%s",ARTISTI[i].codice);
		SetColor(2);
		printf("----------------\nARTISTA: ");
		SetColor(15);
		printf("%s\n", ARTISTI[i].nome);
		SetColor(2);
		printf("\nGENERE: ");
		SetColor(15);
		for(j=0;j<GENERI_TOT;j++)                    //Trovo il generere dell'artista (1 genere trovato)
		{
			if(ARTISTI[i].genere[j]==1)
			{
				printf("%s ", lista_generi[j]);
			}
		}
		SetColor(2);
		printf("\nNAZIONALITA': ");
		SetColor(15);
		printf("%s\n",ARTISTI[i].nazionalita);
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

void modifica_artista(int artisti_effettivi, char lista_generi[][LUNGHEZZA_MAX]) //TODO Controllare bene di tu tu di tutto
{
	int i,j;
	char artista[LUNGHEZZA_MAX]={"\0"};
	char genere[LUNGHEZZA_MAX]={"\0"};
	char scelta[LUNGHEZZA_INPUT]={"\0"};
	int artista_trovato=0;
	int genere_trovato=0;

	do{
		system("cls");
		logo();
		SetColor(3);
		printf("CODICE\t\tNOME\n");
		SetColor(15);
		for(i=0;i<artisti_effettivi;i++)		//Stampa artisti
		{
			printf("%s\t\t%s\n", ARTISTI[i].codice, ARTISTI[i].nome);
		}
		printf("Inserisci il nome dell'artista da modificare:");
		gets(artista);
		fflush(stdin);

		for(i=0;i<artisti_effettivi;i++)
		{
			if(strcmp(artista, ARTISTI[i].nome)==0)		//Controllo per individuare l'artista inserito in input
			{
				printf("Artista trovato!\n");
				artista_trovato=1;
				system("pause");

				do{						//Controllo sull input fornito dall'utente
					system("cls");
					logo();
					printf("Cosa vuoi modificare?\n"
							"1)Nome\n"
							"2)Genere\n"
							"3)Anno\n"
							"4)Produttore\n"
							"5)Nazionalit%c\n\n",133);
					gets(scelta);

					if((strcmp(scelta,"1")!=0) && (strcmp(scelta,"2")!=0) && (strcmp(scelta,"3")!=0) && (strcmp(scelta,"4")!=0) && (strcmp(scelta,"5")!=0) )
					{
						system("cls");
						logo();
						SetColor(5);
						printf("Inserire un campo valido!\n\n");
						SetColor(15);
						system("pause");
					}

				}while((strcmp(scelta,"1")!=0) && (strcmp(scelta,"2")!=0) && (strcmp(scelta,"3")!=0) && (strcmp(scelta,"4")!=0) && (strcmp(scelta,"5")!=0));


	//SELEZIONE ATTRIBUTI DA CAMBIARE------------------------------------
				switch(atoi(scelta))
				{

					case 1: system("cls");			//Cambio nome
							logo();
							printf("L'attuale nome %c: ", 138);
							SetColor(11);
							printf("%s\n\n", ARTISTI[i].nome);
							SetColor(15);
							printf("Con che nome vuoi sostituirlo?\n");
							stringclear(ARTISTI[i].nome);
							gets(ARTISTI[i].nome);
							system("cls");
							logo();
							printf("Nome sostituito correttamente\n\n");
							break;

					case 2: system("cls");		//Cambio generi
							do{
								system("cls");
								logo();
								printf("L'attuale genere %c: ", 138);
								SetColor(11);

								for(j=0;j<GENERI_TOT;j++)		//Stampa lista generi dell'artista chiesto in input
								{
									if(ARTISTI[i].genere[j]==1)
									{
										printf("%s  ", lista_generi[j]);
									}
								}
								SetColor(15);


								printf("\nHai a disposizione le seguenti opzioni:\n"
										"[1]Elimina genere\n"
										"[2]Aggiungere genere\n\n"
										"Inserisci l'opzione: ");
								scanf("%s", scelta);
								fflush(stdin);

								if((strcmp(scelta,"1")!=0) && (strcmp(scelta,"2")!=0) )		//Controllo sull'input fornito dall'utente
								{
									system("cls");
									logo();
									SetColor(4);
									printf("Opzione non disponibile!\n\n");
									SetColor(15);
									system("pause");
								}
							}while((strcmp(scelta,"1")!=0) && (strcmp(scelta,"2")!=0));		//Continua fin quando non viene inserito 1 o 2

							system("cls");

							if(strcmp(scelta,"1")==0)		//Elimina genere
							{
								logo();
								printf("L'attuale genere %c: ", 138);
								SetColor(11);

								for(j=0;j<GENERI_TOT;j++)
								{
									if(ARTISTI[i].genere[j]==1)		//Stampa i generi dell'artista chiesto in input
									{
										printf("%s  ", lista_generi[j]);
									}
								}
								SetColor(15);
								printf("\nInserire genere da modificare: ");
								gets(genere);
								fflush(stdin);

								for(j=0;j<GENERI_TOT;j++)
								{
									if(strcmp(lista_generi[j],genere)==0)		//Controllo se il genere inserito esiste
									{
										if(ARTISTI[i].genere[j]==1)		//Controllo se il genere appartiene all'artista
										{
											ARTISTI[i].genere[j]=0;		//Azzeramento genere
											genere_trovato=1;
											j=GENERI_TOT;
										}
										else
										{
											system("cls");
											logo();
											SetColor(4);
											printf("Genere non appartenente all'artista\n\n");
											SetColor(15);
											system("pause");
										}
									}
								}

								if(genere_trovato==0)
								{
									system("cls");
									logo();
									SetColor(4);
									printf("Genere inserito non esistente\n\n");
									SetColor(15);
									system("pause");
								}
								else
								{
									system("cls");
									logo();
									printf("\nGenere eliminato ");
									system("pause");
								}
							}
							else		//Aggiungi genere
							{
								logo();
								printf("L'attuale genere %c: ", 138);
								SetColor(11);

								for(j=0;j<GENERI_TOT;j++)		//Stampa generi appartenenti all'artista
								{
									if(ARTISTI[i].genere[j]==1)
									{
										printf("%s  ", lista_generi[j]);
									}
								}

								SetColor(15);
								printf("\nI generi disponibili sono: ");
								for(j=0;j<GENERI_TOT;j++)		//Stampa tutti i generi disponibili
								{
									if(ARTISTI[i].genere[j]==0)
									{
										printf("%s  ", lista_generi[j]);
									}
								}

								printf("\n\nInserire genere da aggiungere: ");
								gets(genere);
								fflush(stdin);

								for(j=0;j<GENERI_TOT;j++)
								{
									if(strcmp(lista_generi[j],genere)==0)		//Controllo se il genere inserito esiste
									{
										if(ARTISTI[i].genere[j]==0)
										{
											ARTISTI[i].genere[j]=1;
											genere_trovato=1;
										}
										else
										{
											system("cls");
											logo();
											SetColor(4);
											printf("Genere gi%c inserito\n\n", 133);
											SetColor(15);
											system("pause");
										}
									}
								}

								if(genere_trovato==0)		//Controllo sul genere inserito
								{
									system("cls");
									logo();
									SetColor(4);
									printf("Genere inserito non esistente\n\n");
									SetColor(15);
									system("pause");
								}
								else
								{
									system("cls");
									logo();
									printf("\nGenere inserito ");
									system("pause");
								}
							}
							break;


					case 3: system("cls");	//Cambio anno di inzio attivit�
							char anno_provvisorio[LUNGHEZZA_MAX];

							logo();
							printf("L'attuale anno %c: ", 138);
							SetColor(11);
							printf("%d\n\n", ARTISTI[i].anno_inizio);
							SetColor(15);

							do{
								system("cls");
								logo();
								printf("L'attuale anno %c: ", 138);
								SetColor(11);
								printf("%d\n\n", ARTISTI[i].anno_inizio);
								SetColor(15);

								printf("Inserisci nuovo anno: ");
								gets(anno_provvisorio);
								fflush(stdin);
							}while(isControllo_Numero(anno_provvisorio)!=1);

							ARTISTI[i].anno_inizio=atoi(anno_provvisorio);

							printf("Anno inserito!\n\n");

							break;

					case 4: system("cls");		//Cambio produttore
							logo();
							printf("L'attuale produttore %c: ", 138);
							SetColor(11);
							printf("%s\n\n", ARTISTI[i].produttore);
							SetColor(15);
							printf("Inserisci nuovo produttore: ");
							scanf("%s", ARTISTI[i].produttore);
							system("cls");
							logo();
							printf("Anno inserito!\n\n");
							break;

					case 5: system("cls");		//Cambio nazionalit�
							logo();
							printf("L'attuale nazionalit%c %c: ",133, 138);
							SetColor(11);
							printf("%s\n\n", ARTISTI[i].nazionalita);
							SetColor(15);
							printf("Inserisci nuovo produttore: ");
							scanf("%s", ARTISTI[i].nazionalita);
							system("cls");
							logo();
							printf("Anno inserito!\n\n");
							break;
				}

				system("pause");
				i=artisti_effettivi;
			}
		}

		if(artista_trovato==0)		//Artista non trovato
		{
			SetColor(4);
			printf("Artista non trovato!\n\n");
			SetColor(15);
			printf("Vuoi riprovare? Rispondi si o no\n");
			stringclear(scelta);

			do{							//Continua a chiedere l'input fin quando non viene inserito si o no
				gets(scelta);
				fflush(stdin);
				for(j=0;j<LUNGHEZZA_INPUT;j++)
				{
					scelta[j]=tolower(scelta[j]);		//Trasforma in minuscolo in primo carattere
				}
				if((strcmp(scelta,"si")!=0) && (strcmp(scelta,"no")!=0))
				{
					SetColor(4);
					printf("Risposta non accettata! Riprova\n");
					SetColor(15);
				}
			}while((strcmp(scelta,"si")!=0) && (strcmp(scelta,"no")!=0));

		}
		i=0;

	}while(strcmp(scelta,"si")==0);		//Termina quando viene digitato si
}
