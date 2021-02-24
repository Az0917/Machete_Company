#include <iostream>
#include "Cancion.h"
//constructor
Cancion::Cancion(){
    nombreCancion = "";
    genero = "";
    duracion = 0;
    calificacion = 0;
}

//sets
void Cancion::fijarNombre(string nombre){
    nombreCancion = nombre;
}    
void Cancion::fijarGenero(string generoCancion){
    genero = generoCancion;

}
void Cancion::fijarDuracion(unsigned int duracionT){
    duracion = duracionT;
}
void Cancion::fijarCalificacion(unsigned int calificacionCan){
    calificacion = calificacionCan;
}
//get
string Cancion::obtenerNombre(){
    return(nombreCancion);
}
string Cancion::obtenerGenero()
{
    return(genero);
}
unsigned int Cancion::obtenerduracion(){
    return(duracion);
}
unsigned int Cancion::obtenerCalificacion(){
    return(calificacion);
}