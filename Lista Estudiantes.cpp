Desarrollar un Programa que mantenga una lista de los estudiantes de Algoritmos y Estructuras de Datos I.
Se deberán tener en cuenta las siguientes particularidades:
a.	De cada estudiante: nombre, apellidos, edad, DNI y nota
b.	Se desconoce el número total de estudiantes (máximo 50)
c.	La información de la lista se mantiene en un archivo AyEDI.txt
d.	Se carga el Archivo en Memoria llenando la Estructura al empezar y se guarda la estructura al finalizar el Programa en el mismo Archivo sobrescribiéndolo..

El programa debe ofrecer estas opciones:
e.	Añadir un nuevo alumno
f.	Eliminar un alumno existente
g.	Calificar a los estudiantes
h.	Listado de notas, identificando la mayor y la media
Para un mejor desarrollo tener en cuenta:
i.	Deberán realizar una Estructura para la lista que contenga el array, cantidad de alumnos y estructura del alumno.
j.	Deberán priorizar la Modularización (mediante funciones que permitan: Cargar, Leer, guardar e insertar alumnos).
k.	Deberán tener una Función para leer el Archivo cuando arranca el programa y otra para guardar la estructura de los Alumnos, se lee todo el archivo cuando arranca, se modifica en memoria (las estructuras) y se guardan todos los Alumnos sobrescribiendo el archivo original.
l.	Para el menú un Do..While con las opciones Solicitadas, que deberán llamar a las Funciones Desarrolladas, recibiendo como parámetro la Estructura, cantidad de elementos y demás.
m.	Trate de Mantener el “Nivel de Abstracción” desde lo General a lo Particular, es decir, no arranque a Codificar, Piense en “Macro” (que debe hacer el Programa) … Estructure lo que hace en Funciones, modularizando el programa y Minimizando el Main().
n.	La función Principal (Main) deberá contener el menú y las llamadas a las Funciones y todo el código de Definición de Variables.
o.	El problema se resuelve con los prácticos anteriores y en caso de necesitar revea el material visto en clase, debería ser suficiente para desarrollarlo.


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX = 50;
typedef struct{
    string nombre;
    string apellido;
    string calificacion;
    string dni;
} tAlumno;

typedef tAlumno tArray[MAX];

typedef struct{
    tArray elementos;
    int contador;
} tLista;

int i;

void cargarArchivo(tLista &lista); //LISTO
void guardarArchivo(tLista &lista); //LISTO

void addAlumno(tLista &lista, bool &ok); //LISTO
void eliminarAlumno(tLista &lista, string nombre, string apellido); //LISTO
void buscarAlumno(tLista &lista, string nombre, string apellido); //LISTO
void mostrarAlumnos(tLista &lista); //LISTO
bool operator>(tAlumno opIzq, tAlumno opDer); //LISTO
bool operator<(tAlumno opIzq, tAlumno opDer); //LISTO


int main(){
    tLista lista;
    string tempText,tempText1;
    int op,pos;
    bool ok;
    lista.contador = 0;
    cargarArchivo(lista);
    do {
        cout << "1 - Agregar un nuevo alumno" << endl;
        cout << "2 - Eliminar un alumno" << endl;
        cout << "3 - Buscar alumnos" << endl;
        cout << "4 - Listado de alumnos" << endl;
        cout << "0 - Salir" << endl;
        cin >> op;

        switch(op)
        {
        case 1:
            //Añadir alumnos
            addAlumno(lista,ok);
            break;
        case 2:
            //Eliminar alumno
            cout << "Ingrese el nombre del alumno que desee eliminar: ";
            cin >> tempText;
            cout << "Ingrese el apellido del alumno que desee eliminar: ";
            cin >> tempText1;
            eliminarAlumno(lista,tempText, tempText1);
            break;
        case 3:
            //Buscar Alumno
            cout << "Ingrese el nombre del alumno que desea buscar: ";
            cin >> tempText;
            cout << "Ingrese el apellido del alumno que desea buscar: ";
            cin >> tempText1;
            buscarAlumno(lista,tempText, tempText1);
            break;
        case 4:
            //Listado de alumnos
            mostrarAlumnos(lista);
            break;
        case 0:
            //Guardamos y salimos
            guardarArchivo(lista);
            break;
        default:
            cout << "Opcion desconocida!" << endl;
            break;
        }
    } while (op != 0);
return 0;
}



void cargarArchivo(tLista &lista)
{
    ifstream cArchivo;
    cArchivo.open("Alumnos.txt", ios::in);
    if(cArchivo.is_open())
    {
        while (!cArchivo.eof())
        {
            cArchivo >> lista.elementos[lista.contador].nombre;
            cArchivo.get( );
            cArchivo >> lista.elementos[lista.contador].apellido;
            cArchivo.get( );
            cArchivo >> lista.elementos[lista.contador].calificacion;
            cArchivo >> lista.elementos[lista.contador].dni;

            if((!lista.elementos[lista.contador].nombre.empty())&&(!lista.elementos[lista.contador].apellido.empty())&&(!lista.elementos[lista.contador].calificacion.empty())&&(!lista.elementos[lista.contador].dni.empty()))
            {
                lista.contador++;
            }
        }
    }
    cArchivo.close();
}

void guardarArchivo(tLista &lista)
{
    ofstream gArchivo;
    gArchivo.open("Alumnos.txt", ios::out);
    if(gArchivo.is_open())
    {
        for(i = 0; i < lista.contador; i++)
        {
             gArchivo << lista.elementos[i].nombre<< " " << lista.elementos[i].apellido << " " <<lista.elementos[i].calificacion << " " << lista.elementos[i].dni << endl;
        }
    }
    gArchivo.close();
}

bool operator >(tAlumno opIzq, tAlumno opDer)
{
    return(opIzq.nombre > opDer.nombre);
}

bool operator <(tAlumno opIzq, tAlumno opDer)
{
    return(opIzq.nombre < opDer.nombre);
}

void addAlumno(tLista &lista, bool &ok)
{
    tAlumno alumno;
    ok = true;

    cout << "Ingrese el nombre del alumno: ";
    cin.ignore();
    getline(cin,alumno.nombre);
    cout << "Ingrese el apellido del alumno: ";
    getline(cin,alumno.apellido);
    cout << "Ingrese la calificacion del alumno: ";
    getline(cin,alumno.calificacion);
    cout << "Ingreseel dni del alumno: ";
    cin >> alumno.dni;

    if(lista.contador == MAX)
    {
        ok = false;
    } else {
        int i = 0;
        while ((i < lista.contador) && (lista.elementos[i] < alumno))
        {
            i++;
        }
        for(int j = lista.contador; j > i; j--)
        {
            lista.elementos[j] = lista.elementos[j - 1];
        }
        lista.elementos[i] = alumno;
        lista.contador++;
    }
}

void eliminarAlumno(tLista &lista, string nombre, string apellido)
{
    int pos = 0;
    for(i = 0; i < lista.contador; i++)
    {
        if((lista.elementos[i].nombre == nombre)&&(lista.elementos[i].apellido == apellido))
        {
            pos = i;
            for(i = pos; i < lista.contador - 1; i++)
            {
             lista.elementos[i] = lista.elementos[i+1];
            }
            lista.contador = (lista.contador - 1);
            cout << "Alumno eliminado correctamente!" << endl;
            cout << " " << endl;
        }
    }
}

void buscarAlumno(tLista &lista, string nombre, string apellido)
{
    int pos = 0;
    bool encontrado = false;
    for(i = 0; i < lista.contador; i++)
    {
        if((lista.elementos[i].nombre == nombre)&&(lista.elementos[i].apellido == apellido))
        {
            cout << "El alumno se encuentra en la posicion: " << i << endl;
            cout << " " << endl;
            encontrado = true;
        }
    }
    if(!encontrado)
    {
        cout << "El alumno no se encuentra en la lista." << endl;
        cout << " " << endl;
    }

}

void mostrarAlumnos(tLista &lista)
{
    cout << "Listado de alumnos:" << endl;
    cout << " " << endl;
    for(i = 0; i < lista.contador; i++)
    {
        cout << "Nombre: " << lista.elementos[i].nombre << endl;
        cout << "Apellido: " << lista.elementos[i].apellido << endl;
        cout << "Calificacion: " << lista.elementos[i].calificacion << endl;
        cout << "DNI: " << lista.elementos[i].dni << endl;
        cout << " " << endl;
    }
}



