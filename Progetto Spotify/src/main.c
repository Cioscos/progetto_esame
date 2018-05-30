#include <CUnit/Console.h>
#include <CUnit/CUError.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <stdlib.h>

#include "funzioni.h"

//Funzione id inizializzazione
int init_suite1(void);

//Funzione di clean up
int clean_suite1(void);

//Prototipi di funzioni generali
void test_of_isControllo_Numero(void);
void test_of_isControllo_Esistenza(void);
void test_of_eliminazione_acapo(void);
void test_of_ordinamento_crescente(void);

//Prototipi di funzioni artista
void test_of_elimina_artista(void);

//Prototipi di funzioni utenti
void test_of_elimina_utente(void);

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
	CU_add_test(pSuite_A, "Eliminazione a capo", test_of_eliminazione_acapo);
	CU_add_test(pSuite_A, "Ordinamento Creascente", test_of_ordinamento_crescente);

	CU_pSuite pSuite_B = CU_add_suite("Suite_funzioni_artista", init_suite1,clean_suite1);
	CU_add_test(pSuite_B, "Elimina Artista", test_of_elimina_artista);

	CU_pSuite pSuite_C = CU_add_suite("Suite_funzioni_utente", init_suite1,clean_suite1);
	CU_add_test(pSuite_C, "Elimina Utente", test_of_elimina_utente);


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

void test_of_eliminazione_acapo(void){

	//Vero quando inserisco una parola
	CU_ASSERT_STRING_EQUAL( eliminazione_acapo("vito\n"), "vito");

	//Vero quando inserisco una parola senza \n
	CU_ASSERT_STRING_EQUAL( eliminazione_acapo("vito"), "vito");

	//Vero quando inserisco una frase
	CU_ASSERT_STRING_EQUAL( eliminazione_acapo("vito ciao a tutti\n"), "vito ciao a tutti");

	//Vero quando inserisco stringa vuota
	CU_ASSERT_STRING_EQUAL( eliminazione_acapo("   "), "   ");

	//Vero quando inserisco solo \n
	CU_ASSERT_STRING_EQUAL( eliminazione_acapo("\n"), "");
}

void test_of_ordinamento_crescente(void){

	//Vero quando inserisco un vettore  ordinato
	int vet1[5]={1,2,3,4,5};
	CU_ASSERT_EQUAL( ordinamento_crescente(vet1,5), 1);

	//Vero quando inserisco un vettore disordinato
	int vet2[5]={5,4,3,2,1};
	CU_ASSERT_EQUAL( ordinamento_crescente(vet2,5), 1);

	//Vero quando inserisco un vettore di un singolo elemento
	int vet3[1]={5};
	CU_ASSERT_EQUAL( ordinamento_crescente(vet3,1), 1);

	//Vero quando inserisco un vettore di con gli elementi dello stesso valore
	int vet4[5]={2,2,2,2,2};
	CU_ASSERT_EQUAL( ordinamento_crescente(vet4,5), 1);

	/*è necessario fornire la dimensione corretta del vettore poichè*/

	//Vero anche quando si fornisce una dimensione errata più grande
	int vet5[5]={1,2,3,4,5};
	CU_ASSERT_EQUAL( ordinamento_crescente(vet5,6), 1);

	//Vero anche quando si fornisce una dimensione errata più piccola
	int vet6[5]={1,2,3,4,5};
	CU_ASSERT_EQUAL( ordinamento_crescente(vet6,4), 1);

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

void test_of_elimina_utente(void){

	int utenti_effettivi=10;

	//Vero quando viene dato il numero degli utenti_effettivi e la posizione dell'utente da eliminare
	CU_ASSERT_EQUAL( elimina_utente(utenti_effettivi,10), utenti_effettivi-1);


}




