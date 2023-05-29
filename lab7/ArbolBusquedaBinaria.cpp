#include "ArbolBusquedaBinaria.h"

template<typename T>
ArbolBusquedaBinaria<T>::ArbolBusquedaBinaria(T &value):ArbolBinario<T>(value) {
    count = 0;
}

template<typename T>
ArbolBusquedaBinaria<T>::~ArbolBusquedaBinaria() {}

// Meterlo en el informe
template<typename T>
void ArbolBusquedaBinaria<T>::insert(T &value, NodeArbol<T> *&ptr) {
    if(!ptr){
        ptr = ptr->makeNode(value);
        return;
    }
    else if(value.getNombre() < ptr->data.getNombre()) insert(value,ptr->left);
    else insert(value,ptr->right);
}
// Meterlo en el informe
template<typename T>
void ArbolBusquedaBinaria<T>::insert(T &value) {
    insert(value,this->root);
    count++;
}

template<typename T>
void ArbolBusquedaBinaria<T>::inorder(NodeArbol<T> *ptr) {
    if(!ptr) return;
    inorder(ptr->left);
    cout << ptr->data.getNombre() << " " << ptr->data.getTelefono() << endl;
    inorder(ptr->right);
}


template<typename T>
void ArbolBusquedaBinaria<T>::inorder() {
    inorder(this->root);
}

template<typename T>
void ArbolBusquedaBinaria<T>::preorder(NodeArbol<T> *ptr) {
    if(!ptr) return;
    cout << ptr->data.getNombre() << " " << ptr->data.getTelefono() << endl;
    preorder(ptr->left);
    preorder(ptr->right);
}

template<typename T>
void ArbolBusquedaBinaria<T>::preorder() {
    preorder(this->root);
}

template<typename T>
void ArbolBusquedaBinaria<T>::postorder(NodeArbol<T> *ptr) {
    if(!ptr) return;
    postorder(ptr->left);
    postorder(ptr->right);
    cout << ptr->data.getNombre() << " " << ptr->data.getTelefono() << endl;
}

template<typename T>
void ArbolBusquedaBinaria<T>::postorder() {
    postorder(this->root);
}

// Meterlo en el informe
template<typename T>
bool ArbolBusquedaBinaria<T>::search(string &value, NodeArbol<T> *ptr) {
    if(!ptr) return false;
    else if(ptr->data.getNombre() == value) return true;
    else if(value < ptr->data.getNombre()) return search(value, ptr->left);
    else return search(value,ptr->right);
}

// Meterlo en el informe
template<typename T>
bool ArbolBusquedaBinaria<T>::search(string &value) {
    return search(value, this->root);
}

// Meterlo en el informe
template<typename T>
void ArbolBusquedaBinaria<T>::imprimirTelefonos(NodeArbol<T> *ptr) {
    if(!ptr) return;
    cout << ptr->data.getTelefono() << endl;
    imprimirTelefonos(ptr->left);
    imprimirTelefonos(ptr->right);
}

// Meterlo en el informe
template<typename T>
void ArbolBusquedaBinaria<T>::imprimirTelefonos() {
    imprimirTelefonos(this->root);
}

// Meterlo en el informe
template <typename T>
void ArbolBusquedaBinaria<T>::deleteNode(string &value) {
    NodeArbol<T>* nodoactual = this->root;
    NodeArbol<T>* parent = 0;

    // Buscar el nodo a eliminar
    while (nodoactual) {
        if (value == nodoactual->data.getNombre()) break;  // Nodo encontrado
        parent = nodoactual;
        if (value < nodoactual->data.getNombre()) nodoactual = nodoactual->left;  // Buscar en el subárbol izquierdo
        else nodoactual = nodoactual->right;  // Buscar en el subárbol derecho
    }

    if (!nodoactual) return;  // El nodo no se encontró, no hay cambios

    // Caso 1: El nodo a eliminar es una hoja
    if (!nodoactual->left && !nodoactual->right) {
        if (!parent) {
            // El nodo a eliminar es la raíz
            delete nodoactual;
            Persona p;
            this->setRootValue(p);
        } else {
            if (parent->left == nodoactual) {
                parent->left = 0;
            } else {
                parent->right = 0;
            }
            delete nodoactual;
        }
    }
    // Caso 2: El nodo a eliminar tiene un hijo
    else if (!nodoactual->left || !nodoactual->right) {
        NodeArbol<T>* reencarnacion = 0;
        if (nodoactual->left) {
            reencarnacion = nodoactual->left;
        } else {
            reencarnacion = nodoactual->right;
        }
        if (!parent) {
            // El nodo a eliminar es la raíz
            delete nodoactual;
            this->setRootValue(reencarnacion->data);
        } else {
            if (parent->left == nodoactual) {
                parent->left = reencarnacion;
            } else {
                parent->right = reencarnacion;
            }
            delete nodoactual;
        }
    }
    // Caso 3: El nodo a eliminar tiene dos hijos
    else {
        NodeArbol<T>* successorParent = nodoactual;
        NodeArbol<T>* successor = nodoactual->right;

        while (successor->left) {
            successorParent = successor;
            successor = successor->left;
        }

        nodoactual->data = successor->data;

        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
        delete successor;
    }
}


