#ifndef TADbaraja_H_
#define TADbaraja_H_
#include "TADcarta.h"


const int MAX = 81;
typedef carta TVectorcarta[MAX];


struct baraja {
	TVectorcarta vBaraja;
	int ocupadas;
};

/*
 * PRE:  {b inicializada }
 * POST: {Rellena la baraja de cartas ed diferentes caracteristicas cada una}
 * COMPLEJIDAD:(1)
 */
void iniciarBaraja    (baraja &b);

/*
 * PRE:  {b inicializada }
 * POST: {Quita una carta de la baraja b}
 * COMPLEJIDAD:(n)
 */
void quitarCarta (carta &c, baraja &b);

/*
 * PRE:  {b inicializada }
 * POST: {Devuelve el numero de cartas en la baraja}
 * COMPLEJIDAD:(1)
 */
int cuantasCartas    (baraja b);

/*
 * PRE:  {b inicializada }
 * POST: {Muestra una carta de la baraja}
 * COMPLEJIDAD:(1)
 */
void mostrarCarta (baraja b, int pos);



#endif /* TADbaraja_H_ */
