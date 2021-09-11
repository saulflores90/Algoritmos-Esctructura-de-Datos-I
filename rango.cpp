#include <iostream>
using namespace std;

int main()
{
	int rango1, rango2, digito;
	cout <<"Determine su rango"<<endl;
	cout <<"Ingrese su rango"<<endl;
	cout <<"Primer valor del rango:";
	cin >> rango1;
    cout <<"Segundo valor del rango:";
    cin >> rango2;
    cout <<"Rango="<< "["<<rango1<<"-"<<rango2<<"]"<<endl;
    cout <<"Rango determinado"<<endl;
    cout << "Digite un valor y chequear si se encuentra en el rango"<<endl;
    cout << "Digite valor=";
    cin >> digito;
    if ((digito>=rango1) && (digito<=rango2))
    {
        cout<<"digito dentro de rango";
    }
   else
   	cout << "digito fuera de rango";

	return 0;
}
