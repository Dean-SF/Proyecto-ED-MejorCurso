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

Ventana::Ventana(){
    colaRegular = nullptr;
    colaPrioritaria = nullptr;
    ventanillas = nullptr;
}

Ventana::~Ventana() {
    delete colaRegular;
    delete colaPrioritaria;
    delete ventanillas;
}

Ventana::Ventana(const Ventana &other) {
    List<Ventanilla> *ventanillasCopia = other.ventanillas;
    List<Tiquete> *regularCopia = other.colaRegular->toList();
    List<Tiquete> *prioritariaCopia = other.colaRegular->toList();

    this->tiquetesDispensados = other.tiquetesDispensados;
    this->codigo = other.codigo;
    this->descripcion = other.descripcion;
    this->cantidadVentanillas = other.cantidadVentanillas;
    
    colaRegular = new LinkedQueue<Tiquete>();
    colaPrioritaria = new LinkedQueue<Tiquete>();
    ventanillas = new ArrayList<Ventanilla>(other.ventanillas->getSize());
    for(ventanillasCopia->goToStart();!ventanillasCopia->atEnd();ventanillasCopia->next()) {
        ventanillas->append(ventanillasCopia->getElement());
    }
    for(regularCopia->goToStart();!regularCopia->atEnd();regularCopia->next()) {
        colaRegular->enqueue(regularCopia->getElement());
    }
    for(prioritariaCopia->goToStart();!prioritariaCopia->atEnd();prioritariaCopia->next()) {
        colaPrioritaria->enqueue(prioritariaCopia->getElement());
    }
}

void Ventana::operator=(const Ventana &other){
    this->~Ventana();
    List<Ventanilla> *ventanillasCopia = other.ventanillas;
    List<Tiquete> *regularCopia = other.colaRegular->toList();
    List<Tiquete> *prioritariaCopia = other.colaRegular->toList();

    this->tiquetesDispensados = other.tiquetesDispensados;
    this->codigo = other.codigo;
    this->descripcion = other.descripcion;
    this->cantidadVentanillas = other.cantidadVentanillas;
    
    colaRegular = new LinkedQueue<Tiquete>();
    colaPrioritaria = new LinkedQueue<Tiquete>();
    ventanillas = new ArrayList<Ventanilla>(other.ventanillas->getSize());
    for(ventanillasCopia->goToStart();!ventanillasCopia->atEnd();ventanillasCopia->next()) {
        ventanillas->append(ventanillasCopia->getElement());
    }
    for(regularCopia->goToStart();!regularCopia->atEnd();regularCopia->next()) {
        colaRegular->enqueue(regularCopia->getElement());
    }
    for(prioritariaCopia->goToStart();!prioritariaCopia->atEnd();prioritariaCopia->next()) {
        colaPrioritaria->enqueue(prioritariaCopia->getElement());
    }
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

void Ventana::agregarTiquete(bool esPrioritaria){
    string texto = codigo;
    texto += cantidadVentanillas;
    Tiquete nuevo = Tiquete(texto);
    if(esPrioritaria){
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


