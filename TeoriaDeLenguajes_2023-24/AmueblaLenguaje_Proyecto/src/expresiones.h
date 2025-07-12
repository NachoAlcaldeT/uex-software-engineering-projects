/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 117 "expresiones.y" /* yacc.c:1909  */


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

#line 116 "expresiones.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXPRESIONES_H_INCLUDED  */
