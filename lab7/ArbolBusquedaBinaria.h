#ifndef LAB7_ARBOLBUSQUEDABINARIA_H
#define LAB7_ARBOLBUSQUEDABINARIA_H

#include "ArbolBinario.cpp"
#include "Persona.cpp"

template<typename T>
class ArbolBusquedaBinaria: public ArbolBinario<T>{
private:
    int count;
    void insert(T& value, NodeArbol<T>*& ptr);
    void inorder(NodeArbol<T>* ptr);
    void preorder(NodeArbol<T>* ptr);
    void postorder(NodeArbol<T>* ptr);
    bool search(string& value, NodeArbol<T>* ptr);
    void imprimirTelefonos(NodeArbol<T> *ptr);
public:
    ArbolBusquedaBinaria(T& value);
    ~ArbolBusquedaBinaria();
    void insert(T& value);
    void inorder();
    void preorder();
    void postorder();
    bool search(string& value);
    void imprimirTelefonos();
    void deleteNode(string &value);
};

#endif //LAB7_ARBOLBUSQUEDABINARIA_H
