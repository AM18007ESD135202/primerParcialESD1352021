
#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H



typedef int tipo_dato;
struct mis_datos{
    int filas;
    int columnas;
};


tipo_dato** carga_datos(char *nombre_del_archivo);

int cuenta_de_filas(char *archivo_nombre);

int cuenta_de_columna(char* archivo_nombre);

tipo_dato** matrix_traspuesta(tipo_dato **V,int filas,int columnas);

tipo_dato** multliplicacion_matriz(tipo_dato **V_1,int fila,int columas,tipo_dato **V_2);

const char* carnet();
#endif


