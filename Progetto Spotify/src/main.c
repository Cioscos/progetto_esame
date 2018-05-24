#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include "funzioni.h"

//Funzione id inizializzazione
int init_suite1(void);

//Funzione di clean up
int clean_suite1(void);

//Prototipi di funzioni generali
void test_of_isControllo_Numero(void);
void test_of_isControllo_Esistenza(void);

//Prototipi di funzioni artista
void test_of_elimina_artista(void);

int main(int argc, char *argv[]){

	int artisti_effettivi=0;
    int utenti_effettivi=0;
    char relative_path[LUNGHEZZA_PATH]={'\0'};

	creazione_path(argv[0],relative_path);

	gestione_file('r', 0, &artisti_effettivi, relative_path);
	gestione_file('r', 1, &utenti_effettivi, relative_path);
	gestione_file('r', 2, &utenti_effettivi, relative_path);

	CU_initialize_registry();


	CU_pSuite pSuite_A = CU_add_suite("Suite_funzioni_generali", init_suite1,clean_suite1);
	CU_add_test(pSuite_A, "Controllo Numero", test_of_isControllo_Numero);
	CU_add_test(pSuite_A, "Controllo Esistenza", test_of_isControllo_Esistenza);

	CU_pSuite pSuite_B = CU_add_suite("Suite_funzioni_artista", init_suite1,clean_suite1);
	CU_add_test(pSuite_B, "Elimina Artista", test_of_elimina_artista);

	CU_pSuite pSuite_C = CU_add_suite("Suite_funzioni_utente", init_suite1,clean_suite1);



	CU_console_run_tests();
	CU_cleanup_registry();

	system("pause");


	return CU_get_error();
}

//Funzione id inizializzazione
int init_suite1(void){
	return 0;
}

//Funzione di clean up
int clean_suite1(void){
	return 0;
}

void test_of_isControllo_Numero(void){
	//1 INPUT CORRETTO - 0 INPUT NON CORRETTO

	//Vero per tutti i valori compresi tra 0 e un numero max LUNGHEZZA_MAX di caratteri
	CU_ASSERT_EQUAL( isControllo_Numero("0",LUNGHEZZA_MAX), 1);
	CU_ASSERT_EQUAL( isControllo_Numero("99999999999999999999999999999999",LUNGHEZZA_MAX), 1);

	//Vero anche se si inserisce un cattere oltre la 32esima posizione
	CU_ASSERT_EQUAL( isControllo_Numero("99999999999999999999999999999999a",LUNGHEZZA_MAX), 1);

	//Falso se si inserisce un simbolo diverso da una cifra
	CU_ASSERT_EQUAL( isControllo_Numero("ciao",LUNGHEZZA_MAX), 0);
	CU_ASSERT_EQUAL( isControllo_Numero("1ciao",LUNGHEZZA_MAX), 0);
	CU_ASSERT_EQUAL( isControllo_Numero("ciao1",LUNGHEZZA_MAX), 0);
	CU_ASSERT_EQUAL( isControllo_Numero("-",LUNGHEZZA_MAX), 0);

	//Falso quando si inserisce uno spazio
	CU_ASSERT_EQUAL( isControllo_Numero(" ",LUNGHEZZA_MAX), 0);

	//Falso quando non si inserisce nulla
	CU_ASSERT_EQUAL( isControllo_Numero("",LUNGHEZZA_MAX), 0);
}

void test_of_isControllo_Esistenza(void){
	//1 ELEMENTO TROVATO - 0 ELEMENTO NON TROVATO

	//Falso quando viene inserito un artista non presente
	CU_ASSERT_EQUAL( isControllo_Esistenza(ARTISTI_MAX,"xxxx","nome_artista"), 0);
	//Falso quando viene inserito un numero di artisti non corretto
	CU_ASSERT_EQUAL( isControllo_Esistenza(5,"Hardwell","nome_artista"), 0);
	//Falso quando viene inserito un campo di ricerca non corretto
	CU_ASSERT_EQUAL( isControllo_Esistenza(ARTISTI_MAX,"Hardwell","xxxx"), 0);
	//Vero quando viene inserito il numero degli artisti max, il nome di un artista e il campo di ricerca(nome_artista) corretto
	CU_ASSERT_EQUAL( isControllo_Esistenza(ARTISTI_MAX,"Hardwell","nome_artista"), 1);


	//Falso quando viene inserito un codice artista non presente
	CU_ASSERT_EQUAL( isControllo_Esistenza(ARTISTI_MAX,"xxxx","codice_artista"), 0);
	//Falso quando viene inserito un numero di artisti non corretto
	CU_ASSERT_EQUAL( isControllo_Esistenza(5,"0020","codice_artista"), 0);
	//Falso quando viene inserito un campo di ricerca non corretto
	CU_ASSERT_EQUAL( isControllo_Esistenza(ARTISTI_MAX,"0020","xxxx"), 0);
	//Vero quando viene inserito il numero degli artisti max, il codice di un artista e il campo di ricerca(nome_artista) corretto
	CU_ASSERT_EQUAL( isControllo_Esistenza(ARTISTI_MAX,"0020","codice_artista"), 1);


	//Falso quando viene inserito un nickname non presente
	CU_ASSERT_EQUAL( isControllo_Esistenza(UTENTI_MAX,"xxxx","nickname_utente"), 0);
	//Falso quando viene inserito un numero di utenti non corretto
	CU_ASSERT_EQUAL( isControllo_Esistenza(5,"DaftGot","nickname_utente"), 0);
	//Falso quando viene inserito un campo di ricerca non corretto
	CU_ASSERT_EQUAL( isControllo_Esistenza(UTENTI_MAX,"DaftGot","xxxx"), 0);
	//Vero quando viene inserito il numero degli utenti max, il nome di un utente e il campo di ricerca(nome_artista) corretto
	CU_ASSERT_EQUAL( isControllo_Esistenza(UTENTI_MAX,"DaftGot","nickname_utente"), 1);
}

void test_of_elimina_artista(void){

	int artisti_effettivi=22;

	//Vero quando viene dato il numero degli artisti_effettivi e la posizione dell'artista da eliminare
	CU_ASSERT_EQUAL( elimina_artista(artisti_effettivi,10), artisti_effettivi-1);


}

int elimina_utente(int utenti_effettivi, int posizione_utente)



