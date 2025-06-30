#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTOS=100;
const int MAX_VENTAS=100;

struct Producto{
    string nombre;
    float precio;
};

struct Venta{
    int idVenta;
    string producto;
    int cantidad;
    float precioTotal;
};

Producto productos[MAX_PRODUCTOS];
Venta ventas[MAX_VENTAS];
int cantidadProductos=0;
int cantidadVentas=0; 
int contadorVentas=1;

void registrarProducto(){
    if(cantidadProductos>=MAX_PRODUCTOS){
        cout<<"No se pueden agregar más productos"<<endl;
    } else{
    Producto nuevoProducto;
    cout<<"Ingrese el nombre del producto: ";
    getline(cin, nuevoProducto.nombre);
    cout<<"Ingrese el precio del producto: ";
    cin>>nuevoProducto.precio;
    cin.ignore();
    productos[cantidadProductos]=nuevoProducto;
    cantidadProductos++;
    cout<<"Producto registrado"<<endl;
	}
}

void listarProductos(){
    if(cantidadProductos==0){
        cout<<"No hay productos registrados"<<endl;
    } else{	
    	for(int i=0; i<cantidadProductos; i++){
        	cout<<"Producto #"<<(i + 1)<<endl;
        	cout<<"Nombre: "<<productos[i].nombre<<endl;
        	cout<<"Precio: "<<productos[i].precio<<endl;
    	}
    }
}

void buscarProducto(){
    string nombreBusqueda;
    cout<<"Ingrese el nombre del producto a buscar: ";
    getline(cin, nombreBusqueda);
    bool encontrado=false;
    for (int i=0; i<cantidadProductos; i++){
        if (productos[i].nombre==nombreBusqueda){
            cout<<"Producto encontrado:"<<endl;
            cout<<"Nombre: "<<productos[i].nombre<<endl;
            cout<<"Precio: "<<productos[i].precio<<endl;
            encontrado = true;
            break;
        }
    }
    if (encontrado==false){
        cout<<"Producto no encontrado"<<endl;
    }
}

int main(){
	int opcion;
    do{
        cout<<"\n --- Menu --- \n";
        cout<<"1. Registrar un nuevo producto\n";
        cout<<"2. Listar los productos registrados\n";
        cout<<"3. Buscar un producto por nombre\n";
        cout<<"4. Actualizar los datos de un producto\n";
        cout<<"5. Eliminar un producto\n";
        cout<<"6. Registrar una venta\n";
        cout<<"7. Listar las ventas realizadas\n";
        cout<<"8. Calcular el total de ventas realizadas\n";
        cout<<"9. Salir del programa\n";
        cout<<"Seleccione una opcion: ";
        cin>>opcion;
        cin.ignore();
        switch(opcion){
            case 1:
                registrarProducto();
                break;
            case 2:
                listarProductos();
                break;
            case 3:
                buscarProducto();
                break;
            case 4:
                //actualizarProducto();
                break;
            case 5:
                //eliminarProducto();
                break;
            case 6:
                //registrarVenta();
                break;
            case 7:
                //listarVentas();
                break;
            case 8:
                //calcularTotalVentas();
                break;
            case 9:
                cout<<"Saliendo..."<<endl;
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                break;
        }
    } while(opcion!=9);
	return 0;
}
