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
    Artista artistaM;
    Cancion cancionM;
    Album albumM;
    deque<Album> listaAlbum;
    deque<Cancion> listaCanciones;
    artistaM.fijarNombre(nombreAutor);
    agregarArtista(artistaM);
    deque<Artista>::iterator itArtista;
    deque<Album>::iterator itAlbum;
    deque<Cancion>::iterator itCancion;

    for (itArtista = listaArtistas.begin(); itArtista != listaArtistas.end(); itArtista++)
    {
        if (itArtista->obtenerNombre() == artistaM.obtenerNombre())
        {
            albumM.fijarNombre(album);
            albumM.fijarAnio(anio);
            itArtista->agregarAlbum(albumM);
            listaAlbum = itArtista->obtenerAlbum();
            for (itAlbum = listaAlbum.begin(); itAlbum != listaAlbum.end(); itAlbum++)
            {
                if (itAlbum->obtenerNombre() == albumM.obtenerNombre())
                {
                    cancionM.fijarNombre(nombreCancion);
                    cancionM.fijarGenero(genero);
                    itAlbum->agregarCancion(cancionM);
                    listaCanciones = itAlbum->obtenerCanciones();
                }
            }
        }
    }
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

    deque<Album> listaAlbum;
    deque<Cancion> listaCanciones;
    deque<Artista>::iterator itArtista;
    deque<Album>::iterator itAlbum;
    deque<Cancion>::iterator itCancion;

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
            leerArchivo(nomArch);
            for (itArtista = listaArtistas.begin(); itArtista != listaArtistas.end(); itArtista++)
            {
                cout << "-----------------------------------------------------------------------------"<< endl;
                cout << "El artista " << itArtista->obtenerNombre() << " tiene los albumens: " << endl;
                listaAlbum = itArtista->obtenerAlbum();
                if (listaAlbum.empty())
                {
                    cout << "lista de albumnes vacia" << endl;
                }
                for (itAlbum = listaAlbum.begin(); itAlbum != listaAlbum.end(); itAlbum++)
                {
                    cout << itAlbum->obtenerNombre()  << endl;
                    listaCanciones = itAlbum->obtenerCanciones();
                    if (listaCanciones.empty())
                    {
                        cout << "lista de canciones vacia" << endl;
                    }
                    for (itCancion = listaCanciones.begin(); itCancion != listaCanciones.end(); itCancion++)
                    {
                        cout << itCancion->obtenerNombre() << endl;
                    }
                }
            }

            break;

        default:
            break;
        }
    }
}