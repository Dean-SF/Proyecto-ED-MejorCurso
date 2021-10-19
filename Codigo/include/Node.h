//Creado por: Mauricio Aviles Cisneros
//Modificado por: Deyan Sanabria Fallas
#ifndef NODE_H
#define NODE_H

template <typename E>
class Node {
public:
    E element;
    Node<E> *next;

    /*
    Constructor del nodo con un elemento y un puntero opcional
    */
    Node(E element, Node<E> *next = nullptr) {
        this->element = element;
        this->next = next;
    }

    /*
    Contructor del nodo con un puntero opcional.
    */
    Node(Node<E> *next = nullptr) {
        this->next = next;
    }
};


#endif
