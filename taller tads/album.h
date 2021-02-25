#ifndef __ALBUM__H__
#define __ALBUM__H__
#include<iostream>
#include<bits/stdc++.h>
#include "cancion.h"
using namespace std;
class Album{
    protected:
    string nombreAlbum;
    unsigned int anio;
    vector <Cancion> listaCanciones;

    public:
    Album();
    string obtenerNombre();
    unsigned int obtenerAnio();
    void fijarNombre(string nombreAlbumCancion);
    void fijarAnio(unsigned int AnioCancion);
    void agregarCancion(string nombreCancion, string generoCancion);
    void imprimirCancion();
    vector <Cancion>  obtenerCanciones();
    void imprimirCancionesOrdenadas();
};
#endif