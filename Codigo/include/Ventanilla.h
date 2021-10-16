#ifndef VENTANILLA_H
#define VENTANILLA_H
#include "Tiquete.h"

/*
Clase por Deyan Sanabria Fallas
Esta clase mantiene constancia del numero de ventanilla y el tiquete
siendo atendido al momento.
*/
class Ventanilla{
    private:
        int numero;
        int atendidos;
        Tiquete *atendiendo;
    public:
        Ventanilla();
        ~Ventanilla();
        Tiquete *getAtendiendo();
        void setAtendiendo(Tiquete &atentiendo);
        int getNumero();
        void setNumero(int numero);
        int getAtendidos();
        bool operator==(const Ventanilla &other);
        bool operator!=(const Ventanilla &other);
    
};

#endif // VENTANILLA_H
