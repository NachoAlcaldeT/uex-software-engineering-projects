#ifndef TADcarta_H_
#define TADcarta_H_


#include <iostream>
using namespace std;

struct carta {
	int numero;
	int forma;
	int color;
	int relleno;
	bool seleccionar;
};
/*
 * PRE:  {c inicializada }
 * POST: {Crea una carta con la forma, el color, el relleno y el numero}
 * COMPLEJIDAD:(1)
 */
void crearCarta   (carta &c,int forma,int color,int relleno,int numero);
/*
 * PRE:  {c inicializada  }
 * POST: {Obtiene el numero de la carta c }
 * COMPLEJIDAD:(1)
 */
int  obtenerNumero     (carta c);
/*
 * PRE:  {c inicializada  }
 * POST: {Obtiene la forma de la carta c }
 * COMPLEJIDAD:(1)
 */
int   obtenerForma (carta c);
/*
 * PRE:  { c inicializada }
 * POST: {Obtiene el color de la carta c }
 * COMPLEJIDAD:(1)
 */
int  obtenerColor  (carta c);
/*
 * PRE:  { c incializada }
 * POST: {Obtiene el relleno de la carta c }
 * COMPLEJIDAD:(1)
 */
int  obtenerRelleno (carta c);
/*
 * PRE:  {c inicializada  }
 * POST: {Selecciona la  carta c }
 * COMPLEJIDAD:(1)
 */
void seleccionar (carta &c);
/*
 * PRE:  {c inicializada  }
 * POST: {Deja de seleccionar la carta c }
 * COMPLEJIDAD:(1)
 */
void noSeleccionar (carta &c);
/*
 * PRE:  { c inicializada }
 * POST: {Comprueba si la carta c esta seleccionada o no }
 * COMPLEJIDAD:(1)
 */
bool estaSeleccionada(carta c);




#endif /* TADcarta_H_ */
