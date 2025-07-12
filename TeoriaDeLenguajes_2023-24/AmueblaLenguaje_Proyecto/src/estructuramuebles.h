#ifndef ESTRUCTURAMUEBLES_H
#define ESTRUCTURAMUEBLES_H

#include <string>
#include <vector>

typedef char tipo_cadena[50];

enum TipoValor {
    ENTEROMUEBLES,
    REALMUEBLES
};

enum TipoMueble {
    RECTANGULO,
    CIRCULO,
    NOENCONTRADO
};

union tipo_valor_mueble {
    int valor_entero;
    float valor_real;
};

struct MuebleInfo {
    tipo_cadena nombre;
    TipoMueble tipo;
    TipoValor tipo_valor1; // Tipo de valor1 (entero o real)
    tipo_valor_mueble valor1; // Ancho para rectángulo, radio para círculo
    TipoValor tipo_valor2; // Tipo de valor2 (entero o real, solo para rectángulo)
    tipo_valor_mueble valor2; // Altura para rectángulo
    tipo_cadena color;
};


class MueblesTable {
private:
    std::vector<MuebleInfo> muebles;

public:
    MueblesTable();
    int addMueble(MuebleInfo mueble);
    void printMueblesInfo(FILE* archivo);
    MuebleInfo buscarMueblePorNombre(const tipo_cadena nombre);
    const std::vector<MuebleInfo>& getMuebles() const;
};

#endif // ESTRUCTURAMUEBLES_H
