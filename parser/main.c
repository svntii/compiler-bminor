#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "main.h"

extern int yyparse();
extern FILE *yyin;
extern int yylex();
extern char *yytext;


int main(int argc, char * argv[]){

	return EXIT_SUCCESS;
}



int usage(int exit_code){
	
	fprintf(stderr, "bminor scanner.... sample use is \n\t./bminor -s FILENAME\n\tflags to use:\n\t\t-h help\n\t\t-s to scan file in the next argument\n");

	return exit_code;
}


