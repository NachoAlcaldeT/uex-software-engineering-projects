#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include <string>
#include <vector>

const int MAX_IDENTIFIERS = 100;
typedef char tipo_cadena[50];

union tipo_valor {
	int valor_entero;
	float valor_real;
	bool valor_bool;
	tipo_cadena valor_cad;
};


struct IdentifierInfo {
    tipo_cadena identificador;
    int tipo;
    tipo_valor valor;
};

class IdentifiersTable {
private:
    std::vector<IdentifierInfo> identifiers;

public:
   IdentifiersTable();
    int addIdentifier(IdentifierInfo id);
    void printIdentifiersInfo(FILE* archivo) ;
    IdentifierInfo searchIdentifier(const char* id);
};

#endif // ESTRUCTURA_H

