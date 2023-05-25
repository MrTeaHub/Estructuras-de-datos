#include "Cola.h"

template<typename T>
void Cola<T>::push(const T &value) {
    lista.insert(lista.size(), value);
}

template<typename T>
void Cola<T>::pop() {
    lista.eraser(0);
}

template<typename T>
T &Cola<T>::front() {
    return lista.get(0);
}

template<typename T>
T &Cola<T>::back() {
    return lista.get(lista.size()-1);
}

template<typename T>
int Cola<T>::size()  {
    return lista.size();
}

template<typename T>
void Cola<T>::print() const {
    lista.print();
}