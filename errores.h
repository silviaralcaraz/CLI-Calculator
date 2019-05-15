#ifndef P3COMP_ERRORES_H
#define P3COMP_ERRORES_H

#define COMPONENTE_NO_RECONOCIDO 20
#define ERROR_FICHERO 21
#define DIVISION_POR_CERO 22
#define VARIABLE_NO_INICIALIZADA 23
#define FUNCION_DESCONOCIDA 24
#define ERROR_ARG_FUNCION 25

/* Funcion que recibe un tipo de error e imprime sus datos por pantalla */
void imprimirError(int tipo, int linea);

/* Funcion que imprime un error causado por el fichero de entrada */
void imprimirErrorFichero(int tipo, char *mensaje);

#endif //P3COMP_ERRORES_H
