#ifndef __ARTISTA__H__
#define __ARTISTA__H__
#include <iostream>
#include <bits/stdc++.h>
#include "album.h"
using namespace std;
class Artista{
    protected:
    string nombreArtista;
    vector <Album> listaAlbum;

    public:
    Artista();
    string obtenerNombre();
    void fijarNombre(string nombreArt);
    void agregarAlbum(Album albumP);
    void imprimirAlbum();
    vector <Album>  obtenerAlbum();
};
#endif