all:
	gcc exercicio4.h exercicio4.c main.c -o exec

val:
	valgrind -s --track-origins=yes ./exec
run:;
	./exec
