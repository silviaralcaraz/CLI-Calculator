%option yylineno
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include "definiciones.h"
    	#include "errores.h"
	#include "tablaSimbolos.h"
	#include "comandos.h"
	#include "calculadora.tab.h"
%}

/*/////////////////////////////////////// DEFINICIONES ///////////////////////////////////////*/

/* Identifiers */
identifier	[A-Za-z_]([A-Za-z|0-9|_])*

/* Keywords o Comandos */
printWorkspace  "WORKSPACE"|"workspace"
ayudaExtendida  "FULLHELP"|"fullhelp"
printAyuda      "HELP"|"help"
printConstantes "CONSTANTES"|"constantes"
printFunciones "FUNCIONES"|"funciones"
cargarFichero  "LOAD"|"load"
salir           "EXIT"|"exit"
reiniciarWorkspace	"REINICIAR"|"reiniciar"

/* Spaces and line breaks */
space       [ \r]
tabs	    [ \t]
lineBreak   [ \n]

/* Integer literals */
integer		(-?[0-9]+)

/* Floating point literals */
floatnumber	([0-9]*)\.([0-9]*)|([0-9]+)(e|E)(-?)(\+?)([0-9]+)

/* Operators */
MENOR_IGUAL	"<="
MAYOR_IGUAL	">="
DOBLE_IGUAL	"=="
NO_IGUAL	"!="

%%

{printWorkspace}	{imprimirWorkspace();}
{ayudaExtendida}	{imprimirAyudaExtendida();}
{printAyuda}		{imprimirAyuda();}
{printFunciones}	{imprimirFunciones();}
{printConstantes}	{imprimirConstantes();}
{cargarFichero}	{
			printf("Introduzca la ruta del fichero de entrada: \n");
			char ruta[100];
			scanf(" %s", ruta);
			FILE *fichero = fopen(ruta, "r");
			printf("Ruta introducida: %s\n", ruta);
			if(fichero!=NULL){
				yyrestart(fichero);		
			}else{
				imprimirErrorFichero(ERROR_FICHERO, "el archivo no existe.\n");
			}
			return '\n';
		}
{salir}			{
				printf("Finalizando ejecucion...\n... ha salido correctamente.\n"); 
				yyterminate();
			}
{reiniciarWorkspace}	{
				printf("Reiniciando el workspace...\nEspacio de trabajo reiniciado:"); 
				liberarTablaSimbolos(); 				
				imprimirWorkspace();
				inicializarTablaSimbolos();
			}
{space}				// ninguna accion
{tabs}				// ninguna accion

{lineBreak}    			{return '\n';}

{integer}			{
					yylval.valor=atof(yytext); 
					return(NUM);
				}

{floatnumber}			{
					yylval.valor=atof(yytext); 
					return(NUM);
				}

{identifier}			{  
					yylval.identifier = (char *) malloc(sizeof (yytext));
                                	yylval.identifier = strdup(yytext);
                                	return VAR;
                                }

"("		{return '(';}
")"		{return ')';}
"="		{return '=';}
"-"		{return '-';}
"+"		{return '+';}
"*"		{return '*';}
"/"		{return '/';}
"^"		{return '^';}
"<"		{return '<';}
">"		{return '>';}
";"		{return ';';}
{MENOR_IGUAL}	{return MENOR_IGUAL;}
{MAYOR_IGUAL}	{return MAYOR_IGUAL;}
{DOBLE_IGUAL}	{return DOBLE_IGUAL;}
{NO_IGUAL}	{return NO_IGUAL;}

<<EOF>>		{
			if(yyin!=stdin){ 
				fclose(yyin);	// Cierro el archivo actual
			} 
			yyrestart(stdin); // Reinicio la entrada para que funcione por comandos en vez de fichero
			return '\n';	// Devuelvo salto de carro para que continue la ejecucion
		}

.		{imprimirError(COMPONENTE_NO_RECONOCIDO, yylineno);}

%%
