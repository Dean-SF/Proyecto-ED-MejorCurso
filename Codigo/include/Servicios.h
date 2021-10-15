#ifndef SERVICIOS_H
#define SERVICIOS_H
#include <iostream>
#include <string.h>
#include "Ventana.h"

using std::string;

class Servicios {
    private:
        string descripcion;
        string id;
        string nombre;
        Ventana *ventana;

    public:
        Servicios(string descripcion, string id, string nombre,Ventana *ventana);
        Servicios();
        ~Servicios();
        string getId();
        string getNombre();
        Ventana* getVentana();

};

#endif // SERVICIOS_H
