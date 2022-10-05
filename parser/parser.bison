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

	expr:	assignment
		|	comparison
		|	operation
		|	function_call
		|	atomic
		;

	assignment: ident TOKEN_COLON type
		;
	
	type:	TOKEN_INT end_type
		|	TOKEN_NUMBER end_type
		|	TOKEN_BOOL end_type
		|	TOKEN_CHAR end_type
		|	TOKEN_STR end_type
		|	TOKEN_ARRAY TOKEN_BRACKL inside_arr TOKEN_BRACKR mult_arr
		;
	
	ident:	TOKEN_IDENT;

	mult_arr:	TOKEN_BRACKL inside_arr TOKEN_BRACKR mult_arr
		|		type 
		|		end_type
		|		/*epsilon*/
		;
	
	inside_arr: TOKEN_NUMBER
		|		expr
		|		/*epsilon*/
		;
	
	end_type:	TOKEN_ASSIGN expr TOKEN_SEMI
		|		TOKEN_SEMI
		;
	

	operation: 	expr operation_end
		;
	
	operation_end: operator operation
		|
		;
	
	operator:	TOKEN_EXP
		|		TOKEN_ADD
		|		TOKEN_SUB
		|		TOKEN_MULT
		|		TOKEN_DIV
		|		TOKEN_MOD
		;
	comparison: expr comparison_end
		;
	
	comparison_end: comparer comparison
		|
		;
	
	comparer:	TOKEN_COMP
		|		TOKEN_LTE
		|		TOKEN_LT
		|		TOKEN_GTE
		|		TOKEN_GT
		|		TOKEN_NE
		|		TOKEN_LOGAND
		|		TOKEN_LOGOR
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
	
	body: 	statement
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
			
	atomic: TOKEN_NUMBER
		|	TOKEN_STRLIT
		|	TOKEN_CHARLIT
		|	TOKEN_BRACKR expr array_end
		|	TOKEN_PARL expr TOKEN_PARR
		;

	array_end:	atomic TOKEN_COMMA array_end
		| TOKEN_BRACKR
		;


%%
int yywrap() { return 0; }
