//Creado por: Esteban Perez Picado
//Fecha de creacion: 15/10/2021
//Ultima modificacion: 18/10/2021
//Modificado por: Deyan Sanabria Fallas
#include "Controlador.h"

/*
Contructor prinipal de la clase controlador.
*/
Controlador::Controlador(){
    totalTiquetes = 0;
    totalPreferenciales = 0;
    servicios = new LinkedList<Servicios>();
    ventanas = new LinkedList<Ventana*>();
}

/*
Destructor del controlador que elimina los punteros de las dos listas.
*/
Controlador::~Controlador(){
    delete ventanas;
    delete servicios;
}

/*
Metodo que muestra el estado de las colas y retorna un string con los diferentes datos de todas las
colas actuales en el programa, el string contiene el nombre, la id
la cantidad de ventanillas y sus dos colas respectivas.
*/
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
            if(colaNormal->getPos()!=colaNormal->getSize()-1){
                texto+=",";
            }else{
                texto+=".";
            }
        }
        texto += "\n Cola de prioridad: ";
        for(colaPrioridad->goToStart(); !colaPrioridad->atEnd(); colaPrioridad->next()){
            texto += colaPrioridad->getElement().getCodigo();
            if(colaPrioridad->getPos()!=colaPrioridad->getSize()-1){
                texto+=",";
            }else{
                texto+=".";
            }
        }
        texto+="\n ";
    }
    return texto;
}

/*
Metodo que agrega un tiquete a la ventana retorna un booleano para verificar la correcta agregacion de un tiquete
este llama a agregarTiquete de Servicio y cuenta la cantidad tota y
la cantidad de preferenciales.
*/
bool Controlador::agregarTiquete(bool preferencial, string codigo){
    Servicios temp;
    for(servicios->goToStart();!servicios->atEnd(); servicios->next()){
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

/*
Metodo que atiende un retorno retorna un string con la conformacion de que se atendio un tiquete
ademas llama a atender de Ventana.
*/
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

/*
Metodo que agrega una ventana retorna un booleano confirmando la agreacion de una nueva ventana, este
verifica que no exxita otra igual y si es asi la crea y la agrega a la lista.
*/
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

/*
Metodo que elimina una ventana y retorna un numero segun los diferentes
casos para indicar un error o la correcta eliminacion.
*/
int Controlador::eliminarVentana(string codigo){
    Ventana *temp;
    Servicios tempServicio;
    for(ventanas->goToStart(); !ventanas->atEnd(); ventanas->next()){
        temp = ventanas->getElement();
        if(temp->getCodigo()==codigo){
            for(servicios->goToStart();!servicios->atEnd();servicios->next()){
                tempServicio = servicios->getElement();
                if(tempServicio.getVentana()==temp) {
                    return -1;
                }
            }
            delete temp;
            ventanas->remove();
            return 1;
        }
    }
    return 0;
}

/*
Metodo que agrega un servicio y retorna un booleano para ocnfirmar, verifica que no este
repetido, lo crea y lo agrega a la lista.
*/
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

/*
Metodo que muestra todos los servicios, retorna un string con el nombre,
descripcion y la id.
*/
string Controlador::mostrarServicios(){
    string texto = "--Lista de servicios-- \n";
    string id = "";
    string nombre = "";
    for(servicios->goToStart(); !servicios->atEnd(); servicios->next()){
        id = servicios->getElement().getId();
        nombre = servicios->getElement().getNombre();
        texto += "-"+id+", "+nombre+"("+servicios->getElement().getDescripcion()+"). \n";
    }
    return texto;
}

/*
Metodo que elimina un servicio de la lista y retorna un
booleano como confirmacion.
*/
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

/*
Metodo que llama al swapElement de la lista para intercambiar los
servicios segun la posicion dada y retorna un booleano.
*/
bool Controlador::moverServicio(string id, int pos){
    for(servicios->goToStart(); !servicios->atEnd(); servicios->next()){
        string idActual = servicios->getElement().getId();
        if(idActual==id){
            return servicios->swapElement(servicios->getElement(), pos);
        }
    }
    return false;
}

/*
Metodo que retorna un string con la cuenta promedio del tiempo para
atender un tiquete.
*/
string Controlador::tiempoPromedio(){
    string texto = "\n------- Tiempos Promedios -------";
    for(ventanas->goToStart(); !ventanas->atEnd(); ventanas->next()) {
        texto += ventanas->getElement()->getTiempoEspera();
    }
    if(texto == "\n------- Tiempos Promedios -------") {
        return "No hay ventanas disponibles";
    }
    return texto;
}

/*
Metodo que crea un string con los tiquetes dispensados de cada ventana
*/
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

/*
Metodo que crea un string con los tiquetes atendidos de cada ventana
*/
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
    texto += "Para un total de tiquetes atendidos de: "+to_string(total);
    return texto;
}

/*
Metodo que crea un string con los tiquetes dispensados de cada servicio.
*/
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

/*
Retorna un string con la cantidad de tiquetes dispensados en el programa.
*/
string Controlador::dispensadosPreferenciales(){
    return "La cantidad de tiquetes preferenciales dispensados es de: "+to_string(totalPreferenciales);
}
