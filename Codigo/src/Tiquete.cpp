#include "Tiquete.h"

// Por Deyan Sanabria Fallas
// Constructor de la clase
Tiquete::Tiquete(string codigo) {
    time(&tiempo_creacion); // tiempo actual
    this->codigo = codigo;
}

//Contructor vacio
Tiquete::Tiquete(){
    codigo = "N/A";
    tiempo_creacion = 0;
}

//Contructor de copia
Tiquete::Tiquete(const Tiquete &other){
    this->codigo = other.codigo;
    this->tiempo_creacion = other.tiempo_creacion;
}

//Sobrecarga del operador de asignacion
void Tiquete::operator=(const Tiquete &other) {
    this->codigo = other.codigo;
    this->tiempo_creacion = other.tiempo_creacion;
}

// Setters y getters:
//get del codigo
string Tiquete::getCodigo() {
    return codigo;
}

//set del codigo
void Tiquete::setCodigo(string codigo) {
    this->codigo = codigo;
}

//get del tiempo
time_t Tiquete::getTiempoCreacion() {
    return tiempo_creacion;
}
