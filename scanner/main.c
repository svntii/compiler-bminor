#include "token.h"
#include <stdio.h>
#include <string.h>


extern FILE *yyin;
extern int yylex();
extern char *yytext;

int usage(int value);
void t_lookup(char * t_str, int t);


int main(int argc, char * argv[]){

		int i = 1;
		char flag[BUFSIZ];
		char t_str[BUFSIZ];

		if (i == argc){
            fprintf(stderr,"No specified file or flags \n\n");
			return usage(3);
		}
		while (i < argc)
		{
			if (argv[i][0] == '-')
			{
				strcpy(flag, argv[i]);

				if (strcmp(flag, "-h") == 0){
					return usage(0);
				} else if( strcmp(flag,"-scan") == 0) {
					yyin = fopen(argv[i+1],"r");
				} else{
					return usage(1);
				}

			}
			else
			{
				break; 
			}
			i++;
		}
			
        if(!yyin){
                fprintf(stderr,"could not open %s!\n\n ", argv[i + 1] );
                return usage(2);
        }
		
        while(1){
				if (yyin == stdin){
				}
                token_t t = yylex();
				if (t == TOKEN_ERROR){
					fprintf(stderr, "scan error: %s is not a valid character\n", yytext);
					return 1;
				}
                if (t == TOKEN_EOF) break;

				if(t == TOKEN_CHARLIT){
					for(int i = 0; i < strlen(yytext)/ sizeof(yytext[0]); i++){
							if (yytext[0] == '\\'){

							}
							else{
								continue;
							}					
					}
				}else if( t == TOKEN_STRLIT){
						
				}


				t_lookup(t_str, t);
                printf("%s\t\ttext: %s\n",t_str,yytext);

        }
		return 0;
}


int usage( int value){
	printf("bminor scanner.... sample use is \n\t./bminor -s FILENAME\n\tflags to use:\n\t\t-h help\n\t\t-s to scan file in the next argument\n");
	return(value);
}



void t_lookup(char * t_str, int t){

	switch(t){
		case TOKEN_IDENT:
			strcpy(t_str, "IDENTIFIER");
			break;
		case TOKEN_WHILE:
		case TOKEN_NUMBER:
		case TOKEN_ARRAY:
		case TOKEN_AUTO:
		case TOKEN_BOOL:
		case TOKEN_CHAR:
		case TOKEN_ELSE:
		case TOKEN_TRUE:
		case TOKEN_FALSE:
		case TOKEN_FOR:
		case TOKEN_FUNC:
		case TOKEN_IF:
		case TOKEN_INT:
		case TOKEN_PRINT:
		case TOKEN_RETURN:
		case TOKEN_STR:
		case TOKEN_VOID:
			strcpy(t_str, "KEYWORD");
			break;
		case TOKEN_COMMENT:
			strcpy(t_str, "COMMENT");			
			break;
		case TOKEN_STRLIT:
			strcpy(t_str, "STRING_LITERAL");
			break;
		case TOKEN_CHARLIT:
			strcpy(t_str, "CHARACTER_LITERAL");
			break;
		case TOKEN_ADD:
			strcpy(t_str, "ADD");
			break;
		case TOKEN_SUB:
			strcpy(t_str, "SUB");
			break;
		case TOKEN_MULT:
			strcpy(t_str, "MULTIPLY");
			break;
		case TOKEN_DIV:
			strcpy(t_str, "DIVIDE");
			break;
		case TOKEN_SEMI:
			strcpy(t_str, "SEMICOLON");
			break;
		case TOKEN_COLON:
			strcpy(t_str, "COLON");
			break;
		case TOKEN_COMMA:
			strcpy(t_str, "COMMA");
			break;
		case TOKEN_BRACKR:
			strcpy(t_str, "BRACKR");
			break;
		case TOKEN_BRACKL:
			strcpy(t_str, "BRACKL");
			break;
		case TOKEN_PARR:
			strcpy(t_str, "PARR");
			break;
		case TOKEN_PARL:
			strcpy(t_str, "PARL");
			break;
		case TOKEN_CRLR:
			strcpy(t_str, "CRLR");
			break;
		case TOKEN_CRLL:
			strcpy(t_str, "CRLL");
			break;
		case TOKEN_ASSIGN:
			strcpy(t_str, "ASSIGNMENT");
			break;
		case TOKEN_COMP:
			strcpy(t_str, "COMPARISON");
			break;
		case TOKEN_LOGOR:
			strcpy(t_str, "LOGICAL_OR");
			break;
		case TOKEN_LOGAND:
			strcpy(t_str, "LOGICAL_AND");
			break;
		case TOKEN_GT:
			strcpy(t_str, "GREATER_THAN");
			break;
		case TOKEN_LT:
			strcpy(t_str, "LESS_THAN");
			break;
		case TOKEN_MOD:
			strcpy(t_str, "MODULO");
			break;
		case TOKEN_EXP:
			strcpy(t_str, "EXPONENTIAL");
		case TOKEN_POSIN:
			strcpy(t_str, "POS_INCREMENT");
			break;
		case TOKEN_POSDEC:
			strcpy(t_str, "POS_DECREMENT");
			break;
		case TOKEN_TERN:
			strcpy(t_str, "TERNARY");
			break;
		default:
			strcpy(t_str, "ERROR");
			break;
	}
	return;
}



