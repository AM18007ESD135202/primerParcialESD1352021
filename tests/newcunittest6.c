

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

void testMultliplicacion_matriz() {
 char *nombre = "datos/peliculasFavoritasESD135_2021.csv";
    struct mis_datos datos_struc;
    int i, j,filas,columnas;
    datos_struc.filas =cuenta_de_filas(nombre);
    datos_struc.columnas=cuenta_de_columna(nombre);
    
    filas=datos_struc.filas;
    columnas=datos_struc.columnas;
    
    tipo_dato **V, ** matriz, **producto;
    matriz = carga_datos(nombre);
    V = matrix_traspuesta(matriz, filas, columnas);
    
    producto = multliplicacion_matriz(matriz,filas,columnas, V);
    //primero datos de el producto
    //3,2,1,2,2,1,
    CU_ASSERT_EQUAL(producto[0][0],3);
    CU_ASSERT_EQUAL(producto[0][1],2);
    CU_ASSERT_EQUAL(producto[0][2],1);
    CU_ASSERT_EQUAL(producto[0][3],2);
    CU_ASSERT_EQUAL(producto[0][4],2);
    CU_ASSERT_EQUAL(producto[0][5],1);
    
    
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest6", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testMultliplicacion_matriz", testMultliplicacion_matriz))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
