#ifndef LAB6_PILA_H
#define LAB6_PILA_H

#include "Lista.cpp"

template<typename T>
class Pila {
private:
    Lista<T> lista;
public:
    void push(T& value);
    void pop();
    T& top();
    int size();
};


#endif //LAB6_PILA_H
