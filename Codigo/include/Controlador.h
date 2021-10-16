#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include <iostream>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Ventana.h"
#include "Servicios.h"

using std::string;

class Controlador{
    private:
        LinkedList<Ventana> *ventanas;
        LinkedList<Servicios> *servicios;
        int totalTiquetes;
        int totalPreferenciales;

    public:
        Controlador();
        ~Controlador();
        string estadoColas();
        bool agregarTiquete(bool preferencial, string codigo);
        string atender(string codigoVentana, string numVentanilla);
        bool agregarVentana(string codigo, string descripcion, int cantidad);
        bool eliminarVentana(string codigo);
        bool agregarServicio(string descripcion, string id, string nombre, string codigo);
        bool eliminarServicio(string id);
        bool moverServicio(string id);
        time_t tiempoPromedio();
        string dispensadosVentana();
        string atendidosVentana();
        string dispensadosServicio();
        int dispensadosPreferenciales();

};

#endif // CONTROLADOR_H
