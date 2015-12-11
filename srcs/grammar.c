/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "grammar.y"

    #include <stdio.h>
    #include "parse.h"
    #include "hachage.h"

    extern int yylineno;
    int yylex ();
    int yyerror ();

    char *newvar() {
      static int i=0;
      char *s = NULL;
      asprintf(&s,"%%x%d",i++);
      return s;
    }
    gen_t EMPTY= {"", INT_T, "" } ;
    base basetype;


/* Line 371 of yacc.c  */
#line 88 "grammar.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.tab.h".  */
#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANTI = 259,
     CONSTANTF = 260,
     MAP = 261,
     REDUCE = 262,
     EXTERN = 263,
     DO = 264,
     INC_OP = 265,
     DEC_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     SUB_ASSIGN = 271,
     MUL_ASSIGN = 272,
     ADD_ASSIGN = 273,
     TYPE_NAME = 274,
     INT = 275,
     FLOAT = 276,
     VOID = 277,
     IF = 278,
     ELSE = 279,
     WHILE = 280,
     RETURN = 281,
     FOR = 282
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 33 "grammar.y"

  char *string;
  int n;
  float f;
  gen_t g;


/* Line 387 of yacc.c  */
#line 166 "grammar.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 194 "grammar.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   302

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,    34,    36,    30,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      37,    39,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    20,    27,    31,
      36,    39,    42,    44,    49,    51,    55,    57,    60,    63,
      66,    68,    70,    74,    78,    80,    84,    88,    90,    94,
      98,   102,   106,   110,   114,   118,   120,   122,   124,   126,
     128,   132,   137,   139,   143,   145,   147,   149,   151,   155,
     160,   164,   169,   173,   175,   179,   182,   184,   186,   188,
     190,   192,   195,   199,   204,   206,   209,   211,   214,   216,
     219,   225,   233,   241,   247,   254,   257,   261,   263,   266,
     268,   270
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      68,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    28,
      52,    29,    -1,     6,    28,    45,    30,    45,    29,    -1,
       7,    28,    45,    30,    45,    29,    -1,     3,    28,    29,
      -1,     3,    28,    46,    29,    -1,     3,    10,    -1,     3,
      11,    -1,    44,    -1,    45,    31,    52,    32,    -1,    52,
      -1,    46,    30,    52,    -1,    45,    -1,    10,    47,    -1,
      11,    47,    -1,    48,    47,    -1,    33,    -1,    47,    -1,
      49,    34,    47,    -1,    49,    35,    47,    -1,    49,    -1,
      50,    36,    49,    -1,    50,    33,    49,    -1,    50,    -1,
      50,    37,    50,    -1,    50,    38,    50,    -1,    50,    12,
      50,    -1,    50,    13,    50,    -1,    50,    14,    50,    -1,
      50,    15,    50,    -1,    47,    53,    51,    -1,    51,    -1,
      39,    -1,    17,    -1,    18,    -1,    16,    -1,    56,    55,
      40,    -1,     8,    56,    55,    40,    -1,    57,    -1,    55,
      30,    57,    -1,    22,    -1,    20,    -1,    21,    -1,     3,
      -1,    28,    57,    29,    -1,    57,    31,     4,    32,    -1,
      57,    31,    32,    -1,    57,    28,    58,    29,    -1,    57,
      28,    29,    -1,    59,    -1,    58,    30,    59,    -1,    56,
      57,    -1,    61,    -1,    64,    -1,    65,    -1,    66,    -1,
      67,    -1,    41,    42,    -1,    41,    63,    42,    -1,    41,
      62,    63,    42,    -1,    54,    -1,    62,    54,    -1,    60,
      -1,    63,    60,    -1,    40,    -1,    52,    40,    -1,    23,
      28,    52,    29,    60,    -1,    23,    28,    52,    29,    60,
      24,    60,    -1,    27,    28,    64,    64,    52,    29,    60,
      -1,    25,    28,    52,    29,    60,    -1,     9,    60,    25,
      28,    52,    29,    -1,    26,    40,    -1,    26,    52,    40,
      -1,    69,    -1,    68,    69,    -1,    70,    -1,    54,    -1,
      56,    57,    61,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    56,    61,    66,    67,    68,    69,    70,
      71,    72,    76,    77,    81,    82,    86,    87,    88,    89,
     100,   104,   105,   114,   126,   127,   137,   147,   148,   149,
     150,   151,   152,   153,   157,   158,   162,   163,   164,   165,
     169,   170,   174,   175,   179,   180,   181,   185,   195,   196,
     197,   198,   199,   203,   204,   208,   212,   213,   214,   215,
     216,   220,   221,   222,   226,   227,   231,   232,   236,   237,
     241,   242,   243,   247,   248,   252,   253,   257,   258,   262,
     263,   267
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANTI", "CONSTANTF",
  "MAP", "REDUCE", "EXTERN", "DO", "INC_OP", "DEC_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "SUB_ASSIGN", "MUL_ASSIGN", "ADD_ASSIGN", "TYPE_NAME",
  "INT", "FLOAT", "VOID", "IF", "ELSE", "WHILE", "RETURN", "FOR", "'('",
  "')'", "','", "'['", "']'", "'-'", "'*'", "'/'", "'+'", "'<'", "'>'",
  "'='", "';'", "'{'", "'}'", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "multiplicative_expression", "additive_expression",
  "comparison_expression", "expression", "assignment_operator",
  "declaration", "declarator_list", "type_name", "declarator",
  "parameter_list", "parameter_declaration", "statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "program", "external_declaration",
  "function_definition", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    40,    41,
      44,    91,    93,    45,    42,    47,    43,    60,    62,    61,
      59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    45,    45,    46,    46,    47,    47,    47,    47,
      48,    49,    49,    49,    50,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    53,    53,    53,    53,
      54,    54,    55,    55,    56,    56,    56,    57,    57,    57,
      57,    57,    57,    58,    58,    59,    60,    60,    60,    60,
      60,    61,    61,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     6,     6,     3,     4,
       2,     2,     1,     4,     1,     3,     1,     2,     2,     2,
       1,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     3,     4,
       3,     4,     3,     1,     3,     2,     1,     1,     1,     1,
       1,     2,     3,     4,     1,     2,     1,     2,     1,     2,
       5,     7,     7,     5,     6,     2,     3,     1,     2,     1,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    45,    46,    44,    80,     0,     0,    77,    79,
       0,    47,     0,     0,    42,     1,    78,     0,    42,     0,
       0,    40,     0,     0,     0,    81,    41,    48,    43,    52,
       0,     0,    53,     0,    50,     2,     3,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,    68,
      61,    12,    16,    21,     0,    24,    27,    35,     0,    64,
       0,    66,    56,     0,     0,    57,    58,    59,    60,    55,
      51,     0,    49,    10,    11,     0,     0,     0,     0,    17,
      18,     0,     0,    75,     0,     0,     0,     0,    39,    37,
      38,    36,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    65,     0,    62,    67,    54,
       8,     0,    14,     0,     0,     0,     0,     0,    76,     0,
       5,     0,    21,    34,    22,    23,    30,    31,    32,    33,
      26,    25,    28,    29,    63,     9,     0,     0,     0,     0,
       0,     0,     0,    13,    15,     0,     0,     0,    70,    73,
       0,     6,     7,    74,     0,     0,    71,    72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    51,    52,   111,    53,    54,    55,    56,    57,    58,
      92,     5,    13,     6,    18,    31,    32,    61,    62,    63,
      64,    65,    66,    67,    68,     7,     8,     9
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int16 yypact[] =
{
      33,   149,   -78,   -78,   -78,   -78,    12,   206,   -78,   -78,
      12,   -78,    12,     5,   106,   -78,   -78,   128,   105,    68,
      12,   -78,   200,     0,    99,   -78,   -78,   -78,   105,   -78,
      12,    19,   -78,   -18,   -78,     8,   -78,   -78,    -6,     2,
     229,   269,   269,    63,   103,     6,   124,   269,   -78,   -78,
     -78,   -78,   132,   112,   269,    22,    14,   -78,   134,   -78,
      12,   -78,   -78,   190,   139,   -78,   -78,   -78,   -78,   105,
     -78,   149,   -78,   -78,   -78,   238,    55,    55,   160,   -78,
     -78,   269,   269,   -78,   146,    83,   158,   269,   -78,   -78,
     -78,   -78,   269,   -78,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   -78,   -78,   150,   -78,   -78,   -78,
     -78,    40,   -78,    54,    82,   161,   159,   173,   -78,    83,
     -78,   171,   -78,   -78,   -78,   -78,   102,   102,   102,   102,
      22,    22,   102,   102,   -78,   -78,   269,    55,    55,   269,
     229,   229,   269,   -78,   -78,    34,   153,   175,   181,   -78,
     178,   -78,   -78,   -78,   229,   229,   -78,   -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   -70,   -78,   -21,   -78,    17,   162,   116,   -44,
     -78,   -19,   199,     1,   271,   -78,   148,   -40,   210,   -78,
     174,   -77,   -78,   -78,   -78,   -78,   218,   -78
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      78,    84,    10,    86,    33,    59,   113,   114,   119,    35,
      36,    37,    38,    39,    72,    11,    41,    42,    73,    74,
      79,    80,    76,    30,   108,    60,    96,    97,    98,    99,
      77,   112,    34,    93,    47,    20,    75,   116,   117,    48,
      12,     1,   142,   121,   105,    21,    83,   100,    70,    71,
     101,   102,   103,     2,     3,     4,    94,    95,    35,    36,
      37,    38,    39,   151,    60,    87,   108,   145,   146,   135,
     136,   122,    30,   124,   125,   122,   122,   122,   122,   122,
     122,   122,   122,    47,   137,    87,    35,    36,    37,    38,
      39,    81,   144,    41,    42,   147,    22,    27,   150,    23,
     148,   149,    35,    36,    37,    38,    39,     1,    40,    41,
      42,    47,   138,    87,   156,   157,    48,   130,   131,     2,
       3,     4,    43,    49,    44,    45,    46,    47,    88,    89,
      90,    82,    48,    22,    22,   100,    23,    23,   101,    49,
      24,    50,    35,    36,    37,    38,    39,    24,    40,    41,
      42,    91,    85,    35,    36,    37,    38,    39,    20,    40,
      41,    42,    43,    87,    44,    45,    46,    47,    26,     2,
       3,     4,    48,    43,   104,    44,    45,    46,    47,    49,
      24,   107,   152,    48,    87,   115,   118,   120,   140,   139,
      49,    24,   134,    35,    36,    37,    38,    39,     1,    40,
      41,    42,   141,   143,   153,   154,    15,   155,   123,    17,
       2,     3,     4,    43,     1,    44,    45,    46,    47,   109,
       2,     3,     4,    48,    25,    16,     2,     3,     4,    29,
      49,    24,    35,    36,    37,    38,    39,   106,    40,    41,
      42,    35,    36,    37,    38,    39,     0,     0,    41,    42,
       0,     0,    43,     0,    44,    45,    46,    47,   126,   127,
     128,   129,    48,     0,   132,   133,    47,   110,     0,    49,
      24,    48,    35,    36,    37,    38,    39,    14,     0,    41,
      42,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,     0,     0,     0,    47,     0,     0,
       0,    69,    48
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-78)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      40,    45,     1,    47,     4,    24,    76,    77,    85,     3,
       4,     5,     6,     7,    32,     3,    10,    11,    10,    11,
      41,    42,    28,    22,    64,    24,    12,    13,    14,    15,
      28,    75,    32,    54,    28,    30,    28,    81,    82,    33,
      28,     8,   119,    87,    63,    40,    40,    33,    29,    30,
      36,    37,    38,    20,    21,    22,    34,    35,     3,     4,
       5,     6,     7,    29,    63,    31,   106,   137,   138,    29,
      30,    92,    71,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    28,    30,    31,     3,     4,     5,     6,
       7,    28,   136,    10,    11,   139,    28,    29,   142,    31,
     140,   141,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    28,    30,    31,   154,   155,    33,   100,   101,    20,
      21,    22,    23,    40,    25,    26,    27,    28,    16,    17,
      18,    28,    33,    28,    28,    33,    31,    31,    36,    40,
      41,    42,     3,     4,     5,     6,     7,    41,     9,    10,
      11,    39,    28,     3,     4,     5,     6,     7,    30,     9,
      10,    11,    23,    31,    25,    26,    27,    28,    40,    20,
      21,    22,    33,    23,    40,    25,    26,    27,    28,    40,
      41,    42,    29,    33,    31,    25,    40,    29,    29,    28,
      40,    41,    42,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    29,    32,    29,    24,     0,    29,    92,    10,
      20,    21,    22,    23,     8,    25,    26,    27,    28,    71,
      20,    21,    22,    33,    14,     7,    20,    21,    22,    29,
      40,    41,     3,     4,     5,     6,     7,    63,     9,    10,
      11,     3,     4,     5,     6,     7,    -1,    -1,    10,    11,
      -1,    -1,    23,    -1,    25,    26,    27,    28,    96,    97,
      98,    99,    33,    -1,   102,   103,    28,    29,    -1,    40,
      41,    33,     3,     4,     5,     6,     7,     6,    -1,    10,
      11,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    30,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    20,    21,    22,    54,    56,    68,    69,    70,
      56,     3,    28,    55,    57,     0,    69,    55,    57,    57,
      30,    40,    28,    31,    41,    61,    40,    29,    57,    29,
      56,    58,    59,     4,    32,     3,     4,     5,     6,     7,
       9,    10,    11,    23,    25,    26,    27,    28,    33,    40,
      42,    44,    45,    47,    48,    49,    50,    51,    52,    54,
      56,    60,    61,    62,    63,    64,    65,    66,    67,    57,
      29,    30,    32,    10,    11,    28,    28,    28,    60,    47,
      47,    28,    28,    40,    52,    28,    52,    31,    16,    17,
      18,    39,    53,    47,    34,    35,    12,    13,    14,    15,
      33,    36,    37,    38,    40,    54,    63,    42,    60,    59,
      29,    46,    52,    45,    45,    25,    52,    52,    40,    64,
      29,    52,    47,    51,    47,    47,    50,    50,    50,    50,
      49,    49,    50,    50,    42,    29,    30,    30,    30,    28,
      29,    29,    64,    32,    52,    45,    45,    52,    60,    60,
      52,    29,    29,    29,    24,    29,    60,    60
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
/* Line 1792 of yacc.c  */
#line 43 "grammar.y"
    {
  gen_t g = findtab((yyvsp[(1) - (1)].string));
  char *nv= newvar();
  (yyval.g).var = nv;
  if ( g.type == INT_T){
    (yyval.g).type = INT_T;
    asprintf(&((yyval.g).code), "%s = load i32* %s\n", nv,g.var);
  }
  else{
    (yyval.g).type = FLOAT_T;
    asprintf(&((yyval.g).code), "%s = load float* %s\n", nv,g.var);
  }
 }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 56 "grammar.y"
    {
  (yyval.g).var=newvar(); 
  (yyval.g).type=INT_T;
  asprintf(&((yyval.g).code), "%s = add i32 0, %d\n", (yyval.g).var,(yyvsp[(1) - (1)].n));
 }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 61 "grammar.y"
    {
  (yyval.g).var=newvar(); 
  (yyval.g).type=FLOAT_T;
  asprintf(&((yyval.g).code), "%s = fadd float 0, %f\n", (yyval.g).var,(yyvsp[(1) - (1)].f));
 }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 66 "grammar.y"
    { (yyval.g) = EMPTY; }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 67 "grammar.y"
    { (yyval.g) = EMPTY; }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 68 "grammar.y"
    { (yyval.g) = EMPTY; }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 69 "grammar.y"
    { (yyval.g) = EMPTY; }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 70 "grammar.y"
    { (yyval.g) = EMPTY; }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 71 "grammar.y"
    { (yyval.g) = EMPTY; }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 72 "grammar.y"
    { (yyval.g) = EMPTY; }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 76 "grammar.y"
    { (yyval.g) = (yyvsp[(1) - (1)].g); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 77 "grammar.y"
    { (yyval.g) = (yyvsp[(1) - (4)].g); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 86 "grammar.y"
    { (yyval.g) = (yyvsp[(1) - (1)].g); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 87 "grammar.y"
    { (yyval.g) = (yyvsp[(2) - (2)].g); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 88 "grammar.y"
    { (yyval.g) = (yyvsp[(2) - (2)].g); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 89 "grammar.y"
    {   (yyval.g).var = newvar(); 
  if ((yyvsp[(2) - (2)].g).type==INT_T) {
  (yyval.g).type=INT_T;
    asprintf(&((yyval.g).code), "%s%s = sub i32 0, %s\n", (yyvsp[(2) - (2)].g).code, (yyval.g).var,(yyvsp[(2) - (2)].g).var);
 } else {
  (yyval.g).type=FLOAT_T;
    asprintf(&((yyval.g).code), "%s%s = fsub float 0, %s\n", (yyvsp[(2) - (2)].g).code, (yyval.g).var,(yyvsp[(2) - (2)].g).var);
 } }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 104 "grammar.y"
    { (yyval.g) = (yyvsp[(1) - (1)].g); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 105 "grammar.y"
    { 
  (yyval.g).var = newvar(); 
  if ((yyvsp[(1) - (3)].g).type==INT_T && (yyvsp[(3) - (3)].g).type==INT_T) {
  (yyval.g).type=INT_T;
    asprintf(&((yyval.g).code), "%s%s%s = mul i32 %s, %s\n", (yyvsp[(1) - (3)].g).code, (yyvsp[(3) - (3)].g).code,(yyval.g).var,(yyvsp[(1) - (3)].g).var,(yyvsp[(3) - (3)].g).var);
 } else {
  (yyval.g).type=FLOAT_T;
    asprintf(&((yyval.g).code), "%s%s%s = fmul float %s, %s\n", (yyvsp[(1) - (3)].g).code, (yyvsp[(3) - (3)].g).code,(yyval.g).var,(yyvsp[(1) - (3)].g).var,(yyvsp[(3) - (3)].g).var);
 } }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 114 "grammar.y"
    { 
  (yyval.g).var = newvar(); 
  if ((yyvsp[(1) - (3)].g).type==INT_T && (yyvsp[(3) - (3)].g).type==INT_T) {
  (yyval.g).type=INT_T;
    asprintf(&((yyval.g).code), "%s%s%s = sdiv i32 %s, %s\n", (yyvsp[(1) - (3)].g).code, (yyvsp[(3) - (3)].g).code,(yyval.g).var,(yyvsp[(1) - (3)].g).var,(yyvsp[(3) - (3)].g).var);
 } else {
  (yyval.g).type=FLOAT_T;
    asprintf(&((yyval.g).code), "%s%s%s = fdiv float %s, %s\n", (yyvsp[(1) - (3)].g).code, (yyvsp[(3) - (3)].g).code,(yyval.g).var,(yyvsp[(1) - (3)].g).var,(yyvsp[(3) - (3)].g).var);
 } }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 126 "grammar.y"
    { (yyval.g) = (yyvsp[(1) - (1)].g); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 127 "grammar.y"
    { 
  (yyval.g).var = newvar(); 
  if ((yyvsp[(1) - (3)].g).type==INT_T && (yyvsp[(3) - (3)].g).type==INT_T) {
  (yyval.g).type=INT_T;
    asprintf(&((yyval.g).code), "%s%s%s = add i32 %s, %s\n", (yyvsp[(1) - (3)].g).code, (yyvsp[(3) - (3)].g).code,(yyval.g).var,(yyvsp[(1) - (3)].g).var,(yyvsp[(3) - (3)].g).var);
 } else {
  (yyval.g).type=FLOAT_T;
    asprintf(&((yyval.g).code), "%s%s%s = fadd float %s, %s\n", (yyvsp[(1) - (3)].g).code, (yyvsp[(3) - (3)].g).code,(yyval.g).var,(yyvsp[(1) - (3)].g).var,(yyvsp[(3) - (3)].g).var);
 } 
 }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 137 "grammar.y"
    { 
  (yyval.g).var = newvar(); 
  if ((yyvsp[(1) - (3)].g).type==INT_T && (yyvsp[(3) - (3)].g).type==INT_T) {
    asprintf(&((yyval.g).code), "%s%s%s = sub i32 %s, %s\n", (yyvsp[(1) - (3)].g).code, (yyvsp[(3) - (3)].g).code,(yyval.g).var,(yyvsp[(1) - (3)].g).var,(yyvsp[(3) - (3)].g).var);
 } else {
    asprintf(&((yyval.g).code), "%s%s%s = fsub float %s, %s\n", (yyvsp[(1) - (3)].g).code, (yyvsp[(3) - (3)].g).code,(yyval.g).var,(yyvsp[(1) - (3)].g).var,(yyvsp[(3) - (3)].g).var);
 } }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 147 "grammar.y"
    { printf("%s\n",(yyvsp[(1) - (1)].g).code); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 179 "grammar.y"
    {basetype = VOID_T;}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 180 "grammar.y"
    {basetype = INT_T;}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 181 "grammar.y"
    {basetype = FLOAT;}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 185 "grammar.y"
    {
    (yyval.g).var = newvar();
    addtab((yyvsp[(1) - (1)].string),basetype,(yyval.g).var);
    if ( basetype == INT_T){
      asprintf(&((yyval.g).code),"%s = alloca i32\n",(yyval.g).var);
    }
    else{
      asprintf(&((yyval.g).code),"%s = alloca float\n",(yyval.g).var);      
    }
  }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 195 "grammar.y"
    { (yyval.g) = (yyvsp[(2) - (3)].g) ;}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 196 "grammar.y"
    { (yyval.g) = (yyvsp[(1) - (4)].g) ;}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 197 "grammar.y"
    { (yyval.g) = (yyvsp[(1) - (3)].g) ;}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 198 "grammar.y"
    { (yyval.g) = (yyvsp[(1) - (4)].g) ;}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 199 "grammar.y"
    { (yyval.g) = (yyvsp[(1) - (3)].g) ;}
    break;


/* Line 1792 of yacc.c  */
#line 1816 "grammar.c"
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
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
		  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 270 "grammar.y"

#include <stdio.h>
#include <string.h>
#include "hachage.h"

extern char yytext[];
extern int column;
extern int yylineno;
extern FILE *yyin;

char *file_name = NULL;

int yyerror (char *s) {
    fflush (stdout);
    fprintf (stderr, "%s:%d:%d: %s\n", file_name, yylineno, column, s);
    return 0;
}


int main (int argc, char *argv[]) {


    FILE *input = NULL;
    
    init();

    if (argc==2) {
	input = fopen (argv[1], "r");
	file_name = strdup (argv[1]);
	if (input) {
	    yyin = input;
	}
	else {
	  fprintf (stderr, "%s: Could not open %s\n", *argv, argv[1]);
	    return 1;
	}
    }
    else {
	fprintf (stderr, "%s: error: no input file\n", *argv);
	return 1;
    }
    yyparse ();
    free (file_name);
    return 0;
}
