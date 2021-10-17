#include "Ventana.h"

Ventana::Ventana(string codigo, string descripcion, int cantidad) {
    tiquetesDispensados = 0;
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->cantidadVentanillas = cantidad;
    colaRegular = new LinkedQueue<Tiquete>();
    colaPrioritaria = new LinkedQueue<Tiquete>();
    ventanillas = new ArrayList<Ventanilla>(cantidad);
    Ventanilla nuevo;
    for(int i = 0; i<cantidad; i++){
        nuevo = Ventanilla();
        nuevo.setNumero(i);
        ventanillas->append(nuevo);
    }
}

Ventana::Ventana(){}

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

Ventanilla Ventana::getVentanilla(int numero) {
    ventanillas->goToPos(numero-1);
    return ventanillas->getElement();
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

int Ventana::getCantidadVentanillas(){
    return cantidadVentanillas;
}

void Ventana::agregarTiquete(bool tipo){
    string texto = codigo;
    texto += cantidadVentanillas;
    Tiquete nuevo(texto);
    if(tipo){
        colaPrioritaria->enqueue(nuevo);
    }else{
        colaRegular->enqueue(nuevo);
    }
    tiquetesDispensados+=1;
}

string Ventana::atender(int codigoVentanilla){
    for(ventanillas->goToStart(); !ventanillas->atEnd(); ventanillas->next()){
        if(codigoVentanilla==ventanillas->getElement().getNumero()){
            Tiquete temp;
            if(!colaPrioritaria->isEmpty()){
                temp = colaPrioritaria->dequeue();
                ventanillas->getElement().setAtendiendo(temp);
                return "Se atendio exitosamente";
            }else if(!colaRegular->isEmpty()){
                temp = colaRegular->dequeue();
                ventanillas->getElement().setAtendiendo(temp);
                return "Se atendio exitosamente";
            }else{
                return "Las filas estan vacias";
            }
        }
    }
    return "No existe esa ventanilla.";
}


