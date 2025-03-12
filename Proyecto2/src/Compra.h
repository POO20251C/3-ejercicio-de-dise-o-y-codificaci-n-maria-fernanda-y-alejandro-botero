#include <string>
#include <vector>
#include <tuple>

using namespace std;
class Compra{
private:
    vector <tuple <int, int >> items;
    int id_compra;
public:
    //Constructores
    Compra();       //Constructor vacio
    Compra(int id_compra);    //constructor con parametros

    //Getters

    vector <tuple <int, int >> get_compra();

    //funcionalidades adicionales

    void adicionar_producto_a_compra(int id_product, int cantidad);
};