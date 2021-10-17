#ifndef VENTANA_H
#define VENTANA_H
#include <iostream>
#include <string.h>
#include "Tiquete.h"
#include "Ventanilla.h"

#include "List.h"
#include "ArrayList.h"
#include "Queue.h"
#include "LinkedQueue.h"

using std::string;

class Ventana {
    private:
        int tiquetesDispensados;
        int cantidadVentanillas;
        string codigo;
        string descripcion;
        Queue<Tiquete> *colaRegular = new LinkedQueue<Tiquete>();
        Queue<Tiquete> *colaPrioritaria= new LinkedQueue<Tiquete>();
        List<Ventanilla> *ventanillas= new ArrayList<Ventanilla>();

    public:
        Ventana(string codigo, string descripcion, int cantidad);
        Ventana();
        ~Ventana();
        string getCodigo();
        string getDescripcion();
        List<Ventanilla> *getVentanillas();
        Queue<Tiquete> *getColaRegular();
        Queue<Tiquete> *getcolaPrioritaria();
        int getTiquetesDispensados();
        Ventanilla getVentanilla(int numero);
        void setCodigo(string codigo);
        void setDescripcion(string descripcion);
        bool operator==(const Ventana &other);
        bool operator!=(const Ventana &other);
        int getCantidadVentanillas();
        void agregarTiquete(bool tipo);
        string atender(int ventanilla);

};

#endif // VENTANA_H
