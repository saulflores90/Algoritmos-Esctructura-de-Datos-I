#include <iostream>
using namespace std;


 const int dim = 10;
 int M[dim][dim],fila,columna;
 int M1[dim][dim];
 void mostrarmatriz(int matriz[dim][dim],int dimensiones);
 void sumarmatriz(int matriz[dim][dim], int matriz1[dim][dim], int dimensiones);
 void restarmatriz(int matriz[dim][dim], int matriz1[dim][dim], int dimensiones);
 void multimatriz(int M[dim][dim], int M1[dim][dim], int dimensiones);
 void puntosSillamatriz(int matriz[dim][dim], int dimenciones);
 bool evaluateMatrix(int matriz[dim][dim], int posI, int posJ,int dimenciones);
 void trasponermatriz(int matriz[dim][dim],int dimensiones);


 int main()
 {
     int opcion, dimensiones;
     cout << "Determine la dimensiones de la matriz:";
     cin >> opcion;
     dimensiones = opcion;
    for(int i = 0; i < dimensiones; i++)
    {
        for(int j = 0; j < dimensiones; j++)
        {
            cout << "Ingrese la posicion A["<< i << "]" << "[" << j << "]"<< endl;
            cin >> fila;
            M[i][j] = fila;
        }
     }

     for(int i = 0; i < dimensiones; i++) 
     {
        for(int j = 0; j < dimensiones; j++)
        {
            cout << "Ingrese la posicion B["<< i << "]" << "[" << j << "]"<< endl;
            cin >> fila;
            M1[i][j] = fila;
        }
     }
     do {
        cout << "1 - Suma de matrices" << endl;
        cout << "2 - multiplicacion de matrices" << endl;
        cout << "3 - Resta de matrices" << endl;
        cout << "4 - Traspuesta de una matriz" << endl;
        cout << "5 - Punto silla de una matriz" << endl;
        cout << "0 - Salir" << endl;
        cin >> opcion;
            switch(opcion)
            {
                case 1:
                    //Suma de matrices
                    sumarmatriz(M,M1,dimensiones);
                    break;
                case 2:
                    //Producto de matrices
                    multimatriz(M,M1,dimensiones);
                    break;
                case 3:
                    //resta de matrices
                    restarmatriz(M,M1,dimensiones);
                    break;
                case 4:
                    // multiplicacion de matrices
                    trasponermatriz(M,dimensiones);
                    break;
                case 5:
                    // Traspuesta de una matriz
                     puntosSillamatriz(M,dimensiones);
                    break;            
                case 0:
                    //salimos
                    exit;
                    break;
                default:
                    //Dimensiones fuera de rango  
                    cout << "Dimensiones desconocida!" << endl;
                    break;
            }
        } while (opcion != 0);
return 0;
}

 void mostrarmatriz(int matriz[dim][dim],int dimensiones)
 {
     for(int i = 0; i < dimensiones; i++) {
        cout << "{" << " ";
        for(int j = 0; j < dimensiones; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout <<" " << "}" << endl;
    }
 }

void sumarmatriz(int matriz[dim][dim], int matriz1[dim][dim], int dimensiones)
{
    int R[dim][dim];

    for(int i = 0; i < dimensiones; i++) {
        for(int j = 0; j < dimensiones; j++)
        {
            R[i][j] = (matriz[i][j]+matriz1[i][j]);
        }
    }

    cout << "El resultado de la suma de sus matrices es: " << endl;
    mostrarmatriz(R,dimensiones);

}

void restarmatriz(int matriz[dim][dim], int matriz1[dim][dim], int dimensiones)
{
    int R[dim][dim];

    for(int i = 0; i < dimensiones; i++) {
        for(int j = 0; j < dimensiones; j++)
        {
            R[i][j] = (matriz[i][j]- matriz1[i][j]);
        }
    }

    cout << "El resultado de la resta de sus matrices es: " << endl;
    mostrarmatriz(R,dimensiones);
}

void multimatriz(int M[dim][dim], int M1[dim][dim], int dimensiones)
{
    int R[dim][dim];

    for(int i = 0; i < dimensiones; i++)
     {
        for(int j = 0; j < dimensiones; j++)
        {
          R[i][j]=0;
            for(int k = 0; k<dimensiones;k++)
            {
                R[i][j] += (M[i][k]*M1[k][j]);
            }
        }
    }
         
    cout << "El resultado del producto de sus matrices es: " << endl;
    mostrarmatriz(R,dimensiones);
}

void trasponermatriz(int matriz[dim][dim] , int dimensiones)
{
    int R[dim][dim];

    for(int i = 0; i < dimensiones; i++) {
        for(int j = 0; j < dimensiones; j++) {
           R[j][i] = matriz[i][j];
        }
    }
    cout << "La matriz A traspuesta da: " << endl;
    mostrarmatriz(R,dimensiones);
}

 /*Un punto de silla es el máximo valor de una fila y minimo valor de una columna. 
 Se recorre la matriz hallando el mayor valor de las filas y mínimo valor de las columnas,
 luego se almacenan dichos valores en dos vectores.*/
void puntosSillamatriz(int matriz[dim][dim],int dimenciones)
{
    int posFil = 0;
    int posCol = 0;
    for ( posFil = 0; posFil < dimenciones; posFil++)
    {
        for (posCol = 0; posCol < dimenciones; posCol++)
        {
            if (evaluateMatrix ( M,posFil,posCol,dimenciones))
               cout << "Punto silla: (" << posFil+1 << ", " << posCol+1 << ")." << endl; 
        }
    } 	
}
bool evaluateMatrix(int matriz[dim][dim], int posI, int posJ,int dimenciones)
{
    bool found = true;
    for (int i = 0; i < dimenciones && found; i++)
    {
        for (int j = 0; j < dimenciones && found; j++)
        {
            bool conditionA = (M[posI][posJ] > M[posI][j]);
            bool conditionB = (M[posI][posJ] < M[i][posJ]);
            if ( conditionA || conditionB )
                found = false;
        }
    }
    return found;
}