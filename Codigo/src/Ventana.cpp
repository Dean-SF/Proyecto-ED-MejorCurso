#include "Ventana.h"

Ventana::Ventana(string codigo, string descripcion, int cantidad) {
    tiquetesDispensados = 0;
    this->codigo = codigo;
    this->descripcion = descripcion;
    colaRegular = new LinkedQueue<Tiquete>();
    colaPrioritaria = new LinkedQueue<Tiquete>();
    ventanillas = new ArrayList<Ventanilla>(cantidad);
}

Ventana::~Ventana() {
    delete colaRegular;
    delete colaPrioritaria;
    delete ventanillas;
}

string Ventana::getCodigo() {
    return codigo;
}

string Ventana::getDescripcion() {
    return descripcion;
}

List<Ventanilla> *Ventana::getVentanillas() {
    return ventanillas;
}

Queue<Tiquete> *Ventana::getColaRegular() {
    return colaRegular;
}

Queue<Tiquete> *Ventana::getcolaPrioritaria() {
    return colaPrioritaria;
}

int Ventana::getTiquetesDispensados() {
    return tiquetesDispensados;
}

Ventanilla *Ventana::getVentanilla(int numero) {
    ventanillas->goToPos(numero-1);
    return &ventanillas->getElement();
}

void Ventana::setCodigo(string codigo) {
    this->codigo = codigo;
}

void Ventana::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

bool Ventana::operator==(const Ventana &other) {
    return this->codigo == other.codigo;
}
bool Ventana::operator!=(const Ventana &other) {
    return this->codigo != other.codigo;
}

