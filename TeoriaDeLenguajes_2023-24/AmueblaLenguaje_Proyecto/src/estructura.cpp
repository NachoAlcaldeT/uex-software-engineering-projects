#include "estructura.h"
#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>

IdentifiersTable::IdentifiersTable() {}



int IdentifiersTable::addIdentifier(IdentifierInfo id) {
    size_t i = 0;
    int encontrado =0;
		
    while (i < identifiers.size()) {
        if(strcmp(identifiers[i].identificador, id.identificador) == 0){
		encontrado =1;
            if (identifiers[i].tipo == id.tipo) {
                
                identifiers[i].valor = id.valor;
		std::cout << "Valor actualizado "<< std::endl;
                
            } else {
                // El identificador ya existe pero tiene un tipo diferente
                std::cout << "El identificador '" << id.identificador << "' es de tipo ";
		 switch (identifiers[i].tipo) {
			case 0:
				std::cout << "entero " ;
               		 break;
            		case 1:
                		std::cout << "real ";
               		 break;
            		case 2:
               			std::cout << "logico ";
               		 break;
			default:
               			
                	break;
       			 }
		 	std::cout << " y no se puede actualizar con un valor de tipo " ;
			switch (id.tipo) {
			case 0:
				std::cout << "entero "<< std::endl;
               		 break;
            		case 1:
                		std::cout << "real "<< std::endl;
               		 break;
            		case 2:
               			std::cout << "logico "<< std::endl;
               		 break;
			default:
               			
                	break;
       			 }
                 }
        }
        ++i;
    }
	
	if (encontrado==0){
            
	    if (identifiers.size() < MAX_IDENTIFIERS) {
		identifiers.push_back(id);
	    } 
	}	
return 0;
}

IdentifierInfo IdentifiersTable::searchIdentifier(const char* id){

IdentifierInfo nuevoIdentificador;
int i =0;
nuevoIdentificador.tipo=-1;
 while (i < identifiers.size()) {
        if (strcmp(identifiers[i].identificador, id) == 0) {
            nuevoIdentificador= identifiers[i];
        }
        ++i;
    }


return nuevoIdentificador;
}

void IdentifiersTable::printIdentifiersInfo(FILE* archivo)  {

	fprintf(archivo, "Tabla de identificadores:\n");
    
	
	for (const auto& identifier : identifiers) {
       		fprintf(archivo, "%s  ", identifier.identificador);
    	 switch (identifier.tipo) {
            case 0:
                fprintf(archivo, "entero %d\n", identifier.valor.valor_entero);
                break;
            case 1:
                fprintf(archivo, "real %f\n", identifier.valor.valor_real);
                break;
            case 2:
                fprintf(archivo, "logico %s\n", identifier.valor.valor_bool ? "true" : "false");
                break;
            case 3:
                fprintf(archivo, "cadena %s\n", identifier.valor.valor_cad);
                break;
            default:
                fprintf(archivo, "tipo desconocido\n");
                break;
        }
    }
    fclose(archivo);
}



