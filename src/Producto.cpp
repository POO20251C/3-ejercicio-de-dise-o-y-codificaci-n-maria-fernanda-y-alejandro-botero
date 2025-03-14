#include <string>
#include <vector>
#include "Producto.h"

using namespace std;

Producto::Producto(int id_producto, int CantidadDisponible, float precio, string nombre){
    this->id_producto = id_producto;
    this->CantidadDisponible = CantidadDisponible;
    this->Precio = precio;
    this->nombre = nombre;
};

int Producto::get_id(){
    return this->id_producto;
};

int Producto::get_CantidadDisponible(){
    return this->CantidadDisponible;
};

string Producto::get_nombre(){
    return this->nombre;
}

float Producto::get_Precio(){
    return this->Precio;
};


void Producto::set_Precio(float Precio){
    this->Precio = Precio;
};


void Producto::set_CantidadDisponible(int cantidad){
    this->CantidadDisponible = cantidad;
};




