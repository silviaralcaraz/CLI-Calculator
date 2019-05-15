#ifndef P3COMP_ABB_H
#define P3COMP_ABB_H

//////////////////////////////////////////////
/*  Estructuras y tipos de datos    */
typedef struct Elemento{
    char *lexema;
    int identificador;
    double valor;   // valor de una variable
    double (*puntero)(); // puntero a la funcion correspondiente
}Elemento;

struct Arbol {
    struct Elemento * nodo;
    struct Arbol *izq, *der;
};

typedef struct Elemento* Nodo;
typedef struct Arbol* abb;
/////////////////////////////////////////////
/*  Metodos     */
void crearArbol(abb *A);
void destruirArbol(abb *A);
void insertarNodo(abb *A, Nodo n);
void buscarNodo(abb arbol, char* lexema, Nodo *n);
void modifica(abb *A, char *lexema, Nodo n);
int existeNodo(abb arbol, char* clave);
void imprimirArbol(abb* A, int id);
abb izq(abb A);
abb der(abb A);
unsigned esMiembro(abb A, Nodo n);
unsigned esVacio(abb A);
//////////////////////////////////////////////

#endif //P3COMP_ABB_H
