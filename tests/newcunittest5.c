/*
 * File:   newcunittest5.c
 * Author: avi
 *
 * Created on 4 sept. 2021, 22:10:59
 */

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

void testMatrix_traspuesta() {
     char* nombre_del_archivo = "datos/peliculasFavoritasESD135_2021.csv";
    tipo_dato **V;
       int i;
    V = (tipo_dato **) malloc(60 * sizeof (tipo_dato*));
    for (i = 0; i < 60; i++) {
        V[i] = (tipo_dato *) malloc(6 * sizeof (tipo_dato));
    }
    V=carga_datos(nombre_del_archivo);
    int filas=60;
    int columnas=6;
    tipo_dato** result = matrix_traspuesta(V, filas, columnas);
     //  el primer dato es igial 0 1 0 1 1 0 pero la traspuesta las filas se buelven colunas 
    CU_ASSERT_EQUAL(result[0][0],0);
    CU_ASSERT_EQUAL(result[1][0],1);
    CU_ASSERT_EQUAL(result[2][0],0);
    CU_ASSERT_EQUAL(result[3][0],1);
    CU_ASSERT_EQUAL(result[4][0],1);
    CU_ASSERT_EQUAL(result[5][0],0);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest5", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testMatrix_traspuesta", testMatrix_traspuesta))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
