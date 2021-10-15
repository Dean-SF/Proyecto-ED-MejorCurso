#ifndef TIQUETE_H
#define TIQUETE_H
#include <iostream>
#include <string.h>
#include <time.h>

using std::string;

/*
Clase por Deyan Sanabria Fallas
Esta clase representa un tiquete, cada tiquete tiene una fecha de creacion
y codigo que lo identifique. La fecha puede ser posteriormente usada
para el tiempo aproximado por tipo de ventanilla
*/
class Tiquete{   
    private:
        string codigo;
        time_t tiempo_creacion;
    public:
        Tiquete(string codigo);
        string getCodigo();
        void setCodigo(string codigo);
        time_t getTiempoCreacion();
    
};

#endif // TIQUETE_H
