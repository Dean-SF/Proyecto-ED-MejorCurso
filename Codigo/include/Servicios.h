#ifndef SERVICIOS_H
#define SERVICIOS_H
#include <iostream>
#include <string.h>
#include "Ventana.h"

using std::string;
//using std::ostream;

class Servicios {
    private:
        string descripcion;
        string id;
        string nombre;
        Ventana *ventana;

    public:
        Servicios(string descripcion, string id, string nombre,Ventana *ventana);
        Servicios();
        string getId();
        string getNombre();
        Ventana* getVentana();
        void agregarTiquete(bool tipo);

        bool operator!=(const Servicios& other){
            return this->id != other.id;
        }

        bool operator==(const Servicios& other){
            return this->id == other.id;
        }

};

#endif // SERVICIOS_H
