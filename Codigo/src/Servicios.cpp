//Creado por: Esteban Perez Picado
//Fecha de creacion: 15/10/2021
//Ultima modificacion: 18/10/2021
#include "Servicios.h"

/*
Contructor default de Servicios
*/
Servicios::Servicios(){
    ventana = nullptr;
}

/*
Constructor con los parametros recpectivos de Servicios.
*/
Servicios::Servicios(string descripcion, string id, string nombre,Ventana *ventana){
    cantidadDispensada = 0;
    this->descripcion = descripcion;
    this->id = id;
    this->nombre = nombre;
    this->ventana = ventana;
}

/*
Destructor de Servicios
*/
Servicios::~Servicios() {
    ventana = nullptr;
}

/*
Metodo del constrcotor de copia para varables no inicializadas
*/
Servicios::Servicios(const Servicios &other) {
    this->descripcion = other.descripcion;
    this->id = other.id;
    this->nombre = other.nombre;
    this->ventana = other.ventana;
}

/*
Sobrecarga del operador de igualdad
*/
void Servicios::operator=(const Servicios &other) {
    this->descripcion = other.descripcion;
    this->id = other.id;
    this->nombre = other.nombre;
    this->ventana = other.ventana;
}

/*
get del id retorna un string
*/
string Servicios::getId(){
    return id;
}

/*
get del nombre retorna un string
*/
string Servicios::getNombre(){
    return nombre;
}

/*
get de ventana retorna un puntero a ventana
*/
Ventana* Servicios::getVentana(){
    return ventana;
}

/*
get del id retorna un string
*/
void Servicios::agregarTiquete(bool tipo){
    cantidadDispensada+=1;
    ventana->agregarTiquete(tipo);
}

/*
get de la cantidad de tiquetes dispensados retorna un int
*/
int Servicios::getCantidadDispensada(){
    return cantidadDispensada;
}

/*
get de la descricion retorna un string
*/
string Servicios::getDescripcion(){
    return descripcion;
}
