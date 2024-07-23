all:
	gcc buscaLargura.h buscaLargura.c main.c -o exec

val:
	valgrind -s --track-origins=yes ./exec
run:;
	./exec
