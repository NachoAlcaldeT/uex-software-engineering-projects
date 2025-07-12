%{
#include "expresiones.h"
#include <iostream>
#include <cstdlib>
#include <cstring>


using namespace std;

extern char *yytext;
extern int yylex();
void prompt();
extern int n_lineas;


%}

%option noyywrap
 

%% 

	   



[cC][iI][eE][rR][tT][oO]		return CIERTO; 
[Ff][Aa][Ll][Ss][Oo]			return FALSO; 
[V][A][R][I][A][B][L][E][S]		return VARIABLES;
[M][U][E][B][L][E][S]			return MUEBLES;
[H][A][B][I][T][A][C][I][O][N]		return HABITACION;
[F][I][N][H][A][B][I][T][A][C][I][O][N]		return FINHABITACION;
[s][i][t][u][a][r]			{strcpy(yylval.c_cadena, yytext); return situar;}
[p][a][u][s][a]				{strcpy(yylval.c_cadena, yytext); return pausa;}
[m][e][n][s][a][j][e]			{strcpy(yylval.c_cadena, yytext); return mensaje;}
[n][e][g][r][o]				{strcpy(yylval.c_cadena, yytext); return negro;}
[g][r][i][s]				{strcpy(yylval.c_cadena, yytext);return gris; }
[r][o][j][o]				{strcpy(yylval.c_cadena, yytext); return rojo; }
[a][z][u][l]				{strcpy(yylval.c_cadena, yytext); return azul; }
[a][m][a][r][i][l][l][o]		{strcpy(yylval.c_cadena, yytext); return amarillo; }
[v][e][r][d][e]				{strcpy(yylval.c_cadena, yytext); return verde; }
[m][a][r][r][o][n]			{strcpy(yylval.c_cadena, yytext); return marron;}
[c][i][r][c][u][l][o]			{strcpy(yylval.c_cadena, yytext); return circulo; }
[r][e][c][t][a][n][g][u][l][o]		{strcpy(yylval.c_cadena, yytext); return rectangulo; }
[E][n][t][e][r][o]			{strcpy(yylval.c_cadena, yytext); return Enterovab; }
[R][e][a][l]				{strcpy(yylval.c_cadena, yytext); return Realvab; }
[B][o][o][l]				{strcpy(yylval.c_cadena, yytext); return Boolvab; }
[:]					return PUNTOS;
[n][o]					return no;
[s][i]					return si;
[s][i][_][n][o]				return si_no;
[y]					return y;
[o]					return o;
[0-9]+					{yylval.c_entero = atoi(yytext); return ENTERO;}
[/][/]					return DIVENT;
[<][=]					return MENORIGUAL;
[>][=]					return MAYORIGUAL;
[>]					return MAYOR;
[<]					return MENOR;
[<][>]					return DISTINTO;
[=][=]					return IGUAL;
[=]					return IGUALMUEBLES;
[A-Z0-9_Ñ][a-zA-Z0-9_ñÑ]* 		{strcpy(yylval.c_cadena, yytext); return Nombre;}
[a-z0-9_ñ][a-zA-Z0-9_ñÑ]* 		{strcpy(yylval.c_cadena, yytext); return IDVAB;}
[0-9]+["."][0-9]*|[0-9]*["."][0-9]+|(([0-9]+[.][0-9]*)|([0-9]*[.][0-9]+))[eE][+-]?[0-9]+     	{yylval.c_real = atof(yytext); return REAL; }
[<][-]				{return ASIG;}
["][^"]*["]				{strcpy(yylval.c_cadena, yytext); return CADENA ;}
\n				{n_lineas++; return (yytext[0]);}
[\t ]				;
. 				return (yytext[0]);
[%][%].*\n			return '\n';



%%
