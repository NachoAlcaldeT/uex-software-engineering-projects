#include "estructuramuebles.h"
#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>

MueblesTable::MueblesTable() {}

int MueblesTable::addMueble(MuebleInfo mueble) {
   size_t i = 0;
    int encontrado =0;
		
    while (i < muebles.size()) {
        if(strcmp(muebles[i].nombre, mueble.nombre) == 0){
		encontrado =1;
            std::cout << "El mueble ya esta creado" << std::endl;
                 }
        ++i;
    }
	
	if (encontrado==0){
		muebles.push_back(mueble);
	}	
return 0;
}



void MueblesTable::printMueblesInfo(FILE* archivo) {
	
	 if (!archivo) {
        std::cerr << "Error: Archivo no válido.\n";
        return;
    }
	
    fprintf(archivo, "Tabla de muebles:\n");
    for (const auto& mueble : muebles) {
        fprintf(archivo, "Nombre: %s, Tipo: ", mueble.nombre);
        if (mueble.tipo == RECTANGULO) {
            fprintf(archivo, "Rectángulo, Ancho: ");
            if (mueble.tipo_valor1 == ENTEROMUEBLES) {
                fprintf(archivo, "%d", mueble.valor1.valor_entero);
            } else {
                fprintf(archivo, "%f", mueble.valor1.valor_real);
            }
            fprintf(archivo, ", Altura: ");
            if (mueble.tipo_valor2 == ENTEROMUEBLES) {
                fprintf(archivo, "%d", mueble.valor2.valor_entero);
            } else {
                fprintf(archivo, "%f", mueble.valor2.valor_real);
            }
            fprintf(archivo, ", Color: %s\n", mueble.color);
        } else if (mueble.tipo == CIRCULO) {
            fprintf(archivo, "Círculo, Radio: ");
            if (mueble.tipo_valor1 == ENTEROMUEBLES) {
                fprintf(archivo, "%d", mueble.valor1.valor_entero);
            } else {
                fprintf(archivo, "%f", mueble.valor1.valor_real);
            }
            fprintf(archivo, ", Color: %s\n", mueble.color);
        }
    }
    fclose(archivo);
}

MuebleInfo MueblesTable::buscarMueblePorNombre(const tipo_cadena nombre) {
    MuebleInfo muebleEncontrado;
    muebleEncontrado.tipo=NOENCONTRADO;
    for (const auto& mueble : muebles) {
        if (strcmp(mueble.nombre, nombre) == 0) {
            muebleEncontrado = mueble;
            break;
        }
    }
    return muebleEncontrado;
}

const std::vector<MuebleInfo>& MueblesTable::getMuebles() const {
    return muebles;
}


