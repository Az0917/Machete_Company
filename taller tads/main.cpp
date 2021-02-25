#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "artista.h"
#include "cancion.h"
#include "album.h"
using namespace std;

//funciones


void agregarDatos(string nombreCancion, string nombreAutor, string genero, string album, int anio, vector<Artista> &listaArtistas)
{
    bool encontrado = false;
    vector<Artista>::iterator itArtista;
    for (itArtista = listaArtistas.begin(); itArtista != listaArtistas.end(); itArtista++)
    {
        if (itArtista->obtenerNombre() == nombreAutor)
        {
            itArtista->agregarAlbum(album,anio,nombreCancion,genero);
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        Artista newArtista;
        newArtista.fijarNombre(nombreAutor);
        listaArtistas.push_back(newArtista);
    }
}
void separar(string datos, vector<Artista> &listaArtistas)
{

    int contadorPalabra = 0;
    istringstream is(datos);
    string part;
    string nombreCancion = "";
    string nombreAutor = "";
    string genero = "";
    string album = "";
    int anio = 0;
    while (getline(is, part, '|'))
    {
        if (contadorPalabra == 0)
        {
            nombreCancion = part;
        }
        if (contadorPalabra == 1)
        {
            nombreAutor = part;
        }
        if (contadorPalabra == 2)
        {
            genero = part;
        }
        if (contadorPalabra == 3)
        {
            album = part;
        }
        if (contadorPalabra == 4)
        {
            anio = stoi(part);
        }
        contadorPalabra++;
    }
    agregarDatos(nombreCancion, nombreAutor, genero, album, anio, listaArtistas);
}
void leerArchivo(string nomArch, vector<Artista> &listaArtistas)
{
    string linea;
    ifstream archivo;
    int lineasArchivo = 0;
    archivo.open(nomArch);
    if (archivo.is_open())
    {
        getline(archivo, linea);
        lineasArchivo = stoi(linea);
        for (int i = 0; i < lineasArchivo; i++)
        {
            getline(archivo, linea);
            separar(linea, listaArtistas);
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
    vector<Artista> listaArtistas;
    vector<Artista>::iterator itArtista;

    while (opc != 0)
    {
        cout << "1)Abrir archivo" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese nombre del archivo $: ";
            cin >> nomArch;
            nomArch = nomArch + ".txt";
            leerArchivo(nomArch, listaArtistas);
            for (itArtista = listaArtistas.begin(); itArtista != listaArtistas.end(); itArtista++)
            {
                cout << "-----------------------------------------------------------------------------" << endl;
                cout << "El artista " << itArtista->obtenerNombre() << " tiene los albumens: " << endl;
                itArtista->imprimirAlbum();
            }
            break;

        default:
            break;
        }
    }
}