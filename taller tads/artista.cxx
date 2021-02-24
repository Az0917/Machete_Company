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
void Artista::agregarAlbum(Album albumP)
{
    bool encontrado = false;
    vector<Album>::iterator itAlbum;
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