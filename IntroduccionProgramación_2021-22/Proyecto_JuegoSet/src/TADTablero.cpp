#include "TADTablero.h"


void iniciarTablero(tablero &t,int columnas){
	t.columnas=columnas;
}


int numColumnas(tablero t){
	return t.columnas;
}


int cartasRestantes(baraja b){
	return cuantasCartas(b);
}


void obtenerCarta (tablero t, carta &c, int fila, int columna){
	c= t.mTablero[fila][columna];
}

void obtenerCaracteristicas (tablero t,carta c, int &numero, int &forma, int &color, int &relleno){
	numero=obtenerNumero(c);
	forma=obtenerForma(c);
	color=obtenerColor(c);
	relleno=obtenerRelleno(c);
}


void seleccionarCarta(tablero &t, int fila, int columna){
	seleccionar(t.mTablero[fila][columna]);
}

void noSeleccionarCarta(tablero &t, int fila, int columna){
	noSeleccionar(t.mTablero[fila][columna]);
}

bool obtenerSeleccionada(tablero t,int fila,int columna){

	return estaSeleccionada(t.mTablero[fila][columna]);
}




void anadirCarta (tablero &t, carta c, int fila, int columna){
	t.mTablero[fila][columna]=c;
}

bool comprobarSet(tablero t,carta c1, carta c2, carta c3){
	bool enc;
	enc=false;
	if(estaSeleccionada(c1)==true && estaSeleccionada(c2)==true && estaSeleccionada(c3)==true){
		if((obtenerColor(c1)==obtenerColor(c2)  && obtenerColor(c1)==obtenerColor(c3)) || (obtenerColor(c1)!=obtenerColor(c2) && obtenerColor(c1)!=obtenerColor(c3) && obtenerColor(c2)!=obtenerColor(c3)) ){
			if((obtenerForma(c1)==obtenerForma(c2)  && obtenerForma(c1)==obtenerForma(c3)) || (obtenerForma(c1)!=obtenerForma(c2) && obtenerForma(c1)!=obtenerForma(c3) && obtenerForma(c2)!=obtenerForma(c3)) ){
				if((obtenerNumero(c1)==obtenerNumero(c2)  && obtenerNumero(c1)==obtenerNumero(c3)) || (obtenerNumero(c1)!=obtenerNumero(c2) && obtenerNumero(c1)!=obtenerNumero(c3) && obtenerNumero(c2)!=obtenerNumero(c3)) ){
					if((obtenerRelleno(c1)==obtenerRelleno(c2)  && obtenerRelleno(c1)==obtenerRelleno(c3)) || (obtenerRelleno(c1)!=obtenerRelleno(c2) && obtenerRelleno(c1)!=obtenerRelleno(c3) && obtenerRelleno(c2)!=obtenerRelleno(c3)) ){
						enc=true;
					}
				}
			}
		}
	}

	return enc;
}

void mostrarCartaDelTablero (tablero t, carta c, int fila, int columna){
	t.mTablero[fila][columna]=c;
	cout<<obtenerNumero(c);
	cout<<obtenerForma(c);
	cout<<obtenerColor(c);
	cout<<obtenerRelleno(c);
}















