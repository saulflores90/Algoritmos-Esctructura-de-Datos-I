/*1.Un archivo de texto contiene información acerca de los productos que se venden en un almacén.
 Lo único que se sabe acerca del número de productos es que no puede superar un cierto valor MaxProductos.
  De cada producto se guarda información sobre su código identificador (entero positivo), su precio (real) 
  y el número de unidades existentes (entero positivo). El formato en el que se guarda la información dentro
  del archivo es el siguiente:

id1 precio1 unidades1
id2 precio2 unidades2
...
idN precioN unidadesN

a) Declara un tipo tProducto que represente la información de un producto y
un tipo tLista que mantenga la información de todos los productos.
b) Escribe un subprograma que lea los datos del archivo de texto que almacena
la información, los guarde en la lista y luego los muestre en la pantalla.
c) Escribe un subprograma que encuentre el producto con máximo valor en el
almacén, considerando que el valor del producto i es precioi*unidadesi.
d) Escribe un subprograma que dado un identificador de producto a eliminar
del almacén, lo busque en la lista y lo elimine actualizando la lista como
corresponda.*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int MaxProducto = 50;
typedef struct{
    int articulo;
    double precio;
    int unidades;
} tAlmacen;

typedef tAlmacen tProductos[MaxProducto];

typedef struct{
    tProductos elementos;
    int contador;
} tLista;

int i;
void cargarArchivo(tLista &lista); //listo
void guardarArchivo(tLista &lista); //listo
void addProducto(tLista &lista, bool &ok); //listo 
void modificarProducto(tLista &lista,int articulo);//listo
void buscarProducto(tLista lista);//listo
void buscarProductoMayorPrecio(tLista lista);
void buscarProductoMayorStock(tLista lista);
void eliminarProducto(tLista &lista, int articulo);//listo 
void mostrarLista(tLista lista);//listo



int main(){
    tLista lista;
    int opcion, auxArticulo;
    bool ok;
    lista.contador = 0;
    cargarArchivo(lista);
  
    do {
        cout << "1 - Agregar Producto" << endl;
        cout << "2 - Buscar Producto" << endl;
        cout << "3 - Eliminar Producto" << endl;
        cout << "4 - Buscar Articulo de Mayor Precio" << endl;
        cout << "5 - Buscar Producto con Mayor Stock" << endl;
        cout << "6 - Mostrar Lista de Productos" << endl;
        cout << "0 - Salir" << endl;
        cin >> opcion;

            switch(opcion)
            {
                case 1:
                    //Agregar un Producto
                    if (lista.contador < 50)
                    {
                        addProducto(lista,ok);
                        break;
                    }
                    else cout << "Máximo de Productos" << endl;
                case 2:
                    //Buscar un Producto
                    buscarProducto(lista);
                    break;
                case 3:
                    //Eliminar Productos
                    cout << "Ingrese el articulo del producto que desee eliminar: ";
                    cin >> auxArticulo;
                    eliminarProducto(lista,auxArticulo);
                    break;
                case 4:
                    //Buscar Articulo de Mayor Precio
                    buscarProductoMayorPrecio(lista);
                    break;
                case 5:
                    //  Buscar Producto con Mayor Stock
                    buscarProductoMayorStock(lista);
                    break;
                case 6:
                    //  Mostrar lista de Productos
                    mostrarLista(lista);
                    break; 
                case 0:
                    //Guardamos y salimos
                    guardarArchivo(lista);
                    break;
                default:
                    //Opcion fuera de rango  
                    cout << "Opcion desconocida!" << endl;
                    break;
            }
        } while (opcion != 0);
return 0;
}

void cargarArchivo(tLista &lista)
{
    ifstream texto;
    texto.open("almacen.txt", ios::in);
    if(texto.is_open())
    {
        while (!texto.eof())
        {
            texto >> lista.elementos[lista.contador].articulo;
            texto.get( );
            texto >> lista.elementos[lista.contador].precio;
            texto.get( );
            texto >> lista.elementos[lista.contador].unidades;
            
        if((!lista.elementos[lista.contador].articulo == 0 )&&(!lista.elementos[lista.contador].precio == 0 )&&(!lista.elementos[lista.contador].unidades == 0))
        lista.contador++;            
        }
    }
    texto.close();
}

void guardarArchivo(tLista &lista)
{
    ofstream gArchivo;
    gArchivo.open("almacen.txt", ios::out);
    if(gArchivo.is_open())
    {
        for(i = 0; i < lista.contador; i++)
        {
        gArchivo << lista.elementos[i].articulo << " ";
        gArchivo << lista.elementos[i].precio << " ";
        gArchivo << lista.elementos[i].unidades << " ";
       
        }
    }
    gArchivo.close();
}

void addProducto(tLista &lista, bool &ok)
{
    tAlmacen productos;
    ok = true;

    cout << "Ingrese Articulo: ";
    cin.ignore();
    cin >>  productos.articulo;
    cout << "Ingrese  Precio: ";
    cin >> productos.precio;
    cout << "Ingrese Cantidad en Unidades: ";
    cin >> productos.unidades;
   
    if(lista.contador == MaxProducto)
    {
        ok = false;
    } else {
        int i = 0;
        while ((i < lista.contador) )
        {
            i++;
        }
        for(int j = lista.contador; j > i; j--)
        {
            lista.elementos[j] = lista.elementos[j - 1];
        }
        lista.elementos[i] = productos;
        lista.contador++;
    }
}

void modificarProducto(tLista &lista,int articulo)
    {
    tAlmacen productos;

    if((lista.elementos[i].articulo == articulo))
        {
        int opcion1;

        do {
            cout << "1 - Cambiar articulo" << endl;
            cout << "2 - Cambiar precio" << endl;
            cout << "3 - Cambiar unidades" << endl;
            cout << "0 - Salir" << endl;
            cin >> opcion1;
            switch (opcion1){
            case 1:
                    //modificar articulo
                    cout << "Ingrese nuevo Articulo: ";
                    cin >> productos.articulo;
                    lista.elementos[i].articulo = productos.articulo;
                    break;
            case 2:
                    //modificar precio
                    cout << "Ingrese nuevo Precio: ";
                    cin >>  productos.precio;
                    lista.elementos[i].precio = productos.precio;
                    break;
            case 3:
                    //modificar unidades
                    cout << "Cambiar cantidad en unidades: ";
                    cin >> productos.unidades;
                    lista.elementos[i].unidades = productos.unidades;
                    break;
                default:
                    cout << "Opcion desconocida!" << endl;
                    break;
                    }
            } while (opcion1 != 0);
        }
  }

void eliminarProducto(tLista &lista,int articulo)
{
    int pos = 0;
    for(i = 0; i < lista.contador; i++)
    {
        if((lista.elementos[i].articulo == articulo))
        {
            pos = i;
            for(i = pos; i < lista.contador - 1; i++)
            {
             lista.elementos[i] = lista.elementos[i+1];
            }
            lista.contador = (lista.contador - 1);
            cout << "Produto eliminado correctamente!" << endl;
            cout << " " << endl;
        }
    }
}

void mostrarLista(tLista lista)
{
    cout << "Listado de Productos:" << endl;
    cout << " " << endl;
    for(i = 0; i < lista.contador; i++)
    {
        cout << setw(4) << "-id: "  << lista.elementos[i].articulo<< setw(8) << " Precio= $" << lista.elementos[i].precio << setw(16) << "Unidades: "<< lista.elementos[i].unidades << endl;
    }
}

void buscarProducto(tLista lista)
{
    double id;
    cout << "Ingrese id Articulo:" << endl;
    cin >> id;
    for(i=0; i < lista.contador; i++)
        {
            if((lista.elementos[i].articulo == id ) )
            {
            cout << setw(4) << "-id: "  << lista.elementos[i].articulo<< setw(8) << " Precio= $" << lista.elementos[i].precio << setw(16) << "Unidades: "<< lista.elementos[i].unidades << endl;
            }
        }
}

void buscarProductoMayorPrecio(tLista lista)
{
    cout << "id de mayor precio:" << endl;
    double maximo = 0,temp = 0;
    int id_maximo;
    for (i=0; i< lista.contador; i++)
    {
        if(lista.elementos[i].precio * lista.elementos[i].unidades >= maximo)
           {
               maximo = (lista.elementos[i].precio * lista.elementos[i].unidades);
               id_maximo = lista.elementos[i].articulo;
               temp= lista.elementos[i].precio;
           }
    }
    cout << "El maximo Precio de almacen es: " << temp << endl;
    cout << "Corresponde al id-articulo de producto: " << id_maximo << endl;
    cout << endl;
}
        


void buscarProductoMayorStock(tLista lista)
{
    cout << "id de mayor stock:" << endl;
  
    double maximo = 0, temp =0;
    int id_maximo;
    for (i=0; i< lista.contador; i++)
    {
        if(lista.elementos[i].precio * lista.elementos[i].unidades >= maximo)
           {
               maximo = (lista.elementos[i].precio * lista.elementos[i].unidades);
               id_maximo = lista.elementos[i].articulo;
               temp= lista.elementos[i].unidades;
           }
    }
    cout << "El maximo stock en almacen es: " << temp << endl;
    cout << "Corresponde al id-articulo de producto: " << id_maximo << endl;
    cout << endl;
}
        

