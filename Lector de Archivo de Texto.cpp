a.Crea un programa que vaya leyendo las frases que el usuario teclea y
 las guarde en un fichero de texto llamado “frasesDeBjarme.txt”. 
 Terminará cuando la frase introducida sea "fin" 
 (esa frase no deberá guardarse en el fichero).

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
  {
   string nif, escritura;
   ofstream archivo;
   archivo.open("frasesDeBjarme.txt");
   cout << "Nota o Fin para Salir:";
   cin>> nif;
   while (nif != "fin")
                     {
                     cout << "Nota:";
                     getline(cin, escritura);
                     archivo << escritura << endl;
                     cout << "Desea Terminar ingrese Fin:";
                     cin>>nif;
                     if ( nif == "fin")
    {
        cout<< "Closed";
    }
                     }
   archivo.close();
   return 0;
  }

