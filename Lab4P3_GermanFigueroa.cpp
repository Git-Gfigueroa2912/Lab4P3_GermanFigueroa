#include <iostream>
#include "Miniso.h"
using namespace std;

int main() {
    Miniso miniso;
    int opcion = 0;

    do {
        cout << "--- Miniso ---" << endl;
        cout << "1) Agregar Productos" << endl;
        cout << "2) Listar Productos" << endl;
        cout << "3) Eliminar Productos" << endl;
        cout << "4) Comprar" << endl;
        cout << "0) Salir" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << " Agregando Productos " << endl;
            miniso.agregarProductos();
            break;

        case 2:
            cout << " Listando Productos " << endl;
            miniso.listarProductos();
            break;

        case 3:
            cout << " Eliminando Productos " << endl;
            miniso.eliminarProductos();
            break;

        case 4:
            cout << " Comprando Productos " << endl;
            miniso.comprarProductos();
            break;

        case 0: 
            cout << " Saliendo del programa " << endl;
            break;

        default:
            cout << " Opcion invalida " << endl;
            break;

        }

    } while opcion(!= 0);

    return 0;
    
}
