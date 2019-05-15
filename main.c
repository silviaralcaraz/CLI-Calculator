#include <stdio.h>
#include "stdlib.h"
#include "definiciones.h"
#include "tablaSimbolos.h"
#include "errores.h"
#include "calculadora.tab.h"
#include "comandos.h"

extern int yylex();
extern int yylex_destroy();
extern char *yytext;
extern FILE *yyin;


int main(int argc, char **argv) {
    inicializarTablaSimbolos();
    printf("\n		--	CALCULADORA MULTIFUNCION	--\n");
    imprimirAyuda();

    if (argc == 2) {
        char *rutaFichero = argv[1];
        yyin = fopen(rutaFichero, "r");
	if(yyin == NULL){
		imprimirErrorFichero(ERROR_FICHERO, "el archivo introducido no existe. Calculadora iniciada por comandos.\n");
		yyin = stdin;
	}
    } else if (argc == 1) {
        yyin = stdin;
    } else {
        imprimirErrorFichero(ERROR_FICHERO, "se esperan 0 o 1 argumentos. Calculadora iniciada por comandos.\n");
	yyin = stdin;
    }
    yyparse();

    liberarTablaSimbolos();
    yylex_destroy();
    return 0;
}
