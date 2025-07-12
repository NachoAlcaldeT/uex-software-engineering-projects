// Traducción del lenguaje AMUEBLA
#include "amuebla.h"
#include <allegro5/allegro5.h>

using namespace std;

int main(int argc, char *argv[]) {
	// Se inicia el entorno gráfico
	iniciarAmu();
	pausaAmu(1.5);


	nuevaHabitacionAmu("Salón", 1000.000000, 1000.000000);
	// "Se sitúa el sofá"
	rectanguloAmu(0, 200, 200.000000, 600.000000, AZUL);
	// "Se sitúa la mesa central"
	circuloAmu(450, 500, 150.500000, MARRON);
	pausaAmu(1.20);
	// "Se sitúan los dos sillones"
	rectanguloAmu(350, 100, 200.000000, 200.000000, AZUL);
	rectanguloAmu(350, 700, 200.000000, 200.000000, AZUL);
	// "Se sitúa un mueble"
	rectanguloAmu(900, 100, 200.000000, 800.000000, NEGRO);
	pausaAmu(1.50);
	nuevaHabitacionAmu("Dormitorio", 300.000000, 300.000000);
	rectanguloAmu(75, 0, 150, 200, VERDE);
	circuloAmu(50, 25, 25, ROJO);
	circuloAmu(250, 25, 25, ROJO);
	rectanguloAmu(900, 100, 300, 40, GRIS);
	pausaAmu(2.20);
	pausaAmu(1.50);
	nuevaHabitacionAmu("Terraza", 400.000000, 600.000000);
	rectanguloAmu(0, 0, 100.000000, 100.000000, AMARILLO);
	rectanguloAmu(0, 200, 100.000000, 100.000000, AMARILLO);
	rectanguloAmu(100, 100, 100.000000, 100.000000, AMARILLO);
	rectanguloAmu(100, 300, 100.000000, 100.000000, AMARILLO);
	rectanguloAmu(200, 0, 100.000000, 100.000000, AMARILLO);
	rectanguloAmu(200, 200, 100.000000, 100.000000, AMARILLO);
	rectanguloAmu(300, 100, 100.000000, 100.000000, AMARILLO);
	rectanguloAmu(300, 300, 100.000000, 100.000000, AMARILLO);
	rectanguloAmu(400, 0, 100.000000, 100.000000, AMARILLO);
	rectanguloAmu(400, 200, 100.000000, 100.000000, AMARILLO);
	// "Ejecuta las instrucciones del si no (¡Error!) "
	rectanguloAmu(500, 100, 100.000000, 100.000000, AMARILLO);
	rectanguloAmu(500, 300, 100.000000, 100.000000, AMARILLO);
	circuloAmu(50, 150, 47.500000, GRIS);
	circuloAmu(50, 350, 47.500000, GRIS);
	circuloAmu(150, 50, 47.500000, GRIS);
	circuloAmu(150, 250, 47.500000, GRIS);
	circuloAmu(250, 150, 47.500000, GRIS);
	circuloAmu(250, 350, 47.500000, GRIS);
	circuloAmu(350, 50, 47.500000, GRIS);
	circuloAmu(350, 250, 47.500000, GRIS);
	circuloAmu(450, 150, 47.500000, GRIS);
	circuloAmu(450, 350, 47.500000, GRIS);
	circuloAmu(550, 50, 47.500000, GRIS);
	circuloAmu(550, 250, 47.500000, GRIS);
	pausaAmu(1.50);
	// Se liberan los recursos del entorno gráfico
	terminarAmu();
	return 0;
}
