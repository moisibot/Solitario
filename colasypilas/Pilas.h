
#ifndef SOLITARIO_PILAS_H
#define SOLITARIO_PILAS_H

#include "Nodos.h"
#include "../Cartasdirec/Cartas.h"

class Pila {
private:
    Nodos *cima;
public:

    int contador();
    void agregar(const Cartas& carta);
    Cartas quitar();

    Pila();

    Nodos *getCima();

    void mostrar();
    bool vacia();

    virtual ~Pila();
};


#endif //SOLITARIO_PILAS_H
