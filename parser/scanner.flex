%{

/* C Preamble Code */

#include "token.h"

%}

/* Character Classes */

DIGIT   [0-9]
LETTER  [a-zA-Z]
ALNUM	[0-9a-zA-Z]
STRVALS	[^\"]
%%


[ \n\r\t]*	            {                           }   		

array					{ return TOKEN_ARRAY;		}
auto					{ return TOKEN_AUTO;  		}
boolean					{ return TOKEN_BOOL;		}
char					{ return TOKEN_CHAR;		}
else					{ return TOKEN_ELSE;		}
true					{ return TOKEN_TRUE;		}
false					{ return TOKEN_FALSE;		}
for 					{ return TOKEN_FOR; 		}
function				{ return TOKEN_FUNC;		}
if						{ return TOKEN_IF;			}
integer					{ return TOKEN_INT; 		}
print					{ return TOKEN_PRINT; 		}
return					{ return TOKEN_RETURN;		}
string					{ return TOKEN_STR;			}
void					{ return TOKEN_VOID;		}
while            		{ return TOKEN_WHILE;   	}

;						{ return TOKEN_SEMI;		}
:						{ return TOKEN_COLON;		}
,						{ return TOKEN_COMMA;		}
\[						{ return TOKEN_BRACKL;		}
\]						{ return TOKEN_BRACKR;		}
\{						{ return TOKEN_CRLL;		}
\}						{ return TOKEN_CRLR;		}
\(						{ return TOKEN_PARL;		}
\)						{ return TOKEN_PARR;		}

\/+([^\*]|(\*+([^\*\/])))*\*+\/     {                           }
\/\/.*								{                           }


\:\?                        { return TOKEN_TERN;     } 


\!\=	                    { return TOKEN_NE;	    }
\<						    { return TOKEN_LT;		}
\<\=                        { return TOKEN_LTE;     }
\>						    { return TOKEN_GT;		}
\>\=                        { return TOKEN_GTE;     }
\=\=                        { return TOKEN_COMP;    }


\+                          { return TOKEN_ADD;     }
-						    { return TOKEN_SUB;		}
\/						    { return TOKEN_DIV;		}
\*						    { return TOKEN_MULT;	}
\%						    { return TOKEN_MOD;		}
\^						    { return TOKEN_EXP;		}
\|\|					    { return TOKEN_LOGOR;	}
\&\&					    { return TOKEN_LOGAND;	}

\!                     		{ return  TOKEN_NOT;    }
\+\+					    { return TOKEN_POSIN;	}
\-\-					    { return TOKEN_POSDEC;	}
\=                          { return TOKEN_ASSIGN;  }



\'\\?{ALNUM}\'				    { return TOKEN_CHARLIT;	}
\"(?:[^\\\"\n]|\\.){0,255}\"	{ return TOKEN_STRLIT;	}



[_a-zA-Z][_a-zA-Z0-9]{0,255}   	{ return TOKEN_IDENT;   }
{DIGIT}+                		{ return TOKEN_NUMBER;  }
<<EOF>>                         { return TOKEN_EOF;      }
.                       		{  printf("scan error: bad token: %c\n",yytext[0]); return TOKEN_ERROR;   }

%%

/* Additional Code */


int yywrap()    { return 1;}
