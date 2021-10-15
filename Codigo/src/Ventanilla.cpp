#include "Ventanilla.h"

// Por Deyan Sanabria Fallas
// Constructor de la clase
Ventanilla::Ventanilla() {
    atendiendo = nullptr; // Inicialmente la ventanilla no atiende a nadie
}

Ventanilla::~Ventanilla() {
    delete atendiendo; // limpiar el puntero
}

// Setter y getters:
Tiquete *Ventanilla::getAtendiendo() {
    return atendiendo;
}

void Ventanilla::setAtendiendo(Tiquete &atentiendo) {
    this->atendiendo = atendiendo;
}

int Ventanilla::getNumero(){
    return numero;
}

void Ventanilla::setNumero(int numero) {
    this->numero = numero;
}

