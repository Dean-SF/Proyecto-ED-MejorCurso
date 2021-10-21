#include "Ventanilla.h"

// Por Deyan Sanabria Fallas
// Constructor de la clase
Ventanilla::Ventanilla() {
    atendiendo = nullptr; // Inicialmente la ventanilla no atiende a nadie
}

//Destructor default de ventanilla limpia el puntero de atendiendo
Ventanilla::~Ventanilla() {
    delete atendiendo; // limpiar el puntero
}

// Setter y getters:
//get del puntero a atendiendo
Tiquete *Ventanilla::getAtendiendo() {
    return atendiendo;
}

//set del puntero de atendiendo
void Ventanilla::setAtendiendo(Tiquete *atendiendo1) {
    if(atendiendo1 != nullptr)
        atendidos++;
    this->atendiendo = atendiendo1;
}

//get del numero de la ventanilla
int Ventanilla::getNumero(){
    return numero;
}

//set del numero de la ventanilla
void Ventanilla::setNumero(int numero) {
    this->numero = numero;
}

//get de la cantdad de atendidos
int Ventanilla::getAtendidos() {
    return atendidos;
}

//Sobrecarga del operador de comperacion igual
bool Ventanilla::operator==(const Ventanilla &other) {
    return this->numero == other.numero;
}

//sobrecarga del operador de comparacion diferente
bool Ventanilla::operator!=(const Ventanilla &other) {
    return this->numero != other.numero;
}

