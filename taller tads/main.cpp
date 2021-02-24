#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
void separar(string datos)
{
    istringstream is(datos);
    string part;
    while (getline(is, part, '|'))
    {
        cout << part << endl;
    }
}
void leerArchivo(string nomArch)
{
    string linea;
    ifstream archivo;
    archivo.open(nomArch);
    if (archivo.is_open())
    {
        while (!archivo.eof())
        {
            getline(archivo, linea);
            separar(linea);
        }
        archivo.close();
    }
    else
        cout << "no se pudo abrir" << endl;
}
int main()
{
    string nomArch;
    int opc;
    while (opc != 0)
    {
        cout << "1)Abrir archivo" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese nombre del archivo:";
            cin >> nomArch;
            nomArch = nomArch + ".txt";
            leerArchivo(nomArch);
            break;

        default:
            break;
        }
    }
}