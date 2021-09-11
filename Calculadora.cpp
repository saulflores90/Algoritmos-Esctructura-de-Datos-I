#include <iostream>
using namespace std;

double sumar(double a, double b);
double restar(double a, double b);
double dividir(double a, double b);
double multiplicar(double a, double b);

int main()
{
int menu;
cout << "Calculadora"<< endl;
cout << "Seleccione una opcion ingresando el valor de la opcion"<< endl;
cout << "Opcion 1 = Sumar"<< endl;
cout << "Opcion 2 = Restar "<< endl;
cout << "Opcion 3 = Dividir"<< endl;
cout << "Opcion 4 = Multiplicar"<<endl;
cout << "Seleccione:";
cin >> menu;

if (menu == 1)
{
    double a , b;
	cout << "Selecciono Sumar"<< endl;
	cout << "Ingrese Primer Valor:";
	cin >> a;
	cout << "Ingrese Segundo Valor:";
	cin >> b;
	cout << "Suma="<<sumar(a,b);

}
 else if (menu == 2)
{
	double a, b;
	cout << "Selecciono Restar"<< endl;
	cout << "Ingrese Primer Valor:";
	cin >> a;
	cout << "Ingrese Segundo Valor:";
	cin >> b;
	cout << "Resta="<< restar(a,b);
}
else if (menu == 3)
{
	double a, b;
	cout << "Selecciono Dividir"<< endl;
	cout << "Ingrese Primer Valor:";
	cin >> a;
	cout << "Ingrese Segundo Valor:";
	cin >> b;
	cout << "Division="<< dividir(a,b);
}
else if (menu == 4)
{
	double a, b;
	cout << "Selecciono Multiplicar"<< endl;
	cout << "Ingrese Primer Valor:";
	cin >> a;
	cout << "Ingrese Segundo Valor:";
	cin >> b;
	cout << "Multiplicacion="<< multiplicar(a,b);
}
else if (menu<4 or menu>1)
{
	cout << "Error de Calculadora";
}
	return 0;
}

double sumar(double a, double b)
{
	double sum;
	sum= a+b;
	return sum;
}
double restar(double a, double b)
{
	double res;
	res= a-b;
	return res;
}
double dividir(double a, double b)
{
	double div;
	div=a/b;
	return div;
}
double multiplicar(double a, double b)
{
	double mul;
	mul=a*b;
	return mul;
}