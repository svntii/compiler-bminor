
bminor: main.o scanner.o parser.o decl.o stmt.o type.o expr.o param_list.o special.o symbol.o scope.o hash_table.o scratch.o argument.o label.o
	gcc argument.o hash_table.o scope.o symbol.o special.o param_list.o expr.o type.o stmt.o decl.o parser.o main.o scanner.o scratch.o label.o -g -o ./bminor;
	cp ./bminor ./TESTS/bminor

main.o: main.c token.h
	gcc -c main.c -g -o main.o

parser.o: parser.c 
	gcc -c parser.c -g -o parser.o

decl.o: decl.c decl.h
	gcc -c decl.c -g -o decl.o

stmt.o: stmt.c stmt.h
	gcc -c stmt.c -g -o stmt.o

type.o: type.h type.c
	gcc -c type.c -g -o type.o

expr.o: expr.c expr.h
	gcc -c expr.c -g -o expr.o

special.o: special.c special.h
	gcc -c special.c -g -o special.o

symbol.o: symbol.c symbol.h
	gcc -c symbol.c -g -o symbol.o

scope.o: scope.c scope.h
	gcc -c scope.c -g -o scope.o

param_list.o: param_list.c param_list.h
	gcc -c param_list.c -g -o param_list.o

label.o: label.c label.h
	gcc -c label.c -g -o label.o

scratch.o: scratch.c scratch.h
	gcc -c scratch.c -g -o scratch.o

argument.o: argument.c argument.h
	gcc -c argument.c -g -o argument.o

scan.o: scanner.c token.h
	gcc -c scanner.c -g -o scanner.o

hash_table.o: hash_table.c hash_table.h
	gcc -c hash_table.c -g -o hash_table.o

scanner.c: scanner.flex
	flex -o scanner.c scanner.flex

parser.c: parser.bison  
	bison --defines=token.h --output=parser.c -v parser.bison

clean:
	rm *.o scanner.c ./bminor;
	rm ./TESTS/bminor
