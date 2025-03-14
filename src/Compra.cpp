#include <string>
#include <vector>
#include <tuple>
#include "Compra.h"


Compra::Compra(int id){
    this->id_compra = id;
};

int Compra::get_id(){
    return this->id_compra;
};

vector <tuple <int, int>> Compra::get_articulos(){
    return this->articulos;
};

void Compra::adicionar_producto(int id, int cantidad){
    tuple <int, int> mitupla(id, cantidad);
    this->articulos.push_back(mitupla);
};
