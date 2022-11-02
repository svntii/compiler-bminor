/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.bison"

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


#line 94 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "token.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_ARRAY = 3,                /* TOKEN_ARRAY  */
  YYSYMBOL_TOKEN_AUTO = 4,                 /* TOKEN_AUTO  */
  YYSYMBOL_TOKEN_BOOL = 5,                 /* TOKEN_BOOL  */
  YYSYMBOL_TOKEN_CHAR = 6,                 /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_ELSE = 7,                 /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_TRUE = 8,                 /* TOKEN_TRUE  */
  YYSYMBOL_TOKEN_FALSE = 9,                /* TOKEN_FALSE  */
  YYSYMBOL_TOKEN_FOR = 10,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_FUNC = 11,                /* TOKEN_FUNC  */
  YYSYMBOL_TOKEN_IF = 12,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_INT = 13,                 /* TOKEN_INT  */
  YYSYMBOL_TOKEN_PRINT = 14,               /* TOKEN_PRINT  */
  YYSYMBOL_TOKEN_RETURN = 15,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_STR = 16,                 /* TOKEN_STR  */
  YYSYMBOL_TOKEN_VOID = 17,                /* TOKEN_VOID  */
  YYSYMBOL_TOKEN_SEMI = 18,                /* ";"  */
  YYSYMBOL_TOKEN_COLON = 19,               /* ":"  */
  YYSYMBOL_TOKEN_COMMA = 20,               /* ","  */
  YYSYMBOL_TOKEN_BRACKL = 21,              /* "["  */
  YYSYMBOL_TOKEN_BRACKR = 22,              /* "]"  */
  YYSYMBOL_TOKEN_CRLL = 23,                /* "{"  */
  YYSYMBOL_TOKEN_CRLR = 24,                /* "}"  */
  YYSYMBOL_TOKEN_PARL = 25,                /* "("  */
  YYSYMBOL_TOKEN_PARR = 26,                /* ")"  */
  YYSYMBOL_TOKEN_TERN = 27,                /* "?"  */
  YYSYMBOL_TOKEN_NE = 28,                  /* "!="  */
  YYSYMBOL_TOKEN_LT = 29,                  /* "<"  */
  YYSYMBOL_TOKEN_LTE = 30,                 /* "<="  */
  YYSYMBOL_TOKEN_GT = 31,                  /* ">"  */
  YYSYMBOL_TOKEN_GTE = 32,                 /* ">="  */
  YYSYMBOL_TOKEN_COMP = 33,                /* "=="  */
  YYSYMBOL_TOKEN_ADD = 34,                 /* "+"  */
  YYSYMBOL_TOKEN_SUB = 35,                 /* "-"  */
  YYSYMBOL_TOKEN_DIV = 36,                 /* "/"  */
  YYSYMBOL_TOKEN_MULT = 37,                /* "*"  */
  YYSYMBOL_TOKEN_MOD = 38,                 /* "%"  */
  YYSYMBOL_TOKEN_EXP = 39,                 /* "^"  */
  YYSYMBOL_TOKEN_LOGOR = 40,               /* "||"  */
  YYSYMBOL_TOKEN_LOGAND = 41,              /* "&&"  */
  YYSYMBOL_TOKEN_NOT = 42,                 /* "!"  */
  YYSYMBOL_TOKEN_POSDEC = 43,              /* "--"  */
  YYSYMBOL_TOKEN_POSIN = 44,               /* "++"  */
  YYSYMBOL_TOKEN_ASSIGN = 45,              /* "="  */
  YYSYMBOL_TOKEN_CHARLIT = 46,             /* TOKEN_CHARLIT  */
  YYSYMBOL_TOKEN_STRLIT = 47,              /* TOKEN_STRLIT  */
  YYSYMBOL_TOKEN_IDENT = 48,               /* TOKEN_IDENT  */
  YYSYMBOL_TOKEN_NUMBER = 49,              /* TOKEN_NUMBER  */
  YYSYMBOL_TOKEN_EOF = 50,                 /* TOKEN_EOF  */
  YYSYMBOL_TOKEN_WHILE = 51,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_ERROR = 52,               /* TOKEN_ERROR  */
  YYSYMBOL_TOKEN_COMMENT = 53,             /* TOKEN_COMMENT  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_decl_list = 56,                 /* decl_list  */
  YYSYMBOL_decl = 57,                      /* decl  */
  YYSYMBOL_name = 58,                      /* name  */
  YYSYMBOL_decl_stmnt = 59,                /* decl_stmnt  */
  YYSYMBOL_auto_decl = 60,                 /* auto_decl  */
  YYSYMBOL_type_decl = 61,                 /* type_decl  */
  YYSYMBOL_auto_decl_args = 62,            /* auto_decl_args  */
  YYSYMBOL_type_decl_args = 63,            /* type_decl_args  */
  YYSYMBOL_decl_args_epsilon = 64,         /* decl_args_epsilon  */
  YYSYMBOL_decl_args = 65,                 /* decl_args  */
  YYSYMBOL_decl_args_end = 66,             /* decl_args_end  */
  YYSYMBOL_statement = 67,                 /* statement  */
  YYSYMBOL_stmnt_list = 68,                /* stmnt_list  */
  YYSYMBOL_body = 69,                      /* body  */
  YYSYMBOL_if_term = 70,                   /* if_term  */
  YYSYMBOL_for_arg = 71,                   /* for_arg  */
  YYSYMBOL_return_types = 72,              /* return_types  */
  YYSYMBOL_expr_epsilon = 73,              /* expr_epsilon  */
  YYSYMBOL_expr_list = 74,                 /* expr_list  */
  YYSYMBOL_expr = 75,                      /* expr  */
  YYSYMBOL_or = 76,                        /* or  */
  YYSYMBOL_and = 77,                       /* and  */
  YYSYMBOL_comparison = 78,                /* comparison  */
  YYSYMBOL_term = 79,                      /* term  */
  YYSYMBOL_factor = 80,                    /* factor  */
  YYSYMBOL_exponent = 81,                  /* exponent  */
  YYSYMBOL_unary = 82,                     /* unary  */
  YYSYMBOL_postfix = 83,                   /* postfix  */
  YYSYMBOL_pre_atomic = 84,                /* pre_atomic  */
  YYSYMBOL_ident_assign = 85,              /* ident_assign  */
  YYSYMBOL_atomic = 86,                    /* atomic  */
  YYSYMBOL_atomic_array_epsilon = 87,      /* atomic_array_epsilon  */
  YYSYMBOL_atomic_array = 88,              /* atomic_array  */
  YYSYMBOL_atomic_array_end = 89,          /* atomic_array_end  */
  YYSYMBOL_arg_epsilon = 90,               /* arg_epsilon  */
  YYSYMBOL_arg_list = 91,                  /* arg_list  */
  YYSYMBOL_arg_list_end = 92,              /* arg_list_end  */
  YYSYMBOL_array_end = 93,                 /* array_end  */
  YYSYMBOL_inside_arr = 94                 /* inside_arr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   279

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  225

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   107,   107,   110,   111,   114,   115,   116,   119,   121,
     122,   125,   126,   129,   130,   131,   132,   133,   136,   137,
     140,   141,   142,   143,   144,   145,   148,   149,   151,   154,
     155,   158,   159,   160,   161,   162,   163,   164,   165,   168,
     169,   172,   176,   177,   178,   179,   180,   181,   182,   188,
     189,   192,   193,   194,   195,   196,   197,   200,   201,   204,
     205,   208,   209,   210,   213,   214,   217,   218,   221,   222,
     223,   224,   225,   226,   227,   230,   231,   232,   235,   236,
     237,   238,   241,   242,   245,   246,   247,   250,   251,   252,
     255,   256,   257,   258,   262,   263,   268,   269,   270,   271,
     272,   273,   274,   277,   278,   281,   284,   285,   287,   288,
     291,   294,   295,   299,   300,   303,   304
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_ARRAY",
  "TOKEN_AUTO", "TOKEN_BOOL", "TOKEN_CHAR", "TOKEN_ELSE", "TOKEN_TRUE",
  "TOKEN_FALSE", "TOKEN_FOR", "TOKEN_FUNC", "TOKEN_IF", "TOKEN_INT",
  "TOKEN_PRINT", "TOKEN_RETURN", "TOKEN_STR", "TOKEN_VOID", "\";\"",
  "\":\"", "\",\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\"(\"", "\")\"",
  "\"?\"", "\"!=\"", "\"<\"", "\"<=\"", "\">\"", "\">=\"", "\"==\"",
  "\"+\"", "\"-\"", "\"/\"", "\"*\"", "\"%\"", "\"^\"", "\"||\"", "\"&&\"",
  "\"!\"", "\"--\"", "\"++\"", "\"=\"", "TOKEN_CHARLIT", "TOKEN_STRLIT",
  "TOKEN_IDENT", "TOKEN_NUMBER", "TOKEN_EOF", "TOKEN_WHILE", "TOKEN_ERROR",
  "TOKEN_COMMENT", "$accept", "program", "decl_list", "decl", "name",
  "decl_stmnt", "auto_decl", "type_decl", "auto_decl_args",
  "type_decl_args", "decl_args_epsilon", "decl_args", "decl_args_end",
  "statement", "stmnt_list", "body", "if_term", "for_arg", "return_types",
  "expr_epsilon", "expr_list", "expr", "or", "and", "comparison", "term",
  "factor", "exponent", "unary", "postfix", "pre_atomic", "ident_assign",
  "atomic", "atomic_array_epsilon", "atomic_array", "atomic_array_end",
  "arg_epsilon", "arg_list", "arg_list_end", "array_end", "inside_arr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-175)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-108)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -34,  -175,    22,    -5,   -34,    29,  -175,  -175,  -175,   228,
      21,  -175,  -175,  -175,   246,  -175,  -175,     6,  -175,   138,
    -175,  -175,   246,  -175,  -175,  -175,    31,   138,    66,  -175,
    -175,    82,   138,   138,   138,  -175,  -175,  -175,    73,  -175,
     -20,    46,   236,   -23,    84,    58,  -175,  -175,    16,    54,
    -175,    79,  -175,   -34,  -175,  -175,  -175,    93,    78,  -175,
      81,    -4,  -175,  -175,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,  -175,  -175,   138,   188,    96,   100,  -175,    82,  -175,
    -175,  -175,   138,   110,   114,   112,  -175,   121,    46,   236,
     -23,   -23,   -23,   -23,   -23,   -23,    84,    84,    58,    58,
      58,  -175,  -175,  -175,   242,    -8,  -175,   132,   136,   138,
    -175,  -175,   138,   137,  -175,  -175,  -175,   246,  -175,  -175,
     142,  -175,  -175,   144,   136,   138,   126,  -175,  -175,   138,
    -175,   -34,  -175,    15,  -175,  -175,   154,   155,  -175,   153,
     156,   138,   138,    15,    -6,    15,   159,  -175,   170,   136,
     242,   138,   138,   171,  -175,   176,   180,    23,   188,  -175,
    -175,  -175,  -175,  -175,   182,  -175,   177,  -175,   138,  -175,
       6,   138,   102,  -175,   189,   190,   184,   185,   138,   138,
       7,  -175,   205,   207,   198,  -175,   138,   138,   138,   199,
     200,   188,    15,   214,   196,   206,   203,   218,   219,     6,
    -175,    15,   138,   102,   209,  -175,   217,   229,   231,   138,
     102,   216,  -175,   102,  -175
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     8,     0,     0,     4,     0,     1,     2,     3,     0,
       0,    11,    14,    15,     0,    13,    16,    10,    12,   116,
      53,    54,     0,    52,    55,    51,     0,     0,     0,    99,
     100,   104,     0,     0,     0,    98,    97,    96,   101,   115,
      63,    65,    67,    74,    77,    81,    83,    86,    89,     0,
      93,     0,    56,    27,     9,     5,   101,   107,     0,   103,
       0,   101,    84,    85,   116,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    87,     0,     0,     0,     0,    26,     0,   105,
     102,    92,   116,     0,   112,     0,   108,     0,    64,    66,
      73,    70,    71,    68,    69,    72,    75,    76,    79,    78,
      80,    82,    61,    17,     0,     0,   106,     0,   114,     0,
     110,    90,     0,     0,    18,    21,    22,     0,    20,    23,
      30,    19,     6,     0,   114,   116,    91,   111,    62,   116,
      25,     0,    28,     0,     7,    91,     0,     0,    29,     0,
       0,    58,     0,   104,   101,    40,     0,    35,     0,   114,
       0,    50,     0,     0,    57,    60,     0,    93,     0,    39,
      41,    38,   113,    24,     0,    49,     0,    36,     0,    33,
      10,    50,     0,    59,     0,     0,     0,     0,    58,     0,
     101,    31,    35,     0,     0,    37,    50,    50,     0,     0,
       0,     0,     0,    38,     0,     0,     0,    36,    33,    10,
      32,     0,    50,     0,     0,    34,     0,     0,    37,    50,
       0,     0,    42,     0,    44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,   239,  -175,     0,  -174,   -82,  -175,    89,  -175,
    -175,   109,  -175,   -78,    99,  -128,  -117,   -22,   -19,    68,
      83,    17,  -175,   193,   208,   201,   -10,    87,   -25,  -175,
    -175,  -175,   -30,  -175,   191,  -175,  -175,   158,  -175,  -118,
     -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    38,    28,    17,    18,   130,   131,
      86,    87,   142,   155,   156,   157,   193,   174,    26,   163,
     164,   175,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    58,    59,    89,    95,    96,   120,   136,
      51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,    57,   113,    52,     5,   144,   184,    66,    62,    63,
     132,    75,    76,   168,     1,    64,   145,    92,    93,    65,
      67,    65,     6,    29,    30,   149,   201,   150,    64,   151,
     152,    56,    65,    61,    61,   214,    39,   133,   153,   -94,
      32,   172,    19,    88,    54,     7,   117,  -107,     9,    60,
      33,    27,   -94,    85,   192,   111,    53,    34,    57,    81,
      82,    35,    36,     1,    37,   106,   107,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    39,    94,    97,    55,   192,   180,    68,    56,   146,
      29,    30,   192,   147,    64,   192,   217,    80,    65,    83,
     112,    84,    90,   222,   191,    31,   224,    91,   140,    39,
      29,    30,   186,    88,   187,   114,   188,   189,   -94,   209,
      77,    78,    79,   167,   210,   153,   115,    32,    35,    36,
       1,    37,   118,   215,   119,   191,    94,    33,   121,   138,
     122,    85,   210,   154,    34,   215,    29,    30,    35,    36,
       1,    37,    39,   154,   134,   154,    39,   135,   139,   185,
     158,    31,   141,    32,   108,   109,   110,   143,   165,   166,
     158,   -95,   158,    33,   204,   205,   159,   160,   161,   176,
      34,   162,   190,   170,    35,    36,     1,    37,   171,   177,
     216,    10,    11,    12,    13,   165,   178,   221,   179,   194,
     181,    15,   154,   182,    16,   165,   200,   195,   196,   197,
     198,   154,   -45,   190,   202,   206,   203,   207,   208,   158,
     190,   -48,   211,   190,   212,   -46,   -43,   218,   158,   213,
     194,    10,    11,    12,    13,   219,   220,   194,   -47,    14,
     194,    15,   223,     8,    16,   123,   124,   125,   126,   173,
     148,    20,    21,   127,   169,   128,   199,    22,   129,    23,
      98,   183,    24,    25,    69,    70,    71,    72,    73,    74,
     100,   101,   102,   103,   104,   105,    99,   137,     0,   116
};

static const yytype_int16 yycheck[] =
{
       0,    31,    84,    22,     4,   133,   180,    27,    33,    34,
      18,    34,    35,    19,    48,    21,   134,    21,    64,    25,
      40,    25,     0,     8,     9,    10,    19,    12,    21,    14,
      15,    31,    25,    33,    34,   209,    19,    45,    23,    45,
      25,   159,    21,    20,    27,    50,    92,    24,    19,    32,
      35,    45,    45,    53,   182,    80,    25,    42,    88,    43,
      44,    46,    47,    48,    49,    75,    76,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    64,    65,    66,    18,   213,   168,    41,    88,   135,
       8,     9,   220,   139,    21,   223,   213,    39,    25,    45,
      83,    22,    24,   220,   182,    23,   223,    26,   127,    92,
       8,     9,    10,    20,    12,    19,    14,    15,    45,   201,
      36,    37,    38,   153,   202,    23,    26,    25,    46,    47,
      48,    49,    22,   211,    20,   213,   119,    35,    26,   122,
      19,   141,   220,   143,    42,   223,     8,     9,    46,    47,
      48,    49,   135,   153,    22,   155,   139,    21,    21,   181,
     143,    23,    20,    25,    77,    78,    79,    23,   151,   152,
     153,    45,   155,    35,   196,   197,    22,    22,    25,   162,
      42,    25,   182,    24,    46,    47,    48,    49,    18,    18,
     212,     3,     4,     5,     6,   178,    20,   219,    18,   182,
      18,    13,   202,    26,    16,   188,   189,    18,    18,    25,
      25,   211,     7,   213,     7,   198,    18,    18,    18,   202,
     220,     7,    26,   223,    18,     7,     7,    18,   211,    26,
     213,     3,     4,     5,     6,    18,     7,   220,     7,    11,
     223,    13,    26,     4,    16,     3,     4,     5,     6,   160,
     141,     5,     6,    11,   155,    13,   188,    11,    16,    13,
      67,   178,    16,    17,    28,    29,    30,    31,    32,    33,
      69,    70,    71,    72,    73,    74,    68,   119,    -1,    88
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    55,    56,    57,    58,     0,    50,    56,    19,
       3,     4,     5,     6,    11,    13,    16,    60,    61,    21,
       5,     6,    11,    13,    16,    17,    72,    45,    59,     8,
       9,    23,    25,    35,    42,    46,    47,    49,    58,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    94,    72,    25,    75,    18,    58,    86,    87,    88,
      75,    58,    82,    82,    21,    25,    27,    40,    41,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    43,    44,    45,    22,    58,    64,    65,    20,    89,
      24,    26,    21,    94,    75,    90,    91,    75,    77,    78,
      79,    79,    79,    79,    79,    79,    80,    80,    81,    81,
      81,    82,    75,    60,    19,    26,    88,    94,    22,    20,
      92,    26,    19,     3,     4,     5,     6,    11,    13,    16,
      62,    63,    18,    45,    22,    21,    93,    91,    75,    21,
      72,    20,    66,    23,    69,    93,    94,    94,    65,    10,
      12,    14,    15,    23,    58,    67,    68,    69,    75,    22,
      22,    25,    25,    73,    74,    75,    75,    86,    19,    68,
      24,    18,    93,    62,    71,    75,    75,    18,    20,    18,
      60,    18,    26,    74,    59,    71,    10,    12,    14,    15,
      58,    67,    69,    70,    75,    18,    18,    25,    25,    73,
      75,    19,     7,    18,    71,    71,    75,    18,    18,    60,
      67,    26,    18,    26,    59,    67,    71,    70,    18,    18,
       7,    71,    70,    26,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    58,    59,
      59,    60,    60,    61,    61,    61,    61,    61,    62,    62,
      63,    63,    63,    63,    63,    63,    64,    64,    65,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    69,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    73,    73,    74,
      74,    75,    75,    75,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    79,    79,    79,    80,    80,
      80,    80,    81,    81,    82,    82,    82,    83,    83,    83,
      84,    84,    84,    84,    85,    85,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    88,    89,    89,    90,    90,
      91,    92,    92,    93,    93,    94,    94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     5,     8,     9,     1,     2,
       0,     1,     1,     1,     1,     1,     1,     5,     1,     1,
       1,     1,     1,     1,     5,     2,     1,     0,     4,     2,
       0,     5,     7,     3,     9,     1,     3,     5,     2,     2,
       1,     3,     7,     3,     9,     1,     3,     5,     2,     1,
       0,     1,     1,     1,     1,     1,     2,     1,     0,     3,
       1,     3,     5,     1,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     3,     1,     2,     2,     1,     2,     2,     1,
       4,     5,     3,     1,     1,     5,     1,     1,     1,     1,
       1,     1,     3,     1,     0,     2,     2,     0,     1,     0,
       2,     2,     0,     4,     0,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: decl_list TOKEN_EOF  */
#line 107 "parser.bison"
                                                                                        { parser_result = (yyvsp[-1].decl); return 0; }
#line 1342 "parser.c"
    break;

  case 3: /* decl_list: decl decl_list  */
#line 110 "parser.bison"
                                                                                                { (yyval.decl) = (yyvsp[-1].decl); (yyvsp[-1].decl)->next = (yyvsp[0].decl);	}
#line 1348 "parser.c"
    break;

  case 4: /* decl_list: %empty  */
#line 111 "parser.bison"
                                                                                                                        { (yyval.decl) = 0;					}
#line 1354 "parser.c"
    break;

  case 5: /* decl: name ":" auto_decl decl_stmnt ";"  */
#line 114 "parser.bison"
                                                                                                                { (yyval.decl) = decl_create((yyvsp[-4].name), (yyvsp[-2].type), (yyvsp[-1].expr), 0, 0);  }
#line 1360 "parser.c"
    break;

  case 6: /* decl: name ":" TOKEN_FUNC return_types "(" decl_args_epsilon ")" ";"  */
#line 115 "parser.bison"
                                                                                                                                                                   { (yyval.decl) = decl_create((yyvsp[-7].name), type_create(TYPE_FUNCTION, (yyvsp[-4].type), (yyvsp[-2].param_list), 0,0), 0, 0, 0);  }
#line 1366 "parser.c"
    break;

  case 7: /* decl: name ":" TOKEN_FUNC return_types "(" decl_args_epsilon ")" "=" body  */
#line 116 "parser.bison"
                                                                                                                                                  { (yyval.decl) = decl_create((yyvsp[-8].name), type_create(TYPE_FUNCTION, (yyvsp[-5].type), (yyvsp[-3].param_list), 0,0), 0, (yyvsp[0].stmt), 0); }
#line 1372 "parser.c"
    break;

  case 8: /* name: TOKEN_IDENT  */
#line 119 "parser.bison"
                                                        { (yyval.name) = strdup(yytext); }
#line 1378 "parser.c"
    break;

  case 9: /* decl_stmnt: "=" expr  */
#line 121 "parser.bison"
                                                { (yyval.expr) = (yyvsp[0].expr);	}
#line 1384 "parser.c"
    break;

  case 10: /* decl_stmnt: %empty  */
#line 122 "parser.bison"
                                                                                { (yyval.expr) = 0; 	}
#line 1390 "parser.c"
    break;

  case 11: /* auto_decl: TOKEN_AUTO  */
#line 125 "parser.bison"
                                                                { (yyval.type) = type_create(TYPE_AUTO, 0, 0, 0, 0); 	}
#line 1396 "parser.c"
    break;

  case 12: /* auto_decl: type_decl  */
#line 126 "parser.bison"
                                                                        { (yyval.type) = (yyvsp[0].type);	}
#line 1402 "parser.c"
    break;

  case 13: /* type_decl: TOKEN_INT  */
#line 129 "parser.bison"
                                                                { (yyval.type) = type_create(TYPE_INTEGER, 0, 0, 0,0);	}
#line 1408 "parser.c"
    break;

  case 14: /* type_decl: TOKEN_BOOL  */
#line 130 "parser.bison"
                                                                        { (yyval.type) = type_create(TYPE_BOOLEAN, 0, 0, 0, 0);	}
#line 1414 "parser.c"
    break;

  case 15: /* type_decl: TOKEN_CHAR  */
#line 131 "parser.bison"
                                                                        { (yyval.type) = type_create(TYPE_CHAR,	 0, 0, 0, 0); }
#line 1420 "parser.c"
    break;

  case 16: /* type_decl: TOKEN_STR  */
#line 132 "parser.bison"
                                                                        { (yyval.type) = type_create(TYPE_STRING,  0, 0, 0, 0);	}
#line 1426 "parser.c"
    break;

  case 17: /* type_decl: TOKEN_ARRAY "[" inside_arr "]" auto_decl  */
#line 133 "parser.bison"
                                                                                           { (yyval.type) = type_create( TYPE_ARRAY,(yyvsp[0].type), 0, 0, 0);  }
#line 1432 "parser.c"
    break;

  case 18: /* auto_decl_args: TOKEN_AUTO  */
#line 136 "parser.bison"
                                                { (yyval.type) = type_create(TYPE_AUTO, 0, 0, 0,0);	}
#line 1438 "parser.c"
    break;

  case 19: /* auto_decl_args: type_decl_args  */
#line 137 "parser.bison"
                                                        { (yyval.type) = (yyvsp[0].type);							}
#line 1444 "parser.c"
    break;

  case 20: /* type_decl_args: TOKEN_INT  */
#line 140 "parser.bison"
                                                { (yyval.type) = type_create(TYPE_INTEGER, 0, 0, 0, 0);	}
#line 1450 "parser.c"
    break;

  case 21: /* type_decl_args: TOKEN_BOOL  */
#line 141 "parser.bison"
                                                                { (yyval.type) = type_create(TYPE_BOOLEAN, 0, 0, 0, 0);	}
#line 1456 "parser.c"
    break;

  case 22: /* type_decl_args: TOKEN_CHAR  */
#line 142 "parser.bison"
                                                                { (yyval.type) = type_create(TYPE_CHAR,    0, 0, 0, 0); }
#line 1462 "parser.c"
    break;

  case 23: /* type_decl_args: TOKEN_STR  */
#line 143 "parser.bison"
                                                                { (yyval.type) = type_create(TYPE_STRING,  0, 0, 0, 0); }
#line 1468 "parser.c"
    break;

  case 24: /* type_decl_args: TOKEN_ARRAY "[" inside_arr "]" auto_decl_args  */
#line 144 "parser.bison"
                                                                                                        { (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[0].type), 0, (yyvsp[-2].expr), 0);  }
#line 1474 "parser.c"
    break;

  case 25: /* type_decl_args: TOKEN_FUNC return_types  */
#line 145 "parser.bison"
                                                                { (yyval.type) = type_create(TYPE_FUNCTION, (yyvsp[0].type), 0, 0, 0); }
#line 1480 "parser.c"
    break;

  case 26: /* decl_args_epsilon: decl_args  */
#line 148 "parser.bison"
                                      { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1486 "parser.c"
    break;

  case 27: /* decl_args_epsilon: %empty  */
#line 149 "parser.bison"
                                                                  { (yyval.param_list) = 0;  }
#line 1492 "parser.c"
    break;

  case 28: /* decl_args: name ":" auto_decl_args decl_args_end  */
#line 151 "parser.bison"
                                                                                { (yyval.param_list) = param_list_create((yyvsp[-3].name), (yyvsp[-1].type), 0 ,(yyvsp[0].param_list)) ;   }
#line 1498 "parser.c"
    break;

  case 29: /* decl_args_end: "," decl_args  */
#line 154 "parser.bison"
                                              {	(yyval.param_list) = (yyvsp[0].param_list);	}
#line 1504 "parser.c"
    break;

  case 30: /* decl_args_end: %empty  */
#line 155 "parser.bison"
                                        {(yyval.param_list) = 0;}
#line 1510 "parser.c"
    break;

  case 31: /* statement: TOKEN_IF "(" expr ")" statement  */
#line 158 "parser.bison"
                                                                                                                { (yyval.stmt) = stmt_create_if((yyvsp[-2].expr), (yyvsp[0].stmt));			}
#line 1516 "parser.c"
    break;

  case 32: /* statement: TOKEN_IF "(" expr ")" if_term TOKEN_ELSE statement  */
#line 159 "parser.bison"
                                                                                                        { (yyval.stmt) = stmt_create_if_else((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt));	}
#line 1522 "parser.c"
    break;

  case 33: /* statement: TOKEN_RETURN expr ";"  */
#line 160 "parser.bison"
                                                                                                                                        { (yyval.stmt) = stmt_create_return((yyvsp[-1].expr));			}
#line 1528 "parser.c"
    break;

  case 34: /* statement: TOKEN_FOR "(" for_arg ";" for_arg ";" for_arg ")" statement  */
#line 161 "parser.bison"
                                                                                                                             { (yyval.stmt) = stmt_create_for((yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt));}
#line 1534 "parser.c"
    break;

  case 35: /* statement: body  */
#line 162 "parser.bison"
                                                                                                                                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1540 "parser.c"
    break;

  case 36: /* statement: TOKEN_PRINT expr_epsilon ";"  */
#line 163 "parser.bison"
                                                                                                                                { (yyval.stmt) = stmt_create_print((yyvsp[-1].expr));			}
#line 1546 "parser.c"
    break;

  case 37: /* statement: name ":" auto_decl decl_stmnt ";"  */
#line 164 "parser.bison"
                                                                                                                { (yyval.stmt) = stmt_create_decl( decl_create((yyvsp[-4].name), (yyvsp[-2].type), (yyvsp[-1].expr), 0, 0) );	}
#line 1552 "parser.c"
    break;

  case 38: /* statement: expr ";"  */
#line 165 "parser.bison"
                                                                                                                                                        { (yyval.stmt) = stmt_create_expr((yyvsp[-1].expr));			}
#line 1558 "parser.c"
    break;

  case 39: /* stmnt_list: statement stmnt_list  */
#line 168 "parser.bison"
                                                                                                                                        { (yyval.stmt) = (yyvsp[-1].stmt); (yyvsp[-1].stmt)->next = (yyvsp[0].stmt); 				}
#line 1564 "parser.c"
    break;

  case 40: /* stmnt_list: statement  */
#line 169 "parser.bison"
                                                                                                                                                                { (yyval.stmt) = (yyvsp[0].stmt); 								}
#line 1570 "parser.c"
    break;

  case 41: /* body: "{" stmnt_list "}"  */
#line 172 "parser.bison"
                                                                                                                                { (yyval.stmt) = stmt_create_block((yyvsp[-1].stmt));	}
#line 1576 "parser.c"
    break;

  case 42: /* if_term: TOKEN_IF "(" expr ")" if_term TOKEN_ELSE if_term  */
#line 176 "parser.bison"
                                                                                                { (yyval.stmt) = stmt_create_if_else((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt));	}
#line 1582 "parser.c"
    break;

  case 43: /* if_term: TOKEN_RETURN expr ";"  */
#line 177 "parser.bison"
                                                                                                                                        { (yyval.stmt) = stmt_create_return((yyvsp[-1].expr));			}
#line 1588 "parser.c"
    break;

  case 44: /* if_term: TOKEN_FOR "(" for_arg ";" for_arg ";" for_arg ")" if_term  */
#line 178 "parser.bison"
                                                                                                                                { (yyval.stmt) = stmt_create_for((yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt));	}
#line 1594 "parser.c"
    break;

  case 45: /* if_term: body  */
#line 179 "parser.bison"
                                                                                                                                                                { (yyval.stmt) = (yyvsp[0].stmt);								}
#line 1600 "parser.c"
    break;

  case 46: /* if_term: TOKEN_PRINT expr_epsilon ";"  */
#line 180 "parser.bison"
                                                                                                                                { (yyval.stmt) = stmt_create_print((yyvsp[-1].expr));			}
#line 1606 "parser.c"
    break;

  case 47: /* if_term: name ":" auto_decl decl_stmnt ";"  */
#line 181 "parser.bison"
                                                                                                                { (yyval.stmt) = stmt_create_decl( decl_create((yyvsp[-4].name), (yyvsp[-2].type), (yyvsp[-1].expr), 0, 0)); 		}
#line 1612 "parser.c"
    break;

  case 48: /* if_term: expr ";"  */
#line 182 "parser.bison"
                                                                                                                                                        { (yyval.stmt) = stmt_create_expr((yyvsp[-1].expr));			}
#line 1618 "parser.c"
    break;

  case 49: /* for_arg: expr  */
#line 188 "parser.bison"
                                {(yyval.expr) = (yyvsp[0].expr);	}
#line 1624 "parser.c"
    break;

  case 50: /* for_arg: %empty  */
#line 189 "parser.bison"
                                                {(yyval.expr) = 0	;	}
#line 1630 "parser.c"
    break;

  case 51: /* return_types: TOKEN_VOID  */
#line 192 "parser.bison"
                                                { (yyval.type) = type_create(TYPE_VOID,    0, 0, 0, 1); }
#line 1636 "parser.c"
    break;

  case 52: /* return_types: TOKEN_INT  */
#line 193 "parser.bison"
                                                                { (yyval.type) = type_create(TYPE_INTEGER, 0, 0, 0, 1); }
#line 1642 "parser.c"
    break;

  case 53: /* return_types: TOKEN_BOOL  */
#line 194 "parser.bison"
                                                                { (yyval.type) = type_create(TYPE_BOOLEAN, 0, 0, 0, 1); }
#line 1648 "parser.c"
    break;

  case 54: /* return_types: TOKEN_CHAR  */
#line 195 "parser.bison"
                                                                { (yyval.type) = type_create(TYPE_CHAR, 	 0, 0, 0, 1); }
#line 1654 "parser.c"
    break;

  case 55: /* return_types: TOKEN_STR  */
#line 196 "parser.bison"
                                                                { (yyval.type) = type_create(TYPE_STRING,  0, 0, 0, 1); }
#line 1660 "parser.c"
    break;

  case 56: /* return_types: TOKEN_FUNC return_types  */
#line 197 "parser.bison"
                                                                { (yyval.type) = type_create(TYPE_FUNCTION, (yyvsp[0].type), 0, 0, 1); }
#line 1666 "parser.c"
    break;

  case 57: /* expr_epsilon: expr_list  */
#line 200 "parser.bison"
                                        { (yyval.expr) = (yyvsp[0].expr);	}
#line 1672 "parser.c"
    break;

  case 58: /* expr_epsilon: %empty  */
#line 201 "parser.bison"
                                                        { (yyval.expr) = 0;	}
#line 1678 "parser.c"
    break;

  case 59: /* expr_list: expr "," expr_list  */
#line 204 "parser.bison"
                                                                { (yyval.expr) = (yyvsp[-2].expr); (yyvsp[-2].expr)->right = (yyvsp[0].expr); }
#line 1684 "parser.c"
    break;

  case 60: /* expr_list: expr  */
#line 205 "parser.bison"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1690 "parser.c"
    break;

  case 61: /* expr: ident_assign "=" expr  */
#line 208 "parser.bison"
                                                                        { (yyval.expr) = expr_create(EXPR_ASSIGNMENT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1696 "parser.c"
    break;

  case 62: /* expr: or "?" expr ":" expr  */
#line 209 "parser.bison"
                                                                                { (yyval.expr) = expr_create(EXPR_TERN, (yyvsp[-4].expr), expr_create(EXPR_TERN, (yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 1702 "parser.c"
    break;

  case 63: /* expr: or  */
#line 210 "parser.bison"
                                                                                                                { (yyval.expr) = (yyvsp[0].expr);		}
#line 1708 "parser.c"
    break;

  case 64: /* or: or "||" and  */
#line 213 "parser.bison"
                                                                                        { (yyval.expr) = expr_create(EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1714 "parser.c"
    break;

  case 65: /* or: and  */
#line 214 "parser.bison"
                                                                                                        { (yyval.expr) = (yyvsp[0].expr);		}
#line 1720 "parser.c"
    break;

  case 66: /* and: and "&&" comparison  */
#line 217 "parser.bison"
                                                                { (yyval.expr) = expr_create(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1726 "parser.c"
    break;

  case 67: /* and: comparison  */
#line 218 "parser.bison"
                                                                                                { (yyval.expr) = (yyvsp[0].expr);		}
#line 1732 "parser.c"
    break;

  case 68: /* comparison: comparison ">" term  */
#line 221 "parser.bison"
                                                                        { (yyval.expr) = expr_create(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1738 "parser.c"
    break;

  case 69: /* comparison: comparison ">=" term  */
#line 222 "parser.bison"
                                                                                { (yyval.expr) = expr_create(EXPR_GTE,(yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1744 "parser.c"
    break;

  case 70: /* comparison: comparison "<" term  */
#line 223 "parser.bison"
                                                                                { (yyval.expr) = expr_create(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1750 "parser.c"
    break;

  case 71: /* comparison: comparison "<=" term  */
#line 224 "parser.bison"
                                                                                { (yyval.expr) = expr_create(EXPR_LTE,(yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1756 "parser.c"
    break;

  case 72: /* comparison: comparison "==" term  */
#line 225 "parser.bison"
                                                                                { (yyval.expr) = expr_create(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1762 "parser.c"
    break;

  case 73: /* comparison: comparison "!=" term  */
#line 226 "parser.bison"
                                                                                { (yyval.expr) = expr_create(EXPR_NEQ,(yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1768 "parser.c"
    break;

  case 74: /* comparison: term  */
#line 227 "parser.bison"
                                                                                                { (yyval.expr) = (yyvsp[0].expr);		}
#line 1774 "parser.c"
    break;

  case 75: /* term: term "+" factor  */
#line 230 "parser.bison"
                                                                        { (yyval.expr) = expr_create(EXPR_ADD,(yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1780 "parser.c"
    break;

  case 76: /* term: term "-" factor  */
#line 231 "parser.bison"
                                                                                { (yyval.expr) = expr_create(EXPR_SUB,(yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1786 "parser.c"
    break;

  case 77: /* term: factor  */
#line 232 "parser.bison"
                                                                                                { (yyval.expr) = (yyvsp[0].expr);		}
#line 1792 "parser.c"
    break;

  case 78: /* factor: factor "*" exponent  */
#line 235 "parser.bison"
                                                                        { (yyval.expr) = expr_create(EXPR_MULT,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1798 "parser.c"
    break;

  case 79: /* factor: factor "/" exponent  */
#line 236 "parser.bison"
                                                                                { (yyval.expr) = expr_create(EXPR_DIV,(yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1804 "parser.c"
    break;

  case 80: /* factor: factor "%" exponent  */
#line 237 "parser.bison"
                                                                                { (yyval.expr) = expr_create(EXPR_MOD,(yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1810 "parser.c"
    break;

  case 81: /* factor: exponent  */
#line 238 "parser.bison"
                                                                                                { (yyval.expr) = (yyvsp[0].expr);		}
#line 1816 "parser.c"
    break;

  case 82: /* exponent: exponent "^" unary  */
#line 241 "parser.bison"
                                                                        { (yyval.expr) = expr_create(EXPR_EXP,(yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1822 "parser.c"
    break;

  case 83: /* exponent: unary  */
#line 242 "parser.bison"
                                                                                                { (yyval.expr) = (yyvsp[0].expr);		}
#line 1828 "parser.c"
    break;

  case 84: /* unary: "-" unary  */
#line 245 "parser.bison"
                                                                                { (yyval.expr) = expr_create(EXPR_NEGATE,(yyvsp[0].expr),0);}
#line 1834 "parser.c"
    break;

  case 85: /* unary: "!" unary  */
#line 246 "parser.bison"
                                                                                        { (yyval.expr) = expr_create(EXPR_NOT   ,(yyvsp[0].expr),0);}
#line 1840 "parser.c"
    break;

  case 86: /* unary: postfix  */
#line 247 "parser.bison"
                                                                                                { (yyval.expr) = (yyvsp[0].expr);		}
#line 1846 "parser.c"
    break;

  case 87: /* postfix: pre_atomic "++"  */
#line 250 "parser.bison"
                                                                        { (yyval.expr) = expr_create(EXPR_POSIN, 0, (yyvsp[-1].expr));}
#line 1852 "parser.c"
    break;

  case 88: /* postfix: pre_atomic "--"  */
#line 251 "parser.bison"
                                                                                { (yyval.expr) = expr_create(EXPR_POSDEC,0, (yyvsp[-1].expr));}
#line 1858 "parser.c"
    break;

  case 89: /* postfix: pre_atomic  */
#line 252 "parser.bison"
                                                                                                { (yyval.expr) = (yyvsp[0].expr);		}
#line 1864 "parser.c"
    break;

  case 90: /* pre_atomic: name "(" arg_epsilon ")"  */
#line 255 "parser.bison"
                                                                                                { (yyval.expr) = expr_create(EXPR_FUNCTION_CALL, expr_create_name((yyvsp[-3].name)), (yyvsp[-1].expr));}
#line 1870 "parser.c"
    break;

  case 91: /* pre_atomic: name "[" inside_arr "]" array_end  */
#line 256 "parser.bison"
                                                                                                              { (yyval.expr) = expr_create(EXPR_SUBSCRIPT, expr_create_name((yyvsp[-4].name)), 0); (yyval.expr)->right = expr_create(EXPR_SUBSCRIPT_SUB, (yyvsp[-2].expr), (yyvsp[0].expr));  }
#line 1876 "parser.c"
    break;

  case 92: /* pre_atomic: "(" expr ")"  */
#line 257 "parser.bison"
                                                                                { (yyval.expr) = expr_create(EXPR_GROUP, (yyvsp[-1].expr), 0); }
#line 1882 "parser.c"
    break;

  case 93: /* pre_atomic: atomic  */
#line 258 "parser.bison"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1888 "parser.c"
    break;

  case 94: /* ident_assign: name  */
#line 262 "parser.bison"
                                                                        { (yyval.expr) = expr_create_name((yyvsp[0].name));  		}
#line 1894 "parser.c"
    break;

  case 95: /* ident_assign: name "[" inside_arr "]" array_end  */
#line 263 "parser.bison"
                                                                                            {(yyval.expr) = expr_create(EXPR_SUBSCRIPT, expr_create_name((yyvsp[-4].name)), 0); (yyval.expr)->right = expr_create(EXPR_SUBSCRIPT_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1900 "parser.c"
    break;

  case 96: /* atomic: TOKEN_NUMBER  */
#line 268 "parser.bison"
                                                        { (yyval.expr) = expr_create_integer_literal(atoi(yytext));  		}
#line 1906 "parser.c"
    break;

  case 97: /* atomic: TOKEN_STRLIT  */
#line 269 "parser.bison"
                                                                { (yyval.expr) = expr_create_string_literal(strdup(yytext));		}
#line 1912 "parser.c"
    break;

  case 98: /* atomic: TOKEN_CHARLIT  */
#line 270 "parser.bison"
                                                                { (yyval.expr) = expr_create_char_literal(*(yytext + 1)); 		}
#line 1918 "parser.c"
    break;

  case 99: /* atomic: TOKEN_TRUE  */
#line 271 "parser.bison"
                                                                        { (yyval.expr) = expr_create_boolean_literal(1);		}
#line 1924 "parser.c"
    break;

  case 100: /* atomic: TOKEN_FALSE  */
#line 272 "parser.bison"
                                                                        { (yyval.expr) = expr_create_boolean_literal(0);		}
#line 1930 "parser.c"
    break;

  case 101: /* atomic: name  */
#line 273 "parser.bison"
                                                                        { (yyval.expr) = expr_create_name((yyvsp[0].name));				}
#line 1936 "parser.c"
    break;

  case 102: /* atomic: "{" atomic_array_epsilon "}"  */
#line 274 "parser.bison"
                                                                                   { (yyval.expr) = expr_create(EXPR_ARRAY_LITERAL, (yyvsp[-1].expr), 0);	}
#line 1942 "parser.c"
    break;

  case 103: /* atomic_array_epsilon: atomic_array  */
#line 277 "parser.bison"
                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1948 "parser.c"
    break;

  case 104: /* atomic_array_epsilon: %empty  */
#line 278 "parser.bison"
                                                                                                        { (yyval.expr) = 0;  }
#line 1954 "parser.c"
    break;

  case 105: /* atomic_array: atomic atomic_array_end  */
#line 281 "parser.bison"
                                                                { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[-1].expr), (yyvsp[0].expr));	}
#line 1960 "parser.c"
    break;

  case 106: /* atomic_array_end: "," atomic_array  */
#line 284 "parser.bison"
                                                                { (yyval.expr) = (yyvsp[0].expr);	}
#line 1966 "parser.c"
    break;

  case 107: /* atomic_array_end: %empty  */
#line 285 "parser.bison"
                                                                                                        { (yyval.expr) = 0; 	}
#line 1972 "parser.c"
    break;

  case 108: /* arg_epsilon: arg_list  */
#line 287 "parser.bison"
                                                                                { (yyval.expr) = (yyvsp[0].expr);}
#line 1978 "parser.c"
    break;

  case 109: /* arg_epsilon: %empty  */
#line 288 "parser.bison"
                                                                                        { (yyval.expr) = 0; }
#line 1984 "parser.c"
    break;

  case 110: /* arg_list: expr arg_list_end  */
#line 291 "parser.bison"
                                                                                { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[-1].expr), (yyvsp[0].expr));		}
#line 1990 "parser.c"
    break;

  case 111: /* arg_list_end: "," arg_list  */
#line 294 "parser.bison"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1996 "parser.c"
    break;

  case 112: /* arg_list_end: %empty  */
#line 295 "parser.bison"
                                                                                                        { (yyval.expr) = 0;  }
#line 2002 "parser.c"
    break;

  case 113: /* array_end: "[" inside_arr "]" array_end  */
#line 299 "parser.bison"
                                                                                { (yyval.expr) = expr_create(EXPR_SUBSCRIPT_SUB, (yyvsp[-2].expr), (yyvsp[0].expr));	}
#line 2008 "parser.c"
    break;

  case 114: /* array_end: %empty  */
#line 300 "parser.bison"
                                                                                                                                        { (yyval.expr) = 0; 	}
#line 2014 "parser.c"
    break;

  case 115: /* inside_arr: expr  */
#line 303 "parser.bison"
                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2020 "parser.c"
    break;

  case 116: /* inside_arr: %empty  */
#line 304 "parser.bison"
                                                                                                        { (yyval.expr) = 0 ; }
#line 2026 "parser.c"
    break;


#line 2030 "parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 306 "parser.bison"


int yyerror( char *str )
{
	printf("parse error: %s\n",str);
	return 0;
}


