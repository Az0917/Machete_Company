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
    for (itCancion = listaCanciones.begin(); itCancion != listaCanciones.end(); itCancion++)
    {
        cout << itCancion->obtenerNombre() << endl;
        cout << itCancion->obtenerGenero() << endl;
        cout << itCancion->obtenerduracion() << endl;
        cout << itCancion->obtenerCalificacion() << endl;
    }
}

vector<Cancion> Album::obtenerCanciones()
{
    return listaCanciones;
}

void Album::imprimirCancionesOrdenadas()
{
    vector<Cancion>::iterator itCancion, itCancion2, itCancion3;
    vector<Cancion> canciones1, cancionFinal;
    Cancion auxCan;
    canciones1 = listaCanciones;
    for (itCancion = canciones1.begin(); itCancion != canciones1.end(); itCancion++)
    {
        for (itCancion2 = canciones1.begin(); itCancion2 != canciones1.end() - 1; itCancion2++)
        {
            if (itCancion->obtenerNombre().compare(itCancion2->obtenerNombre()) < 0 )
            {
                auxCan = *itCancion;
                *itCancion = *itCancion2;
                *itCancion2 = auxCan;
            }
        }
    }
    for (itCancion3 = canciones1.begin(); itCancion3 != canciones1.end(); itCancion3++)
    {
        if (itCancion3->obtenerNombre().length() == 16)
        {
            cancionFinal.push_back(*itCancion3);
        }
    }
    for (itCancion3 = canciones1.begin(); itCancion3 != canciones1.end(); itCancion3++)
    {
        if (itCancion3->obtenerNombre().length() == 17)
        {
            cancionFinal.push_back(*itCancion3);
        }
    }
    for (itCancion3 = cancionFinal.begin(); itCancion3 != cancionFinal.end(); itCancion3++)
    {
        cout << "   -->" << itCancion3->obtenerNombre() << endl;
    }
}