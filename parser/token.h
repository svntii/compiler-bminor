/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_TOKEN_H_INCLUDED
# define YY_YY_TOKEN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_ARRAY = 258,
    TOKEN_AUTO = 259,
    TOKEN_BOOL = 260,
    TOKEN_CHAR = 261,
    TOKEN_ELSE = 262,
    TOKEN_TRUE = 263,
    TOKEN_FALSE = 264,
    TOKEN_FOR = 265,
    TOKEN_FUNC = 266,
    TOKEN_IF = 267,
    TOKEN_INT = 268,
    TOKEN_PRINT = 269,
    TOKEN_RETURN = 270,
    TOKEN_STR = 271,
    TOKEN_VOID = 272,
    TOKEN_WHILE = 273,
    TOKEN_SEMI = 274,
    TOKEN_COLON = 275,
    TOKEN_COMMA = 276,
    TOKEN_BRACKL = 277,
    TOKEN_BRACKR = 278,
    TOKEN_CRLL = 279,
    TOKEN_CRLR = 280,
    TOKEN_PARL = 281,
    TOKEN_PARR = 282,
    TOKEN_TERN = 283,
    TOKEN_NE = 284,
    TOKEN_LT = 285,
    TOKEN_LTE = 286,
    TOKEN_GT = 287,
    TOKEN_GTE = 288,
    TOKEN_COMP = 289,
    TOKEN_ADD = 290,
    TOKEN_SUB = 291,
    TOKEN_DIV = 292,
    TOKEN_MULT = 293,
    TOKEN_MOD = 294,
    TOKEN_EXP = 295,
    TOKEN_LOGOR = 296,
    TOKEN_LOGAND = 297,
    TOKEN_NOT = 298,
    TOKEN_POSDEC = 299,
    TOKEN_POSIN = 300,
    TOKEN_ASSIGN = 301,
    TOKEN_CHARLIT = 302,
    TOKEN_STRLIT = 303,
    TOKEN_IDENT = 304,
    TOKEN_NUMBER = 305,
    TOKEN_ERROR = 306,
    TOKEN_COMMENT = 307,
    TOKEN_EOF = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKEN_H_INCLUDED  */
