#include "Servicios.h"

Servicios::Servicios(){
    ventana = nullptr;
}

Servicios::Servicios(string descripcion, string id, string nombre,Ventana *ventana){
    cantidadDispensada = 0;
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
    cantidadDispensada+=1;
    ventana->agregarTiquete(tipo);
}

int Servicios::getCantidadDispensada(){
    return cantidadDispensada;
}

string Servicios::getDescripcion(){
    return descripcion;
}
