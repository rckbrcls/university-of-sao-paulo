all:
	gcc parte2.h parte2.c main.c -o exec

val:
	valgrind -s --track-origins=yes ./exec
run:;
	./exec
