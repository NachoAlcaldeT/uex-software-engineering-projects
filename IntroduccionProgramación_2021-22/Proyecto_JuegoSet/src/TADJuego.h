#ifndef TADJuego_H_
#define TADJuego_H_
#include "TADcarta.h"
#include "TADbaraja.h"
#include "TADTablero.h"


struct juego{
	baraja b;
	tablero t;
	int puntuacion;
	int objetivo;
	int puntos_set;
};

/*
 * PRE:  {j inicializada }
 * POST: {Inicia el juego y rellena el tablero}
 * COMPLEJIDAD:(n)
 */
void iniciarJuego(juego &j);

/*
 * PRE:  {j inicializada }
 * POST: {Es el encargado del control de las teclas y por lo tanto del control del juego}
 * COMPLEJIDAD:(1)
 */
void jugar(juego &j);

/*
 * PRE:  {}
 * POST: {Termina el juego cerrando el entorno grafico}
 * COMPLEJIDAD:(1)
 */
void terminarJuego();






















#endif /* TADJuego_H_ */
