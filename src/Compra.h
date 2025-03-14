#ifndef COMPRA_H
#define COMPRA_H

#include <string>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
class Compra{
private:
    int id_compra;
    vector <tuple <int , int>> articulos;  
public:
    //Constructor
    Compra();
    Compra(int id); //Simplemente crear el   objeto con el identificador
    
    //getters
    int get_id();
    vector <tuple <int, int>> get_articulos();

    //Funcionalidades Adicionales
    void adicionar_producto(int id_producto, int cantidadComprada);
};

#endif