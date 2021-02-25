#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "artista.h"
#include "cancion.h"
#include "album.h"
#include "utilidades.h"
using namespace std;

//funciones

void agregarDatos(string nombreCancion, string nombreAutor, string genero, string album, int anio, vector<Artista> &listaArtistas)
{
    bool encontrado = false;
    vector<Artista>::iterator itArtista;
    for (itArtista = listaArtistas.begin(); itArtista != listaArtistas.end(); itArtista++)
    {
        if (itArtista->obtenerNombre() == nombreAutor)
        {
            itArtista->agregarAlbum(album, anio, nombreCancion, genero);
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        Artista newArtista;
        newArtista.fijarNombre(nombreAutor);
        newArtista.agregarAlbum(album, anio, nombreCancion, genero);
        listaArtistas.push_back(newArtista);
    }
}
void separar(string datos, vector<Artista> &listaArtistas)
{

    int contadorPalabra = 0;
    istringstream is(datos);
    string part;
    string nombreCancion = "";
    string nombreAutor = "";
    string genero = "";
    string album = "";
    int anio = 0;
    while (getline(is, part, '|'))
    {
        if (contadorPalabra == 0)
        {
            nombreCancion = part;
        }
        if (contadorPalabra == 1)
        {
            nombreAutor = part;
        }
        if (contadorPalabra == 2)
        {
            genero = part;
        }
        if (contadorPalabra == 3)
        {
            album = part;
        }
        if (contadorPalabra == 4)
        {
            anio = stoi(part);
        }
        contadorPalabra++;
    }
    agregarDatos(nombreCancion, nombreAutor, genero, album, anio, listaArtistas);
}
void leerArchivo(string nomArch, vector<Artista> &listaArtistas)
{
    string linea;
    ifstream archivo;
    int lineasArchivo = 0;
    archivo.open(nomArch);
    if (archivo.is_open())
    {
        getline(archivo, linea);
        lineasArchivo = stoi(linea);
        for (int i = 0; i < lineasArchivo; i++)
        {
            getline(archivo, linea);
            separar(linea, listaArtistas);
        }
        archivo.close();
    }
    else
        cout << "no se pudo abrir" << endl;
}

void albunesCronologicos(vector<Artista> &listaArtistas)
{
    vector<Album> listaAlubmsActual, listaTotalAlbum;
    vector<Artista>::iterator itArtista;
    vector<Album>::iterator itAlbum, itAlbum2, itAlbum3;
    Album auxAlbum;
    for (itArtista = listaArtistas.begin(); itArtista != listaArtistas.end(); itArtista++)
    {
        listaAlubmsActual = itArtista->obtenerAlbum();
        listaTotalAlbum.insert(listaTotalAlbum.end(), listaAlubmsActual.begin(), listaAlubmsActual.end());
    }

    for (itAlbum = listaTotalAlbum.begin(); itAlbum != listaTotalAlbum.end(); itAlbum++)
    {
        for (itAlbum2 = listaTotalAlbum.begin(); itAlbum2 != listaTotalAlbum.end() - 1; itAlbum2++)
        {
            if (itAlbum->obtenerAnio() < itAlbum2->obtenerAnio())
            {
                auxAlbum = *itAlbum2;
                *itAlbum2 = *itAlbum;
                *itAlbum = auxAlbum;
            }
        }
    }
    cout << "    album     |anio" << endl;
    for (itAlbum3 = listaTotalAlbum.begin(); itAlbum3 != listaTotalAlbum.end(); itAlbum3++)
    {
        cout << "    " << itAlbum3->obtenerNombre() << "|" << itAlbum3->obtenerAnio() << endl;
    }
}

void albunesAlfa(vector<Artista> &listaArtistas)
{
    vector<Album> listaAlubmsActual, listaTotalAlbum;
    vector<Artista>::iterator itArtista;
    vector<Album>::iterator itAlbum, itAlbum2, itAlbum3;
    Album auxAlbum;
    for (itArtista = listaArtistas.begin(); itArtista != listaArtistas.end(); itArtista++)
    {
        listaAlubmsActual = itArtista->obtenerAlbum();
        listaTotalAlbum.insert(listaTotalAlbum.end(), listaAlubmsActual.begin(), listaAlubmsActual.end());
    }

    for (itAlbum = listaTotalAlbum.begin(); itAlbum != listaTotalAlbum.end(); itAlbum++)
    {
        for (itAlbum2 = listaTotalAlbum.begin(); itAlbum2 != listaTotalAlbum.end() - 1; itAlbum2++)
        {
            if (itAlbum->obtenerNombre().compare(itAlbum2->obtenerNombre()) < 0)
            {
                auxAlbum = *itAlbum2;
                *itAlbum2 = *itAlbum;
                *itAlbum = auxAlbum;
            }
        }
    }
    cout << "-----------------------------------------------------------------------------" << endl;
    for (itAlbum3 = listaTotalAlbum.begin(); itAlbum3 != listaTotalAlbum.end(); itAlbum3++)
    {
        cout << itAlbum3->obtenerNombre() <<endl;
        itAlbum3->imprimirCancionesOrdenadas();

    }
    cout << "-----------------------------------------------------------------------------" << endl;
}
int main()
{
    string nomArch, nomArtista, auxArt, nomAlbum;
    int opc;
    vector<Artista> listaArtistas;
    vector<Artista>::iterator itArtista;
    bool encontrado = false;
    int validacion5 = 0;
    system("clear");
    while (opc != 0)
    {
        titulo();
        cout << "1)Abrir archivo" << endl;
        cout << "2)Listar autores alfabeticamente" << endl;
        cout << "3)Listar canciones de un autor" << endl;
        cout << "4)Listar todos los album" << endl;
        cout << "5)Listar canciones de un album" << endl;
        cout << "6)Listar todas las canciones y album" << endl;
        cout << "7)editar informacion adicional" << endl;
        cout << "0)Salir" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:

            cout << "Ingrese nombre del archivo (sin el .txt) $: ";
            cin >> nomArch;
            nomArch = nomArch + ".txt";
            leerArchivo(nomArch, listaArtistas);
            if (leerArchivo != NULL)
            {
                cout << "--->Archivo Cargado Correctamente<---"<<endl;
            }
            
            break;
        case 2:

            break;
        case 3:
            cout << "Ingrese el nombre del artista $: ";
            cin >> nomArtista;
            cout << endl;
            for (itArtista = listaArtistas.begin(); itArtista != listaArtistas.end(); itArtista++)
            {

                auxArt = itArtista->obtenerNombre();
                if (nomArtista.compare(auxArt) == 0)
                {
                    itArtista->listarCanciones();
                    encontrado = true; 
                }
            }
            if (!encontrado)
            {
                cout <<"ALERTA: el autor ingresado no existe" << endl;
            }
            
            cout << "-----------------------------------------------------------------------------" << endl;

            break;
        case 4:
            albunesCronologicos(listaArtistas);
            cout << "-----------------------------------------------------------------------------" << endl;
            break;
        case 5:
            cout << "Ingrese el nombre del Album $:  ";
            cin >> nomAlbum;
            cout << endl;
            for (itArtista = listaArtistas.begin(); itArtista != listaArtistas.end(); itArtista++)
            {
                validacion5 = itArtista->buscarAlbum(nomAlbum);
            }
            if (validacion5 == 1)
            {
                cout <<"ALERTA: el album ingresado no existe" << endl;
            }
            
            cout << "-----------------------------------------------------------------------------" << endl;

            break;
        case 6:
            albunesAlfa(listaArtistas);

            break;
        case 7:

            break;
        case 0:
            cout << "Saliendo del sistema"<<endl;
            return 0;

        default:
            cout << "Ingrese una opcion valida" << endl;
            break;
        }
    }
}