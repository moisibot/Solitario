#include "PushPop.h"
#include "unistd.h"

void PushPop::agregar() {
    for (int i = 1; i < 14; ++i) {
        cartas->agregarFinal(Cartas(i, 'C'));
    }
    for (int i = 1; i < 14; ++i) {
        cartas->agregarFinal(Cartas(i, 'E'));
    }
    for (int i = 1; i < 14; ++i) {
        cartas->agregarFinal(Cartas(i, 'D'));
    }
    for (int i = 1; i < 14; ++i) {
        cartas->agregarFinal(Cartas(i, 'T'));
    }
}

void PushPop::repartir() {
    agregar();
    srand(getpid());
    int contador = 0;
    while (contador < 24) {
        int _random = rand() % (cartas->size() / 2) + 1;
        reserva.AgregarValor(cartas->obtenerContenido(_random));
        cartas->eliminar(_random);
        contador++;
    }
    // crear un pila temporal que servira para repartir las cartas restantes
    Pila tmp;
    int cont = 0;
    while (cont < 27) {
        tmp.agregar(cartas->obtenerContenido(1));
        cartas->eliminar(1);
        cont++;
    }
    tmp.agregar(cartas->principal());
    cartas->quitarPrimero();

    a1.agregar(tmp.quitar()); //llenar la primera columna (pila)
    for (int i = 0; i < 2; ++i) {
        b1.agregar(tmp.quitar());
    }
    for (int i = 0; i < 3; ++i) {
        c1.agregar(tmp.quitar());
    }
    for (int i = 0; i < 4; ++i) {
        d1.agregar(tmp.quitar());
    }
    for (int i = 0; i < 5; ++i) {
        e1.agregar(tmp.quitar());
    }
    for (int i = 0; i < 6; ++i) {
        f1.agregar(tmp.quitar());
    }
    for (int i = 0; i < 7; ++i) {
        g1.agregar(tmp.quitar());
    }
}

void PushPop::verCartas() {
    int contador = 0;
    for (int i = 0; i < cartas->size(); ++i) {
        cout << cartas->obtenerContenido(i).mostar();
        if (contador == 12) {
            cout << endl;
            contador = 0;
        } else {
            cout << " -> ";
            contador++;
        }
    }
}


PushPop::PushPop() {
    cartas = new ConexionDole();
    repartir();
}

void PushPop::trasladar(Pila &p1, Pila &p2) {
    int x = p1.getCima()->getDato().getValor();
    int y = p2.getCima()->getDato().getValor();
    if (x == y - 1) {
        if (p1.getCima()->getDato().getColor() != p2.getCima()->getDato().getColor()) {
            p2.agregar(p1.quitar());
        } else {
            cout << endl << "\tmovimiento invalido "
                 << endl << "\tlos colores tienen que ser intercalados y con numero consecutivo";
        }
    } else {
        cout << endl << "\tmovimiento invalido" << endl;
    }
}

void PushPop::rotarColas() {
    if (!reserva.colasVacias()) {
        reserva.primer().cambiarVisibilidad(0);
        descarte.AgregarValor(reserva.QuitarValor());
    } else {
        while (!descarte.colasVacias()) {
            descarte.primer().cambiarVisibilidad(0);
            reserva.AgregarValor(descarte.QuitarValor());
        }
    }
}

Pila &PushPop::especifica(char a) {
    switch (a) {
        case 'A':
            return this->getA1();
        case 'B':
            return this->getB1();
        case 'C':
            return this->getC1();
        case 'D':
            return this->getD1();
        case 'E':
            return this->getE1();
        case 'F':
            return this->getF1();
        case 'G':
            return this->getG1();
    }
    throw "No encontrado";
}

Colas PushPop::getReserva() const { return reserva; }

Colas PushPop::getDescarte() { return descarte; }

Pila &PushPop::getA1() { return a1; }

Pila &PushPop::getB1() { return b1; }

Pila &PushPop::getC1() { return c1; }

Pila &PushPop::getD1() { return d1; }

Pila &PushPop::getE1() { return e1; }

Pila &PushPop::getF1() { return f1; }

Pila &PushPop::getG1() { return g1; }

PushPop::~PushPop() = default;
