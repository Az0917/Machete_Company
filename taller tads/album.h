#ifndef __ALBUM__H__
#define __ALBUM__H__
#include<iostream>
#include<bits/stdc++.h>
#include "Cancion.h"
using namespace std;
class Album{
    protected:
    string nombreAlbum;
    unsigned int anio;
    deque <Cancion> listaCanciones;

    public:
    Album();
    string obtenerNombre();
    unsigned int obtenerAnio();
    void fijarNombre(string nombreAlbumCancion);
    void fijarAnio(unsigned int AnioCancion);
    void agregarCancion(Cancion cancionP);
    deque <Cancion>  obtenerCanciones();
};
#endif