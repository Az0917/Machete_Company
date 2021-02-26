#ifndef __ARTISTA__H__
#define __ARTISTA__H__
#include <iostream>
#include <bits/stdc++.h>
#include "album.h"
using namespace std;
class Artista{
    private:
    string nombreArtista;
    vector <Album> listaAlbum;

    public:
    Artista();
    string obtenerNombre();
    void fijarNombre(string nombreArt);
    void agregarAlbum(string nombreAlbum,int anio, string nombreCancion, string generoCancion);
    void agregarCancion(string nombreAlbum,int anio, string nombreCancion, string generoCancion);
    void modificarCan(int duracionN, int caliN, string album, string cancion);
    void imprimirAlbum();
    int buscarAlbum(string nombre);
    void listarCanciones();
    vector <Album>  obtenerAlbum();
};
#endif