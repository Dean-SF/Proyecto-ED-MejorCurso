#include "Controlador.h"

Controlador::Controlador(){
    totalTiquetes = 0;
    totalPreferenciales = 0;
    servicios = new LinkedList<Servicios>();
    ventanas = new LinkedList<Ventana*>();
}

Controlador::~Controlador(){
    delete ventanas;
    delete servicios;
}

string Controlador::estadoColas(){
    string texto = "--Estado de las colas-- \n";
    Ventana *temp;
    ArrayList<Tiquete> *colaNormal;
    ArrayList<Tiquete> *colaPrioridad;
    for(ventanas->goToStart(); !ventanas->atEnd(); ventanas->next()){
        temp = ventanas->getElement();
        texto+="\n --";
        texto += " Ventana: ";
        texto += temp->getCodigo()+", "+temp->getDescripcion()+". \n";
        texto += "Con una cantidad de ventanillas de: "+to_string(temp->getCantidadVentanillas());
        colaNormal = temp->getColaRegular()->toList();
        colaPrioridad = temp->getcolaPrioritaria()->toList();
        texto += "\n Cola regular: ";
        for(colaNormal->goToStart(); !colaNormal->atEnd(); colaNormal->next()){
            texto += colaNormal->getElement().getCodigo();
            if(colaNormal->getPos()!=colaNormal->getSize()){
                texto+=",";
            }else{
                texto+=". \n";
            }
        }
        texto += "\n Cola de prioridad: ";
        for(colaPrioridad->goToStart(); !colaPrioridad->atEnd(); colaPrioridad->next()){
            texto += colaPrioridad->getElement().getCodigo();
            if(colaPrioridad->getPos()!=colaPrioridad->getSize()){
                texto+=",";
            }else{
                texto+=". \n";
            }
        }
        texto+="\n ";
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
            if(preferencial){
                totalPreferenciales+=1;
            }
            totalTiquetes+=1;
            return true;
        }
    }

    return false;
}

string Controlador::atender(string codigoVentana, int numVentanilla){
    Ventana *temp;
    for(ventanas->goToStart(); !ventanas->atEnd(); ventanas->next()){
        temp=ventanas->getElement();
        if(codigoVentana==temp->getCodigo()){
            return temp->atender(numVentanilla);
        }
    }
    return "No exite esta ventana.";
}

bool Controlador::agregarVentana(string codigo, string descripcion, int cantidad){
    Ventana *actual;
    for(ventanas->goToStart(); !ventanas->atEnd(); ventanas->next()){
        actual = ventanas->getElement();
        if(codigo== actual->getCodigo())
            return false;
    }
    Ventana *nueva = new Ventana(codigo, descripcion, cantidad);
    ventanas->append(nueva);
    return true;
}

bool Controlador::eliminarVentana(string codigo){
    for(ventanas->goToStart(); !ventanas->atEnd(); ventanas->next()){
        string codigoActual = ventanas->getElement()->getCodigo();
        if(codigoActual==codigo){
            ventanas->remove();
            return true;
        }
    }
    return false;
}

bool Controlador::agregarServicio(string descripcion, string id, string nombre, string codigo){
    for(servicios->goToStart(); !servicios->atEnd(); servicios->next()){
        if(id==servicios->getElement().getId()){
            return false;
        }
    }
    Ventana *actual;
    for(ventanas->goToStart(); !ventanas->atEnd(); ventanas->next()){
        actual = ventanas->getElement();
        if(actual->getCodigo()==codigo){
            Servicios nuevo = Servicios(descripcion, id, nombre, actual);
            servicios->append(nuevo);
            return true;
        }
    }
    return false;
}

string Controlador::mostrarServicios(){
    string texto = "--Lista de servicios-- \n";
    string id = "";
    string nombre = "";
    for(servicios->goToStart(); !servicios->atEnd(); servicios->next()){
        id = servicios->getElement().getId();
        nombre = servicios->getElement().getNombre();
        texto += "-"+id+", "+nombre+". \n";
    }
    return texto;
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

bool Controlador::moverServicio(string id, int pos){
    //ahacer un swap : D
    return false;
}

string Controlador::tiempoPromedio(){}

string Controlador::dispensadosVentana(){
    string texto = "";
    int total = 0;
    Ventana *temp;
    for(ventanas->goToStart(); !ventanas->atEnd(); ventanas->next()){
        temp=ventanas->getElement();
        texto += "Ventanilla "+temp->getCodigo()+", con una cantidad dispensada de: ";
        texto+= to_string(temp->getTiquetesDispensados())+". \n";
        total += temp->getTiquetesDispensados();
    }
    texto += "Para un total de tiquetes dispensados de: "+to_string(total);
    return texto;
}

string Controlador::atendidosVentana(){
    string texto = "";
    int total = 0;
    Ventana *temp;
    for(ventanas->goToStart(); !ventanas->atEnd(); ventanas->next()){
        temp=ventanas->getElement();
        texto += "Ventanilla "+temp->getCodigo()+", con una cantidad atendida de: ";
        texto+= to_string(temp->getTotalAtendidos())+". \n";
        total += temp->getTotalAtendidos();
    }
    texto += "Para un total de tiquetes dispensados de: "+to_string(total);
    return texto;
}

string Controlador::dispensadosServicio(){
    string texto = "";
    int total = 0;
    Servicios temp;
    for(servicios->goToStart(); !servicios->atEnd(); servicios->next()){
        temp=servicios->getElement();
        texto += "Servicio "+temp.getId()+", con una cantidad dispensada de: ";
        texto+= to_string(temp.getCantidadDispensada())+". \n";
        total += temp.getCantidadDispensada();
    }
    texto += "Para un total de tiquetes dispensados de: "+to_string(total);
    return texto;
}

string Controlador::dispensadosPreferenciales(){
    return "La cantidad de tiquetes preferenciales dispensados es de: "+to_string(totalPreferenciales);
}
