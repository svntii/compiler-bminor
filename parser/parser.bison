%{
	#include <stdio.h>
%}

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

%token TOKEN_COMMENT 


%token TOKEN_TERN   ":?"   


%token TOKEN_NE	    "!="
%token TOKEN_LT		"<"
%token TOKEN_LTE    "<="
%token TOKEN_GT		">"
%token TOKEN_GTE    ">="
%token TOKEN_COMP   "=="


%token TOKEN_ADD    "+"
%token TOKEN_SUB	"-"	
%token TOKEN_DIV	"/"	
%token TOKEN_MULT	"**"
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

%%
	program : statement_epsilon
	;
	
	statement_epsilon: 	statement_list TOKEN_SEMI
	|						/*epsilon*/
	;

	statement_list:		statement_list TOKEN_SEMI statement
	|					statement TOKEN_SEMI													{ $$ = $1;					}
	;
	
	statement: 	TOKEN_RETURN expr TOKEN_SEMI										{ $$ = return $1; }
		| 		if 
		|		TOKEN_WHILE TOKEN_PARL expr TOKEN_PARR 	statement_list		
		|		TOKEN_FOR 	TOKEN_PARL for_list	TOKEN_PARR body						{ $$ = for( $3 )   $5		}
		|		TOKEN_PRINT	arg_epsilon TOKEN_SEMI									
		|		expr TOKEN_SEMI														{ $$ = $1;					}
		|		ident TOKEN_PARL arg_epsilon TOKEN_PARR TOKEN_SEMI					{ $$ = $1($3);				}
		|		ident TOKEN_SEMI TOKEN_FUNC return_types TOKEN_PARL arg_epsilon TOKEN_PARR TOKEN_ASSIGN body
		;

	if	:	matched_if 
		| 	open_if
		;
	open_if: 	TOKEN_IF TOKEN_PARL expr TOKEN_PARR statement_list
		|		TOKEN_IF TOKEN_PARL expr TOKEN_PARR matched_if TOKEN_ELSE open_if
		;

	matched_if:	TOKEN_IF TOKEN_PARL expr TOKEN_PARR matched_if TOKEN_ELSE matched_if
		|		expr
		;

	body:	TOKEN_CRLL statement TOKEN_CRLR 				{ $$ = "{"$1"}";		}
		;

	for_list: for_arg TOKEN_SEMI for_arg TOKEN_SEMI for_arg		{$$ = $1; $3; $5	}
		;

	for_arg: expr			{$$ = $1}
		|
		;

	return_types:
		| TOKEN_VOID		{ $$ = void;	}
		| TOKEN_INT			{ $$ = int; 	}
		| TOKEN_BOOL		{ $$ = bool; 	}
		| TOKEN_CHAR		{ $$ = char;	}
		| TOKEN_STR
		;

	expr:	TOKEN_IDENT TOKEN_COLON auto		{ 				}
		|	ass_ter 							{ $$ = $1;		}
		;
	
	
	auto: TOKEN_AUTO end_type;
		| type
		;
	type:	TOKEN_INT end_type
		|	TOKEN_NUMBER end_type
		|	TOKEN_BOOL end_type
		|	TOKEN_CHAR end_type
		|	TOKEN_STR end_type
		|	TOKEN_ARRAY TOKEN_BRACKL inside_arr TOKEN_BRACKR mult_arr
		|	TOKEN_FUNC type TOKEN_PARL arg_epsilon TOKEN_PARR TOKEN_ASSIGN expr
		;
	
	end_type:	TOKEN_ASSIGN expr TOKEN_SEMI
		|		TOKEN_SEMI
		;
	
	ident:	TOKEN_IDENT;

	ass_ter: 	expr TOKEN_ASSIGN or	
		|		expr TOKEN_TERN   or	
		|		or							{$$ = $1;		}
		;

	or:		ass_ter TOKEN_LOGOR and			{$$ = $1 || $3;	}
		|	and								{$$ = $1;		}
		;

	and:	or  TOKEN_LOGAND comparison		{$$ = $1 && $3;	}
		| 	comparison						{$$ = $1;		}
		;

	comparison:	and TOKEN_GT add_sub		{$$ = $1 > $3;	}
		|		and TOKEN_GTE add_sub		{$$ = $1 >= $3;	}
		|		and TOKEN_LT add_sub		{$$ = $1 < $3;	}
		|		and TOKEN_LTE add_sub		{$$ = $1 <= $3;	}
		|		and TOKEN_COMP add_sub		{$$ = $1 == $3;	}
		|		and TOKEN_NE add_sub		{$$ = $1 != $3;	}
		|		add_sub						{$$ = $1;		}
		;

	add_sub: 	comparison 	TOKEN_ADD 	mult_div	{$$ = $1 + $3; 	}
		|		comparison 	TOKEN_SUB 	mult_div	{$$ = $1 - $3; 	}
		|		mult_div							{$$ = $1;		}
		;
	
	mult_div: 	mult_div	TOKEN_MULT 	exponent	{$$ = $1 * $3; 	}
		|		mult_div	TOKEN_DIV 	exponent	{$$ = $1 / $3; 	}
		|		mult_div	TOKEN_MOD 	exponent	{$$ = $1 % $3; 	}
		|		exponent							{$$ = $1;		}
		;

	exponent:	exponent TOKEN_EXP factor		{$$ = $1 ** $3;	}
		|		factor							{$$ = $1;		}
		;

	factor:		factor TOKEN_SUB 	postfix		
		|		factor TOKEN_NOT	postfix		{$$ = -$1;		}
		|		postfix							{$$ = $1;		}
		;
	
	postfix:	postfix TOKEN_POSIN  atomic		{$$ = $1++;		}
		|		postfix TOKEN_POSDEC atomic		{$$ = $1--;		}
		|		atomic							{$$ = $1;		}
		;

	atomic: TOKEN_NUMBER						{$$ = atoi(yytext);	}
		|	TOKEN_STRLIT
		|	TOKEN_CHARLIT
		|	TOKEN_BRACKR expr array_end
		|	TOKEN_PARL expr TOKEN_PARR
		|	function_call
		;
	
	function_call: ident TOKEN_PARL arg_epsilon TOKEN_PARR
		;

	arg_epsilon: arg_list
		|	/*epsilon*/
		;
	
	arg_list:	expr arg_list_end
		;

	arg_list_end:	TOKEN_COMMA arg_list
		| 
		;
			
	array_end:	atomic TOKEN_COMMA array_end
		| 		TOKEN_BRACKR
		;

	mult_arr:	TOKEN_BRACKL inside_arr TOKEN_BRACKR mult_arr
		|		return_types mult_arr
		|		end_type
		;
	
	inside_arr: expr
		;
	

%%
int yywrap() { return 0; }
