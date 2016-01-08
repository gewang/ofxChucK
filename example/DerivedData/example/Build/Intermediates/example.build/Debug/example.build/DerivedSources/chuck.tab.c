/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     STRING_LIT = 259,
     CHAR_LIT = 260,
     NUM = 261,
     FLOAT = 262,
     POUND = 263,
     COMMA = 264,
     COLON = 265,
     SEMICOLON = 266,
     LPAREN = 267,
     RPAREN = 268,
     LBRACK = 269,
     RBRACK = 270,
     LBRACE = 271,
     RBRACE = 272,
     DOT = 273,
     PLUS = 274,
     MINUS = 275,
     TIMES = 276,
     DIVIDE = 277,
     PERCENT = 278,
     EQ = 279,
     NEQ = 280,
     LT = 281,
     LE = 282,
     GT = 283,
     GE = 284,
     AND = 285,
     OR = 286,
     ASSIGN = 287,
     IF = 288,
     THEN = 289,
     ELSE = 290,
     WHILE = 291,
     FOR = 292,
     DO = 293,
     LOOP = 294,
     BREAK = 295,
     CONTINUE = 296,
     NULL_TOK = 297,
     FUNCTION = 298,
     RETURN = 299,
     QUESTION = 300,
     EXCLAMATION = 301,
     S_OR = 302,
     S_AND = 303,
     S_XOR = 304,
     PLUSPLUS = 305,
     MINUSMINUS = 306,
     DOLLAR = 307,
     POUNDPAREN = 308,
     PERCENTPAREN = 309,
     ATPAREN = 310,
     SIMULT = 311,
     PATTERN = 312,
     CODE = 313,
     TRANSPORT = 314,
     HOST = 315,
     TIME = 316,
     WHENEVER = 317,
     NEXT = 318,
     UNTIL = 319,
     EVERY = 320,
     BEFORE = 321,
     AFTER = 322,
     AT = 323,
     AT_SYM = 324,
     ATAT_SYM = 325,
     NEW = 326,
     SIZEOF = 327,
     TYPEOF = 328,
     SAME = 329,
     PLUS_CHUCK = 330,
     MINUS_CHUCK = 331,
     TIMES_CHUCK = 332,
     DIVIDE_CHUCK = 333,
     S_AND_CHUCK = 334,
     S_OR_CHUCK = 335,
     S_XOR_CHUCK = 336,
     SHIFT_RIGHT_CHUCK = 337,
     SHIFT_LEFT_CHUCK = 338,
     PERCENT_CHUCK = 339,
     SHIFT_RIGHT = 340,
     SHIFT_LEFT = 341,
     TILDA = 342,
     CHUCK = 343,
     COLONCOLON = 344,
     S_CHUCK = 345,
     AT_CHUCK = 346,
     LEFT_S_CHUCK = 347,
     UNCHUCK = 348,
     UPCHUCK = 349,
     CLASS = 350,
     INTERFACE = 351,
     EXTENDS = 352,
     IMPLEMENTS = 353,
     PUBLIC = 354,
     PROTECTED = 355,
     PRIVATE = 356,
     STATIC = 357,
     ABSTRACT = 358,
     CONST = 359,
     SPORK = 360,
     ARROW_RIGHT = 361,
     ARROW_LEFT = 362,
     L_HACK = 363,
     R_HACK = 364
   };
#endif
/* Tokens.  */
#define ID 258
#define STRING_LIT 259
#define CHAR_LIT 260
#define NUM 261
#define FLOAT 262
#define POUND 263
#define COMMA 264
#define COLON 265
#define SEMICOLON 266
#define LPAREN 267
#define RPAREN 268
#define LBRACK 269
#define RBRACK 270
#define LBRACE 271
#define RBRACE 272
#define DOT 273
#define PLUS 274
#define MINUS 275
#define TIMES 276
#define DIVIDE 277
#define PERCENT 278
#define EQ 279
#define NEQ 280
#define LT 281
#define LE 282
#define GT 283
#define GE 284
#define AND 285
#define OR 286
#define ASSIGN 287
#define IF 288
#define THEN 289
#define ELSE 290
#define WHILE 291
#define FOR 292
#define DO 293
#define LOOP 294
#define BREAK 295
#define CONTINUE 296
#define NULL_TOK 297
#define FUNCTION 298
#define RETURN 299
#define QUESTION 300
#define EXCLAMATION 301
#define S_OR 302
#define S_AND 303
#define S_XOR 304
#define PLUSPLUS 305
#define MINUSMINUS 306
#define DOLLAR 307
#define POUNDPAREN 308
#define PERCENTPAREN 309
#define ATPAREN 310
#define SIMULT 311
#define PATTERN 312
#define CODE 313
#define TRANSPORT 314
#define HOST 315
#define TIME 316
#define WHENEVER 317
#define NEXT 318
#define UNTIL 319
#define EVERY 320
#define BEFORE 321
#define AFTER 322
#define AT 323
#define AT_SYM 324
#define ATAT_SYM 325
#define NEW 326
#define SIZEOF 327
#define TYPEOF 328
#define SAME 329
#define PLUS_CHUCK 330
#define MINUS_CHUCK 331
#define TIMES_CHUCK 332
#define DIVIDE_CHUCK 333
#define S_AND_CHUCK 334
#define S_OR_CHUCK 335
#define S_XOR_CHUCK 336
#define SHIFT_RIGHT_CHUCK 337
#define SHIFT_LEFT_CHUCK 338
#define PERCENT_CHUCK 339
#define SHIFT_RIGHT 340
#define SHIFT_LEFT 341
#define TILDA 342
#define CHUCK 343
#define COLONCOLON 344
#define S_CHUCK 345
#define AT_CHUCK 346
#define LEFT_S_CHUCK 347
#define UNCHUCK 348
#define UPCHUCK 349
#define CLASS 350
#define INTERFACE 351
#define EXTENDS 352
#define IMPLEMENTS 353
#define PUBLIC 354
#define PROTECTED 355
#define PRIVATE 356
#define STATIC 357
#define ABSTRACT 358
#define CONST 359
#define SPORK 360
#define ARROW_RIGHT 361
#define ARROW_LEFT 362
#define L_HACK 363
#define R_HACK 364




/* Copy the first part of user declarations.  */
#line 1 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"


/*----------------------------------------------------------------------------
    ChucK Concurrent, On-the-fly Audio Programming Language
      Compiler and Virtual Machine

    Copyright (c) 2004 Ge Wang and Perry R. Cook.  All rights reserved.
      http://chuck.cs.princeton.edu/
      http://soundlab.cs.princeton.edu/

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
    U.S.A.
-----------------------------------------------------------------------------*/

//-----------------------------------------------------------------------------
// file: chuck.tab.c
// desc: chuck parser
//
// author: Ge Wang (gewang@cs.princeton.edu) - generated by yacc
//         Perry R. Cook (prc@cs.princeton.edu)
//
// based in part on the ansi C grammar by Jeff Lee, maintained by Jutta Degener
//
// date: Summer 2002
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "chuck_utils.h"
#include "chuck_errmsg.h"
#include "chuck_absyn.h"

// function
int yylex( void );

void yyerror( char *s )
{
    EM_error( EM_tokPos, "%s", s );
}

a_Program g_program = NULL;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 59 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
{
    int pos;
    int ival;
    double fval;
    c_str sval;
    
    a_Program program;
    a_Section program_section;
    a_Stmt_List stmt_list;
    a_Class_Def class_def;
    a_Class_Ext class_ext;
    a_Class_Body class_body;
    a_Stmt stmt;
    a_Exp exp;
    a_Func_Def func_def;
    a_Var_Decl_List var_decl_list;
    a_Var_Decl var_decl;
    a_Type_Decl type_decl;
    a_Arg_List arg_list;
    a_Id_List id_list;
    a_Array_Sub array_sub;
    a_Complex complex_exp;
    a_Polar polar_exp;
    a_Vec vec_exp; // ge: added 1.3.5.3
}
/* Line 193 of yacc.c.  */
#line 396 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/example/DerivedData/example/Build/Intermediates/example.build/Debug/example.build/DerivedSources/chuck.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 409 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/example/DerivedData/example/Build/Intermediates/example.build/Debug/example.build/DerivedSources/chuck.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  118
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  110
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNRULES -- Number of states.  */
#define YYNSTATES  313

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   364

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    21,    29,
      36,    44,    47,    52,    55,    60,    62,    63,    65,    68,
      70,    72,    74,    77,    79,    83,    85,    89,    98,   106,
     115,   123,   125,   127,   128,   130,   132,   134,   136,   138,
     140,   141,   143,   146,   150,   155,   157,   159,   161,   164,
     167,   172,   174,   177,   179,   181,   183,   185,   187,   190,
     194,   197,   200,   206,   214,   220,   228,   235,   243,   249,
     257,   263,   266,   270,   272,   275,   277,   281,   283,   287,
     289,   293,   297,   302,   305,   309,   311,   314,   318,   321,
     325,   327,   331,   333,   336,   339,   343,   347,   351,   353,
     355,   357,   359,   361,   363,   365,   367,   369,   371,   373,
     375,   377,   379,   381,   383,   385,   391,   393,   397,   399,
     403,   405,   409,   411,   415,   417,   421,   423,   427,   431,
     433,   437,   441,   445,   449,   451,   455,   459,   461,   465,
     469,   471,   475,   479,   483,   485,   489,   491,   495,   497,
     500,   503,   506,   509,   512,   515,   519,   521,   523,   525,
     527,   529,   532,   534,   538,   540,   543,   547,   552,   556,
     559,   562,   564,   566,   568,   570,   572,   574,   576,   578,
     580,   584,   588
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     111,     0,    -1,   112,    -1,   112,   111,    -1,   130,    -1,
     121,    -1,   113,    -1,   122,    95,   119,    16,   115,    17,
      -1,   122,    95,   119,   114,    16,   115,    17,    -1,   122,
      96,   119,    16,   115,    17,    -1,   122,    96,   119,   118,
      16,   115,    17,    -1,    98,   119,    -1,    98,   119,    97,
     120,    -1,    97,   120,    -1,    97,   120,    98,   119,    -1,
     116,    -1,    -1,   117,    -1,   117,   116,    -1,   130,    -1,
     121,    -1,   113,    -1,    97,   119,    -1,     3,    -1,     3,
       9,   119,    -1,     3,    -1,     3,    18,   120,    -1,   123,
     124,   128,     3,    12,   129,    13,   135,    -1,   123,   124,
     128,     3,    12,    13,   135,    -1,   123,   124,   128,     3,
      12,   129,    13,    11,    -1,   123,   124,   128,     3,    12,
      13,    11,    -1,    99,    -1,   101,    -1,    -1,    43,    -1,
      99,    -1,   100,    -1,   101,    -1,   102,    -1,   103,    -1,
      -1,     3,    -1,     3,    69,    -1,    26,   120,    28,    -1,
      26,   120,    28,    69,    -1,   125,    -1,   126,    -1,   127,
      -1,   127,   141,    -1,   127,   144,    -1,   127,   144,     9,
     129,    -1,   131,    -1,   131,   130,    -1,   136,    -1,   134,
      -1,   133,    -1,   132,    -1,   135,    -1,    44,    11,    -1,
      44,   137,    11,    -1,    40,    11,    -1,    41,    11,    -1,
      33,    12,   137,    13,   131,    -1,    33,    12,   137,    13,
     131,    35,   131,    -1,    36,    12,   137,    13,   131,    -1,
      38,   131,    36,    12,   137,    13,    11,    -1,    37,    12,
     136,   136,    13,   131,    -1,    37,    12,   136,   136,   137,
      13,   131,    -1,    64,    12,   137,    13,   131,    -1,    38,
     131,    64,    12,   137,    13,    11,    -1,    39,    12,   137,
      13,   131,    -1,    16,    17,    -1,    16,   130,    17,    -1,
      11,    -1,   137,    11,    -1,   138,    -1,   138,     9,   137,
      -1,   139,    -1,   138,   148,   139,    -1,   142,    -1,   139,
     149,   142,    -1,    14,   137,    15,    -1,    14,   137,    15,
     140,    -1,    14,    15,    -1,   141,    14,    15,    -1,   150,
      -1,   127,   143,    -1,   102,   127,   143,    -1,    74,   143,
      -1,   102,    74,   143,    -1,   144,    -1,   144,     9,   143,
      -1,     3,    -1,     3,   140,    -1,     3,   141,    -1,    53,
     137,    13,    -1,    54,   137,    13,    -1,    55,   137,    13,
      -1,    88,    -1,    91,    -1,    75,    -1,    76,    -1,    77,
      -1,    78,    -1,    82,    -1,    83,    -1,    84,    -1,    93,
      -1,    94,    -1,    79,    -1,    80,    -1,    81,    -1,   107,
      -1,   106,    -1,   151,    -1,   151,    45,   137,    10,   150,
      -1,   152,    -1,   151,    31,   152,    -1,   153,    -1,   152,
      30,   153,    -1,   154,    -1,   153,    47,   154,    -1,   155,
      -1,   154,    49,   155,    -1,   156,    -1,   155,    48,   156,
      -1,   157,    -1,   156,    24,   157,    -1,   156,    25,   157,
      -1,   158,    -1,   157,    26,   158,    -1,   157,    28,   158,
      -1,   157,    27,   158,    -1,   157,    29,   158,    -1,   159,
      -1,   158,    86,   159,    -1,   158,    85,   159,    -1,   160,
      -1,   159,    19,   160,    -1,   159,    20,   160,    -1,   161,
      -1,   160,    21,   161,    -1,   160,    22,   161,    -1,   160,
      23,   161,    -1,   162,    -1,   161,    87,   162,    -1,   163,
      -1,   162,    52,   127,    -1,   165,    -1,    50,   163,    -1,
      51,   163,    -1,   164,   163,    -1,    73,   163,    -1,    72,
     163,    -1,    71,   127,    -1,    71,   127,   140,    -1,    19,
      -1,    20,    -1,    87,    -1,    46,    -1,    21,    -1,   105,
      87,    -1,   166,    -1,   165,    89,   166,    -1,   167,    -1,
     166,   140,    -1,   166,    12,    13,    -1,   166,    12,   137,
      13,    -1,   166,    18,     3,    -1,   166,    50,    -1,   166,
      51,    -1,     3,    -1,     6,    -1,     7,    -1,     4,    -1,
       5,    -1,   140,    -1,   145,    -1,   146,    -1,   147,    -1,
     108,   137,   109,    -1,    12,   137,    13,    -1,    12,    13,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   181,   181,   182,   186,   187,   188,   192,   194,   196,
     198,   203,   204,   205,   206,   210,   211,   215,   216,   221,
     222,   223,   227,   231,   232,   236,   237,   241,   243,   245,
     247,   252,   253,   254,   258,   259,   260,   261,   265,   266,
     267,   271,   272,   276,   277,   286,   287,   292,   293,   297,
     298,   302,   303,   307,   308,   309,   310,   312,   316,   317,
     318,   319,   323,   325,   330,   332,   334,   336,   338,   340,
     342,   347,   348,   352,   353,   357,   358,   362,   363,   368,
     369,   374,   375,   380,   381,   385,   386,   387,   388,   389,
     393,   394,   398,   399,   400,   404,   409,   414,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   436,   437,   441,   442,   447,   448,   453,   454,
     459,   460,   465,   466,   471,   472,   477,   478,   480,   485,
     486,   488,   490,   492,   497,   498,   500,   505,   506,   508,
     513,   514,   516,   518,   523,   524,   529,   530,   535,   536,
     538,   540,   542,   544,   546,   548,   555,   556,   557,   558,
     559,   560,   565,   566,   571,   572,   574,   576,   578,   580,
     582,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING_LIT", "CHAR_LIT", "NUM",
  "FLOAT", "POUND", "COMMA", "COLON", "SEMICOLON", "LPAREN", "RPAREN",
  "LBRACK", "RBRACK", "LBRACE", "RBRACE", "DOT", "PLUS", "MINUS", "TIMES",
  "DIVIDE", "PERCENT", "EQ", "NEQ", "LT", "LE", "GT", "GE", "AND", "OR",
  "ASSIGN", "IF", "THEN", "ELSE", "WHILE", "FOR", "DO", "LOOP", "BREAK",
  "CONTINUE", "NULL_TOK", "FUNCTION", "RETURN", "QUESTION", "EXCLAMATION",
  "S_OR", "S_AND", "S_XOR", "PLUSPLUS", "MINUSMINUS", "DOLLAR",
  "POUNDPAREN", "PERCENTPAREN", "ATPAREN", "SIMULT", "PATTERN", "CODE",
  "TRANSPORT", "HOST", "TIME", "WHENEVER", "NEXT", "UNTIL", "EVERY",
  "BEFORE", "AFTER", "AT", "AT_SYM", "ATAT_SYM", "NEW", "SIZEOF", "TYPEOF",
  "SAME", "PLUS_CHUCK", "MINUS_CHUCK", "TIMES_CHUCK", "DIVIDE_CHUCK",
  "S_AND_CHUCK", "S_OR_CHUCK", "S_XOR_CHUCK", "SHIFT_RIGHT_CHUCK",
  "SHIFT_LEFT_CHUCK", "PERCENT_CHUCK", "SHIFT_RIGHT", "SHIFT_LEFT",
  "TILDA", "CHUCK", "COLONCOLON", "S_CHUCK", "AT_CHUCK", "LEFT_S_CHUCK",
  "UNCHUCK", "UPCHUCK", "CLASS", "INTERFACE", "EXTENDS", "IMPLEMENTS",
  "PUBLIC", "PROTECTED", "PRIVATE", "STATIC", "ABSTRACT", "CONST", "SPORK",
  "ARROW_RIGHT", "ARROW_LEFT", "L_HACK", "R_HACK", "$accept", "program",
  "program_section", "class_definition", "class_ext", "class_body",
  "class_body2", "class_section", "iface_ext", "id_list", "id_dot",
  "function_definition", "class_decl", "function_decl", "static_decl",
  "type_decl_a", "type_decl_b", "type_decl", "type_decl2", "arg_list",
  "statement_list", "statement", "jump_statement", "selection_statement",
  "loop_statement", "code_segment", "expression_statement", "expression",
  "chuck_expression", "arrow_expression", "array_exp", "array_empty",
  "decl_expression", "var_decl_list", "var_decl", "complex_exp",
  "polar_exp", "vec_exp", "chuck_operator", "arrow_operator",
  "conditional_expression", "logical_or_expression",
  "logical_and_expression", "inclusive_or_expression",
  "exclusive_or_expression", "and_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "tilda_expression", "cast_expression",
  "unary_expression", "unary_operator", "dur_expression",
  "postfix_expression", "primary_expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   110,   111,   111,   112,   112,   112,   113,   113,   113,
     113,   114,   114,   114,   114,   115,   115,   116,   116,   117,
     117,   117,   118,   119,   119,   120,   120,   121,   121,   121,
     121,   122,   122,   122,   123,   123,   123,   123,   124,   124,
     124,   125,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   130,   130,   131,   131,   131,   131,   131,   132,   132,
     132,   132,   133,   133,   134,   134,   134,   134,   134,   134,
     134,   135,   135,   136,   136,   137,   137,   138,   138,   139,
     139,   140,   140,   141,   141,   142,   142,   142,   142,   142,
     143,   143,   144,   144,   144,   145,   146,   147,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   149,   149,   150,   150,   151,   151,   152,   152,
     153,   153,   154,   154,   155,   155,   156,   156,   156,   157,
     157,   157,   157,   157,   158,   158,   158,   159,   159,   159,
     160,   160,   160,   160,   161,   161,   162,   162,   163,   163,
     163,   163,   163,   163,   163,   163,   164,   164,   164,   164,
     164,   164,   165,   165,   166,   166,   166,   166,   166,   166,
     166,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     6,     7,     6,
       7,     2,     4,     2,     4,     1,     0,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     3,     8,     7,     8,
       7,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       0,     1,     2,     3,     4,     1,     1,     1,     2,     2,
       4,     1,     2,     1,     1,     1,     1,     1,     2,     3,
       2,     2,     5,     7,     5,     7,     6,     7,     5,     7,
       5,     2,     3,     1,     2,     1,     3,     1,     3,     1,
       3,     3,     4,     2,     3,     1,     2,     3,     2,     3,
       1,     3,     1,     2,     2,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     1,     3,     1,     2,
       2,     2,     2,     2,     2,     3,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     2,     3,     4,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      33,   171,   174,   175,   172,   173,    73,     0,     0,     0,
     156,   157,   160,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   158,    35,    36,    37,     0,     0,
       0,     0,    33,     6,     5,     0,    40,    45,    46,     0,
       4,    51,    56,    55,    54,    57,    53,     0,    75,    77,
     176,    79,   177,   178,   179,    85,   114,   116,   118,   120,
     122,   124,   126,   129,   134,   137,   140,   144,   146,     0,
     148,   162,   164,    42,   182,     0,     0,    71,     0,    25,
       0,     0,     0,     0,     0,     0,    60,    61,    58,     0,
     171,   149,   150,     0,     0,     0,     0,    41,   154,   153,
     152,    92,    88,    90,     0,     0,   161,     0,     1,     3,
       0,     0,    38,    39,     0,    86,    52,    74,     0,   100,
     101,   102,   103,   109,   110,   111,   104,   105,   106,    98,
      99,   107,   108,     0,   113,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,     0,
       0,     0,   169,   170,   165,   181,    81,    72,     0,    43,
       0,     0,     0,     0,     0,     0,    59,    95,    96,    97,
       0,   155,     0,    93,    94,     0,    89,    87,   180,    23,
       0,     0,    47,     0,    76,    78,    80,   117,     0,   119,
     121,   123,   125,   127,   128,   130,   132,   131,   133,   136,
     135,   138,   139,   141,   142,   143,   145,   147,   163,   166,
       0,   168,    82,    26,    44,     0,     0,     0,     0,     0,
       0,     0,    83,     0,    91,     0,    33,     0,     0,     0,
      33,     0,     0,     0,    48,     0,     0,   167,    62,    64,
       0,     0,     0,     0,    70,    68,    84,    24,    21,     0,
      15,    33,    20,    19,    13,    11,    33,     0,    22,    33,
       0,   115,     0,    66,     0,     0,     0,     7,    18,     0,
       0,     0,     9,     0,     0,     0,     0,    63,    67,    65,
      69,    14,    12,     8,    10,    30,    28,    49,     0,     0,
      29,    27,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    41,    42,   268,   249,   269,   270,   271,   252,   200,
      90,   272,    45,    46,   124,    47,    48,    49,   203,   296,
     273,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,   194,    61,   112,   113,    62,    63,    64,   143,   146,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -259
static const yytype_int16 yypact[] =
{
     482,    13,  -259,  -259,  -259,  -259,  -259,     6,  1029,   559,
    -259,  -259,  -259,    26,    36,    43,    62,   633,    64,    52,
      77,  -259,   705,  -259,   156,   156,  1029,  1029,  1029,    80,
      28,   156,   156,   110,  -259,   -51,  -259,   -27,    38,   -49,
    1029,   119,   251,  -259,  -259,    34,    50,  -259,  -259,   110,
    -259,   633,  -259,  -259,  -259,  -259,  -259,   121,  1042,    60,
    -259,  -259,  -259,  -259,  -259,  -259,     2,   105,    95,   115,
      96,   131,    98,    72,   154,    94,    82,   130,  -259,   156,
      97,    71,  -259,  -259,  -259,   158,   170,  -259,   171,   172,
     161,  1029,  1029,   777,   -21,  1029,  -259,  -259,  -259,   180,
    -259,  -259,  -259,   179,   181,   182,  1029,   124,   183,  -259,
    -259,   184,  -259,   187,   110,   110,  -259,    90,  -259,  -259,
     198,   198,  -259,  -259,    28,  -259,  -259,  -259,  1029,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  1029,  -259,  -259,  1029,   156,  1029,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,    28,  -259,    92,
     840,   200,  -259,  -259,  -259,  -259,   183,  -259,    26,   135,
     192,   195,   777,   201,   202,   199,  -259,  -259,  -259,  -259,
     203,  -259,   903,  -259,   204,   110,  -259,  -259,  -259,   206,
      12,     8,   207,   214,  -259,    60,  -259,   105,   212,    95,
     115,    96,   131,    98,    98,    72,    72,    72,    72,   154,
     154,    94,    94,    82,    82,    82,   130,  -259,    71,  -259,
     210,  -259,  -259,  -259,  -259,   633,   633,   966,  1029,  1029,
     633,   633,  -259,   211,  -259,   198,   328,    26,   198,   215,
     328,   198,   219,   221,   204,   218,   156,  -259,   205,  -259,
     633,   224,   225,   226,  -259,  -259,  -259,  -259,  -259,   228,
    -259,   405,  -259,  -259,   143,   145,   328,   229,  -259,   328,
      27,  -259,   633,  -259,   633,   236,   237,  -259,  -259,   198,
      26,   232,  -259,   235,    35,   110,   240,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,   250,    51,    28,
    -259,  -259,  -259
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -259,   227,  -259,    39,  -259,  -143,   -11,  -259,  -259,  -117,
    -172,    42,  -259,  -259,  -259,  -259,  -259,   -30,  -259,   -36,
      49,   -16,  -259,  -259,  -259,  -258,   -79,    -5,  -259,   132,
     -74,    74,   128,   -44,   -14,  -259,  -259,  -259,  -259,  -259,
      24,  -259,   136,   129,   146,   134,   141,    25,   -17,    21,
      22,   -15,   116,    41,  -259,  -259,   117,  -259
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -42
static const yytype_int16 yytable[] =
{
     108,    94,    85,    86,   201,   125,   233,   174,   115,     1,
       2,     3,     4,     5,   182,   183,   -41,    99,     7,    84,
       8,   103,   104,   105,   250,    10,    11,    12,   246,    89,
     107,   107,    13,   147,   191,   117,   306,   193,   116,    43,
     294,   107,    44,   184,   -31,   -31,   305,   148,    91,    50,
     311,     9,    23,    13,    13,    92,    24,    25,    88,    26,
      27,    28,   310,    96,    13,   101,   102,     9,   -32,   -32,
     196,   197,   109,   110,    93,   274,    95,    30,    31,    32,
      33,    43,    83,   170,    44,     8,   180,   181,    97,   171,
     185,    50,   106,    34,   202,   100,     2,     3,     4,     5,
     126,   190,   232,   237,     7,   251,     8,   277,    38,   247,
     248,    39,   114,   111,    40,   163,   164,   165,   302,   118,
     168,   172,   173,   204,   155,   156,   157,   158,   267,   120,
     121,   275,   127,   291,   278,   149,   293,   227,   215,   216,
     217,   218,   150,   208,   152,    26,    27,    28,   223,   224,
     225,   244,   122,   123,   174,   153,   154,   159,   160,   100,
       2,     3,     4,     5,   151,   230,   144,   145,     7,   166,
       8,   175,   301,   161,   162,    10,    11,    12,   213,   214,
     219,   220,   167,   221,   222,   176,   169,    86,   177,   179,
     178,   186,   187,    83,   188,   189,   195,     8,   192,   198,
      40,   199,    23,   231,   234,   235,    24,    25,   236,    26,
      27,    28,   240,   238,   239,   245,   241,   255,   243,   258,
     259,   253,   256,   257,   264,   265,   266,    30,    31,    32,
     280,   276,   261,   262,   263,   279,   242,   284,   285,   286,
     282,   289,   290,    34,   283,   287,   292,   299,   300,   303,
     295,    -2,   304,   308,     1,     2,     3,     4,     5,   309,
     288,    39,     6,     7,    40,     8,   297,     9,   298,   119,
      10,    11,    12,   312,   206,   205,   254,    13,   209,   295,
     281,   307,   226,   207,    14,   211,   228,    15,    16,    17,
      18,    19,    20,   212,    21,    22,   210,    23,     0,     0,
       0,    24,    25,     0,    26,    27,    28,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,     0,     0,     0,
       0,     0,    30,    31,    32,    33,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     0,     0,    34,     6,
       7,     0,     8,     0,     9,   -16,     0,    10,    11,    12,
      35,    36,    37,    38,    13,     0,    39,     0,     0,    40,
       0,    14,     0,     0,    15,    16,    17,    18,    19,    20,
       0,    21,    22,     0,    23,     0,     0,     0,    24,    25,
       0,    26,    27,    28,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,    30,
      31,    32,    33,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     0,     0,    34,     6,     7,     0,     8,
       0,     9,   -17,     0,    10,    11,    12,    35,    36,    37,
      38,    13,     0,    39,     0,     0,    40,     0,    14,     0,
       0,    15,    16,    17,    18,    19,    20,     0,    21,    22,
       0,    23,     0,     0,     0,    24,    25,     0,    26,    27,
      28,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,     0,     0,     0,    30,    31,    32,    33,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       0,     0,    34,     6,     7,     0,     8,     0,     9,     0,
       0,    10,    11,    12,    35,    36,    37,    38,    13,     0,
      39,     0,     0,    40,     0,    14,     0,     0,    15,    16,
      17,    18,    19,    20,     0,    21,    22,     0,    23,     0,
       0,     0,    24,    25,     0,    26,    27,    28,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,    30,    31,    32,    33,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     0,     0,    34,
       6,     7,     0,     8,     0,     9,    87,     0,    10,    11,
      12,    35,    36,    37,    38,    13,     0,    39,     0,     0,
      40,     0,    14,     0,     0,    15,    16,    17,    18,    19,
      20,     0,     0,    22,     0,    23,     0,     0,     0,    24,
      25,     0,    26,    27,    28,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
      30,    31,    32,    33,     0,     0,     1,     2,     3,     4,
       5,     0,     0,     0,     6,     7,    34,     8,     0,     9,
       0,     0,    10,    11,    12,     0,     0,     0,     0,    13,
       0,    38,     0,     0,    39,     0,    14,    40,     0,    15,
      16,    17,    18,    19,    20,     0,     0,    22,     0,    23,
       0,     0,     0,    24,    25,     0,    26,    27,    28,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,    30,    31,    32,    33,     1,     2,
       3,     4,     5,     0,     0,     0,    98,     7,     0,     8,
      34,     0,     0,     0,    10,    11,    12,     0,     0,     0,
       0,    13,     0,     0,     0,    38,     0,     0,    39,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,     0,     0,     0,    24,    25,     0,    26,    27,
      28,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    31,    32,    33,
       1,     2,     3,     4,     5,     0,     0,     0,     6,     7,
       0,     8,    34,     0,     0,     0,    10,    11,    12,     0,
       0,     0,     0,    13,     0,     0,     0,    38,     0,     0,
      39,     0,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     0,    24,    25,     0,
      26,    27,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,    30,    31,
      32,    33,     7,   229,     8,     0,     0,     0,     0,    10,
      11,    12,     0,     0,    34,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,    39,     0,     0,    40,    23,     0,     0,     0,
      24,    25,     0,    26,    27,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     3,     4,
       5,    30,    31,    32,    33,     7,     0,     8,   242,     0,
       0,     0,    10,    11,    12,     0,     0,    34,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,    39,     0,     0,    40,    23,
       0,     0,     0,    24,    25,     0,    26,    27,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,    30,    31,    32,    33,     7,   260,
       8,     0,     0,     0,     0,    10,    11,    12,     0,     0,
      34,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,    39,     0,
       0,    40,    23,     0,     0,     0,    24,    25,     0,    26,
      27,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,    30,    31,    32,
      33,     7,     0,     8,     0,     0,     0,     0,    10,    11,
      12,   128,     0,    34,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,    39,     0,     0,    40,    23,     0,     0,     0,    24,
      25,     0,    26,    27,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      30,    31,    32,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
     139,    38,     0,   140,    39,   141,   142,    40
};

static const yytype_int16 yycheck[] =
{
      30,    17,     7,     8,   121,    49,   178,    81,    38,     3,
       4,     5,     6,     7,    93,    36,     3,    22,    12,    13,
      14,    26,    27,    28,    16,    19,    20,    21,    16,     3,
       3,     3,    26,    31,   108,    40,   294,   111,    87,     0,
      13,     3,     0,    64,    95,    96,    11,    45,    12,     0,
     308,    16,    46,    26,    26,    12,    50,    51,     9,    53,
      54,    55,    11,    11,    26,    24,    25,    16,    95,    96,
     114,   115,    31,    32,    12,   247,    12,    71,    72,    73,
      74,    42,    69,    12,    42,    14,    91,    92,    11,    18,
      95,    42,    12,    87,   124,     3,     4,     5,     6,     7,
      51,   106,   176,   182,    12,    97,    14,   250,   102,    97,
      98,   105,    74,     3,   108,    21,    22,    23,   290,     0,
      79,    50,    51,   128,    26,    27,    28,    29,   245,    95,
      96,   248,    11,   276,   251,    30,   279,   167,   155,   156,
     157,   158,    47,   148,    48,    53,    54,    55,   163,   164,
     165,   195,   102,   103,   228,    24,    25,    85,    86,     3,
       4,     5,     6,     7,    49,   170,   106,   107,    12,    87,
      14,    13,   289,    19,    20,    19,    20,    21,   153,   154,
     159,   160,    52,   161,   162,    15,    89,   192,    17,    28,
      18,    11,    13,    69,    13,    13,     9,    14,    14,   109,
     108,     3,    46,     3,    69,    13,    50,    51,    13,    53,
      54,    55,    13,    12,    12,     9,    13,     3,    14,   235,
     236,    14,    10,    13,   240,   241,    15,    71,    72,    73,
      12,    16,   237,   238,   239,    16,    15,    13,    13,    13,
      35,    98,    97,    87,   260,    17,    17,    11,    11,    17,
     280,     0,    17,    13,     3,     4,     5,     6,     7,     9,
     271,   105,    11,    12,   108,    14,   282,    16,   284,    42,
      19,    20,    21,   309,   146,   143,   202,    26,   149,   309,
     256,   295,   166,   147,    33,   151,   169,    36,    37,    38,
      39,    40,    41,   152,    43,    44,   150,    46,    -1,    -1,
      -1,    50,    51,    -1,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    87,    11,
      12,    -1,    14,    -1,    16,    17,    -1,    19,    20,    21,
      99,   100,   101,   102,    26,    -1,   105,    -1,    -1,   108,
      -1,    33,    -1,    -1,    36,    37,    38,    39,    40,    41,
      -1,    43,    44,    -1,    46,    -1,    -1,    -1,    50,    51,
      -1,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    87,    11,    12,    -1,    14,
      -1,    16,    17,    -1,    19,    20,    21,    99,   100,   101,
     102,    26,    -1,   105,    -1,    -1,   108,    -1,    33,    -1,
      -1,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      -1,    46,    -1,    -1,    -1,    50,    51,    -1,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    87,    11,    12,    -1,    14,    -1,    16,    -1,
      -1,    19,    20,    21,    99,   100,   101,   102,    26,    -1,
     105,    -1,    -1,   108,    -1,    33,    -1,    -1,    36,    37,
      38,    39,    40,    41,    -1,    43,    44,    -1,    46,    -1,
      -1,    -1,    50,    51,    -1,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    87,
      11,    12,    -1,    14,    -1,    16,    17,    -1,    19,    20,
      21,    99,   100,   101,   102,    26,    -1,   105,    -1,    -1,
     108,    -1,    33,    -1,    -1,    36,    37,    38,    39,    40,
      41,    -1,    -1,    44,    -1,    46,    -1,    -1,    -1,    50,
      51,    -1,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    12,    87,    14,    -1,    16,
      -1,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      -1,   102,    -1,    -1,   105,    -1,    33,   108,    -1,    36,
      37,    38,    39,    40,    41,    -1,    -1,    44,    -1,    46,
      -1,    -1,    -1,    50,    51,    -1,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    12,    -1,    14,
      87,    -1,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    50,    51,    -1,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    12,
      -1,    14,    87,    -1,    -1,    -1,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    71,    72,
      73,    74,    12,    13,    14,    -1,    -1,    -1,    -1,    19,
      20,    21,    -1,    -1,    87,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,   108,    46,    -1,    -1,    -1,
      50,    51,    -1,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    71,    72,    73,    74,    12,    -1,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    -1,    -1,    87,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,   105,    -1,    -1,   108,    46,
      -1,    -1,    -1,    50,    51,    -1,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    71,    72,    73,    74,    12,    13,
      14,    -1,    -1,    -1,    -1,    19,    20,    21,    -1,    -1,
      87,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,   108,    46,    -1,    -1,    -1,    50,    51,    -1,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    71,    72,    73,
      74,    12,    -1,    14,    -1,    -1,    -1,    -1,    19,    20,
      21,     9,    -1,    87,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,   105,    -1,    -1,   108,    46,    -1,    -1,    -1,    50,
      51,    -1,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      88,   102,    -1,    91,   105,    93,    94,   108
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    11,    12,    14,    16,
      19,    20,    21,    26,    33,    36,    37,    38,    39,    40,
      41,    43,    44,    46,    50,    51,    53,    54,    55,    64,
      71,    72,    73,    74,    87,    99,   100,   101,   102,   105,
     108,   111,   112,   113,   121,   122,   123,   125,   126,   127,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   142,   145,   146,   147,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    69,    13,   137,   137,    17,   130,     3,
     120,    12,    12,    12,   131,    12,    11,    11,    11,   137,
       3,   163,   163,   137,   137,   137,    12,     3,   127,   163,
     163,     3,   143,   144,    74,   127,    87,   137,     0,   111,
      95,    96,   102,   103,   124,   143,   130,    11,     9,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    88,
      91,    93,    94,   148,   106,   107,   149,    31,    45,    30,
      47,    49,    48,    24,    25,    26,    27,    28,    29,    85,
      86,    19,    20,    21,    22,    23,    87,    52,   163,    89,
      12,    18,    50,    51,   140,    13,    15,    17,    18,    28,
     137,   137,   136,    36,    64,   137,    11,    13,    13,    13,
     137,   140,    14,   140,   141,     9,   143,   143,   109,     3,
     119,   119,   127,   128,   137,   139,   142,   152,   137,   153,
     154,   155,   156,   157,   157,   158,   158,   158,   158,   159,
     159,   160,   160,   161,   161,   161,   162,   127,   166,    13,
     137,     3,   140,   120,    69,    13,    13,   136,    12,    12,
      13,    13,    15,    14,   143,     9,    16,    97,    98,   114,
      16,    97,   118,    14,   141,     3,    10,    13,   131,   131,
      13,   137,   137,   137,   131,   131,    15,   119,   113,   115,
     116,   117,   121,   130,   120,   119,    16,   115,   119,    16,
      12,   150,    35,   131,    13,    13,    13,    17,   116,    98,
      97,   115,    17,   115,    13,   127,   129,   131,   131,    11,
      11,   119,   120,    17,    17,    11,   135,   144,    13,     9,
      11,   135,   129
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 181 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.program) = g_program = new_program( (yyvsp[(1) - (1)].program_section), EM_lineNum ); }
    break;

  case 3:
#line 182 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.program) = g_program = prepend_program( (yyvsp[(1) - (2)].program_section), (yyvsp[(2) - (2)].program), EM_lineNum ); }
    break;

  case 4:
#line 186 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.program_section) = new_section_stmt( (yyvsp[(1) - (1)].stmt_list), EM_lineNum ); }
    break;

  case 5:
#line 187 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.program_section) = new_section_func_def( (yyvsp[(1) - (1)].func_def), EM_lineNum ); }
    break;

  case 6:
#line 188 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.program_section) = new_section_class_def( (yyvsp[(1) - (1)].class_def), EM_lineNum ); }
    break;

  case 7:
#line 193 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.class_def) = new_class_def( (yyvsp[(1) - (6)].ival), (yyvsp[(3) - (6)].id_list), NULL, (yyvsp[(5) - (6)].class_body), EM_lineNum ); }
    break;

  case 8:
#line 195 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.class_def) = new_class_def( (yyvsp[(1) - (7)].ival), (yyvsp[(3) - (7)].id_list), (yyvsp[(4) - (7)].class_ext), (yyvsp[(6) - (7)].class_body), EM_lineNum ); }
    break;

  case 9:
#line 197 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.class_def) = new_iface_def( (yyvsp[(1) - (6)].ival), (yyvsp[(3) - (6)].id_list), NULL, (yyvsp[(5) - (6)].class_body), EM_lineNum ); }
    break;

  case 10:
#line 199 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.class_def) = new_iface_def( (yyvsp[(1) - (7)].ival), (yyvsp[(3) - (7)].id_list), (yyvsp[(4) - (7)].class_ext), (yyvsp[(6) - (7)].class_body), EM_lineNum ); }
    break;

  case 11:
#line 203 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.class_ext) = new_class_ext( NULL, (yyvsp[(2) - (2)].id_list), EM_lineNum ); }
    break;

  case 12:
#line 204 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.class_ext) = new_class_ext( (yyvsp[(4) - (4)].id_list), (yyvsp[(2) - (4)].id_list), EM_lineNum ); }
    break;

  case 13:
#line 205 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.class_ext) = new_class_ext( (yyvsp[(2) - (2)].id_list), NULL, EM_lineNum ); }
    break;

  case 14:
#line 206 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.class_ext) = new_class_ext( (yyvsp[(2) - (4)].id_list), (yyvsp[(4) - (4)].id_list), EM_lineNum ); }
    break;

  case 15:
#line 210 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.class_body) = (yyvsp[(1) - (1)].class_body); }
    break;

  case 16:
#line 211 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.class_body) = NULL; }
    break;

  case 17:
#line 215 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.class_body) = new_class_body( (yyvsp[(1) - (1)].program_section), EM_lineNum ); }
    break;

  case 18:
#line 216 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.class_body) = prepend_class_body( (yyvsp[(1) - (2)].program_section), (yyvsp[(2) - (2)].class_body), EM_lineNum ); }
    break;

  case 19:
#line 221 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.program_section) = new_section_stmt( (yyvsp[(1) - (1)].stmt_list), EM_lineNum ); }
    break;

  case 20:
#line 222 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.program_section) = new_section_func_def( (yyvsp[(1) - (1)].func_def), EM_lineNum ); }
    break;

  case 21:
#line 223 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.program_section) = new_section_class_def( (yyvsp[(1) - (1)].class_def), EM_lineNum ); }
    break;

  case 22:
#line 227 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.class_ext) = new_class_ext( NULL, (yyvsp[(2) - (2)].id_list), EM_lineNum ); }
    break;

  case 23:
#line 231 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.id_list) = new_id_list( (yyvsp[(1) - (1)].sval), EM_lineNum ); }
    break;

  case 24:
#line 232 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.id_list) = prepend_id_list( (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].id_list), EM_lineNum ); }
    break;

  case 25:
#line 236 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.id_list) = new_id_list( (yyvsp[(1) - (1)].sval), EM_lineNum ); }
    break;

  case 26:
#line 237 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.id_list) = prepend_id_list( (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].id_list), EM_lineNum ); }
    break;

  case 27:
#line 242 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.func_def) = new_func_def( (yyvsp[(1) - (8)].ival), (yyvsp[(2) - (8)].ival), (yyvsp[(3) - (8)].type_decl), (yyvsp[(4) - (8)].sval), (yyvsp[(6) - (8)].arg_list), (yyvsp[(8) - (8)].stmt), EM_lineNum ); }
    break;

  case 28:
#line 244 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.func_def) = new_func_def( (yyvsp[(1) - (7)].ival), (yyvsp[(2) - (7)].ival), (yyvsp[(3) - (7)].type_decl), (yyvsp[(4) - (7)].sval), NULL, (yyvsp[(7) - (7)].stmt), EM_lineNum ); }
    break;

  case 29:
#line 246 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.func_def) = new_func_def( (yyvsp[(1) - (8)].ival), (yyvsp[(2) - (8)].ival), (yyvsp[(3) - (8)].type_decl), (yyvsp[(4) - (8)].sval), (yyvsp[(6) - (8)].arg_list), NULL, EM_lineNum ); }
    break;

  case 30:
#line 248 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.func_def) = new_func_def( (yyvsp[(1) - (7)].ival), (yyvsp[(2) - (7)].ival), (yyvsp[(3) - (7)].type_decl), (yyvsp[(4) - (7)].sval), NULL, NULL, EM_lineNum ); }
    break;

  case 31:
#line 252 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_key_public; }
    break;

  case 32:
#line 253 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_key_private; }
    break;

  case 33:
#line 254 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_key_private; }
    break;

  case 34:
#line 258 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_key_func; }
    break;

  case 35:
#line 259 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_key_public; }
    break;

  case 36:
#line 260 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_key_protected; }
    break;

  case 37:
#line 261 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_key_private; }
    break;

  case 38:
#line 265 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_key_static; }
    break;

  case 39:
#line 266 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_key_abstract; }
    break;

  case 40:
#line 267 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_key_instance; }
    break;

  case 41:
#line 271 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.type_decl) = new_type_decl( new_id_list( (yyvsp[(1) - (1)].sval), EM_lineNum ), 0, EM_lineNum ); }
    break;

  case 42:
#line 272 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.type_decl) = new_type_decl( new_id_list( (yyvsp[(1) - (2)].sval), EM_lineNum ), 1, EM_lineNum ); }
    break;

  case 43:
#line 276 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.type_decl) = new_type_decl( (yyvsp[(2) - (3)].id_list), 0, EM_lineNum ); }
    break;

  case 44:
#line 277 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.type_decl) = new_type_decl( (yyvsp[(2) - (4)].id_list), 1, EM_lineNum ); }
    break;

  case 45:
#line 286 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.type_decl) = (yyvsp[(1) - (1)].type_decl); }
    break;

  case 46:
#line 287 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.type_decl) = (yyvsp[(1) - (1)].type_decl); }
    break;

  case 47:
#line 292 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.type_decl) = (yyvsp[(1) - (1)].type_decl); }
    break;

  case 48:
#line 293 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.type_decl) = add_type_decl_array( (yyvsp[(1) - (2)].type_decl), (yyvsp[(2) - (2)].array_sub), EM_lineNum ); }
    break;

  case 49:
#line 297 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.arg_list) = new_arg_list( (yyvsp[(1) - (2)].type_decl), (yyvsp[(2) - (2)].var_decl), EM_lineNum ); }
    break;

  case 50:
#line 298 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.arg_list) = prepend_arg_list( (yyvsp[(1) - (4)].type_decl), (yyvsp[(2) - (4)].var_decl), (yyvsp[(4) - (4)].arg_list), EM_lineNum ); }
    break;

  case 51:
#line 302 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt_list) = new_stmt_list( (yyvsp[(1) - (1)].stmt), EM_lineNum ); }
    break;

  case 52:
#line 303 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt_list) = prepend_stmt_list( (yyvsp[(1) - (2)].stmt), (yyvsp[(2) - (2)].stmt_list), EM_lineNum ); }
    break;

  case 53:
#line 307 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 54:
#line 308 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 55:
#line 309 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 56:
#line 310 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 57:
#line 312 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 58:
#line 316 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_return( NULL, EM_lineNum ); }
    break;

  case 59:
#line 317 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_return( (yyvsp[(2) - (3)].exp), EM_lineNum ); }
    break;

  case 60:
#line 318 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_break( EM_lineNum ); }
    break;

  case 61:
#line 319 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_continue( EM_lineNum ); }
    break;

  case 62:
#line 324 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_if( (yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].stmt), NULL, EM_lineNum ); }
    break;

  case 63:
#line 326 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_if( (yyvsp[(3) - (7)].exp), (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt), EM_lineNum ); }
    break;

  case 64:
#line 331 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_while( (yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].stmt), EM_lineNum ); }
    break;

  case 65:
#line 333 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_do_while( (yyvsp[(5) - (7)].exp), (yyvsp[(2) - (7)].stmt), EM_lineNum ); }
    break;

  case 66:
#line 335 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_for( (yyvsp[(3) - (6)].stmt), (yyvsp[(4) - (6)].stmt), NULL, (yyvsp[(6) - (6)].stmt), EM_lineNum ); }
    break;

  case 67:
#line 337 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_for( (yyvsp[(3) - (7)].stmt), (yyvsp[(4) - (7)].stmt), (yyvsp[(5) - (7)].exp), (yyvsp[(7) - (7)].stmt), EM_lineNum ); }
    break;

  case 68:
#line 339 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_until( (yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].stmt), EM_lineNum ); }
    break;

  case 69:
#line 341 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_do_until( (yyvsp[(5) - (7)].exp), (yyvsp[(2) - (7)].stmt), EM_lineNum ); }
    break;

  case 70:
#line 343 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_loop( (yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].stmt), EM_lineNum ); }
    break;

  case 71:
#line 347 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_code( NULL, EM_lineNum ); }
    break;

  case 72:
#line 348 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_code( (yyvsp[(2) - (3)].stmt_list), EM_lineNum ); }
    break;

  case 73:
#line 352 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = NULL; }
    break;

  case 74:
#line 353 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.stmt) = new_stmt_from_expression( (yyvsp[(1) - (2)].exp), EM_lineNum ); }
    break;

  case 75:
#line 357 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 76:
#line 358 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = prepend_expression( (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 77:
#line 362 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 78:
#line 364 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), (yyvsp[(2) - (3)].ival), (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 79:
#line 368 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 80:
#line 370 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), (yyvsp[(2) - (3)].ival), (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 81:
#line 374 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.array_sub) = new_array_sub( (yyvsp[(2) - (3)].exp), EM_lineNum ); }
    break;

  case 82:
#line 376 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.array_sub) = prepend_array_sub( (yyvsp[(4) - (4)].array_sub), (yyvsp[(2) - (4)].exp), EM_lineNum ); }
    break;

  case 83:
#line 380 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.array_sub) = new_array_sub( NULL, EM_lineNum ); }
    break;

  case 84:
#line 381 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.array_sub) = prepend_array_sub( (yyvsp[(1) - (3)].array_sub), NULL, EM_lineNum ); }
    break;

  case 85:
#line 385 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 86:
#line 386 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_decl( (yyvsp[(1) - (2)].type_decl), (yyvsp[(2) - (2)].var_decl_list), 0, EM_lineNum ); }
    break;

  case 87:
#line 387 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_decl( (yyvsp[(2) - (3)].type_decl), (yyvsp[(3) - (3)].var_decl_list), 1, EM_lineNum ); }
    break;

  case 88:
#line 388 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_decl( NULL, (yyvsp[(2) - (2)].var_decl_list), 0, EM_lineNum ); }
    break;

  case 89:
#line 389 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_decl( NULL, (yyvsp[(3) - (3)].var_decl_list), 1, EM_lineNum ); }
    break;

  case 90:
#line 393 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.var_decl_list) = new_var_decl_list( (yyvsp[(1) - (1)].var_decl), EM_lineNum ); }
    break;

  case 91:
#line 394 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.var_decl_list) = prepend_var_decl_list( (yyvsp[(1) - (3)].var_decl), (yyvsp[(3) - (3)].var_decl_list), EM_lineNum ); }
    break;

  case 92:
#line 398 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.var_decl) = new_var_decl( (yyvsp[(1) - (1)].sval), NULL, EM_lineNum ); }
    break;

  case 93:
#line 399 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.var_decl) = new_var_decl( (yyvsp[(1) - (2)].sval), (yyvsp[(2) - (2)].array_sub), EM_lineNum ); }
    break;

  case 94:
#line 400 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.var_decl) = new_var_decl( (yyvsp[(1) - (2)].sval), (yyvsp[(2) - (2)].array_sub), EM_lineNum ); }
    break;

  case 95:
#line 405 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.complex_exp) = new_complex( (yyvsp[(2) - (3)].exp), EM_lineNum ); }
    break;

  case 96:
#line 410 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.polar_exp) = new_polar( (yyvsp[(2) - (3)].exp), EM_lineNum ); }
    break;

  case 97:
#line 415 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.vec_exp) = new_vec( (yyvsp[(2) - (3)].exp), EM_lineNum ); }
    break;

  case 98:
#line 419 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_chuck; }
    break;

  case 99:
#line 420 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_at_chuck; }
    break;

  case 100:
#line 421 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_plus_chuck; }
    break;

  case 101:
#line 422 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_minus_chuck; }
    break;

  case 102:
#line 423 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_times_chuck; }
    break;

  case 103:
#line 424 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_divide_chuck; }
    break;

  case 104:
#line 425 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_shift_right_chuck; }
    break;

  case 105:
#line 426 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_shift_left_chuck; }
    break;

  case 106:
#line 427 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_percent_chuck; }
    break;

  case 107:
#line 428 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_unchuck; }
    break;

  case 108:
#line 429 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_upchuck; }
    break;

  case 109:
#line 430 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_s_and_chuck; }
    break;

  case 110:
#line 431 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_s_or_chuck; }
    break;

  case 111:
#line 432 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_s_xor_chuck; }
    break;

  case 112:
#line 436 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_arrow_left; }
    break;

  case 113:
#line 437 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_arrow_right; }
    break;

  case 114:
#line 441 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 115:
#line 443 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_if( (yyvsp[(1) - (5)].exp), (yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].exp), EM_lineNum ); }
    break;

  case 116:
#line 447 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 117:
#line 449 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_or, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 118:
#line 453 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 119:
#line 455 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_and, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 120:
#line 459 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 121:
#line 461 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_s_or, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 122:
#line 465 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 123:
#line 467 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_s_xor, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 124:
#line 471 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 125:
#line 473 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_s_and, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 126:
#line 477 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 127:
#line 479 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_eq, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 128:
#line 481 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_neq, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 129:
#line 485 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 130:
#line 487 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_lt, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 131:
#line 489 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_gt, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 132:
#line 491 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_le, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 133:
#line 493 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_ge, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 134:
#line 497 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 135:
#line 499 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_shift_left, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 136:
#line 501 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_shift_right, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 137:
#line 505 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 138:
#line 507 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_plus, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 139:
#line 509 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_minus, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 140:
#line 513 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 141:
#line 515 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_times, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 142:
#line 517 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_divide, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 143:
#line 519 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_percent, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 144:
#line 523 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 145:
#line 525 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_binary( (yyvsp[(1) - (3)].exp), ae_op_tilda, (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 146:
#line 529 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 147:
#line 531 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_cast( (yyvsp[(3) - (3)].type_decl), (yyvsp[(1) - (3)].exp), EM_lineNum ); }
    break;

  case 148:
#line 535 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 149:
#line 537 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_unary( ae_op_plusplus, (yyvsp[(2) - (2)].exp), EM_lineNum ); }
    break;

  case 150:
#line 539 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_unary( ae_op_minusminus, (yyvsp[(2) - (2)].exp), EM_lineNum ); }
    break;

  case 151:
#line 541 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_unary( (yyvsp[(1) - (2)].ival), (yyvsp[(2) - (2)].exp), EM_lineNum ); }
    break;

  case 152:
#line 543 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_unary( ae_op_typeof, (yyvsp[(2) - (2)].exp), EM_lineNum ); }
    break;

  case 153:
#line 545 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_unary( ae_op_sizeof, (yyvsp[(2) - (2)].exp), EM_lineNum ); }
    break;

  case 154:
#line 547 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_unary2( ae_op_new, (yyvsp[(2) - (2)].type_decl), NULL, EM_lineNum ); }
    break;

  case 155:
#line 549 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_unary2( ae_op_new, (yyvsp[(2) - (3)].type_decl), (yyvsp[(3) - (3)].array_sub), EM_lineNum ); }
    break;

  case 156:
#line 555 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_plus; }
    break;

  case 157:
#line 556 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_minus; }
    break;

  case 158:
#line 557 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_tilda; }
    break;

  case 159:
#line 558 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_exclamation; }
    break;

  case 160:
#line 559 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_times; }
    break;

  case 161:
#line 560 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.ival) = ae_op_spork; }
    break;

  case 163:
#line 567 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_dur( (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), EM_lineNum ); }
    break;

  case 164:
#line 571 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 165:
#line 573 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_array( (yyvsp[(1) - (2)].exp), (yyvsp[(2) - (2)].array_sub), EM_lineNum ); }
    break;

  case 166:
#line 575 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_func_call( (yyvsp[(1) - (3)].exp), NULL, EM_lineNum ); }
    break;

  case 167:
#line 577 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_func_call( (yyvsp[(1) - (4)].exp), (yyvsp[(3) - (4)].exp), EM_lineNum ); }
    break;

  case 168:
#line 579 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_member_dot( (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].sval), EM_lineNum ); }
    break;

  case 169:
#line 581 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_postfix( (yyvsp[(1) - (2)].exp), ae_op_plusplus, EM_lineNum ); }
    break;

  case 170:
#line 583 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_postfix( (yyvsp[(1) - (2)].exp), ae_op_minusminus, EM_lineNum ); }
    break;

  case 171:
#line 588 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_id( (yyvsp[(1) - (1)].sval), EM_lineNum ); }
    break;

  case 172:
#line 589 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_int( (yyvsp[(1) - (1)].ival), EM_lineNum ); }
    break;

  case 173:
#line 590 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_float( (yyvsp[(1) - (1)].fval), EM_lineNum ); }
    break;

  case 174:
#line 591 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_str( (yyvsp[(1) - (1)].sval), EM_lineNum ); }
    break;

  case 175:
#line 592 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_char( (yyvsp[(1) - (1)].sval), EM_lineNum ); }
    break;

  case 176:
#line 593 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_array_lit( (yyvsp[(1) - (1)].array_sub), EM_lineNum ); }
    break;

  case 177:
#line 594 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_complex( (yyvsp[(1) - (1)].complex_exp), EM_lineNum ); }
    break;

  case 178:
#line 595 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_polar( (yyvsp[(1) - (1)].polar_exp), EM_lineNum ); }
    break;

  case 179:
#line 596 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_vec( (yyvsp[(1) - (1)].vec_exp), EM_lineNum ); }
    break;

  case 180:
#line 597 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_hack( (yyvsp[(2) - (3)].exp), EM_lineNum ); }
    break;

  case 181:
#line 598 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = (yyvsp[(2) - (3)].exp); }
    break;

  case 182:
#line 599 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
    { (yyval.exp) = new_exp_from_nil( EM_lineNum ); }
    break;


/* Line 1267 of yacc.c.  */
#line 3000 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/example/DerivedData/example/Build/Intermediates/example.build/Debug/example.build/DerivedSources/chuck.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



