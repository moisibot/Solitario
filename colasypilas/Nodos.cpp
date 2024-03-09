
#include "Nodos.h"
#include "../Cartasdirec/Cartas.h"

Cartas &Nodos::getDato()  {
    return dato;
}

void Nodos::setDato(const Cartas &dato) {
    Nodos::dato = dato;
}

Nodos *Nodos::getSiguiente() const {
    return siguiente;
}

void Nodos::setSiguiente(Nodos *siguiente) {
    Nodos::siguiente = siguiente;
}

Nodos::Nodos(const Cartas &dato) : dato(dato) {}

string Nodos::mostrar() {
    return this->dato.mostar();
}