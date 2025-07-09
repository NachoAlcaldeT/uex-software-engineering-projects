#include <iostream>
#include "pr_tablero.h"
#include "TADTablero.h"
#include "TADbaraja.h"
#include "TADcarta.h"
using namespace std;

void pruebaIniciarTablero(){
	cout<<"Inicio de prueba iniciar tablero y numero de columnas:"<<endl;
	tablero t;
	baraja b;
	iniciarBaraja(b);
	int columnas; columnas=3;
	iniciarTablero(t,columnas);
	cout<<"Si el tablero esta bien inciado el numero de columnas debe ser igual a 3 y es:"<<numColumnas(t)<<endl;
	cout<<"Fin de prueba iniciar tablero y numero de columnas"<<endl<<endl;
}

void pruebaCartasRestantes(){
	cout<<"Inicio de prueba cartas restantes"<<endl;
	baraja b;
	iniciarBaraja(b);
	carta c1,c2,c3;
	quitarCarta(c1,b);
	quitarCarta(c2,b);
	quitarCarta(c3,b);
	cout<<"Ahora la baraja deberia tener 78 cartas y tiene:"<<cartasRestantes(b)<<endl<<endl;
}

void pruebaObtenerCarta(){
	cout<<"Inicio de prueba obtener carta"<<endl;
	tablero t;
	carta c;
	baraja b;
	iniciarBaraja(b);
	int filas, columnas; filas=1; columnas=3;
	iniciarTablero(t,columnas);
	anadirCarta(t,c,filas,columnas);
	cout<<"La carta obtenida deberia de ser ";
	mostrarCartaDelTablero(t, c, filas, columnas);
	cout<<", y es: ";
	obtenerCarta(t, c, filas, columnas);
	cout<<obtenerNumero(c)<<obtenerForma (c)<<obtenerColor (c)<<obtenerRelleno(c);
	cout<<"Fin de pruebas obtener carta"<<endl<<endl;
}

void pruebaObtenerCaracteristicas (){
	cout<<"Inicio de prueba cartas restantes"<<endl;
	tablero t;
	carta c;
	baraja b;
	iniciarBaraja(b);
	int numero, forma, color, relleno;
	int filas, columnas; filas=1; columnas=3;
	iniciarTablero(t, columnas);
	anadirCarta(t,c,filas,columnas);
	cout<<"Las caracteristicas de la carta obtenida deberian de ser  ";
	mostrarCartaDelTablero(t, c, filas, columnas);
	cout<<", y son: ";
	obtenerCaracteristicas(t, c, numero, forma, color, relleno);
	cout<<numero;
	cout<<forma;
	cout<<color;
	cout<<relleno;
}

void pruebaSeleccionarCarta(){
	cout<<"Inicio de prueba seleccion de cartas"<<endl;
	tablero t;
	carta c;
	baraja b;
	iniciarBaraja(b);
	int filas,columnas; filas=2; columnas=4;
	iniciarTablero(t, columnas);
	anadirCarta(t,c,filas,columnas);
	seleccionarCarta(t,filas,columnas);
	cout<<"Si la carta esta seleccionada deberia devolver true y devuelve:";
	obtenerSeleccionada(t,filas,columnas);
	cout<<"Fin de prueba seleccionar carta"<<endl<<endl;
}

void pruebaObtenerSeleccionada(){
	cout<<"Inicio de prueba seleccion de cartas"<<endl;
	tablero t;
	baraja b;
	iniciarBaraja(b);
	int filas,columna; filas=2; columna=4;
	iniciarTablero(t, columna);
	cout<<"Si esta la carta seleccionada deberia de salir true y sale: ";
	seleccionarCarta(t, filas, columna);
	cout<<endl;
	cout<<"Fin de prueba obtener seleccionar"<<endl<<endl;

}

void pruebaAnadirCarta(){
	cout<<"Inicio de prueba añadir carta"<<endl;
	tablero t;
	carta c;
	baraja b;
	iniciarBaraja(b);
	int numero, forma, color, relleno;
	int filas,columna; filas=1; columna=1;
	iniciarTablero(t,columna);
	anadirCarta(t, c, filas, columna);
	obtenerCaracteristicas(t, c, numero, forma, color, relleno);
	cout<<"Si la carta ha sido añadida, la posicion debera contener"<<numero<<forma<<color<<relleno<<" y realmente contiene: ";
	mostrarCartaDelTablero (t, c, filas, columna);
	cout<<"Fin de la prueba añadir  carta"<<endl<<endl;
}

void pruebaComprobarSet(){
	cout<<"Inicio de prueba comprobar set"<<endl;
	tablero t;
	baraja b;
	carta c1, c2, c3, c4, c5, c6;
	iniciarBaraja(b);
	int columnas; columnas=3;
	iniciarTablero(t, columnas);
	crearCarta(c1, 1, 2, 3, 2);
	crearCarta(c2, 3, 2, 3, 2);
	crearCarta(c3, 2, 2, 3, 2);
	seleccionar(c1);
	seleccionar(c2);
	seleccionar(c3);
	seleccionar(c4);
	seleccionar(c5);
	seleccionar(c6);

	cout<<"Las cartas c1, c2 y c3 forman set, por tanto deberia devolver true y devuelve: "<<endl;
	comprobarSet(t, c1, c2, c3);

	crearCarta(c4, 1, 1, 3, 2);
	crearCarta(c5, 3, 2, 1, 3);
	crearCarta(c6, 2, 1, 3, 2);
	cout<<"Las cartas c4, 5 y c6 no forman set, por tanto deberia devolver false y devuelve: "<<endl;
	comprobarSet(t, c4, c5, c6);
	cout<<"Fin de las prueba comprobar set";





}

