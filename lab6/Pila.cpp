#include "Pila.h"


template<typename T>
void Pila<T>::push(T &value) {
    lista.insert(0, value);
}

template<typename T>
void Pila<T>::pop() {
    lista.eraser(0);
}


template<typename T>
T &Pila<T>::top() {
    return  lista.get(0);
}

template<typename T>
int Pila<T>::size() {
    return lista.size();
}
