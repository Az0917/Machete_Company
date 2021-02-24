#ifndef __ARTISTA__H__
#define __ARTISTA__H__
#include <iostream>
#include <deque>
#include <bits/stdc++.h>
#include "Album.h"
using namespace std;
class Artista{
    protected:
    string nombreArtista;
    deque <Album> listaAlbum;

    public:
    Artista();
    string obtenerNombre();
    void fijarNombre(string nombreArt);
    void agregarAlbum(Album albumP);
    deque <Album>  obtenerAlbum();
};
#endif