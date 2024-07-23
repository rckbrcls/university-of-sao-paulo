all:
	gcc parte4.h parte4.c main.c -o exec

val:
	valgrind -s --track-origins=yes ./exec
run:;
	./exec
