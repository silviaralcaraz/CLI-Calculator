/* Calculadora multifuncion */
%{
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "errores.h"
#include "tablaSimbolos.h"
#include "definiciones.h"
#include "comandos.h"

void yyerror (const char *s);

extern int yylex();
extern FILE *yyin;
extern char *yytext;
extern int yylineno;
%}

%union{
  double valor;
  char *identifier;
}

%start input

// Simbolos terminales
%token <identifier> VAR
%token <valor> NUM

%token '+'
%token '-'
%token '='
%token '*'
%token '/'
%token '('
%token ')'
%token ';'
%token '\n'
%token MENOR_IGUAL
%token MAYOR_IGUAL
%token DOBLE_IGUAL
%token NO_IGUAL

// Simbolos no terminales
%type <valor> exp

%left '<' '>' MENOR_IGUAL MAYOR_IGUAL DOBLE_IGUAL NO_IGUAL
%left '-' '+'
%left '*' '/'
%left NEG 
%right '='
%right '^' 

%%

/* REGLAS GRAMATICALES Y ACCIONES */

input:	// puede haber entradas vacias o una linea de entrada
	/* vacio */	
	| input line	
;

line:
	'\n'	// si hay un salto de carro solo, no se hace nada
	| exp ';' { printf ("\t%lf\n", $1); }	// Si acaba en ; la expresion, se imprime
	| exp '\n' // Si no acaba en ; no se imprime nada
	| error '\n' { yyerrok; } // se imprime un syntax error
;

exp :     NUM                       { $$ = $1; }
	| VAR '=' exp		{
					if(existeElemento($1)){ // si el elemento existe, se modifica
						modificarElemento($1, $3);
					}else{	// en caso contrario se crea con el valor correspondiente
						Nodo nodo;
						insertarSimbolo(&nodo, $1, VARIABLE, $3);
					}
					$$ = buscarValorElemento($1);
				}
	| VAR			{
					if(existeElemento($1)){
						$$ = buscarValorElemento($1);
					}else{	// si el elemento no existe se imprime un error y se crea con valor 0.0
						imprimirError(VARIABLE_NO_INICIALIZADA, yylineno);
						Nodo nodo;
						insertarSimbolo(&nodo, $1, VARIABLE, 0.0);
					}
					$$ = buscarValorElemento($1);
				}
	| VAR '(' exp ')'	{
					if(existeElemento($1)){	// si la funcion existe en la TS, se invoca
						$$ = invocarFuncion($1, $3);
					}else{	// en caso contrario se imprime un error y se muestran las funciones disponibles
						imprimirError(FUNCION_DESCONOCIDA, yylineno);
						imprimirFunciones();						
					}
				}
	| VAR '('')'		{	// Se imprime un error en caso de que una funcion no lleve argumento
					imprimirError(ERROR_ARG_FUNCION, yylineno);
					imprimirFunciones();
				}
	| 	exp '+' exp	{ $$ = $1 + $3;}
	| 	exp '-'	exp 	{ $$ = $1 - $3;}
	| 	exp '*' exp	{ $$ = $1 * $3;}
	| 	exp '/' exp	{ if($3 != 0) $$ = $1 / $3; else{ imprimirError(DIVISION_POR_CERO, yylineno); $$ = 0;} }
	|	'-' exp %prec NEG { $$ = -$2; }
	| 	exp '^' exp	{ $$ = pow($1, $3); }
	| 	exp '<' exp	{ $$ = ($1 < $3); } // 1-> true 0-> false
	| 	exp '>' exp	{ $$ = ($1 > $3); } 
	|	exp MENOR_IGUAL exp {$$ = ($1 <= $3); }
	|	exp MAYOR_IGUAL exp {$$ = ($1 >= $3); }
	|	exp DOBLE_IGUAL exp {$$ = ($1 == $3); }
	|	exp NO_IGUAL exp {$$ = ($1 != $3); }
	| 	'(' exp ')'	{ $$ = $2; }
;

%%

void yyerror (const char *s) {
   printf ("ERROR: %s\n", s);
}
