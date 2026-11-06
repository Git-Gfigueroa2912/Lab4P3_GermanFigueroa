#ifndef MINISO_H
#define MINISO_H

#include <vector>
#include "Producto.h"

using namespace std;

class Miniso {
private:
    vector<Producto> listaProductos;

public:
    Miniso();
    ~Miniso();

    void agregarProductos();
    void listarProductos();
    void eliminarProductos();
    void comprarProductos();
};
#endif
