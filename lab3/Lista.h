#ifndef LISTAS_LISTA_H
#define LISTAS_LISTA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "Node.h"


using namespace std;

template <typename T>
class Lista {
private:
    int count;
    Node* begin;
    Node* makeNode(const T &value);
public:
    Lista();
    ~Lista();
    void insert(int posicion, const T &value);
    void eraser(int posicion);
    T& get(int posicion) const;
    void print() const;
    int size();
    void sumaPolinomios(Lista<T> *l1, Lista<T> *l2);
    void restaPolinomios(Lista<T> *l1, Lista<T> *l2);
    void almacenarArchivo(string archivo, Lista<T> *polinomio);
};

#endif //LISTAS_LISTA_H
