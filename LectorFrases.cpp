Escribe un programa que lea del teclado una frase y a continuación visualice las palabras de la frase en columna, seguida cada una del número de letras que la componen.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string frase;
string palabras;

int main()
{
	cout << "Introduzca una frase para procesar: ";
	getline(cin, frase);

	ofstream out_file;
	out_file.open("frase.txt", ios::out);
	if(out_file.is_open())
	{
		out_file << frase;
	}
	out_file.close();

	ifstream inp_file;
	inp_file.open("frase.txt", ios::in);
	if(inp_file.is_open())
	{
		while(!inp_file.eof())
		{
			inp_file >> palabras;
			cout << palabras << " -> numero de letras: " << palabras.length() << endl;
		}
	}
	inp_file.close();

	cin.get();

	return 0;
}
