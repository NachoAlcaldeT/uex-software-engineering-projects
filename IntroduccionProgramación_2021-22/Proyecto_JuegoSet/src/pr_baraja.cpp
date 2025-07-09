#include <iostream>
#include "pr_baraja.h"
#include "TADbaraja.h"
using namespace std;



void pruebaIniciarBaraja () {
	cout<<"inicio prueba iniciar baraja:"<<endl;
	baraja b;
	 iniciarBaraja (b);
	int i;
	for(i=0;i<MAX;i++){
		cout<<i<<"-->";
		mostrarCarta(b,i);
	}
	cout<<"Fin de la prueba iniciar baraja"<<endl<<endl;
	cout<<"Inicio prueba cuantas cartas"<<endl;

	cout<<"En la baraja debe haber 81 cartas y hay:"<<cuantasCartas(b)<<endl<<endl;
}

void pruebaQuitarCartas(){
	cout<<"Inicio prueba quitar cartas:"<<endl;
	baraja b;
	carta c;
	iniciarBaraja(b);
	quitarCarta(c,b);
	cout<<"Como le hemos quitado una carta la baraja debe tener 80 y tiene:"<<cuantasCartas(b)<<endl<<endl;
}

void pruebaMostrarCarta(){
	baraja b;
	iniciarBaraja (b);
	cout<<"Inicio de prueba mostrar carta:"<<endl;
	int posicion=1;
	cout<<"Al mostrar la carta 1 nos debera salir: 2111 y sale:";
	mostrarCarta(b, posicion);
	cout<<"Fin de pruebas mostrar carta"<<endl;
}
