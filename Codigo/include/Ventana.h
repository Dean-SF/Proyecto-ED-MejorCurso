//Creado por: Deyan Sanabria Fallas
//Modificado por: Esteban Perez Picado

#ifndef VENTANA_H
#define VENTANA_H
#include <iostream>
#include <string.h>
#include "Tiquete.h"
#include "Ventanilla.h"

#include "List.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "Queue.h"
#include "LinkedQueue.h"

using std::string;

/*
Clase creada por Deyan Sanabria Fallas
Clase de ventana que permite la creacion de tiquetes, servicios y las ventanilas dentro de esta.
*/
class Ventana {
    private:
        int tiquetesDispensados;
        int totalAtendidos;
        string codigo;
        string descripcion;
        Queue<Tiquete*> *colaRegular;
        Queue<Tiquete*> *colaPrioritaria;
        List<Ventanilla> *ventanillas;
        List<double> *tiemposEspera;
        void agregarTiempoEspera(Tiquete *tiquete);
        void clearTiquetes();
        void borrarTiqueteAnterior();
    public:
        Ventana(string codigo, string descripcion, int cantidad);
        Ventana(const Ventana& other);
        Ventana();
        ~Ventana();
        void operator=(const Ventana& other);
        string getCodigo();
        string getDescripcion();
        List<Ventanilla> *getVentanillas();
        Queue<Tiquete*> *getColaRegular();
        Queue<Tiquete*> *getcolaPrioritaria();
        int getTiquetesDispensados();
        Ventanilla getVentanilla(int numero);
        string getEstado();
        void setCodigo(string codigo);
        void setDescripcion(string descripcion);
        bool operator==(const Ventana &other);
        bool operator!=(const Ventana &other);
        int getCantidadVentanillas();
        void agregarTiquete(bool tipo);
        string atender(int ventanilla);
        int getTotalAtendidos();
        string getTiempoEspera();

};

#endif // VENTANA_H
