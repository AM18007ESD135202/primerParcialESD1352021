
#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../prototipos.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testCarga_datos() {
 char* nombre_del_archivo = "datos/peliculasFavoritasESD135_2021.csv";
    tipo_dato **matriz;
       int i;
    matriz = (tipo_dato **) malloc(60 * sizeof (tipo_dato*));
    for (i = 0; i < 60; i++) {
        matriz[i] = (tipo_dato *) malloc(6 * sizeof (tipo_dato));
    }
    matriz=carga_datos(nombre_del_archivo);
  //  el primer dato es igial 0 1 0 1 1 0
  //el segundo es  1 1 0 1 0 0
    //primer dato

    ///////////////////////////////////
    CU_ASSERT_EQUAL(matriz[0][0],0);
    CU_ASSERT_EQUAL(matriz[0][1],1);
    CU_ASSERT_EQUAL(matriz[0][2],0);
    CU_ASSERT_EQUAL(matriz[0][3],1);
    CU_ASSERT_EQUAL(matriz[0][4],1);
    CU_ASSERT_EQUAL(matriz[0][5],0);


    
    
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest2", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testCarga_datos", testCarga_datos))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
