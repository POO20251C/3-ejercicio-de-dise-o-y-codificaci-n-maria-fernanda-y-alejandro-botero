#include <string>
#include <vector>
#include "Producto.h"

//Constructor
Producto::Producto(string name, int id, int stock, float precio) {
    this->name= name;
    this->id=id;
    this->stock=stock;
    this->precio=precio;
}

//Getters
string Producto::getName(){
    return this->name;
}
string Producto::getId(){
    return this->id;
}
int Producto::getstock(){
    return this->stock;
}
float Producto::getprecio(){
    return this->precio;
}

//setters
void Producto::setName(string name) {
   this->name = name;
}
void Producto::setId(string id) {
   this->id = id;
}
void Producto::setStock(int stock) {
   this->stock = stock;
}
void Producto::setPrecio(float precio) {
   this->precio = precio;
}
