
bminor: main.o scanner.o parser.o decl.o stmt.o type.o expr.o param_list.o special.o
	gcc special.o param_list.o expr.o type.o stmt.o decl.o parser.o main.o scanner.o -o ./bminor;
	cp ./bminor ./TESTS/bminor

main.o: main.c token.h
	gcc -c main.c -o main.o

parser.o: parser.c 
	gcc -c parser.c -o parser.o

decl.o: decl.c decl.h
	gcc -c decl.c -o decl.o

stmt.o: stmt.c stmt.h
	gcc -c stmt.c -o stmt.o

type.o: type.h type.c
	gcc -c type.c -o type.o

expr.o: expr.c expr.h
	gcc -c expr.c -o expr.o

special.o: special.c special.h
	gcc -c special.c -o special.o

param_list.o: param_list.c param_list.h
	gcc -c param_list.c -o param_list.o

scan.o: scanner.c token.h
	gcc -c scanner.c -o scanner.o

scanner.c: scanner.flex
	flex -o scanner.c scanner.flex

parser.c: parser.bison  
	bison --defines=token.h --output=parser.c -v parser.bison

clean:
	rm *.o scanner.c ./bminor;
	rm ./TESTS/bminor
