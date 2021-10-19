//Creado por: Esteban Perez Picado
//Fecha de creacion: 15/10/2021
//Ultima modificacion: 18/10/2021
//Modificado por: Deyan Sanabria Fallas
#ifndef SERVICIOS_H
#define SERVICIOS_H
#include <iostream>
#include <string.h>
#include "Ventana.h"

using std::string;
//using std::ostream;

/*
Clase Servicios que se usa para representar un servicio con una descripcion, id,
nombre y tiene asignado un puntero a la ventana asignada respectiva
*/
class Servicios {
    private:
        int cantidadDispensada;
        string descripcion;
        string id;
        string nombre;
        Ventana *ventana;

    public:
        Servicios(string descripcion, string id, string nombre,Ventana *ventana);
        Servicios();
        Servicios(const Servicios& other);
        ~Servicios();
        void operator=(const Servicios& other);
        string getId();
        string getNombre();
        Ventana* getVentana();
        void agregarTiquete(bool tipo);
        int getCantidadDispensada();
        string getDescripcion();

        /*
        Sobregarga del operador de comparacion diferente
        */
        bool operator!=(const Servicios& other){
            return this->id != other.id;
        }

        /*
        Sobregarga del operador de comparacion igual
        */
        bool operator==(const Servicios& other){
            return this->id == other.id;
        }

};

#endif // SERVICIOS_H
