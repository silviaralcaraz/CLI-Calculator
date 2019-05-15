#include "stdlib.h"
#include "stdio.h"
#include "errores.h"

void imprimirError(int tipo, int linea){
    switch (tipo){
        case COMPONENTE_NO_RECONOCIDO:   // error del analizador lexico reconociendo el componente lexico
	    printf("> ERROR: componente no reconocido. [Linea: %d ]\n", linea);
            break;
	case DIVISION_POR_CERO:
	    printf("> ERROR: division por cero. [Linea: %d ]\n", linea);
            break;
	case VARIABLE_NO_INICIALIZADA:
	    printf("> AVISO: variable no inicializada. Se ha inicializado con valor 0.0. [Linea: %d ]\n", linea);
	    break;
	case FUNCION_DESCONOCIDA:
	    printf("> AVISO: la funcion introducida no ha sido reconocida por el programa. [Linea: %d ]\nFunciones disponibles:", linea);
	    break;
	case ERROR_ARG_FUNCION:
	    printf("> ERROR: se espera un argumento para la funcion. [Linea: %d ]\nModo de uso de las funciones:", linea);
	    break;
    }
}

void imprimirErrorFichero(int tipo, char* msg){
    printf("> ERROR: %s \n", msg);
}
