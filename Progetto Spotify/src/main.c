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

void test_Somma(void);

int main(int argc, char *argv[]){

	CU_initialize_registry();



//	CU_pSuite pSuite_A = CU_add_suite("Suite_Somma", init_suite1,clean_suite1);
//	CU_add_test(pSuite_A, "test of somma()", test_Somma);

		CU_basic_set_mode(CU_BRM_VERBOSE);
			CU_console_run_tests();
		CU_cleanup_registry();

		system("pause");

		return CU_get_error();
}

//Funzione id inizializzazione
int init_suite1(void){
	return 0; //nessuna inizializzzazione
}

//Funzione di clean up
int clean_suite1(void){
	return 0; //nessun cleanup
}

/*
void test_Somma(void){

	CU_ASSERT_EQUAL( somma(50, 50), 100);
	CU_ASSERT_EQUAL( somma(0, 0), 0);
}
*/
