#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"
#include "definiciones.h"

//////////////////////////////////////////////
abb izq(abb A) {
    return A->izq;
}

abb der(abb A) {
    return A->der;
}

unsigned esVacio(abb A) {
    return A == NULL;
}

unsigned esMiembro(abb A, Nodo E) {
    if (esVacio(A))
        return 0;
    else if (strcmp(E->lexema, A->nodo->lexema) == 0)
        return 1;
    else if (strcmp(E->lexema, A->nodo->lexema) > 0)
        return esMiembro(A->der, E);
    else
        return esMiembro(A->izq, E);
}
//////////////////////////////////////////////

void crearArbol(abb *A) {
    *A = NULL;
}

void destruirArbol(abb *A) {
    if (*A != NULL) {
        destruirArbol(&(*A)->izq);
        destruirArbol(&(*A)->der);
        free(&(*A)->nodo->lexema);
        free(*A);
        *A = NULL;
    }
}

void insertarNodo(abb *A, Nodo E) {
    if (esVacio(*A)) {
        *A = (abb) malloc(sizeof(struct Elemento));
        (*A)->nodo = E;
        (*A)->izq = NULL;
        (*A)->der = NULL;
    } else if (strcmp(E->lexema, ((*A)->nodo)->lexema) < 0)
        insertarNodo(&(*A)->izq, E);
    else
        insertarNodo(&(*A)->der, E);
}

void imprimirArbol(abb *A, int id) {
    if(id == VARIABLE || id == CONSTANTE){
        if (!esVacio(*A)) {
            imprimirArbol(&(*A)->izq, id);
            if (((*A)->nodo->identificador == id)) {
                printf("%s -> %lf\n", (*A)->nodo->lexema, (*A)->nodo->valor);
            }
            imprimirArbol(&(*A)->der, id);
        }
    }else if(id == FUNCION){
        if (!esVacio(*A)) {
            imprimirArbol(&(*A)->izq, id);
            if (((*A)->nodo->identificador == id)) {
                printf("%s -> %s(X)\n", (*A)->nodo->lexema, (*A)->nodo->lexema);
            }
            imprimirArbol(&(*A)->der, id);
        }
    }
}

int existeNodo(abb A, char *clave) {
    if (esVacio(A))
        return 1;   // no existe
    else if (strcmp(clave, A->nodo->lexema) == 0)
        return 0;   // existe
    else if (strcmp(clave, A->nodo->lexema) < 0)
        existeNodo(izq(A), clave);
    else
        existeNodo(der(A), clave);
}

void buscarNodo(abb A, char *lexema, Nodo *n) {
    if (esVacio(A))
        *n = NULL;
    else if (strcmp(lexema, A->nodo->lexema) == 0)
        *n = A->nodo;
    else if (strcmp(lexema, A->nodo->lexema) < 0)
        buscarNodo(izq(A), lexema, n);
    else
        buscarNodo(der(A), lexema, n);
}

void modifica(abb *A, char *lexema, Nodo n) {
    if (esVacio(*A)) {
        printf("Clave inexistente\n"); 
    } else if (strcmp(lexema, (*A)->nodo->lexema) == 0)
        (*A)->nodo = n;
    else if (strcmp(lexema, (*A)->nodo->lexema) < 0)
        modifica(&(*A)->izq, lexema, n);
    else
        modifica(&(*A)->der, lexema, n);
}
