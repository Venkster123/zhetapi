/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "fparser.y" /* yacc.c:339  */

	#include <iostream>
	#include <cctype>
	#include <cstring>
	#include <vector>
	#include <stack>
	#include <string>

	#include "operation.h"
	#include "defaults.h"
  	#include "operand.h"

	#include "functor.h"
	// #include "func_stack.h"

	#include "var_stack.h"
	#include "variable.h"

	extern "C" int yylex();
  	
	using namespace std;

	void yyerror(functor <double> ::node *(&), functor <double> ::param_list, functor <double> ::map, const char *);

#line 91 "fparser.h" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENT = 258,
    NUMBER = 259,
    PLUS = 260,
    MINUS = 261,
    MULT = 262,
    DIV = 263,
    SIN = 264,
    COS = 265,
    TAN = 266,
    CSC = 267,
    SEC = 268,
    COT = 269,
    LOG = 270,
    LN = 271,
    LG = 272,
    SUPERSCRIPT = 273,
    SUBSCRIPT = 274,
    LPAREN = 275,
    RPAREN = 276,
    LBRACE = 277,
    RBRACE = 278,
    LBRACKET = 279,
    RBRACKET = 280,
    END = 281
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 54 "fparser.y" /* yacc.c:355  */

	functor <double> ::node		*expr;
	functor <double> ::node		*coll;
	functor <double> ::node		*term;
	functor <double> ::node		*felm;
	functor <double> ::node		*dopn;
	functor <double> ::node		*dpnt;
	functor <double> ::node		*prth;
	functor <double> ::node		*sclr;

	const char			*ident;
	double       			value;

#line 169 "fparser.h" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (functor <double> ::node *(&root), functor <double> ::param_list list, functor <double> ::map &vmap);



/* Copy the second part of user declarations.  */

#line 186 "fparser.h" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  27
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  31
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  56

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   111,   125,   139,   153,   167,   181,   196,
     202,   216,   220,   227,   236,   242,   258,   275,   297,   318,
     330,   342,   354,   366,   378,   391,   406,   410,   414,   419,
     490,   498
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "NUMBER", "PLUS", "MINUS",
  "MULT", "DIV", "SIN", "COS", "TAN", "CSC", "SEC", "COT", "LOG", "LN",
  "LG", "SUPERSCRIPT", "SUBSCRIPT", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "LBRACKET", "RBRACKET", "END", "$accept", "input", "expr", "coll",
  "term", "felm", "dopn", "dpnt", "sclr", "prth", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281
};
# endif

#define YYPACT_NINF -20

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-20)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      60,   -20,   -20,    75,    60,    60,    60,    60,    60,    60,
      42,    60,    60,    60,    22,    12,   -20,    75,   -20,     3,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
       1,   -20,   -20,   -20,    91,   -20,    60,    60,    60,    60,
      60,   -20,     7,   -20,     7,    60,   -20,    21,    21,     6,
       6,     6,     3,     8,    60,   -20
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,    12,    11,    14,
      26,    27,    28,     8,    24,    23,    22,    21,    20,    19,
       0,    18,    17,    16,     0,     1,     0,     0,     0,     0,
       0,     2,    13,    10,     0,     0,    31,     6,     7,     4,
       5,     3,    25,     0,     0,    15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -20,   -20,    -4,    37,    -5,    25,   -19,   -20,   -20,   -20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      24,    25,    26,    27,    28,    29,    31,    32,    33,    34,
       1,     2,    42,    36,    37,    38,    39,    36,    37,    38,
      39,    44,    35,    45,    40,    52,    40,    13,    38,    39,
      40,    54,    47,    48,    49,    50,    51,    42,    41,    40,
      23,    53,    43,     0,     0,     1,     2,     0,     3,     0,
      55,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    30,    13,     1,     2,     0,     3,     0,     0,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     1,     2,
      13,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,    13,    36,    37,    38,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    40,
       0,     0,    46
};

static const yytype_int8 yycheck[] =
{
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       3,     4,    17,     5,     6,     7,     8,     5,     6,     7,
       8,    18,     0,    22,    18,    44,    18,    20,     7,     8,
      18,    23,    36,    37,    38,    39,    40,    42,    26,    18,
       3,    45,    17,    -1,    -1,     3,     4,    -1,     6,    -1,
      54,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    20,     3,     4,    -1,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     3,     4,
      20,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    20,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    20,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    30,    29,    29,    29,    29,    29,    29,
      19,    29,    29,    29,    29,     0,     5,     6,     7,     8,
      18,    26,    31,    32,    18,    22,    21,    29,    29,    29,
      29,    29,    33,    29,    23,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    27,    28,    29,    29,    29,    29,    29,    29,    29,
      30,    30,    30,    31,    31,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    33,    33,    33,    33,    34,
      35,    36
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     3,     3,     3,     3,     2,     1,
       2,     1,     1,     2,     1,     6,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     1,     1,     1,     1,
       1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (root, list, vmap, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, root, list, vmap); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, functor <double> ::node *(&root), functor <double> ::param_list list, functor <double> ::map &vmap)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (root);
  YYUSE (list);
  YYUSE (vmap);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, functor <double> ::node *(&root), functor <double> ::param_list list, functor <double> ::map &vmap)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, root, list, vmap);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, functor <double> ::node *(&root), functor <double> ::param_list list, functor <double> ::map &vmap)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , root, list, vmap);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, root, list, vmap); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, functor <double> ::node *(&root), functor <double> ::param_list list, functor <double> ::map &vmap)
{
  YYUSE (yyvaluep);
  YYUSE (root);
  YYUSE (list);
  YYUSE (vmap);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (functor <double> ::node *(&root), functor <double> ::param_list list, functor <double> ::map &vmap)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 100 "fparser.y" /* yacc.c:1646  */
    {
     		// value->set($1->get());
		//printf("end of input, root is %s\n", $1->tok->str().c_str());
		root = (yyvsp[-1].expr);
		// root = new functor <double> ::node {new operand <double> (10), functor <double> ::m_none, vector <functor <double> ::node *> ()};
		// functor <double> ::print($1, 1, 0);
		// functor <double> ::print(root, 1, 0);
		return 0;
}
#line 1319 "fparser.h" /* yacc.c:1646  */
    break;

  case 3:
#line 111 "fparser.y" /* yacc.c:1646  */
    { // Exponentiation
   		//printf("expression exponentiation\n");
		/* vector <operand <double>> vals;
		vals.push_back(*$1);
		vals.push_back(*$3);

		$$ = new operand <double> (defaults <double> ::exp_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[-2].expr));
		leaves.push_back((yyvsp[0].expr));

		(yyval.expr) = new functor <double> ::node {&defaults <double> ::exp_op, functor <double> ::m_none, leaves};
}
#line 1337 "fparser.h" /* yacc.c:1646  */
    break;

  case 4:
#line 125 "fparser.y" /* yacc.c:1646  */
    { // Multiplication
   		//printf("expression multiplication\n");
		/* vector <operand <double>> vals;
		vals.push_back(*$1);
		vals.push_back(*$3);

		$$ = new operand <double> (defaults <double> ::mult_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[-2].expr));
		leaves.push_back((yyvsp[0].expr));

		(yyval.expr) = new functor <double> ::node {&defaults <double> ::mult_op, functor <double> ::m_none, leaves};
}
#line 1355 "fparser.h" /* yacc.c:1646  */
    break;

  case 5:
#line 139 "fparser.y" /* yacc.c:1646  */
    { // Division
   		//printf("expression divition\n");
		/* tor <operand <double>> vals;
		vals.push_back(*$1);
		vals.push_back(*$3);

		$$ = new operand <double> (defaults <double> ::div_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[-2].expr));
		leaves.push_back((yyvsp[0].expr));

		(yyval.expr) = new functor <double> ::node {&defaults <double> ::div_op, functor <double> ::m_none, leaves};
}
#line 1373 "fparser.h" /* yacc.c:1646  */
    break;

  case 6:
#line 153 "fparser.y" /* yacc.c:1646  */
    { // Addition
   		//printf("expression addition\n");
		/* vector <operand <double>> vals;
		vals.push_back(*$1);
		vals.push_back(*$3);

		$$ = new operand <double> (defaults <double> ::add_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[-2].expr));
		leaves.push_back((yyvsp[0].expr));

		(yyval.expr) = new functor <double> ::node {&defaults <double> ::add_op, functor <double> ::m_none, leaves};
}
#line 1391 "fparser.h" /* yacc.c:1646  */
    break;

  case 7:
#line 167 "fparser.y" /* yacc.c:1646  */
    { // Subtraction
   		//printf("expression substraction\n");
   		/* vector <operand <double>> vals;
		vals.push_back(*$1);
		vals.push_back(*$3);

		$$ = new operand <double> (defaults <double> ::sub_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[-2].expr));
		leaves.push_back((yyvsp[0].expr));

		(yyval.expr) = new functor <double> ::node {&defaults <double> ::sub_op, functor <double> ::m_none, leaves};
}
#line 1409 "fparser.h" /* yacc.c:1646  */
    break;

  case 8:
#line 181 "fparser.y" /* yacc.c:1646  */
    {
   		//printf("expression negative collective\n");
   		/* vector <operand <double>> vals;
		vals.push_back(operand <double> (-1));
		vals.push_back(*$2);

		$$ = new operand <double> (defaults <double> ::mult_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back(new functor <double> ::node (new operand <double> (-1), functor <double> ::m_none,
			vector <functor <double> ::node *> ()));
		leaves.push_back((yyvsp[0].coll));

		(yyval.expr) = new functor <double> ::node {&defaults <double> ::sub_op, functor <double> ::m_none, leaves};
}
#line 1428 "fparser.h" /* yacc.c:1646  */
    break;

  case 9:
#line 196 "fparser.y" /* yacc.c:1646  */
    {
   		//printf("expression collective\n");
   		(yyval.expr) = (yyvsp[0].coll);
}
#line 1437 "fparser.h" /* yacc.c:1646  */
    break;

  case 10:
#line 202 "fparser.y" /* yacc.c:1646  */
    { // Implicit Multiplication: term and non-arithmetic operation
    		//printf("collective, term (%s) implicitly multiplicied with non-arithmetic operation (%s)\n", $1->tok->str().c_str(), $2->tok->str().c_str());
		/* vector <operand <double>> vals;
		vals.push_back(*$1);
		vals.push_back(*$2);

		$$ = new operand <double> (defaults <double> ::mult_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[-1].term));
		leaves.push_back((yyvsp[0].felm));

		(yyval.coll) = new functor <double> ::node (&defaults <double> ::mult_op, functor <double> ::m_none, leaves);
}
#line 1455 "fparser.h" /* yacc.c:1646  */
    break;

  case 11:
#line 216 "fparser.y" /* yacc.c:1646  */
    {
    		(yyval.coll) = (yyvsp[0].felm);
}
#line 1463 "fparser.h" /* yacc.c:1646  */
    break;

  case 12:
#line 220 "fparser.y" /* yacc.c:1646  */
    {

    		// printf("collective as a regular term (%s)\n", $1->str().c_str());
    		(yyval.coll) = (yyvsp[0].term);
}
#line 1473 "fparser.h" /* yacc.c:1646  */
    break;

  case 13:
#line 227 "fparser.y" /* yacc.c:1646  */
    { // Implicit Multiplication: two or more terms
    		//printf("term with two terms, %s and %s\n", $1->tok->str().c_str(), $2->tok->str().c_str());
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[-1].term));
		leaves.push_back((yyvsp[0].term));

		(yyval.term) = new functor <double> ::node (&defaults <double> ::mult_op, functor <double> ::m_none, leaves);
}
#line 1486 "fparser.h" /* yacc.c:1646  */
    break;

  case 14:
#line 236 "fparser.y" /* yacc.c:1646  */
    { // Direct Operand
    		//printf("term with direct operand %s\n", $1->tok->str().c_str());
    		(yyval.term) = (yyvsp[0].dopn);
}
#line 1495 "fparser.h" /* yacc.c:1646  */
    break;

  case 15:
#line 242 "fparser.y" /* yacc.c:1646  */
    {
    		// printf("non-arithmetic regular logarithm: log_{%s} (%s)\n", $4->str().c_str(), $6->str().c_str());
   		/* vector <operand <double>> vals;
		
		vals.push_back(*$4);
		vals.push_back(*$6);

		$$ = new operand <double> (defaults <double> ::log_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[-2].expr));
		leaves.push_back((yyvsp[0].expr));

		(yyval.felm) = new functor <double> ::node {&defaults <double> ::log_op,
			functor <double> ::m_none, leaves};
}
#line 1515 "fparser.h" /* yacc.c:1646  */
    break;

  case 16:
#line 258 "fparser.y" /* yacc.c:1646  */
    { // Binary log
    		//printf("non-arithmetic binary logarithm of %s\n", $2->str().c_str());
   		/* vector <operand <double>> vals;
		
		vals.push_back(operand <double> (2));
		vals.push_back(*$2);

		$$ = new operand <double> (defaults <double> ::log_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back(new functor <double> ::node (new operand <double> (2), functor <double> ::m_none,
			vector <functor <double> ::node *> ()));
		leaves.push_back((yyvsp[0].expr));

		(yyval.felm) = new functor <double> ::node {&defaults <double> ::log_op,
			functor <double> ::m_none, leaves};
}
#line 1536 "fparser.h" /* yacc.c:1646  */
    break;

  case 17:
#line 275 "fparser.y" /* yacc.c:1646  */
    { // Natural log
    		//printf("non-arithmetic natural logarithm of %s\n", $2->tok->str().c_str());
   		/* vector <operand <double>> vals;
		
		vals.push_back(operand <double> (exp(1.0)));
		vals.push_back(*$2);

		$$ = new operand <double> (defaults <double> ::log_op(vals));
		vector <functor <double> ::node *> leaves;
		leaves.push_back($2);

		$$ = new functor <double> ::node {&defaults <double> ::sin_op,
			m_none, leaves}; */
		vector <functor <double> ::node *> leaves;
		leaves.push_back(new functor <double> ::node (new operand <double> (exp(1)), functor <double> ::m_none,
			vector <functor <double> ::node *> ()));
		leaves.push_back((yyvsp[0].expr));

		(yyval.felm) = new functor <double> ::node {&defaults <double> ::log_op,
			functor <double> ::m_none, leaves};
}
#line 1562 "fparser.h" /* yacc.c:1646  */
    break;

  case 18:
#line 297 "fparser.y" /* yacc.c:1646  */
    { // Log base 10
   		/* vector <operand <double>> vals;
		
		vals.push_back(operand <double> (10));
		vals.push_back(*$2);

		$$ = new operand <double> (defaults <double> ::log_op(vals));
		vector <functor <double> ::node *> leaves;
		leaves.push_back($2);

		$$ = new functor <double> ::node {&defaults <double> ::sin_op,
			functor <double> ::m_none, leaves}; */
		vector <functor <double> ::node *> leaves;
		leaves.push_back(new functor <double> ::node (new operand <double> (10), functor <double> ::m_none,
			vector <functor <double> ::node *> ()));
		leaves.push_back((yyvsp[0].expr));

		(yyval.felm) = new functor <double> ::node {&defaults <double> ::log_op,
			functor <double> ::m_none, leaves};
}
#line 1587 "fparser.h" /* yacc.c:1646  */
    break;

  case 19:
#line 318 "fparser.y" /* yacc.c:1646  */
    { // Cot
   		/* vector <operand <double>> vals;
		vals.push_back(*$2);

		$$ = new operand <double> (defaults <double> ::cot_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[0].expr));

		(yyval.felm) = new functor <double> ::node {&defaults <double> ::cot_op,
			functor <double> ::m_none, leaves};
}
#line 1603 "fparser.h" /* yacc.c:1646  */
    break;

  case 20:
#line 330 "fparser.y" /* yacc.c:1646  */
    { // Sec
   		/* vector <operand <double>> vals;
		vals.push_back(*$2);

		$$ = new operand <double> (defaults <double> ::sec_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[0].expr));

		(yyval.felm) = new functor <double> ::node {&defaults <double> ::sec_op,
			functor <double> ::m_none, leaves};
}
#line 1619 "fparser.h" /* yacc.c:1646  */
    break;

  case 21:
#line 342 "fparser.y" /* yacc.c:1646  */
    { // Csc
   		/* vector <operand <double>> vals;
		vals.push_back(*$2);

		$$ = new operand <double> (defaults <double> ::csc_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[0].expr));

		(yyval.felm) = new functor <double> ::node {&defaults <double> ::csc_op,
			functor <double> ::m_none, leaves};
}
#line 1635 "fparser.h" /* yacc.c:1646  */
    break;

  case 22:
#line 354 "fparser.y" /* yacc.c:1646  */
    { // Tan
   		/* vector <operand <double>> vals;
		vals.push_back(*$2);

		$$ = new operand <double> (defaults <double> ::tan_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[0].expr));

		(yyval.felm) = new functor <double> ::node {&defaults <double> ::tan_op,
			functor <double> ::m_none, leaves};
}
#line 1651 "fparser.h" /* yacc.c:1646  */
    break;

  case 23:
#line 366 "fparser.y" /* yacc.c:1646  */
    { // Cos
   		/* vector <operand <double>> vals;
		vals.push_back(*$2);

		$$ = new operand <double> (defaults <double> ::cos_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[0].expr));

		(yyval.felm) = new functor <double> ::node {&defaults <double> ::cos_op,
			functor <double> ::m_none, leaves};
}
#line 1667 "fparser.h" /* yacc.c:1646  */
    break;

  case 24:
#line 378 "fparser.y" /* yacc.c:1646  */
    { // Sin
		/* vector <operand <double>> vals;
		vals.push_back(*$2);

		$$ = new operand <double> (defaults <double> ::sin_op(vals)); */
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[0].expr));

		(yyval.felm) = new functor <double> ::node {&defaults <double> ::sin_op,
			functor <double> ::m_none, leaves};
}
#line 1683 "fparser.h" /* yacc.c:1646  */
    break;

  case 25:
#line 391 "fparser.y" /* yacc.c:1646  */
    {
		/* vector <operand <double>> vals;
		vals.push_back(*$1);
		vals.push_back(*$3);

		$$ = new operand <double> (defaults <double> ::exp_op(vals)); */
		
		vector <functor <double> ::node *> leaves;
		leaves.push_back((yyvsp[-2].dopn));
		leaves.push_back((yyvsp[0].dopn));

		(yyval.dopn) = new functor <double> ::node {&defaults <double> ::exp_op,
			functor <double> ::m_none, leaves};
}
#line 1702 "fparser.h" /* yacc.c:1646  */
    break;

  case 26:
#line 406 "fparser.y" /* yacc.c:1646  */
    {
    		(yyval.dopn) = (yyvsp[0].dpnt);
}
#line 1710 "fparser.h" /* yacc.c:1646  */
    break;

  case 27:
#line 410 "fparser.y" /* yacc.c:1646  */
    {
    		(yyval.dopn) = (yyvsp[0].sclr);
}
#line 1718 "fparser.h" /* yacc.c:1646  */
    break;

  case 28:
#line 414 "fparser.y" /* yacc.c:1646  */
    {
    		(yyval.dopn) = (yyvsp[0].prth);
}
#line 1726 "fparser.h" /* yacc.c:1646  */
    break;

  case 29:
#line 419 "fparser.y" /* yacc.c:1646  */
    { // Variable
    		//printf("dependant, variable %s\n", $1);
		string str = (yyvsp[0].ident);
		
		/* try {
			var = vst.find(str);
		} catch (...) {
			yyerror(value, vst, "no variable in scope");
		} */

		/* bool param = false;
		for (auto v : list) {
			if (v.symbol() == str) {
				param = true;
				break;
			}
		}

		if (!param)
			yyerror(root, list, vmap, "no variable in function scope"); */

		// variable <double> *var = new variable <double> {str, true};
		functor <double> ::node *save;
		functor <double> ::node *temp;
		functor <double> ::node *in;
		// variable <double> var;

		(yyval.dpnt) = new functor <double> ::node {&defaults <double> ::mult_op,
			functor <double> ::m_variable, vector <functor <double> ::node *>
			{new functor <double> ::node {new operand <double> (1), functor <double> ::m_none, {}},
			new functor <double> ::node {new operand <double> (1), functor <double> ::m_none, {}}}};
		temp = (yyval.dpnt);

		int num = 0;

		string acc;
		for (int i = 0; i < str.length(); i++) {
			acc += str[i];

			auto var = find_if(list.begin(), list.end(),
				[&](const variable <double> &vr) {
					return vr.symbol() == acc;
				}
			);

			if (var != list.end()) {
				/* in = new functor <double> ::node {&(*var), functor <double> ::m_none, {}};
				temp->leaves[1] = new functor <double> ::node {&defaults <double> ::mult_op,
					functor <double> ::m_none, vector <functor <double> ::node *> {in,
					new functor <double> ::node {new operand <double> (1), functor <double> ::m_none, {}}}};
				temp = temp->leaves[1]; */
				(yyval.dpnt) = new functor <double> ::node {&defaults <double> ::mult_op, functor <double> ::m_none,
					{(yyval.dpnt), new functor <double> ::node {new variable <double> {var->symbol(), true}, functor <double> ::m_none, {}}}};
				vmap[var->symbol()].push_back((yyval.dpnt)->leaves[1]);
				// temp = $$;
				acc.clear();
				num++;
			}
		}

		// printf("done\n");
		//$$ = new functor <double> ::node {new variable <double> {"x", true}, functor <double> ::m_none, {}};
		//functor <double> ::print($$, 1, 0);

		if (!num)
			throw functor <double> ::invalid_definition();

		// operand <double> val = new operand <double> (var.get());
}
#line 1800 "fparser.h" /* yacc.c:1646  */
    break;

  case 30:
#line 490 "fparser.y" /* yacc.c:1646  */
    { // Number
		operand <double> *val = new operand <double> ((yyvsp[0].value));
		(yyval.sclr) = new functor <double> ::node {val, functor <double> ::m_constant,
			vector <functor <double> ::node *> ()};
    		//printf("scalar, %s\n", $$->tok->str().c_str());
}
#line 1811 "fparser.h" /* yacc.c:1646  */
    break;

  case 31:
#line 498 "fparser.y" /* yacc.c:1646  */
    { // Parenthesis
    		//printf("parenthesis, %s\n", $2->tok->str().c_str());
   		(yyval.prth) = (yyvsp[-1].expr);
}
#line 1820 "fparser.h" /* yacc.c:1646  */
    break;


#line 1824 "fparser.h" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (root, list, vmap, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (root, list, vmap, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval, root, list, vmap);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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
                  yystos[yystate], yyvsp, root, list, vmap);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (root, list, vmap, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, root, list, vmap);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, root, list, vmap);
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
  return yyresult;
}
#line 503 "fparser.y" /* yacc.c:1906  */


void yyerror(functor <double> ::node *(&nd), functor <double> ::param_list l, functor <double> ::map m, const char *error)
{
	cout << error << endl;
}
