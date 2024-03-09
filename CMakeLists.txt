cmake_minimum_required(VERSION 3.27)
project(Solitario)

set(CMAKE_CXX_STANDARD 17)

add_executable(Solitario main.cpp
        colasypilas/Colas.cpp
        colasypilas/Colas.h
        colasypilas/Nodos.cpp
        colasypilas/Nodos.h
        Cartasdirec/Cartas.cpp
        Cartasdirec/Cartas.h
        colasypilas/Listas.cpp
        colasypilas/Listas.h
        colasypilas/EnlacesDobles.cpp
        colasypilas/EnlacesDobles.h
        colasypilas/NodoDoble.cpp
        colasypilas/NodoDoble.h
        colasypilas/Pilas.cpp
        colasypilas/Pilas.h
        Cartasdirec/PushPop.cpp
        Cartasdirec/PushPop.h
        Cartasdirec/Interfaz.cpp
        Cartasdirec/Interfaz.h

)
