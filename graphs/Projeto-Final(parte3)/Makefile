all:
	gcc parte3.h parte3.c main.c -o exec

val:
	valgrind -s --track-origins=yes ./exec
run:;
	./exec
