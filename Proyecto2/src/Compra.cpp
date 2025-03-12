#include <string>
#include <vector>
#include <tuple>
#include "Compra.h"

//Definicion del constructor
Compra::Compra(int id_compra){
    this->id_compra = id_compra;
};

//Definicion getter

vector<tuple <int, int >> Compra::get_compra(){
    return this->items;
};

//funcionalidades adicionales

void Compra::adicionar_producto_a_compra(int id_product, int cantidad){
    items = this->items;
    tuple< int, int> new_item = make_tuple (id_product, cantidad);
    items.push_back(new_item);
};