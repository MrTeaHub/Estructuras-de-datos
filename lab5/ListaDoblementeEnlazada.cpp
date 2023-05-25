#include "ListaDoblementeEnlazada.h"

template<typename T>
ListaDoblementeEnlazada<T>::ListaDoblementeEnlazada():begin(0), count(0) {}

template<typename T>
ListaDoblementeEnlazada<T>::~ListaDoblementeEnlazada() {
    Node<T>* del = begin;
    while (begin){
        begin = begin->next;
        delete del;
        del = begin;
    }
}

template<typename T>
Node<T>* ListaDoblementeEnlazada<T>::makeNode(const T &value) {
    Node<T>* temp = new Node<T>;
    temp->data = value;
    temp->next = 0;
    temp->prev = 0;
    return temp;
}

template<typename T>
void ListaDoblementeEnlazada<T>::insert(int posicion, const T &value) {
    if(posicion < 0 || posicion > count) cout << "Error! la posicion esta fuera del rango" << endl;
    Node<T>* add = makeNode(value);
    if(posicion == 0){
        if(count > 0) begin->prev = add;
        add->next = begin;
        begin = add;
    } else {
        Node<T>* cur = begin;
        for (int i = 0; i < posicion - 1; i++) {
            cur = cur->next;
        }
        add->next = cur->next;
        cur->next = add;
        if(posicion < count) add->next->prev = add;
        add->prev = cur;
    }
    count++;
}

template<typename T>
void ListaDoblementeEnlazada<T>::erase(int posicion) {
    if(posicion < 0 || posicion >= count) cout << "Error! la posicion esta fuera del rango" << endl;
    if(posicion == 0) {
        Node<T>* del = begin;
        begin = begin->next;
        begin->prev = 0;
        delete del;
    }
    else {
        Node<T>* cur = begin;
        for (int i = 0; i < posicion - 1; i++) {
            cur = cur->next;
        }
        Node<T>* del = cur->next;
        cur->next = del->next;
        if(posicion < count - 1) cur->next->prev = cur;
        delete del;
    }
    count--;
}

template<typename T>
T &ListaDoblementeEnlazada<T>::get(int posicion) {
    if(posicion < 0 || posicion > count - 1) cout << "Error! la posicion esta fuera del rango" << endl;
    else if(posicion == 0) return begin->data;
    else {
        Node<T>* cur = begin;
        for (int i = 0; i < posicion; ++i) {
            cur = cur->next;
        }
        return cur->data;
    }
}

template<typename T>
void ListaDoblementeEnlazada<T>::print() {
    if(count == 0) cout << "La lista esta vacia" << endl;
    Node<T>* cur = begin;
    while (cur){
        cout << cur->data.getNombre() << " " << endl;
        cur = cur->next;
    }
}

template<typename T>
void ListaDoblementeEnlazada<T>::printReverse() {
    if(count == 0) cout << "La lista esta vacia" << endl;
    Node<T>* cur = begin;
    while (cur->next){
        cout << cur->data.getNombre() << " ";
        cur = cur->prev;
    }
}

template<typename T>
int ListaDoblementeEnlazada<T>::size() {
    return count;
}