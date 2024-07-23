all:
	gcc exercicio3a.h exercicio3a.c main.c -o exec

val:
	valgrind -s --track-origins=yes ./exec
run:;
	./exec
