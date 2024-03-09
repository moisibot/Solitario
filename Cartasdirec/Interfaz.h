

#ifndef SOLITARIO_INTERFAZ_H
#define SOLITARIO_INTERFAZ_H
#include "PushPop.h"
class Interfaz {
private:
    PushPop admin;
    string mesa[13][7];

    void MostrarCartas();


    void CrearTablero();


public:
    void verMenu();

    Interfaz();

    void MostrarColumas(Pila pila, int columna);

    void moverEntreTablero(int a, int b);
};

#endif //SOLITARIO_INTERFAZ_H
