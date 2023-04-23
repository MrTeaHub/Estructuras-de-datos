#include "Lista.h"
#include "Node.h"

template <typename T>
Lista<T>::Lista() : begin(0), count(0) {}

template<typename T>
Lista<T>::~Lista() {
    Node *del = begin;
    while (begin){
        begin = begin->next;
        delete del;
        del = begin;
    }
}

template<typename T>
Node *Lista<T>::makeNode(const T &value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = 0;
    return newNode;
}

template<typename T>
void Lista<T>::insert(int posicion, const T &value) {
    Node* add = makeNode(value);
    if(posicion == 0) {
        add->next = begin;
        begin = add;
    } else{
        Node* cur = begin;
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
        Node* del = begin;
        begin = del->next;
        delete del;
    } else {
        Node* cur = begin;
        for (int i = 0; i < (posicion-1); i++) {
            cur = cur->next;
        }
        Node* del = cur->next;
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
        Node* cur = begin;
        for (int i = 0; i < posicion; i++) {
            cur = cur->next;
        }
        return cur->data;
    }
}

template<typename T>
void Lista<T>::print() const{
    if(count == 0) {
        cout << "La lista esta vacia" << endl;
    }
    Node* cur = begin;
    while(cur) {
        cout << cur->data.getCoeficiente() << " " << cur->data.getExponente() << endl;
        cur = cur->next;
    }
}

template<typename T>
int Lista<T>::size() {
    return count;
}

template<typename T>
void Lista<T>::sumaPolinomios(Lista<T> *l1, Lista<T> *l2) {
    Node* cur1 = l1->begin;
    Node* cur2 = l2->begin;
    Termino termino;
    int posicion = 0;
    //La funcion se va a ejecutar hasta que lista 1 y lista 2 lleguen al final
    while (cur1 || cur2){
        //Si dos exponentes son iguales, sumar coeficientes
        if(cur1->data.getExponente() == cur2->data.getExponente()) {
            termino.setCoeficiente(cur1->data.getCoeficiente() + cur2->data.getCoeficiente());
            termino.setExponente(cur1->data.getExponente());
            //Agregar el termino, solo si el coeficiente es diferente de 0
            if(cur1->data.getCoeficiente() + cur2->data.getCoeficiente() != 0) {
                insert(posicion, termino);
                posicion++;
            }
            //Apuntar al siguiente nodo en las dos listas
            cur1 = cur1->next;
            cur2 = cur2->next;
        } //Si el exponente de la lista 2 es mayor al de la lista 1
        else if(cur1->data.getExponente() < cur2->data.getExponente()){
            termino.setCoeficiente(cur2->data.getCoeficiente());
            termino.setExponente(cur2->data.getExponente());
            //Se agrega el termino con exponente mayor
            insert(posicion, termino);
            //Se apunta al siguiente nodo de la lista 2, el nodo de la lista 1 sigue igual
            cur2 = cur2->next;
            posicion++;
        } //Si el exponente de la lista 1 es mayor al de la lista 2
        else if(cur1->data.getExponente() > cur2->data.getExponente()){
            termino.setCoeficiente(cur1->data.getCoeficiente());
            termino.setExponente(cur1->data.getExponente());
            //Se agrega el termino con exponente mayor
            insert(posicion, termino);
            //Se apunta al siguiente nodo de la lista 1, el nodo de la lista 2 sigue igual
            cur1 = cur1->next;
            posicion++;
        } // Si la lista 1 ya llego al final y la lista 2 aún tiene terminos
        if(!cur1 && cur2){
            termino.setCoeficiente(cur2->data.getCoeficiente());
            termino.setExponente(cur2->data.getExponente());
            //Se agregan los terminos restantes
            insert(posicion, termino);
            cur2 = cur2->next;
            posicion++;
        } // Si la lista 2 ya llego al final y la lista 1 aún tiene terminos
        if(!cur2 && cur1) {
            termino.setCoeficiente(cur1->data.getCoeficiente());
            termino.setExponente(cur1->data.getExponente());
            //Se agregan los terminos restantes
            insert(posicion, termino);
            cur1 = cur1->next;
            posicion++;
        } //Si ya se llego al final en la lista 1 y 2 y si la posicion es igual a 0
        if(!cur1 && !cur2 && posicion == 0) {
            termino.setCoeficiente(0);
            termino.setExponente(0);
            //Se agrega 0 0, lo que quiere decir que la operacion dio como resultado 0
            insert(posicion,termino);
        }
    }
}

template<typename T>
void Lista<T>::restaPolinomios(Lista<T> *l1, Lista<T> *l2) {
    Node* cur1 = l1->begin;
    Node* cur2 = l2->begin;
    Termino termino;
    int posicion = 0;
    //La funcion se va a ejecutar hasta que lista 1 y lista 2 lleguen al final
    while (cur1 || cur2){
        //Si dos exponentes son iguales, restar coeficientes
        if(cur1->data.getExponente() == cur2->data.getExponente()) {
            termino.setCoeficiente(cur1->data.getCoeficiente() - cur2->data.getCoeficiente());
            termino.setExponente(cur1->data.getExponente());
            //Agregar el termino, solo si el coeficiente es diferente de 0
            if(cur1->data.getCoeficiente() - cur2->data.getCoeficiente() != 0) {
                insert(posicion, termino);
                posicion++;
            }
            //Apuntar al siguiente nodo en las dos listas
            cur1 = cur1->next;
            cur2 = cur2->next;
        } //Si el exponente de la lista 2 es mayor al de la lista 1
        else if(cur1->data.getExponente() < cur2->data.getExponente()){
            termino.setCoeficiente(cur2->data.getCoeficiente()*-1);
            termino.setExponente(cur2->data.getExponente());
            //Se agrega el termino con exponente mayor
            insert(posicion, termino);
            //Se apunta al siguiente nodo de la lista 2, el nodo de la lista 1 sigue igual
            cur2 = cur2->next;
            posicion++;
        } //Si el exponente de la lista 1 es mayor al de la lista 2
        else if(cur1->data.getExponente() > cur2->data.getExponente()){
            termino.setCoeficiente(cur1->data.getCoeficiente());
            termino.setExponente(cur1->data.getExponente());
            //Se agrega el termino con exponente mayor
            insert(posicion, termino);
            //Se apunta al siguiente nodo de la lista 1, el nodo de la lista 2 sigue igual
            cur1 = cur1->next;
            posicion++;
        } //Si la lista 1 ya llego al final y la lista 2 aún tiene terminos
        if(!cur1 && cur2){
            termino.setCoeficiente(cur2->data.getCoeficiente()*-1);
            termino.setExponente(cur2->data.getExponente());
            //Se agregan los terminos restantes
            insert(posicion, termino);
            cur2 = cur2->next;
            posicion++;
        } //Si la lista 2 ya llego al final y la lista 1 aún tiene terminos
        if(!cur2 && cur1) {
            termino.setCoeficiente(cur1->data.getCoeficiente());
            termino.setExponente(cur1->data.getExponente());
            //Se agregan los terminos restantes
            insert(posicion, termino);
            cur1 = cur1->next;
            posicion++;
        } //Si ya se llego al final en la lista 1 y 2 y si la posicion es igual a 0
        if(!cur1 && !cur2 && posicion == 0) {
            termino.setCoeficiente(0);
            termino.setExponente(0);
            //Se agrega 0 0, lo que quiere decir que la operacion dio como resultado 0
            insert(posicion,termino);
        }
    }
}

template<typename T>
void Lista<T>::almacenarArchivo(string Archivo, Lista<T> *polinomio) {
    ifstream archivo(Archivo);
    string linea, coeficiente, exponente;
    char delim = ' ';
    Termino termino;
    int posicion = 0;
    //archivo es el objeto a leer y linea es la variable donde se va a guardar lo leido
    //getline puede recibir 3 parametros, el primero recibe lo que se va a leer, el segundo donde se
    // a almacenar lo leido y el tercero lo que le dice hasta donde leer en la linea
    while (getline(archivo, linea)) {
        //stream recibe la primera linea del .txt
        stringstream stream(linea);
        getline(stream, coeficiente, delim);
        getline(stream, exponente, delim);
        termino.setCoeficiente(stoi(coeficiente));
        termino.setExponente(stoi(exponente));
        polinomio->insert(posicion,termino);
        posicion++;
    }
    archivo.close();
}