#include <string>
#include <vector>

using namespace std;

class Producto{
private:
    string name;
    string id;
    int stock;
    float precio;
public:
	//Constructor de la clase 
    Producto();
    Producto(string name, int id, int stock, float precio);
	
    //Getters
    string getName();
    string getId();
    int getstock();
    float getprecio();
    
    //Setters
    void setName(string name);
    void setId(string id);
    void setStock(int id);
    void setPrecio(float precio);   
};