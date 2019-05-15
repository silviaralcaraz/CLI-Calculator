# CLI-Calculator

A continuación se describen tanto los requisitos del sistema como las acciones 
a realizar para compilar y ejecutar el programa.

## Requirements

- Linux System with BASH.
- Have "make" installed

		$ sudo apt-get install make

- Have "flex" installed
    
		$ sudo apt-get install flex

- Have "bison" installed
		
		$ sudo apt-get install bison

## Compilation

Open a shell in the same folder that Makefile is located (probably, CLI-Calculator).

Execute:

		$ make

At this point, the executable file "p3Compiladores" will have been generated.

## Execution
        
        $ ./p3Compiladores [entrada.m]      

*Note: in this case, the input file is entrada.m*

## Program help

### Available commands:

- **HELP/help**:
	shows this help message.

- **FULLHELP/fullhelp**:
	shows all the information about the program usage.
- **LOAD/load**: 
	load a file with expresions to analyze.
- **WORKSPACE/workspace**: 
	prints the workspace, in other words, the variables in use in that moment.
- **CONSTANTES/constantes**: 
	prints the available constants.
- **FUNCIONES/funciones**: 
	prints the available functions. 
- **REINICIAR/reiniciar**: 
	restarts the workspace (deletes all the variables in use).
- **EXIT/exit**: 
	to finish the program.
