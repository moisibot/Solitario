//
// Created by moisibot on 8/03/24.
//

#include "Pilas.h"
#include "../Cartasdirec/Cartas.h"
//push
void Pila::agregar(const Cartas &carta) {
    Nodos *nuevo = new Nodos(carta);
    if (vacia()) {
        cima = nuevo;
        nuevo->setSiguiente(nullptr);
    } else {
        nuevo->setSiguiente(cima);
        cima = nuevo;
    }
}
//pop
Cartas Pila::quitar() {
    if (!vacia()) {
        Cartas temp = cima->getDato();
        Nodos *del = cima;
        cima = cima->getSiguiente();
        // delete del;
        return temp;
    } else {
        throw "malo Pila Vacias!";
    }
}

void Pila::mostrar() {
    if (vacia()) {
        cout << "pila Vacias" << endl;
    } else {
        Nodos *curr = cima;
        cout << "Listado de todos los elementos de la pila." << endl;
        while (curr != nullptr) {
            cout << curr->mostrar() << " - ";
            curr = curr->getSiguiente();
        }
        cout << endl;
    }
}

Pila::Pila() { cima = nullptr; }

bool Pila::vacia() {
    if (cima == nullptr) {
        return true;
    }
    return false;
}

Pila::~Pila() { while (!vacia()) { quitar(); }}

int Pila::contador() {
    if (vacia()) {
        cout << "la lista esta vacias";
    } else {
        int cont = 0;
        Nodos *curr = cima;
        while (curr != nullptr) {
            curr = curr->getSiguiente();
            cont++;
        }
        return cont;
    }
    return 0;
}

Nodos *Pila::getCima() { return cima; }
