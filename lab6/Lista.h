#ifndef LAB6_LISTA_H
#define LAB6_LISTA_H

#include <iostream>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node<T>* next;
};

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


#endif //LAB6_LISTA_H
