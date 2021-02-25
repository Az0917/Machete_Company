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
void Artista::agregarAlbum(string nombreAlbum,int anio, string nombreCancion, string generoCancion)
{
    bool encontrado = false;
    vector<Album>::iterator itAlbum;
    for (itAlbum = listaAlbum.begin(); itAlbum != listaAlbum.end(); itAlbum++)
    {
        if (itAlbum->obtenerNombre() == nombreAlbum)
        {
            itAlbum->agregarCancion(nombreCancion,generoCancion);
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        Album newAlbum;
        newAlbum.fijarNombre(nombreAlbum);
        newAlbum.fijarAnio(anio);
        newAlbum.agregarCancion(nombreCancion,generoCancion);
        listaAlbum.push_back(newAlbum);
    }
}
void Artista::imprimirAlbum(){
    vector<Album>::iterator itAlbum;
    for (itAlbum = listaAlbum.begin(); itAlbum != listaAlbum.end(); itAlbum++){
        cout<<itAlbum->obtenerNombre()<<endl;
        itAlbum->imprimirCancion();
    }
}

vector<Album> Artista::obtenerAlbum()
{
    return listaAlbum;
}