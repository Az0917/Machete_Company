#include <iostream>
#include "Artista.h"
#include "Album.h"
#include <deque>
using namespace std;
Artista::Artista()
{
    nombreArtista = "";
    deque<Album> listaAlbum;
}
string Artista::obtenerNombre()
{
    return (nombreArtista);
}
void Artista::fijarNombre(string nombreArt)
{
    nombreArtista = nombreArt;
}
void Artista::agregarAlbum(Album albumP)
{
    bool encontrado = false;
    deque<Album>::iterator itAlbum;
    for (itAlbum = listaAlbum.begin(); itAlbum != listaAlbum.end(); itAlbum++)
    {
        if (itAlbum->obtenerNombre() == albumP.obtenerNombre())
        {
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        listaAlbum.push_back(albumP);
        cout << "agregando datos al deque de album, el nombre del archivo es : " << albumP.obtenerNombre() << endl; 
    }
}

deque<Album> Artista::obtenerAlbum()
{
    return listaAlbum;
}