//
// Created by moisibot on 8/03/24.
//

#ifndef SOLITARIO_NODOS_H
#define SOLITARIO_NODOS_H

#include "../Cartasdirec/Cartas.h"

class Nodos {
private:
    Cartas dato;
    Nodos *siguiente;
public:
    explicit Nodos(const Cartas &dato);

    Cartas &getDato();

    void setDato(const Cartas &dato);

    Nodos *getSiguiente() const;

    void setSiguiente(Nodos *siguiente);
    string mostrar();
};


#endif //SOLITARIO_NODOS_H
