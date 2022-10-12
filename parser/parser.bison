%define parse.trace

%token TOKEN_ARRAY
%token TOKEN_AUTO  		
%token TOKEN_BOOL		
%token TOKEN_CHAR		
%token TOKEN_ELSE		
%token TOKEN_TRUE		
%token TOKEN_FALSE		
%token TOKEN_FOR 		
%token TOKEN_FUNC		
%token TOKEN_IF			
%token TOKEN_INT 		
%token TOKEN_PRINT 		
%token TOKEN_RETURN	
%token TOKEN_STR			
%token TOKEN_VOID		
%token TOKEN_WHILE   	
%token TOKEN_SEMI	";"	
%token TOKEN_COLON	":"	
%token TOKEN_COMMA	","	
%token TOKEN_BRACKL "["	
%token TOKEN_BRACKR	"]"	
%token TOKEN_CRLL	"{"	
%token TOKEN_CRLR	"}"	
%token TOKEN_PARL	"("		
%token TOKEN_PARR	")"	

%token TOKEN_TERN   "?"   

%token TOKEN_NE	    "!="
%token TOKEN_LT		"<"
%token TOKEN_LTE    "<="
%token TOKEN_GT		">"
%token TOKEN_GTE    ">="
%token TOKEN_COMP   "=="

%token TOKEN_ADD    "+"
%token TOKEN_SUB	"-"	
%token TOKEN_DIV	"/"	
%token TOKEN_MULT	"*"
%token TOKEN_MOD	"%"	
%token TOKEN_EXP	"^"	
%token TOKEN_LOGOR	"||"
%token TOKEN_LOGAND	"&&"
%token TOKEN_NOT    "!"

%token TOKEN_POSDEC	"--"
%token TOKEN_POSIN	"++"
%token TOKEN_ASSIGN "="

%token TOKEN_CHARLIT
%token TOKEN_STRLIT
%token TOKEN_IDENT
%token TOKEN_NUMBER

%token TOKEN_ERROR
%token TOKEN_COMMENT 
%token TOKEN_EOF


%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define YYSTYPE struct expr *

extern char *yytext;
extern int yylex();
extern int yyerror(char * str);


%}


%%
	program : declaration_list TOKEN_EOF							{return 0;}	
		|		TOKEN_EOF											{return 0;}
		;
	
	declaration_list:	declaration declaration_list								{}
		|				declaration													{}
		;	

	declaration: 	TOKEN_IDENT TOKEN_COLON auto_decl decl_stmnt TOKEN_SEMI /*Variable Declaration*/
		|			TOKEN_IDENT TOKEN_COLON TOKEN_FUNC return_types	TOKEN_PARL decl_args_epsilon TOKEN_PARR TOKEN_ASSIGN TOKEN_CRLL stmnt_list TOKEN_CRLR
		|			TOKEN_IDENT TOKEN_COLON TOKEN_FUNC return_types	TOKEN_PARL decl_args_epsilon TOKEN_PARR	TOKEN_SEMI /*function prototype */
		;
	
	
	decl_stmnt: TOKEN_ASSIGN expr
		|
		;
	
	auto_decl: TOKEN_AUTO 
		| type_decl									{$$ = $1;}
		;
	
	type_decl:	TOKEN_INT 
		|		TOKEN_BOOL 
		|		TOKEN_CHAR
		|		TOKEN_STR
		|		TOKEN_ARRAY TOKEN_BRACKL inside_arr TOKEN_BRACKR auto_decl

	
	auto_decl_args: TOKEN_AUTO
		|	type_decl_args
		;
	
	type_decl_args:		TOKEN_INT 
		|				TOKEN_BOOL
		|				TOKEN_CHAR
		|				TOKEN_STR
		|				TOKEN_ARRAY TOKEN_BRACKL expr TOKEN_BRACKR auto_decl_args
		|				TOKEN_FUNC return_types 
		;

	decl_args_epsilon: decl_args
		|
		;
	decl_args: TOKEN_IDENT TOKEN_COLON auto_decl_args decl_args_end
		;
	
	decl_args_end: TOKEN_COMMA decl_args
		|
		;

	statement: 	TOKEN_RETURN expr TOKEN_SEMI										{ }
		| 		TOKEN_IF TOKEN_PARL expr TOKEN_PARR statement						{ }
		|		TOKEN_IF TOKEN_PARL expr TOKEN_PARR if_term TOKEN_ELSE statement	{ }
		|		TOKEN_WHILE TOKEN_PARL expr TOKEN_PARR 	statement					{ }
		|		TOKEN_FOR 	TOKEN_PARL for_list	TOKEN_PARR statement				{ }
		|		TOKEN_CRLL stmnt_list TOKEN_CRLR					/*body*/		{ }
		|		TOKEN_PRINT	expr_epsilon TOKEN_SEMI					/*print*/		{ }	
		|		TOKEN_IDENT TOKEN_COLON auto_decl decl_stmnt TOKEN_SEMI /*decl*/
		|		expr TOKEN_SEMI														{ }
		;

	stmnt_list:	statement stmnt_list												{ }
		|		statement															{ }
		;

	if_term:	TOKEN_IF TOKEN_PARL expr TOKEN_PARR if_term TOKEN_ELSE if_term		{ }
		|		TOKEN_CRLL stmnt_list TOKEN_CRLR	/*only statement i am iffy about because you can have if statements as is*/						{ }
		;

	for_list: for_arg TOKEN_SEMI for_arg TOKEN_SEMI for_arg							{ }
		;

	for_arg: expr
		|
		;

	return_types: TOKEN_VOID		
		| TOKEN_INT		
		| TOKEN_BOOL
		| TOKEN_CHAR
		| TOKEN_STR
		| TOKEN_FUNC return_types
		;

	expr_epsilon:	expr_list
		|
		;

	expr_list:	expr TOKEN_COMMA expr_list
		|		expr
		;

	expr: 		ident_assign TOKEN_ASSIGN expr
		|		or TOKEN_TERN expr TOKEN_COLON expr			/*Also this one ish*/	
		|		or											{$$ = $1;		}
		;

	or:		or TOKEN_LOGOR and				{}
		|	and								{$$ = $1;		}
		;

	and:	and  TOKEN_LOGAND comparison	{}
		| 	comparison						{$$ = $1;		}
		;

	comparison:	comparison TOKEN_GT term	{	}
		|		comparison TOKEN_GTE term	{	}
		|		comparison TOKEN_LT term		{	}
		|		comparison TOKEN_LTE term	{	}
		|		comparison TOKEN_COMP term	{	}
		|		comparison TOKEN_NE term		{	}
		|		term							{	}
		;

	term: 	term 	TOKEN_ADD 	factor	{ 	}
		|	term 	TOKEN_SUB 	factor	{ 	}
		|		factor							{$$ = $1;		}
		;
	
	factor: 	factor	TOKEN_MULT 	exponent	{ 	}
		|		factor	TOKEN_DIV 	exponent	{ 	}
		|		factor	TOKEN_MOD 	exponent	{ 	}
		|		exponent							{$$ = $1;		}
		;

	exponent:	exponent TOKEN_EXP unary		{	}
		|		unary							{$$ = $1;		}
		;

	unary:		TOKEN_SUB unary					{		}	
		|		TOKEN_NOT unary					{		}
		|		postfix							{$$ = $1;		}
		;
	
	postfix:	pre_atomic TOKEN_POSIN 				{				}
		|		pre_atomic TOKEN_POSDEC 			{				}
		|		pre_atomic							{ $$ = $1;		}
		;

	pre_atomic:	TOKEN_IDENT TOKEN_PARL arg_epsilon TOKEN_PARR			/*function call*/
		|		TOKEN_IDENT TOKEN_BRACKL inside_arr TOKEN_BRACKR array_end			/*subscript*/
		|		TOKEN_PARL expr TOKEN_PARR						/*grouping */
		| 		atomic
		;


	ident_assign:	TOKEN_IDENT
		|			TOKEN_IDENT TOKEN_BRACKL inside_arr TOKEN_BRACKR array_end
		;



	atomic: TOKEN_NUMBER			
		|	TOKEN_STRLIT
		|	TOKEN_CHARLIT
		|	TOKEN_TRUE
		|	TOKEN_FALSE
		|	TOKEN_IDENT
		|	TOKEN_CRLL atomic_array_epsilon TOKEN_CRLR
		;
	
	atomic_array_epsilon: atomic_array
		|
		;

	atomic_array: atomic atomic_array_end
		;

	atomic_array_end: TOKEN_COMMA atomic_array
		|
		;
	arg_epsilon: arg_list
		|	/*epsilon*/
		;
	
	arg_list:	expr arg_list_end
		;

	arg_list_end:	TOKEN_COMMA arg_list
		| 
		;

	
	array_end: TOKEN_BRACKL inside_arr TOKEN_BRACKR
		|
		;

	inside_arr: expr
		|
		;
%%

int yyerror( char *str )
{
	printf("parse error: %s\n",str);
	return 0;
}


