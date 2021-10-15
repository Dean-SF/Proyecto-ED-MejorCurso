#include "Controlador.h"

Controlador::Controlador(){
    totalTiquetes = 0;
    totalPreferenciales = 0;
    servicios = new LinkedList<Servicios>();
    ventanas = new LinkedList<Ventana>();
}

Controlador::~Controlador(){
    delete ventanas;
    delete servicios;
}

string Controlador::estadoColas(){}
bool Controlador::agregarTiquete(bool preferencial, string codigo){}
string Controlador::atender(string codigoVentana, string numVentanilla){}
bool Controlador::agregarVentana(string codigo, string descripcion, int cantidad){}
bool Controlador::eliminarVentana(string codigo){}
bool Controlador::agregarServicio(){}
bool Controlador::eliminarServicio(){}
bool Controlador::moverServicio(){}
time_t Controlador::tiempoPromedio(){}
string Controlador::dispensadosVentana(){}
string Controlador::atendidosVentana(){}
string Controlador::dispensadosServicio(){}
int Controlador::dispensadosPreferenciales(){
    return totalPreferenciales;
}
