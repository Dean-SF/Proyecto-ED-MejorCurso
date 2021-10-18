#include "Servicios.h"

Servicios::Servicios(){
    ventana = nullptr;
}

Servicios::Servicios(string descripcion, string id, string nombre,Ventana *ventana){
    this->descripcion = descripcion;
    this->id = id;
    this->nombre = nombre;
    this->ventana = ventana;
}

Servicios::~Servicios() {
    ventana = nullptr;
}

Servicios::Servicios(const Servicios &other) {
    this->descripcion = other.descripcion;
    this->id = other.id;
    this->nombre = other.nombre;
    this->ventana = other.ventana;
}

void Servicios::operator=(const Servicios &other) {
    this->descripcion = other.descripcion;
    this->id = other.id;
    this->nombre = other.nombre;
    this->ventana = other.ventana;
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

void Servicios::agregarTiquete(bool tipo){
    ventana->agregarTiquete(tipo);
}
