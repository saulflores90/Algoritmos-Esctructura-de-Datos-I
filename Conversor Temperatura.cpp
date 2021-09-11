#include <iostream>
using namespace std;

double conversorf(double temp);
double conversorc(double tempe);

int main()
{
int menu;
double fahr,cel;
cout << "Programa conversor de Temperatura"<< endl;
cout << "Seleccione una opcion ingresando el valor de la opcion"<< endl;
cout << "Opcion 1 = Conversor de Grados Fahrenheit a Celsius"<< endl;
cout << "Opcion 2 = Conversor de Grados Celsius a Fahrenheit"<< endl;
cout << "Seleccione:";
cin >> menu;
if(menu == 1 )
    {
	   cout << "Conversor de Grados Fahrenheit a Celsius"<< endl;
	   cout << "Ingrese Grados Fahrenheit:";
	   cin >> fahr;
	   cout << "Grados Celsius=" << conversorf(fahr) ;
	  }
	else if (menu == 2 )
	{
	cout << "Conversor de Grados Celsius a Fahrenheit"<< endl;
	cout << "Ingrese Grados Celsius:";
	cin >> cel;
	cout << "Grados Fahrenheit="<< conversorc(cel);
	}
	else if (menu<2 or menu >1)
	{
		cout << "Error en seleccion"<< endl;
	}
	return 0;
} 


double conversorf(double temp)
{
  double cels; 
  cels = (5*(temp-32))/9;
  return cels;
}
double conversorc(double tempe)
{
  double cels2;
  cels2= ((tempe*9)/5)+32;
  return cels2;
}