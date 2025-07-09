#include "TADcarta.h"
#include "TADbaraja.h"


void iniciarBaraja (baraja &b){
	carta c;
	b.ocupadas=0;

	int co,f,r,n;

	for(co=1;co<4;co++){

		for(f=1;f<4;f++){

			for(r=1;r<4;r++){

				for(n=1;n<4;n++){
					crearCarta(c, co, f, r, n);
					b.vBaraja[b.ocupadas]=c;
					b.ocupadas++;
				}
			}

		}

	}

}

void quitarCarta (carta &c, baraja &b){
	int carta;
	carta= (rand()%b.ocupadas);

	c=b.vBaraja[carta];
	int i;
	i=carta;
	while(i<b.ocupadas){
		b.vBaraja[i]=b.vBaraja[i+1];
		i++;
	}
	b.ocupadas--;

}

int cuantasCartas    (baraja b){
	return b.ocupadas;
}

void mostrarCarta (baraja b, int pos){
	carta c;
	c=b.vBaraja[pos];
	cout<<obtenerNumero(c);
	cout<<obtenerForma(c);
	cout<<obtenerColor(c);
	cout<<obtenerRelleno(c);
	cout<<endl;
}


