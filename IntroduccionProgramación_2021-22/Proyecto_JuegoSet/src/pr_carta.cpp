#include <iostream>

#include "pr_carta.h"
using namespace std;

void pruebaCarta(){
	carta c1, c2;
	cout << "Inicio prueba automatica carta"<<endl;

	crearCarta(c1,1,2,3,2);
	if (obtenerForma(c1) != 1){
		cout << "Error en el forma de la carta c1"<<endl;
	}

	if (obtenerColor(c1) != 2){
		cout << "Error en la color de la carta c1"<<endl;
	}
	if (obtenerRelleno(c1) != 3){
		cout << "Error en el relleno de la carta c1"<<endl;
	}
	if (obtenerNumero(c1) != 2){
		cout << "Error en el numero de la carta c1"<<endl;
	}


	// prueba supervisada, usuamos el módulo mostrar para comprobar que la carta se ha creado correctamente
	crearCarta(c2,2,1,1,3);
	if (obtenerForma(c2) != 2){
		cout << "Error en el forma de la carta c2"<<endl;
	}

	if (obtenerColor(c2) != 1){
		cout << "Error en la color de la carta c2"<<endl;
	}
	if (obtenerRelleno(c2) != 1){
		cout << "Error en el relleno de la carta c2"<<endl;
	}
	if (obtenerNumero(c2) != 3){
		cout << "Error en el numero de la carta c2"<<endl;
	}
	cout<<"Fin de la prueba carta";
}
