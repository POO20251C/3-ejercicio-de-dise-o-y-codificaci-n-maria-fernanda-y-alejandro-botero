#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Producto{
private:
    //Atributos de la clase
    int id_producto;
    int CantidadDisponible;
    float Precio;
    string nombre;

public:
    //Constructor vacio
    Producto();
    Producto(int id_producto, int CantidadDisponible, float precio, string nombre);

    //Getters

    int get_id();
    int get_CantidadDisponible();
    float get_Precio();
    string get_nombre();

    //setters

    void set_CantidadDisponible(int CantidadDisponible);
    void set_Precio(float Precio);
};

#endif