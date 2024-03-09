
#include <limits>
#include "Interfaz.h"

Interfaz::Interfaz() {}
void Interfaz::MostrarCartas() {

    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 7; ++j) {
            if ((i == 0 && j != 2) || i == 1) {
                if (i == 0 && j == 0) {
                    if (!admin.getReserva().colasVacias()) {
                        string tmp = "[" + admin.getReserva().primer().mostar() + "]";
                        mesa[i][j] = tmp;
                    } else {
                        mesa[i][j] = "[     ]";
                    }
                } else if (i == 0 && j == 1) {
                    if (!admin.getDescarte().colasVacias()) {
                        string tmp = "[" + admin.getDescarte().ultimoo().mostar() + "]";
                        mesa[i][j] = tmp;
                    } else {
                        mesa[i][j] = "[     ]";
                    }
                } else {
                    mesa[i][j] = "[     ]";
                }
            } else {    //asignar espacios en blanco
                mesa[i][j] = "       ";
            }
        }
    }


    MostrarColumas(admin.getA1(), 0);
    MostrarColumas(admin.getB1(), 1);
    MostrarColumas(admin.getC1(), 2);
    MostrarColumas(admin.getD1(), 3);
    MostrarColumas(admin.getE1(), 4);
    MostrarColumas(admin.getF1(), 5);
    MostrarColumas(admin.getG1(), 6);

}

void Interfaz::MostrarColumas(Pila pila, int columna) {
    if (pila.vacia()) {
        mesa[1][columna] = "[     ]";
    } else {
        int cont = pila.contador();
        pila.getCima()->getDato().cambiarVisibilidad(1);
        Pila tmp = pila;
        while (!tmp.vacia()) {
            mesa[cont][columna] = "[" + tmp.quitar().mostar() + "]";
            cont--;
        }
    }
}

void Interfaz::CrearTablero() {
    cout << endl;
    MostrarCartas();

    cout << "\t\t\t   ";
    for (int i = 1; i <= 7; ++i) {
        cout << i << "       ";
    }
    cout << endl;
    for (int i = 0; i < 31; ++i) {
        cout << ((i == 0) ? "\t    + " : " ");
        cout << " ";
    }
    cout << " +" << endl;

    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (i == 0 && j == 2) {
                cout << "        ";
            } else if (j == 0) {
                if (i <= 8) {
                    cout << "\t" << i + 1 << "   \t";
                } else {
                    cout << "\t" << i + 1 << "  \t";
                }
                cout << mesa[i][j] << "\t";
            } else {
                cout << mesa[i][j] << "\t";
                if (j == 6 && i == 0) {
                    cout << "\t|" << endl << "\t    ";
                }
            }
        }
        if (i == 0) {
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
        } else {
            cout << "\t|" << endl;
        }
    }

    for (int i = 0; i < 31; ++i) {
        cout << ((i == 0) ? "\t    + " : " ");
        cout << "-";
    }
    cout << " +" << endl;
}


void Interfaz::verMenu() {
    string menuOp = "\n\t 1. mover las cartas en la mesa.\n"
                    "\t 2. ver colas\n"

                    "\tSelecciona una opcion"
                    "\to ingrese 5 para salir ";
    int op = -1;
    while (op != 5) {
        CrearTablero();
        cout << menuOp;
        cin >> op;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            op = -1;
        }
        switch (op) {
            case 1:
                int seleccion, destino;
                cout << "\n\tingrese el numero de una columna [1-7] > ";
                cin >> seleccion;
                cout << "\n\tingrese la columna destino [1-7] menos " << seleccion << ": ";
                cin >> destino;
                moverEntreTablero(seleccion, destino);
                break;
            case 2:
                admin.rotarColas();
                break;
            case 5:
                cout << "\nhasta la proczima";
                break;
            default:
                cout << "\topcion invalida" << endl;
                break;
        }
        cout << endl;
        cin.clear();
    }
}
void Interfaz::moverEntreTablero(int a, int b) {
    if (a >= 1 && a <= 7 && b >= 1 && b <= 7 && a != b) {
        char origen = 'A' + a - 1;
        char destino = 'A' + b - 1;
        admin.trasladar(
                admin.especifica(origen),
                admin.especifica(destino));
    } else {
        cout << endl << "\tmovimiento invalido "
             << "ingreseun numero entre 1 y 7 que no sea el mismo para mover la carta"
             << endl;
    }
}

