#include "TADTablero.h"
#include "TADcarta.h"
#include "TADbaraja.h"
#include "entorno.h"
#include "TADJuego.h"

void iniciarJuego(juego &j){
	carta c;

	int cartas_disponibles;             //cartas disponibles en la baraja
	int numero, forma, color, relleno; //características de las cartas

	int n;        //número de columnas de 3 cartas con las que se iniciará el juego, valores permitidos 3,4,5
	//j.objetivo;   número de puntos que debe lograr el usuario para ganar (> 0)
	//j.puntos_set;	número de puntos que suma el usuario cuando forma un set.
	int pa;       //numero de puntos necesarios para solicitar una ayuda
	int fila_act, col_act;   //coordenadas de la carta actual en el tablero


	srand((time(NULL)));

	if (entornoCargarConfiguracion(n, j.puntos_set, j.objetivo, pa)) {
		entornoIniciar(n);
		iniciarTablero(j.t, n);
		iniciarBaraja(j.b);

		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < n; k++) {
				quitarCarta(c,j.b);
				numero = obtenerNumero(c);
				forma = obtenerForma(c);
				color = obtenerColor(c);
				relleno = obtenerRelleno(c);
				entornoPintarCarta(i, k, numero, forma, color, relleno);
				anadirCarta (j.t, c, i, k);
			}
		}
		fila_act = 0;
		col_act = 0;
		entornoMarcarCarta(fila_act, col_act);

		j.puntuacion=0;
		cartas_disponibles = cuantasCartas(j.b);//cartas disponibles en la baraja
		entornoPonerPuntuacion(j.puntuacion);
		entornoPonerDisponibles(cartas_disponibles);

		entornoMostrarMensaje("Pulsa ENTER para seleccionar la carta", 2);


	}
}

void jugar(juego &j){
	TipoTecla tecla;
	int cartas_disponibles;
	cartas_disponibles = cuantasCartas(j.b);//cartas disponibles en la baraja
	carta c1,c2,c3;
	bool salir = false;
	int num_filas = 3;	//numero de filas de la matriz
	int n;	           //número de columnas de 3 cartas con las que se iniciará el juego, valores permitidos 3,4,5
	int fila_act, col_act; fila_act=0; col_act=0;   //coordenadas de la carta actual en el tablero
	int contador;contador=0;                        //Contador de las cartas seleccionadas
	int fila_carta1,fila_carta2,fila_carta3;           //coordenadas de la fila de cada carta seleccionada
	int columna_carta1,columna_carta2,columna_carta3; //coordenadas de la columna de cada carta seleccionada
	n=numColumnas(j.t);
	contador=0;
	int seleccionadas;


	while (!salir) {


		tecla = entornoLeerTecla();
		switch (tecla) {
		case TEnter:

			if(obtenerSeleccionada(j.t,fila_act,col_act)==false){
				entornoSeleccionarCarta(fila_act, col_act);
				seleccionarCarta(j.t, fila_act, col_act);
				contador=contador+1;


			}
			else{
				entornoDeseleccionarCarta ( fila_act, col_act );
				noSeleccionarCarta(j.t,fila_act,col_act);
				contador=contador-1;

			}

			if(contador==3){
				seleccionadas=0;
				contador=0;
				for (int i = 0; i < 3; i++) {
					for (int k = 0; k < n; k++) {

						if(obtenerSeleccionada(j.t,i,k)==true){
							seleccionadas=seleccionadas+1;
							switch (seleccionadas){
							case 1:

								fila_carta1=i;
								columna_carta1=k;
								obtenerCarta(j.t,c1,fila_carta1,columna_carta1);


								break;
							case 2:

								fila_carta2=i;
								columna_carta2=k;
								obtenerCarta(j.t,c2,fila_carta2,columna_carta2);


								break;
							case 3:

								fila_carta3=i;
								columna_carta3=k;
								obtenerCarta(j.t,c3,fila_carta3,columna_carta3);


								break;
							}


						}
					}
				}

				entornoDeseleccionarCarta(fila_carta1,columna_carta1);
				entornoDeseleccionarCarta(fila_carta2,columna_carta2);
				entornoDeseleccionarCarta(fila_carta3,columna_carta3);


				if(comprobarSet(j.t,c1,c2,c3)==false){

					noSeleccionarCarta(j.t, fila_carta1, columna_carta1);
					noSeleccionarCarta(j.t, fila_carta2, columna_carta2);
					noSeleccionarCarta(j.t, fila_carta3, columna_carta3);

					entornoMostrarMensaje("Eso no es un set", 3);

				}
				else{

					entornoMostrarMensaje("Has encontrado un set!", 3);

					quitarCarta(c1,j.b);
					quitarCarta(c2,j.b);
					quitarCarta(c3,j.b);

					anadirCarta(j.t,c1,fila_carta1,columna_carta1);
					entornoPintarCarta (fila_carta1,columna_carta1, c1.numero, c1.forma,c1.color,c1.relleno);

					anadirCarta(j.t,c2,fila_carta2,columna_carta2);
					entornoPintarCarta (fila_carta2,columna_carta2, c2.numero, c2.forma,c2.color,c2.relleno);

					anadirCarta(j.t,c3,fila_carta3,columna_carta3);
					entornoPintarCarta (fila_carta3,columna_carta3, c3.numero, c3.forma,c3.color,c3.relleno);

					j.puntuacion=j.puntuacion+j.puntos_set;
					entornoPonerPuntuacion(j.puntuacion);
					cartas_disponibles=cartas_disponibles-3;
					entornoPonerDisponibles(cartas_disponibles);

					if(j.puntuacion==j.objetivo){
						entornoMostrarMensaje("Enhorabuena, has ganado!", 2);
						string Fin;
						Fin="La partida ha finalizado. FIN";
						entornoMostrarMensajeFin ( Fin );
						entornoTerminar ( );

					}




				}
			}

			break;
		case TDerecha:
			entornoDesmarcarCarta(fila_act, col_act);
			if (col_act < n-1)
				col_act++;
			else
				col_act=0;
			entornoMarcarCarta(fila_act, col_act);
			break;
		case TIzquierda:
			entornoDesmarcarCarta(fila_act, col_act);
			if (col_act > 0)
				col_act--;
			else
				col_act=n-1;
			entornoMarcarCarta(fila_act, col_act);
			break;
		case TArriba:
			entornoDesmarcarCarta(fila_act, col_act);
			if (fila_act > 0)
				fila_act--;
			else
				fila_act=num_filas-1;
			entornoMarcarCarta(fila_act, col_act);
			break;
		case TAbajo:
			entornoDesmarcarCarta(fila_act, col_act);
			if (fila_act < num_filas - 1)
				fila_act++;
			else
				fila_act=0;
			entornoMarcarCarta(fila_act, col_act);
			break;
		case TSalir:
			salir = true;
			break;
		case TF1:
			break;
		case TF2:
			break;
		case TNada:
			break;
		}
	}

}

void terminarJuego(){
	string Fin;
	Fin="La partida ha finalizado. FIN";
	entornoMostrarMensajeFin ( Fin );
	entornoTerminar ( );
}
