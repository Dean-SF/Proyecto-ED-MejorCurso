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

class Ventana {
    private:
        int tiquetesDispensados;
        string codigo;
        string descripcion;
        Queue<Tiquete> *colaNormal;
        Queue<Tiquete> *colaPrioritaria;
        List<Ventanilla> *ventanillas;
        
    public: 
        Ventana(string codigo, string descripcion, int cantidad);
        ~Ventana();
        string getCodigo();
        string getDescripcion();
        List<Ventanilla> *getVentanillas();


    
};

#endif // VENTANA_H
