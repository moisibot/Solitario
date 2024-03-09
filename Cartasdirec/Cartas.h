
#ifndef SOLITARIO_CARTAS_H
#define SOLITARIO_CARTAS_H


#include "iostream"

using namespace std;

class Cartas {
private:
    int valor;
    char simbolo;
    bool visibilidad;
    char color;
    char tipo;
public:

    int getValor();

    void darColor(char tipoCarta);

    void obtenerSimbol(int asignado);

    bool isVisibilidad() const;

    string mostar();

    Cartas();

    Cartas(int constante1, char tipo); //constructor con args

    virtual ~Cartas();  //destructor

    void cambiarVisibilidad(int op);

    char getColor();
};


#endif //SOLITARIO_CARTAS_H
