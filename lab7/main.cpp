#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "ArbolBusquedaBinaria.cpp"

void devolverPersonas(NodeArbol<Persona> *ptr, vector<Persona> *personas) {
    if(!ptr) return;
    personas->push_back(ptr->data);
    devolverPersonas(ptr->left,personas);
    devolverPersonas(ptr->right,personas);
}

vector<Persona> devolverPersonas(NodeArbol<Persona> *ptr) {
    vector<Persona> personas;
    devolverPersonas(ptr,&personas);
    return personas;
}

void almacenarArchivo(string Archivo, ArbolBusquedaBinaria<Persona> *personas) {
    ifstream archivo(Archivo);
    string linea, nombre, telefono;
    char delim = ',';
    Persona persona;
    bool flag = true;
    //archivo es el objeto a leer y linea es la variable donde se va a guardar lo leido
    //getline puede recibir 3 parametros, el primero recibe lo que se va a leer, el segundo donde se
    // a almacenar lo leido y el tercero lo que le dice hasta donde leer en la linea
    while (getline(archivo, linea)) {
        //stream recibe la primera linea del .txt
        stringstream stream(linea);
        getline(stream, nombre, delim);
        getline(stream, telefono, delim);
        persona.setNombre(nombre);
        persona.setTelefono(telefono);
        if(flag) {
            personas->setRootValue(persona);
            flag = false;
        }
        else personas->insert(persona);
    }
    archivo.close();
}

template<typename T>
void guardarArchivo(ArbolBusquedaBinaria<T> &resultado, string nombreArchivo){
    ofstream file;
    //creo el .txt
    file.open(nombreArchivo);
    vector<Persona> persona = devolverPersonas(resultado.getRootValue());
    for (int i = 0; i <= persona.size(); i++) {
        file << persona[i].getNombre() << " " << persona[i].getTelefono() << endl;
    }
    file.close();
}

void imprimirArbol(NodeArbol<Persona> *ptr, int ordenJerarquico){
    if(!ptr) return;
    if(ordenJerarquico == 1)
        cout << ordenJerarquico << ". " << ptr->data.getNombre() << " " << ptr->data.getTelefono() << endl;
    else {
        for (int i = 1; i < ordenJerarquico; i++) {
            cout << "   ";
        }
        cout << ordenJerarquico << ". " << ptr->data.getNombre() << " " << ptr->data.getTelefono() << endl;
    }
    imprimirArbol(ptr->left,ordenJerarquico+1);
    imprimirArbol(ptr->right,ordenJerarquico+1);
}

void imprimirArbol(NodeArbol<Persona> *ptr){
    imprimirArbol(ptr,1);
}

void menu(ArbolBusquedaBinaria<Persona> *personas){
    while (true) {
        string Nombre;
        int opc;
        while (true) {
            cout << "Que desea realizar?" << endl;
            cout << "1-Buscar un nombre" << endl;
            cout << "2-Insertar una nueva persona" << endl;
            cout << "3-Eliminar una persona" << endl;
            cout << "4-Imprimir toda la lista de telefonos" << endl;
            cout << "5-Salir" << endl;
            cin >> opc;
            if (opc > 0 && opc < 6) break;
            else {
                cout << "Ingrese una opción correcta" << endl << endl;
            }
        }
        cin.ignore();
        if(opc == 1) {
            cout << endl << "Escriba el nombre que quiera buscar" << endl;
            getline(cin,Nombre);
            if(personas->search(Nombre)) cout << "El nombre ingresado, si esta en la lista" << endl << endl;
            else cout << "El nombre ingresado, no esta en la lista" << endl << endl;
        }
        else if(opc == 2){
            string Telefono;
            cout << endl << "Ingrese el nombre de la nueva persona" << endl;
            getline(cin,Nombre);
            if(personas->search(Nombre)) cout << "Este nombre ya esta registrado" << endl << endl;
            else {
                cout << "Ingrese el telefono de la nueva persona" << endl;
                cin >> Telefono;
                Persona nuevaPersona(Nombre,Telefono);
                personas->insert(nuevaPersona);
                cout << "La persona fue insertada exitosamente" << endl << endl;
            }
        }
        else if(opc == 3) {
            cout << endl << "Ingrese el nombre de la persona que quiera eliminar de la lista" << endl;
            getline(cin,Nombre);
            if(personas->search(Nombre)) {
                personas->deleteNode(Nombre);
                cout << "La persona fue borrada exitosamente" << endl << endl;
            }
            else cout << "El nombre ingresado, no esta en la lista" << endl << endl;
        }
        else if(opc == 4){
            cout << endl << "Lista de telefonos" << endl;
            personas->imprimirTelefonos();
            cout << endl;
        }
        else {
            cout <<"Saliendo del programa" << endl;
            break;
        }
    }
}

int main() {
    Persona p;
    ArbolBusquedaBinaria<Persona> personas(p);
    almacenarArchivo("personas.txt", &personas);
    menu(&personas);
    // Punto3
    imprimirArbol(personas.getRootValue());
    guardarArchivo(personas,"resultadoPersonas.txt");
    return 0;
}
