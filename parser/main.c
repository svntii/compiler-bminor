#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "main.h"

extern int yyparse();
extern FILE *yyin;
extern int yydebug;


int main(int argc, char *argv[])
{
	yydebug = 0;
	int i = 1;
	char flag[BUFSIZ];
	char t_str[BUFSIZ];

	if (i == argc)
	{
		fprintf(stderr, "No specified file or flags \n\n");
		return usage(3);
	}

	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			printf("%s\n",flag);
			strcpy(flag, argv[i]);
			if (strcmp(flag, "-h") == 0)
			{
				return usage(0);
			}
			else if (strcmp(flag, "-scan") == 0)
			{
				yyin = fopen(argv[i + 1], "r");
				if(!yyin) return usage(4);
			}
			else if (strcmp(flag, "-l") == 0)
			{
				yyin = stdin;
			}
			else if(strcmp(flag, "-debug") == 0)
			{
				yydebug = 1;
			}
			else
			{
				return usage(1);
			}
		}
		else
		{
			break;
		}
		i++;
	}
	printf("CSE 40243 B-Minor Parser\n");
	printf("Enter a valid  B-Minor Code \n\n");

	if (yyparse() == 0)
	{
		printf("Parse Successful\n");
		return 0;
	}
	else
	{
		printf("Parse Unsuccessful\n");
		return -1;
	}
}

int usage(int exit_code)
{

	fprintf(stderr, "bminor scanner.... sample use is \n\t \
					./bminor -s FILENAME\n\tflags to use:\
					\n\t\t-h help\
					\n\t\t-s to scan file in the next argument\n\
					\n\t\t-l for interpreter\
					\n\t\t-debug for debugging output\n");

	return exit_code;
}
