//
// Created by moisibot on 8/03/24.
//

#ifndef SOLITARIO_NODODOBLE_H
#define SOLITARIO_NODODOBLE_H


#include "../Cartasdirec/Cartas.h"

class NodoDoble {
private:
    Cartas dato;
    NodoDoble *siguiente;
    NodoDoble *anterior;
public:
    explicit NodoDoble(const Cartas &dato);  //constructor con args

    NodoDoble();    //constructor vacio
    virtual ~NodoDoble();   //destructor

    const Cartas &getDato() const;

    void setDato(const Cartas &dato);

    NodoDoble *getSiguiente() const;

    void setSiguiente(NodoDoble *siguiente);

    NodoDoble *getAnterior() const;

    void setAnterior(NodoDoble *anterior);
    string mostrar();
};

#endif //SOLITARIO_NODODOBLE_H
