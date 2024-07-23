all:
	gcc parte1.h parte1.c main.c -o exec

val:
	valgrind -s --track-origins=yes ./exec
run:;
	./exec
