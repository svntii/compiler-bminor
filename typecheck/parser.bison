/*	bminor parser	*/
/* ALL THE C Modules needed in our parser*/
%{
#include "expr.h"
#include "stmt.h"
#include "token.h"
#include "decl.h"
#include "type.h"
#include "param_list.h"

#include "token.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct decl * parser_result;
extern char *yytext;
extern int yylex();
extern int yyerror(char * str);
extern FILE *yyin;

%}


%union{
	struct decl *decl;
	struct stmt *stmt;
	struct expr *expr;
	char * name;
	struct type *type;
	struct param_list *param_list;
};

%type <decl> program decl decl_list
%type <stmt> body stmnt_list statement if_term
%type <type> auto_decl type_decl auto_decl_args type_decl_args return_types 
%type <expr> decl_stmnt expr expr_list expr_epsilon for_arg ident_assign or and comparison term factor exponent unary postfix pre_atomic atomic atomic_array_epsilon atomic_array atomic_array_end arg_epsilon arg_list arg_list_end array_end inside_arr
%type <param_list> decl_args_epsilon decl_args decl_args_end
%type <name> name 

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

%token TOKEN_EOF

%token TOKEN_WHILE   	
%token TOKEN_ERROR
%token TOKEN_COMMENT



%%
	program: decl_list TOKEN_EOF							{ parser_result = $1; return 0; }	
		;
	
	decl_list:	decl decl_list								{ $$ = $1; $1->next = $2;	}
		|													{ $$ = 0;					}
		;	

	decl: 			name TOKEN_COLON auto_decl decl_stmnt TOKEN_SEMI /*Variable Declaration*/	{ $$ = decl_create($1, $3, $4, 0, 0);  }
		|			name TOKEN_COLON TOKEN_FUNC return_types	TOKEN_PARL decl_args_epsilon TOKEN_PARR	TOKEN_SEMI /*function prototype */ { $$ = decl_create($1, type_create(TYPE_FUNCTION, $4, $6, 0,0), 0, 0, 0);  }
		|			name TOKEN_COLON TOKEN_FUNC return_types	TOKEN_PARL decl_args_epsilon TOKEN_PARR TOKEN_ASSIGN body { $$ = decl_create($1, type_create(TYPE_FUNCTION, $4, $6, 0,0), 0, $9, 0); }
		;

	name:	TOKEN_IDENT 				{ $$ = strdup(yytext); }	
		;
	decl_stmnt: TOKEN_ASSIGN expr		{ $$ = $2;	}
		|								{ $$ = 0; 	}
		;
	
	auto_decl: 	TOKEN_AUTO				{ $$ = type_create(TYPE_AUTO, 0, 0, 0, 0); 	}
		| 		type_decl				{ $$ = $1;	}
		;
	
	type_decl:	TOKEN_INT 				{ $$ = type_create(TYPE_INTEGER, 0, 0, 0,0);	}
		|		TOKEN_BOOL 				{ $$ = type_create(TYPE_BOOLEAN, 0, 0, 0, 0);	}
		|		TOKEN_CHAR				{ $$ = type_create(TYPE_CHAR,	 0, 0, 0, 0); }
		|		TOKEN_STR				{ $$ = type_create(TYPE_STRING,  0, 0, 0, 0);	}
		|		TOKEN_ARRAY TOKEN_BRACKL inside_arr TOKEN_BRACKR auto_decl { $$ = type_create( TYPE_ARRAY,$5, 0, 0, 0);  }

	
	auto_decl_args: TOKEN_AUTO 		{ $$ = type_create(TYPE_AUTO, 0, 0, 0,0);	}
		|			type_decl_args	{ $$ = $1;							}
		;
	
	type_decl_args:	TOKEN_INT 		{ $$ = type_create(TYPE_INTEGER, 0, 0, 0, 0);	}
		|			TOKEN_BOOL		{ $$ = type_create(TYPE_BOOLEAN, 0, 0, 0, 0);	}
		|			TOKEN_CHAR		{ $$ = type_create(TYPE_CHAR,    0, 0, 0, 0); }
		|			TOKEN_STR		{ $$ = type_create(TYPE_STRING,  0, 0, 0, 0); }	
		|			TOKEN_ARRAY TOKEN_BRACKL inside_arr TOKEN_BRACKR auto_decl_args	{ $$ = type_create(TYPE_ARRAY, $5, 0, $3, 0);  }
		|			TOKEN_FUNC return_types	{ $$ = type_create(TYPE_FUNCTION, $2, 0, 0, 1); $$->return_type = 1; } 
		;

	decl_args_epsilon: decl_args  { $$ = $1; }
		|						  { $$ = 0;  }
		;
	decl_args: 		name TOKEN_COLON auto_decl_args decl_args_end 	{ $$ = param_list_create($1, $3, 0 ,$4) ;   } /*What is symbol in param_list*/
		;
	
	decl_args_end: 	TOKEN_COMMA decl_args {	$$ = $2;	}
		|			{$$ = 0;}
		;

	statement: 	TOKEN_IF TOKEN_PARL expr TOKEN_PARR statement						{ $$ = stmt_create_if($3, $5);			}
		|		TOKEN_IF TOKEN_PARL expr TOKEN_PARR if_term TOKEN_ELSE statement	{ $$ = stmt_create_if_else($3, $5, $7);	}
		|		TOKEN_RETURN expr TOKEN_SEMI										{ $$ = stmt_create_return($2);			}
		|		TOKEN_FOR 	TOKEN_PARL for_arg TOKEN_SEMI for_arg TOKEN_SEMI for_arg TOKEN_PARR statement{ $$ = stmt_create_for($3, $5, $7, $9);}
		|		body																{ $$ = $1; }
		|		TOKEN_PRINT	expr_epsilon TOKEN_SEMI				 /*print*/			{ $$ = stmt_create_print($2);			}	
		|		name TOKEN_COLON auto_decl decl_stmnt TOKEN_SEMI /*decl*/			{ $$ = stmt_create_decl( decl_create($1, $3, $4, 0, 0) );	}
		|		expr TOKEN_SEMI														{ $$ = stmt_create_expr($1);			}
		;

	stmnt_list:	statement stmnt_list												{ $$ = $1; $1->next = $2; 				}
		|		statement															{ $$ = $1; 								}
		;

	body:		TOKEN_CRLL stmnt_list TOKEN_CRLR									{ $$ = stmt_create_block($2);	}
		;


	if_term:	TOKEN_IF TOKEN_PARL expr TOKEN_PARR if_term TOKEN_ELSE if_term		{ $$ = stmt_create_if_else($3, $5, $7);	}
		|		TOKEN_RETURN expr TOKEN_SEMI										{ $$ = stmt_create_return($2);			}
		|		TOKEN_FOR 	TOKEN_PARL for_arg TOKEN_SEMI for_arg TOKEN_SEMI for_arg TOKEN_PARR 	if_term	{ $$ = stmt_create_for($3, $5, $7, $9);	}
		|		body																{ $$ = $1;								}
		|		TOKEN_PRINT	expr_epsilon TOKEN_SEMI					/*print*/		{ $$ = stmt_create_print($2);			}	
		|		name TOKEN_COLON auto_decl decl_stmnt TOKEN_SEMI /*decl*/			{ $$ = stmt_create_decl( decl_create($1, $3, $4, 0, 0)); 		}
		|		expr TOKEN_SEMI														{ $$ = stmt_create_expr($1);			}
		;
		
		;


	for_arg: expr		{$$ = $1;	}
		|				{$$ = 0	;	}
		;

	return_types: 	TOKEN_VOID 		{ $$ = type_create(TYPE_VOID,    0, 0, 0, 1); }		
		| 			TOKEN_INT		{ $$ = type_create(TYPE_INTEGER, 0, 0, 0, 1); }
		| 			TOKEN_BOOL		{ $$ = type_create(TYPE_BOOLEAN, 0, 0, 0, 1); }
		| 			TOKEN_CHAR		{ $$ = type_create(TYPE_CHAR, 	 0, 0, 0, 1); }
		| 			TOKEN_STR		{ $$ = type_create(TYPE_STRING,  0, 0, 0, 1); }
		;
	
	expr_epsilon:	expr_list 	{ $$ = $1;	}
		|			/*epsilon*/	{ $$ = 0;	}
		;

	expr_list:		expr TOKEN_COMMA expr_list	{ $$ = $1; $1->right = $3; }
		|			expr		{ $$ = $1; }
		;

	expr: 			ident_assign TOKEN_ASSIGN expr		{ $$ = expr_create(EXPR_ASSIGNMENT, $1, $3); }
		|			or TOKEN_TERN expr TOKEN_COLON expr	{ $$ = expr_create(EXPR_TERN, $1, expr_create(EXPR_TERN_BODY, $3, $5)); }				
		|			or									{ $$ = $1;		}
		;

	or:				or TOKEN_LOGOR and				{ $$ = expr_create(EXPR_OR, $1, $3); }
		|			and								{ $$ = $1;		}
		;

	and:			and  TOKEN_LOGAND comparison	{ $$ = expr_create(EXPR_AND, $1, $3);}
		| 			comparison						{ $$ = $1;		}
		;

	comparison:		comparison TOKEN_GT term		{ $$ = expr_create(EXPR_GT, $1, $3); }
		|			comparison TOKEN_GTE term		{ $$ = expr_create(EXPR_GTE,$1, $3); }
		|			comparison TOKEN_LT term		{ $$ = expr_create(EXPR_LT, $1, $3); }
		|			comparison TOKEN_LTE term		{ $$ = expr_create(EXPR_LTE,$1, $3); }
		|			comparison TOKEN_COMP term		{ $$ = expr_create(EXPR_EQ, $1, $3); }
		|			comparison TOKEN_NE term		{ $$ = expr_create(EXPR_NEQ,$1, $3); }
		|			term							{ $$ = $1;		}	
		;

	term: 			term TOKEN_ADD factor			{ $$ = expr_create(EXPR_ADD,$1, $3); }
		|			term TOKEN_SUB factor			{ $$ = expr_create(EXPR_SUB,$1, $3); }
		|			factor							{ $$ = $1;		}
		;
	
	factor: 		factor	TOKEN_MULT 	exponent	{ $$ = expr_create(EXPR_MULT,$1,$3); }
		|			factor	TOKEN_DIV 	exponent	{ $$ = expr_create(EXPR_DIV,$1, $3); }
		|			factor	TOKEN_MOD 	exponent	{ $$ = expr_create(EXPR_MOD,$1, $3); }
		|			exponent						{ $$ = $1;		}
		;

	exponent:		exponent TOKEN_EXP unary		{ $$ = expr_create(EXPR_EXP,$1, $3); }
		|			unary							{ $$ = $1;		}
		;

	unary:			TOKEN_SUB unary					{ $$ = expr_create(EXPR_NEGATE,0,$2);}	
		|			TOKEN_NOT unary					{ $$ = expr_create(EXPR_NOT,0,$2);}
		|			postfix							{ $$ = $1;		}
		;
	
	postfix:		pre_atomic TOKEN_POSIN 			{ $$ = expr_create(EXPR_POSIN, 0, $1);}
		|			pre_atomic TOKEN_POSDEC 		{ $$ = expr_create(EXPR_POSDEC,0, $1);}
		|			pre_atomic						{ $$ = $1;		}
		;

	pre_atomic:		name TOKEN_PARL arg_epsilon TOKEN_PARR /*function call*/	{ $$ = expr_create(EXPR_FUNCTION_CALL, expr_create_name($1), $3);}
		|			name TOKEN_BRACKL inside_arr TOKEN_BRACKR array_end	/*subscript*/ { $$ = expr_create(EXPR_SUBSCRIPT, expr_create_name($1), 0); $$->right = expr_create(EXPR_SUBSCRIPT_SUB, $3, $5);  }
		|			TOKEN_PARL expr TOKEN_PARR		{ $$ = expr_create(EXPR_GROUP, 0,$2); }				/*grouping */
		| 			atomic							{ $$ = $1; }	
		;


	ident_assign:	name						{ $$ = expr_create_name($1);  		}  /*REVIEW*/
		|			name TOKEN_BRACKL inside_arr TOKEN_BRACKR array_end {$$ = expr_create(EXPR_SUBSCRIPT, expr_create_name($1), 0); $$->right = expr_create(EXPR_SUBSCRIPT_SUB, $3, $5); }
		;



	atomic: 		TOKEN_NUMBER		{ $$ = expr_create_integer_literal(atoi(yytext));  		}	
		|			TOKEN_STRLIT		{ $$ = expr_create_string_literal(strdup(yytext));		}
		|			TOKEN_CHARLIT		{ $$ = expr_create_char_literal(*(yytext + 1)); 		}
		|			TOKEN_TRUE			{ $$ = expr_create_boolean_literal(1);		}
		|			TOKEN_FALSE			{ $$ = expr_create_boolean_literal(0);		} /*REVIEW*/
		|			name				{ $$ = expr_create_name($1);				}
		|			TOKEN_CRLL atomic_array_epsilon TOKEN_CRLR { $$ = expr_create(EXPR_ARRAY_LITERAL, $2, 0);	}/*array declaration REVIEW*/
		;		

	atomic_array_epsilon: atomic_array				{ $$ = $1; }
		|											{ $$ = 0;  }
		;

	atomic_array: 	atomic atomic_array_end 		{ $$ = expr_create(EXPR_ARG, $1, $2);	}
		;

	atomic_array_end: TOKEN_COMMA atomic_array 		{ $$ = $2;	}
		|											{ $$ = 0; 	}
		;
	arg_epsilon: 	arg_list						{ $$ = $1;}
		|			/*epsilon*/ 					{ $$ = 0; }
		;
	
	arg_list:		expr arg_list_end				{ $$ = expr_create(EXPR_ARG, $1, $2);		}
		;

	arg_list_end:	TOKEN_COMMA arg_list 			{ $$ = $2; }
		| 											{ $$ = 0;  }
		;

	
	array_end: 		TOKEN_BRACKL inside_arr TOKEN_BRACKR array_end 	{ $$ = expr_create(EXPR_SUBSCRIPT_SUB, $2, $4);	}
		|												 			{ $$ = 0; 	}
		;

	inside_arr: 	expr							{ $$ = $1; }
		|											{ $$ = 0 ; }
		;
%%

int yyerror( char *str )
{
	printf("parse error: %s\n",str);
	return 0;
}


