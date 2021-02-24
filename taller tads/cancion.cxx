#include <iostream>
#include "cancion.h"
//constructor
cancion::cancion(){
    nombreCancion = "";
    genero = "";
    duracion = 0;
    calificacion = 0;
}

//sets
void cancion::fijarNombre(string nombre){
    nombreCancion = nombre;
}    
void cancion::fijarGenero(string generoCancion){
    genero = generoCancion;

}
void cancion::fijarDuracion(unsigned int duracionT){
    duracion = duracionT;
}
void cancion::fijarCalificacion(unsigned int calificacionCan){
    calificacion = calificacionCan;
}
//get
string cancion::obtenerNombre(){
    return(nombreCancion);
}
string cancion::obtenerGenero()
{
    return(genero);
}
unsigned int cancion::obtenerduracion(){
    return(duracion);
}
unsigned int cancion::obtenerCalificacion(){
    return(calificacion);
}