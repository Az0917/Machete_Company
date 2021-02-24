#include <iostream>
#include<bits/stdc++.h>
#include "album.h"
#include "cancion.h"
album::album(){
    nombreAlbum = "";
    anio = 0;
    deque <cancion> listaCanciones;
}
string album::obtenerNombre(){
    return(nombreAlbum);
}
unsigned int album::obtenerAnio(){
    return(anio);
}
void album::fijarNombre(string nombreAlbump){
    nombreAlbum = nombreAlbump;
}
void album::fijarAnio(unsigned int anioP){
    anio = anioP;
}
void album::agregarCancion(string nombCancio, string nombreGenero,unsigned int duracionCan, unsigned int calificacionCan){
    deque<cancion>::iterator itCancion;
    bool encontrado = false;
    for(itCancion = listaCanciones.begin(); itCancion != listaCanciones.end(); itCancion++)
    {
        if(itCancion->obtenerNombre() == nombCancio){
            encontrado = true;
        }
    }
    if(!encontrado){
        cancion cancionNuevo;
        cancionNuevo.fijarNombre(nombCancio);
        cancionNuevo.fijarGenero(nombreGenero);
        cancionNuevo.fijarDuracion(duracionCan);
        cancionNuevo.fijarCalificacion(calificacionCan);
        listaCanciones.push_back(cancionNuevo);
    }
}