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