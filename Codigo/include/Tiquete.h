#ifndef TIQUETE_H
#define TIQUETE_H
#include <iostream>
#include <string.h>
#include <time.h>

using std::string;

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
