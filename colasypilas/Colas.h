
#ifndef SOLITARIO_COLAS_H
#define SOLITARIO_COLAS_H

#include "Nodos.h"
#include "../Cartasdirec/Cartas.h"

class Colas {
private:
    Nodos *inicio;
    Nodos *final;
public:
    Colas();

    virtual ~Colas();

    bool colasVacias();

    void AgregarValor(const Cartas &carta);

    Cartas QuitarValor();

    Cartas &primer() ;

    Cartas &ultimoo();

    void VerificarColas();

    string mostrarUno() const;

    Cartas Centinela() const;
};


#endif //SOLITARIO_COLAS_H
