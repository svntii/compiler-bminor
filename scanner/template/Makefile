

bminor: main.o scanner.o
	gcc main.o scanner.o -o bminor

main.o: main.c token.h
	gcc -c main.c -o main.o

scanner.o: scanner.flex scanner.c token.h
	gcc -c scanner.c -o scanner.o



scanner.c: scanner.flex
	flex -o scanner.c scanner.flex

clean:
	rm *.o 
