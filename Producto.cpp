#include "Producto.h"

Producto::Producto() {
	this->nombre = "";
	this->id = 0;
	this->precio = 0.0;
	this->stock = 0;
	this->marca = "";
	this->subCategoria = "";
}
Producto::Producto(string nombre, int id, double precio, int stock, string marca, string subCategoria) {
	this->nombre = nombre;
	this->id = id;
	this->precio = precio;
	this->stock = stock;
	this->marca = marca;
	this->subCategoria = subCategoria;

}
Producto::~Producto() {}

string Producto::getNombre() const {
	return nombre;
}
void Producto::setNombre(const string& nombre) {
	this->nombre = nombre;
}
int Producto::getId() const {
	return id;
}
void Producto::setId(int id) {
	this->id = id;
}
double Producto::getPrecio() const {
	return precio;
}
void Producto::setPrecio(double precio) {
	this->precio = precio;
}
int Producto::getStock() const {
	return stock;
}
void Producto::setStock(int stock) {
	this->stock = stock;
}
string Producto::getMarca() const {
	return marca;
}
void Producto::setMarca(const string& marca) {
	this->marca = marca;
}
string Producto::getSubcategoria() const {
	return subCategoria;
}
void Producto::setSubcategoria(const string& subCategoria) {
	this->subCategoria = subCategoria;
}
