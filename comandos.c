#include "stdio.h"
#include "stdlib.h"
#include "comandos.h"
#include "tablaSimbolos.h"
#include "definiciones.h"

void imprimirAyuda() {
       printf("\n------------------------------------------------------------------------\n"
              "------------------------------   AYUDA   -------------------------------\n"
              "------------------------------------------------------------------------\n"
              "Teclee los siguientes comandos para interactuar con la calculadora:\n"
              "- HELP/help:\n\tinvocar a este mensaje de ayuda.\n"
              "- FULLHELP/fullhelp:\n\timprime la informacion completa del programa.\n"
              "- LOAD/load: \n\tcarga un archivo con expresiones que la calculadora analizara.\n"
              "- WORKSPACE/workspace: \n\timprime el workspace actual, es decir, las variables utilizadas.\n"
	      "- CONSTANTES/constantes: \n\timprime las constantes disponibles.\n"
	      "- FUNCIONES/funciones: \n\timprime las funciones disponibles. \n"
	      "- REINICIAR/reiniciar: \n\tborra todas las variables del espacio de trabajo.\n"
              "- EXIT/exit: \n\tse finaliza el programa.\n"
              "------------------------------------------------------------------------\n\n");
}

void imprimirAyudaExtendida() {
       printf("\n------------------------------------------------------------------------\n"
              "-------------------------   AYUDA EXTENDIDA   --------------------------\n"
              "------------------------------------------------------------------------\n"
              "Comandos que soporta la calculadora:\n"
              "- HELP/help:\n\tinvoca un mensaje de ayuda con los comandos del programa.\n"
              "- FULLHELP/fullhelp:\n\timprime la informacion completa del programa.\n"
              "- LOAD/load: \n\tcarga un archivo con expresiones que la calculadora analizara.\n"
              "- WORKSPACE/workspace: \n\timprime el workspace actual, es decir, las variables utilizadas.\n"
	      "- CONSTANTES/constantes: \n\timprime las constantes disponibles.\n"
	      "- FUNCIONES/funciones: \n\timprime las funciones disponibles. \n"
	      "- REINICIAR/reiniciar: \n\tborra todas las variables del espacio de trabajo.\n"
              "- EXIT/exit: \n\tse finaliza el programa.\n"
	      "________________________________________________________________________\n"
	      "Operadores disponibles: +, -, *, /, ^, <, >, <=, >=, ==, !=\n"
	      "[Nota: el resultado de sentencias del tipo 'a<2' es 1-> cierto 0-> falso]\n"
	      "________________________________________________________________________\n"
	      "Funciones disponibles:");
	      imprimirFunciones();
	      printf("Constantes disponibles:");
	      imprimirConstantes();	
	      printf("________________________________________________________________________\n"
	      "Ejemplos de uso:\n"
	      "\t[Nota: el resultado solo se imprime si la expresion acaba por ';']\n"
	      "> a = -sin(PI);\n> (2*6)/4;\n> b = ((2*6)/4)\n> b^tan(a);\n");		 		
              printf("------------------------------------------------------------------------\n\n");
}

void imprimirWorkspace(){
       imprimirTablaSimbolos(VARIABLE);
}

void imprimirConstantes(){
       imprimirTablaSimbolos(CONSTANTE);
}

void imprimirFunciones(){
       imprimirTablaSimbolos(FUNCION);
}
