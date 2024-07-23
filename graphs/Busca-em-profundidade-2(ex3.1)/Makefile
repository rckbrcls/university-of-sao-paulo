all:
	gcc exercicio3b.h exercicio3b.c main.c -o exec

val:
	valgrind -s --track-origins=yes ./exec
run:;
	./exec
