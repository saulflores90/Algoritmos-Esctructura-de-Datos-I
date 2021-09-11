/* c.Un Verdulería nos pide que armemos el pedido para
 el mayorista para lo cual deberemos pedir al usuario el código proveedor,
 razón social, fecha de solicitud y fecha de entrega.
 Las frutas estarán enumeradas (tomar solo 6 a modo de ejemplo),
 mostrando los datos x pantalla.*/

#include <iostream>
using namespace std;

enum  verduras{tomate = 1, lechuga, papa};

 int lista(int a);

int main()
{
   cout<< "**Verduleria**" << endl;
   int codProvedor = 3009;
   int  verduras = 0;
   int a;
   string data;
   cout<<"Razon Social:";
   getline(cin,data);
   cout<<"Armado de Nota de Pedido:"<<endl;
   cout<< "Seleccione  Verduras:"<<endl;
   cout<< "1.Tomate"<<endl;
   cout<< "2.Lechuga"<<endl;
   cout<< "3.Papa"<<endl;

   cout<< "Haga su Pedido:";
   cin>>a;

  cout<<"Proveedor:"<<codProvedor<<endl;
  cout<<"Razon Social:"<<data;
  cout<<endl;
  cout<<"Pedido"<<endl;
  cout<<lista(a);

 return 0;
}

int lista(int a)
{

int selec;
    if ((a>=1) && (a<=6))
      {
                  if (a == tomate){
                      cout<< "Cantidad de tomates:";
                      cin>>a;
                      cout<< "Kilos:"<< a<<endl;
                      }
                  if (a == lechuga){
                    cout<< "Cantidad de Lechuga:";
                    cin>>a;
                    cout<<"Kilos:"<<a;
                  }
                  if (a ==papa){
                    cout<< "Cantidad papa:";
                    cin>>a;
                    cout<<"Kilos:"<<a;
                  }
      }
return selec;
}
