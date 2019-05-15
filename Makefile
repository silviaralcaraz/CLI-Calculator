p3Compiladores:
	bison -d calculadora.y
	lex calculadora.l
	gcc *.c -o p3Compiladores -lfl -lm
