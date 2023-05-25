#include "ListaDoblementeEnlazada.cpp"
#include "Lista.cpp"
#include "Estudiante.h"
#include <fstream>
#include <sstream>
#include <cmath>


void almacenarArchivo(string Archivo, ListaDoblementeEnlazada<Estudiante> *estudiantes) {
    ifstream archivo(Archivo);
    string linea, nombre;
    Estudiante estudiante;
    //archivo es el objeto a leer y linea es la variable donde se va a guardar lo leido
    //getline puede recibir 3 parametros, el primero recibe lo que se va a leer, el segundo donde se
    // a almacenar lo leido y el tercero lo que le dice hasta donde leer en la linea
    while (getline(archivo, linea)) {
        //stream recibe la primera linea del .txt
        stringstream stream(linea);
        getline(stream, nombre);
        estudiante.setNombre(nombre);
        estudiantes->insert(estudiantes->size(),estudiante);
    }
    archivo.close();
}

float sum(Lista<float> &lista) {
    float sumatoria = 0.0;
    for(int i = 0; i < lista.size(); i++){
        sumatoria = sumatoria + lista.get(i);
    }
    return sumatoria;
}

void imprimirLista(ListaDoblementeEnlazada<Estudiante> &estudiantes){
    cout << "Nombre del estudiante  Calificacion 1  Calificacion 2  Calificacion 3  Calificacion 4  Puntaje Total  Promedio" << endl;
    for (int i = 0; i < estudiantes.size(); i++) {
        cout << estudiantes.get(i).getNombre();
        for (int r = 0; r < (26 - estudiantes.get(i).getNombre().length()); r++) { //Se agregan espacios dependiendo el tamaño del nombre
            cout << " ";
        }
        for (int j = 0; j < estudiantes.get(i).notas.size(); j++) {
            cout << estudiantes.get(i).notas.get(j) << "             "; //Se imprimen las notas del estudiante
            if(fmodf(estudiantes.get(i).notas.get(j),1) == 0) cout << "  "; //Se agregan dos espacios si el numero es entero
        } //fmodf me devuelve el residuo de una division de flotantes
        int espacios = estudiantes.get(i).notas.size();
        if(espacios == 1) espacios = 48;
        else if(espacios == 2) espacios = 32;
        else if(espacios == 3) espacios = 16;
        else espacios = 0;
        for (int k = 0; k < espacios; k++) { //Se agregan espacios dependiendo el # de notas que tenga el estudiante
            cout << " ";
        }
        // Se muestra el puntaje total y el promedio
        cout << sum(estudiantes.get(i).notas) << "          " <<  round((sum(estudiantes.get(i).notas)/float (estudiantes.get(i).notas.size()))*10)/10 << endl;
    }
}

void programa(ListaDoblementeEnlazada<Estudiante> &estudiantes){
    int nCalificaciones;
    float nota = 0;

    for (int i = 0; i < estudiantes.size(); i++) {
        Lista<float> calificaciones;
        while (true){
            cout << "Ingrese el # de calificaciones que tiene: " << estudiantes.get(i).getNombre() << endl;
            cin >> nCalificaciones;
            if(nCalificaciones >= 1  && nCalificaciones <= 4) break;
            else cout << "Error!" << endl;
        }
        for (int j = 0; j < nCalificaciones; j++) {
            while (true) {
                cout << "Calificacion: " << j+1 << endl;
                cin >> nota;
                if(nota != 0) break;
                else cout << "Ingrese la nota" << endl;
            }
            estudiantes.get(i).notas.insert(j,nota);
        }
    }
    imprimirLista(estudiantes);
}

void organizarNombres(ListaDoblementeEnlazada<Estudiante> &estudiantes) {
    string nombre, intercambio;
    for (int i = 0; i < estudiantes.size(); ++i) {
        nombre = estudiantes.get(i).getNombre();
        for (int j = 0; j < nombre.size(); ++j) {
            if (nombre[j] == ' ') {
                intercambio = "";
                for (int k = j + 1; k < nombre.size(); ++k) {
                    intercambio += nombre[k];
                }
                intercambio += " ";
                for (int k = 0; k < j; ++k) {
                    intercambio += nombre[k];
                }
            }
            estudiantes.get(i).setNombre(intercambio);
        }
    }
    intercambio = "";
    nombre = "";
    for (int i = 0; i < estudiantes.size() - 1; ++i) {
        for (int j = i+1; j <estudiantes.size() ; ++j) {
            if(estudiantes.get(i).getNombre()>estudiantes.get(j).getNombre()) {
                intercambio = estudiantes.get(i).getNombre();
                nombre = estudiantes.get(j).getNombre();
                estudiantes.get(i).setNombre(nombre);
                estudiantes.get(j).setNombre(intercambio);
            }
            intercambio = "";
            nombre = "";
        }
    }
    intercambio = "";
    nombre = "";
    for (int i = 0; i < estudiantes.size(); ++i) {
        nombre = estudiantes.get(i).getNombre();
        for (int j = 0; j < nombre.size(); ++j) {
            if (nombre[j] == ' ') {
                intercambio = "";
                for (int k = j + 1; k < nombre.size(); ++k) {
                    intercambio += nombre[k];
                }
                intercambio += " ";
                for (int k = 0; k < j; ++k) {
                    intercambio += nombre[k];
                }
            }
            estudiantes.get(i).setNombre(intercambio);
        }
    }
    imprimirLista(estudiantes);
}


int main() {
    ListaDoblementeEnlazada<Estudiante> estudiantes;
    almacenarArchivo("Estudiantes.txt", &estudiantes);
    programa(estudiantes);
    organizarNombres(estudiantes);
    return 0;
}
