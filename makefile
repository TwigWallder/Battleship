all: out clear

out: main.o
	gcc main.o -o Battleship.exe

main.o: main.c
	gcc main.c -c

clear:
	rm *.o
