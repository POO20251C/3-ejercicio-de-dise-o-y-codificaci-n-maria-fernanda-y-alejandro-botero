#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <vector>
#include "Producto.h"
#include "Cliente.h"


using namespace std;


class Tienda{
private:
    string nombre;
    vector <Cliente> clientes;
    vector <Producto> productos;
public:
    //Constructor
    Tienda();
    Tienda(string nombre);
    
    //getters
    string get_name();
    vector <Cliente> get_clientes();
    vector <Producto> get_productos();

    //setters 

    void set_producto(int Precio, int Cantidad);
    //Funcionalidades

    //El menu inicial debe de tener estas tres opciones
    //1. Admin, 2.Crear Usuario, 3.Iniciar Sesion
    //En admin debe de haber dos opciones: ver clientes registrados, ver productos, modificar productos

    void registrar_producto(string nombre, int cantidad, float precio);
    Cliente* registrar_compra(string nombre, int cedula);
    Producto* buscar(int id);
};


#endif