#include "ArbolBinario.h"

template<typename T>
NodeArbol<T>* NodeArbol<T>::makeNode(const T &value) {
    NodeArbol<T>* temp = new NodeArbol<T>;
    temp->data = value;
    temp->left = 0;
    temp->right = 0;
    return temp;
}

template<typename T>
void ArbolBinario<T>::destroy(NodeArbol<T> *ptr) {
    if(!ptr) return;
    destroy(ptr->left);
    destroy(ptr->right);
    delete ptr;
}

template<typename T>
ArbolBinario<T>::ArbolBinario(const T& value) {
    root = root->makeNode(value);
}

template<typename T>
ArbolBinario<T>::~ArbolBinario() {
    destroy(root);
}

template<typename T>
NodeArbol<T>* ArbolBinario<T>::getRootValue() {
    return root;
}

template<typename T>
void ArbolBinario<T>::setRootValue(T &value) {
    root=root->makeNode(value);
}

template<typename T>
void NodeArbol<T>::insertLeft(const T &value) {
    if(!left) left = makeNode(value);
    else {
        NodeArbol<T>* temp = makeNode(value);
        temp->left = left;
        left = temp;
    }
}

template<typename T>
void NodeArbol<T>::insertRight(const T &value) {
    if(!right) right = makeNode(value);
    else {
        NodeArbol<T>* temp = makeNode(value);
        temp->right = right;
        right = temp;
    }
}
