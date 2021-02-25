#include <iostream>
#include "artista.h"
#include "album.h"
using namespace std;
Artista::Artista()
{
    nombreArtista = "";
    vector<Album> listaAlbum;
}
string Artista::obtenerNombre()
{
    return (nombreArtista);
}
void Artista::fijarNombre(string nombreArt)
{
    nombreArtista = nombreArt;
}
void Artista::agregarAlbum(string nombreAlbum, int anio, string nombreCancion, string generoCancion)
{
    bool encontrado = false;
    vector<Album>::iterator itAlbum;
    for (itAlbum = listaAlbum.begin(); itAlbum != listaAlbum.end(); itAlbum++)
    {
        if (itAlbum->obtenerNombre() == nombreAlbum)
        {
            itAlbum->agregarCancion(nombreCancion, generoCancion);
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        Album newAlbum;
        newAlbum.fijarNombre(nombreAlbum);
        newAlbum.fijarAnio(anio);
        newAlbum.agregarCancion(nombreCancion, generoCancion);
        listaAlbum.push_back(newAlbum);
    }
}
void Artista::imprimirAlbum()
{
    vector<Album>::iterator itAlbum;
    for (itAlbum = listaAlbum.begin(); itAlbum != listaAlbum.end(); itAlbum++)
    {
        cout << itAlbum->obtenerNombre() << endl;
        itAlbum->imprimirCancion();
    }
}

void Artista::buscarAlbum(string nombre)
{
    vector<Album>::iterator itAlbum;
    vector<Cancion>::iterator itCancion, itCancion2, itCancion3;
    vector<Cancion> canciones1;
    Cancion auxCan;
    string aux;
    for (itAlbum = listaAlbum.begin(); itAlbum != listaAlbum.end(); itAlbum++)
    {
        aux = itAlbum->obtenerNombre();
        if (nombre.compare(aux) == 0)
        {
            canciones1 = itAlbum->obtenerCanciones();

            for (itCancion = canciones1.begin(); itCancion != canciones1.end(); itCancion++)
            {
                for (itCancion2 = canciones1.begin(); itCancion2 != canciones1.end() - 1; itCancion2++)
                {
                    if (itCancion->obtenerNombre().compare(itCancion2->obtenerNombre()) < 0)
                    {
                        auxCan = *itCancion;
                        *itCancion = *itCancion2;
                        *itCancion2 = auxCan;
                    }
                }
            }
        }
    }
    for (itCancion3 = canciones1.begin(); itCancion3 != canciones1.end(); itCancion3++)
    {
        if (itCancion3->obtenerNombre().length() == 17)
        {
            canciones1.push_back(*itCancion3);
            canciones1.erase(itCancion3);
        }
    }
    for (itCancion3 = canciones1.begin(); itCancion3 != canciones1.end(); itCancion3++)
    {
        cout << "  " << itCancion3->obtenerNombre() << endl;
    }
}

void Artista::listarCanciones()
{
    vector<Cancion> cancionesCompl, aux;
    vector<Album>::iterator itAlbum;
    vector<Cancion>::iterator itCancion, itCancion2, itCancion3;
    Cancion auxCan, cancion17;

    for (itAlbum = listaAlbum.begin(); itAlbum != listaAlbum.end(); itAlbum++)
    {
        aux = itAlbum->obtenerCanciones();
        cancionesCompl.insert(cancionesCompl.end(), aux.begin(), aux.end());
        for (itCancion = cancionesCompl.begin(); itCancion != cancionesCompl.end(); itCancion++)
        {
            for (itCancion2 = cancionesCompl.begin(); itCancion2 != cancionesCompl.end() - 1; itCancion2++)
            {
                if (itCancion->obtenerNombre().compare(itCancion2->obtenerNombre()) < 0 && itCancion->obtenerNombre().length() == 16)
                {
                    auxCan = *itCancion;
                    *itCancion = *itCancion2;
                    *itCancion2 = auxCan;
                }
            }
        }
    }
    for (itCancion3 = cancionesCompl.begin(); itCancion3 != cancionesCompl.end(); itCancion3++)
    {
        if (itCancion3->obtenerNombre().length() == 17)
        {
            cancionesCompl.push_back(*itCancion3);
            cancionesCompl.erase(itCancion3);
        }
    }
    for (itCancion3 = cancionesCompl.begin(); itCancion3 != cancionesCompl.end(); itCancion3++)
    {
        cout << "   " << itCancion3->obtenerNombre() << endl;
    }
}

vector<Album> Artista::obtenerAlbum()
{
    return listaAlbum;
}
