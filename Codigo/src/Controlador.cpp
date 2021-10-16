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
    string texto = "";
    Ventana temp;
    ArrayList<Tiquete> *colaNormal;
    ArrayList<Tiquete> *colaPrioridad;
    for(ventanas->goToStart(); !ventanas->atEnd(); ventanas->next()){
        temp = ventanas->getElement();
        texto += temp.getCodigo()+" "+temp.getDescripcion()+'\n';
        texto += "Con una cantidad de ventanillas de: "+temp.getCantidadVentanillas()+'\n';
        colaNormal = temp.getColaRegular()->toList();
        colaPrioridad = temp.getcolaPrioritaria()->toList();
        texto += "Cola regular: ";
        for(colaNormal->goToStart(); !colaNormal->atEnd(); colaNormal->next()){
            texto += colaNormal->getElement().getCodigo();
            if(colaNormal->getPos()!=colaNormal->getSize()){
                texto+=",";
            }else{
                texto+="."+'\n';
            }
        }
        texto += "Cola de prioridad: ";
        for(colaPrioridad->goToStart(); !colaPrioridad->atEnd(); colaPrioridad->next()){
            texto += colaPrioridad->getElement().getCodigo();
            if(colaPrioridad->getPos()!=colaPrioridad->getSize()){
                texto+=",";
            }else{
                texto+="."+'\n';
            }
        }
    }
    return texto;
}

bool Controlador::agregarTiquete(bool preferencial, string codigo){
    Servicios temp;
    for(int i = 0; i<servicios->getSize(); i++){
        servicios->goToPos(i);
        temp = servicios->getElement();
        if(temp.getId()==codigo){
            temp.agregarTiquete(preferencial);
            return true;
        }
    }
    return false;
}

string Controlador::atender(string codigoVentana, int numVentanilla){
    Ventana temp;
    for(ventanas->goToStart(); !ventanas->atEnd(); ventanas->next()){
        temp=ventanas->getElement();
        if(codigoVentana==temp.getCodigo()){
            return temp.atender(numVentanilla);
        }
    }
    return "No exite esta ventana.";
}

bool Controlador::agregarVentana(string codigo, string descripcion, int cantidad){
    return false;
}

bool Controlador::eliminarVentana(string codigo){
    for(ventanas->goToStart(); !ventanas->atEnd(); ventanas->next()){
        string codigoActual = ventanas->getElement().getCodigo();
        if(codigoActual==codigo){
            ventanas->remove();
            return true;
        }
    }
    return false;
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
    return false;
}

bool Controlador::moverServicio(string id){
    return false;
}

time_t Controlador::tiempoPromedio(){}

string Controlador::dispensadosVentana(){}

string Controlador::atendidosVentana(){}

string Controlador::dispensadosServicio(){}

int Controlador::dispensadosPreferenciales(){
    return totalPreferenciales;
}
