#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "spanish");
    Miniso miniso;
    int opción;

    do {
        cout << " --- TIENDA MINISO --- " << endl;
        cout << " 1. Agregar Productos " << endl;
        cout << " 2. Listar Productos " << endl;
        cout << " 3. Eliminar Productos " << endl;
        cout << " 4. Comprar " << endl;
        cout << " 0. Salir " << endl;
        cout << " Ingrese una opción: ";
        cin >> opción;

        switch (opción) {

            case 1:
                cout << " Agregando Productos " << endl;

            case 2:
                cout << " Listando Productos " << endl;

            case 3:
                cout << " Eliminando Productos " << endl;

            case 4:
                cout << " Comprando Productos " << endl;

            case 0:
                cout << " Saliendo del Programa " << endl;

            default:
                cout << " Opción invalida " << endl;
        }

    } while (opcion != 0);

    return 0;
}

