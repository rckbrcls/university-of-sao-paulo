all:
	gcc exercicio5.h exercicio5.c main.c -o exec

val:
	valgrind -s --track-origins=yes ./exec
run:;
	./exec
