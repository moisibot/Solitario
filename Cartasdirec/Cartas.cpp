#include "Cartas.h"

Cartas::~Cartas() {}

Cartas::Cartas(int constante1, char tipo) : valor(constante1), tipo(tipo) {
    this->visibilidad = false;
    obtenerSimbol(constante1);
    darColor(tipo);
}

void Cartas::obtenerSimbol(int asignado) {
    switch (asignado) {
        case 1:
            this->simbolo = 'A';
            break;
        case 11:
            this->simbolo = 'J';
            break;
        case 12:
            this->simbolo = 'Q';
            break;
        case 13:
            this->simbolo = 'K';
            break;
        default:
            this->simbolo = (asignado < 10) ? (asignado + '0') : '\0';
            break;
    }
}


std::string Cartas::mostar() {
    if (!isVisibilidad()) {
        return "▓▓▓▓▓";
    }

    std::string tmp;

    switch (tipo) {
        case 'C':
            tmp = "<3";  // corazones
            break;
        case 'D':
            tmp = "<>";  // ciamantes
            break;
        case 'E':
            tmp = "!!";  // picas
            break;
        case 'T':
            tmp = "EB";  // treboles
            break;
        default:
            break;
    }

    tmp += color;

    if (valor == 10) {
        return "10" + tmp;
    } else {
        return simbolo + tmp + " ";
    }
}



bool Cartas::isVisibilidad() const {
    return visibilidad;
}

void Cartas::cambiarVisibilidad(int op) {
    if (op == 0) {
        this->visibilidad = !this->visibilidad;
    } else {
        this->visibilidad = true;
    }
}

void Cartas::darColor(char tipoCarta) {
    if (tipoCarta == 'C' || tipoCarta == 'D') {
        this->color = 'R';
    } else {
        this->color = 'N';
    }
}

Cartas::Cartas() {}

int Cartas::getValor() { return this->valor; }

char Cartas::getColor() { return this->color; }
