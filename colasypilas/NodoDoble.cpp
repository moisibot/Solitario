
#include "NodoDoble.h"
NodoDoble::NodoDoble() {}

NodoDoble::NodoDoble(const Cartas &dato) : dato(dato) {}

NodoDoble::~NodoDoble() {}

const Cartas &NodoDoble::getDato() const { return dato; }

void NodoDoble::setDato(const Cartas &dato) { NodoDoble::dato = dato; }

NodoDoble *NodoDoble::getSiguiente() const { return siguiente; }

void NodoDoble::setSiguiente(NodoDoble *siguiente) { NodoDoble::siguiente = siguiente; }

NodoDoble *NodoDoble::getAnterior() const { return anterior; }

void NodoDoble::setAnterior(NodoDoble *anterior) { NodoDoble::anterior = anterior; }

string NodoDoble::mostrar() {
    return this->dato.mostar();
}