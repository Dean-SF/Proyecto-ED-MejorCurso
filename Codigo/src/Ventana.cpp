#include "Ventana.h"
//Creado por: Deyan Sanabria Fallas

//Contructor de Ventana 
Ventana::Ventana(string codigo, string descripcion, int cantidad) {
    tiquetesDispensados = 0;
    totalAtendidos = 0;
    this->codigo = codigo;
    this->descripcion = descripcion;
    colaRegular = new LinkedQueue<Tiquete*>();
    colaPrioritaria = new LinkedQueue<Tiquete*>();
    ventanillas = new ArrayList<Ventanilla>(cantidad);
    tiemposEspera = new LinkedList<double>();
    Ventanilla nuevo;
    for(int i = 0; i<cantidad; i++){
        nuevo = Ventanilla();
        nuevo.setNumero(i + 1);
        ventanillas->append(nuevo);
    }
}

//Contructor default de ventana
Ventana::Ventana(){
    colaRegular = nullptr;      // inicializar punteros para
    colaPrioritaria = nullptr;  // evitar errores
    ventanillas = nullptr;
}

// Metodo para borrar el contenido de los punteros de la cola
void Ventana::clearTiquetes() {
    Tiquete *temp;  // Temporal
    while (!colaRegular->isEmpty()) { // Se sacan todos los elementos
        temp = colaRegular->dequeue();
        delete temp;                    // y se retorna la memoria
    }
    while (!colaPrioritaria->isEmpty()) {
        temp = colaPrioritaria->dequeue();
        delete temp;
    }
}

//Destructor de Ventana que limpia todos los punteros
Ventana::~Ventana() {
    clearTiquetes();        // Se borrar todos los punteros dentro de la cola
    delete colaRegular;     // borrar todo lo que contienen los punteros
    delete colaPrioritaria;
    delete ventanillas;
    delete tiemposEspera;
}

//Constructor de copia de Ventana
Ventana::Ventana(const Ventana &other) {
    List<Ventanilla> *ventanillasCopia = other.ventanillas;     // Copias de en lista de los atributos de la otra ventana
    List<Tiquete*> *regularCopia = other.colaRegular->toList();  // todo para no poner cosas como "other.colaRegular->goToStart()".
    List<Tiquete*> *prioritariaCopia = other.colaRegular->toList(); // Las colas son mas faciles copiarlas manejandolas como listas
    List<double> *tiemposCopia = other.tiemposEspera;
    
    // copia de parametros
    this->tiquetesDispensados = other.tiquetesDispensados; 
    this->codigo = other.codigo;
    this->descripcion = other.descripcion;

    colaRegular = new LinkedQueue<Tiquete*>();       // Nueva memoria para iniciar los punteros
    colaPrioritaria = new LinkedQueue<Tiquete*>();
    ventanillas = new ArrayList<Ventanilla>(other.ventanillas->getSize());
    tiemposEspera = new LinkedList<double>();

    // Se copian los datos de las estructuras de datos (listas y colas)
    for(ventanillasCopia->goToStart();!ventanillasCopia->atEnd();ventanillasCopia->next()) {
        ventanillas->append(ventanillasCopia->getElement());
    }
    for(regularCopia->goToStart();!regularCopia->atEnd();regularCopia->next()) {
        colaRegular->enqueue(regularCopia->getElement());
    }
    for(prioritariaCopia->goToStart();!prioritariaCopia->atEnd();prioritariaCopia->next()) {
        colaPrioritaria->enqueue(prioritariaCopia->getElement());
    }
    for(tiemposCopia->goToStart(); !tiemposCopia->atEnd(); tiemposCopia->next()) {
        tiemposEspera->append(tiemposCopia->getElement());
    }

}

//Sobreescritura del operador de igualdad
void Ventana::operator=(const Ventana &other){
    // lo mismo que el constructor de copia pero pasando el destructor antes
    this->~Ventana();
    List<Ventanilla> *ventanillasCopia = other.ventanillas; 
    List<Tiquete*> *regularCopia = other.colaRegular->toList();
    List<Tiquete*> *prioritariaCopia = other.colaRegular->toList();
    List<double> *tiemposCopia = other.tiemposEspera;

    this->tiquetesDispensados = other.tiquetesDispensados;
    this->codigo = other.codigo;
    this->descripcion = other.descripcion;
    this->totalAtendidos = other.totalAtendidos;

    colaRegular = new LinkedQueue<Tiquete*>();
    colaPrioritaria = new LinkedQueue<Tiquete*>();
    ventanillas = new ArrayList<Ventanilla>(other.ventanillas->getSize());
    tiemposEspera = new LinkedList<double>();

    for(ventanillasCopia->goToStart();!ventanillasCopia->atEnd();ventanillasCopia->next()) {
        ventanillas->append(ventanillasCopia->getElement());
    }
    for(regularCopia->goToStart();!regularCopia->atEnd();regularCopia->next()) {
        colaRegular->enqueue(regularCopia->getElement());
    }
    for(prioritariaCopia->goToStart();!prioritariaCopia->atEnd();prioritariaCopia->next()) {
        colaPrioritaria->enqueue(prioritariaCopia->getElement());
    }
    for(tiemposCopia->goToStart(); !tiemposCopia->atEnd(); tiemposCopia->next()) {
        tiemposEspera->append(tiemposCopia->getElement());
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
Queue<Tiquete*> *Ventana::getColaRegular() {
    return colaRegular;
}

//get del puntero de la cola prioritaria
Queue<Tiquete*> *Ventana::getcolaPrioritaria() {
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

//Metodo que retorna una version string del estado de las ventanillas
string Ventana::getEstado() {
    Ventanilla actual;
    string atendiendo = "N/A";
    string retorno = string("\nVentana de codigo: ") + codigo + "\n";
    for(ventanillas->goToStart(); !ventanillas->atEnd(); ventanillas->next()) {
        actual = ventanillas->getElement();
        if(actual.getAtendiendo() != nullptr) {
            atendiendo = actual.getAtendiendo()->getCodigo();
        }
        retorno += string("ventanilla numero: ") + to_string(actual.getNumero()) +
        string(" atendiendo ahora mismo: ") + atendiendo + "\n";
    }
    return retorno;
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
    return ventanillas->getSize();
}

//Metoddo que agrega un tique y automaticamente le asiga un codigo y lo mete a una cola segun el booleano
void Ventana::agregarTiquete(bool esPrioritaria){
    string texto = codigo;
    texto += to_string(tiquetesDispensados + 1);
    Tiquete *nuevo = new Tiquete(texto);
    if(esPrioritaria){
        colaPrioritaria->enqueue(nuevo);
    }else{
        colaRegular->enqueue(nuevo);
    }
    tiquetesDispensados+=1;
}

//Metodo que calcula el tiempo de espera del tiquete de entrada
void Ventana::agregarTiempoEspera(Tiquete *tiquete) {
    time_t tiempoCreacion = tiquete->getTiempoCreacion(); // se obtiene el tiempo de creacion
    time_t tiempoActual;                                 // y el tiempo actual
    time(&tiempoActual);
    double tiempoEspera = difftime(tiempoActual,tiempoCreacion); // Se saca la diferencia entre las dos y
    tiemposEspera->append(tiempoEspera);                         // con ello se obtiene lo que se tardo en atender
}

void Ventana::borrarTiqueteAnterior() {
    Tiquete *temp;
    temp = ventanillas->getElement().getAtendiendo();
    delete temp;
    ventanillas->getElement().setAtendiendo(nullptr);
}

//Metodo que atiende o hace dequeue a un tiquete si cumple los requisitos
string Ventana::atender(int codigoVentanilla){
    for(ventanillas->goToStart(); !ventanillas->atEnd(); ventanillas->next()){
        if(codigoVentanilla==ventanillas->getElement().getNumero()){
            Tiquete *temp;
            if(!colaPrioritaria->isEmpty()){
                temp = colaPrioritaria->dequeue();
                borrarTiqueteAnterior();
                ventanillas->getElement().setAtendiendo(temp);
                agregarTiempoEspera(temp);
                totalAtendidos+=1;
                return "Se atendio exitosamente" + getEstado();
            }
            if(!colaRegular->isEmpty()){
                temp = colaRegular->dequeue();
                borrarTiqueteAnterior();
                ventanillas->getElement().setAtendiendo(temp);
                agregarTiempoEspera(temp);
                totalAtendidos +=1;
                return "Se atendio exitosamente" + getEstado();
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
        segundos += tiemposEspera->getElement(); // se suman los segundos que se tardaba por tiquete atendido
    if(tiemposEspera->getSize() != 0)
        segundos = segundos/tiemposEspera->getSize(); // se divide entre la cantidad de tiquetes atendidos
    horas = segundos/3600;
    segundos = segundos%60;
    minutos = segundos/60;
    segundos = segundos%60;
    texto = "\nTipo de ventanilla con codigo: " + codigo + "\ncon tiempo de espera de: ";
    texto += to_string(horas) + string(" horas con ") + to_string(minutos) +
    string(" minutos y ") + to_string(segundos) + " segundos";
    return texto;
 }

