#include "Ventana.h"
//Creado por: Deyan Sanabria Fallas

//Contructor completo de Ventana con todos sus datos,
Ventana::Ventana(string codigo, string descripcion, int cantidad) {
    tiquetesDispensados = 0;
    totalAtendidos = 0;
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->cantidadVentanillas = cantidad;
    colaRegular = new LinkedQueue<Tiquete>();
    colaPrioritaria = new LinkedQueue<Tiquete>();
    ventanillas = new ArrayList<Ventanilla>(cantidad);
    tiemposEspera = new LinkedList<double>();
    Ventanilla nuevo;
    for(int i = 0; i<cantidad; i++){
        nuevo = Ventanilla();
        nuevo.setNumero(i);
        ventanillas->append(nuevo);
    }
}

//Contructor vaicio de ventana
Ventana::Ventana(){
    colaRegular = nullptr;
    colaPrioritaria = nullptr;
    ventanillas = nullptr;
}

//Destructor de Ventana que limpia todos los punteros
Ventana::~Ventana() {
    delete colaRegular;
    delete colaPrioritaria;
    delete ventanillas;
}

//Constructor de copia de Ventana
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

//Sobrecarga del operador de igualdad
void Ventana::operator=(const Ventana &other){
    this->~Ventana();
    List<Ventanilla> *ventanillasCopia = other.ventanillas;
    List<Tiquete> *regularCopia = other.colaRegular->toList();
    List<Tiquete> *prioritariaCopia = other.colaRegular->toList();

    this->tiquetesDispensados = other.tiquetesDispensados;
    this->codigo = other.codigo;
    this->descripcion = other.descripcion;
    this->cantidadVentanillas = other.cantidadVentanillas;
    this->totalAtendidos = other.totalAtendidos;

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

//get del codigo de la ventana
string Ventana::getCodigo() {
    return codigo;
}

//get de la descipcion de la ventana
string Ventana::getDescripcion() {
    return descripcion;
}

//get del puntero de la lista de ventanillas
List<Ventanilla> *Ventana::getVentanillas() {
    return ventanillas;
}

//get del puntero de la cola regular
Queue<Tiquete> *Ventana::getColaRegular() {
    return colaRegular;
}

//get del puntero de la cola prioritaria
Queue<Tiquete> *Ventana::getcolaPrioritaria() {
    return colaPrioritaria;
}

//get de la cantidad de tiquetes dispensados
int Ventana::getTiquetesDispensados() {
    return tiquetesDispensados;
}

//Retorna una ventailla indicada por la posicion dada
Ventanilla Ventana::getVentanilla(int numero) {
    ventanillas->goToPos(numero-1);
    return ventanillas->getElement();
}

//set del codigo de la ventana
void Ventana::setCodigo(string codigo) {
    this->codigo = codigo;
}

//set de la descipcion.
void Ventana::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

//sobrecarga del operador de comparacion igual
bool Ventana::operator==(const Ventana &other) {
    return this->codigo == other.codigo;
}

//sobrecarga del operador de diferente
bool Ventana::operator!=(const Ventana &other) {
    return this->codigo != other.codigo;
}

//get de la cantidad de ventanillas en la ventana
int Ventana::getCantidadVentanillas(){
    return cantidadVentanillas;
}

//Metoddo que agrega un tique y automaticamente le asiga un codigo y lo mete a una cola segun el booleano
void Ventana::agregarTiquete(bool esPrioritaria){
    string texto = codigo;
    texto += to_string(cantidadVentanillas);
    Tiquete nuevo = Tiquete(texto);
    if(esPrioritaria){
        colaPrioritaria->enqueue(nuevo);
    }else{
        colaRegular->enqueue(nuevo);
    }
    tiquetesDispensados+=1;
}

//Metodo que tomma un tiquete le saca la hora de creacion la compara con la actual y saca el tiempo de espera y lo suma
void Ventana::agregarTiempoEspera(Tiquete tiquete) {
    time_t tiempoCreacion = tiquete.getTiempoCreacion();
    time_t tiempoActual;
    time(&tiempoActual);
    double tiempoEspera = difftime(tiempoActual,tiempoCreacion);
    tiemposEspera->append(tiempoEspera);
}

//Metodo que atiende o hace dequeue a un tiquete si cumple los requisitos
string Ventana::atender(int codigoVentanilla){
    for(ventanillas->goToStart(); !ventanillas->atEnd(); ventanillas->next()){
        if(codigoVentanilla==ventanillas->getElement().getNumero()){
            Tiquete temp;
            if(!colaPrioritaria->isEmpty()){
                temp = colaPrioritaria->dequeue();
                ventanillas->getElement().setAtendiendo(temp);
                agregarTiempoEspera(temp);
                totalAtendidos+=1;
                return "Se atendio exitosamente";
            }
            if(!colaRegular->isEmpty()){
                temp = colaRegular->dequeue();
                ventanillas->getElement().setAtendiendo(temp);
                agregarTiempoEspera(temp);
                totalAtendidos +=1;
                return "Se atendio exitosamente";
            }
            return "Las filas estan vacias";

        }
    }
    return "No existe esa ventanilla.";
}

//get de la cantidad total de atendidos
int Ventana::getTotalAtendidos(){
    return totalAtendidos;
 }

 //get del total de tiempo de espera de todos los tiquetes
string Ventana::getTiempoEspera() {
    string texto;
    int segundos = 0;
    int minutos = 0;
    int horas = 0;
    for(tiemposEspera->goToStart(); !tiemposEspera->atEnd(); tiemposEspera->next())
        segundos += tiemposEspera->getElement();
    if(tiemposEspera->getSize() != 0)
        segundos = segundos/tiemposEspera->getSize();
    horas = segundos/3600;
    segundos = segundos%60;
    minutos = segundos/60;
    segundos = segundos%60;
    texto = "\nTipo de ventanilla con codigo: " + codigo + "\ncon tiempo de espera de: ";
    texto += to_string(horas) + string(" horas con ") + to_string(minutos) +
    string(" minutos y ") + to_string(segundos) + " segundos";
    return texto;
 }

