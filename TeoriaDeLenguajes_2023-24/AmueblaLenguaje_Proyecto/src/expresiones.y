%{

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




%}



%union{

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
}



%start entrada
%token <c_real> REAL
%token <c_entero> ENTERO
%token <c_cadena> Nombre
%token <c_cadena> IDVAB
%token <c_cadena> rectangulo
%token <c_cadena> circulo

%token VARIABLES
%token MUEBLES
%token HABITACION
%token <c_cadena> Enterovab
%token <c_cadena> Realvab
%token <c_cadena> Boolvab
%token IGUALMUEBLES
%token <c_cadena>negro
%token <c_cadena>amarillo
%token <c_cadena>gris
%token <c_cadena>rojo
%token <c_cadena>azul
%token <c_cadena>marron
%token <c_cadena>verde
%token PUNTOS
%token FINHABITACION
%token <c_cadena>situar
%token <c_cadena>mensaje
%token <c_cadena>pausa
%token <c_mensaje>CADENA

%token ASIG
%token DIVENT
%token MENORIGUAL
%token MAYORIGUAL
%token MENOR
%token MAYOR
%token DISTINTO
%token IGUAL
%token CIERTO
%token FALSO
%token no
%token si
%token si_no
%token y
%token o
%type <c_expresion> expr
%type <c_logica> expr_logica
%type <c_cadena> color
%type <c_expresion> valor

%left o
%left y 
%left IGUAL DISTINTO
%left MENOR MENORIGUAL MAYORIGUAL MAYOR
%left '+' '-'   
%left '*' '/' DIVENT '%' 
%left menosunario
%left no







%%


entrada:  blVars blMuebles Habitaciones
	| salto blVars blMuebles Habitaciones
	;

  
blVars:
	| VARIABLES {cout<<"Bloque de variables detectado"<<endl;} salto secDefVars 
	;

secDefVars: defVar
	| secDefVars defVar
	;

defVar: Enterovab identificadoresEntero salto	{cout<<"Variables de tipo "<<$1<<" detectadas"<< endl;}
	| Realvab identificadoresReal salto		{cout<<"Variables de tipo "<<$1<<" detectadas"<< endl;}
	| Boolvab identificadoresBool salto		{cout<<"Variables de tipo "<<$1<<" detectadas"<< endl;}
	| Enterovab IDVAB ASIG expr salto   { cout << "Variable de tipo " << $1 << " declarada e inicializada con id: "<< $2<<" y con valor " << $4.valor << endl; 
						 if (errorSemantico) {
							manejarErrores(cont);
						 } else {
							IdentifierInfo nuevoIdentificador;
							nuevoIdentificador.tipo = 0;
							nuevoIdentificador.valor.valor_entero = $4.valor;
							strcpy(nuevoIdentificador.identificador, $2);
							identifiersTable.addIdentifier(nuevoIdentificador);
		}
	}		      
	| Realvab IDVAB ASIG expr salto		{ cout << "Variable de tipo " << $1 << " declarada e inicializada con id: "<< $2<<" y con valor " << $4.valor << endl; 
						 if (errorSemantico) {
							manejarErrores(cont);
						 } else {
							IdentifierInfo nuevoIdentificador;
							nuevoIdentificador.tipo = 1;
							nuevoIdentificador.valor.valor_real = $4.valor;
							strcpy(nuevoIdentificador.identificador, $2);
							identifiersTable.addIdentifier(nuevoIdentificador);
						}
	}
        | Boolvab IDVAB ASIG expr_logica salto	{ cout << "Variable de tipo " << $1 << " declarada e inicializada con id: "<< $2<<" y con valor " << $4.bandera << endl; 
						if (errorSemantico) {
							manejarErrores(cont);
						 } else {
							IdentifierInfo nuevoIdentificador;
							nuevoIdentificador.tipo = 2;
							nuevoIdentificador.valor.valor_bool = $4.bandera;
							strcpy(nuevoIdentificador.identificador, $2);
							identifiersTable.addIdentifier(nuevoIdentificador);
						}
	}
	| IDVAB ASIG expr salto			{ cout << "Variable con id: "<< $1<<" y con valor " << $3.valor << endl; 
					
						if (errorSemantico) {
						manejarErrores(cont);
					    } else {
						IdentifierInfo nuevoIdentificador;

						if ($3.esReal) {
						    nuevoIdentificador.tipo = 1;
						    nuevoIdentificador.valor.valor_real = $3.valor;
						} else {
						    nuevoIdentificador.tipo = 0;
						    nuevoIdentificador.valor.valor_entero = $3.valor;
						}
						strcpy(nuevoIdentificador.identificador, $1);
						identifiersTable.addIdentifier(nuevoIdentificador);
			    }
						
	}
	| IDVAB ASIG expr_logica salto		{ cout << "Variable bool con id: "<< $1<<" y con valor: "<< $3.bandera ; 

						if (errorSemantico) {
						manejarErrores(cont);
					    } else {
						IdentifierInfo nuevoIdentificador;

						
						    nuevoIdentificador.tipo = 2;
						    nuevoIdentificador.valor.valor_bool = $3.bandera;
						
						
						strcpy(nuevoIdentificador.identificador, $1);
						identifiersTable.addIdentifier(nuevoIdentificador);
			    }
	}
	;


identificadoresEntero: IDVAB ',' identificadoresEntero { cout << "ID: " << $1 << endl; 
							if (errorSemantico) {
							manejarErrores(cont);
						 } else {
							IdentifierInfo nuevoIdentificador;
							nuevoIdentificador.tipo = 0;
							nuevoIdentificador.valor.valor_entero = -1; //valor por defecto
							strcpy(nuevoIdentificador.identificador, $1);
							identifiersTable.addIdentifier(nuevoIdentificador);
						}
							
		}
               | IDVAB { cout << "ID: " << $1 << endl; 
			if (errorSemantico) {
				manejarErrores(cont);
			 } else {
				IdentifierInfo nuevoIdentificador;
				nuevoIdentificador.tipo = 0;
				nuevoIdentificador.valor.valor_entero = -1; //valor por defecto
				strcpy(nuevoIdentificador.identificador, $1);
				identifiersTable.addIdentifier(nuevoIdentificador);
			}
		}
               ;

identificadoresReal: IDVAB ',' identificadoresReal { cout << "ID: " << $1 << endl; 
						if (errorSemantico) {
							manejarErrores(cont);
						 } else {
							IdentifierInfo nuevoIdentificador;
							nuevoIdentificador.tipo = 1;
							nuevoIdentificador.valor.valor_entero = -1.0; //valor por defecto
						strcpy(nuevoIdentificador.identificador, $1);
						identifiersTable.addIdentifier(nuevoIdentificador);
						}
						
		}
               | IDVAB { cout << "ID: " << $1 << endl; 
			if (errorSemantico) {
				manejarErrores(cont);
			 } else {
				IdentifierInfo nuevoIdentificador;
				nuevoIdentificador.tipo = 1;
				nuevoIdentificador.valor.valor_entero = -1.0; //valor por defecto
				strcpy(nuevoIdentificador.identificador, $1);
				identifiersTable.addIdentifier(nuevoIdentificador);
			}
		}
               ;

identificadoresBool: IDVAB ',' identificadoresBool { cout << "ID: " << $1 << endl; 
						if (errorSemantico) {
							manejarErrores(cont);
						 } else {
							IdentifierInfo nuevoIdentificador;
							nuevoIdentificador.tipo = 2;
							nuevoIdentificador.valor.valor_bool = false; //valor por defecto
							strcpy(nuevoIdentificador.identificador, $1);
							identifiersTable.addIdentifier(nuevoIdentificador);
						}
		}
               | IDVAB { cout << "ID: " << $1 << endl; 
			if (errorSemantico) {
				manejarErrores(cont);
			} else {
				IdentifierInfo nuevoIdentificador;
				nuevoIdentificador.tipo = 2;
				nuevoIdentificador.valor.valor_bool = false; //valor por defecto
				strcpy(nuevoIdentificador.identificador, $1);
				identifiersTable.addIdentifier(nuevoIdentificador);
			}
		}
               ;
 
blMuebles: MUEBLES {cout<<"Bloque de muebles detectado"<<endl;} salto secDefMbls
	;


secDefMbls: defMbls
	| secDefMbls defMbls
	;

defMbls:Nombre IGUALMUEBLES MENOR rectangulo ',' valor ',' valor ',' color MAYOR salto { cout << "Mueble: " << $1 << " con forma " <<$4<<" de ancho: "<<$6.valor<<" y la altura: "<<$8.valor<<" y color: "<<$10<<endl; 
			MuebleInfo mueble;
			strcpy(mueble.nombre, $1);
			mueble.tipo = RECTANGULO;
			if($6.esReal){
				 mueble.tipo_valor1=REALMUEBLES;
				 mueble.valor1.valor_real=$6.valor;
			}else{
				mueble.tipo_valor1=ENTEROMUEBLES;
				mueble.valor1.valor_entero=$6.valor;
			}
			if($8.esReal){
				 mueble.tipo_valor2=REALMUEBLES;
				 mueble.valor2.valor_real=$8.valor;
			}else{
				mueble.tipo_valor2=ENTEROMUEBLES;
				mueble.valor2.valor_entero=$8.valor;
			}
			strcpy(mueble.color, $10);
        		mueblesTable.addMueble(mueble);
			
		}
		| Nombre IGUALMUEBLES MENOR circulo ',' valor ',' color MAYOR salto { cout << "Mueble: " << $1 << " con forma " <<$4<<" de radio: "<<$6.valor<<" y color: "<<$8<<endl; 
				MuebleInfo mueble;
				strcpy(mueble.nombre, $1);
				mueble.tipo = CIRCULO;
				if($6.esReal){
					 mueble.tipo_valor1=REALMUEBLES;
					 mueble.valor1.valor_real=$6.valor;
				}else{
					mueble.tipo_valor1=ENTEROMUEBLES;
					mueble.valor1.valor_entero=$6.valor;
				}
				strcpy(mueble.color, $8);
				mueblesTable.addMueble(mueble);		
	}
	;

color: negro
	| gris
	| verde
	| marron
	| amarillo
	| rojo
	| azul						
	;
valor:	expr
	;


Habitaciones: blHabitaciones
	| Habitaciones blHabitaciones
	;

blHabitaciones: HABITACION '(' valor ',' valor ')' CADENA PUNTOS {cout<<"Habitacion detectada"<<endl;fprintf(archivo, "\tnuevaHabitacionAmu(%s, %f, %f);\n", $7, $3.valor, $5.valor);} salto secDefHabs FINHABITACION salto{cout<<"Fin Habitacion"<<endl;fprintf(archivo, "\tpausaAmu(%.2f);\n", 1.5);		
	}
	;

secDefHabs: defHabs
	| secDefHabs defHabs
	;
secDefHabs2: defHabs2
	| secDefHabs2 defHabs2
	;

defHabs: situar '(' Nombre ',' valor ',' valor ')' salto{ if (condicional) { cout<<"Instruccion "<<$1<<" "<<$3<<" en la fila: "<<$5.valor<<" en la columna: "<<$7.valor<<endl; printMuebles($3, $5.valor, $7.valor);}}
	| mensaje '(' CADENA ')' salto { if (condicional) { cout<<"se ha detectado un mensaje: "<< $3<<endl;   fprintf(archivo, "\t// %s\n", $3) ;}}
	| pausa '(' expr ')' salto { if (condicional) { cout<<"se ha detectado una "<<$1<<" de "<<$3.valor<<" segundos"<<endl;fprintf(archivo, "\tpausaAmu(%.2f);\n", $3.valor);}}
	| IDVAB ASIG expr salto		{ if (condicional) { 
					cout << "Variable con id: "<< $1<<" y con valor " << $3.valor << endl; 
					 if (errorSemantico) {
						manejarErrores(cont);
					    } else {
						IdentifierInfo nuevoIdentificador;

						if ($3.esReal) {
						    nuevoIdentificador.tipo = 1;
						    nuevoIdentificador.valor.valor_real = $3.valor;
						} else {
						    nuevoIdentificador.tipo = 0;
						    nuevoIdentificador.valor.valor_entero = $3.valor;
						}
						strcpy(nuevoIdentificador.identificador, $1);
						identifiersTable.addIdentifier(nuevoIdentificador);
			    }
	}condicional=true;
	}  
	| IDVAB ASIG expr_logica salto	{ if (condicional) { 
						cout << "Variable bool con id: "<< $1<<" y con valor: "<< $3.bandera ; 

						if (errorSemantico) {
						manejarErrores(cont);
					    } else {
						IdentifierInfo nuevoIdentificador;

						
						    nuevoIdentificador.tipo = 2;
						    nuevoIdentificador.valor.valor_bool = $3.bandera;
						
						
						strcpy(nuevoIdentificador.identificador, $1);
						identifiersTable.addIdentifier(nuevoIdentificador);
			    }
		}
	}

	| si_bloque
	;

defHabs2: situar '(' Nombre ',' valor ',' valor ')' salto{ if (!condicional) { cout<<"Instruccion "<<$1<<" "<<$3<<" en la fila: "<<$5.valor<<" en la columna: "<<$7.valor<<endl; printMuebles($3, $5.valor, $7.valor);} }
	| mensaje '(' CADENA ')' salto { if (!condicional) { cout<<"se ha detectado un mensaje: "<< $3<<endl;   fprintf(archivo, "\t// %s\n", $3) ;}}
	| pausa '(' valor ')' salto { if (!condicional) { cout<<"se ha detectado una "<<$1<<" de "<<$3.valor<<" segundos"<<endl;fprintf(archivo, "\tpausaAmu(%.2f);\n", $3.valor);}}
	| IDVAB ASIG expr salto		{ if (!condicional) { 
					cout << "Variable con id: "<< $1<<" y con valor " << $3.valor << endl; 
					 if (errorSemantico) {
						manejarErrores(cont);
					    } else {
						IdentifierInfo nuevoIdentificador;

						if ($3.esReal) {
						    nuevoIdentificador.tipo = 1;
						    nuevoIdentificador.valor.valor_real = $3.valor;
						} else {
						    nuevoIdentificador.tipo = 0;
						    nuevoIdentificador.valor.valor_entero = $3.valor;
						}
						strcpy(nuevoIdentificador.identificador, $1);
						identifiersTable.addIdentifier(nuevoIdentificador);
			    }
	}
	}
	| IDVAB ASIG expr_logica salto	{ if (!condicional) { 
						cout << "Variable bool con id: "<< $1<<" y con valor: "<< $3.bandera ; 

						if (errorSemantico) {
						manejarErrores(cont);
					    } else {
						IdentifierInfo nuevoIdentificador;

						
						    nuevoIdentificador.tipo = 2;
						    nuevoIdentificador.valor.valor_bool = $3.bandera;
						
						
						strcpy(nuevoIdentificador.identificador, $1);
						identifiersTable.addIdentifier(nuevoIdentificador);
			    }
		}
	}
	;



si_bloque:  si '(' expr_logica ')' {condicional=$3.bandera;} '{' salto secDefHabs '}' salto si_no '{' salto secDefHabs2 '}' salto { cout << "detectado un condicional" << endl; condicional=true;}
    ;

salto: '\n'
	| salto '\n'
	;

expr: ENTERO {$$.esReal = false; $$.valor = $1;}
	|REAL {$$.esReal = true; $$.valor = $1; }
	| IDVAB { IdentifierInfo nuevoIdentificador;
		nuevoIdentificador.tipo=-1;
		nuevoIdentificador=identifiersTable.searchIdentifier($1);
		if(nuevoIdentificador.tipo == -1){
			cout<<"error, "<<$1<<" no existe"<<endl;
			Encontrado=true;
		}else{
			if (nuevoIdentificador.tipo==0){
				$$.esReal=false;
				$$.valor=nuevoIdentificador.valor.valor_entero;
			}
			if (nuevoIdentificador.tipo==1){
				$$.esReal=true;
				$$.valor=nuevoIdentificador.valor.valor_real;
			}
			if (nuevoIdentificador.tipo==2){
				cout<<"Error semántico en la instrucción "<<cont <<": variables de tipo lógico no pueden aparecer en la parte derecha de una asignación"<<endl;
			Encontrado=true;
				
			}
		}	
		}
	
	| expr '+' expr {$$.valor = $1.valor + $3.valor; $$.esReal = $1.esReal || $3.esReal; }
	| expr '-' expr {$$.valor = $1.valor - $3.valor; $$.esReal = $1.esReal || $3.esReal;}
	| expr '*' expr {$$.valor = $1.valor * $3.valor; $$.esReal = $1.esReal || $3.esReal;}
	| expr '/' expr {$$.esReal = true; 				
				if($3.valor==0){
					errorSemantico = true;
					divisionRealCero=true;
				}else {
					 $$.valor = $1.valor / $3.valor;
				}
			}
	| expr DIVENT expr {$$.esReal = $1.esReal || $3.esReal; 				
				if($$.esReal){
					errorSemantico = true;
					divEnt = true;
				}else {
					if($3.valor==0){
						errorSemantico = true;
						divisionRealCero=true;
				}else {
					
					 $$.valor =floor( $1.valor / $3.valor);
				}
				}
			}
	| expr '%' expr {$$.esReal = $1.esReal || $3.esReal;
				if($$.esReal){
					errorSemantico = true;
					porcentaje=true;
				}
				else{
					$$.valor = fmod($1.valor,$3.valor);
				}
	}
	| '-' expr %prec menosunario {$$.valor = -$2.valor;}
	| '(' expr ')' {$$.valor = $2.valor;}
	;


expr_logica: CIERTO {$$.bandera = true;}
	| FALSO {$$.bandera = false;}
	| expr_logica IGUAL expr_logica {$$.bandera=($1.bandera==$3.bandera);}
	| expr_logica DISTINTO expr_logica {$$.bandera=($1.bandera!=$3.bandera);}
	| expr_logica y expr_logica {$$.bandera=($1.bandera && $3.bandera);}
	| expr_logica o expr_logica {$$.bandera=($1.bandera || $3.bandera);}
	| no expr_logica { $$.bandera = !$2.bandera ;}
	| expr MENORIGUAL expr {$$.bandera = ($1.valor <= $3.valor);}
	| expr MAYORIGUAL expr {$$.bandera = ($1.valor >= $3.valor);}
	| expr MENOR expr {$$.bandera = ($1.valor < $3.valor);}
	| expr MAYOR expr {$$.bandera = ($1.valor > $3.valor);}
	| expr IGUAL expr {$$.bandera = ($1.valor == $3.valor);}
	| expr DISTINTO expr {$$.bandera = ($1.valor != $3.valor);}
	| '(' expr_logica ')' {$$.bandera = $2.bandera;}
	;

%%



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


