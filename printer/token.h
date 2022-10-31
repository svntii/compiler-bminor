/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TOKEN_H_INCLUDED
# define YY_YY_TOKEN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_ARRAY = 258,             /* TOKEN_ARRAY  */
    TOKEN_AUTO = 259,              /* TOKEN_AUTO  */
    TOKEN_BOOL = 260,              /* TOKEN_BOOL  */
    TOKEN_CHAR = 261,              /* TOKEN_CHAR  */
    TOKEN_ELSE = 262,              /* TOKEN_ELSE  */
    TOKEN_TRUE = 263,              /* TOKEN_TRUE  */
    TOKEN_FALSE = 264,             /* TOKEN_FALSE  */
    TOKEN_FOR = 265,               /* TOKEN_FOR  */
    TOKEN_FUNC = 266,              /* TOKEN_FUNC  */
    TOKEN_IF = 267,                /* TOKEN_IF  */
    TOKEN_INT = 268,               /* TOKEN_INT  */
    TOKEN_PRINT = 269,             /* TOKEN_PRINT  */
    TOKEN_RETURN = 270,            /* TOKEN_RETURN  */
    TOKEN_STR = 271,               /* TOKEN_STR  */
    TOKEN_VOID = 272,              /* TOKEN_VOID  */
    TOKEN_SEMI = 273,              /* ";"  */
    TOKEN_COLON = 274,             /* ":"  */
    TOKEN_COMMA = 275,             /* ","  */
    TOKEN_BRACKL = 276,            /* "["  */
    TOKEN_BRACKR = 277,            /* "]"  */
    TOKEN_CRLL = 278,              /* "{"  */
    TOKEN_CRLR = 279,              /* "}"  */
    TOKEN_PARL = 280,              /* "("  */
    TOKEN_PARR = 281,              /* ")"  */
    TOKEN_TERN = 282,              /* "?"  */
    TOKEN_NE = 283,                /* "!="  */
    TOKEN_LT = 284,                /* "<"  */
    TOKEN_LTE = 285,               /* "<="  */
    TOKEN_GT = 286,                /* ">"  */
    TOKEN_GTE = 287,               /* ">="  */
    TOKEN_COMP = 288,              /* "=="  */
    TOKEN_ADD = 289,               /* "+"  */
    TOKEN_SUB = 290,               /* "-"  */
    TOKEN_DIV = 291,               /* "/"  */
    TOKEN_MULT = 292,              /* "*"  */
    TOKEN_MOD = 293,               /* "%"  */
    TOKEN_EXP = 294,               /* "^"  */
    TOKEN_LOGOR = 295,             /* "||"  */
    TOKEN_LOGAND = 296,            /* "&&"  */
    TOKEN_NOT = 297,               /* "!"  */
    TOKEN_POSDEC = 298,            /* "--"  */
    TOKEN_POSIN = 299,             /* "++"  */
    TOKEN_ASSIGN = 300,            /* "="  */
    TOKEN_CHARLIT = 301,           /* TOKEN_CHARLIT  */
    TOKEN_STRLIT = 302,            /* TOKEN_STRLIT  */
    TOKEN_IDENT = 303,             /* TOKEN_IDENT  */
    TOKEN_NUMBER = 304,            /* TOKEN_NUMBER  */
    TOKEN_EOF = 305,               /* TOKEN_EOF  */
    TOKEN_WHILE = 306,             /* TOKEN_WHILE  */
    TOKEN_ERROR = 307,             /* TOKEN_ERROR  */
    TOKEN_COMMENT = 308            /* TOKEN_COMMENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 62 "parser.bison"

	struct decl *decl;
	struct stmt *stmt;
	struct expr *expr;
	char * name;
	struct type *type;
	struct param_list *param_list;

#line 126 "token.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TOKEN_H_INCLUDED  */
