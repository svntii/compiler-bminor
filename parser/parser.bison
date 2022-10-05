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
%token TOKEN_SEMI		
%token TOKEN_COLON		
%token TOKEN_COMMA		
%token TOKEN_BRACKL		
%token TOKEN_BRACKR		
%token TOKEN_CRLL		
%token TOKEN_CRLR		
%token TOKEN_PARL		
%token TOKEN_PARR		

%token TOKEN_COMMENT 


%token TOKEN_TERN      


%token TOKEN_NE	    
%token TOKEN_LT		
%token TOKEN_LTE     
%token TOKEN_GT		
%token TOKEN_GTE     
%token TOKEN_COMP    


%token TOKEN_ADD     
%token TOKEN_SUB		
%token TOKEN_DIV		
%token TOKEN_MULT	
%token TOKEN_MOD		
%token TOKEN_EXP		
%token TOKEN_LOGOR	
%token TOKEN_LOGAND	

%token TOKEN_NOT    
%token TOKEN_POSDEC	
%token TOKEN_POSIN	
%token TOKEN_ASSIGN  

%token TOKEN_CHARLIT
%token TOKEN_STRLIT
%token TOKEN_IDENT
%token TOKEN_NUMBER
%token TOKEN_ERROR

%%
	program : declaration_epsilon
	;
	
	declaration_epsilon: 	declaration_list
	|						/*epsilon*/
	;

	declaration_list:	declaration declaration_list
	|					declaration
	;

	declaration:	ident TOKEN_COLON TOKEN_FUNC ident TOKEN_PARL /*LOOK*/ TOKEN_PARR arg_epsilon TOKEN_CRLL body TOKEN_CRLR
	;
	
	body: 	statement
		;	
	
	statement: 	TOKEN_RETURN expr TOKEN_SEMI
		| 		TOKEN_IF 	TOKEN_PARL expr TOKEN_PARR statement end_if
		|		TOKEN_WHILE TOKEN_PARL expr TOKEN_PARR statement
		|		TOKEN_CRLL	body	TOKEN_CRLR
		|		TOKEN_PRINT	arg_epsilon TOKEN_SEMI
		|		expr TOKEN_SEMI
		;
	
	end_if:		TOKEN_ELSE end_else
		|		/*epsilon*/
		;
	
	end_else:	TOKEN_CRLL statement TOKEN_CRLR
		|		TOKEN_IF 	TOKEN_PARL expr TOKEN_PARR statement end_if
		;

	expr:	ass_ter
		|	assignment
		;
	
	assignment: ident TOKEN_COLON auto
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
		;
	
	end_type:	TOKEN_ASSIGN expr TOKEN_SEMI
		|		TOKEN_SEMI
		;
	
	ident:	TOKEN_IDENT;

	ass_ter: 	expr TOKEN_ASSIGN or
		|		expr TOKEN_TERN   or
		|		or
		;

	or:		ass_ter TOKEN_LOGOR and
		|	and
		;

	and:	or  TOKEN_LOGAND comparison
		| 	comparison
		;

	comparison:	and TOKEN_GT add_sub
		|		and TOKEN_GTE add_sub
		|		and TOKEN_LT add_sub
		|		and TOKEN_LTE add_sub
		|		and TOKEN_COMP add_sub
		|		and TOKEN_NE add_sub
		|		add_sub
		;

	add_sub: 	comparison 	TOKEN_PLUS 	mult_div
		|		comparison 	TOKEN_SUB 	mult_div
		|		mult_div
		;
	
	mult_div: 	mult_div	TOKEN_MULT 	exponent	
		|		mult_div	TOKEN_DIV 	exponent
		|		mult_div	TOKEN_MOD 	exponent
		|		exponent
		;

	exponent:	exponent TOKEN_EXP factor
		|		factor
		;

	factor:		factor TOKEN_MINUS 	postfix
		|		factor TOKEN_NOT	postfix
		|		postfix
		;
	
	postfix:	postfix TOKEN_POSIN  atomic
		|		postfix TOKEN_POSDEC atomic
		|		atomic
		;

	atomic: TOKEN_NUMBER
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
		| TOKEN_BRACKR
		;

	mult_arr:	TOKEN_BRACKL inside_arr TOKEN_BRACKR mult_arr
		|		type 
		|		end_type
		|		/*epsilon*/
		;
	
	inside_arr: TOKEN_NUMBER
		|		expr
		|		/*epsilon*/
		;
	

%%
int yywrap() { return 0; }
