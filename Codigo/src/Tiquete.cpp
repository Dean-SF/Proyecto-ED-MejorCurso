#include "Tiquete.h"

// Por Deyan Sanabria Fallas
// Constructor de la clase
Tiquete::Tiquete(string codigo) {
    time(&tiempo_creacion); // tiempo actual
    this->codigo = codigo;
}

Tiquete::Tiquete(){}

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
