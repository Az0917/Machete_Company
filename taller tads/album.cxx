#include <iostream>
#include<bits/stdc++.h>
#include "Album.h"
#include "Cancion.h"
Album::Album(){
    nombreAlbum = "";
    anio = 0;
    deque <Cancion> listaCanciones;
}
string Album::obtenerNombre(){
    return(nombreAlbum);
}
unsigned int Album::obtenerAnio(){
    return(anio);
}
void Album::fijarNombre(string nombreAlbump){
    nombreAlbum = nombreAlbump;
}
void Album::fijarAnio(unsigned int anioP){
    anio = anioP;
}
void Album::agregarCancion(Cancion cancionP){
    deque<Cancion>::iterator itCancion;
    bool encontrado = false;
    for(itCancion = listaCanciones.begin(); itCancion != listaCanciones.end(); itCancion++)
    {
        if(itCancion->obtenerNombre() == cancionP.obtenerNombre()){
            encontrado = true;
        }
    }
    if(!encontrado){
        listaCanciones.push_back(cancionP);
    }
}

deque <Cancion> Album::obtenerCanciones()
{
    return listaCanciones;
}