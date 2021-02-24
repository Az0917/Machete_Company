#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Artista.h"
#include "Cancion.h"
#include "Album.h"
using namespace std;

//variable global
deque<Artista> listaArtistas;

//funciones

void agregarArtista(Artista artistaP)
{
    bool encontrado = false;
    deque<Artista>::iterator itArtista;
    for (itArtista = listaArtistas.begin(); itArtista != listaArtistas.end(); itArtista++)
    {
        if (itArtista->obtenerNombre() == artistaP.obtenerNombre())
        {
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        listaArtistas.push_back(artistaP);
    }
}

void separar(string datos)
{
    Artista artistaM;
    Cancion cancionM;
    Album albumM;
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
    cancionM.fijarNombre(nombreCancion);
    cancionM.fijarGenero(genero);
    albumM.fijarNombre(album);
    albumM.fijarAnio(anio);
    albumM.agregarCancion(cancionM);
    artistaM.fijarNombre(nombreAutor);
    artistaM.agregarAlbum(albumM);
    agregarArtista(artistaM);
}
void leerArchivo(string nomArch)
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
    deque<Artista>::iterator itArtista;
    deque<Album> listaAlbum;
    deque<Cancion> listaCanciones;
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
            for (itArtista = listaArtistas.begin(); itArtista != listaArtistas.end(); itArtista++)
            {
                cout << "el artista : " <<itArtista->obtenerNombre() << " tiene los albums "<< endl;
                listaAlbum = itArtista->obtenerAlbum();
                deque<Album>::iterator itAlbum;
                for (itAlbum = listaAlbum.begin(); itAlbum != listaAlbum.end(); itAlbum++)
                {
                    cout<<itAlbum->obtenerNombre()<<endl;
                    listaCanciones = itAlbum->obtenerCanciones();
                    deque<Cancion>::iterator itCancion;
                    for(itCancion = listaCanciones.begin(); itCancion != listaCanciones.end(); itCancion++)
                    {
                        cout<< "con la cancion: " << itCancion->obtenerNombre() << endl;
                    }
    
                }
            }
            break;

        default:
            break;
        }
    }
}