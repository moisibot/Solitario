
#ifndef SOLITARIO_LISTAS_H
#define SOLITARIO_LISTAS_H


#include <iostream>

template<class T>
class ND_Generico {
public:
    T contenido;
    ND_Generico<T> *siguiente;
    ND_Generico<T> *anterior;

    explicit ND_Generico(T _contenido) : contenido(_contenido), siguiente(nullptr), anterior(nullptr) {}
};

template<class T>
class Listas {
private:
    ND_Generico<T> *inicio;
    ND_Generico<T> *ultimo;
    int longitud;

public:
    Listas() : inicio(nullptr), ultimo(nullptr), longitud(0) {}

    ~Listas() {
        while (!vacia()) {
            eliminarPrimero();
        }
    }

    void eliminarPrimero();
    void eliminarUltimo();
    void eliminar(int indice);
    void addFinal(const T &contenido);
    bool vacia() const;
    T &frente();
    T &fin();
    T &obtenerContenido(int indice);
    void addInicio(const T &contenido);
    int size() const;

private:
    ND_Generico<T> &buscarIndice(int indice);
};

template<class T>
void Listas<T>::eliminarPrimero() {
    if (vacia()) {
        throw "La lista esta colasVacias";
    }
    ND_Generico<T> *temp = inicio;
    if (inicio == ultimo) {
        inicio = nullptr;
        ultimo = nullptr;
    } else {
        inicio = inicio->siguiente;
        inicio->anterior = nullptr;
    }
    delete temp;
    longitud--;
}

template<class T>
void Listas<T>::eliminarUltimo() {
    if (vacia()) {
        throw "La lista esta colasVacias";
    }
    ND_Generico<T> *temp = ultimo;
    if (inicio == ultimo) {
        inicio = nullptr;
        ultimo = nullptr;
    } else {
        ultimo = ultimo->anterior;
        ultimo->siguiente = nullptr;
    }
    delete temp;
    longitud--;
}

template<class T>
void Listas<T>::eliminar(int indice) {
    if (vacia()) {
        throw "La lista esta colasVacias";
    }
    if (indice < 0 || indice >= longitud) {
        throw "Indice fuera de rango";
    }
    if (indice == 0) {
        eliminarPrimero();
    } else if (indice == longitud - 1) {
        eliminarUltimo();
    } else {
        ND_Generico<T> &actual = buscarIndice(indice);
        actual.anterior->siguiente = actual.siguiente;
        actual.siguiente->anterior = actual.anterior;
        delete &actual;
        longitud--;
    }
}

template<class T>
void Listas<T>::addFinal(const T &contenido) {
    ND_Generico<T> *nuevo = new ND_Generico<T>(contenido);
    if (vacia()) {
        inicio = nuevo;
    } else {
        nuevo->anterior = ultimo;
        ultimo->siguiente = nuevo;
    }
    ultimo = nuevo;
    longitud++;
}

template<class T>
bool Listas<T>::vacia() const {
    return longitud == 0;
}

template<class T>
T &Listas<T>::frente() {
    if (vacia()) {
        throw "La lista esta colasVacias";
    }
    return inicio->contenido;
}

template<class T>
T &Listas<T>::fin() {
    if (vacia()) {
        throw "La lista esta colasVacias";
    }
    return ultimo->contenido;
}

template<class T>
T &Listas<T>::obtenerContenido(int indice) {
    if (indice < 0 || indice >= longitud) {
        throw "Indice fuera de rango";
    }
    ND_Generico<T> &nodo = buscarIndice(indice);
    return nodo.contenido;
}

template<class T>
void Listas<T>::addInicio(const T &contenido) {
    ND_Generico<T> *nuevo = new ND_Generico<T>(contenido);
    if (vacia()) {
        inicio = nuevo;
        ultimo = nuevo;
    } else {
        inicio->anterior = nuevo;
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
    longitud++;
}

template<class T>
int Listas<T>::size() const {
    return longitud;
}

template<class T>
ND_Generico<T> &Listas<T>::buscarIndice(int indice) {
    if (indice < 0 || indice >= longitud) {
        throw "Indice fuera de rango";
    }
    ND_Generico<T> *temp;
    if (indice < longitud / 2) {
        temp = inicio;
        for (int i = 0; i < indice; ++i) {
            temp = temp->siguiente;
        }
    } else {
        temp = ultimo;
        for (int i = longitud - 1; i > indice; --i) {
            temp = temp->anterior;
        }
    }
    return *temp;
}



#endif //SOLITARIO_LISTAS_H
