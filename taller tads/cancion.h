#ifndef __CANCION__H__
#define __CANCION__H__
#include <iostream>
using namespace std;
class cancion
{
    //atributos
    protected:
    string nombreCancion;
    string genero;
    unsigned int duracion;
    unsigned int calificacion;
    //funciones
    public:
    cancion();
    void fijarNombre(string nombCancion);
    string obtenerNombre();
    void fijarGenero(string nombreGenero);
    string obtenerGenero();
    void fijarDuracion(unsigned int duracionCancion);
    unsigned int obtenerduracion();
    void fijarCalificacion(unsigned int calificacionCancion);
    unsigned int obtenerCalificacion();

};

#endif 