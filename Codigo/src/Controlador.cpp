#include "Controlador.h"

Controlador::Controlador(){
    totalTiquetes = 0;
    totalPreferenciales = 0;
    servicios = new LinkedList<Servicios>();
    ventanas = new LinkedList<Ventana>();
}

Controlador::~Controlador(){
    delete ventanas;
    delete servicios;
}

string Controlador::estadoColas(){
    /*string texto = "";
    for(ventanas->goToStart(); !ventanas->atEnd(); ventanas->next()){
        //texto += ventanas->getElement().getCodigo();
    }*/
}

bool Controlador::agregarTiquete(bool preferencial, string codigo){

}

string Controlador::atender(string codigoVentana, string numVentanilla){}

bool Controlador::agregarVentana(string codigo, string descripcion, int cantidad){

}

bool Controlador::eliminarVentana(string codigo){
    /*for(ventanas->goToStart(); !ventanas->atEnd(); ventanas->next()){
        string codigoActual = ventanas->getElement().getCodigo();
        if(codigoActual==codigo){
            ventanas->remove();
            return true;
        }
    }*/
}

bool Controlador::agregarServicio(string descripcion, string id, string nombre, string codigo){

    //Servicios nuevo = new Servicios(string descripcion, string id, nullptr);

    return false;
}

bool Controlador::eliminarServicio(string id){
      for(servicios->goToStart(); !servicios->atEnd(); servicios->next()){
        string idActual = servicios->getElement().getId();
        if(idActual==id){
            servicios->remove();
            return true;
        }
    }
}

bool Controlador::moverServicio(string id){}

time_t Controlador::tiempoPromedio(){}

string Controlador::dispensadosVentana(){}

string Controlador::atendidosVentana(){}

string Controlador::dispensadosServicio(){}

int Controlador::dispensadosPreferenciales(){
    return totalPreferenciales;
}
