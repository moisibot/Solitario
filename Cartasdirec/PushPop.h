//
// Created by moisibot on 8/03/24.
//

#ifndef SOLITARIO_PUSHPOP_H
#define SOLITARIO_PUSHPOP_H

#include "../colasypilas/EnlacesDobles.h"
#include "../colasypilas/Pilas.h"
#include "../colasypilas/Colas.h"

class PushPop {
private:
    ConexionDole *cartas;
    Colas reserva;
    Colas descarte;
    Pila baseNo1;
    Pila baseNo2;
    Pila baseNo3;
    Pila baseNo4;
    Pila a1;  //Columna 1
    Pila b1;  //columna 2
    Pila c1;  //columna 3
    Pila d1;  //columna 4
    Pila e1;  //columna 5
    Pila f1;  //columna 6
    Pila g1;  //columna 7

    void agregar();

    void repartir();

public:
    Colas getReserva() const;

    Colas getDescarte();

    void verCartas();

    PushPop();

    virtual ~PushPop();

    void rotarColas();

    Pila &getA1();

    Pila &getB1();

    Pila &getC1();

    Pila &getD1();

    Pila &getE1();

    Pila &getF1();

    Pila &getG1();

    void trasladar(Pila &p1, Pila &p2);

    Pila &especifica(char a);
};


#endif //SOLITARIO_PUSHPOP_H
