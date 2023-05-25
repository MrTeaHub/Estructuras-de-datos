#include "Lista.h"


template<typename T>
Lista<T>::Lista():begin(0), count(0){}

template<typename T>
Lista<T>::~Lista() {
    Node<T>* del = begin;
    while (begin){
        begin = begin->next;
        delete del;
        del = begin;
    }
}

template<typename T>
Node<T> *Lista<T>::makeNode(const T &value) {
    Node<T>* newNode = new Node<T>;
    newNode->data = value;
    newNode->next = 0;
    return newNode;
}

template<typename T>
void Lista<T>::insert(int posicion, T &value) {
    Node<T>* add = makeNode(value);
    if(posicion == 0) {
        add->next = begin;
        begin = add;
    } else{
        Node<T>* cur = begin;
        for (int i = 0; i < (posicion-1); i++) {
            cur = cur->next;
        }
        add->next = cur->next;
        cur->next = add;
    }
    count++;
}

template<typename T>
void Lista<T>::eraser(int posicion) {
    if(posicion == 0){
        Node<T>* del = begin;
        begin = del->next;
        delete del;
    } else {
        Node<T>* cur = begin;
        for (int i = 0; i < (posicion-1); i++) {
            cur = cur->next;
        }
        Node<T>* del = cur->next;
        cur->next = del->next;
        delete del;
    }
    count--;
}

template<typename T>
T& Lista<T>::get(int posicion) const{
    if(posicion < 0 || posicion > (count-1)){
        cout << "Error! La posicion ingresada esta fuera del rango" << endl;
    }
    if (posicion == 0) {
        return begin->data;
    } else {
        Node<T>* cur = begin;
        for (int i = 0; i < posicion; i++) {
            cur = cur->next;
        }
        return cur->data;
    }
}

template<typename T>
void Lista<T>::print(){
    if(count == 0) {
        cout << "La lista esta vacia" << endl;
    }
    Node<T>* cur = begin;
    while(cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

template<typename T>
int Lista<T>::size() {
    return count;
}