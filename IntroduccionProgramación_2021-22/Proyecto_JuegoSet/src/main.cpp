#include "TADcarta.h"
#include "TADbaraja.h"
#include "pr_baraja.h"
#include "pr_carta.h"
#include "TADJuego.h"


int main() {
	juego j;
	iniciarJuego(j);
	jugar(j);
	terminarJuego();
	return 0;
}


