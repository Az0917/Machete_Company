#include <iostream>
#include <bits/stdc++.h>
#include "Album.h"
#include "Cancion.h"
#include <deque>
Album::Album()
{
    nombreAlbum = "";
    anio = 0;
    deque<Cancion> listaCanciones;
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
void Album::agregarCancion(Cancion cancionP)
{
    bool encontrado = false;
    deque<Cancion>::iterator itCancion;
    for (itCancion = listaCanciones.begin(); itCancion != listaCanciones.end(); itCancion++)
    {
        if (itCancion->obtenerNombre() == cancionP.obtenerNombre())
        {
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        listaCanciones.push_back(cancionP);
        cout << "agregando datos al deque de cancion, el nombre del archivo es: " << cancionP.obtenerNombre() << endl; 
    }
}

deque<Cancion> Album::obtenerCanciones()
{
    return listaCanciones;
}