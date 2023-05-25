#ifndef LAB4_COLA_H
#define LAB4_COLA_H

#include "Lista.h"

template<typename T>
class Cola {
private:
    Lista<T> lista;
public:
    void push(const T& value);
    void pop();
    T& front();
    T& back();
    int size();
    void print() const;
};




#endif //LAB4_COLA_H
