#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <CUnit/Basic.h>
#include "funzioni.h"

//Funzione id inizializzazione
int init_suite1(void);

//Funzione di clean up
int clean_suite1(void);

void test_of_isControllo_Numero(void);


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
	CU_add_test(pSuite_A, "test of isControllo_Numero()", test_of_isControllo_Numero);

		CU_basic_set_mode(CU_BRM_VERBOSE);
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

	//Vera per tutti i valori compresi tra 0 e un numero max LUNGHEZZA_MAX di caratteri
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

