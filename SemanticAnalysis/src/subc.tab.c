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
#line 6 "subc.y"


/* Prologue section */

#include "subc.h"

int   yylex ();
void   yyerror (char* s);
int   get_lineno();
void error_redeclaration(void);
void error_undeclared(void);
void error_incompatible(void);
void error_assignable(void);
void error_indirection(void);
void error_struct(void);
void error_strurctp(void);
void error_member(void);
void error_array(void);
void error_subscript(void);
void error_incomplete(void);
void error_return(void);
void error_comparable(void);
void error_binary(void);
void error_unary(void);
void error_arguments(void);
void error_function(void);
void error_null(void);
void error_addressof(void);


#line 102 "subc.tab.c"

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
  YYSYMBOL_LOGICAL_OR = 5,                 /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_AND = 6,                /* LOGICAL_AND  */
  YYSYMBOL_EQUOP = 7,                      /* EQUOP  */
  YYSYMBOL_RELOP = 8,                      /* RELOP  */
  YYSYMBOL_9_ = 9,                         /* '+'  */
  YYSYMBOL_10_ = 10,                       /* '-'  */
  YYSYMBOL_11_ = 11,                       /* '*'  */
  YYSYMBOL_12_ = 12,                       /* '/'  */
  YYSYMBOL_13_ = 13,                       /* '%'  */
  YYSYMBOL_14_ = 14,                       /* '!'  */
  YYSYMBOL_15_ = 15,                       /* '&'  */
  YYSYMBOL_INCOP = 16,                     /* INCOP  */
  YYSYMBOL_DECOP = 17,                     /* DECOP  */
  YYSYMBOL_18_ = 18,                       /* '['  */
  YYSYMBOL_19_ = 19,                       /* ']'  */
  YYSYMBOL_20_ = 20,                       /* '('  */
  YYSYMBOL_21_ = 21,                       /* ')'  */
  YYSYMBOL_22_ = 22,                       /* '.'  */
  YYSYMBOL_STRUCTOP = 23,                  /* STRUCTOP  */
  YYSYMBOL_IF = 24,                        /* IF  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_STRUCT = 26,                    /* STRUCT  */
  YYSYMBOL_RETURN = 27,                    /* RETURN  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_FOR = 29,                       /* FOR  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 31,                  /* CONTINUE  */
  YYSYMBOL_SYM_NULL = 32,                  /* SYM_NULL  */
  YYSYMBOL_TYPE = 33,                      /* TYPE  */
  YYSYMBOL_CHAR_CONST = 34,                /* CHAR_CONST  */
  YYSYMBOL_STRING = 35,                    /* STRING  */
  YYSYMBOL_INTEGER_CONST = 36,             /* INTEGER_CONST  */
  YYSYMBOL_ID = 37,                        /* ID  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_ext_def_list = 43,              /* ext_def_list  */
  YYSYMBOL_ext_def = 44,                   /* ext_def  */
  YYSYMBOL_type_specifier = 45,            /* type_specifier  */
  YYSYMBOL_struct_specifier = 46,          /* struct_specifier  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_48_2 = 48,                      /* $@2  */
  YYSYMBOL_func_decl = 49,                 /* func_decl  */
  YYSYMBOL_pointers = 50,                  /* pointers  */
  YYSYMBOL_param_list = 51,                /* param_list  */
  YYSYMBOL_param_decl = 52,                /* param_decl  */
  YYSYMBOL_def_list = 53,                  /* def_list  */
  YYSYMBOL_def = 54,                       /* def  */
  YYSYMBOL_compound_stmt = 55,             /* compound_stmt  */
  YYSYMBOL_56_3 = 56,                      /* $@3  */
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
#define YYLAST   229

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


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
       2,     2,     2,    14,     2,     2,     2,    13,    15,     2,
      20,    21,    11,     9,     3,    10,    22,    12,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,     4,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    18,     2,    19,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     5,     6,
       7,     8,    16,    17,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    91,    92,    96,   113,   139,   140,   144,
     164,   168,   172,   168,   196,   222,   250,   284,   294,   301,
     304,   315,   336,   365,   366,   370,   388,   417,   417,   440,
     441,   445,   446,   455,   456,   457,   458,   459,   460,   461,
     462,   466,   467,   473,   491,   497,   512,   527,   537,   547,
     557,   567,   577,   580,   595,   609,   613,   617,   627,   637,
     653,   684,   691,   698,   712,   727,   744,   762,   788,   811,
     826,   850,   874,   896,   923,   936,   947
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
  "\"end of file\"", "error", "\"invalid token\"", "','", "'='",
  "LOGICAL_OR", "LOGICAL_AND", "EQUOP", "RELOP", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "'&'", "INCOP", "DECOP", "'['", "']'", "'('", "')'",
  "'.'", "STRUCTOP", "IF", "ELSE", "STRUCT", "RETURN", "WHILE", "FOR",
  "BREAK", "CONTINUE", "SYM_NULL", "TYPE", "CHAR_CONST", "STRING",
  "INTEGER_CONST", "ID", "';'", "'{'", "'}'", "$accept", "program",
  "ext_def_list", "ext_def", "type_specifier", "struct_specifier", "$@1",
  "$@2", "func_decl", "pointers", "param_list", "param_decl", "def_list",
  "def", "compound_stmt", "$@3", "stmt_list", "stmt", "expr_e", "expr",
  "binary", "unary", "args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-128)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-12)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -128,     4,    14,  -128,   -31,  -128,  -128,    17,   -23,    26,
      39,  -128,     2,  -128,  -128,  -128,    69,    -2,  -128,  -128,
       1,    88,  -128,    14,  -128,    71,  -128,    17,  -128,     0,
    -128,    17,  -128,    65,    51,    77,    80,    14,  -128,    81,
     126,   126,   126,   126,   126,   126,   126,    99,   126,   102,
     109,   101,   106,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,   107,   159,   134,  -128,  -128,   129,  -128,   -11,
     175,   175,   175,   175,   175,   175,   127,    46,   126,   111,
     126,   126,  -128,  -128,  -128,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,  -128,  -128,   126,     9,   116,
     118,   123,   137,  -128,  -128,  -128,   173,  -128,   196,   158,
    -128,   177,   175,   192,   198,   203,    61,    61,  -128,  -128,
    -128,  -128,   199,  -128,  -128,    28,  -128,  -128,   200,   201,
      96,    96,   126,  -128,   126,  -128,  -128,   183,   197,  -128,
     185,  -128,  -128,    96,   126,  -128,   204,    96,  -128
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     9,     3,    18,    10,     0,
      14,    17,     0,     7,    27,     8,     0,     0,    24,    12,
       0,     0,     5,    30,    24,     0,    15,    18,    10,     0,
      19,    18,    23,     0,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    58,    59,    57,    60,    35,    28,
      36,    29,     0,    44,    52,    13,     6,    21,    20,     0,
      61,    68,    62,    67,    65,    66,     0,    52,     0,     0,
       0,    42,    33,    34,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,     0,     0,     0,
       0,     0,     0,    25,    55,    56,     0,    32,     0,     0,
      41,    54,    52,    53,    46,    45,    47,    48,    49,    50,
      51,    43,     0,    73,    75,     0,    70,    71,     0,     0,
       0,     0,    42,    69,     0,    72,    22,     0,    37,    39,
       0,    76,    26,     0,    42,    38,     0,     0,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,  -128,    -1,   222,  -128,  -128,  -128,    11,
    -128,   189,   205,  -128,   218,  -128,  -128,   -60,  -127,   -46,
      89,   -32,  -128
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,    27,    28,    16,    24,     9,    12,
      29,    30,    23,    32,    60,    18,    33,    61,   109,    62,
      63,    64,   125
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,     7,    79,    37,     3,   140,    10,   102,    70,    71,
      72,    73,    74,    75,    77,    13,    20,   146,    21,    40,
      41,    38,    31,    42,    43,    44,    45,   103,    11,    46,
     123,   134,   106,    31,   108,   110,    22,    25,    36,    17,
       4,    53,    39,    54,    55,    56,    57,     5,   121,   135,
      94,   122,   124,   112,   112,   112,   112,   112,   112,   112,
     112,   112,    95,    96,    97,    14,    98,   105,    99,   100,
     138,   139,    91,    92,    93,    40,    41,     4,   -11,    42,
      43,    44,    45,   145,     5,    46,   110,   148,   141,    47,
      35,    65,    48,    49,    50,    51,    52,    53,   110,    54,
      55,    56,    57,    58,    14,    59,    40,    41,    19,    26,
      42,    43,    44,    45,     4,    66,    46,    67,    69,    78,
      47,     5,    80,    48,    49,    50,    51,    52,    53,    81,
      54,    55,    56,    57,    58,    14,    40,    41,    94,    82,
      42,    43,    44,    45,    83,    84,    46,   101,   104,   107,
      95,    96,    97,   126,    98,   127,    99,   100,    53,   128,
      54,    55,    56,    57,    85,    86,    87,    88,    89,    90,
      91,    92,    93,   129,   111,   113,   114,   115,   116,   117,
     118,   119,   120,    86,    87,    88,    89,    90,    91,    92,
      93,    95,    96,    97,   130,    98,   132,    99,   100,    87,
      88,    89,    90,    91,    92,    93,    88,    89,    90,    91,
      92,    93,    89,    90,    91,    92,    93,   131,   133,   136,
     137,   142,   143,   144,     8,   147,    68,    15,     0,    34
};

static const yytype_int16 yycheck[] =
{
      46,     2,    48,     3,     0,   132,    37,    18,    40,    41,
      42,    43,    44,    45,    46,    38,    18,   144,    20,    10,
      11,    21,    23,    14,    15,    16,    17,    38,    11,    20,
      21,     3,    78,    34,    80,    81,    38,    36,    27,    37,
      26,    32,    31,    34,    35,    36,    37,    33,    94,    21,
       4,    97,    98,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    16,    17,    18,    39,    20,    21,    22,    23,
     130,   131,    11,    12,    13,    10,    11,    26,    39,    14,
      15,    16,    17,   143,    33,    20,   132,   147,   134,    24,
      19,    40,    27,    28,    29,    30,    31,    32,   144,    34,
      35,    36,    37,    38,    39,    40,    10,    11,    39,    21,
      14,    15,    16,    17,    26,    38,    20,    37,    37,    20,
      24,    33,    20,    27,    28,    29,    30,    31,    32,    20,
      34,    35,    36,    37,    38,    39,    10,    11,     4,    38,
      14,    15,    16,    17,    38,    38,    20,    18,    21,    38,
      16,    17,    18,    37,    20,    37,    22,    23,    32,    36,
      34,    35,    36,    37,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    36,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     6,     7,     8,     9,    10,    11,    12,
      13,    16,    17,    18,    21,    20,    38,    22,    23,     7,
       8,     9,    10,    11,    12,    13,     8,     9,    10,    11,
      12,    13,     9,    10,    11,    12,    13,    21,    19,    19,
      19,    38,    25,    38,     2,    21,    37,     9,    -1,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    43,     0,    26,    33,    44,    45,    46,    49,
      37,    11,    50,    38,    39,    55,    47,    37,    56,    39,
      18,    20,    38,    53,    48,    36,    21,    45,    46,    51,
      52,    45,    54,    57,    53,    19,    50,     3,    21,    50,
      10,    11,    14,    15,    16,    17,    20,    24,    27,    28,
      29,    30,    31,    32,    34,    35,    36,    37,    38,    40,
      55,    58,    60,    61,    62,    40,    38,    37,    52,    37,
      62,    62,    62,    62,    62,    62,    60,    62,    20,    60,
      20,    20,    38,    38,    38,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     4,    16,    17,    18,    20,    22,
      23,    18,    18,    38,    21,    21,    60,    38,    60,    59,
      60,    61,    62,    61,    61,    61,    61,    61,    61,    61,
      61,    60,    60,    21,    60,    63,    37,    37,    36,    36,
      21,    21,    38,    19,     3,    21,    19,    19,    58,    58,
      59,    60,    38,    25,    38,    58,    59,    21,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    45,
      45,    47,    48,    46,    46,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    56,    55,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     7,     2,     2,     1,
       1,     0,     0,     7,     2,     5,     6,     1,     0,     1,
       3,     3,     6,     2,     0,     4,     7,     0,     5,     2,
       0,     2,     3,     2,     2,     1,     1,     5,     7,     5,
       9,     1,     0,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     4,
       3,     3,     4,     3,     1,     1,     3
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
  case 5: /* ext_def: type_specifier pointers ID ';'  */
#line 96 "subc.y"
                                   { 
    /* 전역 변수 선언 규칙 */

    /* 1. 기본 타입(type_specifier)에 포인터(pointers)를 연결해 최종 타입 생성 */
    TypeInfo* final_type = (yyvsp[-3].typeInfo);
    if((yyvsp[-2].typeInfo) != NULL) {
      (yyvsp[-2].typeInfo)->next = (yyvsp[-3].typeInfo);
      final_type = (yyvsp[-2].typeInfo);
    }
    
    /* 2. 타입 체크 및 심볼 테이블에 변수 추가 */
    if(final_type == NULL) {
      error_incomplete(); /* 불완전한 타입 에러 */
    } else if (!insert_symbol((yyvsp[-1].stringVal), final_type)) {
      error_redeclaration(); /* 변수 재선언 에러 */
    }
  }
#line 1275 "subc.tab.c"
    break;

  case 6: /* ext_def: type_specifier pointers ID '[' INTEGER_CONST ']' ';'  */
#line 113 "subc.y"
                                                         {
    TypeInfo *base_type = (yyvsp[-6].typeInfo); /* 배열 타입의 경우, 배열의 기본 타입을 저장 */
    
    // 포인터 타입이 있는 경우, 포인터 타입을 추가함.
    if((yyvsp[-5].typeInfo) != NULL) {
      (yyvsp[-5].typeInfo)->next = (yyvsp[-6].typeInfo);
      base_type = (yyvsp[-5].typeInfo);
    }

    // 배열 타입 생성
    TypeInfo *array_type = malloc(sizeof(TypeInfo));
    array_type->type = TYPE_ARRAY; // 배열 타입으로 설정
    array_type->next = base_type; // 배열 타입을 설정 (배열의 기본 타입을 저장 ex_int, char 등)

    // 배열 타입의 경우, lvalue가 아님.
    array_type->is_lvalue = 0;
    array_type->struct_name = NULL;
    array_type->array_size = (yyvsp[-2].intVal); // INTEGER_CONST를 통해서 배열의 크기를 저장
    array_type->field_list = NULL;

    // 심볼 테이블에 배열 타입 추가
    if(!insert_symbol((yyvsp[-4].stringVal), array_type)) {
      // 변수를 재선언함 에러 발생
      error_redeclaration();
    }
  }
#line 1306 "subc.tab.c"
    break;

  case 9: /* type_specifier: TYPE  */
#line 144 "subc.y"
         {
    /* 타입 정보 생성 */
    /* 만약 int 또는 char가 들어오면 해당 타입을 나타내는 TypeInfo를 생성해 반환 */
    (yyval.typeInfo) = malloc(sizeof(TypeInfo));
    /* 타입 정보 초기화 */
    
    if (strcmp((yyvsp[0].stringVal), "int") == 0) { // int 타입 처리
      (yyval.typeInfo)->type = TYPE_INT;
    } else if (strcmp((yyvsp[0].stringVal), "char") == 0) { // 문자 타입 처리
      (yyval.typeInfo)->type = TYPE_CHAR;
    } else { // 기본 타입이 아닌 경우, int로 설정
      (yyval.typeInfo)->type = TYPE_INT; 
    }
    // 타입 정보 초기화
    (yyval.typeInfo)->next = NULL;
    (yyval.typeInfo)->struct_name = NULL;
    (yyval.typeInfo)->array_size = 0;
    (yyval.typeInfo)->is_lvalue = 0;
    (yyval.typeInfo)->field_list = NULL;
  }
#line 1331 "subc.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 168 "subc.y"
              {
    // error_lineno을 통해서 오류 발생 위치를 저장
    error_lineno = get_lineno();
  }
#line 1340 "subc.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 172 "subc.y"
      {
    // 스코프 추가
    push_scope();
  }
#line 1349 "subc.tab.c"
    break;

  case 13: /* struct_specifier: STRUCT ID $@1 '{' $@2 def_list '}'  */
#line 175 "subc.y"
                 {
    // 구조체 재선언 체크
    if(is_redelcare_struct((yyvsp[-5].stringVal))) {
      error_redeclaration();
      (yyval.typeInfo) = NULL;
    } else {
      // 구조체 타입 생성
      (yyval.typeInfo) = malloc(sizeof(TypeInfo));
      (yyval.typeInfo)->type = TYPE_STRUCT;
      (yyval.typeInfo)->struct_name = strdup((yyvsp[-5].stringVal));
      (yyval.typeInfo)->next = NULL;
      (yyval.typeInfo)->array_size = 0;
      (yyval.typeInfo)->is_lvalue = 0;
      /* 스코프 내의 모든 심볼들을 fieldInfo 리스트로 변환 */
      (yyval.typeInfo)->field_list = convert_scope_to_field_list();
      /* 전역 구조체 리스트에 추가(구조체 이름을 키로 사용하여 구조체 정보를 저장) */
      register_struct_type((yyvsp[-5].stringVal), (yyval.typeInfo)->field_list);
    }
    /* 스코프 종료 */
    pop_scope();
  }
#line 1375 "subc.tab.c"
    break;

  case 14: /* struct_specifier: STRUCT ID  */
#line 196 "subc.y"
              {
    /* 단순한 구조체 선언( struct S; 와 같은 경우) */
    StructType *current = global_type_list;
    
    while(current != NULL) {
      if(strcmp(current->name, (yyvsp[0].stringVal)) == 0) {
        (yyval.typeInfo) = malloc(sizeof(TypeInfo));
        (yyval.typeInfo)->type = TYPE_STRUCT;
        (yyval.typeInfo)->struct_name = strdup((yyvsp[0].stringVal));
        (yyval.typeInfo)->next = NULL;
        (yyval.typeInfo)->array_size = 0;
        (yyval.typeInfo)->is_lvalue = 0;
        (yyval.typeInfo)->field_list = current->field_list;
        break;
      }
      current = current->next;
    }
    
    if (current == NULL) {
      error_undeclared();
      (yyval.typeInfo) = NULL;
    }
  }
#line 1403 "subc.tab.c"
    break;

  case 15: /* func_decl: type_specifier pointers ID '(' ')'  */
#line 222 "subc.y"
                                       {
    // 함수 선언 규칙
    TypeInfo* final_type = (yyvsp[-4].typeInfo);
    
    // pointer가 있으면 pointer 타입을 추가함.
    if((yyvsp[-3].typeInfo) != NULL) {
      (yyvsp[-3].typeInfo)->next = (yyvsp[-4].typeInfo);
      final_type = (yyvsp[-3].typeInfo);
    }

    // 함수 반환 타입 설정
    current_function_return_type = final_type;

    // 함수 선언 체크
    if(!insert_symbol((yyvsp[-2].stringVal), final_type)) { // 함수가 선언이 가능한지를 체크
      // 함수가 이미 선언되어 있는 경우 에러 발생
      error_redeclaration();
      (yyval.typeInfo) = NULL;
    } else if(is_func_declared((yyvsp[-2].stringVal))) { // 함수 재선언 체크
      // 함수가 이미 선언되어 있는 경우 에러 발생
      error_redeclaration();
      (yyval.typeInfo) = NULL;
    } else { // 함수 선언 추가
      // 함수 추가
      insert_func_info((yyvsp[-2].stringVal), final_type, NULL);
      (yyval.typeInfo) = NULL;
    }
  }
#line 1436 "subc.tab.c"
    break;

  case 16: /* func_decl: type_specifier pointers ID '(' param_list ')'  */
#line 250 "subc.y"
                                                  {
    // 함수 선언 규칙
    TypeInfo* final_type = (yyvsp[-5].typeInfo);
    
    // pointer가 있으면 pointer 타입을 추가함.
    if ((yyvsp[-4].typeInfo) != NULL) {
      (yyvsp[-4].typeInfo)->next = (yyvsp[-5].typeInfo);
      final_type = (yyvsp[-4].typeInfo);
    }

    // 함수 반환 타입 설정
    current_function_return_type = final_type;

    // 함수 파라미터 리스트 설정
    current_param_list = (yyvsp[-1].paramList);

    // 함수 선언 체크
    if (is_func_declared((yyvsp[-3].stringVal))) { // 함수 재선언 체크
      // 함수가 이미 선언되어 있는 경우 에러 발생
      error_redeclaration();
      (yyval.typeInfo) = NULL;
    } else {
      // 함수 추가
      insert_func_info((yyvsp[-3].stringVal), final_type, (yyvsp[-1].paramList));
      if (!insert_symbol((yyvsp[-3].stringVal), final_type)) { // 함수가 선언이 가능한지를 체크
        // 함수가 이미 선언되어 있는 경우 에러 발생
        error_redeclaration();
      }
      (yyval.typeInfo) = NULL;
    }
  }
#line 1472 "subc.tab.c"
    break;

  case 17: /* pointers: '*'  */
#line 284 "subc.y"
        {
    // 포인터 타입 생성
    (yyval.typeInfo) = malloc(sizeof(TypeInfo));
    (yyval.typeInfo)->type = TYPE_POINTER;
    (yyval.typeInfo)->next = NULL;
    (yyval.typeInfo)->is_lvalue = 0;
    (yyval.typeInfo)->struct_name = NULL;
    (yyval.typeInfo)->array_size = 0;
    (yyval.typeInfo)->field_list = NULL;
  }
#line 1487 "subc.tab.c"
    break;

  case 18: /* pointers: %empty  */
#line 294 "subc.y"
           {
    // 파라미터 리스트가 없는 경우 에러 발생
    (yyval.typeInfo) = NULL;
  }
#line 1496 "subc.tab.c"
    break;

  case 19: /* param_list: param_decl  */
#line 301 "subc.y"
               {
    (yyval.paramList) = (yyvsp[0].paramList);
  }
#line 1504 "subc.tab.c"
    break;

  case 20: /* param_list: param_list ',' param_decl  */
#line 304 "subc.y"
                              {
    // 파라미터 리스트가 있는 경우 파라미터 추가
    if ((yyvsp[-2].paramList) != NULL && (yyvsp[0].paramList) != NULL) {
      (yyvsp[-2].paramList)->tail->next = (yyvsp[0].paramList)->head;
      (yyvsp[-2].paramList)->tail = (yyvsp[0].paramList)->tail;
    }
    (yyval.paramList) = (yyvsp[-2].paramList);
  }
#line 1517 "subc.tab.c"
    break;

  case 21: /* param_decl: type_specifier pointers ID  */
#line 315 "subc.y"
                               {
    // 파라미터 타입 설정
    if ((yyvsp[-2].typeInfo) == NULL) {
      error_incomplete();
      (yyval.paramList) = NULL;
    } else {
      // 파라미터 타입 설정
      TypeInfo* final_type = (yyvsp[-2].typeInfo);
      if ((yyvsp[-1].typeInfo) != NULL) { // 포인터가 있는 경우
        // 포인터 타입을 추가함
        (yyvsp[-1].typeInfo)->next = (yyvsp[-2].typeInfo); /* POINTER -> INT 로 연결하는 부분 */
        final_type = (yyvsp[-1].typeInfo); // $2는 포인터 타입임. 따라서 포인터 타입을 추가함
      }
      (yyval.paramList) = create_param_list(); // 파라미터 리스트 생성
      if(!add_param((yyval.paramList), (yyvsp[0].stringVal), final_type)) {
        // 파라미터 추가 에러 발생
        error_redeclaration();
        (yyval.paramList) = NULL;
      }
    }
  }
#line 1543 "subc.tab.c"
    break;

  case 22: /* param_decl: type_specifier pointers ID '[' INTEGER_CONST ']'  */
#line 336 "subc.y"
                                                     {
    if ((yyvsp[-5].typeInfo) == NULL) {
      error_incomplete();
      (yyval.paramList) = NULL;
    } else {
      // 기존 타입을 deep_copy
      TypeInfo* base_type = deep_copy_typeinfo((yyvsp[-5].typeInfo));

      // 배열 타입 생성
      TypeInfo* array_type = malloc(sizeof(TypeInfo));
      array_type->type = TYPE_ARRAY;
      array_type->array_size = (yyvsp[-1].intVal);
      array_type->next = base_type;
      array_type->is_lvalue = 0;
      array_type->struct_name = NULL;
      array_type->field_list = NULL;

      // 파라미터 리스트 생성
      (yyval.paramList) = create_param_list();
      // 파라미터 추가
      if (!add_param((yyval.paramList), (yyvsp[-3].stringVal), array_type)) {
        error_redeclaration();
        (yyval.paramList) = NULL;
      }
    }
  }
#line 1574 "subc.tab.c"
    break;

  case 25: /* def: type_specifier pointers ID ';'  */
#line 370 "subc.y"
                                   {
    // 변수 선언 규칙
    TypeInfo* final_type = (yyvsp[-3].typeInfo);

    // pointer가 있으면 pointer 타입을 추가함.
    if((yyvsp[-2].typeInfo) != NULL) {
      (yyvsp[-2].typeInfo)->next = (yyvsp[-3].typeInfo);
      final_type = (yyvsp[-2].typeInfo);
    }
    
    // 변수 선언 체크
    if(final_type == NULL) { // 타입 정보가 없는 경우 에러 발생
      error_incomplete();
    } else if (!insert_symbol((yyvsp[-1].stringVal), final_type)) { // 변수 선언 체크
      // 변수가 이미 선언되어 있는 경우 에러 발생
      error_redeclaration();
    }
  }
#line 1597 "subc.tab.c"
    break;

  case 26: /* def: type_specifier pointers ID '[' INTEGER_CONST ']' ';'  */
#line 388 "subc.y"
                                                         {
    // 배열 선언 규칙
    TypeInfo* base_type = (yyvsp[-6].typeInfo);

    // pointer가 있으면 pointer 타입을 추가함.
    if ((yyvsp[-5].typeInfo) != NULL) {
        (yyvsp[-5].typeInfo)->next = (yyvsp[-6].typeInfo);
        base_type = (yyvsp[-5].typeInfo);
    }

    // 배열 타입 생성
    TypeInfo* array_type = malloc(sizeof(TypeInfo));
    // 배열 타입 설정
    array_type->type = TYPE_ARRAY;
    array_type->array_size = (yyvsp[-2].intVal); // 배열 크기 설정
    array_type->next = base_type; // 배열 타입을 설정 (기본 타입을 저장)
    array_type->is_lvalue = 0; // 배열 타입은 lvalue가 아님
    array_type->struct_name = NULL;
    array_type->field_list = NULL;

    // 배열 타입 선언 체크
    if (!insert_symbol((yyvsp[-4].stringVal), array_type)) {
      // 배열 타입이 이미 선언되어 있는 경우 에러 발생
      error_redeclaration();
    }
  }
#line 1628 "subc.tab.c"
    break;

  case 27: /* $@3: %empty  */
#line 417 "subc.y"
        {
    // 스코프 추가
    push_scope();
    // 파라미터 리스트가 있는 경우 파라미터 추가
    if (current_param_list != NULL) {
      // 파라미터 리스트를 순회하며 파라미터 추가
        ParamNode* cur = current_param_list->head;
        while (cur != NULL) {
          if (!insert_symbol(cur->name, cur->type)) {
            // 파라미터가 이미 선언되어 있는 경우 에러 발생
            error_redeclaration();
          }
          cur = cur->next;
        }
        current_param_list = NULL; // 파라미터 리스트 초기화
      }
  }
#line 1650 "subc.tab.c"
    break;

  case 28: /* compound_stmt: '{' $@3 def_list stmt_list '}'  */
#line 433 "subc.y"
                           {
    // 스코프 종료
    pop_scope();
  }
#line 1659 "subc.tab.c"
    break;

  case 32: /* stmt: RETURN expr ';'  */
#line 446 "subc.y"
                    {
    // 반환 타입 체크
    if ((yyvsp[-1].typeInfo) != NULL && current_function_return_type != NULL) {
        if (!is_same_type((yyvsp[-1].typeInfo), current_function_return_type)) {
            // 반환 타입이 일치하지 않는 경우 에러 발생
            error_return();
        }
    }
  }
#line 1673 "subc.tab.c"
    break;

  case 42: /* expr_e: %empty  */
#line 467 "subc.y"
           {
    (yyval.typeInfo) = NULL;
  }
#line 1681 "subc.tab.c"
    break;

  case 43: /* expr: unary '=' expr  */
#line 473 "subc.y"
                   { /* 대입문을 분석할 때, 왼쪽과 오른쪽의 타입 검사 및 할당 가능한지를 체크하는 부분
  만약 a가 선언되지 않았는데, lookup_symbol()을 통해 타입을 찾으려고 하면, 에러가 발생함.
  따라서 이를 통해서 둘 중 하나라도 문제가 있는 경우에는 NULL을 반환하게 한다. */
    if ((yyvsp[-2].typeInfo) == NULL || (yyvsp[0].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.typeInfo) = NULL;
    } else if(!is_lvalue((yyvsp[-2].typeInfo))) { // 왼쪽 피연산자가 lvalue가 아닌 경우
      error_assignable(); /* 할당이 불가능 함 */
      (yyval.typeInfo) = NULL;
    } else if((yyvsp[0].typeInfo)->type == TYPE_NULLPTR && (yyvsp[-2].typeInfo)->type != TYPE_POINTER) { // 오른쪽 피연산자가 NULL인 경우
      error_null();
      (yyval.typeInfo) = NULL;
    } else if(!is_same_type((yyvsp[-2].typeInfo), (yyvsp[0].typeInfo))) { // 피연산자 타입이 일치하지 않는 경우
      error_incompatible();
      (yyval.typeInfo) = NULL;
    } else { // 정상적인 경우
      (yyval.typeInfo) = (yyvsp[-2].typeInfo);
    }
  }
#line 1704 "subc.tab.c"
    break;

  case 44: /* expr: binary  */
#line 491 "subc.y"
           {
    (yyval.typeInfo) = (yyvsp[0].typeInfo); /* binary의 결과를 그대로 넘김 */
  }
#line 1712 "subc.tab.c"
    break;

  case 45: /* binary: binary RELOP binary  */
#line 497 "subc.y"
                        {
    if ((yyvsp[-2].typeInfo) == NULL || (yyvsp[0].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.typeInfo) = NULL;
    } else if (!is_comparable_type((yyvsp[-2].typeInfo), (yyvsp[0].typeInfo))) { // 피연산자 타입이 비교 가능한 타입이 아닌 경우
      error_comparable();
      (yyval.typeInfo) = NULL;
    } else {
      (yyval.typeInfo) = malloc(sizeof(TypeInfo));
      (yyval.typeInfo)->type = TYPE_INT;
      (yyval.typeInfo)->is_lvalue = 0;
      (yyval.typeInfo)->next = NULL;
      (yyval.typeInfo)->struct_name = NULL;
      (yyval.typeInfo)->array_size = 0;
    }
  }
#line 1732 "subc.tab.c"
    break;

  case 46: /* binary: binary EQUOP binary  */
#line 512 "subc.y"
                        {
    if ((yyvsp[-2].typeInfo) == NULL || (yyvsp[0].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.typeInfo) = NULL;
    } else if (!is_comparable_type((yyvsp[-2].typeInfo), (yyvsp[0].typeInfo))) { // 피연산자 타입이 비교 가능한 타입이 아닌 경우
      error_comparable();
      (yyval.typeInfo) = NULL;
    } else {
      (yyval.typeInfo) = malloc(sizeof(TypeInfo));
      (yyval.typeInfo)->type = TYPE_INT;
      (yyval.typeInfo)->is_lvalue = 0;
      (yyval.typeInfo)->next = NULL;
      (yyval.typeInfo)->struct_name = NULL;
      (yyval.typeInfo)->array_size = 0;
    }
  }
#line 1752 "subc.tab.c"
    break;

  case 47: /* binary: binary '+' binary  */
#line 527 "subc.y"
                      {
    if ((yyvsp[-2].typeInfo) == NULL || (yyvsp[0].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.typeInfo) = NULL;
    } else if(!is_arithmetic_type((yyvsp[-2].typeInfo)) || !is_arithmetic_type((yyvsp[0].typeInfo))) { // 피연산자 타입이 산술 타입이 아닌 경우
      error_binary();
      (yyval.typeInfo) = NULL;
    } else {
      (yyval.typeInfo) = deep_copy_typeinfo((yyvsp[-2].typeInfo));
    }
  }
#line 1767 "subc.tab.c"
    break;

  case 48: /* binary: binary '-' binary  */
#line 537 "subc.y"
                       {
    if ((yyvsp[-2].typeInfo) == NULL || (yyvsp[0].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.typeInfo) = NULL;
    } else if(!is_arithmetic_type((yyvsp[-2].typeInfo)) || !is_arithmetic_type((yyvsp[0].typeInfo))) { // 피연산자 타입이 산술 타입이 아닌 경우
      error_binary();
      (yyval.typeInfo) = NULL;
    } else {
      (yyval.typeInfo) = deep_copy_typeinfo((yyvsp[-2].typeInfo));
    }
  }
#line 1782 "subc.tab.c"
    break;

  case 49: /* binary: binary '*' binary  */
#line 547 "subc.y"
                      {
    if ((yyvsp[-2].typeInfo) == NULL || (yyvsp[0].typeInfo) == NULL) {
      (yyval.typeInfo) = NULL;
    } else if(!is_arithmetic_type((yyvsp[-2].typeInfo)) || !is_arithmetic_type((yyvsp[0].typeInfo))) {
      error_binary();
      (yyval.typeInfo) = NULL;
    } else {
      (yyval.typeInfo) = deep_copy_typeinfo((yyvsp[-2].typeInfo));
    }
  }
#line 1797 "subc.tab.c"
    break;

  case 50: /* binary: binary '/' binary  */
#line 557 "subc.y"
                      {
    if ((yyvsp[-2].typeInfo) == NULL || (yyvsp[0].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.typeInfo) = NULL;
    } else if(!is_arithmetic_type((yyvsp[-2].typeInfo)) || !is_arithmetic_type((yyvsp[0].typeInfo))) { // 피연산자 타입이 산술 타입이 아닌 경우
      error_binary();
      (yyval.typeInfo) = NULL;
    } else {
      (yyval.typeInfo) = deep_copy_typeinfo((yyvsp[-2].typeInfo));
    }
  }
#line 1812 "subc.tab.c"
    break;

  case 51: /* binary: binary '%' binary  */
#line 567 "subc.y"
                      {
    if ((yyvsp[-2].typeInfo) == NULL || (yyvsp[0].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.typeInfo) = NULL;
    } else if(!is_arithmetic_type((yyvsp[-2].typeInfo)) || !is_arithmetic_type((yyvsp[0].typeInfo))) { // 피연산자 타입이 산술 타입이 아닌 경우
      error_binary();
      (yyval.typeInfo) = NULL;
    } else {
      (yyval.typeInfo) = deep_copy_typeinfo((yyvsp[-2].typeInfo));
    }
  }
#line 1827 "subc.tab.c"
    break;

  case 52: /* binary: unary  */
#line 577 "subc.y"
                    {
    (yyval.typeInfo) = (yyvsp[0].typeInfo);
  }
#line 1835 "subc.tab.c"
    break;

  case 53: /* binary: binary LOGICAL_AND binary  */
#line 580 "subc.y"
                               {
    if ((yyvsp[-2].typeInfo) == NULL || (yyvsp[0].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.typeInfo) = NULL;
    } else if (!is_boolean_type((yyvsp[-2].typeInfo)) || !is_boolean_type((yyvsp[0].typeInfo))) { // 피연산자 타입이 불리언 타입이 아닌 경우
      error_binary();
      (yyval.typeInfo) = NULL;
    } else {
      (yyval.typeInfo) = malloc(sizeof(TypeInfo));
      (yyval.typeInfo)->type = TYPE_INT;
      (yyval.typeInfo)->is_lvalue = 0;
      (yyval.typeInfo)->next = NULL;
      (yyval.typeInfo)->struct_name = NULL;
      (yyval.typeInfo)->array_size = 0;
    }
  }
#line 1855 "subc.tab.c"
    break;

  case 54: /* binary: binary LOGICAL_OR binary  */
#line 595 "subc.y"
                             {
    if ((yyvsp[-2].typeInfo) == NULL || (yyvsp[0].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.typeInfo) = NULL;
    } else if (!is_boolean_type((yyvsp[-2].typeInfo)) || !is_boolean_type((yyvsp[0].typeInfo))) { // 피연산자 타입이 불리언 타입이 아닌 경우
      error_binary();
      (yyval.typeInfo) = NULL;
    } else { // 정상적인 경우
      (yyval.typeInfo) = (yyvsp[-2].typeInfo);
    }
  }
#line 1870 "subc.tab.c"
    break;

  case 55: /* unary: '(' expr ')'  */
#line 609 "subc.y"
                 {
    // expr을 괄호로 감싸면 타입 정보를 그대로 넘김
    (yyval.typeInfo) = (yyvsp[-1].typeInfo);
  }
#line 1879 "subc.tab.c"
    break;

  case 56: /* unary: '(' unary ')'  */
#line 613 "subc.y"
                  {
    // 피연산자를 괄호로 감싸면 타입 정보를 그대로 넘김
    (yyval.typeInfo) = (yyvsp[-1].typeInfo);
  }
#line 1888 "subc.tab.c"
    break;

  case 57: /* unary: INTEGER_CONST  */
#line 617 "subc.y"
                  {
    // 정수 상수 타입 생성
    (yyval.typeInfo) = malloc(sizeof(TypeInfo));
    (yyval.typeInfo)->type = TYPE_INT;
    (yyval.typeInfo)->is_lvalue = 0;
    (yyval.typeInfo)->next = NULL;
    (yyval.typeInfo)->struct_name = NULL;
    (yyval.typeInfo)->array_size = 0;
    (yyval.typeInfo)->field_list = NULL;
  }
#line 1903 "subc.tab.c"
    break;

  case 58: /* unary: CHAR_CONST  */
#line 627 "subc.y"
               {
    // 문자 상수 타입 생성
    (yyval.typeInfo) = malloc(sizeof(TypeInfo));
    (yyval.typeInfo)->type = TYPE_CHAR;
    (yyval.typeInfo)->is_lvalue = 0;
    (yyval.typeInfo)->next = NULL;
    (yyval.typeInfo)->struct_name = NULL;
    (yyval.typeInfo)->array_size = 0;
    (yyval.typeInfo)->field_list = NULL;
  }
#line 1918 "subc.tab.c"
    break;

  case 59: /* unary: STRING  */
#line 637 "subc.y"
           {
    // 문자열 타입 생성
    (yyval.typeInfo) = malloc(sizeof(TypeInfo));
    (yyval.typeInfo)->type = TYPE_POINTER;
    (yyval.typeInfo)->next = malloc(sizeof(TypeInfo));
    (yyval.typeInfo)->next->type = TYPE_CHAR;
    (yyval.typeInfo)->next->is_lvalue = 0;
    (yyval.typeInfo)->next->next = NULL;
    (yyval.typeInfo)->next->struct_name = NULL;
    (yyval.typeInfo)->next->array_size = 0;
    (yyval.typeInfo)->next->field_list = NULL;
    (yyval.typeInfo)->is_lvalue = 0;
    (yyval.typeInfo)->struct_name = NULL;
    (yyval.typeInfo)->array_size = 0;
    (yyval.typeInfo)->field_list = NULL;
  }
#line 1939 "subc.tab.c"
    break;

  case 60: /* unary: ID  */
#line 653 "subc.y"
       {
    // 심볼 테이블에서 타입 정보를 찾음
    Symbol* symbol = lookup_symbol((yyvsp[0].stringVal)); // ID의 타입 정보를 찾음
    // 여기서 나올 수 있는 것은 심볼이 없는 경우와 심볼이 있는 경우 두 가지 경우가 있음.
    // 심볼이 없는 경우는 변수가 선언되지 않은 경우임.
    // 심볼이 있는 경우는 변수가 선언된 경우임.
    // 따라서 심볼이 없는 경우는 에러 발생하고, 심볼이 있는 경우는 타입 정보를 복사하고, lvalue 여부를 결정함.

    if (!symbol) { // 심볼이 없는 경우 에러 발생
        error_undeclared();
        (yyval.typeInfo) = NULL;
    } else { // 심볼이 있는 경우
        // 피연산자의 타입 정보를 복사
        (yyval.typeInfo) = deep_copy_typeinfo(symbol->type);

        // 배열이면 lvalue가 아님!
        // lvalue는 대입 연산자의 왼쪽에 올 수 있는 값을 의미
        // 예를 들어 변수는 lvalue가 될 수 있지만, 상수나 표현식의 결과는 lvalue가 될 수 없음
        // 즉, int a = 10; 에서 a는 lvalue이고 10은 rvalue임
        // 포인터를 통한 간접 참조도 lvalue가 될 수 있음

        if ((yyval.typeInfo)->type == TYPE_ARRAY) { // 배열이면 lvalue가 아님
            (yyval.typeInfo)->is_lvalue = 0;
        } else { // 배열이 아닌 경우, lvalue로 처리
            (yyval.typeInfo)->is_lvalue = 1;
        }

        // 구조체 이름 복사해서 저장
        (yyval.typeInfo)->struct_name = strdup((yyvsp[0].stringVal));
    }
}
#line 1975 "subc.tab.c"
    break;

  case 61: /* unary: '-' unary  */
#line 684 "subc.y"
                        {
    if ((yyvsp[0].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.typeInfo) = NULL;
    } else { // 정상적인 경우
      (yyval.typeInfo) = (yyvsp[0].typeInfo);
    }
  }
#line 1987 "subc.tab.c"
    break;

  case 62: /* unary: '!' unary  */
#line 691 "subc.y"
              {
    if ((yyvsp[0].typeInfo) == NULL) {
      (yyval.typeInfo) = NULL;
    } else {
      (yyval.typeInfo) = (yyvsp[0].typeInfo);
    }
  }
#line 1999 "subc.tab.c"
    break;

  case 63: /* unary: unary INCOP  */
#line 698 "subc.y"
                               { // 후위 증감 연산
    // 피연산자가 NULL인 경우 즉, 피연산자가 없는 경우
    if ((yyvsp[-1].typeInfo) == NULL) {
      (yyval.typeInfo) = NULL;
    } 
    // 피연산자가 lvalue가 아닌 경우 에러 발생
    else if (!is_lvalue((yyvsp[-1].typeInfo))) {
      error_unary();
      (yyval.typeInfo) = NULL;
    } else { // 정상적인 경우
      (yyval.typeInfo) = deep_copy_typeinfo((yyvsp[-1].typeInfo));
      (yyval.typeInfo)->is_lvalue = 0; // 후위 증감 연산 결과는 rvalue
    }
  }
#line 2018 "subc.tab.c"
    break;

  case 64: /* unary: unary DECOP  */
#line 712 "subc.y"
                               { // 후위 감소 연산
    // 피연산자가 NULL인 경우 즉, 피연산자가 없는 경우
    if ((yyvsp[-1].typeInfo) == NULL) {
      (yyval.typeInfo) = NULL;
    } 
    // 피연산자가 lvalue가 아닌 경우 에러 발생
    else if (!is_lvalue((yyvsp[-1].typeInfo))) {
      error_unary();
      (yyval.typeInfo) = NULL;
    } else { // 정상적인 경우
      // 피연산자의 타입 정보를 복사
      (yyval.typeInfo) = deep_copy_typeinfo((yyvsp[-1].typeInfo));
      (yyval.typeInfo)->is_lvalue = 0; // 후위 증감 연산 결과는 rvalue
    }
  }
#line 2038 "subc.tab.c"
    break;

  case 65: /* unary: INCOP unary  */
#line 727 "subc.y"
                          {
    // 피연산자가 NULL인 경우
    if ((yyvsp[0].typeInfo) == NULL) {
      (yyval.typeInfo) = NULL;
    } 
    // 피연산자가 lvalue가 아닌 경우 에러 발생
    else if (!is_lvalue((yyvsp[0].typeInfo))) {
      error_unary();
      (yyval.typeInfo) = NULL;
    } 
    // 정상적인 경우
    else {
      // 피연산자의 타입 정보를 복사
      (yyval.typeInfo) = deep_copy_typeinfo((yyvsp[0].typeInfo));
      (yyval.typeInfo)->is_lvalue = 0; // 전위 증감 연산 결과도 rvalue
    }
  }
#line 2060 "subc.tab.c"
    break;

  case 66: /* unary: DECOP unary  */
#line 744 "subc.y"
                          {
    // 피연산자가 NULL인 경우
    if ((yyvsp[0].typeInfo) == NULL) {
      (yyval.typeInfo) = NULL;
    } 
    // 피연산자가 lvalue가 아닌 경우 에러 발생
    else if (!is_lvalue((yyvsp[0].typeInfo))) {
      error_unary();
      (yyval.typeInfo) = NULL;
    }
    // 정상적인 경우
    else {
      // 피연산자의 타입 정보를 복사
      (yyval.typeInfo) = deep_copy_typeinfo((yyvsp[0].typeInfo));
      // 전위 감소 연산의 결과는 rvalue
      (yyval.typeInfo)->is_lvalue = 0;
    }
  }
#line 2083 "subc.tab.c"
    break;

  case 67: /* unary: '&' unary  */
#line 762 "subc.y"
              {
    // 피연산자가 NULL인 경우
    if ((yyvsp[0].typeInfo) == NULL) {
      (yyval.typeInfo) = NULL;
    } 
    // 피연산자가 lvalue가 아닌 경우 에러 발생
    else if(!is_lvalue((yyvsp[0].typeInfo))) {
      if ((yyvsp[0].typeInfo)->type == TYPE_ARRAY) { // 나눠서 처리해야 에러 메시지가 제대로 출력됨.
        // 배열 타입의 경우, 주소 연산 에러 발생
        error_addressof();
      } else {
        // 포인터 타입의 경우, 주소 연산 에러 발생
        error_unary();
      }
      (yyval.typeInfo) = NULL;
    } else {
      // 포인터 타입 생성
      (yyval.typeInfo) = malloc(sizeof(TypeInfo));
      (yyval.typeInfo)->type = TYPE_POINTER;
      (yyval.typeInfo)->next = deep_copy_typeinfo((yyvsp[0].typeInfo));
      (yyval.typeInfo)->is_lvalue = 0;
      (yyval.typeInfo)->struct_name = NULL;
      (yyval.typeInfo)->array_size = 0;
      (yyval.typeInfo)->field_list = NULL;
    }
}
#line 2114 "subc.tab.c"
    break;

  case 68: /* unary: '*' unary  */
#line 788 "subc.y"
                        {
    // 피연산자가 NULL인 경우
    if ((yyvsp[0].typeInfo) == NULL) {
      (yyval.typeInfo) = NULL;
    } 
    // 피연산자가 포인터가 아닌 경우 에러 발생
    else if((yyvsp[0].typeInfo)->type != TYPE_POINTER) {
      error_indirection();
      (yyval.typeInfo) = NULL;
    } 
    // 피연산자가 lvalue가 아닌 경우 에러 발생
    else if (!is_lvalue((yyvsp[0].typeInfo))) {
      error_unary();
      (yyval.typeInfo) = NULL;
    } 
    // 정상적인 경우
    else { 
      // 피연산자의 타입 정보를 복사
      (yyval.typeInfo) = deep_copy_typeinfo((yyvsp[0].typeInfo)->next);
      // 포인터 타입의 경우, lvalue로 처리
      (yyval.typeInfo)->is_lvalue = 1;
    }
  }
#line 2142 "subc.tab.c"
    break;

  case 69: /* unary: unary '[' expr ']'  */
#line 811 "subc.y"
                       {
    // 배열 인덱스 연산 규칙
    if ((yyvsp[-3].typeInfo) == NULL || (yyvsp[-1].typeInfo) == NULL) {
      (yyval.typeInfo) = NULL;
    } else if((yyvsp[-3].typeInfo)->type != TYPE_ARRAY) { // 피연산자가 배열이 아닌 경우
      error_array();
      (yyval.typeInfo) = NULL;
    } else if((yyvsp[-1].typeInfo)->type != TYPE_INT) { // 피연산자가 정수가 아닌 경우
      error_subscript();
      (yyval.typeInfo) = NULL;
    } else { // 정상적인 경우
      (yyval.typeInfo) = deep_copy_typeinfo((yyvsp[-3].typeInfo)->next);
      (yyval.typeInfo)->is_lvalue = 1;
    }
  }
#line 2162 "subc.tab.c"
    break;

  case 70: /* unary: unary '.' ID  */
#line 826 "subc.y"
                 {
    // 구조체 멤버 접근 규칙
    if ((yyvsp[-2].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.typeInfo) = NULL;
    } else if((yyvsp[-2].typeInfo)->type != TYPE_STRUCT) { // 피연산자가 구조체가 아닌 경우
      error_lineno = get_lineno(); /* 여기에서 라인번호 기록 */
      // 타입 호환 에러 발생
      error_incompatible(); 
      (yyval.typeInfo) = NULL;
    } else { // 정상적인 경우
      TypeInfo *field_type = find_field_type((yyvsp[-2].typeInfo), (yyvsp[0].stringVal));
      // 필드 없을 때도 마찬가지
      if(field_type == NULL) {
        error_lineno = get_lineno();
        // 필드 없을 때도 마찬가지
        error_member();
        (yyval.typeInfo) = NULL;
      } else {
        // 필드 타입 복사
        (yyval.typeInfo) = deep_copy_typeinfo(field_type);
        (yyval.typeInfo)->is_lvalue = 1;
      }
    }
  }
#line 2191 "subc.tab.c"
    break;

  case 71: /* unary: unary STRUCTOP ID  */
#line 850 "subc.y"
                      {
    // 구조체 포인터 멤버 접근 규칙
    if((yyvsp[-2].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.typeInfo) = NULL;
    } else if((yyvsp[-2].typeInfo)->type != TYPE_POINTER || (yyvsp[-2].typeInfo)->next->type != TYPE_STRUCT) { // 피연산자가 구조체 포인터가 아닌 경우
      error_strurctp(); /* 구조체 포인터가 아니라면 에러 메시지를 출력함 */
      (yyval.typeInfo) = NULL;
    } else {
      // 구조체 타입 정보 복사
      TypeInfo *struct_type = (yyvsp[-2].typeInfo)->next;
      // 필드 타입 찾기
      TypeInfo *field_type = find_field_type(struct_type, (yyvsp[0].stringVal));

      // 필드가 없으면 에러 발생
      if(field_type == NULL) {
        error_member();
        (yyval.typeInfo) = NULL;
      } else {
        // 필드 타입 복사
        (yyval.typeInfo) = deep_copy_typeinfo(field_type);
        (yyval.typeInfo)->is_lvalue = 1;
      }
    }
  }
#line 2220 "subc.tab.c"
    break;

  case 72: /* unary: unary '(' args ')'  */
#line 874 "subc.y"
                       {
    // 함수 호출 규칙
    if ((yyvsp[-3].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.typeInfo) = NULL;
    } else {
      // 함수 타입 정보 찾기
      FuncInfo* func = find_func_info((yyvsp[-3].typeInfo)->struct_name); /* struct_name에 함수 이름 저장됨 */
        if (func == NULL) { /* 함수가 아니라면 */
            error_function(); /* 에러 메시지를 출력함 */
            (yyval.typeInfo) = NULL;
        } else if (!is_compatible_arguments(func->param_list, (yyvsp[-1].paramList))) {
            error_arguments(); /* 인자 리스트가 호환되지 않으면 에러 메시지를 출력함 */
            (yyval.typeInfo) = NULL;
        } else if (func->param_list == NULL) { // 인자 리스트가 없는 경우 에러 발생
          error_function();
          (yyval.typeInfo) = NULL;
        } else {
            (yyval.typeInfo) = deep_copy_typeinfo(func->return_type); /* 함수 반환 타입을 반환함 */
            (yyval.typeInfo)->is_lvalue = 0;
        }
    }
  }
#line 2247 "subc.tab.c"
    break;

  case 73: /* unary: unary '(' ')'  */
#line 896 "subc.y"
                  {
    // 인자가 없는 함수 호출 규칙
    if ((yyvsp[-2].typeInfo) == NULL || (yyvsp[-2].typeInfo)->struct_name == NULL) {
      error_function();
      (yyval.typeInfo) = NULL;
    } else { // 정상적인 경우
      // 함수 타입 정보 찾기
      FuncInfo* func = find_func_info((yyvsp[-2].typeInfo)->struct_name);

      // 함수가 없거나 반환 타입이 없는 경우 에러 발생
      if (func == NULL || func->return_type == NULL) {
        error_function(); 
        (yyval.typeInfo) = NULL;
      } 

      // 인자 리스트가 있는 경우 에러 발생
      else if (func->param_list != NULL) {
        error_arguments();
        (yyval.typeInfo) = NULL;
      }

      else { // 정상적인 경우
        (yyval.typeInfo) = deep_copy_typeinfo(func->return_type);
        (yyval.typeInfo)->is_lvalue = 0;
      }
    }
  }
#line 2279 "subc.tab.c"
    break;

  case 74: /* unary: SYM_NULL  */
#line 923 "subc.y"
             {
    // NULL 타입 생성
    (yyval.typeInfo) = malloc(sizeof(TypeInfo));
    (yyval.typeInfo)->type = TYPE_NULLPTR;
    (yyval.typeInfo)->next = NULL;
    (yyval.typeInfo)->is_lvalue = 0;
    (yyval.typeInfo)->struct_name = NULL;
    (yyval.typeInfo)->array_size = 0;
    (yyval.typeInfo)->field_list = NULL;
  }
#line 2294 "subc.tab.c"
    break;

  case 75: /* args: expr  */
#line 936 "subc.y"
         {
    // 함수 호출 시 인자 리스트 생성
    // 인자 리스트 생성
    if ((yyvsp[0].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.paramList) = NULL;
    } else { // 정상적인 경우
      (yyval.paramList) = create_param_list();
      // 인자 리스트에 피연산자 추가
      add_arg((yyval.paramList), (yyvsp[0].typeInfo));
    }
  }
#line 2310 "subc.tab.c"
    break;

  case 76: /* args: args ',' expr  */
#line 947 "subc.y"
                  {
    // 함수 호출 시 인자 리스트 생성
    // 인자 리스트 생성
    if ((yyvsp[-2].paramList) == NULL || (yyvsp[0].typeInfo) == NULL) { // 피연산자가 NULL인 경우
      (yyval.paramList) = NULL;
    } else { // 정상적인 경우
        (yyval.paramList) = (yyvsp[-2].paramList);
        // 인자 리스트에 피연산자 추가
        add_arg((yyval.paramList), (yyvsp[0].typeInfo));
    }
  }
#line 2326 "subc.tab.c"
    break;


#line 2330 "subc.tab.c"

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

#line 960 "subc.y"


/* Epilogue section */

void error_preamble(void) {
  if (error_lineno != -1) {
    printf("%s:%d: error: ", current_filename, error_lineno);
  } else {
    printf("%s:%d: error: ", current_filename, get_lineno());
  }
  error_lineno = -1;
}

void error_undeclared(void) {
  error_preamble();
  printf("use of undeclared identifier\n");
}

void error_redeclaration(void) {
  error_preamble();
  printf("redeclaration\n");
}

void error_assignable(void) {
  error_preamble();
  printf("lvalue is not assignable\n");
}

void error_incompatible(void) {
  error_preamble();
  printf("incompatible types for assignment operation\n");
}

void error_null(void) {
  error_preamble();
  printf("cannot assign 'NULL' to non-pointer type\n");
}

void error_binary(void) {
  error_preamble();
  printf("invalid operands to binary expression\n");
}

void error_unary(void) {
  error_preamble();
  printf("invalid argument type to unary expression\n");
}

void error_comparable(void) {
  error_preamble();
  printf("types are not comparable in binary expression\n");
}

void error_indirection(void) {
  error_preamble();
  printf("indirection requires pointer operand\n");
}

void error_addressof(void) {
  error_preamble();
  printf("cannot take the address of an rvalue\n");
}

void error_struct(void) {
  error_preamble();
  printf("member reference base type is not a struct\n");
}

void error_strurctp(void){
  error_preamble();
  printf("member reference base type is not a struct pointer\n");
}

void error_member(void) {
  error_preamble();
  printf("no such member in struct\n");
}

void error_array(void) {
  error_preamble();
  printf("subscripted value is not an array\n");
}

void error_subscript(void) {
  error_preamble();
  printf("array subscript is not an integer\n");
}

void error_incomplete(void) {
  error_preamble();
  printf("incomplete type\n");
}

void error_return(void) {
  error_preamble();
  printf("incompatible return types\n");
}

void error_function(void) {
  error_preamble();
  printf("not a function\n");
}

void error_arguments(void) {
  error_preamble();
  printf("incompatible arguments in function call\n");
}

void yyerror(char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}
