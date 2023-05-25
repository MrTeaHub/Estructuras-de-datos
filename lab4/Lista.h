#ifndef LAB4_LISTA_H
#define LAB4_LISTA_H

#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class Lista {
private:
    int count;
    Node<T>* begin;
    Node<T>* makeNode(const T &value);
public:
    Lista();
    ~Lista();
    void insert(int posicion, const T &value);
    void eraser(int posicion);
    T& get(int posicion) const;
    void print() const;
    int size();
};

#endif //LAB4_LISTA_H
