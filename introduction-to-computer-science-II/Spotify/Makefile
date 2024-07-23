all: main.o spotify.o
	@gcc main.o spotify.o -o exec
main.o: main.c
	@gcc main.c -c
spotify.o: spotify.c
	@gcc spotify.c -c
run:
	@./exec