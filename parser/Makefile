
bminor: main.o scanner.o parser.o
	gcc parser.o main.o scanner.o -o ./bminor

main.o: main.c token.h
	gcc -c main.c -o main.o

parser.o: parser.c
	gcc -c parser.c -o parser.o

scan.o: scanner.c token.h
	gcc -c scanner.c -o scanner.o

scanner.c: scanner.flex
	flex -o scanner.c scanner.flex

parser.c: parser.bison
	bison --defines=token.h --output=parser.c parser.bison

clean:
	rm *.o scanner.c ./bminor
