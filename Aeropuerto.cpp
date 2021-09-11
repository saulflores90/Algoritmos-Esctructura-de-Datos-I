/* b.  Una empresa de viaje nos pide que realicemos un 
programa para tomar reservas en avión, las mismas pueden ser clase Primera,
 Bussiness y económica, además del DNI apellido y nombre, aeropuerto origen
 y destino:
Código Aeropuerto
1. Bahía Blanca-BHI
2. Buenos Aires Aeroparque-AEP
3. Buenos Aires El Palomar-EPA
4. Buenos Aires Ezeiza-EZE
5. San Carlos de Bariloche-BRC
6. San Fernando del Valle de Catamarca-CTC
7. Comodoro Rivadavia-CRD
El usuario introduce los datos personales, la clase y el origen – 
destino, mostrando el resultado x pantalla*/

#include <iostream>
#include <string>
using namespace std;

enum clase{primera_clase=1,bussiness,turista};
enum codigo_air{bhi=1,aep,epa,eze,brc,ctc,crd};


int clase(int a);
int codigo_air_origen(int b);
int codigo_air_destino(int c);


int main()
{
	string nombres, apellido;
    int a,b,c,dni=0;
	cout << "Aeropuerto"<<endl;
    cout <<"Seleccione Clase de Vuelo:"<<endl;
    cout <<"-----------------------------"<<endl;
    cout <<"1. Primera Clase"<<endl;
    cout <<"2. Business"<<endl;
    cout <<"3. Economica"<<endl;
    cout << " Seleccione:";
    cin >>a;
    cout <<"Codigo Aeropuerto-Seleccione-Origen:"<<endl;
    cout <<"------------------------------------"<<endl;
    cout <<"1. Bahia Blanca-BHI"<<endl;
    cout <<"2. Buenos Aires Aeroparque-AEP"<<endl;
    cout <<"3. Buenos Aires El Palomar-EPA"<<endl;
    cout <<"4. Buenos Aires Ezeiza-EZE"<<endl;
    cout <<"5. San Carlos de Bariloche-BRC"<<endl;
    cout <<"6. San Fernando del Valle de Catamarca-CTC"<<endl;
    cout <<"7. Comodoro Rivadavia-CRD"<<endl;
    cout << " Seleccione: ";
    cin >> b;
    cout <<"Codigo Aeropuerto-Seleccione-Destino:"<<endl;
    cout <<"------------------------------------"<<endl;
    cout <<"1. Bahia Blanca-BHI"<<endl;
    cout <<"2. Buenos Aires Aeroparque-AEP"<<endl;
    cout <<"3. Buenos Aires El Palomar-EPA"<<endl;
    cout <<"4. Buenos Aires Ezeiza-EZE"<<endl;
    cout <<"5. San Carlos de Bariloche-BRC"<<endl;
    cout <<"6. San Fernando del Valle de Catamarca-CTC"<<endl;
    cout <<"7. Comodoro Rivadavia-CRD"<<endl;
    cout << " Seleccione: ";
    cin >> c;
    cout<<"Ingresa tu DNI:";
    cin >> dni;
    cout<<"Nombres:";
    cin>>nombres;
    getline(cin,nombres);
    cin.sync();
    cout<<"Apellidos:";
    getline(cin,apellido);
    cout<<endl;
    cout <<"-----------------------------"<<endl;
    cout <<"-----------------------------"<<endl;
    cout <<"Datos de Pasajero:"<<endl;
    cout <<"Nombre completo:"<<nombres<<" "<<apellido<<endl;
    cout <<"DNI:"<< dni<<endl;
    cout <<"Clase de Vuelo:"<<clase(a)<<endl;
    cout <<"Codigo Aeropuerto-Seleccione-Origen:"<<codigo_air_origen(b)<<endl;
    cout <<"Codigo Aeropuerto-Seleccione-Destino:"<<codigo_air_destino(c)<<endl;
return 0;
}


int clase(int a)
{
	if (a == primera_clase)cout<<"Primera clase-";
    if (a == bussiness )cout<<"Business-";
    if (a == turista)cout<<"Turista-";
    return a;
}
int codigo_air_origen(int b)
{
    if (b ==bhi )cout<<"Bahia Blanca-";
    if (b ==aep )cout<<"Buenos Aires Aeroparque-";
    if (b ==epa )cout<<"Buenos Aires El Palomar-";
    if (b ==eze )cout<<"Buenos Aires Ezeiza--";
    if (b ==brc )cout<<"San Carlos de Bariloche-";
    if (b ==ctc )cout<<"San Fernando del Valle de Catamarca-";
    if (b ==crd )cout<<"Comodoro Rivadavia-";
    return b;
}
int codigo_air_destino(int c)
{
    if (c ==bhi )cout<<"Bahia Blanca-";
    if (c ==aep )cout<<"Buenos Aires Aeroparque-";
    if (c ==epa )cout<<"Buenos Aires El Palomar-";
    if (c ==eze )cout<<"Buenos Aires Ezeiza--";
    if (c ==brc )cout<<"San Carlos de Bariloche-";
    if (c ==ctc )cout<<"San Fernando del Valle de Catamarca-";
    if (c ==crd )cout<<"Comodoro Rivadavia-";
    return c;
}
