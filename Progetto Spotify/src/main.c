#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main(int argc, char *argv[]){

	char input_utente[LUNGHEZZA_INPUT]={"1"};		//Variabile contenente l'input dell'utente

	char lista_generi[GENERI_TOT][LUNGHEZZA_MAX]={"Electro","Pop","Techno","Rock","Jazz","Rap","Blues","Country","Britpop","Dubstep"};


	int artisti_effettivi=0;

	while(strcmp(input_utente,"0")!=0)		//Permette di eseguire più opreazioni fin quando non viene inserito uno 0, ovvero l'opzione termina programma
	{
		flag=1;
		do{
			controllo_menu(input_utente,MENU_PRINCIPALE);
		}while(isControllo_Numero(input_utente)!=1);		//Controllo sull'input dell'utente fin quando non viene digitato una cifra

		switch(atoi(input_utente))		//Funzione atoi converta da stringa a intero
		{

			case 0:	system("cls");
					logo();
					printf("Programma terminato\n");
					break;

			case 1:	system("cls");
					while(strcmp(input_utente,"0")!=0)
					{
						flag=1;
						do{
							controllo_menu(input_utente,MENU_ARTISTA);
						}while(isControllo_Numero(input_utente)!=1);		//Controllo sull'input dell'utente fin quando non viene digitato una cifra

						switch(atoi(input_utente))
						{
							case 0: system("cls");
									logo();
									break;

							case 1:	system("cls");
									logo();
									printf("Caso 1 selezionato\n");
									system("PAUSE");
									break;

							case 2:	system("cls");		//DEVO LAVORARE QUI

/*------------------------------------------------------------------------------------------------*/
									logo();		//nome artista
									printf("Inserisci nome artista:");
									gets(ARTISTI[artisti_effettivi].nome);
									fflush(stdin);
									system("cls");


									do{		//codice artista
										system("cls");
										logo();
										printf("Inserisci codice artista di lunghezza 4:");
										gets(ARTISTI[artisti_effettivi].codice);
										fflush(stdin);
									}while(strlen(ARTISTI[artisti_effettivi].codice)!=LUNGHEZZA_CODICE /* && Fare una funzione che controlla se il codice è già stato utlizzato */);



									int posizione_genere=0;					//pozione del genere nel vettore lista_generi
									char genere_provvisorio[LUNGHEZZA_MAX];
									int genere_esistente=GENERI_TOT;		//0 genere non esistente 1 genere esistente
									char risposta[LUNGHEZZA_INPUT]={"si"};			//Risposta alla domanda 'Vuoi inserire un'altra preferenza?'

									do{		//Inserimento generi fin quando non viene digitato no
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
											printf("Vuoi inserire un'altra preferenza?\nRispondere con si o no:");
											scanf("%3s",risposta);
											fflush(stdin);		//Svuota flusso in input
										}while(strcmp(risposta,"si")!=0 && strcmp(risposta,"no")!=0);

									}while(strcmp(risposta,"si")==0);


									system("cls");
									logo();
									printf("Inserisci produttore:");
									gets(ARTISTI[artisti_effettivi].produttore);
									fflush(stdin);

									system("cls");
									logo();
									printf("Inserisci nazionalita:");
									gets(ARTISTI[artisti_effettivi].nazionalita);
									fflush(stdin);


									char anno_provvisorio[LUNGHEZZA_MAX];
									do{
										system("cls");
										logo();
										printf("Inserisci anno di inizio:");
										gets(anno_provvisorio);
										fflush(stdin);
									}while(isControllo_Numero(anno_provvisorio)!=1);
									ARTISTI[artisti_effettivi].anno_inizio=atoi(anno_provvisorio);

/*------------------------------------------------------------------------------------------------*/
									system("PAUSE");
									break;

							case 3:	system("cls");
									logo();
									printf("Caso 3 selezionato\n");
									system("PAUSE");
									break;

							case 4:	system("cls");
									logo();
									printf("Caso 4 selezionato\n");
									system("PAUSE");
									break;

							default : 	system("cls");
										logo();
										printf("Comando errato, inserisci un valore corretto\a\n");
										system("PAUSE");
						}
					}
					strcpy(input_utente,"1");            //Permette di rientrare nel menu principale
					system("PAUSE");
					break;

			case 2:	system("cls");
					while(strcmp(input_utente,"0")!=0)
					{
						flag=1;
						do{
							controllo_menu(input_utente,MENU_UTENTE);
						}while(isControllo_Numero(input_utente)!=1);		//Controllo sull'input dell'utente fin quando non viene digitato una cifra

						switch(atoi(input_utente))
						{
							case 0: system("cls");
									logo();
									break;

							case 1:	system("cls");
									logo();
									printf("Caso 1 selezionato\n");
									system("PAUSE");
									break;

							case 2:	system("cls");
									logo();
									printf("Caso 2 selezionato\n");
									system("PAUSE");
									break;

							case 3:	system("cls");
									logo();
									printf("Caso 3 selezionato\n");
									system("PAUSE");
									break;

							case 4:	system("cls");
									logo();
									printf("Caso 4 selezionato\n");
									system("PAUSE");
									break;

							case 5:	system("cls");
									logo();
									printf("Caso 5 selezionato\n");
									system("PAUSE");
									break;

							case 6:	system("cls");
									logo();
									printf("Caso 6 selezionato\n");
									system("PAUSE");
									break;

							case 7:	system("cls");
									logo();
									printf("Caso 7 selezionato\n");
									system("PAUSE");
									break;

							case 8:	system("cls");
									logo();
									printf("Caso 8 selezionato\n");
									system("PAUSE");
									break;

							default : 	system("cls");
										logo();
										printf("Comando errato, inserisci un valore corretto\a\n");
										system("PAUSE");
						}
					}
					strcpy(input_utente,"1");            //Permette di rientrare nel menu principale
					system("PAUSE");
					break;

			case 3:	system("cls");
					printf("Hai selezionato 3\n");
					system("PAUSE");
					break;

			default : 	system("cls");
						logo();
						printf("Comando errato, inserisci un valore corretto\a\n");
						system("PAUSE");
		}

	}

system("PAUSE");
return 0;
}


