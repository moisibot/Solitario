
#ifndef SOLITARIO_ENLACESDOBLES_H
#define SOLITARIO_ENLACESDOBLES_H


#include "NodoDoble.h"

class ConexionDole {
private:
    NodoDoble *primero;
    NodoDoble *ultimo;
    int tamaño;

    NodoDoble &primerIndice(int indice);

    NodoDoble &inicioAlUltimo(int indice);

    NodoDoble &ultimoAlPrimero(int indice);

public:
    NodoDoble *getInicio() const;

    ConexionDole();   //constructor vacio

    virtual ~ConexionDole();  //desconstructor

    void quitarPrimero();

    void quitarUltimo();

    void eliminar(int indice);

    void agregarFinal(const Cartas &carta);

    bool esVacia() const;

    Cartas &principal();

    Cartas &fin();

    Cartas &obtenerContenido(int indice);

    void addInicio(const Cartas &carta);

    void mostrar();

    int size() const;
};



#endif //SOLITARIO_ENLACESDOBLES_H
