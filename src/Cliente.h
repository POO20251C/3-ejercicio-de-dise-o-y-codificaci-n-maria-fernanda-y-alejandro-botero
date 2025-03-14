#ifndef CLIENTE_H
#define cLIENTE_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "Compra.h"


using namespace std;
class Cliente{
private:
    string name_cliente;
    int cedula;
    //Adicionalmente el usuario tiene una lista de Objetos tipo Compra
    vector <Compra> compras;

public:
    //Constructor
    Cliente();   //Constructor Vacio
    Cliente(string name, int cedula);

    //Getters
    int get_cedula();
    string get_name();
    vector <Compra> get_compras();

    //Funcionalidades adicionales

    Compra* comprar();

    

};

#endif