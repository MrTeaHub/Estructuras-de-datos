#ifndef LISTAS_NODE_H
#define LISTAS_NODE_H

#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
};


#endif //LISTAS_NODE_H
