#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "Queue.h"
#include "Node.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename E>
class LinkedQueue : public Queue<E> {
private:
    Node<E> *front;
    Node<E> *rear;
    int size;

    void checkIfEmpty() {
        if(front == rear)
            throw runtime_error("Queue is Empty");
    }

public:
    // Constructor de la clase
    LinkedQueue() {
        front = rear = new Node<E>(nullptr);
        size = 0;
    }


    // Deconstructor de la clase
    ~LinkedQueue() {
        clear();
        delete front;
    }

    /*
    Metodo enqueue: Agrega un elemento a la cola
    */
    void enqueue(E element) {
        rear = rear->next = new Node<E>(element,nullptr);
        size++;
    }

    /*
    Metodo dequeue: Saca un elemento de la cola
    */
    E dequeue() {
        checkIfEmpty();
        E result = front->next->element;
        Node<E> *temp = front->next;
        front->next = temp->next;
        delete temp;
        if(front->next == nullptr)
            rear = front;
        size--;
        return result;
    }

    /*
    Metodo frontValue: Muestra el elemento proximo a salir de la cola sin eliminarlo
    */
    E frontValue() {
        checkIfEmpty();
        return front->next->element;
    }

    /*
    Metodo clear: borra todos los elementos de la cola
    */
    void clear() {
        while (front->next != nullptr) {
            rear = front->next;
            front->next = rear->next;
            delete rear;
        }
        rear = front;
        size = 0;

    }

    /*
    Metodo clear: retorna un booleano dependiendo si esta vacia o no
    */
    bool isEmpty() {
        return size == 0;
    }

    /*
    Metodo getSize: retorna el tamaño de la cola
    */
    int getSize() {
        return size;
    }
    /*
    Metodo enqueueFront: agrega un elemento al frente de la cola
    */
    void enqueueFront(E element) {
        front->next = new Node<E>(element,front->next);
        if (rear == front)
            rear = front->next;
        size++;
    }

    /*
    Metodo dequeueRear: elimina y retorna el elemento a final de la cola
    */
    E dequeueRear() {
        checkIfEmpty();
        E result = rear->element;
        delete rear;
        size--;
        rear = front;
        for(int i = 0; i < size; i++) {
            rear = rear->next;
        }
        rear->next = nullptr;
        return result;
    }

    /*
    Metodo rearValue: retorna el elemento al final de la cola
    */
    E rearValue() {
        checkIfEmpty();
        return rear->element;
    }

    /*
    Metodo print: Imprime los elementos de la cola
    */
    /*void print() {
        Node<E> *current = front;
        cout << "[ ";
        while (current->next != nullptr) {
            current = current->next;
            cout << current->element;
            if(current->next == nullptr)
                continue;
            cout << ", ";
        }
        cout << " ]" << endl;

    }*/


};

#endif
