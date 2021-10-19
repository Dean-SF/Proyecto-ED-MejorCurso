//Creado por: Esteban Perez Picado
//Fecha de creacion: 15/10/2021
//Ultima modificacion: 19/10/2021
//Modificado por: Deyan Sanabria Fallas
#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include <iostream>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Ventana.h"
#include "Servicios.h"

using std::string;

/*
Clase que controla todos los objetos del  programa para y tiene los
metodos para realizar la funcionalidad deseada en el menu.
*/
class Controlador{
    private:
        List<Ventana*> *ventanas;
        List<Servicios> *servicios;
        int totalTiquetes;
        int totalPreferenciales;
        void clearVentanas();
    public:
        Controlador();
        ~Controlador();
        string estadoColas();
        bool agregarTiquete(bool preferencial, string codigo);
        string atender(string codigoVentana, int numVentanilla);
        bool agregarVentana(string codigo, string descripcion, int cantidad);
        int eliminarVentana(string codigo);
        bool agregarServicio(string descripcion, string id, string nombre, string codigo);
        bool eliminarServicio(string id);
        bool moverServicio(string id, int pos);
        string tiempoPromedio();
        string dispensadosVentana();
        string atendidosVentana();
        string dispensadosServicio();
        string dispensadosPreferenciales();
        string mostrarServicios();

};

#endif // CONTROLADOR_H
