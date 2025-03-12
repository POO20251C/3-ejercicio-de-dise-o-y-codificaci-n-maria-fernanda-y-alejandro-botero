#include <string>
#include <vector>
#include "Compra.h"


using namespace std;

class Tienda{
private:
    int num;
public:
    Tienda();  

};
class Cliente{
private:
    int id;    //Id asociado al cliente
    string name;  //Nombre de registro del cliente
    vector <Compra> compras;
public:
    //Constructores
    Cliente();  //Constructor vacio
    Cliente(int id, string name);  //Constructor con parametros

    //Getters
    int get_id();   //funcion para obtener el id de un cliente
    string get_name();  //funcion para obtener el nombre del cliente
    vector <Compra> get_compras();
    //setters
    void set_name(string name);  //funcion para cmabiar el nombre del cliente

    //funcionalidades adicionales
    Compra comprar(Tienda* tienda);
    void mostrar_compras();    
};