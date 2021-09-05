#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"
#include <string.h>



//metodo para contar las filas del archivo de texto
int cuenta_de_filas(char* archivo_nombre) {
    struct mis_datos datos_st;
    FILE* archivo;
    archivo = fopen(archivo_nombre, "r");
    int cant = 0;
    char c;
    bool verda = true;
    while (verda) {
        c = fgetc(archivo);
        if (c == '\n') {
            cant++;
        } else {
            if (c == EOF) {
                verda = false;
            }

        }
    }
    return cant;
}

//metodo para contar las columnas del archivo de texto
int cuenta_de_columna(char* archivo_nombre) {
    FILE* archivo;
    char aux_c[80];
    int cant = 0, cont = 0;
    char c;
    bool verda = true;
    archivo = fopen(archivo_nombre, "r");
    fscanf(archivo, " %[^\n]", aux_c); //primera fila del encabesado =culumnas
    while (verda) {
        if (aux_c[cont] == ',') {
            cant++;
        }
        if (aux_c[cont] == EOF) {
            verda = false;
        }
        cont++;
    }
    return cant;
}


tipo_dato** carga_datos(char *nombre_del_archivo) {
      tipo_dato **matriz;
       int i;
        int filas_cant, columna_cant, j, cont = 0;
           //metodos para ver la cantidad de filas y columnas
    filas_cant = cuenta_de_filas(nombre_del_archivo);
    columna_cant = cuenta_de_columna(nombre_del_archivo);
       
    matriz = (tipo_dato **) malloc(filas_cant * sizeof (tipo_dato*));
    for (i = 0; i < filas_cant; i++) {
        matriz[i] = (tipo_dato *) malloc(columna_cant * sizeof (tipo_dato));
    }
    
    FILE* mi_archivo;

   


    mi_archivo = fopen(nombre_del_archivo, "r");
    char lectura[80];

    fscanf(mi_archivo, " %[^\n]", lectura); //esta intrucion leera la primera fila que en nuestro caso es inesesari
    //pero esta intrucion solo permite una fila a la vez y la siguiente intrucion leera la siguiente fila

    fscanf(mi_archivo, " %[^\n]", lectura);
    int aux;
    //asignacion de datos a la matrix //
    for (i = 0; i < filas_cant; i++) {
        for (j = 8; j < 19; j += 2) {
            aux = (lectura[j] - 48);
           matriz[i][cont] = aux;
            cont++;
        }
        cont = 0;
        fscanf(mi_archivo, " %[^\n]", lectura);
    }
    return matriz;
}




tipo_dato** matrix_traspuesta(tipo_dato **V,int filas,int columnas) {
 tipo_dato **vector_aux;
    int i, j, aux = 0; 
  
    vector_aux = (tipo_dato **) malloc(columnas * sizeof (tipo_dato*));
    for (i = 0; i < columnas; i++) {
        vector_aux[i] = (tipo_dato *) malloc(filas * sizeof (tipo_dato));
    }
    //en este blucle se traspone
    for (i = 0; i < columnas; i++) {
    for (j = 0; j < filas ; j++) {
        vector_aux[i][j]=V[j][i];
    }   
    }
  
    return vector_aux;

}


tipo_dato** multliplicacion_matriz(tipo_dato **V_1,int fila,int columas,tipo_dato **V_2){
    int i,j,numero_salida=0,k,cont_aux=0;
        
    tipo_dato ** Vector_salida;
        Vector_salida = (tipo_dato **) malloc(fila * sizeof (tipo_dato*));
    for (i = 0; i < fila; i++) {
        Vector_salida[i] = (tipo_dato *) malloc(fila * sizeof (tipo_dato));
    }
    /*
     */
    //bucle para la multiplicacion
        for (i = 0; i < fila; i++){
        for (j = 0; j < fila; j++){
            for (k = 0; k < columas; k++) {                
                 numero_salida+=(V_1[i][k])*(V_2[k][j]);
            }
            Vector_salida[i][j]=numero_salida;
            cont_aux++;
            numero_salida=0;
        }
  
        }
    return Vector_salida;
}


const char* carnet(){
    return "Aviles Morán Ernesto Alexander,AM18007";
}
