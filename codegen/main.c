#include "main.h"
#include "decl.h"
#include "scope.h"
#include "special.h"

extern int yyparse();
extern FILE *yyin;
extern int yydebug;
extern int yywrap();
extern struct decl *parser_result;
int MAIN_TYPEERROR_COUNT = 0;
int MAIN_RESOLVEERROR_COUNT = 0;
FILE *output_file;

int main(int argc, char *argv[])
{
	yydebug = 0;
	int i = 1;
	char flag[BUFSIZ];
	char t_str[BUFSIZ];
	int interpreter_flag = 0;
	int scan_flag = 0;
	int parse_flag = 0;
	int print_flag = 0;
	int typecheck_flag = 0;
	int resolve_flag = 0;
	int codegen_flag = 0;

	if (i == argc)
	{
		fprintf(stderr, "No specified file or flags \n\n");
		return usage(3);
	}

	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			strcpy(flag, argv[i]);
			if (strcmp(flag, "-h") == 0)
			{
				return usage(0);
			}
			else if (strcmp(flag, "-scan") == 0)
			{
				yyin = fopen(argv[i + 1], "r");
				if (!yyin)
					return usage(4);
				scan_flag = 1;
				i++;
				break;
			}
			else if (strcmp(flag, "-parse") == 0)
			{
				yyin = fopen(argv[i + 1], "r");
				if (!yyin)
					return usage(4);
				i++;
				scan_flag = 1;
				print_flag = 1;
				break;
			}
			else if (strcmp(flag, "-i") == 0)
			{
				output_file = fopen(argv[i + 1], "w");
				if (!output_file)
					return usage(5);

				yyin = stdin;
				interpreter_flag = 1;
				scan_flag = 1;
				parse_flag = 1;
				print_flag = 1;
				resolve_flag = 1;
				typecheck_flag = 1;
				codegen_flag = 1;
			}
			else if (strcmp(flag, "-debug") == 0)
			{
				yydebug = 1;
			}
			else if (strcmp(flag, "-print") == 0)
			{
				yyin = fopen(argv[i + 1], "r");
				if (!yyin)
					return usage(4);
				i++;
				scan_flag = 1;
				parse_flag = 1;
				print_flag = 1;
				break;
			}
			else if (strcmp(flag, "-resolve") == 0)
			{
				yyin = fopen(argv[i + 1], "r");
				if (!yyin)
					return usage(4);
				i++;
				scan_flag = 1;
				parse_flag = 1;
				print_flag = 1;
				resolve_flag = 1;
				break;
			}
			else if (strcmp(flag, "-typecheck") == 0)
			{
				yyin = fopen(argv[i + 1], "r");
				if (!yyin)
					return usage(4);

				i++;
				scan_flag = 1;
				parse_flag = 1;
				print_flag = 1;
				resolve_flag = 1;
				typecheck_flag = 1;
				break;
			}
			else if (strcmp(flag, "-codegen") == 0)
			{
				yyin = fopen(argv[i + 1], "r");
				if (!yyin)
					return usage(4);

				output_file = fopen(argv[i + 2], "w");
				if (!output_file)
					return usage(5);
				i++;
				scan_flag = 1;
				parse_flag = 1;
				print_flag = 1;
				resolve_flag = 1;
				typecheck_flag = 1;
				codegen_flag = 1;
				break;
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
	if (interpreter_flag)
	{
		printf("CSE 40243 B-Minor Interpreter\n");
		printf("Enter a valid  B-Minor Code Below...\n\n");
	}

	if (scan_flag)
	{
		if (yywrap() == 1)
		{
			printf("	Scan Successful\n");
		}
		else
		{
			printf("Scan Unsuccessful\n");
			return 1;
		}
	}

	if (parse_flag)
	{
		if (yyparse() == 0)
		{
			printf("	Parse Successful\n");
		}
		else
		{
			printf("Parse Unsuccessful\n");
			return 1;
		}
	}

	if (print_flag == 1)
	{
		printf("	Reformatted Code\n");
		// we want to print the output
		decl_print(parser_result, 0);
	}

	if (resolve_flag == 1)
	{
		scope_enter();
		// we want to resolve the code
		printf("\n*****RESOLVING*******\n\n");
		decl_resolve(parser_result);
		printf("	Code Resolved\n");
		if (MAIN_RESOLVEERROR_COUNT > 0)
			return MAIN_RESOLVEERROR_COUNT;
		scope_exit();
	}
	if (typecheck_flag == 1)
	{
		// we want to typecheck the code
		printf("\n*****TYPECHECKING*******\n\n");
		decl_typecheck(parser_result);
		printf("	Code Typecheck\n");

		if (MAIN_TYPEERROR_COUNT > 0)
			return MAIN_TYPEERROR_COUNT;
	}

	if (codegen_flag == 1)
	{
		printf("\n*****Codegen*******\n\n");
		decl_codegen(parser_result);
	}

	return 0;
}

int usage(int exit_code)
{

	fprintf(stderr, "bminor scanner.... sample use is \n\t \
					./bminor -s FILENAME\n\tflags to use:\
					\n\t\t-h help\
					\n\t\t-scan to scan file in the next argument\
					\n\t\t-parse to parse file in the next argument\
					\n\t\t-print to print reformated code\
					\n\t\t-resolves file in the next argument\
					\n\t\t-typechecks file in the next argument\
					\n\t\t-i for interpreter\
					\n\t\t-debug for debugging output\n");

	return exit_code;
}
