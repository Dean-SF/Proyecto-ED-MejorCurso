//Creado por: Mauricio Aviles Cisneros
//Modificado por: Deyan Sanabria Fallas
#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "List.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename E>
class ArrayList : public List<E> {
private:
    E *elements;
    int max;
    int size;
    int pos;

    /*
    Metodo privado checkListSize:
    revisa el tamaño de la lista para verificar si es necesario hacerla mas grande
    */
    void checkListSize() {
        if(size == max) {
            expand();
        }
    }

    /*
    Metodo privado checkCurrentElement:
    revisa la existencia de un elemento actual
    */
    void checkCurrentElement() {
        if(size == 0) {
            throw runtime_error("Error: List is empty");
        }
        if(pos == size) {
            throw runtime_error("Error: No current element");
        }

    }

    /*
    Metodo Privado expand:
    Aumenta el tamaño de la lista el doble
    */
    void expand() {
        max *= 2;                           // se dup;ica el tamaño
        E *temp = new E[max];               // se crea array temporal con el doble tamaño
        for(int i = 0; i < size; i++) {     // se copian los elementos de un array a otro
            temp[i] = elements[i];
        }
        delete [] elements;                 // se borra el array viejo y se reemplaza con el nuevo
        elements = temp;
    }

public:

    // Constructor de la clase
    ArrayList(int max = 5) {
        elements = new E[max];
        pos = size = 0;
        this->max = max;
    }

    // Deconstructor de la clase
    ~ArrayList() {
        delete [] elements;
    }
    /*
    Metodo insert:
    inserta un elemento en la posicion actual
    */
    void insert(E element) {
        checkListSize();
        for(int i = size; i > pos; i--) {
            elements[i] = elements[i - 1];
        }
        elements[pos] = element;
        size++;
    }
    /*
    Metodo append:
    Inserta un elemento en la ultima posicion
    */
    void append(E element) {
        checkListSize();
        elements[size] = element;
        size++;
    }

    /*
    Metodo remove:
    Elimina el elemento actual
    */
    E remove() {
        checkCurrentElement();
        E result = elements[pos];
        for (int i = pos + 1; i < size; i++) {
            elements[i - 1] = elements[i];
        }
        size--;
        return result;
    }

    /*
    Metodo clear
    */
    void clear() {
        size = pos = 0;
        delete [] elements;
        elements = new E[max];
    }

    /*
    Metodo getElement:
    retorna el elemento actual
    */
    E getElement() {
        checkCurrentElement();
        return elements[pos];
    }

    /*
    Metodo goToStart:
    mueve la posicion actual al inicio de la lista
    */
    void goToStart() {
        pos = 0;
    }
    /*
    Metodo goToEnd:
    mueve la posicion actual al final de la lista
    */
    void goToEnd() {
        pos = size;
    }
    /*
    Metodo goToPos:
    mueve la posicion actual a un indice indicado
    */
    void goToPos(int pos) {
        if (pos < 0 || pos > size)
            throw runtime_error("Error: Position out of range");
        this->pos = pos;
    }

    /*
    Metodo next:
    mueve la posicion actual al siguiente
    */
    void next() {
        if(pos < size)
            pos++;
    }

    /*
    Metodo previous:
    mueve la posicion actual al anterior
    */
    void previous() {
        if (pos > 0)
            pos--;
    }

    /*
    Metodo atStart:
    Indica si se esta al inicio de la lista
    */
    bool atStart() {
        return pos == 0;
    }

    /*
    Metodo atEnd:
    Indica si se esta al final de la lista
    */
    bool atEnd() {
        return pos == size;
    }

    /*
    Metodo getPos:
    retorna la posicion actual
    */
    int getPos() {
        return pos;
    }

    /*
    Metodo getSize:
    retorna el tamaño de la lista
    */
    int getSize() {
        return size;
    }

    /*
    metodo print:
    Imprime la lista
    */
    void print() {
        int oldPos = pos;
        cout << "[ ";
        for(goToStart(); !atEnd(); next()) {
            cout << getElement() << " ";
        }
        cout << "]" << endl;
        pos = oldPos;
    }
    /*
    metodo indexOf:
    retorna el indice de un elemento dado, si no existe, retorna -1
    */
    int indexOf(E element) {
        int oldPos = pos;                           // Se guarda la posicion actual de la lista.
        int temp;
        for(goToStart(); !atEnd(); next()) {        // Con un ciclo se recorre la lista
            if(getElement()==element) {             // y revisa si existe el elemento.
                temp = pos;                         // se guarda la posicion a retornar de forma temporal
                pos = oldPos;                       // Se recupera la posicion en la que estaba la lista
                return temp;                        // para dejarla sin alterar.
            }
        }
        pos = oldPos;                               // Se recupera la posicion en la que estaba la lista en caso
        return -1;                                  // que no haya encontrado el elemento
    }

    /*
    Metodo contain:
    retorna un booleano dependiendo si un elemento existe en la lista
    */
    bool contains(E element) {
        return indexOf(element) != -1;              // Se usa el metodo anterior y se comprueba si es distinto de -1
    }                                               // para de volver true

    /*
    Metodo extend:
    añada los elementos de una lista entrante al final de la lista
    */
    void extend(List<E> *L) {
        int oldPos = L->getPos();
        for(L->goToStart(); !L->atEnd(); L->next()) {   // recorre todos los elementos de la lista entrante
            this->append(L->getElement());              // y le hace append a cada elemento
        }
        L->goToPos(oldPos);                             // se devuelve la posicion que tenia antes de alterarla
    }

    /*
    Metodo extend:
    añada los elementos de una lista entrante al final de la lista
    */
    bool equals(List<E> *L) {
        int oldPosEntrada = L->getPos();                                                // Se guardan la posiciones actuales de las listas
        int oldPos = getPos();
        for(goToStart(),L->goToStart(); !atEnd() || !L->atEnd(); next(),L->next()) {        // Con un for se manda ambas listas a su inicio.
            if (L->getElement() != getElement()) {                                      // se cambia de elemento en cada ciclo,
                L->goToPos(oldPosEntrada);                                              // y se comprueba si alguna lista llego al final
                goToPos(oldPos);                                                        // si algun elemento no cuadra se retorna false
                return false;                                                           // y se restauran las posiciones
            }
        }
        L->goToPos(oldPosEntrada);                                                      // Si no, se devuelve true y se restauran las posiciones
        goToPos(oldPos);
        return true;

    }
};

#endif
