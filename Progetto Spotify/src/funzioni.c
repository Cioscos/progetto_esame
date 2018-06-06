#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include "funzioni.h"

void SetColor(short Color) {
	/*	1 = Blue 2 = Green 3 = Light Blue 4 = Red 5 = Purple
	 6 = Orange/Brown 7 = White 8 = Grey 9 = Blue
	 10 = Green 11 = Light Blue 12 = Pink/Red 13 = Purple
	 14 = Yellow 15 = White	*/
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); /*HANDLE=Puntatore "opaco";gli viene assegnato
	 *un valore da una funzione
	 *GetStdHandle=restituisce a HANDLE un dispositivo
	 *standard (STD_OUTPUT_HANDLE)*/
	SetConsoleTextAttribute(hCon, Color);
}

void logo() {
	SetColor(2);
	printf("   _____                   _     _    __         \n"
			"  / ____|                 | |   (_)  / _|        \n"
			" | (___    _ __     ___   | |_   _  | |_   _   _ \n"
			"  \\___ \\  | '_ \\   / _ \\  | __| | | |  _| | | | |\n"
			"  ____) | | |_) | | (_) | | |_  | | | |   | |_| |\n"
			" |_____/  | .__/   \\___/   \\__| |_| |_|    \\__, |\n"
			"          | |                               __/ |\n"
			"          |_|        TEST                  |___/   %c\n\n\n", 169);
	SetColor(15);
}

void stampa_menu_principale() {
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

void stampa_menu_artista() {
	SetColor(2);
	printf("[1]");
	SetColor(15);
	printf("Visualizza artisti\n");
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

void stampa_menu_secondario() {
	SetColor(2);
	printf("[1]");
	SetColor(15);
	printf("Registrati a Spotify!\n");
	SetColor(2);
	printf("[2]");
	SetColor(15);
	printf("Accedi a Spotify!\n");
	SetColor(2);
	printf("[0]");
	SetColor(15);
	printf("Torna al menu principale\n\nInserisci comndo: ");
}

void stampa_menu_utente() {
	SetColor(2);
	printf("[1]");
	SetColor(15);
	printf("Visualizza il tuo Account\n");
	SetColor(2);
	printf("[2]");
	SetColor(15);
	printf("Ascolta artisti\n");
	SetColor(2);
	printf("[3]");
	SetColor(15);
	printf("Modifica il tuo profilo\n");
	SetColor(2);
	printf("[4]");
	SetColor(15);
	printf("Eliminati da Spotify\n");
	SetColor(2);
	printf("[0]");
	SetColor(15);
	printf("Disconnetti\n\nInserisci comando: ");
}

int isControllo_Numero(char appoggio[], int lunghezza_massima) {
	int i = 0;
	int input_valido = 0;			//1 Input valido - 0 Input non valido
	int lughezza_effettiva = 0;	//Numero caratteri effettivi

	while (i < lunghezza_massima)		//Conta numero effettivo di caratteri
	{
		if (appoggio[i] != '\0')
		{
			lughezza_effettiva++;
			i++;
		}else
		{
			i = lunghezza_massima;
		}
	}
	i = 0;

	for (i = 0; i < lughezza_effettiva; i++)//Controllo se l'input è diverso da un numero
	{
		if ((isdigit(appoggio[i]) != 0) || (appoggio[i] == '\0'))
		{
			input_valido = 1;
		}else
		{
			input_valido = 0;
			i = lughezza_effettiva;
		}
	}

	if (lunghezza_massima == 3)	//Ulteriore controllo su i casi limite di 01-10-00-0'\0'
	{
		if ((appoggio[0] == '0' && appoggio[1] != '0')
		        || (appoggio[0] != '0' && appoggio[1] == '0')
		        || (appoggio[0] == '0' && appoggio[1] == '0'))
		{
			if ((appoggio[0] == '0' && appoggio[1] != '\0'))
				input_valido = 0;
		}
	}

	if (input_valido == 1)//Ritorna il valore 1 se la striga era corretta oppure ritorna il valore 0 se la stringa non era corretta
	{
		return 1;		//Input corretto
	}else
	{
		return 0;		//Input non corretto
	}
}

void controllo_menu(char* input_utente, unsigned int menu) {
	if (flag == 1)		//Comando input accettato
	{
		system("cls");
		logo();
		switch (menu)		//Scelta del menu da stampare
		{
		case MENU_PRINCIPALE:
			stampa_menu_principale();
			break;

		case MENU_ARTISTA:
			stampa_menu_artista();
			break;

		case MENU_UTENTE:
			stampa_menu_utente();
			break;

		case MENU_SECONDARIO:
			stampa_menu_secondario();
			break;
		}
		stringclear(input_utente, LUNGHEZZA_MAX);
		fgets(input_utente,LUNGHEZZA_MAX,stdin);
		eliminazione_acapo(input_utente);
		fflush(stdin);		//Svuota flusso in input
		flag = 0;
	}else	//Comando input non accettato
	{
		system("cls");
		logo();
		SetColor(4);
		printf("Comando errato, inserisci un valore corretto\a\n\n");
		SetColor(15);
		system("PAUSE");
		system("cls");

		logo();
		switch (menu)		//Scelta del menu da stampare
		{
		case MENU_PRINCIPALE:
			stampa_menu_principale();
			break;

		case MENU_ARTISTA:
			stampa_menu_artista();
			break;

		case MENU_UTENTE:
			stampa_menu_utente();
			break;

		case MENU_SECONDARIO:
			stampa_menu_secondario();
			break;
		}
		fgets(input_utente,LUNGHEZZA_MAX,stdin);
		eliminazione_acapo(input_utente);
		fflush(stdin);		//Svuota flusso in input
	}
}

int ordinamento_crescente(int vett[],int dim)
{
	int i,x;
	int p=0;
	int flag=0;
	int ordinato=1;		//1 vettore ordinato - 0 vettore non ordinato

	while(p<dim-1 && flag!=1)
	{
		p++;
		flag=1;

		for(i=dim-1;i>=p;i--)
		{
			if(vett[i]<vett[i-1])
			{
				x=vett[i];
				vett[i]=vett[i-1];
				vett[i-1]=x;

				flag=0;
			}

		}
	}

	for(i=1;i<dim;i++)		//Controllo se il vettore Ã¨ stato ordinato
	{
		if(vett[i-1]<=vett[i])
		{

		}
		else
		{
			ordinato=0;
			i=dim;
		}
	}

	return ordinato;
}

char* eliminazione_acapo(char *input) {

	char *stringa;
	stringa=malloc(LUNGHEZZA_MAX * sizeof(char));

	strcpy(stringa, input);

	int i;

	for (i = 0; i < LUNGHEZZA_MAX; i++)
	{
		if (stringa[i] == '\n')
			stringa[i] = '\0';
	}

	return (stringa);
}

int isControllo_Esistenza(int numero_presenze, char* campo, char* controllo) {
	int i;
	int presenza = 0;		//0 elemento già presente - 1 elemento non presente

	if (strcmp(controllo, "nome_artista") == 0)
	{
		for (i = 0; i < numero_presenze; i++)
		{
			if (strcmp(campo, ARTISTI[i].nome) == 0)
			{
				presenza = 1;
			}
		}
	}

	if (strcmp(controllo, "codice_artista") == 0)
	{
		for (i = 0; i < numero_presenze; i++)
		{
			if (strcmp(campo, ARTISTI[i].codice) == 0)
			{
				presenza = 1;
			}
		}
	}

	if (strcmp(controllo, "nickname_utente") == 0)
	{
		for (i = 0; i < numero_presenze; i++)
		{
			if (strcmp(campo, UTENTI[i].nickname) == 0)
			{
				presenza = 1;
			}
		}
	}


	return presenza;

}

void gestione_file(char modalita, int tipo, int *numero, char relative_path[]) {
	int i = 0, j, k;
	char buffer[LUNGHEZZA_BUFFER] = { '\0' };
	char *token;
	char virgola[2] = { "," };
	char barra[2] = { "/" };
	char itoa_bf[5] = { '\0' };
	char lista_generi[GENERI_TOT][LUNGHEZZA_MAX] = { "N.A.", "Electro", "Pop",
	        "Techno", "Rock", "Jazz", "Rap", "Blues", "Country", "Britpop",
	        "Dubstep", "EDM", "Hip-Hop", "House", "Musica leggera", "Trap",
	        "Trance", "Disco", "Dance" };
	char artisti_path[LUNGHEZZA_PATH] = { '\0' };
	char preferenze_path[LUNGHEZZA_PATH] = { '\0' };
	char utenti_path[LUNGHEZZA_PATH] = { '\0' };
	int controllo_parametri=0;	//Controllo sui parametri d'ingresso  0 paramentri non corretti | 1 parametri corretti

	//CREO PATH ARTISTI
	strcpy(artisti_path, relative_path);
	strcat(artisti_path, "artisti.txt");

	//CREO PATH PREFERENZE
	strcpy(preferenze_path, relative_path);
	strcat(preferenze_path, "preferenze.txt");

	//CREO PATH UTENTI
	strcpy(utenti_path, relative_path);
	strcat(utenti_path, "utenti.txt");

	if (modalita == 'r' && tipo == 0)		//Lettura artisti da file
	{
		controllo_parametri=1;
		FILE *pf;

		pf = fopen(artisti_path, "r");

		if (pf != NULL)
		{
			i = 0;

			while (!feof(pf))
			{
				fgets(buffer, LUNGHEZZA_BUFFER, pf);

				token = strtok(buffer, virgola);
				strcpy(ARTISTI[i].codice, token);

				token = strtok(NULL, virgola);
				strcpy(ARTISTI[i].nome, token);

				token = strtok(NULL, virgola);
				strcpy(ARTISTI[i].produttore, token);

				token = strtok(NULL, virgola);
				strcpy(ARTISTI[i].nazionalita, token);

				token = strtok(NULL, virgola);
				ARTISTI[i].anno_inizio = atoi(token);

				token = strtok(NULL, virgola);
				ARTISTI[i].ascolti = atoi(token);

				token = strtok(NULL, virgola);
				ARTISTI[i].preferenze = atoi(token);

				token = strtok(NULL, virgola);
				eliminazione_acapo(token);

				for (k = 0; k < GENERI_TOT; k++)
				{
					for (j = 0; j < GENERI_TOT; j++)
					{
						if (strcmp(lista_generi[j], token) == 0)
						{
							ARTISTI[i].genere[j] = 1;
							j = GENERI_TOT;
							if ((token = strtok(NULL, virgola)) == NULL)
							{
								k = GENERI_TOT;
							}else
							{
								eliminazione_acapo(token);
							}
						}
					}
				}

				i++;
				*numero += 1;
			}
			fclose(pf);
		}else
		{
			SetColor(4);
			printf("\n\aErrore nella lettura artisti da file\n");
			SetColor(15);
			system("pause");
			fclose(pf);
		}
	}

	if (modalita == 'a' && tipo == 0)		//Inserimento di un artista su file
	{
		controllo_parametri=1;
		FILE *pf;

		pf = fopen(artisti_path, "a");

		if (pf != NULL)
		{
			*numero -= 1;

			strcpy(buffer, "\n");
			strcat(buffer, ARTISTI[*numero].codice);
			strcat(buffer, virgola);

			strcat(buffer, ARTISTI[*numero].nome);
			strcat(buffer, virgola);

			strcat(buffer, ARTISTI[*numero].produttore);
			strcat(buffer, virgola);

			strcat(buffer, ARTISTI[*numero].nazionalita);
			strcat(buffer, virgola);

			sprintf(itoa_bf, "%d", ARTISTI[*numero].anno_inizio);
			strcat(buffer, itoa_bf);
			strcat(buffer, virgola);

			sprintf(itoa_bf, "%d", ARTISTI[*numero].ascolti);
			strcat(buffer, itoa_bf);
			strcat(buffer, virgola);

			sprintf(itoa_bf, "%d", ARTISTI[*numero].preferenze);
			strcat(buffer, itoa_bf);
			strcat(buffer, virgola);

			for (i = 0; i < GENERI_TOT; i++)
			{
				if (ARTISTI[*numero].genere[i] == 1)
				{
					strcat(buffer, lista_generi[i]);
					strcat(buffer, virgola);
				}
			}

			buffer[strlen(buffer) - 1] = '\0';

			fprintf(pf, "%s", buffer);

			*numero += 1;
			fclose(pf);
		}else
		{
			SetColor(4);
			printf("\n\aErrore nell'nserimento di un artista su file\n");
			SetColor(15);
			system("pause");
			fclose(pf);
		}
	}

	if (modalita == 'w' && tipo == 0)		//Inserimento degli artisti su file
	{
		controllo_parametri=1;
		FILE *pf;

		pf = fopen(artisti_path, "w");

		if (pf != NULL)
		{
			for (j = 0; j < *numero; j++)
			{
				if (j > 0)
				{
					strcpy(buffer, "\n");
					strcat(buffer, ARTISTI[j].codice);
					strcat(buffer, virgola);
				}else
				{
					strcpy(buffer, ARTISTI[j].codice);
					strcat(buffer, virgola);
				}

				strcat(buffer, ARTISTI[j].nome);
				strcat(buffer, virgola);

				strcat(buffer, ARTISTI[j].produttore);
				strcat(buffer, virgola);

				strcat(buffer, ARTISTI[j].nazionalita);
				strcat(buffer, virgola);

				sprintf(itoa_bf, "%d", ARTISTI[j].anno_inizio);
				strcat(buffer, itoa_bf);
				strcat(buffer, virgola);

				sprintf(itoa_bf, "%d", ARTISTI[j].ascolti);
				strcat(buffer, itoa_bf);
				strcat(buffer, virgola);

				sprintf(itoa_bf, "%d", ARTISTI[j].preferenze);
				strcat(buffer, itoa_bf);
				strcat(buffer, virgola);

				for (i = 0; i < GENERI_TOT; i++)
				{
					if (ARTISTI[j].genere[i] == 1)
					{
						strcat(buffer, lista_generi[i]);
						strcat(buffer, virgola);
					}
				}

				buffer[strlen(buffer) - 1] = '\0';

				fprintf(pf, "%s", buffer);
			}
			fclose(pf);
		}else
		{
			SetColor(4);
			printf("\n\aErrore nell'nserimento degli artisti su file\n");
			SetColor(15);
			system("pause");
			fclose(pf);
		}
	}

	if (modalita == 'r' && tipo == 1)		//Lettura di utenti da file
	{
		controllo_parametri=1;
		FILE *pf;

		pf = fopen(utenti_path, "r");

		if (pf != NULL)
		{
			i = 0;

			while (!feof(pf))
			{
				fgets(buffer, LUNGHEZZA_BUFFER, pf);

				token = strtok(buffer, virgola);
				strcpy(UTENTI[i].nickname, token);

				token = strtok(NULL, virgola);
				strcpy(UTENTI[i].password, token);

				token = strtok(NULL, virgola);
				strcpy(UTENTI[i].nome, token);

				token = strtok(NULL, virgola);
				strcpy(UTENTI[i].cognome, token);

				token = strtok(NULL, barra);
				UTENTI[i].data_nascita.giorno = atoi(token);

				token = strtok(NULL, barra);
				UTENTI[i].data_nascita.mese = atoi(token);

				token = strtok(NULL, virgola);
				UTENTI[i].data_nascita.anno = atoi(token);

				token = strtok(NULL, barra);
				UTENTI[i].data_iscrizione.giorno = atoi(token);

				token = strtok(NULL, barra);
				UTENTI[i].data_iscrizione.mese = atoi(token);

				token = strtok(NULL, barra);
				UTENTI[i].data_iscrizione.anno = atoi(token);

				i++;
				*numero += 1;
			}
			fclose(pf);
		}else
		{
			SetColor(4);
			printf("\n\aErrore nella lettura di utenti da file\n");
			SetColor(15);
			system("pause");
			fclose(pf);
		}
	}

	if (modalita == 'a' && tipo == 1)		//Inserimento di un utente su file
	{
		controllo_parametri=1;
		FILE *pf;

		pf = fopen(utenti_path, "a");

		if (pf != NULL)
		{
			*numero -= 1;

			strcpy(buffer, "\n");
			strcat(buffer, UTENTI[*numero].nickname);
			strcat(buffer, virgola);

			strcat(buffer, UTENTI[*numero].password);
			strcat(buffer, virgola);

			strcat(buffer, UTENTI[*numero].nome);
			strcat(buffer, virgola);

			strcat(buffer, UTENTI[*numero].cognome);
			strcat(buffer, virgola);

			sprintf(itoa_bf, "%d", UTENTI[*numero].data_nascita.giorno);
			strcat(buffer, itoa_bf);
			strcat(buffer, barra);

			sprintf(itoa_bf, "%d", UTENTI[*numero].data_nascita.mese);
			strcat(buffer, itoa_bf);
			strcat(buffer, barra);

			sprintf(itoa_bf, "%d", UTENTI[*numero].data_nascita.anno);
			strcat(buffer, itoa_bf);
			strcat(buffer, barra);
			strcat(buffer, virgola);

			sprintf(itoa_bf, "%d", UTENTI[*numero].data_iscrizione.giorno);
			strcat(buffer, itoa_bf);
			strcat(buffer, barra);

			sprintf(itoa_bf, "%d", UTENTI[*numero].data_iscrizione.mese);
			strcat(buffer, itoa_bf);
			strcat(buffer, barra);

			sprintf(itoa_bf, "%d", UTENTI[*numero].data_iscrizione.anno);
			strcat(buffer, itoa_bf);

			fprintf(pf, "%s", buffer);

			*numero += 1;
			fclose(pf);
		}else
		{
			SetColor(4);
			printf("\n\aErrore nell'nserimento di un utente su file\n");
			SetColor(15);
			system("pause");
			fclose(pf);
		}
	}

	if (modalita == 'w' && tipo == 1)		//Inserimento degli utenti su file
	{
		controllo_parametri=1;
		FILE *pf;

		pf = fopen(utenti_path, "w");

		i = 0;

		if (pf != NULL)
		{
			for (i = 0; i < *numero; i++)
			{
				if (i > 0)
				{
					strcpy(buffer, "\n");
					strcat(buffer, UTENTI[i].nickname);
					strcat(buffer, virgola);
				}else
				{
					strcpy(buffer, UTENTI[i].nickname);
					strcat(buffer, virgola);
				}

				strcat(buffer, UTENTI[i].password);
				strcat(buffer, virgola);

				strcat(buffer, UTENTI[i].nome);
				strcat(buffer, virgola);

				strcat(buffer, UTENTI[i].cognome);
				strcat(buffer, virgola);

				sprintf(itoa_bf, "%d", UTENTI[i].data_nascita.giorno);
				strcat(buffer, itoa_bf);
				strcat(buffer, barra);

				sprintf(itoa_bf, "%d", UTENTI[i].data_nascita.mese);
				strcat(buffer, itoa_bf);
				strcat(buffer, barra);

				sprintf(itoa_bf, "%d", UTENTI[i].data_nascita.anno);
				strcat(buffer, itoa_bf);
				strcat(buffer, barra);
				strcat(buffer, virgola);

				sprintf(itoa_bf, "%d", UTENTI[i].data_iscrizione.giorno);
				strcat(buffer, itoa_bf);
				strcat(buffer, barra);

				sprintf(itoa_bf, "%d", UTENTI[i].data_iscrizione.mese);
				strcat(buffer, itoa_bf);
				strcat(buffer, barra);

				sprintf(itoa_bf, "%d", UTENTI[i].data_iscrizione.anno);
				strcat(buffer, itoa_bf);

				fprintf(pf, "%s", buffer);

			}
			fclose(pf);
		}else
		{
			SetColor(4);
			printf("\n\aErrore nell'inserimento degli utenti su file\n");
			SetColor(15);
			system("pause");
			fclose(pf);
		}
	}

	if (modalita == 'w' && tipo == 2)
	{
		controllo_parametri=1;
		FILE *pf;

		pf = fopen(preferenze_path, "w");

		if (pf != NULL)
		{

			int primo = 0;
			int nome_scritto = 0;

			if (pf != NULL)
			{
				for (i = 0; i < UTENTI_MAX; i++)//Effettuo l'inserimento delle preferenze per tutti gli utenti
				{
					nome_scritto = 0;
					for (j = 0; j < ARTISTI_MAX; j++)//Inserisco anche la preferenza di un utente che Ã¨ stato eliminato
					{
						if (UTENTI[i].preferenze[j] != 0)//Controllo se l'utente ha espresso una preferenza
						{
							for (k = 0; k < ARTISTI_MAX; k++)
							{

								if (strcmp(UTENTI[i].codice_artista[j], ARTISTI[k].codice)
								        == 0)//Controllo se l'artista è ancora presente
								{
									if (nome_scritto == 0)
									{
										if (primo != 0)
										{
											strcpy(buffer, "\n");
											strcat(buffer, UTENTI[i].nickname);
											strcat(buffer, barra);
										}else
										{
											strcpy(buffer, UTENTI[i].nickname);
											strcat(buffer, barra);
											primo = 1;
										}
										nome_scritto = 1;
									}

									strcat(buffer, UTENTI[i].codice_artista[j]);
									strcat(buffer, virgola);
									sprintf(itoa_bf, "%d", UTENTI[i].preferenze[j]);
									strcat(buffer, itoa_bf);
									strcat(buffer, barra);

									k = ARTISTI_MAX;
								}
							}

						}
					}
					if (nome_scritto == 1)
					{
						fprintf(pf, "%s", buffer);
					}

				}

			}
			fclose(pf);

		}else
		{
			SetColor(4);
			printf("\n\aErrore nell'nserimento delle preferenze su file\n");
			SetColor(15);
			system("pause");
			fclose(pf);
		}
	}

	if (modalita == 'r' && tipo == 2) //Legge preferenze da file
	{
		controllo_parametri=1;
		FILE *pf;

		pf = fopen(preferenze_path, "r");

		int utente_presente;
		int pos_utenti_con_preferenze = 0;
		if (pf != NULL)
		{
			i = 0;

			while (!feof(pf))
			{
				utente_presente = 0;
				j = 0;
				fgets(buffer, LUNGHEZZA_BUFFER, pf);

				if ((token = strtok(buffer, barra)) != NULL)  //Contiene il nome
				{
					for (i = 0; i < *numero; i++)
					{
						if (strcmp(UTENTI[i].nickname, token) == 0) //Individua la posizione dell'utente
						{
							pos_utenti_con_preferenze = i;
							utente_presente = 1;
							for (j = 0; j < ARTISTI_MAX; j++) //Azzeramento Vettore preferenze e codici_artisti
							{
								UTENTI[i].preferenze[j] = 0;
								strcpy(UTENTI[i].codice_artista[j], "0000");
							}

							for (k = 0; k < ARTISTI_MAX; k++)
							{
								if ((token = strtok(NULL, virgola)) != NULL) //Contiene il codice
								{
									for (j = 0; j < ARTISTI_MAX; j++)
									{
										if (strcmp(ARTISTI[j].codice, token)
										        == 0) //Controllo se il codice Ã¨ ancora presente
										{
											strcpy(UTENTI[i].codice_artista[k], ARTISTI[j].codice);
											token = strtok(NULL, barra); //Contiene la barra
											UTENTI[i].preferenze[k] =
											        atoi(token);
											j =
											ARTISTI_MAX;
										}
									}
								}else
								{
									i = *numero;
									k = ARTISTI_MAX;
								}
							}
						}
					}
					if (utente_presente == 0)
					{
						for (i = pos_utenti_con_preferenze; i < UTENTI_MAX; i++)
						{
							for (j = 0; j < ARTISTI_MAX; j++) //Azzeramento Vettore preferenze e codici_artisti
							{
								UTENTI[i].preferenze[j] = 0;
								strcpy(UTENTI[i].codice_artista[j], "0000");
							}
						}
					}
				}
			}
			fclose(pf);
		}else
		{
			SetColor(4);
			printf("\n\aErrore nel passaggio dei parametri\n");
			SetColor(15);
			system("pause");
			fclose(pf);
		}
	}

	if(controllo_parametri==0)		//Stampa messaggio di errore quando i parametri non sono corretti
	{
		SetColor(4);
		printf("\n\aErrore nella lettura delle preferenze da file\n");
		SetColor(15);
		system("pause");
	}

}

void creazione_path(char* token_buffer, char* relative_path) {
	char unita_path[LUNGHEZZA_PATH] = { '\0' };
	char *token;
	int i = 0;  	//Permette di gestire l'if nel while
	int k = 1;           //Permette di entrare nel while

	while ((k == 1) || (strcmp("Progetto Spotify", unita_path) != 0))
	{
		if (i == 0)
		{
			token = strtok(token_buffer, "\\");
			strcpy(unita_path, token);
			strcpy(relative_path, unita_path);
			strcat(relative_path, "\\");
		}else
		{
			token = strtok(NULL, "\\");
			strcpy(unita_path, token);
			strcat(relative_path, unita_path);
			strcat(relative_path, "\\");
		}
		i++;
		k++;
	}

	strcat(relative_path, "File\\");

}

int isControllo_Lettera(char stringa[], int DIMENSIONE_MAX){

    unsigned int i, input_valido=0;
    unsigned int lettera_reale=0;	//Diventa 1 solo se trova effettivamente un carattere

    for(i=0;i<(strlen(stringa));i++)
    {
        if(isalpha(stringa[i])!=0)
        {
            input_valido=1;
            lettera_reale=1;
        }
        else
        {
            if(stringa[i]=='\0' || stringa[i]==32)  //32 spazio in ASCII
            {
                input_valido=1;
            }
            else
            {
                input_valido=0;
                i=DIMENSIONE_MAX;
            }
        }
    }

    if(input_valido==1 && lettera_reale==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
