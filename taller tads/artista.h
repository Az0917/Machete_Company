#ifndef __ARTISTA__H__
#define __ARTISTA__H__
#include <iostream>
#include <bits/stdc++.h>
#include "album.h"
using namespace std;
class artista{
    protected:
    string nombreArtista;
    deque <album> listaAlbum;

    public:
    artista();
    string obtenerNombre();
    void fijarNombre(string nombreArt);
    void agregarAlbum(string nombreAlbum);
};
#endif