#include <iostream>
#include "artista.h"
using namespace std;
artista::artista(){
    nombreArtista = "";
    deque <album> listaAlbum;
}
string artista::obtenerNombre(){
    return (nombreArtista);
}
void artista::fijarNombre(string nombreArt){
    nombreArtista = nombreArt;
}
void artista::agregarAlbum(string nombreAlbumP){
    bool encontrado = false;
    deque<album>::iterator itAlbum;
    for(itAlbum = listaAlbum.begin();itAlbum != listaAlbum.end();itAlbum++){
        if(itAlbum->obtenerNombre() == nombreAlbumP)
        {
            encontrado = true;
        }
    }
    if(!encontrado)
    {
        album albumNuevo;
        albumNuevo.fijarNombre(nombreAlbumP);
        listaAlbum.push_back(albumNuevo);
    }
}