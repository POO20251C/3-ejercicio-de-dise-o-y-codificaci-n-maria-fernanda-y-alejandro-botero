#include <string>
#include <vector>
#include "Tienda.h"

using namespace std;

Tienda::Tienda(string nombre){
    this->nombre = nombre;
};

string Tienda::get_name(){
    return this->nombre;
};

vector <Producto> Tienda::get_productos(){
    return this->productos;
};

vector <Cliente> Tienda::get_clientes(){
    return this->clientes;
};

Cliente* Tienda::registrar_compra(string nombre, int cedula){
    for(Cliente& c: this->clientes){
        if( c.get_cedula() == cedula){
            return &c;
        }
    }

    this->clientes.push_back(Cliente(nombre, cedula));
    return &this->clientes.back();
}

void Tienda::registrar_producto(string nombre, int cantidad, float precio){
    int id = this->productos.size() + 1;
    Producto p(id, cantidad, precio, nombre);
    this->productos.push_back(p);
}

Producto* Tienda::buscar(int id){
    for(Producto& p: this->productos){
        if( p.get_id() == id){
            return &p;
        }
    }
    return nullptr;
};