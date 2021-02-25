#include <iostream>
#include <bits/stdc++.h>
#include "album.h"
#include "cancion.h"
Album::Album()
{
    nombreAlbum = "";
    anio = 0;
    vector<Cancion> listaCanciones;
}
string Album::obtenerNombre()
{
    return (nombreAlbum);
}
unsigned int Album::obtenerAnio()
{
    return (anio);
}
void Album::fijarNombre(string nombreAlbump)
{
    nombreAlbum = nombreAlbump;
}
void Album::fijarAnio(unsigned int anioP)
{
    anio = anioP;
}
void Album::agregarCancion(string nombreCancion, string generoCancion)
{
    bool encontrado = false;
    vector<Cancion>::iterator itCancion;
    for (itCancion = listaCanciones.begin(); itCancion != listaCanciones.end(); itCancion++)
    {
        if (itCancion->obtenerNombre() == nombreCancion)
        {
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        Cancion newCancion;
        newCancion.fijarNombre(nombreCancion);
        newCancion.fijarGenero(generoCancion);
        listaCanciones.push_back(newCancion);
    }   
}
void Album::imprimirCancion()
{
    vector<Cancion>::iterator itCancion;
    for (itCancion = listaCanciones.begin(); itCancion != listaCanciones.end(); itCancion++){
        cout<<itCancion->obtenerNombre() << endl;
        cout<<itCancion->obtenerGenero() << endl;
        cout<<itCancion->obtenerduracion() << endl;
        cout<<itCancion->obtenerCalificacion() << endl;
    }
}
vector<Cancion> Album::obtenerCanciones()
{
    return listaCanciones;
}