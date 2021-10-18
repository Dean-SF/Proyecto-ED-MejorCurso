#include "Tiquete.h"

// Por Deyan Sanabria Fallas
// Constructor de la clase
Tiquete::Tiquete(string codigo) {
    time(&tiempo_creacion); // tiempo actual
    this->codigo = codigo;
}

Tiquete::Tiquete(){
    codigo = "N/A";
    tiempo_creacion = 0;
}

Tiquete::Tiquete(const Tiquete &other){
    this->codigo = other.codigo;
    this->tiempo_creacion = other.tiempo_creacion;
}

void Tiquete::operator=(const Tiquete &other) {
    this->codigo = other.codigo;
    this->tiempo_creacion = other.tiempo_creacion;
}

// Setters y getters:
string Tiquete::getCodigo() {
    return codigo;
}

void Tiquete::setCodigo(string codigo) {
    this->codigo = codigo;
}

time_t Tiquete::getTiempoCreacion() {
    return tiempo_creacion;
}
