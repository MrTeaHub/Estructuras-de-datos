#ifndef LAB5_LISTA_H
#define LAB5_LISTA_H

#include "Node.h"

template<typename T>
class Lista {
private:
    int count;
    Node<T>* begin;
    Node<T>* makeNode(const T &value);
public:
    Lista();
    ~Lista();
    void insert(int posicion, T &value);
    void eraser(int posicion);
    T& get(int posicion) const;
    void print();
    int size();
};




#endif //LAB5_LISTA_H
