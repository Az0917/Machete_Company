#ifndef __ALBUM__H__
#define __ALBUM__H__
#include<iostream>
#include<bits/stdc++.h>
#include "cancion.h"
using namespace std;
class album{
    protected:
    string nombreAlbum;
    unsigned int anio;
    deque <cancion> listaCanciones;

    public:
    album();
    string obtenerNombre();
    unsigned int obtenerAnio();
    void fijarNombre(string nombreAlbumCancion);
    void fijarAnio(unsigned int AnioCancion);
    void agregarCancion(string nombCancio, string nombreGenero,unsigned int duracionCan, unsigned int calificacionCan);
};
#endif