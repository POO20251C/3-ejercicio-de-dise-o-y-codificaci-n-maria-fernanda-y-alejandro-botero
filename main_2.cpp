#include "src/Tienda.h"
#include <iostream>
#include <string>
#include <tuple>

using namespace std;


int main() {
    // Crear una tienda
    Tienda tienda("Super Shop");
    
    Cliente* cliente;
    Compra* micompra;
    Producto* producto_seleccionado;
    int opcion;
    int cantidad, cantidad_comprar, id_producto, cedula;
    float precio;
    string nombre, nombre_cliente, salir;
    cout << "Bienvenido a la Tienda " << tienda.get_name() << endl;

    while (true) {
        cout << "\nOpciones:\n";
        cout << "1. Registrar Producto\n";
        cout << "2. Registrar Compra\n";
        cout << "3. Mostrar Productos\n";
        cout << "4. Mostrar Clientes\n";
        cout << "5. Buscar Compras\n";
        cout << "6. Modificar Producto\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Registrar un producto\n" << endl;
                cout << "Ingresa los siguientes datos: \n" << endl;
                cout << "\nNombre del Producto:";
                cin >> nombre;
                cout << "\nPrecio:";
                cin >> precio;
                cout << "\nCantidad Disponible";
                cin >> cantidad;
                tienda.registrar_producto(nombre, cantidad, precio);
                break;
            case 2:
                cout << "Registrar una Compra\n" << endl;
                cout << "Ingresa el nombre del cliente\n" << endl;
                cout << "Cliente nombre: ";
                cin >> nombre_cliente;
                cout << "Ingresa la cedula del cliente\n" << endl;
                cin >> cedula;
                cliente = tienda.registrar_compra(nombre_cliente, cedula);
                micompra = cliente->comprar();                
                while(true){
                    for(Producto& p: tienda.get_productos()){
                        cout << p.get_id() << " " << p.get_nombre() << " " << p.get_Precio() << "\n" << endl; 
                    }
                    cout << "\nIngrese la informacion del producto( id y cantidad de producto a comprar )\n ";
                    cout << "Id: ";
                    cin >> id_producto;
                    cout << "Cantidad: ";
                    cin >> cantidad_comprar;
                    producto_seleccionado = tienda.buscar(id_producto);
                    if( producto_seleccionado == nullptr){
                        cout << "Producto no encontrado" << endl;
                    }else{
                        if( producto_seleccionado->get_CantidadDisponible() < cantidad_comprar){
                            cout << "Upss no tenemos todo eso, solo tenemos " << producto_seleccionado->get_CantidadDisponible() << "\n" << endl;
                            cout << "Intentalo de Nuevo\n" << endl;  
                        }else{
                            
                            micompra->adicionar_producto(id_producto, cantidad_comprar);
                            //Actualizar cantidad Disponible
                            int nueva_cantidad = producto_seleccionado->get_CantidadDisponible() - cantidad_comprar;
                            producto_seleccionado->set_CantidadDisponible(nueva_cantidad);
                            //
                            cout << "Desea adicionar otro producto a su compra?[y/n]\n";
                            cin >> salir;
                            if(salir == "n"){
                                break;
                            }
                        }
                    }    
                    
                }
                break;
            case 3:
                for(Producto& p: tienda.get_productos()){
                    cout << p.get_id() << " " << p.get_nombre() << " " << p.get_Precio() << " " << p.get_CantidadDisponible() << "\n" << endl; 
                }
                break;
            case 4:
                for(Cliente& c: tienda.get_clientes()){
                    cout << c.get_name() << " " << c.get_cedula() << " " << c.get_compras().size() << "\n" << endl;
                }  
                break; 
            case 5:
                //Esta funcionalidad permite ver las compras que tiene un cliente registradas en el sistema
                for(Cliente& c: tienda.get_clientes()){
                    cout << c.get_name() << " " << c.get_cedula() << " " << c.get_compras().size() << "\n" << endl;
                }  

                cout << "Ingresa la cedula del Cliente que deseas revisar: ";
                cin >> cedula;
                Cliente* cliente_seleccionado;
                for (Cliente& c : tienda.get_clientes()) {
                    if (c.get_cedula() == cedula) {
                        cliente_seleccionado = &c;
                        break; // Ya encontramos al cliente, no hace falta seguir buscando
                    }
                }
                
                if (cliente_seleccionado == nullptr) {
                    cout << "Cliente no encontrado en el sistema.\n";
                } else {
                    cout << "\nCompras del cliente " << cliente_seleccionado->get_name() << ":\n";
                
                    // Recorrer las compras del cliente
                    for (Compra& comp : cliente_seleccionado->get_compras()) {
                        cout << "Compra " << comp.get_id() << "\n";
                        float total = 0;
                
                        // Recorrer los artículos de la compra
                        for (tuple<int, int>& tup : comp.get_articulos()) {
                            id_producto = get<0>(tup);
                            cantidad_comprar = get<1>(tup);
                            producto_seleccionado = tienda.buscar(id_producto);
                
                            // Validar que el producto exista antes de acceder a sus atributos
                            if (producto_seleccionado) {
                                cout << producto_seleccionado->get_nombre() << " - Precio: $" 
                                     << producto_seleccionado->get_Precio() << "\n";
                                total += producto_seleccionado->get_Precio()*cantidad_comprar;
                            } else {
                                cout << "Producto con ID " << id_producto << " no encontrado en la tienda.\n";
                            }
                        }
                        cout << "Total de la compra: $" << total << "\n\n";
                    }
                }
                break;    
            case 6:
                //Muestras los productos
                for(Producto& p: tienda.get_productos()){
                    cout << p.get_id() << " " << p.get_nombre() << " " << p.get_Precio() << " " << p.get_CantidadDisponible() << "\n" << endl; 
                }
                
                cout << "\nIngrese el ID del producto a modificar: ";
                cin >> id_producto;
                
                for (Producto& p : tienda.get_productos()) {
                    if(p.get_id() == id_producto){
                        cout << "Nuevo precio: ";
                        cin >> precio;
                        cout << "Nueva cantidad: ";
                        cin >> cantidad;
                        p.set_CantidadDisponible(cantidad);
                        p.set_Precio(precio);
                        cout << "Producto actualizado.\n";
                        break;
                    }
                }
                break;     
            case 7:
                break;                            
                 

        }
        if( opcion == 7){
            break;
        }
    }    

    return 0;
}