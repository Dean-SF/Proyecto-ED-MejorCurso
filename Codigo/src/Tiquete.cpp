#include "include/Tiquete.h"

Tiquete::Tiquete(string codigo) {
    time(&tiempo_creacion);
    this->codigo = codigo;
}

string Tiquete::getCodigo() {
    return codigo;
}

void Tiquete::setCodigo(string codigo) {
    this->codigo = codigo;
}

time_t Tiquete::getTiempoCreacion() {
    return tiempo_creacion;
}
