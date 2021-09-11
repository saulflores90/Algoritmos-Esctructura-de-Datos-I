/*c.	Para el  Archivo del ejercicio (a) contar la cantidad de palabras que hay x l�nea,
 luego mostrar la cantidad total y el averageedio de palabras x l�nea.
*/
# include <iostream>
# include <string >
# include <fstream>
using namespace std ;

void  readPharse () ;

int main ()
{
   readPharse () ;
   return 0 ;
}

void readPharse()
{
ifstream  file ;
char character ;
float amountWords = 0 ;
float amountLine = 0 ;
float average ;

file.open ("frasesDeBjarme.txt" );
        while (!file.eof())
        {
        character = file.get();
                if (character == ' ' || character == '\n')
                {
                amountWords++;
                if (character == '\n')
                        {
                        amountLine++;
                        }
                }   
        }

average = amountWords / amountLine ;

cout << "La cantidad de linea son " << amountLine << endl  ;
        cout << "La cantidad total de palabras es " << amountWords << endl ;
        cout << "El averageedio de palabras por lineas es " << average << endl ;

file.close();
}
