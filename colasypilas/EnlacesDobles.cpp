#include "EnlacesDobles.h"
#include "NodoDoble.h"
#include "../Cartasdirec/Cartas.h"

ConexionDole::ConexionDole() {
    this->tamaño = 0;
    this->primero = nullptr;
    this->ultimo = nullptr;
}

ConexionDole::~ConexionDole() {
    while (!esVacia()) {
        quitarPrimero();
    }
}

void ConexionDole::quitarPrimero() {
    if (esVacia()) {
        throw "La lista esta colasVacias";
    }
    if (tamaño == 1) {
        primero = nullptr;
        ultimo = nullptr;
    } else {
        NodoDoble *aux = primero->getSiguiente();
        aux->setAnterior(nullptr);
        primero = aux;
    }
    tamaño--;
}

void ConexionDole::quitarUltimo() {
    if (esVacia()) {
        throw "Error-> La lista esta colasVacias!";
    }
    if (tamaño == 1) {
        primero = nullptr;
        ultimo = nullptr;
    } else {
        NodoDoble *aux = ultimo->getAnterior();
        aux->setSiguiente(nullptr);
        ultimo = aux;
    }
    tamaño--;
}

void ConexionDole::agregarFinal(const Cartas &carta) {
    if (esVacia()) {
        auto *nuevo = new NodoDoble(carta);
        primero = nuevo;
        ultimo = nuevo;
    } else {
        auto *nuevo = new NodoDoble(carta);
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
    }
    tamaño++;
}

bool ConexionDole::esVacia() const {
    return this->tamaño == 0;
}

Cartas &ConexionDole::fin() {
    return const_cast<Cartas &>(primero->getDato());
}

Cartas &ConexionDole::principal() {
    return const_cast<Cartas &>(ultimo->getDato());
}

Cartas &ConexionDole::obtenerContenido(int indice) {
    return const_cast<Cartas &>(primerIndice(indice).getDato());
}

NodoDoble &ConexionDole::primerIndice(int indice) {    //indice es de 0-(tamLista-1)
    if (indice > tamaño - 1 || indice < 0) {
        throw "Error> Indice fuera de rango";
    }
    int mitad = tamaño / 2;
    if (indice <= mitad) {
        return inicioAlUltimo(indice);
    } else {
        return ultimoAlPrimero(indice);
    }
}

NodoDoble &ConexionDole::ultimoAlPrimero(int indice) {
    NodoDoble *actual = ultimo;
    int cont = 0;
    while (cont < (tamaño - indice - 1)) {
        NodoDoble *curr = actual->getAnterior();
        actual = curr;
        cont++;
    }
    return *actual;
}

NodoDoble &ConexionDole::inicioAlUltimo(int indice) {
    NodoDoble *actual = primero;
    int cont = 0;
    while (cont < indice) {
        NodoDoble *curr = actual->getSiguiente();
        actual = curr;
        cont++;
    }
    return *actual;
}

void ConexionDole::mostrar() {
    NodoDoble *curr = primero;
    if (!esVacia()) {
        while (curr) {
            cout << curr->mostrar() << " - ";
            curr = curr->getSiguiente();
        }
        cout << endl;
    }
    delete curr;
}

void ConexionDole::eliminar(int indice) {
    if (esVacia()) {
        cout << "La lista esta colasVacias";
    } else {
        if (indice == 0) {
            quitarPrimero();
        } else if (indice == (tamaño - 1)) {
            quitarUltimo();
        } else {
            NodoDoble *actual = &primerIndice(indice);
            NodoDoble *sig = actual->getSiguiente();
            NodoDoble *ant = actual->getAnterior();
            sig->setAnterior(ant);
            ant->setSiguiente(sig);
            tamaño--;
        }
    }
}

int ConexionDole::size() const {
    return this->tamaño;
}

NodoDoble *ConexionDole::getInicio() const {
    return primero;
}

void ConexionDole::addInicio(const Cartas &carta) {
    auto *nuevo = new NodoDoble(carta);
    nuevo->setSiguiente(primero);
    if (primero != nullptr)
        primero->setAnterior(nuevo);
    primero = nuevo;
}
