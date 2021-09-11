/* a. Una aplicación para un restaurante que tiene: primer plato, plato principal y poste, toma pedidos de los mozos.
Estos envían la comanda codificada por número para cada plato. 
El cocinero recibe el pedido en formato de texto con el nro. de mesa,nombre mozo, fecha, hora, primer plato, plato principal y poste. Se pide desarrollar una APP que pida la comanda y muestre por pantalla la Info solicitada.*/

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

enum entrance{pizza=1,empanada,papas};
enum  main_dish{noquis=1,pollo,canelones};
enum dessert{helado=1,tiramisu,torta};

int menu_entrance(int a);
int menu_main(int b);
int menu_dessert(int c);

int main()
{
	int a,b,c;
	cout << "RestoBar"<<endl;
    cout << " Menu Primer Plato: "  << endl;
    cout <<"----------------------"<<endl;
    cout << " 1 - Pizza"        << endl;
    cout << " 2 - Empanada"         << endl;
    cout << " 3 - Papas"      << endl;
    cout << " Selecciona: " ;
    cin >> a;
    cout << "Menu Plato Principal: "<< endl;
    cout <<"----------------------"<<endl;
    cout << " 1 - Noquis"           << endl;
    cout << " 2 - Pollo"            << endl;
    cout << " 3 - Canelones"        << endl;
    cout << " Selecciona: "; 
    cin >> b;
    cout << "Menu Postre: "  << endl;
    cout <<"----------------------"<<endl;
    cout << " 1 - Helado"    << endl;
    cout << " 2 - Tiramisu"  << endl;
    cout << " 3 - Torta"     << endl;
    cout << " Selecciona: " ;
    cin >> c;
 time_t rawtime;
 time (&rawtime);
 cout<<endl;
 cout<<endl;
 cout<<"Comanda"<<endl;
 cout<<"----------------------"<<endl;
 cout<<"Horario del Pedido:"<< ctime (&rawtime);
 cout<<"Primer Plato:"<<menu_entrance(a)<<endl;
 cout<<"Plato Principal:"<<menu_main(b)<<endl;
 cout<<"Postre:"<<menu_dessert(c)<<endl;
return 0;
}


int menu_entrance(int a)
{
	if (a == pizza)cout<<"Pizza-";
    if (a == empanada)cout<<"Empanada-";
    if (a == papas) cout<<"Papas-";
	return a;
}
int menu_main(int b)
{
    if(b ==noquis)cout<<"Noquis-";
    if(b ==pollo)cout<<"Pollo-";
    if(b ==canelones)cout<<"Canelones-";
    return b;
}
int menu_dessert(int c)
{
    if(c ==helado)cout<<"Helado-";
    if(c ==tiramisu)cout<<"Tiramisu-";
    if(c ==torta)cout<<"Torta-";    
    return c;
}
