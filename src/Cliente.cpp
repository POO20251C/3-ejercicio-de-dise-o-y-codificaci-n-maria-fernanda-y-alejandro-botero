#include "Cliente.h"
#include <string>
#include <vector>


Cliente::Cliente(string name, int cedula){
    this->name_cliente = name;
    this->cedula = cedula;
};

//Getters

string Cliente::get_name(){
    return this->name_cliente;
};

int Cliente::get_cedula(){
    return this->cedula;
};

vector <Compra> Cliente::get_compras(){
    return this->compras;
};

//Esta funcion devuelve un apuntador a un objeto tipo compra
Compra* Cliente::comprar(){
    //Creamos un objeto tipo compra
    int id = this->compras.size() + 1;
    this->compras.push_back(Compra(id));
    return &this->compras.back();
};