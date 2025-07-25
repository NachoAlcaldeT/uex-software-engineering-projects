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
#line 1 "expresiones.y" /* yacc.c:339  */


#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdio>

#include "estructura.h"
#include "estructuramuebles.h"
#include <cstring>


using namespace std;




int n_lineas;
extern int yylex();
extern FILE* yyin;
extern FILE* yyout;


bool errorSemantico = false;
bool divEnt = false;
bool aritmetica = false;
bool porcentaje= false;
bool divisionRealCero = false;
bool logica = false;
bool reslog=false;
int cont=0;
int tipoDato=0;
bool Encontrado=false;
bool varDerecha=false;
bool condicional=true;

FILE *archivo;

MueblesTable mueblesTable;

void convertirMayusculas(const char* original, char* mayusculas) {
    size_t i = 0;
    while (original[i]) {
        mayusculas[i] = toupper(original[i]);
        ++i;
    }
    mayusculas[i] = '\0'; 
}

void printMuebles(const tipo_cadena nombre, int fila, int columna){
	MuebleInfo mueble= mueblesTable.buscarMueblePorNombre(nombre);
	
	 if (mueble.tipo != NOENCONTRADO) {
        char colorMayusculas[50]; // Buffer para almacenar la versión en mayúsculas del color
        convertirMayusculas(mueble.color, colorMayusculas);

        if (mueble.tipo == RECTANGULO) {
            if (mueble.tipo_valor1 == ENTEROMUEBLES && mueble.tipo_valor2 == ENTEROMUEBLES) {
                fprintf(archivo, "\trectanguloAmu(%d, %d, %d, %d, %s);\n", fila, columna, mueble.valor1.valor_entero, mueble.valor2.valor_entero, colorMayusculas);
            } else if (mueble.tipo_valor1 == ENTEROMUEBLES && mueble.tipo_valor2 == REALMUEBLES) {
                fprintf(archivo, "\trectanguloAmu(%d, %d, %d, %f, %s);\n", fila, columna, mueble.valor1.valor_entero, mueble.valor2.valor_real, colorMayusculas);
            } else if (mueble.tipo_valor1 == REALMUEBLES && mueble.tipo_valor2 == ENTEROMUEBLES) {
                fprintf(archivo, "\trectanguloAmu(%d, %d, %f, %d, %s);\n", fila, columna, mueble.valor1.valor_real, mueble.valor2.valor_entero, colorMayusculas);
            } else {
                fprintf(archivo, "\trectanguloAmu(%d, %d, %f, %f, %s);\n", fila, columna, mueble.valor1.valor_real, mueble.valor2.valor_real, colorMayusculas);
            }
        } else if (mueble.tipo == CIRCULO) {
            if (mueble.tipo_valor1 == ENTEROMUEBLES) {
                fprintf(archivo, "\tcirculoAmu(%d, %d, %d, %s);\n", fila, columna, mueble.valor1.valor_entero, colorMayusculas);
            } else {
                fprintf(archivo, "\tcirculoAmu(%d, %d, %f, %s);\n", fila, columna, mueble.valor1.valor_real, colorMayusculas);
            }
        }
    } else {
        cout << "Mueble no encontrado " << endl;
    }
      
}


void yyerror(const char* s) {
    cout << "Error sintactico en la instruccion " << cont << endl;
 cont = cont +1;
}

void prompt() {
   
}

void manejarErrores(int cont) {
    cout << "Error semantico en la instruccion " << cont << ":";
    if (porcentaje) {
        cout << " se utiliza el operador % con numeros reales" << endl;
        porcentaje = false;
    }
    if (divEnt) {
        cout << ": se utiliza el operador // con numeros reales" << endl;
        divEnt = false;
    }
    if (divisionRealCero) {
        cout << " division por cero" << endl;
        divisionRealCero = false;
    }
    errorSemantico = false;
}

IdentifiersTable identifiersTable;





#line 180 "expresiones.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "expresiones.h".  */
#ifndef YY_YY_EXPRESIONES_H_INCLUDED
# define YY_YY_EXPRESIONES_H_INCLUDED
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
    REAL = 258,
    ENTERO = 259,
    Nombre = 260,
    IDVAB = 261,
    rectangulo = 262,
    circulo = 263,
    VARIABLES = 264,
    MUEBLES = 265,
    HABITACION = 266,
    Enterovab = 267,
    Realvab = 268,
    Boolvab = 269,
    IGUALMUEBLES = 270,
    negro = 271,
    amarillo = 272,
    gris = 273,
    rojo = 274,
    azul = 275,
    marron = 276,
    verde = 277,
    PUNTOS = 278,
    FINHABITACION = 279,
    situar = 280,
    mensaje = 281,
    pausa = 282,
    CADENA = 283,
    ASIG = 284,
    DIVENT = 285,
    MENORIGUAL = 286,
    MAYORIGUAL = 287,
    MENOR = 288,
    MAYOR = 289,
    DISTINTO = 290,
    IGUAL = 291,
    CIERTO = 292,
    FALSO = 293,
    no = 294,
    si = 295,
    si_no = 296,
    y = 297,
    o = 298,
    menosunario = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 117 "expresiones.y" /* yacc.c:355  */


int c_entero;
float c_real;
char c_cadena[20];
char c_mensaje[100];

struct estructur{
	 	float valor;
		bool esReal;
		} c_expresion;

struct str_logica{
	bool bandera;
	} c_logica;

#line 282 "expresiones.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXPRESIONES_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 299 "expresiones.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   305

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  222

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      55,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    48,     2,     2,
      51,    52,    46,    44,    50,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   203,   203,   204,   208,   209,   209,   212,   213,   216,
     217,   218,   219,   230,   241,   252,   271,   290,   302,   315,
     327,   340,   351,   364,   364,   368,   369,   372,   394,   410,
     411,   412,   413,   414,   415,   416,   418,   422,   423,   426,
     426,   430,   431,   433,   434,   437,   438,   439,   440,   459,
     478,   481,   482,   483,   484,   503,   525,   525,   528,   529,
     532,   533,   534,   557,   558,   559,   560,   568,   582,   591,
     592,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "REAL", "ENTERO", "Nombre", "IDVAB",
  "rectangulo", "circulo", "VARIABLES", "MUEBLES", "HABITACION",
  "Enterovab", "Realvab", "Boolvab", "IGUALMUEBLES", "negro", "amarillo",
  "gris", "rojo", "azul", "marron", "verde", "PUNTOS", "FINHABITACION",
  "situar", "mensaje", "pausa", "CADENA", "ASIG", "DIVENT", "MENORIGUAL",
  "MAYORIGUAL", "MENOR", "MAYOR", "DISTINTO", "IGUAL", "CIERTO", "FALSO",
  "no", "si", "si_no", "y", "o", "'+'", "'-'", "'*'", "'/'", "'%'",
  "menosunario", "','", "'('", "')'", "'{'", "'}'", "'\\n'", "$accept",
  "entrada", "blVars", "$@1", "secDefVars", "defVar",
  "identificadoresEntero", "identificadoresReal", "identificadoresBool",
  "blMuebles", "$@2", "secDefMbls", "defMbls", "color", "valor",
  "Habitaciones", "blHabitaciones", "$@3", "secDefHabs", "secDefHabs2",
  "defHabs", "defHabs2", "si_bloque", "$@4", "salto", "expr",
  "expr_logica", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    43,    45,    42,    47,    37,   299,
      44,    40,    41,   123,   125,    10
};
# endif

#define YYPACT_NINF -147

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-147)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,  -147,  -147,     5,    -1,    23,   -40,  -147,  -147,     7,
    -147,    -1,    -2,   -40,   -26,     7,  -147,     7,     9,    36,
      73,    81,   222,  -147,    -3,    88,  -147,     7,    77,   -23,
     -40,   -21,   -40,    70,   -40,  -147,    61,    84,  -147,  -147,
    -147,  -147,    88,    88,    43,   179,  -147,  -147,    77,    77,
     185,   130,    88,   103,    57,    88,   107,    57,    77,   115,
      57,    94,  -147,  -147,    56,    88,    88,    88,    88,    88,
      88,    88,   243,  -147,   211,   218,    88,    88,    88,    88,
      88,    88,    57,    77,    77,    77,    77,    57,   157,    86,
    -147,   157,    91,  -147,   130,    93,  -147,    26,  -147,    95,
    -147,   102,   102,  -147,  -147,  -147,  -147,   179,   179,   179,
     179,   179,   179,  -147,  -147,    99,    82,    57,    57,    57,
     101,   114,   110,    88,    88,   129,   119,   120,  -147,    88,
     278,   -40,   121,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
     140,    35,   278,   -40,   147,   126,   128,   131,   138,    -5,
    -147,  -147,   146,    57,    77,   186,   162,    88,    77,   -40,
    -147,   -40,   185,   130,   142,   141,   220,   250,    57,    57,
      57,    57,    88,   -40,   -40,  -147,   145,    57,    57,   144,
      88,   -40,   154,    35,   -40,   104,    57,   -40,    29,   158,
     -40,    71,   181,   171,   187,   188,   134,  -147,    77,   208,
     209,    88,   -40,  -147,   185,   130,   198,   197,   199,    57,
      57,    57,    88,   -40,   -40,   202,    57,    57,    88,   210,
     -40,    57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     5,    58,     0,     0,     4,     0,     1,    23,     0,
      59,     0,     0,     0,     0,     2,    37,     0,     0,     0,
       0,     0,     6,     7,     0,     0,    38,     3,     0,    18,
       0,    20,     0,    22,     0,     8,     0,    24,    25,    61,
      60,    62,     0,     0,     0,    36,    71,    72,     0,     0,
       0,     0,     0,     0,     9,     0,     0,    10,     0,     0,
      11,     0,    26,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     0,     0,     0,    16,     0,    18,
      17,     0,    20,    19,     0,    22,    21,     0,    70,     0,
      67,    63,    64,    65,    66,    68,    84,    78,    79,    80,
      81,    83,    82,    74,    73,    75,    76,    12,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,    39,     0,
       0,     0,     0,    29,    33,    30,    34,    35,    32,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,    50,     0,    28,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,     0,     0,     0,     0,    40,    27,
      48,    49,     0,     0,     0,    56,     0,    46,    47,     0,
       0,     0,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    43,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,    57,
      54,    55,     0,     0,     0,     0,    52,    53,     0,     0,
       0,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,   264,  -147,  -147,   249,   227,   225,   223,   272,
    -147,  -147,   247,   159,   -18,   286,    80,  -147,   122,  -147,
    -146,   108,  -147,  -147,    -6,   -12,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     6,    22,    23,    30,    32,    34,     9,
      13,    37,    38,   140,    44,    15,    16,   131,   149,   196,
     150,   197,   151,   179,     5,    45,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      12,   144,    36,   160,    18,     7,    52,    24,    55,     8,
      19,    20,    21,    73,    75,     2,    50,     1,    14,   159,
     145,   146,   147,    94,    54,    25,    57,    53,    60,    56,
      63,    64,     1,   120,   121,   148,    72,    74,    28,   160,
      88,   144,    29,    91,    82,    87,    72,    99,   113,   114,
     115,   116,    10,    10,   100,   101,   102,   103,   104,   105,
     145,   146,   147,     2,   107,   108,   109,   110,   111,   112,
     189,    72,    72,    72,    72,   148,    61,   192,    10,    31,
      39,    40,   117,    41,    10,   118,    66,    33,   119,    36,
      10,    39,    40,    65,    41,    26,   193,   194,   195,    58,
      67,    68,    69,    70,    71,   126,   127,    26,    98,    89,
     144,   132,    10,    92,    46,    47,    48,    83,    84,   163,
      59,    95,    42,   167,    85,   141,    10,    97,    49,   145,
     146,   147,    66,    42,    83,    84,    53,   153,   125,    43,
     192,    56,   162,    59,   148,   166,    72,   122,    69,    70,
      71,   123,   128,   168,   176,   169,   170,   171,   187,   193,
     194,   195,   182,   205,   124,    83,    84,   177,   178,   129,
     130,   142,    85,    86,   143,   183,   154,   155,   186,   156,
     161,   188,   157,   208,   191,     2,   204,    66,   202,   158,
     165,   164,   172,   173,   215,   180,   209,   181,   210,   211,
     219,    67,    68,    69,    70,    71,   184,   216,   217,    66,
     198,   190,     2,   206,   221,    66,    76,    77,    78,    79,
      80,    81,   199,    67,    68,    69,    70,    71,    18,    67,
      68,    69,    70,    71,    19,    20,    21,   207,   200,   201,
       2,    66,    76,    77,    78,    79,    80,    81,   212,   213,
      66,   214,   218,    83,    84,    67,    68,    69,    70,    71,
      85,    86,   220,    98,    67,    68,    69,    70,    71,    11,
     106,    35,   174,    66,    76,    77,    78,    79,    80,    81,
      90,    93,    96,    17,    62,    83,    84,    67,    68,    69,
      70,    71,    85,    86,   133,   134,   135,   136,   137,   138,
     139,   152,   175,    27,   203,   185
};

static const yytype_uint8 yycheck[] =
{
       6,     6,     5,   149,     6,     0,    29,    13,    29,    10,
      12,    13,    14,    48,    49,    55,    28,     9,    11,    24,
      25,    26,    27,    58,    30,    51,    32,    50,    34,    50,
      42,    43,     9,     7,     8,    40,    48,    49,    29,   185,
      52,     6,     6,    55,    50,    51,    58,    65,    83,    84,
      85,    86,    55,    55,    66,    67,    68,    69,    70,    71,
      25,    26,    27,    55,    76,    77,    78,    79,    80,    81,
      41,    83,    84,    85,    86,    40,    15,     6,    55,     6,
       3,     4,    88,     6,    55,    91,    30,     6,    94,     5,
      55,     3,     4,    50,     6,    15,    25,    26,    27,    29,
      44,    45,    46,    47,    48,   123,   124,    27,    52,     6,
       6,   129,    55,     6,    37,    38,    39,    35,    36,   154,
      50,     6,    45,   158,    42,   131,    55,    33,    51,    25,
      26,    27,    30,    45,    35,    36,    50,   143,    28,    51,
       6,    50,   154,    50,    40,   157,   158,    52,    46,    47,
      48,    50,    23,   159,   172,   161,   162,   163,    54,    25,
      26,    27,   180,   198,    50,    35,    36,   173,   174,    50,
      50,    50,    42,    43,    34,   181,    29,    51,   184,    51,
      34,   187,    51,   201,   190,    55,   198,    30,    54,    51,
      28,     5,    50,    52,   212,    50,   202,    53,   204,   205,
     218,    44,    45,    46,    47,    48,    52,   213,   214,    30,
      29,    53,    55,     5,   220,    30,    31,    32,    33,    34,
      35,    36,    51,    44,    45,    46,    47,    48,     6,    44,
      45,    46,    47,    48,    12,    13,    14,    28,    51,    51,
      55,    30,    31,    32,    33,    34,    35,    36,    50,    52,
      30,    52,    50,    35,    36,    44,    45,    46,    47,    48,
      42,    43,    52,    52,    44,    45,    46,    47,    48,     5,
      52,    22,    52,    30,    31,    32,    33,    34,    35,    36,
      53,    56,    59,    11,    37,    35,    36,    44,    45,    46,
      47,    48,    42,    43,    16,    17,    18,    19,    20,    21,
      22,   142,    52,    17,   196,   183
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    55,    57,    58,    80,    59,     0,    10,    65,
      55,    58,    80,    66,    11,    71,    72,    65,     6,    12,
      13,    14,    60,    61,    80,    51,    72,    71,    29,     6,
      62,     6,    63,     6,    64,    61,     5,    67,    68,     3,
       4,     6,    45,    51,    70,    81,    37,    38,    39,    51,
      81,    82,    29,    50,    80,    29,    50,    80,    29,    50,
      80,    15,    68,    81,    81,    50,    30,    44,    45,    46,
      47,    48,    81,    82,    81,    82,    31,    32,    33,    34,
      35,    36,    80,    35,    36,    42,    43,    80,    81,     6,
      62,    81,     6,    63,    82,     6,    64,    33,    52,    70,
      81,    81,    81,    81,    81,    81,    52,    81,    81,    81,
      81,    81,    81,    82,    82,    82,    82,    80,    80,    80,
       7,     8,    52,    50,    50,    28,    70,    70,    23,    50,
      50,    73,    70,    16,    17,    18,    19,    20,    21,    22,
      69,    80,    50,    34,     6,    25,    26,    27,    40,    74,
      76,    78,    69,    80,    29,    51,    51,    51,    51,    24,
      76,    34,    81,    82,     5,    28,    81,    82,    80,    80,
      80,    80,    50,    52,    52,    52,    70,    80,    80,    79,
      50,    53,    70,    80,    52,    74,    80,    54,    80,    41,
      53,    80,     6,    25,    26,    27,    75,    77,    29,    51,
      51,    51,    54,    77,    81,    82,     5,    28,    70,    80,
      80,    80,    50,    52,    52,    70,    80,    80,    50,    70,
      52,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    58,    59,    58,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    63,
      63,    64,    64,    66,    65,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    70,    71,    71,    73,
      72,    74,    74,    75,    75,    76,    76,    76,    76,    76,
      76,    77,    77,    77,    77,    77,    79,    78,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     4,     0,     0,     4,     1,     2,     3,
       3,     3,     5,     5,     5,     4,     4,     3,     1,     3,
       1,     3,     1,     0,     4,     1,     2,    12,    10,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
      13,     1,     2,     1,     2,     9,     5,     5,     4,     4,
       1,     9,     5,     5,     4,     4,     0,    16,     1,     2,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     1,     1,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3
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
      yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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
yyparse (void)
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
        case 5:
#line 209 "expresiones.y" /* yacc.c:1646  */
    {cout<<"Bloque de variables detectado"<<endl;}
#line 1539 "expresiones.c" /* yacc.c:1646  */
    break;

  case 9:
#line 216 "expresiones.y" /* yacc.c:1646  */
    {cout<<"Variables de tipo "<<(yyvsp[-2].c_cadena)<<" detectadas"<< endl;}
#line 1545 "expresiones.c" /* yacc.c:1646  */
    break;

  case 10:
#line 217 "expresiones.y" /* yacc.c:1646  */
    {cout<<"Variables de tipo "<<(yyvsp[-2].c_cadena)<<" detectadas"<< endl;}
#line 1551 "expresiones.c" /* yacc.c:1646  */
    break;

  case 11:
#line 218 "expresiones.y" /* yacc.c:1646  */
    {cout<<"Variables de tipo "<<(yyvsp[-2].c_cadena)<<" detectadas"<< endl;}
#line 1557 "expresiones.c" /* yacc.c:1646  */
    break;

  case 12:
#line 219 "expresiones.y" /* yacc.c:1646  */
    { cout << "Variable de tipo " << (yyvsp[-4].c_cadena) << " declarada e inicializada con id: "<< (yyvsp[-3].c_cadena)<<" y con valor " << (yyvsp[-1].c_expresion).valor << endl; 
						 if (errorSemantico) {
							manejarErrores(cont);
						 } else {
							IdentifierInfo nuevoIdentificador;
							nuevoIdentificador.tipo = 0;
							nuevoIdentificador.valor.valor_entero = (yyvsp[-1].c_expresion).valor;
							strcpy(nuevoIdentificador.identificador, (yyvsp[-3].c_cadena));
							identifiersTable.addIdentifier(nuevoIdentificador);
		}
	}
#line 1573 "expresiones.c" /* yacc.c:1646  */
    break;

  case 13:
#line 230 "expresiones.y" /* yacc.c:1646  */
    { cout << "Variable de tipo " << (yyvsp[-4].c_cadena) << " declarada e inicializada con id: "<< (yyvsp[-3].c_cadena)<<" y con valor " << (yyvsp[-1].c_expresion).valor << endl; 
						 if (errorSemantico) {
							manejarErrores(cont);
						 } else {
							IdentifierInfo nuevoIdentificador;
							nuevoIdentificador.tipo = 1;
							nuevoIdentificador.valor.valor_real = (yyvsp[-1].c_expresion).valor;
							strcpy(nuevoIdentificador.identificador, (yyvsp[-3].c_cadena));
							identifiersTable.addIdentifier(nuevoIdentificador);
						}
	}
#line 1589 "expresiones.c" /* yacc.c:1646  */
    break;

  case 14:
#line 241 "expresiones.y" /* yacc.c:1646  */
    { cout << "Variable de tipo " << (yyvsp[-4].c_cadena) << " declarada e inicializada con id: "<< (yyvsp[-3].c_cadena)<<" y con valor " << (yyvsp[-1].c_logica).bandera << endl; 
						if (errorSemantico) {
							manejarErrores(cont);
						 } else {
							IdentifierInfo nuevoIdentificador;
							nuevoIdentificador.tipo = 2;
							nuevoIdentificador.valor.valor_bool = (yyvsp[-1].c_logica).bandera;
							strcpy(nuevoIdentificador.identificador, (yyvsp[-3].c_cadena));
							identifiersTable.addIdentifier(nuevoIdentificador);
						}
	}
#line 1605 "expresiones.c" /* yacc.c:1646  */
    break;

  case 15:
#line 252 "expresiones.y" /* yacc.c:1646  */
    { cout << "Variable con id: "<< (yyvsp[-3].c_cadena)<<" y con valor " << (yyvsp[-1].c_expresion).valor << endl; 
					
						if (errorSemantico) {
						manejarErrores(cont);
					    } else {
						IdentifierInfo nuevoIdentificador;

						if ((yyvsp[-1].c_expresion).esReal) {
						    nuevoIdentificador.tipo = 1;
						    nuevoIdentificador.valor.valor_real = (yyvsp[-1].c_expresion).valor;
						} else {
						    nuevoIdentificador.tipo = 0;
						    nuevoIdentificador.valor.valor_entero = (yyvsp[-1].c_expresion).valor;
						}
						strcpy(nuevoIdentificador.identificador, (yyvsp[-3].c_cadena));
						identifiersTable.addIdentifier(nuevoIdentificador);
			    }
						
	}
#line 1629 "expresiones.c" /* yacc.c:1646  */
    break;

  case 16:
#line 271 "expresiones.y" /* yacc.c:1646  */
    { cout << "Variable bool con id: "<< (yyvsp[-3].c_cadena)<<" y con valor: "<< (yyvsp[-1].c_logica).bandera ; 

						if (errorSemantico) {
						manejarErrores(cont);
					    } else {
						IdentifierInfo nuevoIdentificador;

						
						    nuevoIdentificador.tipo = 2;
						    nuevoIdentificador.valor.valor_bool = (yyvsp[-1].c_logica).bandera;
						
						
						strcpy(nuevoIdentificador.identificador, (yyvsp[-3].c_cadena));
						identifiersTable.addIdentifier(nuevoIdentificador);
			    }
	}
#line 1650 "expresiones.c" /* yacc.c:1646  */
    break;

  case 17:
#line 290 "expresiones.y" /* yacc.c:1646  */
    { cout << "ID: " << (yyvsp[-2].c_cadena) << endl; 
							if (errorSemantico) {
							manejarErrores(cont);
						 } else {
							IdentifierInfo nuevoIdentificador;
							nuevoIdentificador.tipo = 0;
							nuevoIdentificador.valor.valor_entero = -1; //valor por defecto
							strcpy(nuevoIdentificador.identificador, (yyvsp[-2].c_cadena));
							identifiersTable.addIdentifier(nuevoIdentificador);
						}
							
		}
#line 1667 "expresiones.c" /* yacc.c:1646  */
    break;

  case 18:
#line 302 "expresiones.y" /* yacc.c:1646  */
    { cout << "ID: " << (yyvsp[0].c_cadena) << endl; 
			if (errorSemantico) {
				manejarErrores(cont);
			 } else {
				IdentifierInfo nuevoIdentificador;
				nuevoIdentificador.tipo = 0;
				nuevoIdentificador.valor.valor_entero = -1; //valor por defecto
				strcpy(nuevoIdentificador.identificador, (yyvsp[0].c_cadena));
				identifiersTable.addIdentifier(nuevoIdentificador);
			}
		}
#line 1683 "expresiones.c" /* yacc.c:1646  */
    break;

  case 19:
#line 315 "expresiones.y" /* yacc.c:1646  */
    { cout << "ID: " << (yyvsp[-2].c_cadena) << endl; 
						if (errorSemantico) {
							manejarErrores(cont);
						 } else {
							IdentifierInfo nuevoIdentificador;
							nuevoIdentificador.tipo = 1;
							nuevoIdentificador.valor.valor_entero = -1.0; //valor por defecto
						strcpy(nuevoIdentificador.identificador, (yyvsp[-2].c_cadena));
						identifiersTable.addIdentifier(nuevoIdentificador);
						}
						
		}
#line 1700 "expresiones.c" /* yacc.c:1646  */
    break;

  case 20:
#line 327 "expresiones.y" /* yacc.c:1646  */
    { cout << "ID: " << (yyvsp[0].c_cadena) << endl; 
			if (errorSemantico) {
				manejarErrores(cont);
			 } else {
				IdentifierInfo nuevoIdentificador;
				nuevoIdentificador.tipo = 1;
				nuevoIdentificador.valor.valor_entero = -1.0; //valor por defecto
				strcpy(nuevoIdentificador.identificador, (yyvsp[0].c_cadena));
				identifiersTable.addIdentifier(nuevoIdentificador);
			}
		}
#line 1716 "expresiones.c" /* yacc.c:1646  */
    break;

  case 21:
#line 340 "expresiones.y" /* yacc.c:1646  */
    { cout << "ID: " << (yyvsp[-2].c_cadena) << endl; 
						if (errorSemantico) {
							manejarErrores(cont);
						 } else {
							IdentifierInfo nuevoIdentificador;
							nuevoIdentificador.tipo = 2;
							nuevoIdentificador.valor.valor_bool = false; //valor por defecto
							strcpy(nuevoIdentificador.identificador, (yyvsp[-2].c_cadena));
							identifiersTable.addIdentifier(nuevoIdentificador);
						}
		}
#line 1732 "expresiones.c" /* yacc.c:1646  */
    break;

  case 22:
#line 351 "expresiones.y" /* yacc.c:1646  */
    { cout << "ID: " << (yyvsp[0].c_cadena) << endl; 
			if (errorSemantico) {
				manejarErrores(cont);
			} else {
				IdentifierInfo nuevoIdentificador;
				nuevoIdentificador.tipo = 2;
				nuevoIdentificador.valor.valor_bool = false; //valor por defecto
				strcpy(nuevoIdentificador.identificador, (yyvsp[0].c_cadena));
				identifiersTable.addIdentifier(nuevoIdentificador);
			}
		}
#line 1748 "expresiones.c" /* yacc.c:1646  */
    break;

  case 23:
#line 364 "expresiones.y" /* yacc.c:1646  */
    {cout<<"Bloque de muebles detectado"<<endl;}
#line 1754 "expresiones.c" /* yacc.c:1646  */
    break;

  case 27:
#line 372 "expresiones.y" /* yacc.c:1646  */
    { cout << "Mueble: " << (yyvsp[-11].c_cadena) << " con forma " <<(yyvsp[-8].c_cadena)<<" de ancho: "<<(yyvsp[-6].c_expresion).valor<<" y la altura: "<<(yyvsp[-4].c_expresion).valor<<" y color: "<<(yyvsp[-2].c_cadena)<<endl; 
			MuebleInfo mueble;
			strcpy(mueble.nombre, (yyvsp[-11].c_cadena));
			mueble.tipo = RECTANGULO;
			if((yyvsp[-6].c_expresion).esReal){
				 mueble.tipo_valor1=REALMUEBLES;
				 mueble.valor1.valor_real=(yyvsp[-6].c_expresion).valor;
			}else{
				mueble.tipo_valor1=ENTEROMUEBLES;
				mueble.valor1.valor_entero=(yyvsp[-6].c_expresion).valor;
			}
			if((yyvsp[-4].c_expresion).esReal){
				 mueble.tipo_valor2=REALMUEBLES;
				 mueble.valor2.valor_real=(yyvsp[-4].c_expresion).valor;
			}else{
				mueble.tipo_valor2=ENTEROMUEBLES;
				mueble.valor2.valor_entero=(yyvsp[-4].c_expresion).valor;
			}
			strcpy(mueble.color, (yyvsp[-2].c_cadena));
        		mueblesTable.addMueble(mueble);
			
		}
#line 1781 "expresiones.c" /* yacc.c:1646  */
    break;

  case 28:
#line 394 "expresiones.y" /* yacc.c:1646  */
    { cout << "Mueble: " << (yyvsp[-9].c_cadena) << " con forma " <<(yyvsp[-6].c_cadena)<<" de radio: "<<(yyvsp[-4].c_expresion).valor<<" y color: "<<(yyvsp[-2].c_cadena)<<endl; 
				MuebleInfo mueble;
				strcpy(mueble.nombre, (yyvsp[-9].c_cadena));
				mueble.tipo = CIRCULO;
				if((yyvsp[-4].c_expresion).esReal){
					 mueble.tipo_valor1=REALMUEBLES;
					 mueble.valor1.valor_real=(yyvsp[-4].c_expresion).valor;
				}else{
					mueble.tipo_valor1=ENTEROMUEBLES;
					mueble.valor1.valor_entero=(yyvsp[-4].c_expresion).valor;
				}
				strcpy(mueble.color, (yyvsp[-2].c_cadena));
				mueblesTable.addMueble(mueble);		
	}
#line 1800 "expresiones.c" /* yacc.c:1646  */
    break;

  case 39:
#line 426 "expresiones.y" /* yacc.c:1646  */
    {cout<<"Habitacion detectada"<<endl;fprintf(archivo, "\tnuevaHabitacionAmu(%s, %f, %f);\n", (yyvsp[-1].c_mensaje), (yyvsp[-5].c_expresion).valor, (yyvsp[-3].c_expresion).valor);}
#line 1806 "expresiones.c" /* yacc.c:1646  */
    break;

  case 40:
#line 426 "expresiones.y" /* yacc.c:1646  */
    {cout<<"Fin Habitacion"<<endl;fprintf(archivo, "\tpausaAmu(%.2f);\n", 1.5);		
	}
#line 1813 "expresiones.c" /* yacc.c:1646  */
    break;

  case 45:
#line 437 "expresiones.y" /* yacc.c:1646  */
    { if (condicional) { cout<<"Instruccion "<<(yyvsp[-8].c_cadena)<<" "<<(yyvsp[-6].c_cadena)<<" en la fila: "<<(yyvsp[-4].c_expresion).valor<<" en la columna: "<<(yyvsp[-2].c_expresion).valor<<endl; printMuebles((yyvsp[-6].c_cadena), (yyvsp[-4].c_expresion).valor, (yyvsp[-2].c_expresion).valor);}}
#line 1819 "expresiones.c" /* yacc.c:1646  */
    break;

  case 46:
#line 438 "expresiones.y" /* yacc.c:1646  */
    { if (condicional) { cout<<"se ha detectado un mensaje: "<< (yyvsp[-2].c_mensaje)<<endl;   fprintf(archivo, "\t// %s\n", (yyvsp[-2].c_mensaje)) ;}}
#line 1825 "expresiones.c" /* yacc.c:1646  */
    break;

  case 47:
#line 439 "expresiones.y" /* yacc.c:1646  */
    { if (condicional) { cout<<"se ha detectado una "<<(yyvsp[-4].c_cadena)<<" de "<<(yyvsp[-2].c_expresion).valor<<" segundos"<<endl;fprintf(archivo, "\tpausaAmu(%.2f);\n", (yyvsp[-2].c_expresion).valor);}}
#line 1831 "expresiones.c" /* yacc.c:1646  */
    break;

  case 48:
#line 440 "expresiones.y" /* yacc.c:1646  */
    { if (condicional) { 
					cout << "Variable con id: "<< (yyvsp[-3].c_cadena)<<" y con valor " << (yyvsp[-1].c_expresion).valor << endl; 
					 if (errorSemantico) {
						manejarErrores(cont);
					    } else {
						IdentifierInfo nuevoIdentificador;

						if ((yyvsp[-1].c_expresion).esReal) {
						    nuevoIdentificador.tipo = 1;
						    nuevoIdentificador.valor.valor_real = (yyvsp[-1].c_expresion).valor;
						} else {
						    nuevoIdentificador.tipo = 0;
						    nuevoIdentificador.valor.valor_entero = (yyvsp[-1].c_expresion).valor;
						}
						strcpy(nuevoIdentificador.identificador, (yyvsp[-3].c_cadena));
						identifiersTable.addIdentifier(nuevoIdentificador);
			    }
	}condicional=true;
	}
#line 1855 "expresiones.c" /* yacc.c:1646  */
    break;

  case 49:
#line 459 "expresiones.y" /* yacc.c:1646  */
    { if (condicional) { 
						cout << "Variable bool con id: "<< (yyvsp[-3].c_cadena)<<" y con valor: "<< (yyvsp[-1].c_logica).bandera ; 

						if (errorSemantico) {
						manejarErrores(cont);
					    } else {
						IdentifierInfo nuevoIdentificador;

						
						    nuevoIdentificador.tipo = 2;
						    nuevoIdentificador.valor.valor_bool = (yyvsp[-1].c_logica).bandera;
						
						
						strcpy(nuevoIdentificador.identificador, (yyvsp[-3].c_cadena));
						identifiersTable.addIdentifier(nuevoIdentificador);
			    }
		}
	}
#line 1878 "expresiones.c" /* yacc.c:1646  */
    break;

  case 51:
#line 481 "expresiones.y" /* yacc.c:1646  */
    { if (!condicional) { cout<<"Instruccion "<<(yyvsp[-8].c_cadena)<<" "<<(yyvsp[-6].c_cadena)<<" en la fila: "<<(yyvsp[-4].c_expresion).valor<<" en la columna: "<<(yyvsp[-2].c_expresion).valor<<endl; printMuebles((yyvsp[-6].c_cadena), (yyvsp[-4].c_expresion).valor, (yyvsp[-2].c_expresion).valor);} }
#line 1884 "expresiones.c" /* yacc.c:1646  */
    break;

  case 52:
#line 482 "expresiones.y" /* yacc.c:1646  */
    { if (!condicional) { cout<<"se ha detectado un mensaje: "<< (yyvsp[-2].c_mensaje)<<endl;   fprintf(archivo, "\t// %s\n", (yyvsp[-2].c_mensaje)) ;}}
#line 1890 "expresiones.c" /* yacc.c:1646  */
    break;

  case 53:
#line 483 "expresiones.y" /* yacc.c:1646  */
    { if (!condicional) { cout<<"se ha detectado una "<<(yyvsp[-4].c_cadena)<<" de "<<(yyvsp[-2].c_expresion).valor<<" segundos"<<endl;fprintf(archivo, "\tpausaAmu(%.2f);\n", (yyvsp[-2].c_expresion).valor);}}
#line 1896 "expresiones.c" /* yacc.c:1646  */
    break;

  case 54:
#line 484 "expresiones.y" /* yacc.c:1646  */
    { if (!condicional) { 
					cout << "Variable con id: "<< (yyvsp[-3].c_cadena)<<" y con valor " << (yyvsp[-1].c_expresion).valor << endl; 
					 if (errorSemantico) {
						manejarErrores(cont);
					    } else {
						IdentifierInfo nuevoIdentificador;

						if ((yyvsp[-1].c_expresion).esReal) {
						    nuevoIdentificador.tipo = 1;
						    nuevoIdentificador.valor.valor_real = (yyvsp[-1].c_expresion).valor;
						} else {
						    nuevoIdentificador.tipo = 0;
						    nuevoIdentificador.valor.valor_entero = (yyvsp[-1].c_expresion).valor;
						}
						strcpy(nuevoIdentificador.identificador, (yyvsp[-3].c_cadena));
						identifiersTable.addIdentifier(nuevoIdentificador);
			    }
	}
	}
#line 1920 "expresiones.c" /* yacc.c:1646  */
    break;

  case 55:
#line 503 "expresiones.y" /* yacc.c:1646  */
    { if (!condicional) { 
						cout << "Variable bool con id: "<< (yyvsp[-3].c_cadena)<<" y con valor: "<< (yyvsp[-1].c_logica).bandera ; 

						if (errorSemantico) {
						manejarErrores(cont);
					    } else {
						IdentifierInfo nuevoIdentificador;

						
						    nuevoIdentificador.tipo = 2;
						    nuevoIdentificador.valor.valor_bool = (yyvsp[-1].c_logica).bandera;
						
						
						strcpy(nuevoIdentificador.identificador, (yyvsp[-3].c_cadena));
						identifiersTable.addIdentifier(nuevoIdentificador);
			    }
		}
	}
#line 1943 "expresiones.c" /* yacc.c:1646  */
    break;

  case 56:
#line 525 "expresiones.y" /* yacc.c:1646  */
    {condicional=(yyvsp[-1].c_logica).bandera;}
#line 1949 "expresiones.c" /* yacc.c:1646  */
    break;

  case 57:
#line 525 "expresiones.y" /* yacc.c:1646  */
    { cout << "detectado un condicional" << endl; condicional=true;}
#line 1955 "expresiones.c" /* yacc.c:1646  */
    break;

  case 60:
#line 532 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_expresion).esReal = false; (yyval.c_expresion).valor = (yyvsp[0].c_entero);}
#line 1961 "expresiones.c" /* yacc.c:1646  */
    break;

  case 61:
#line 533 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_expresion).esReal = true; (yyval.c_expresion).valor = (yyvsp[0].c_real); }
#line 1967 "expresiones.c" /* yacc.c:1646  */
    break;

  case 62:
#line 534 "expresiones.y" /* yacc.c:1646  */
    { IdentifierInfo nuevoIdentificador;
		nuevoIdentificador.tipo=-1;
		nuevoIdentificador=identifiersTable.searchIdentifier((yyvsp[0].c_cadena));
		if(nuevoIdentificador.tipo == -1){
			cout<<"error, "<<(yyvsp[0].c_cadena)<<" no existe"<<endl;
			Encontrado=true;
		}else{
			if (nuevoIdentificador.tipo==0){
				(yyval.c_expresion).esReal=false;
				(yyval.c_expresion).valor=nuevoIdentificador.valor.valor_entero;
			}
			if (nuevoIdentificador.tipo==1){
				(yyval.c_expresion).esReal=true;
				(yyval.c_expresion).valor=nuevoIdentificador.valor.valor_real;
			}
			if (nuevoIdentificador.tipo==2){
				cout<<"Error semántico en la instrucción "<<cont <<": variables de tipo lógico no pueden aparecer en la parte derecha de una asignación"<<endl;
			Encontrado=true;
				
			}
		}	
		}
#line 1994 "expresiones.c" /* yacc.c:1646  */
    break;

  case 63:
#line 557 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_expresion).valor = (yyvsp[-2].c_expresion).valor + (yyvsp[0].c_expresion).valor; (yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal; }
#line 2000 "expresiones.c" /* yacc.c:1646  */
    break;

  case 64:
#line 558 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_expresion).valor = (yyvsp[-2].c_expresion).valor - (yyvsp[0].c_expresion).valor; (yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal;}
#line 2006 "expresiones.c" /* yacc.c:1646  */
    break;

  case 65:
#line 559 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_expresion).valor = (yyvsp[-2].c_expresion).valor * (yyvsp[0].c_expresion).valor; (yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal;}
#line 2012 "expresiones.c" /* yacc.c:1646  */
    break;

  case 66:
#line 560 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_expresion).esReal = true; 				
				if((yyvsp[0].c_expresion).valor==0){
					errorSemantico = true;
					divisionRealCero=true;
				}else {
					 (yyval.c_expresion).valor = (yyvsp[-2].c_expresion).valor / (yyvsp[0].c_expresion).valor;
				}
			}
#line 2025 "expresiones.c" /* yacc.c:1646  */
    break;

  case 67:
#line 568 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal; 				
				if((yyval.c_expresion).esReal){
					errorSemantico = true;
					divEnt = true;
				}else {
					if((yyvsp[0].c_expresion).valor==0){
						errorSemantico = true;
						divisionRealCero=true;
				}else {
					
					 (yyval.c_expresion).valor =floor( (yyvsp[-2].c_expresion).valor / (yyvsp[0].c_expresion).valor);
				}
				}
			}
#line 2044 "expresiones.c" /* yacc.c:1646  */
    break;

  case 68:
#line 582 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal;
				if((yyval.c_expresion).esReal){
					errorSemantico = true;
					porcentaje=true;
				}
				else{
					(yyval.c_expresion).valor = fmod((yyvsp[-2].c_expresion).valor,(yyvsp[0].c_expresion).valor);
				}
	}
#line 2058 "expresiones.c" /* yacc.c:1646  */
    break;

  case 69:
#line 591 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_expresion).valor = -(yyvsp[0].c_expresion).valor;}
#line 2064 "expresiones.c" /* yacc.c:1646  */
    break;

  case 70:
#line 592 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_expresion).valor = (yyvsp[-1].c_expresion).valor;}
#line 2070 "expresiones.c" /* yacc.c:1646  */
    break;

  case 71:
#line 596 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_logica).bandera = true;}
#line 2076 "expresiones.c" /* yacc.c:1646  */
    break;

  case 72:
#line 597 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_logica).bandera = false;}
#line 2082 "expresiones.c" /* yacc.c:1646  */
    break;

  case 73:
#line 598 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_logica).bandera=((yyvsp[-2].c_logica).bandera==(yyvsp[0].c_logica).bandera);}
#line 2088 "expresiones.c" /* yacc.c:1646  */
    break;

  case 74:
#line 599 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_logica).bandera=((yyvsp[-2].c_logica).bandera!=(yyvsp[0].c_logica).bandera);}
#line 2094 "expresiones.c" /* yacc.c:1646  */
    break;

  case 75:
#line 600 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_logica).bandera=((yyvsp[-2].c_logica).bandera && (yyvsp[0].c_logica).bandera);}
#line 2100 "expresiones.c" /* yacc.c:1646  */
    break;

  case 76:
#line 601 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_logica).bandera=((yyvsp[-2].c_logica).bandera || (yyvsp[0].c_logica).bandera);}
#line 2106 "expresiones.c" /* yacc.c:1646  */
    break;

  case 77:
#line 602 "expresiones.y" /* yacc.c:1646  */
    { (yyval.c_logica).bandera = !(yyvsp[0].c_logica).bandera ;}
#line 2112 "expresiones.c" /* yacc.c:1646  */
    break;

  case 78:
#line 603 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_logica).bandera = ((yyvsp[-2].c_expresion).valor <= (yyvsp[0].c_expresion).valor);}
#line 2118 "expresiones.c" /* yacc.c:1646  */
    break;

  case 79:
#line 604 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_logica).bandera = ((yyvsp[-2].c_expresion).valor >= (yyvsp[0].c_expresion).valor);}
#line 2124 "expresiones.c" /* yacc.c:1646  */
    break;

  case 80:
#line 605 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_logica).bandera = ((yyvsp[-2].c_expresion).valor < (yyvsp[0].c_expresion).valor);}
#line 2130 "expresiones.c" /* yacc.c:1646  */
    break;

  case 81:
#line 606 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_logica).bandera = ((yyvsp[-2].c_expresion).valor > (yyvsp[0].c_expresion).valor);}
#line 2136 "expresiones.c" /* yacc.c:1646  */
    break;

  case 82:
#line 607 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_logica).bandera = ((yyvsp[-2].c_expresion).valor == (yyvsp[0].c_expresion).valor);}
#line 2142 "expresiones.c" /* yacc.c:1646  */
    break;

  case 83:
#line 608 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_logica).bandera = ((yyvsp[-2].c_expresion).valor != (yyvsp[0].c_expresion).valor);}
#line 2148 "expresiones.c" /* yacc.c:1646  */
    break;

  case 84:
#line 609 "expresiones.y" /* yacc.c:1646  */
    {(yyval.c_logica).bandera = (yyvsp[-1].c_logica).bandera;}
#line 2154 "expresiones.c" /* yacc.c:1646  */
    break;


#line 2158 "expresiones.c" /* yacc.c:1646  */
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 612 "expresiones.y" /* yacc.c:1906  */




void escribirBloqueInicial(FILE *archivo) {
    if (archivo) {
        fprintf(archivo, "// Traducción del lenguaje AMUEBLA\n");
        fprintf(archivo, "#include \"amuebla.h\"\n");
        fprintf(archivo, "#include <allegro5/allegro5.h>\n\n");
        fprintf(archivo, "using namespace std;\n\n");
        fprintf(archivo, "int main(int argc, char *argv[]) {\n");
        fprintf(archivo, "\t// Se inicia el entorno gráfico\n");
        fprintf(archivo, "\tiniciarAmu();\n");
        fprintf(archivo, "\tpausaAmu(1.5);\n");
	fprintf(archivo, "\n\n");
    } else {
        cerr << "Error: el archivo no está abierto para escritura." << endl;
    }
}

void escribirBloqueFinal(FILE *archivo) {
	 if (archivo) {
        	 fprintf(archivo, "\t// Se liberan los recursos del entorno gráfico\n");
		fprintf(archivo, "\tterminarAmu();\n");
		fprintf(archivo, "\treturn 0;\n");
		fprintf(archivo, "}\n");
    } else {
        cerr << "Error: el archivo no está abierto para escritura." << endl;
    }
}

int main(int argc, char *argv[]){

 n_lineas = 0;
	

    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <fichero_entrada> <fichero_salida>" << endl;
        return 1;
    }

    yyin = fopen(argv[1], "r");  // Abrir el archivo de entrada

    if (yyin == nullptr) {
        cerr << "Error al abrir el archivo de entrada: " << argv[1] << endl;
        return 1;
    }

    
    archivo = fopen(argv[2], "w"); 

	escribirBloqueInicial(archivo);

    yyparse(); 



    fclose(yyin);  // Cerrar el archivo de entrada

	//identifiersTable.printIdentifiersInfo(archivo);

	escribirBloqueFinal(archivo);

    return 0;

} 


