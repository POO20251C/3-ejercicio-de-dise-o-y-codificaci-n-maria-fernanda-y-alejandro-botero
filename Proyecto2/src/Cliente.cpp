#include <string>
#include <vector>
#include "Cliente.h"


using namespace std;
//Descripcion del Constructor

Cliente::Cliente(int id, string name){
    this->id = id;
    this->name = name;
};

//Descripcion de Getters

int Cliente::get_id(){
    return this->id;
};

string Cliente::get_name(){
    return this->name;
};

vector <Compra> Cliente::get_compras(){
    return this ->compras;
};
//Descripcion de setters

void Cliente::set_name(string name){
    this->name = name;
};


//Funcionalidades adicionales

void Cliente::mostrar_compras(){
    //Debo de printear todas las compras incluyendo sus items       
};

Compra Cliente::comprar(Tienda *tienda){
    

};