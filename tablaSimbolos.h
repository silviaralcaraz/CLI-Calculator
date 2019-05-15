#ifndef P3COMP_TABLASIMBOLOS_H
#define P3COMP_TABLASIMBOLOS_H

#include "abb.h"
#include "stdbool.h"

/* Funcion que inicializa la tabla de simbolos */
void inicializarTablaSimbolos();
/* Funcion que comprueba si la tabla tiene o no un elemento */
bool existeElemento(char *lexema);
/* Funcion que inserta un componente en la tabla de simbolos */
void insertarSimbolo(Nodo *nodo, char *lexema, int id, double valor);
/* Funcion que modifica un componente de la tabla de simbolos */
void modificarElemento(char *lexema, double value);
/* Funcion que imprime el contenido de la tabla de simbolos */
void imprimirTablaSimbolos(int id);
/* Funcion que libera la tabla de simbolos */
void liberarTablaSimbolos();
/* Funcion que busca el valor de un elemento dado su lexema*/
double buscarValorElemento(char *lexema);
/* Funcion que invoca a la funcion matematica correspondiente y devuelve su resultado */
double invocarFuncion(char *lexema, double num);

#endif //P3COMP_TABLASIMBOLOS_H
