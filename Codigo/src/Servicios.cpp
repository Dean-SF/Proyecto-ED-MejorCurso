#include "Servicios.h"

Servicios::Servicios(){}

Servicios::Servicios(string descripcion, string id, string nombre,Ventana *ventana){
    this->descripcion = descripcion;
    this->id = id;
    this->nombre = nombre;
    this->ventana = ventana;
}

string Servicios::getId(){
    return id;
}
string Servicios::getNombre(){
    return nombre;
}
Ventana* Servicios::getVentana(){
    return ventana;
}
