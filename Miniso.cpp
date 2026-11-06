#include "Miniso.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

Miniso::Miniso() {}
Miniso::~Miniso(){}

void Miniso::agregarProductos() {
	string nombre, marca, subCategoria;
	int id, stock;
	double precio;

	cout << " Ingrese el nombre del producto: ";
	cin >> nombre;
	cout << "Ingresar el id del producto: ";
	while (!(cin >> id) || id < 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "El ID es invalido: ";
	}
	cout << "Ingresar el precio del producto: ";
	while (!(cin >> precio) || precio <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ingresar el precio del producto: ";
	}
	cout << "Ingresar el stock de producto: ";
	while (!(cin >> stock) || stock < 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ingresar el stock de producto: ";
	}
	while (true) {
		cout << "Ingresar la marca del producto [Sanrio/Disney]: ";
		cin >> marca;
		if (marca == "Sanrio" || marca == "Disney") {
			break;
		}
	}
    cout << "Ingrese la Subcategoria del Producto: ";
	cin >> subCategoria;

	listaProductos.push_back(Producto(nombre, id, precio, stock, marca, subCategoria));
	cout << "Producto " << nombre << " agregado con exito." << endl;


}
void Miniso::listarProductos() {
	if (listaProductos.empty()) {
		cout << "No hay productos registrados." << endl;
		return;
	}

	for (size_t i = 0; i < listaProductos.size(); i++) {
		cout << "-***" << i << "***-" << endl;
		cout << "Producto: " << listaProductos[i].getNombre() << endl;
		cout << "Precio: " << listaProductos[i].getPrecio() << endl;
		cout << "Id: " << listaProductos[i].getId() << endl;
		cout << "Stock: " << listaProductos[i].getStock() << endl;
		cout << "Marca: " << listaProductos[i].getMarca() << endl;
		cout << "Sub Categoria: " << listaProductos[i].getSubCategoria() << endl;
	}
}

void Miniso::eliminarProductos() {
	if (listaProductos.empty()) {
		cout << "No hay productos para eliminar." << endl;
		return;
	}

	listarProductos();

	int indice;
	cout << "Ingrese el indice del producto a eliminar: ";
	while (!(cin >> indice) || indice < 0 || indice >= static_cast<int>(listaProductos.size())) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Indice invalido. Ingrese el indice del producto a eliminar: ";
	}

	listaProductos.erase(listaProductos.begin() + indice);
	cout << "El elemento fue borrado con exito." << endl;
}
void Miniso::comprarProductos() {
	char matriz[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matriz[i][j] = ' ';
		}
	}

	srand(time(0));
	if (!listaProductos.empty()) {
		for (size_t k = 0; k < listaProductos.size(); k++) {
			int f = rand() % 10;
			int c = rand() % 10;
			while (matriz[f][c] != ' ') {
				f = rand() % 10;
				c = rand() % 10;
			}
			matriz[f][c] = listaProductos[k].getNombre()[0];
		}
	}

	vector<char> carrito;
	int tarjetazos = 10;

	while (tarjetazos > 0) {
		cout << "Te quedan " << tarjetazos << " tarjetazos." << endl;
		cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
		for (int i = 0; i < 10; i++) {
			cout << i << "|";
			for (int j = 0; j < 10; j++) {
				cout << matriz[i][j] << " ";
			}
			cout << endl;
		}

		cout << "Carrito: [ ";
		for (size_t i = 0; i < carrito.size(); i++) {
			cout << carrito[i] << " ";
		}
		cout << "]" << endl;

		int fila, columna;
		cout << "Ingresa la fila (0-9): ";
		if (!(cin >> fila) || fila < 0 || fila > 9) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Casilla Invalida. No se agrego ningun producto." << endl;
			tarjetazos--;
			continue;
		}

		cout << "Ingresa la columna (0-9): ";
		if (!(cin >> columna) || columna < 0 || columna > 9) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Casilla Invalida. No se agrego ningun producto." << endl;
			tarjetazos--;
			continue;
		}
		if (matriz[fila][columna] != ' ') {
			carrito.push_back(matriz[fila][columna]);
			matriz[fila][columna] = ' ';
			tarjetazos--;
			cout << "Exito! Agregaste un producto. Te quedan " << tarjetazos << " tarjetazos." << endl;
		}
		else {
			tarjetazos--;
			cout << "Casilla vacia, por lo tanto no se agrego nada" << endl;
			cout << " Quedan " << tarjetazos << " tarjetazos." << endl;
		}
	}
}


