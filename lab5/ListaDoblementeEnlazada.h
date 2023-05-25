#ifndef LAB5_LISTADOBLEMENTEENLAZADA_H
#define LAB5_LISTADOBLEMENTEENLAZADA_H

#include "Node.h"
using namespace std;

template<typename T>
class ListaDoblementeEnlazada {
private:
    Node<T>* begin;
    int count;
    Node<T>* makeNode(const T& value);
public:
    ListaDoblementeEnlazada();
    ~ListaDoblementeEnlazada();
    void insert(int posicion, const T& value);
    void erase(int posicion);
    T& get(int posicion);
    void print();
    void printReverse();
    int size();
};


#endif //LAB5_LISTADOBLEMENTEENLAZADA_H
