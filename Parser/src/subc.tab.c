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
#line 8 "subc.y"

/* Prologue section */
#include <stdio.h>
#include <strings.h>

int   yylex ();
int   yyerror (char* s);
void  reduce(char* s);

#line 81 "subc.tab.c"

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

#include "subc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* ','  */
  YYSYMBOL_4_ = 4,                         /* '='  */
  YYSYMBOL_5_ = 5,                         /* '+'  */
  YYSYMBOL_6_ = 6,                         /* '-'  */
  YYSYMBOL_7_ = 7,                         /* '*'  */
  YYSYMBOL_8_ = 8,                         /* '/'  */
  YYSYMBOL_9_ = 9,                         /* '%'  */
  YYSYMBOL_10_ = 10,                       /* '['  */
  YYSYMBOL_11_ = 11,                       /* '.'  */
  YYSYMBOL_12_ = 12,                       /* '('  */
  YYSYMBOL_13_ = 13,                       /* '!'  */
  YYSYMBOL_14_ = 14,                       /* '&'  */
  YYSYMBOL_DEREF = 15,                     /* DEREF  */
  YYSYMBOL_LOWER_THAN_ELSE = 16,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_UMINUS = 17,                    /* UMINUS  */
  YYSYMBOL_TYPE = 18,                      /* TYPE  */
  YYSYMBOL_STRUCT = 19,                    /* STRUCT  */
  YYSYMBOL_SYM_NULL = 20,                  /* SYM_NULL  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_INTEGER_CONST = 22,             /* INTEGER_CONST  */
  YYSYMBOL_CHAR_CONST = 23,                /* CHAR_CONST  */
  YYSYMBOL_STRING = 24,                    /* STRING  */
  YYSYMBOL_IF = 25,                        /* IF  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_WHILE = 27,                     /* WHILE  */
  YYSYMBOL_FOR = 28,                       /* FOR  */
  YYSYMBOL_BREAK = 29,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 30,                  /* CONTINUE  */
  YYSYMBOL_LOGICAL_OR = 31,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_AND = 32,               /* LOGICAL_AND  */
  YYSYMBOL_RELOP = 33,                     /* RELOP  */
  YYSYMBOL_EQUOP = 34,                     /* EQUOP  */
  YYSYMBOL_INCOP = 35,                     /* INCOP  */
  YYSYMBOL_DECOP = 36,                     /* DECOP  */
  YYSYMBOL_STRUCTOP = 37,                  /* STRUCTOP  */
  YYSYMBOL_ID = 38,                        /* ID  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* ']'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_ext_def_list = 46,              /* ext_def_list  */
  YYSYMBOL_ext_def = 47,                   /* ext_def  */
  YYSYMBOL_type_specifier = 48,            /* type_specifier  */
  YYSYMBOL_struct_specifier = 49,          /* struct_specifier  */
  YYSYMBOL_func_decl = 50,                 /* func_decl  */
  YYSYMBOL_pointers = 51,                  /* pointers  */
  YYSYMBOL_param_list = 52,                /* param_list  */
  YYSYMBOL_param_decl = 53,                /* param_decl  */
  YYSYMBOL_def_list = 54,                  /* def_list  */
  YYSYMBOL_def = 55,                       /* def  */
  YYSYMBOL_compound_stmt = 56,             /* compound_stmt  */
  YYSYMBOL_stmt_list = 57,                 /* stmt_list  */
  YYSYMBOL_stmt = 58,                      /* stmt  */
  YYSYMBOL_expr_e = 59,                    /* expr_e  */
  YYSYMBOL_expr = 60,                      /* expr  */
  YYSYMBOL_binary = 61,                    /* binary  */
  YYSYMBOL_unary = 62,                     /* unary  */
  YYSYMBOL_args = 63                       /* args  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   235

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


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
       2,     2,     2,    13,     2,     2,     2,     9,    14,     2,
      12,    43,     7,     5,     3,     6,    11,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,     4,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    10,     2,    40,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    52,    53,    58,    59,    60,    61,    65,
      66,    70,    71,    75,    76,    80,    81,    85,    86,    90,
      91,    95,    96,   100,   101,   105,   109,   110,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   127,   128,
     132,   133,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   172,   173
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
  "\"end of file\"", "error", "\"invalid token\"", "','", "'='", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'['", "'.'", "'('", "'!'", "'&'", "DEREF",
  "LOWER_THAN_ELSE", "UMINUS", "TYPE", "STRUCT", "SYM_NULL", "RETURN",
  "INTEGER_CONST", "CHAR_CONST", "STRING", "IF", "ELSE", "WHILE", "FOR",
  "BREAK", "CONTINUE", "LOGICAL_OR", "LOGICAL_AND", "RELOP", "EQUOP",
  "INCOP", "DECOP", "STRUCTOP", "ID", "';'", "']'", "'{'", "'}'", "')'",
  "$accept", "program", "ext_def_list", "ext_def", "type_specifier",
  "struct_specifier", "func_decl", "pointers", "param_list", "param_decl",
  "def_list", "def", "compound_stmt", "stmt_list", "stmt", "expr_e",
  "expr", "binary", "unary", "args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-120)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -120,    12,    98,  -120,  -120,   -12,  -120,    15,  -120,     1,
       3,  -120,    24,  -120,  -120,  -120,    13,   112,    58,    38,
      -9,  -120,    43,    15,  -120,    99,    46,    53,  -120,    15,
       0,  -120,    54,    49,   172,   172,   172,   172,   172,  -120,
     172,  -120,  -120,  -120,    91,    96,   102,    71,    79,   172,
     172,  -120,  -120,  -120,  -120,  -120,    86,   182,     4,  -120,
      93,    95,   112,  -120,  -120,    -4,  -120,  -120,   101,  -120,
    -120,    97,   172,   172,   172,  -120,  -120,  -120,  -120,  -120,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   107,    66,  -120,  -120,   108,  -120,   129,  -120,    73,
     125,  -120,  -120,  -120,   119,   124,   130,  -120,    90,    47,
      90,  -120,  -120,  -120,   192,    41,   146,    22,  -120,   128,
    -120,  -120,  -120,     2,  -120,   148,  -120,   133,   136,   136,
     172,  -120,   172,  -120,   140,   137,   155,  -120,   143,  -120,
    -120,  -120,   136,   172,  -120,   150,   136,  -120
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     9,     0,     3,    16,    10,     0,
      12,    15,     0,    22,     8,    22,     0,    27,     0,     0,
       0,     5,     0,    16,    21,     0,    11,     0,    13,    16,
       0,    17,    12,     0,     0,     0,     0,     0,     0,    70,
       0,    53,    54,    55,     0,     0,     0,     0,     0,     0,
       0,    56,    31,    25,    29,    26,     0,    41,    49,     7,
       0,     0,     0,    14,    22,     0,    57,    64,     0,    58,
      63,     0,     0,     0,    39,    36,    37,    61,    62,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,    60,     0,     6,    19,    18,     0,
       0,    23,    52,    30,     0,     0,     0,    38,    44,    49,
      45,    46,    47,    48,    51,    50,    42,    43,    40,     0,
      66,    69,    71,     0,    67,     0,    11,     0,     0,     0,
      39,    65,     0,    68,     0,     0,    32,    34,     0,    72,
      20,    24,     0,    39,    33,     0,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,  -120,  -120,    -1,  -120,  -120,   -16,  -120,   121,
     -13,  -120,   193,  -120,    75,  -119,   -36,   147,   -17,  -120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,    23,     8,     9,    12,    30,    31,
      17,    24,    54,    25,    55,   106,    56,    57,    58,   123
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      68,     7,    18,    62,    71,   132,   100,    33,    89,     4,
      22,   138,     3,    61,    90,    91,    92,    66,    67,    29,
      69,    70,    11,    19,   145,    20,    10,    80,    81,    82,
      83,    84,    77,    78,    28,   101,   104,   105,   107,    93,
      94,    95,    13,    63,    15,   133,    80,    81,    82,    83,
      84,    99,    21,   118,   119,    87,   122,    90,    91,    92,
      27,    29,    16,   109,   109,   109,   109,   109,   109,   109,
     109,   109,    34,    35,    87,    88,     4,    22,    36,    37,
      38,    32,    93,    94,    95,    59,    39,    65,    41,    42,
      43,     4,    22,    60,   107,    64,   139,    82,    83,    84,
      26,    49,    50,    72,    51,    34,    35,   107,    73,   121,
      75,    36,    37,    38,    74,   126,     4,     5,    76,    39,
      40,    41,    42,    43,    44,    79,    45,    46,    47,    48,
       4,    22,    96,    97,    49,    50,   103,    51,    52,   125,
      13,    53,    34,    35,   102,   120,   124,   127,    36,    37,
      38,    80,    81,    82,    83,    84,    39,    40,    41,    42,
      43,    44,   128,    45,    46,    47,    48,   129,   131,   130,
     134,    49,    50,   135,    51,    52,   141,    13,    34,    35,
     140,   142,   143,    98,    36,    37,    38,    80,    81,    82,
      83,    84,    39,   146,    41,    42,    43,    80,    81,    82,
      83,    84,    14,   136,   137,     0,     0,    49,    50,     0,
      51,     0,     0,    85,    86,    87,    88,   144,     0,     0,
       0,   147,     0,     0,    86,    87,    88,   108,   110,   111,
     112,   113,   114,   115,   116,   117
};

static const yytype_int16 yycheck[] =
{
      36,     2,    15,     3,    40,     3,    10,    23,     4,    18,
      19,   130,     0,    29,    10,    11,    12,    34,    35,    20,
      37,    38,     7,    10,   143,    12,    38,     5,     6,     7,
       8,     9,    49,    50,    43,    39,    72,    73,    74,    35,
      36,    37,    41,    43,    41,    43,     5,     6,     7,     8,
       9,    64,    39,    89,    90,    33,    92,    10,    11,    12,
      22,    62,    38,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     6,     7,    33,    34,    18,    19,    12,    13,
      14,    38,    35,    36,    37,    39,    20,    38,    22,    23,
      24,    18,    19,    40,   130,    41,   132,     7,     8,     9,
      42,    35,    36,    12,    38,     6,     7,   143,    12,    43,
      39,    12,    13,    14,    12,    42,    18,    19,    39,    20,
      21,    22,    23,    24,    25,    39,    27,    28,    29,    30,
      18,    19,    39,    38,    35,    36,    39,    38,    39,    10,
      41,    42,     6,     7,    43,    38,    38,    22,    12,    13,
      14,     5,     6,     7,     8,     9,    20,    21,    22,    23,
      24,    25,    43,    27,    28,    29,    30,    43,    40,    39,
      22,    35,    36,    40,    38,    39,    39,    41,     6,     7,
      40,    26,    39,    62,    12,    13,    14,     5,     6,     7,
       8,     9,    20,    43,    22,    23,    24,     5,     6,     7,
       8,     9,     9,   128,   129,    -1,    -1,    35,    36,    -1,
      38,    -1,    -1,    31,    32,    33,    34,   142,    -1,    -1,
      -1,   146,    -1,    -1,    32,    33,    34,    80,    81,    82,
      83,    84,    85,    86,    87,    88
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    46,     0,    18,    19,    47,    48,    49,    50,
      38,     7,    51,    41,    56,    41,    38,    54,    54,    10,
      12,    39,    19,    48,    55,    57,    42,    22,    43,    48,
      52,    53,    38,    51,     6,     7,    12,    13,    14,    20,
      21,    22,    23,    24,    25,    27,    28,    29,    30,    35,
      36,    38,    39,    42,    56,    58,    60,    61,    62,    39,
      40,    51,     3,    43,    41,    38,    62,    62,    60,    62,
      62,    60,    12,    12,    12,    39,    39,    62,    62,    39,
       5,     6,     7,     8,     9,    31,    32,    33,    34,     4,
      10,    11,    12,    35,    36,    37,    39,    38,    53,    54,
      10,    39,    43,    39,    60,    60,    59,    60,    61,    62,
      61,    61,    61,    61,    61,    61,    61,    61,    60,    60,
      38,    43,    60,    63,    38,    10,    42,    22,    43,    43,
      39,    40,     3,    43,    22,    40,    58,    58,    59,    60,
      40,    39,    26,    39,    58,    59,    43,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    48,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     7,     6,     2,     1,
       1,     5,     2,     5,     6,     1,     0,     1,     3,     3,
       6,     2,     0,     4,     7,     4,     2,     0,     2,     1,
       3,     1,     5,     7,     5,     9,     2,     2,     1,     0,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     4,     3,     3,     4,     3,
       1,     1,     3
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
  case 2: /* program: ext_def_list  */
#line 48 "subc.y"
                { printf("program->ext_def_list\n"); }
#line 1239 "subc.tab.c"
    break;

  case 3: /* ext_def_list: ext_def_list ext_def  */
#line 52 "subc.y"
                        { printf("ext_def_list->ext_def_list ext_def\n"); }
#line 1245 "subc.tab.c"
    break;

  case 4: /* ext_def_list: %empty  */
#line 53 "subc.y"
          { printf("ext_def_list->epsilon\n"); }
#line 1251 "subc.tab.c"
    break;

  case 5: /* ext_def: type_specifier pointers ID ';'  */
#line 58 "subc.y"
                                  { printf("ext_def->type_specifier pointers ID ';'\n"); }
#line 1257 "subc.tab.c"
    break;

  case 6: /* ext_def: type_specifier pointers ID '[' INTEGER_CONST ']' ';'  */
#line 59 "subc.y"
                                                        { printf("ext_def->type_specifier pointers ID '[' INTEGER_CONST ']' ';'\n"); }
#line 1263 "subc.tab.c"
    break;

  case 7: /* ext_def: STRUCT ID '{' def_list '}' ';'  */
#line 60 "subc.y"
                                  { printf("ext_def->STRUCT ID '{' def_list '}' ';'\n"); }
#line 1269 "subc.tab.c"
    break;

  case 8: /* ext_def: func_decl compound_stmt  */
#line 61 "subc.y"
                           { printf("ext_def->func_decl compound_stmt\n"); }
#line 1275 "subc.tab.c"
    break;

  case 9: /* type_specifier: TYPE  */
#line 65 "subc.y"
        { printf("type_specifier->TYPE\n"); }
#line 1281 "subc.tab.c"
    break;

  case 10: /* type_specifier: struct_specifier  */
#line 66 "subc.y"
                    { printf("type_specifier->struct_specifier\n"); }
#line 1287 "subc.tab.c"
    break;

  case 11: /* struct_specifier: STRUCT ID '{' def_list '}'  */
#line 70 "subc.y"
                              { printf("struct_specifier->STRUCT ID '{' def_list '}'\n"); }
#line 1293 "subc.tab.c"
    break;

  case 12: /* struct_specifier: STRUCT ID  */
#line 71 "subc.y"
             { printf("struct_specifier->STRUCT ID\n"); }
#line 1299 "subc.tab.c"
    break;

  case 13: /* func_decl: type_specifier pointers ID '(' ')'  */
#line 75 "subc.y"
                                      { printf("func_decl->type_specifier pointers ID '(' ')'\n"); }
#line 1305 "subc.tab.c"
    break;

  case 14: /* func_decl: type_specifier pointers ID '(' param_list ')'  */
#line 76 "subc.y"
                                                 { printf("func_decl->type_specifier pointers ID '(' param_list ')'\n"); }
#line 1311 "subc.tab.c"
    break;

  case 15: /* pointers: '*'  */
#line 80 "subc.y"
       { printf("pointers->'*'\n"); }
#line 1317 "subc.tab.c"
    break;

  case 16: /* pointers: %empty  */
#line 81 "subc.y"
          { printf("pointers->epsilon\n"); }
#line 1323 "subc.tab.c"
    break;

  case 17: /* param_list: param_decl  */
#line 85 "subc.y"
              { printf("param_list->param_decl\n"); }
#line 1329 "subc.tab.c"
    break;

  case 18: /* param_list: param_list ',' param_decl  */
#line 86 "subc.y"
                             { printf("param_list->param_list ',' param_decl\n"); }
#line 1335 "subc.tab.c"
    break;

  case 19: /* param_decl: type_specifier pointers ID  */
#line 90 "subc.y"
                              { printf("param_decl->type_specifier pointers ID\n"); }
#line 1341 "subc.tab.c"
    break;

  case 20: /* param_decl: type_specifier pointers ID '[' INTEGER_CONST ']'  */
#line 91 "subc.y"
                                                    { printf("param_decl->type_specifier pointers ID '[' INTEGER_CONST ']'\n"); }
#line 1347 "subc.tab.c"
    break;

  case 21: /* def_list: def_list def  */
#line 95 "subc.y"
                { printf("def_list->def_list def\n"); }
#line 1353 "subc.tab.c"
    break;

  case 22: /* def_list: %empty  */
#line 96 "subc.y"
          { printf("def_list->epsilon\n"); }
#line 1359 "subc.tab.c"
    break;

  case 23: /* def: type_specifier pointers ID ';'  */
#line 100 "subc.y"
                                  { printf("def->type_specifier pointers ID ';'\n"); }
#line 1365 "subc.tab.c"
    break;

  case 24: /* def: type_specifier pointers ID '[' INTEGER_CONST ']' ';'  */
#line 101 "subc.y"
                                                        { printf("def->type_specifier pointers ID '[' INTEGER_CONST ']' ';'\n"); }
#line 1371 "subc.tab.c"
    break;

  case 25: /* compound_stmt: '{' def_list stmt_list '}'  */
#line 105 "subc.y"
                              { printf("compound_stmt->'{' def_list stmt_list '}'\n"); }
#line 1377 "subc.tab.c"
    break;

  case 26: /* stmt_list: stmt_list stmt  */
#line 109 "subc.y"
                  { printf("stmt_list->stmt_list stmt\n"); }
#line 1383 "subc.tab.c"
    break;

  case 27: /* stmt_list: %empty  */
#line 110 "subc.y"
          { printf("stmt_list->epsilon\n"); }
#line 1389 "subc.tab.c"
    break;

  case 28: /* stmt: expr ';'  */
#line 114 "subc.y"
            { printf("stmt->expr ';'\n"); }
#line 1395 "subc.tab.c"
    break;

  case 29: /* stmt: compound_stmt  */
#line 115 "subc.y"
                 { printf("stmt->compound_stmt\n"); }
#line 1401 "subc.tab.c"
    break;

  case 30: /* stmt: RETURN expr ';'  */
#line 116 "subc.y"
                   { printf("stmt->RETURN expr ';'\n"); }
#line 1407 "subc.tab.c"
    break;

  case 31: /* stmt: ';'  */
#line 117 "subc.y"
       { printf("stmt->';'\n"); }
#line 1413 "subc.tab.c"
    break;

  case 32: /* stmt: IF '(' expr ')' stmt  */
#line 118 "subc.y"
                                              { printf("stmt->IF '(' expr ')' stmt\n"); }
#line 1419 "subc.tab.c"
    break;

  case 33: /* stmt: IF '(' expr ')' stmt ELSE stmt  */
#line 119 "subc.y"
                                  { printf("stmt->IF '(' expr ')' stmt ELSE stmt\n"); }
#line 1425 "subc.tab.c"
    break;

  case 34: /* stmt: WHILE '(' expr ')' stmt  */
#line 120 "subc.y"
                           { printf("stmt->WHILE '(' expr ')' stmt\n"); }
#line 1431 "subc.tab.c"
    break;

  case 35: /* stmt: FOR '(' expr_e ';' expr_e ';' expr_e ')' stmt  */
#line 121 "subc.y"
                                                 { printf("stmt->FOR '(' expr_e ';' expr_e ';' expr_e ')' stmt\n"); }
#line 1437 "subc.tab.c"
    break;

  case 36: /* stmt: BREAK ';'  */
#line 122 "subc.y"
             { printf("stmt->BREAK ';'\n"); }
#line 1443 "subc.tab.c"
    break;

  case 37: /* stmt: CONTINUE ';'  */
#line 123 "subc.y"
                { printf("stmt->CONTINUE ';'\n"); }
#line 1449 "subc.tab.c"
    break;

  case 38: /* expr_e: expr  */
#line 127 "subc.y"
        { printf("expr_e->expr\n"); }
#line 1455 "subc.tab.c"
    break;

  case 39: /* expr_e: %empty  */
#line 128 "subc.y"
          { printf("expr_e->epsilon\n"); }
#line 1461 "subc.tab.c"
    break;

  case 40: /* expr: unary '=' expr  */
#line 132 "subc.y"
                  { printf("expr->unary '=' expr\n"); }
#line 1467 "subc.tab.c"
    break;

  case 41: /* expr: binary  */
#line 133 "subc.y"
          { printf("expr->binary\n"); }
#line 1473 "subc.tab.c"
    break;

  case 42: /* binary: binary RELOP binary  */
#line 137 "subc.y"
                       { printf("binary->binary RELOP binary\n"); }
#line 1479 "subc.tab.c"
    break;

  case 43: /* binary: binary EQUOP binary  */
#line 138 "subc.y"
                       { printf("binary->binary EQUOP binary\n"); }
#line 1485 "subc.tab.c"
    break;

  case 44: /* binary: binary '+' binary  */
#line 139 "subc.y"
                     { printf("binary->binary '+' binary\n"); }
#line 1491 "subc.tab.c"
    break;

  case 45: /* binary: binary '-' binary  */
#line 140 "subc.y"
                     { printf("binary->binary '-' binary\n"); }
#line 1497 "subc.tab.c"
    break;

  case 46: /* binary: binary '*' binary  */
#line 141 "subc.y"
                     { printf("binary->binary '*' binary\n"); }
#line 1503 "subc.tab.c"
    break;

  case 47: /* binary: binary '/' binary  */
#line 142 "subc.y"
                     { printf("binary->binary '/' binary\n"); }
#line 1509 "subc.tab.c"
    break;

  case 48: /* binary: binary '%' binary  */
#line 143 "subc.y"
                     { printf("binary->binary '%%' binary\n"); }
#line 1515 "subc.tab.c"
    break;

  case 49: /* binary: unary  */
#line 144 "subc.y"
                   { printf("binary->unary\n"); }
#line 1521 "subc.tab.c"
    break;

  case 50: /* binary: binary LOGICAL_AND binary  */
#line 145 "subc.y"
                             { printf("binary->binary LOGICAL_AND binary\n"); }
#line 1527 "subc.tab.c"
    break;

  case 51: /* binary: binary LOGICAL_OR binary  */
#line 146 "subc.y"
                            { printf("binary->binary LOGICAL_OR binary\n"); }
#line 1533 "subc.tab.c"
    break;

  case 52: /* unary: '(' expr ')'  */
#line 150 "subc.y"
                { printf("unary->'(' expr ')'\n"); }
#line 1539 "subc.tab.c"
    break;

  case 53: /* unary: INTEGER_CONST  */
#line 151 "subc.y"
                 { printf("unary->INTEGER_CONST\n"); }
#line 1545 "subc.tab.c"
    break;

  case 54: /* unary: CHAR_CONST  */
#line 152 "subc.y"
              { printf("unary->CHAR_CONST\n"); }
#line 1551 "subc.tab.c"
    break;

  case 55: /* unary: STRING  */
#line 153 "subc.y"
          { printf("unary->STRING\n"); }
#line 1557 "subc.tab.c"
    break;

  case 56: /* unary: ID  */
#line 154 "subc.y"
      { printf("unary->ID\n"); }
#line 1563 "subc.tab.c"
    break;

  case 57: /* unary: '-' unary  */
#line 155 "subc.y"
                          { printf("unary->'-' unary\n"); }
#line 1569 "subc.tab.c"
    break;

  case 58: /* unary: '!' unary  */
#line 156 "subc.y"
             { printf("unary->'!' unary\n"); }
#line 1575 "subc.tab.c"
    break;

  case 59: /* unary: unary INCOP  */
#line 157 "subc.y"
                              { printf("unary->unary INCOP\n"); }
#line 1581 "subc.tab.c"
    break;

  case 60: /* unary: unary DECOP  */
#line 158 "subc.y"
                              { printf("unary->unary DECOP\n"); }
#line 1587 "subc.tab.c"
    break;

  case 61: /* unary: INCOP unary  */
#line 159 "subc.y"
                            { printf("unary->INCOP unary\n"); }
#line 1593 "subc.tab.c"
    break;

  case 62: /* unary: DECOP unary  */
#line 160 "subc.y"
                            { printf("unary->DECOP unary\n"); }
#line 1599 "subc.tab.c"
    break;

  case 63: /* unary: '&' unary  */
#line 161 "subc.y"
             { printf("unary->'&' unary\n"); }
#line 1605 "subc.tab.c"
    break;

  case 64: /* unary: '*' unary  */
#line 162 "subc.y"
                         { printf("unary->'*' unary\n"); }
#line 1611 "subc.tab.c"
    break;

  case 65: /* unary: unary '[' expr ']'  */
#line 163 "subc.y"
                      { printf("unary->unary '[' expr ']'\n"); }
#line 1617 "subc.tab.c"
    break;

  case 66: /* unary: unary '.' ID  */
#line 164 "subc.y"
                { printf("unary->unary '.' ID\n"); }
#line 1623 "subc.tab.c"
    break;

  case 67: /* unary: unary STRUCTOP ID  */
#line 165 "subc.y"
                     { printf("unary->unary STRUCTOP ID\n"); }
#line 1629 "subc.tab.c"
    break;

  case 68: /* unary: unary '(' args ')'  */
#line 166 "subc.y"
                      { printf("unary->unary '(' args ')'\n"); }
#line 1635 "subc.tab.c"
    break;

  case 69: /* unary: unary '(' ')'  */
#line 167 "subc.y"
                 { printf("unary->unary '(' ')'\n"); }
#line 1641 "subc.tab.c"
    break;

  case 70: /* unary: SYM_NULL  */
#line 168 "subc.y"
            { printf("unary->SYM_NULL\n"); }
#line 1647 "subc.tab.c"
    break;

  case 71: /* args: expr  */
#line 172 "subc.y"
        { printf("args->expr\n"); }
#line 1653 "subc.tab.c"
    break;

  case 72: /* args: args ',' expr  */
#line 173 "subc.y"
                 { printf("args->args ',' expr\n"); }
#line 1659 "subc.tab.c"
    break;


#line 1663 "subc.tab.c"

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

#line 174 "subc.y"


/* Epilogue section */

int yyerror (char* s) {
  fprintf (stderr, "yyerror: %s\n", s);
}

void reduce(char* s) {
  printf("%s\n", s);
}
