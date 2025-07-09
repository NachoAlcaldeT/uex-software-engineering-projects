#ifndef TADTablero_H_
#define TADTablero_H_
#include "TADcarta.h"
#include "TADbaraja.h"


const int FILA=3;
const int COLUMNA=5;
typedef carta matriz[FILA][COLUMNA];


struct tablero {
	matriz mTablero;
	 int columnas;
};

/*
 * PRE:  {t inicializada }
 * POST: {inicia el tablero asignando el numero de columnas correspondientes}
 * COMPLEJIDAD:(1)
 */
void iniciarTablero  (tablero &t, int columnas);

/*
 * PRE:  {t inicializada}
 * POST: {Devuelve el numero de columnas que hay en el tablero}
 * COMPLEJIDAD:(1)
 */
int numColumnas  (tablero t);

/*
 * PRE:  {b inicializada }
 * POST: {Devueve el numero de cartas restantes en la baraja }
 * COMPLEJIDAD:(1)
 */
int cartasRestantes (baraja b);

/*
 * PRE:  {t y c inicializadas }
 * POST: {Obtiene una carta determinada del tablero}
 * COMPLEJIDAD:(1)
 */
void obtenerCarta (tablero t, carta &c, int fila, int columna);

/*
 * PRE:  {t y c inicializada}
 * POST: {Obtiene las caracteristicas de una carta determinada}
 * COMPLEJIDAD:(1)
 */
void obtenerCaracteristicas (tablero t, carta c, int &numero, int &forma, int &color, int &relleno);

/*
 * PRE:  {t inicializada }
 * POST: {Selecciona una carta deterimnada del tablero}
 * COMPLEJIDAD:(1)
 */
void seleccionarCarta (tablero &t, int fila, int columnas);

/*
 * PRE:  {t inicializada}
 * POST: {Deja de seleccionar una carta determinada del tablero}
 * COMPLEJIDAD:(1)
 */
void noSeleccionarCarta (tablero &t, int fila, int columnas);
/*
 * PRE:  {t inicializada}
 * POST: {Obtiene si una carta del tablero esta seleccionada o no}
 * COMPLEJIDAD:(1)
 */

bool obtenerSeleccionada (tablero t,int fila, int columna);

/*
 * PRE:  {t inicializada }
 * POST: {Añade una carta determinada al tablero}
 * COMPLEJIDAD:(1)
 */

void anadirCarta (tablero &t, carta c, int fila, int columnas);

/*
 * PRE:  {t,c1,c2 y c3 inicializadas }
 * POST: {Comprueba si las tres cartas seleccionadas por el usuario forman set o no}
 * COMPLEJIDAD:
 */

bool comprobarSet (tablero t, carta c1, carta c2, carta c3);

/*
 * PRE:  {t inicializada }
 * POST: {Muestra una carta determinada deterinada del tablero}
 * COMPLEJIDAD:(1)
 */

void mostrarCartaDelTablero (tablero t, carta c, int fila, int columna);


#endif /* TADbaraja_H_ */

