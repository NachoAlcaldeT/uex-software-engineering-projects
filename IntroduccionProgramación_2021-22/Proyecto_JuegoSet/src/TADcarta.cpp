#include "TADcarta.h"
#include "TADbaraja.h"

void crearCarta (carta &c,int forma,int color,int relleno,int numero){

	c.forma=forma;
	c.color=color;
	c.relleno=relleno;
	c.numero=numero;
	c.seleccionar=false;

}

int  obtenerNumero (carta c){
	return c.numero;
}

int   obtenerForma (carta c){
	return c.forma;
}

int  obtenerColor  (carta c){
	return c.color;
}

int  obtenerRelleno (carta c){
	return c.relleno;
}

void seleccionar (carta &c){
	c.seleccionar=true;
}

void noSeleccionar (carta &c){
	c.seleccionar=false;
}

bool estaSeleccionada(carta c){
	return c.seleccionar;
}


