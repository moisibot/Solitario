#include "Colas.h"
#include <iostream>
#include <string>

using namespace std;

Colas::Colas() {
    inicio = nullptr;
    final = nullptr;
}

string Colas::mostrarUno() const {
    return this->inicio->mostrar();
}

Cartas &Colas::ultimoo() {
    return final->getDato();
}

bool Colas::colasVacias() {
    if (inicio == nullptr && final == nullptr) {
        return true;
    }
    return false;
}

Cartas Colas::Centinela() const {
    return inicio->getDato();
}

void Colas::AgregarValor(const Cartas &carta) {
    Nodos *nuevo = new Nodos(carta);
    nuevo->setSiguiente(nullptr);

    if (final != nullptr) {
        final->setSiguiente(nuevo);
    }
    final = nuevo;

    if (inicio == nullptr) {
        inicio = nuevo;
    }
}

Cartas &Colas::primer() {
    return inicio->getDato();
}

Cartas Colas::QuitarValor() {
    if (!colasVacias()) {
        Cartas carta = inicio->getDato();
        Nodos *temp = inicio;

        if (inicio == final) {
            inicio = nullptr;
            final = nullptr;
        } else {
            inicio = inicio->getSiguiente();
        }

        return carta;
    } else {
        throw "Error-> Colas colasVacias!";
    }
}

void Colas::VerificarColas() {
    if (colasVacias()) {
        cout << "colas vacias" << endl;
    } else {
        Nodos *curr = inicio;
        cout << "elementos de la cola." << endl;
        int c = 1;
        while (curr != nullptr) {
            cout << c << "- " << curr->mostrar() << endl;
            curr = curr->getSiguiente();
            c++;
        }
        cout << endl;
    }
}
//eliminar cada elemento de la cola
Colas::~Colas() {
    while (!colasVacias()) {
        QuitarValor();
    }
}