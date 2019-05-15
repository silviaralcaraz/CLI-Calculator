#include <memory.h>
#include <ctype.h>
#include "stdlib.h"
#include "stdio.h"
#include "abb.h"
#include "tablaSimbolos.h"
#include "definiciones.h"
#include "stdbool.h"
#include "math.h"

abb *tablaSimbolos;

// Arrays utilizados para inicializar la tabla de simbolos:
char* fname[]={ "sin", "cos", "tan", "asin", "acos", "atan", "sinh", "cosh", "tanh", "log", "log10", "exp", "sqrt", "ceil", "floor", "round", "trunc"};
double (*fnct[])()={ sin, cos, tan, asin, acos, atan, sinh, cosh, tanh, log, log10, exp, sqrt, ceil, floor, round, trunc, NULL};
 
char *constantes[] = {"PI", "E", "LOG2E", "LOG10E", "LN2", "LN10", "PI_2", "PI_4", "M_1_PI", "M_2_PI", "M_2_SQRTPI", "SQRT2", "SQRT1_2", "FI"};
float valorCtes[] = {M_PI, M_E, M_LOG2E, M_LOG10E, M_LN2, M_LN10, M_PI_2, M_PI_4, M_1_PI, M_2_PI, M_2_SQRTPI, M_SQRT2, M_SQRT1_2, 1.61803398874989, -1};

void insertarSimbolo(Nodo *nodo, char *lexema, int id, double valor) {
    *nodo = malloc(sizeof(struct Elemento));
    (*nodo)->identificador = id;
    (*nodo)->lexema = lexema;
    (*nodo)->valor = valor;
    insertarNodo(tablaSimbolos, *nodo);
}

void imprimirTablaSimbolos(int id) {
    if(id==VARIABLE){
        printf("\n-----------------------------"
               "\n-----TABLA DE SIMBOLOS-------\n"
               "-----------------------------\n"
               "(VARIABLE -> VALOR):\n");
        imprimirArbol(tablaSimbolos, id);
        printf("-----------------------------\n");
    }else if(id == FUNCION){
        printf("\n-----------------------------"
               "\n--------- FUNCIONES ---------\n"
               "-----------------------------\n"
               "(FUNCION -> USO):\n");
        imprimirArbol(tablaSimbolos, id);
        printf("-----------------------------\n");
    }else if(id == CONSTANTE){
    	printf("\n-----------------------------"
               "\n--------- CONSTANTE ---------\n"
               "-----------------------------\n"
               "(CONSTANTE -> VALOR):\n");
        imprimirArbol(tablaSimbolos, id);
        printf("-----------------------------\n");
    }
}

void inicializarTablaSimbolos() {
    tablaSimbolos = malloc(sizeof(abb *));
    int i = 0;
    Nodo nodo;
    while (valorCtes[i] != -1) { // se introducen las constantes
        insertarSimbolo(&nodo, constantes[i], CONSTANTE, valorCtes[i]);
        i++;
    }
    i = 0;
    while (fnct[i] != NULL) { // se introducen las funciones
        nodo = malloc(sizeof(struct Elemento));
        (nodo)->identificador = FUNCION;
        (nodo)->lexema = fname[i];
        (nodo)->puntero = fnct[i];
        insertarNodo(tablaSimbolos, nodo);
        i++;
    }
}

bool existeElemento(char *lexema) {
    if (existeNodo(*tablaSimbolos, lexema) == 0) {
        return true;
    } else if (existeNodo(*tablaSimbolos, lexema) == 1) {
        return false;
    } else {
        return false;
    }
}

void modificarElemento(char *lexema, double value){
    Nodo n;
    buscarNodo(*tablaSimbolos, lexema, &n);
    n->valor = value;
    modifica(tablaSimbolos, lexema, n);
}

double buscarValorElemento(char *lexema){
    Nodo n;
    buscarNodo(*tablaSimbolos, lexema, &n);
    return n->valor;
}

double invocarFuncion(char *lexema, double num){
    Nodo n;
    buscarNodo(*tablaSimbolos, lexema, &n);	
    return n->puntero(num);
}

void liberarTablaSimbolos() {
    destruirArbol(tablaSimbolos);
}
