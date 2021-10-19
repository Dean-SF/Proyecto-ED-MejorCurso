#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "List.h"
#include "Node.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename E>
class LinkedList : public List<E> {
private:
    Node<E> *head;
    Node<E> *current;
    Node<E> *tail;
    int size;

public:

    // Constructor de la clase
    LinkedList() {
        tail = current = head =  new Node<E>();
        size = 0;
    }

    // Deconstructor de la clase
    ~LinkedList() {
        clear();
        delete head;
    }

    /*
    Metodo insert:
    inserta un elemento en la posicion actual
    */
    void insert(E element) {
        current->next = new Node<E>(element,current->next);
        if(current == tail) {
            tail = current->next;
        }
        size++;
    }

    /*
    Metodo append:
    Inserta un elemento en la ultima posicion
    */
    void append(E element) {
        tail = tail->next = new Node<E>(element,nullptr);
        size++;
    }

    /*
    Metodo remove:
    Elimina el elemento actual
    */
    E remove() {
        if (size == 0)
            throw runtime_error("Error: List is empty");
        if (current == tail)
            throw runtime_error("Error: There is no current element");
        E result = current->next->element;
        Node<E> *temp = current->next;
        current->next = current->next->next;
        if (tail == temp)
            tail = current;
        delete temp;
        size--;
        return result;
    }

    /*
    Metodo clear
    */
    void clear() {
        while(head->next != nullptr) {
            current = head->next;
            head->next = current->next;
            delete current;
        }
        current = tail = head;
        size = 0;
    }

    /*
    Metodo getElement:
    retorna el elemento actual
    */
    E getElement() {
        return current->next->element;
    }

    /*
    Metodo goToStart:
    mueve la posicion actual al inicio de la lista
    */
    void goToStart() {
        current = head;
    }

    /*
    Metodo goToEnd:
    mueve la posicion actual al final de la lista
    */
    void goToEnd() {
        current = tail;
    }

    /*
    Metodo goToPos:
    mueve la posicion actual a un indice indicado
    */
    void goToPos(int pos) {
        if (pos < 0 || pos > size)
            throw runtime_error("Index out of range.");
        current = head;
        for (int i = 0; i < pos; i++)
            current = current->next;
    }

    /*
    Metodo next:
    mueve la posicion actual al siguiente
    */
    void next() {
        if (current != tail)
            current = current->next;
    }

    /*
    Metodo previous:
    mueve la posicion actual al anterior
    */
    void previous() {
        if (current != head) {
            Node<E> *temp = head;
            while(temp->next != current)
                temp = temp->next;
            current = temp;
        }
    }

    /*
    Metodo atStart:
    Indica si se esta al inicio de la lista
    */
    bool atStart() {
        return current == head;
    }

    /*
    Metodo atEnd:
    Indica si se esta al final de la lista
    */
    bool atEnd() {
        return current == tail;
    }

    /*
    Metodo getPos:
    retorna la posicion actual
    */
    int getPos() {
        int pos = 0;
        Node<E> *temp = head;
        while (temp != current) {
            temp = temp->next;
            pos++;
        }
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
<<<<<<< Updated upstream
=======
    metodo print:
    Imprime la lista
    */

    /*void print() {
        Node<E> *oldCurrent = current;
        cout << "[ ";
        for(goToStart(); !atEnd(); next()) {
            cout << getElement() << " ";
        }
        cout << "]" << endl;
        current = oldCurrent;
    }*/

    /*
>>>>>>> Stashed changes
    metodo indexOf:
    retorna el indice de un elemento dado, si no existe, retorna -1
    */
    int indexOf(E element) {
        Node<E> *oldCurrent = current;                              // se guarda el current para restaurarlo en el futuro
        for(int pos = 0,goToStart(); !atEnd(); next(),pos++) {      // Mediante un for, se recorre toda la lista hasta encontrar
            if (getElement() == element) {                          // el elemento, en caso de que exista, con una posicion contada
                current = oldCurrent;                               // previamente, se retorna pero antes se restaura el current
                return pos;
            }
        }
        current = oldCurrent;                                       // caso de que no exista, se retorna -1 y se restaura el current
        return -1;
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
        Node<E> *oldCurrent = current;
        for(goToStart(),L->goToStart(); !atEnd() || !L->atEnd(); next(),L->next()) {    // Con un for se manda ambas listas a su inicio.
            if (L->getElement() != getElement()) {                                      // se cambia de elemento en cada ciclo,
                L->goToPos(oldPosEntrada);                                              // y se comprueba si alguna lista llego al final
                current = oldCurrent;                                                   // si algun elemento no cuadra se retorna false
                return false;                                                           // y se restauran las posiciones
            }
        }
        L->goToPos(oldPosEntrada);                                                      // Si no, se devuelve true y se restauran las posiciones
        current = oldCurrent;
        return true;

    }

    bool swapElement(E element, int pos){
        if(pos==size||size<=1)
            return false;
        int oldPos = indexOf(element);
        if(oldPos==-1)
            return false;
    }

};




#endif
